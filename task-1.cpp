/*
Task 1: Working with STL Algorithms
Goal: Practice commonly used STL algorithms in the context of managing HMI control states (e.g., button visibility, slider values).
Scenario:
Imagine an HMI dashboard with buttons and sliders. Each control has a unique ID and a state (visible, invisible, disabled).
Steps:
Define the data structure:
Create a struct Control:
cppCopy codestruct Control {    int id;               // Unique ID    std::string type;     // "button" or "slider"    std::string state;    // "visible", "invisible", "disabled"}; 

Initialize the container:
Create a std::vector<Control> and populate it with sample controls (5 buttons and 5 sliders).
Use the following algorithms:
std::for_each: Iterate through all controls and print their details.
std::find: Find a control with a specific ID.
std::find_if: Find the first invisible control.
std::adjacent_find: Check for consecutive controls with the same state.
std::count: Count the number of visible controls.
std::count_if: Count sliders that are disabled.
std::equal: Compare two subranges of controls to check if they are identical.
Implementation Example:

cppCopy codeauto invisibleControl = std::find_if(controls.begin(), controls.end(),    [](const Control& ctrl) { return ctrl.state == "invisible"; }); 

Output Results:
Print the results of each algorithm in a user-friendly format.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Control {    
    // Unique ID    
    int id;               
    // "button" or "slider"    
    std::string type;     
    // "visible", "invisible", "disabled"}; 
    std::string state; 

    Control(int id,string type,string state){
        this->id=id;
        this->type=type;
        this->state=state;
    }   
};
class ControlManagement{
    vector<Control> controls;
    public:
    void addControls(const Control& control){
        controls.push_back(control);
    }
    void display(){
        for_each(controls.begin(),controls.end(),[](const Control& con){
        cout<<con.id<<" "<<con.type<<" "<<con.state<<endl;
    });
    }

    void findIfOPeration(){
        auto invisibleControl = find_if(controls.begin(), controls.end(),[](const Control& ctrl) { return ctrl.state == "invisible"; }); 
        if(invisibleControl!=controls.end()){
            cout<<invisibleControl->id<<" "<<invisibleControl->type<<" "<<invisibleControl->state<<endl;
        }else{
            cout<<"there is no invisible type controls are there..!"<<endl;
        }
    }

    void findOPeration(int id){
        auto invisibleControl = find_if(controls.begin(), controls.end(),[&](const Control& ctrl) { return ctrl.id==id; }); 
        if(invisibleControl!=controls.end()){
            cout<<invisibleControl->id<<" "<<invisibleControl->type<<" "<<invisibleControl->state<<endl;
        }else{
            cout<<"there is no object specified type controls are there..!"<<endl;
        }
    }
    void countControls(){
        int n=count_if(controls.begin(),controls.end(),[](const Control& ctrl){
            return ctrl.state=="visible";
        });
        cout<<"visible controls are : "<<n<<endl;
    }

    void count_if_Controls(){
        int n=count_if(controls.begin(),controls.end(),[](const Control& ctrl){
            return ctrl.state=="disabled" && ctrl.type=="slider";
        });
        cout<<"disable and sliders controls are : "<<n<<endl;
    }

    void adjacent_find_Controls(){
        auto it=adjacent_find(controls.begin(),controls.end(),[](const Control& a, const Control& b) {
                                return a.id == b.id && a.type == b.type && a.state == b.state;
                            });

        if(it!=controls.end()){
            cout<<(*it).id<<" "<<(*it).type<<" "<<(*it).state<<endl;
            cout<<(*(it+1)).id<<" "<<(*(it+1)).type<<" "<<(*(it+1)).state<<endl;
        }else{
            cout<<" no two controls are adjacently equal "<<endl;
        }
    }

    void equal_Controls(){
        bool it = equal(controls.begin(), controls.begin() + 5, controls.begin() + 5,
                 [](const Control& a, const Control& b) {
                     return a.id == b.id && a.type == b.type && a.state == b.state;
                 });

        if(it){
            cout<<"both are equal"<<endl;
        }else{
            cout<<"both are not equal"<<endl;
        }

    }


};

int main(){
    ControlManagement cm;
    Control c1(1,"button","visible");
    Control c2(2,"button","invisible");
    Control c3(3,"button","invisible");
    Control c4(4,"button","disabled");
    Control c5(5,"button","disabled");
    Control c6(6,"slider","disabled");
    Control c7(7,"slider","visible");
    Control c8(8,"slider","disabled");
    Control c9(9,"slider","visible");
    Control c10(10,"slider","invisible");

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
    cm.findIfOPeration();
    cm.findOPeration(9);
    cm.countControls();
    cm.count_if_Controls();
    cm.adjacent_find_Controls();
    cm.equal_Controls();
}