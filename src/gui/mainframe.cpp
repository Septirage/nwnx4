/***************************************************************************
    NWNX Main frame - The main window of the GUI client
    Copyright (C) 2007 Ingmar Stieger (Papillon, papillon@nwnx.org)

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

// Generated by DialogBlocks (unregistered), 17/12/2006 17:50:01

////@begin includes
////@end includes

#include "stdwx.h"
#include "mainframe.h"
#include "wx/mimetype.h"
#include "dlgabout.h"

////@begin XPM images
#include "res/nwnx4_icon.xpm"
#include "res/nwnx4_logo.xpm"
////@end XPM images

/*!
 * MainFrame type definition
 */

IMPLEMENT_CLASS( MainFrame, wxFrame )

/*!
 * MainFrame event table definition
 */
DEFINE_EVENT_TYPE(wxEVT_SERVER_STARTED)
DEFINE_EVENT_TYPE(wxEVT_SERVER_STOPPED)
DEFINE_EVENT_TYPE(wxEVT_SERVER_KILLED)

BEGIN_EVENT_TABLE( MainFrame, wxFrame )

////@begin MainFrame event table entries
    EVT_CLOSE(MainFrame::OnClose)

    EVT_CHECKBOX( ID_PW_ENABLED, MainFrame::OnPwEnabledClick )

    EVT_CHECKBOX( ID_GW_ENABLED, MainFrame::OnGwEnabledClick )

    EVT_BUTTON( ID_BTNSTART, MainFrame::OnBtnstartClick )

    EVT_BUTTON( ID_BTNSTOP, MainFrame::OnBtnstopClick )

    EVT_BUTTON( ID_BTNRESTART, MainFrame::OnBtnrestartClick )

    EVT_MENU( wxID_EXIT, MainFrame::OnEXITClick )

    EVT_MENU( ID_HELP, MainFrame::OnHelpClick )

    EVT_MENU( ID_FORUM, MainFrame::OnForumClick )

    EVT_MENU( wxID_ABOUT, MainFrame::OnABOUTClick )

////@end MainFrame event table entries
	EVT_COMMAND  (ID_MAINFRAME, wxEVT_SERVER_STARTED, MainFrame::OnServerStarted)
	EVT_COMMAND  (ID_MAINFRAME, wxEVT_SERVER_STOPPED, MainFrame::OnServerStopped)
	EVT_COMMAND  (ID_MAINFRAME, wxEVT_SERVER_KILLED, MainFrame::OnServerKilled)
END_EVENT_TABLE()

LogNWNX* logger;

/*!
 * MainFrame constructors
 */

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create( parent, id, caption, pos, size, style );
}

/*!
 * MainFrame creator
 */

bool MainFrame::Create(wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style)
{
    logger = static_cast<LogNWNX*>(new Log());

////@begin MainFrame creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("res/nwnx4_icon.xpm")));
////@end MainFrame creation

	m_logger = new wxLogTextCtrl(m_log);
	wxLog::SetActiveTarget(m_logger);

	wxLogMessage(wxT("Running in GUI mode."));

	wxDateTime now = wxDateTime::Now();
	m_startedAt->AppendText(now.Format());

    // open ini file
    std::string inifile("nwnx.ini");
    auto config = new SimpleIniConfig(inifile);

    controller = new NWNXController(config);

	m_CmdLine->AppendText(controller->parameters);
	m_PWEnabled->SetValue(controller->processWatchdog);
	m_GWEnabled->SetValue(controller->gamespyWatchdog);
    m_PWInterval->AppendText(wxT("1"));
	m_GWInterval->AppendText(wxString::Format(wxT("%d"), controller->gamespyInterval));
    m_GWRetries->AppendText(wxString::Format(wxT("%d"), controller->gamespyTolerance));

	m_BtnStop->Enable(false);

	// Create worker thread
	worker = new NWNXWorker(controller, this);
	if (worker->Create() != wxTHREAD_NO_ERROR)
	{
		wxLogError(wxT("Can't create worker thread!"));
		worker->Delete();
		worker = nullptr;
	}
	else
	{
		worker->Run();
		m_BtnStart->Enable(false);
		worker->startServer();
	}

    return true;
}

/*!
 * Member initialisation 
 */

