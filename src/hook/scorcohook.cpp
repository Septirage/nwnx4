/***************************************************************************
scorcohook.cpp - Hooking of StoreCampaingObject and RetrieveCampaignObject
Copyright (C) 2007 virusman (virusman@virusman.ru)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***************************************************************************/

#include "scorcohook.h"
#include "hook.h"
#include "nwn2heap.h"

static DBPlugin* legacyDBPlugin = nullptr;
void SCORCOSetLegacyDBPlugin(DBPlugin* dbplugin){
	legacyDBPlugin = dbplugin;
}

int (__fastcall *OriginalSCO)(void* pThis, void* _, char** database, char** key, char** player, int flags, unsigned char* pData, int size);
unsigned char* (__fastcall *OriginalRCO)(void* pThis, void* _, char** database, char** key, char** player, int* arg4, int* size);

int __fastcall SCOHookProc(void* pThis, void* _, char** database, char** key, char** player, int flags, unsigned char * pData, int size)
{
	if(!pThis) return 0;

	if (memcmp(*database, "NWNX", 4) != 0)
	{
		return OriginalSCO(pThis, _, database, key, player, flags, pData, size);
	}
	else
	{
		// *database starts with "NWNX"
		if((*database)[4] == '.'){
			// Send to CPlugin
			auto pluginID = &(*database)[5];

			auto pluginIt = cplugins.find(pluginID);
			if(pluginIt != cplugins.end()){
				pluginIt->second->SetGFF(*key, pData, size);
				return true;
			}
		}
		else{
			// By default, send to SQL plugin
			if(legacyDBPlugin != nullptr)
				return legacyDBPlugin->WriteScorcoData(pData, size);
			else
				logger->Err("Called StoreCampaignObject(\"NWNX\", ...), but there is no SQL plugin");
		}
		return false;
	}
}

unsigned char* __fastcall RCOHookProc(void* pThis, void* _, char** database, char** key, char** player, int* arg4, int* size)
{
	if(!pThis) return NULL;

	if (memcmp(*database, "NWNX", 4) != 0)
	{
		return OriginalRCO(pThis, _, database, key, player, arg4, size);
	}
	else
	{
		// *database starts with "NWNX"
		if((*database)[4] == '.'){
			// Send to CPlugin
			auto pluginID = &(*database)[5];

			auto pluginIt = cplugins.find(pluginID);
			if(pluginIt != cplugins.end()){
				*size = pluginIt->second->GetGFFSize(*key);

				if(*size > 0){
					// Note: Any returned non-null pointer will be deallocated by the nwn2 server.
					// Currently we cannot return data that isn't managed by the NWN2_HeapMgr
					NWN2_HeapMgr *pHeapMgr = NWN2_HeapMgr::Instance();
					NWN2_Heap *pHeap = pHeapMgr->GetDefaultHeap();
					uint8_t* data = (uint8_t*) pHeap->Allocate(*size);

					pluginIt->second->GetGFF(*key, data, *size);
					return data;
				}
			}
		}
		else{
			// By default, send to SQL plugin
			if(legacyDBPlugin != nullptr)
				return legacyDBPlugin->ReadScorcoData(*key, size);
			else
				logger->Err("Called RetrieveCampaignObject(\"NWNX\", ...), but there is no SQL plugin");
		}

		return nullptr;
	}
}

