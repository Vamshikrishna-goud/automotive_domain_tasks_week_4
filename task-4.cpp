/*
Task 4: Sorting, Searching, and Merging
Goal: Practice sorting, searching, and merging in an HMI-related context.
Scenario:
A new feature requires merging two lists of controls into a single sorted list for efficient access.
Steps:
Sorting:
Sort the controls by their ID using std::sort.
Use std::stable_sort to maintain relative order for controls with equal IDs.
Binary Search:
Search for a control by ID using std::lower_bound and std::upper_bound.
Merging:
Merge two sorted lists of controls using std::merge.
Use std::inplace_merge to combine controls from two different segments in the same list.
Set Operations:
Use std::set_union and std::set_intersection to identify common and unique controls.
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <set>
#include <list>
using namespace std;

struct Control
{
    // Unique ID
    int id;
    // "button" or "slider"
    std::string type;
    // "visible", "invisible", "disabled"};
    std::string state;

    Control() : id(0), type(""), state("") {}

    Control(int id, string type, string state)
    {
        this->id = id;
        this->type = type;
        this->state = state;
    }

    bool operator<(const Control& other) const {
        return id < other.id;
    }
};

class ControlManagement
{
    vector<Control> controls;
    list<Control> Control1;
    list<Control> Control2;

public:
    void addControls(const Control &control)
    {
        controls.push_back(control);
    }

    void addControlsToList1(const Control &control){
        Control1.push_back(control);
    }

    void addControlsToList2(const Control &control){
        Control2.push_back(control);
    }
    void display()
    {
        for_each(controls.begin(), controls.end(), [](const Control &con)
                 { cout << con.id << " " << con.type << " " << con.state << endl; });
    }

    void sortControls()
    {
        sort(controls.begin(), controls.end(), [](const Control &con, const Control &con1)
             { return con.id > con1.id; });
    }

    void stable_sortControls()
    {
        stable_sort(controls.begin(), controls.end(), [](const Control &con, const Control &con1)
                    { return con.id > con1.id; });
    }

    void searchUsingLower_bound(const Control& con)
    {
        auto it = lower_bound(controls.begin(), controls.end(), con);
        if (it != controls.end())
        {
            cout << "it was found ...!" << endl;
        }
        else
        {
            cout << "it was not found...!" << endl;
        }
    }

    void searchUsingUpper_bound(const Control& con)
    {
        auto it = upper_bound(controls.begin(), controls.end(), con);
        if (it != controls.end())
        {
            cout << "it was found ...!" << endl;
        }
        else
        {
            cout << "it was not found...!" << endl;
        }
    }

    void mergeTwoLists(){
            list<Control> ControlCombined(10);
        merge(Control1.begin(),Control1.end(),Control2.begin(),Control2.end(),ControlCombined.begin());
        cout<<endl;
        for_each(ControlCombined.begin(), ControlCombined.end(), [](const Control &con)
                 { cout << con.id << " " << con.type << " " << con.state << endl; });
    }

    void inPlaceMergeTwoLists(){
        inplace_merge(controls.begin(),controls.begin()+5,controls.end());
        cout<<endl;
        for_each(controls.begin(), controls.end(), [](const Control &con)
                 { cout << con.id << " " << con.type << " " << con.state << endl; });
    }

    void set_Union_And_Set_Intersection(){
        list<Control> ControlCombined(10);
        set_union(Control1.begin(),Control1.end(),Control2.begin(),Control2.end(),ControlCombined.begin());
        for_each(controls.begin(), controls.end(), [](const Control &con)
                 { cout << con.id << " " << con.type << " " << con.state << endl; });
        cout<<endl;
        set_intersection(Control1.begin(),Control1.end(),Control2.begin(),Control2.end(),ControlCombined.begin());
        for_each(controls.begin(), controls.end(), [](const Control &con)
                 { cout << con.id << " " << con.type << " " << con.state << endl; });
        
    }
};

int main()
{
    ControlManagement cm;
    Control c1(1, "button", "visible");
    Control c2(2, "button", "invisible");
    Control c3(2, "button", "invisible");
    Control c4(2, "button", "disabled");
    Control c5(5, "button", "disabled");
    Control c6(6, "slider", "disabled");
    Control c7(7, "slider", "visible");
    Control c8(8, "slider", "disabled");
    Control c9(9, "slider", "visible");
    Control c10(10, "slider", "invisible");

    cm.addControls(c1);
    cm.addControls(c2);
    cm.addControls(c3);
    cm.addControls(c4);
    cm.addControls(c5);
    cm.addControls(c6);
    cm.addControls(c7);
    cm.addControls(c8);
    cm.addControls(c9);
    cm.addControls(c10);

    cm.display();
    // cm.sortControls(); 
    // cout<<endl;
    // cm.display();

    cm.stable_sortControls();
    cout << endl;
    cm.display();

    cout<<endl;
    cm.searchUsingLower_bound(c1);
    cm.searchUsingUpper_bound(c8);

    cm.addControlsToList1(c1);
    cm.addControlsToList1(c2);
    cm.addControlsToList1(c3);
    cm.addControlsToList1(c4);
    cm.addControlsToList1(c5);

    cm.addControlsToList1(c6);
    cm.addControlsToList1(c7);
    cm.addControlsToList1(c8);
    cm.addControlsToList1(c9);
    cm.addControlsToList1(c10);

    cm.mergeTwoLists();
    cm.inPlaceMergeTwoLists();
    cout<<endl;
    cm.set_Union_And_Set_Intersection();
    
}