void MainFrame::Init()
{
////@begin MainFrame member initialisation
    m_startedAt = nullptr;
    m_CmdLine = nullptr;
    m_PWEnabled = nullptr;
    m_PWInterval = nullptr;
    m_PWRestarts = nullptr;
    m_GWEnabled = nullptr;
    m_GWInterval = nullptr;
    m_GWRetries = nullptr;
    m_GWRestarts = nullptr;
    m_GWLockups = nullptr;
    m_log = nullptr;
    m_BtnStart = nullptr;
    m_BtnStop = nullptr;
    m_BtnRestart = nullptr;
////@end MainFrame member initialisation
	worker = nullptr;
}
/*!
 * Control creation for MainFrame
 */

void MainFrame::CreateControls()
{    
////@begin MainFrame content construction
    // Generated by DialogBlocks, 27/01/2007 20:06:23 (Personal Edition)

    MainFrame* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu47 = new wxMenu;
    itemMenu47->Append(wxID_EXIT, _("Exit"), _(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu47, _("&File"));
    wxMenu* itemMenu49 = new wxMenu;
    itemMenu49->Append(ID_HELP, _("Online Help"), _(""), wxITEM_NORMAL);
    itemMenu49->Append(ID_FORUM, _("Open Forum"), _(""), wxITEM_NORMAL);
    itemMenu49->Append(wxID_ABOUT, _("About..."), _(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu49, _("&Help"));
    itemFrame1->SetMenuBar(menuBar);

    wxPanel* itemPanel2 = new wxPanel( itemFrame1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer5Static = new wxStaticBox(itemPanel2, wxID_ANY, _("NWN Server"));
    wxStaticBoxSizer* itemStaticBoxSizer5 = new wxStaticBoxSizer(itemStaticBoxSizer5Static, wxHORIZONTAL);
    itemBoxSizer4->Add(itemStaticBoxSizer5, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
    itemFlexGridSizer6->AddGrowableCol(1);
    itemStaticBoxSizer5->Add(itemFlexGridSizer6, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemPanel2, wxID_STATIC, _("Started at:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(itemStaticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_startedAt = new wxTextCtrl( itemPanel2, ID_TEXTCTRL1, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_startedAt->Enable(false);
    itemFlexGridSizer6->Add(m_startedAt, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemPanel2, wxID_STATIC, _("Command line:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer6->Add(itemStaticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_CmdLine = new wxTextCtrl( itemPanel2, ID_TEXTCTRL2, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_CmdLine->Enable(false);
    itemFlexGridSizer6->Add(m_CmdLine, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBitmap itemStaticBitmap11Bitmap(itemFrame1->GetBitmapResource(wxT("res/nwnx4_logo.xpm")));
    wxStaticBitmap* itemStaticBitmap11 = new wxStaticBitmap( itemPanel2, wxID_STATIC, itemStaticBitmap11Bitmap, wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(64, 64)), 0 );
    itemBoxSizer4->Add(itemStaticBitmap11, 0, wxALIGN_CENTER_VERTICAL|wxLEFT, 10);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer12, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer13Static = new wxStaticBox(itemPanel2, wxID_ANY, _("Process watchdog"));
    wxStaticBoxSizer* itemStaticBoxSizer13 = new wxStaticBoxSizer(itemStaticBoxSizer13Static, wxVERTICAL);
    itemBoxSizer12->Add(itemStaticBoxSizer13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer14 = new wxFlexGridSizer(0, 3, 0, 0);
    itemStaticBoxSizer13->Add(itemFlexGridSizer14, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemPanel2, wxID_STATIC, _("Enabled"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(itemStaticText15, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_PWEnabled = new wxCheckBox( itemPanel2, ID_PW_ENABLED, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_PWEnabled->SetValue(true);
    itemFlexGridSizer14->Add(m_PWEnabled, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer14->Add(4, 4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel2, wxID_STATIC, _("Interval:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(itemStaticText18, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_PWInterval = new wxTextCtrl( itemPanel2, ID_TEXTCTRL3, _(""), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_PWInterval->Enable(false);
    itemFlexGridSizer14->Add(m_PWInterval, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText20 = new wxStaticText( itemPanel2, wxID_STATIC, _("seconds"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(itemStaticText20, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    wxStaticText* itemStaticText21 = new wxStaticText( itemPanel2, wxID_STATIC, _("Restarts:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(itemStaticText21, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_PWRestarts = new wxTextCtrl( itemPanel2, ID_TEXTCTRL4, _("0"), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_PWRestarts->Enable(false);
    itemFlexGridSizer14->Add(m_PWRestarts, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText23 = new wxStaticText( itemPanel2, wxID_STATIC, _("crashes"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer14->Add(itemStaticText23, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    wxStaticBox* itemStaticBoxSizer24Static = new wxStaticBox(itemPanel2, wxID_ANY, _("Gamespy watchdog"));
    wxStaticBoxSizer* itemStaticBoxSizer24 = new wxStaticBoxSizer(itemStaticBoxSizer24Static, wxVERTICAL);
    itemBoxSizer12->Add(itemStaticBoxSizer24, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer25 = new wxFlexGridSizer(0, 5, 0, 0);
    itemStaticBoxSizer24->Add(itemFlexGridSizer25, 0, wxALIGN_LEFT|wxALL, 5);

    wxStaticText* itemStaticText26 = new wxStaticText( itemPanel2, wxID_STATIC, _("Enabled"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText26, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_GWEnabled = new wxCheckBox( itemPanel2, ID_GW_ENABLED, _(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_GWEnabled->SetValue(true);
    itemFlexGridSizer25->Add(m_GWEnabled, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer25->Add(4, 4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer25->Add(4, 4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemFlexGridSizer25->Add(4, 4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText31 = new wxStaticText( itemPanel2, wxID_STATIC, _("Interval:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText31, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_GWInterval = new wxTextCtrl( itemPanel2, ID_TEXTCTRL, _(""), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_GWInterval->Enable(false);
    itemFlexGridSizer25->Add(m_GWInterval, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText33 = new wxStaticText( itemPanel2, wxID_STATIC, _("seconds"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText33, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_GWRetries = new wxTextCtrl( itemPanel2, ID_TEXTCTRL6, _(""), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_GWRetries->Enable(false);
    itemFlexGridSizer25->Add(m_GWRetries, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText35 = new wxStaticText( itemPanel2, wxID_STATIC, _("retries"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText35, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    wxStaticText* itemStaticText36 = new wxStaticText( itemPanel2, wxID_STATIC, _("Restarts:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText36, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_GWRestarts = new wxTextCtrl( itemPanel2, ID_TEXTCTRL5, _("0"), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_GWRestarts->Enable(false);
    itemFlexGridSizer25->Add(m_GWRestarts, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText38 = new wxStaticText( itemPanel2, wxID_STATIC, _("crashes"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText38, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_GWLockups = new wxTextCtrl( itemPanel2, ID_TEXTCTRL7, _("0"), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(26, -1)), 0 );
    m_GWLockups->Enable(false);
    itemFlexGridSizer25->Add(m_GWLockups, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText40 = new wxStaticText( itemPanel2, wxID_STATIC, _("lockups"), wxDefaultPosition, wxDefaultSize, 0 );
    itemFlexGridSizer25->Add(itemStaticText40, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxFIXED_MINSIZE, 5);

    m_log = new wxTextCtrl( itemPanel2, ID_TEXTCTRL_LOG, _(""), wxDefaultPosition, itemPanel2->ConvertDialogToPixels(wxSize(-1, 46)), wxTE_MULTILINE );
    itemBoxSizer3->Add(m_log, 0, wxGROW|wxALL, 10);

    wxBoxSizer* itemBoxSizer42 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer3->Add(itemBoxSizer42, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    m_BtnStart = new wxButton( itemPanel2, ID_BTNSTART, _("Start"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer42->Add(m_BtnStart, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BtnStop = new wxButton( itemPanel2, ID_BTNSTOP, _("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer42->Add(m_BtnStop, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_BtnRestart = new wxButton( itemPanel2, ID_BTNRESTART, _("Restart"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer42->Add(m_BtnRestart, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end MainFrame content construction

    SetClientSize(600, 450);
}

/*!
 * Should we show tooltips?
 */

bool MainFrame::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap MainFrame::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin MainFrame bitmap retrieval
    wxUnusedVar(name);
    if (name == _("res/nwnx4_logo.xpm"))
    {
        wxBitmap bitmap(nwnx4_logo_xpm);
        return bitmap;
    }
    return wxNullBitmap;
////@end MainFrame bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon MainFrame::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin MainFrame icon retrieval
    wxUnusedVar(name);
    if (name == _("res/nwnx4_icon.xpm"))
    {
        wxIcon icon(nwnx4_icon_xpm);
        return icon;
    }
    return wxNullIcon;
////@end MainFrame icon retrieval
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTNSTART
 */

void MainFrame::OnBtnstartClick( wxCommandEvent& event )
{
	if (worker)
	{
		m_BtnStart->Enable(false);
		worker->startServer();
	}
}


/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTNSTOP
 */

void MainFrame::OnBtnstopClick( wxCommandEvent& event )
{
	if (worker)
	{
		m_BtnStop->Enable(false);
		worker->stopServer();
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_RESTART
 */

void MainFrame::OnBtnrestartClick( wxCommandEvent& event )
{
	m_BtnStart->Enable(false);
	m_BtnStop->Enable(false);
	m_BtnRestart->Enable(false);
	worker->restartServer();
}


void MainFrame::OnServerStarted(wxCommandEvent &event)
{
    m_BtnStart->Enable(false);
	m_BtnStop->Enable(true);
	m_BtnRestart->Enable(true);
}

void MainFrame::OnServerStopped(wxCommandEvent &event)
{
    m_BtnStart->Enable(true);
	m_BtnStop->Enable(false);
	m_BtnRestart->Enable(false);
}

/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX1
 */

void MainFrame::OnPwEnabledClick( wxCommandEvent& event )
{
	controller->processWatchdog = m_PWEnabled->GetValue();
	if (controller->processWatchdog)
		wxLogMessage(wxT("Process watchdog set to: enabled"));
	else
		wxLogMessage(wxT("Process watchdog set to: disabled"));
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHECKBOX
 */

void MainFrame::OnGwEnabledClick( wxCommandEvent& event )
{
	controller->gamespyWatchdog = m_GWEnabled->GetValue();
	if (controller->gamespyWatchdog)
		wxLogMessage(wxT("Gamespy watchdog set to: enabled"));
	else
		wxLogMessage(wxT("Gamespy watchdog set to: disabled"));
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_EXIT
 */

void MainFrame::OnEXITClick( wxCommandEvent& event )
{
	Close();
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM
 */

void MainFrame::OnHelpClick( wxCommandEvent& event )
{
	wxString url = wxT("http://www.nwnx.org/index.php?id=docs");
	bool ok = false;

	wxFileType *ft = wxTheMimeTypesManager->GetFileTypeFromExtension(wxT("html"));
	if (ft)
	{
		wxString cmd;
		ok = ft->GetOpenCommand(&cmd, wxFileType::MessageParameters(url, wxEmptyString));
		delete ft;

		if (ok)
			ok = (wxExecute(cmd, wxEXEC_ASYNC) != 0);
		else
			wxLogMessage(wxT("Could not start webbrowser. Check your installation."));
	}
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_FORUM
 */

void MainFrame::OnForumClick( wxCommandEvent& event )
{
	wxString url = wxT("http://nwnx.org/index.php?id=forum");
	bool ok = false;

	wxFileType *ft = wxTheMimeTypesManager->GetFileTypeFromExtension(wxT("html"));
	if (ft)
	{
		wxString cmd;
		ok = ft->GetOpenCommand(&cmd, wxFileType::MessageParameters(url, wxEmptyString));
		delete ft;

		if (ok)
			ok = (wxExecute(cmd, wxEXEC_ASYNC) != 0);
		else
			wxLogMessage(wxT("Could not start webbrowser. Check your installation."));
	}
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for wxID_ABOUT
 */

void MainFrame::OnABOUTClick( wxCommandEvent& event )
{
	AboutDialog *dlg = 
		new AboutDialog(this, -1, wxT("About NWNx4"), wxPoint(100,100), wxSize(200,200),
		wxDEFAULT_FRAME_STYLE |
		wxRESIZE_BORDER);
	dlg->ShowModal();
}

void MainFrame::OnClose(wxCloseEvent& event) {
    worker->killServer();
}

void MainFrame::OnServerKilled(wxCommandEvent &event) {
    Destroy();
}