static DWORD FindHookSCO()
{
	//8B 44 24 04 56 57 6A 01 50 8B F9 E8 ** ** ** ** 8B F0 85 F6 75 07 5F 33 C0 5E C2 18 00 8B 54 24 14
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x800000)
	{
		if ((ptr[0] == (char) 0x8B) &&
			(ptr[1] == (char) 0x44) &&
			(ptr[2] == (char) 0x24) &&
			(ptr[3] == (char) 0x04) &&
			(ptr[4] == (char) 0x56) &&
			(ptr[5] == (char) 0x57) &&
			(ptr[6] == (char) 0x6A) &&
			(ptr[7] == (char) 0x01) &&
			(ptr[8] == (char) 0x50) &&
			(ptr[9] == (char) 0x8B) &&
			(ptr[0xA] == (char) 0xF9) &&
			(ptr[0xB] == (char) 0xE8) &&
			//c
			//d
			//e
			//f
			(ptr[0x10] == (char) 0x8B) &&
			(ptr[0x11] == (char) 0xF0) &&
			(ptr[0x12] == (char) 0x85) &&
			(ptr[0x13] == (char) 0xF6) &&
			(ptr[0x14] == (char) 0x75) &&
			(ptr[0x15] == (char) 0x07) &&
			(ptr[0x16] == (char) 0x5F) &&
			(ptr[0x17] == (char) 0x33) &&
			(ptr[0x18] == (char) 0xC0) &&
			(ptr[0x19] == (char) 0x5E) &&
			(ptr[0x1A] == (char) 0xC2) &&
			(ptr[0x1B] == (char) 0x18) &&
			(ptr[0x1C] == (char) 0x00) &&
			(ptr[0x1D] == (char) 0x8B) &&
			(ptr[0x1E] == (char) 0x54) &&
			(ptr[0x1F] == (char) 0x24) &&
			(ptr[0x20] == (char) 0x14)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

static DWORD FindHookRCO()
{
	//8B 44 24 04 56 57 33 FF 57 50 8B F1 E8 ** ** ** ** 85 C0 0F 84 9C 00 00 00 8B 4C 24 14 8B 54 24 10 51 52 50
	char* ptr = (char*) 0x400000;
	while (ptr < (char*) 0x800000)
	{
		if ((ptr[0] == (char) 0x8B) &&
			(ptr[1] == (char) 0x44) &&
			(ptr[2] == (char) 0x24) &&
			(ptr[3] == (char) 0x04) &&
			(ptr[4] == (char) 0x56) &&
			(ptr[5] == (char) 0x57) &&
			(ptr[6] == (char) 0x33) &&
			(ptr[7] == (char) 0xFF) &&
			(ptr[8] == (char) 0x57) &&
			(ptr[9] == (char) 0x50) &&
			(ptr[0xA] == (char) 0x8B) &&
			(ptr[0xB] == (char) 0xF1) &&
			(ptr[0xC] == (char) 0xE8) &&
			//d
			//e
			//f
			//10
			(ptr[0x11] == (char) 0x85) &&
			(ptr[0x12] == (char) 0xC0) &&
			(ptr[0x13] == (char) 0x0F) &&
			(ptr[0x14] == (char) 0x84) &&
			(ptr[0x15] == (char) 0x9C) &&
			(ptr[0x16] == (char) 0x00) &&
			(ptr[0x17] == (char) 0x00) &&
			(ptr[0x18] == (char) 0x00) &&
			(ptr[0x19] == (char) 0x8B)
			)
			return (DWORD) ptr;
		else
			ptr++;
	}
	return NULL;
}

bool SCORCOHook(LogNWNX* logger)
{	
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	int sco_success, rco_success, detour_success;
	DWORD sco = FindHookSCO();
	if (sco)
	{
		logger->Info("o SCO located at %x.", sco);
		//odmbc.Log(0, "o SCO located at %x.\n", sco);
		//sco_success = HookCode((PVOID) sco, SCOHookProc, (PVOID*) &OriginalSCO);
		*(DWORD*)&OriginalSCO = sco;
		sco_success = DetourAttach(&(PVOID&)OriginalSCO, SCOHookProc)==0;
	}
	else
	{
		logger->Err("! SCO locate failed.");
		return false;
	}

	DWORD rco = FindHookRCO();
	if (rco)
	{
		logger->Info("o RCO located at %x.", rco);
		//rco_success = HookCode((PVOID) rco, RCOHookProc, (PVOID*) &OriginalRCO);
		*(DWORD*)&OriginalRCO = rco;
		rco_success = DetourAttach(&(PVOID&)OriginalRCO, RCOHookProc)==0;
	}
	else
	{
		logger->Err("! RCO locate failed.");
		return false;
	}
    detour_success = DetourTransactionCommit()==0;
	return sco_success && rco_success&&detour_success;
}

