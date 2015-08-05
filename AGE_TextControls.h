#include "Common.h"

//  The purpose of these custom text controls is that you get specified error messages
//  when your mouse cursor focus gets off from a data edit box.

#ifndef AGE_TextControls_h
#define AGE_TextControls_h

class AGEListView: public wxListCtrl
{
public:
    AGEListView(wxWindow *parent, const wxSize &size):
    wxListCtrl(parent, wxID_ANY, wxDefaultPosition, size, wxLC_VIRTUAL | wxLC_REPORT | wxLC_NO_HEADER)
    {
        SetItemCount(0);
        InsertColumn(0, wxEmptyString, wxLIST_FORMAT_LEFT, wxLIST_AUTOSIZE_USEHEADER);
    }

    wxArrayString names;
    vector<int> indexes;

private:
    virtual wxString OnGetItemText(long item, long column) const;
};

class AGELinkedBox
{
public:
    virtual void update(int)=0;
    virtual void enable(bool)=0;
};

class AGETextCtrl: public wxTextCtrl
{
public:
    AGETextCtrl(wxWindow *parent, int width):
    wxTextCtrl(parent, wxID_ANY, "", wxDefaultPosition, wxSize(width, 20), wxTE_PROCESS_ENTER){edits = 0;}

    static AGETextCtrl* init(const ContainerType type, forward_list<AGETextCtrl*> *group,
        wxFrame *frame, const short window, wxWindow *parent, short length = 0);
    virtual int SaveEdits(bool forced = false)=0;
    virtual void update()
    {
        if(container.empty())
        {
            Clear();
            Enable(false);
            if(!LinkedBoxes.empty())
            for(auto it = LinkedBoxes.begin(); it != LinkedBoxes.end(); ++it)
            {
                (*it)->update(-1);
                (*it)->enable(false);
            }
            return;
        }
        curFileLoaded = AGETextCtrl::fileLoaded[window];
        replenish();
        Enable(true);
    }
    virtual void replenish()=0;
    void changeContainerType(const ContainerType type)
    {
        switch(type)
        {
        case CByte: SetBackgroundColour(wxColour(255, 235, 215)); break;
        case CUByte: SetBackgroundColour(wxColour(255, 235, 215)); break;
        case CFloat: SetBackgroundColour(wxColour(255, 225, 255)); break;
        case CLong: SetBackgroundColour(wxColour(215, 255, 255)); break;
        case CShort: SetBackgroundColour(wxColour(210, 230, 255)); break;
        case CUShort: SetBackgroundColour(wxColour(210, 230, 255)); break;
        case CString: SetBackgroundColour(wxColour(220, 255, 220)); break;
        }
    }
    void clear(){container.clear();}
    void prepend(void* data){container.push_front(data);}
    void SetMaxSize(unsigned short size){MaxSize = size;}

    static const wxString BATCHWARNING, BWTITLE, IETITLE;
    // Make these window specific
    static vector<bool> hexMode, accurateFloats;
    static vector<int> unSaved, fileLoaded;
    forward_list<AGELinkedBox*> LinkedBoxes; // These are for check and combo boxes.

protected:
    void OnKillFocus(wxFocusEvent &Event){Event.Skip(); SaveEdits();}
    void OnEnter(wxCommandEvent &Event){SaveEdits(true);}

    bool BatchCheck(string &value, short &batchMode)
    {
        if(value.size() < 3) return false;
        switch((char)value[1])
        {
            case '+': batchMode = 1; value = value.substr(2); return true;
            case '-': batchMode = 2; value = value.substr(2); return true;
            case '*': batchMode = 3; value = value.substr(2); return true;
            case '/': batchMode = 4; value = value.substr(2); return true;
            case '%': batchMode = 5; value = value.substr(2); return true;
            default: return false;
        }
    }
    void HandleResults(int casted)
    {
        if(!LinkedBoxes.empty())
        for(auto it = LinkedBoxes.begin(); it != LinkedBoxes.end(); ++it)
        {
            (*it)->update(casted);
        }
        frame->SetStatusText("Edits: "+lexical_cast<string>(AGETextCtrl::unSaved[window])+" + "+lexical_cast<string>(edits), 3);
        AGETextCtrl::unSaved[window] += edits;
        edits = 0;
    }

    wxFrame* frame;
    ContainerType type;
    forward_list<void*> container; // Change to forward_list
    int curFileLoaded, window, edits;
    unsigned short MaxSize;
};

class TextCtrl_DLL: public wxTextCtrl
{
public:
    TextCtrl_DLL(wxWindow *parent, wxSize dimensions):
    wxTextCtrl(parent, wxID_ANY, "", wxDefaultPosition, dimensions, wxTE_MULTILINE | wxTE_PROCESS_ENTER){}

    int index;
};

class TextCtrl_Byte: public AGETextCtrl
{
public:
    TextCtrl_Byte(wxFrame *frame, int window, wxWindow *parent, bool petit = false):
    AGETextCtrl(parent, petit ? 30 : 50)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(255, 235, 215));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_Byte::OnKillFocus, this);    // Must-have
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_Byte::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_UByte: public AGETextCtrl
{
public:
    TextCtrl_UByte(wxFrame *frame, int window, wxWindow *parent):
    AGETextCtrl(parent, 50)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(255, 235, 215));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_UByte::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_UByte::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_Float: public AGETextCtrl
{
public:
    TextCtrl_Float(wxFrame *frame, int window, wxWindow *parent, bool petit = false):
    AGETextCtrl(parent, petit ? 70 : 100)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(255, 225, 255));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_Float::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_Float::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_Long: public AGETextCtrl
{
public:
    TextCtrl_Long(wxFrame *frame, int window, wxWindow *parent, bool petit = false):
    AGETextCtrl(parent, petit ? 50 : 100)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(215, 255, 255));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_Long::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_Long::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_Short: public AGETextCtrl
{
public:
    TextCtrl_Short(wxFrame *frame, int window, wxWindow *parent, bool petit = false):
    AGETextCtrl(parent, petit ? 50 : 100)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(210, 230, 255));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_Short::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_Short::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_UShort: public AGETextCtrl
{
public:
    TextCtrl_UShort(wxFrame *frame, int window, wxWindow *parent):
    AGETextCtrl(parent, 100)
    {
        this->frame = frame;
        this->window = window;
        SetBackgroundColour(wxColour(210, 230, 255));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_UShort::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_UShort::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

class TextCtrl_String: public AGETextCtrl
{
public:
    TextCtrl_String(wxFrame *frame, int window, wxWindow *parent, unsigned short CLength = 0):
    AGETextCtrl(parent, 0)
    {
        this->frame = frame;
        this->window = window;
        MaxSize = CLength;
        SetBackgroundColour(wxColour(220, 255, 220));
        Bind(wxEVT_KILL_FOCUS, &TextCtrl_String::OnKillFocus, this);
        Bind(wxEVT_COMMAND_TEXT_ENTER, &TextCtrl_String::OnEnter, this);
    }
    int SaveEdits(bool forced = false);
    void replenish();
};

#endif
