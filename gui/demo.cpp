#include <wx/sizer.h>
#include <wx/wx.h>
#include <wx/timer.h>

class BasicDrawPane;

class RenderTimer : public wxTimer
{
    BasicDrawPane* pane;
public:
    RenderTimer(BasicDrawPane* pane);
    void Notify();
    void start();
};


class BasicDrawPane : public wxPanel
{
    wxBitmap image;
public:
    BasicDrawPane(wxFrame* parent);
	
    void paintEvent(wxPaintEvent& evt);
    void paintNow();
    void render( wxDC& dc );
    
    DECLARE_EVENT_TABLE()
};

class MyFrame;

class MyApp: public wxApp
{
    bool OnInit();
    
    MyFrame* frame;
public:
        
};


RenderTimer::RenderTimer(BasicDrawPane* pane) : wxTimer()
{
    RenderTimer::pane = pane;
}

void RenderTimer::Notify()
{
    pane->Refresh();
}

void RenderTimer::start()
{
    wxTimer::Start(500);
}

IMPLEMENT_APP(MyApp)

class MyFrame : public wxFrame
{
    RenderTimer* timer;
    BasicDrawPane* drawPane;
    
public:
    MyFrame() : wxFrame((wxFrame *)NULL, -1,  wxT("Ping Pong Adventure"), wxPoint(50,50), wxSize(400,200))
    {
        wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
        drawPane = new BasicDrawPane( this );
        sizer->Add(drawPane, 1, wxEXPAND);
        SetSizer(sizer);
        
        timer = new RenderTimer(drawPane);
        Show();
        timer->start();
    }
    ~MyFrame()
    {
        delete timer;
    }
    void onClose(wxCloseEvent& evt)
    {
        timer->Stop();
        evt.Skip();
    }
    DECLARE_EVENT_TABLE()
};


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_CLOSE(MyFrame::onClose)
END_EVENT_TABLE()

bool MyApp::OnInit()
{
    frame = new MyFrame();
    frame->Show();

    return true;
} 


BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()



BasicDrawPane::BasicDrawPane(wxFrame* parent) :
wxPanel(parent)
{
    wxInitAllImageHandlers();
    image.LoadFile(wxT("pong.jpeg"), wxBITMAP_TYPE_JPEG);
}


void BasicDrawPane::paintEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void BasicDrawPane::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void BasicDrawPane::render( wxDC& dc )
{
    static bool visible = true;
    wxRect rc = GetClientRect();

    dc.Clear();
    wxImage Image = image.ConvertToImage();
    Image.Rescale(rc.width, rc.height);
    wxBitmap newBitmap = wxBitmap(Image);
    dc.DrawBitmap(newBitmap , 0, 0, false );
    wxFont myFont(rc.width/14, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    dc.SetFont(myFont);  
    dc.SetTextForeground(wxColour(106,117,210));
    wxString title = wxT("PING PONG");
    wxSize sizeTitle = dc.GetTextExtent(title);
    dc.DrawText(wxT("PING PONG"), rc.width/2 - sizeTitle.GetWidth()/2, 0);

    if(visible) {
    wxString mytext = wxT("Press any key to play");
    wxSize size = dc.GetTextExtent(mytext);
    dc.DrawText(wxT("Press any key to play"), rc.width/2 - size.GetWidth()/2, rc.height - size.GetHeight()); 
    visible = false;
    } else {
    
        visible = true;
    }
    
    
}