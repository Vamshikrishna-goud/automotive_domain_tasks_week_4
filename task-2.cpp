/*
Task 2: Iterating Through Containers and Finding Elements
Goal: Practice iterating through containers and retrieving specific elements.
Scenario:
You are tasked with highlighting all active widgets on the HMI screen. The HMI has two main containers:
std::vector for dynamic widgets.
std::set for static widgets.
Steps:
Populate Containers:
Initialize a std::vector<std::string> with dynamic widgets ("Speedometer", "Tachometer", etc.).
Initialize a std::set<std::string> with static widgets ("Logo", "WarningLights").
Use Iterators:
Print all dynamic widgets using an iterator.
Check if a specific widget (e.g., "WarningLights") is in the std::set using std::set::find.
Advanced Iteration:
Combine both containers into a std::vector<std::string> using std::copy.
Use std::find to locate a specific widget in the combined container.
Output Results:
Print the widget list dynamically and show results of widget searches.
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class WidgetsOfHmiScreen{

    vector<string> dynamicWidgets={"Speedometer","Tachometer","ClimateControl","ZoneControl"};
    set<string> staticWidgets={"Logo", "WarningLights","Labels","Buttons"};
    vector<string> widgetsCombined;
    public:
    void displayDynamicWidgets(){
        cout<<"dynamiv widgets :"<<endl;
        for(auto it=dynamicWidgets.begin();it!=dynamicWidgets.end();it++){
            cout<<*it<<endl;
        }
        cout<<endl;
    }
    void findStaticWidget(const string& s){
        auto it=staticWidgets.find(s);
        if(it!=staticWidgets.end()){
            cout<<s<<" staticwidget is persent ."<<endl;
        }else{
            cout<<s<<" is not present."<<endl;
        }
    }
    void copyWidgets(){
        widgetsCombined.resize(8);
        copy(dynamicWidgets.begin(),dynamicWidgets.end(),widgetsCombined.begin());
        copy(staticWidgets.begin(),staticWidgets.end(),widgetsCombined.begin()+4);
        for(auto i: widgetsCombined){
            cout<<i<<endl;
        }
    }
    void findInAllWidgets(const string& s){
        auto it=find(widgetsCombined.begin(),widgetsCombined.end(),s);
        if(it!=widgetsCombined.end()){
            cout<<s<<" widget is persent ."<<endl;
        }else{
            cout<<s<<" is not present."<<endl;
        }
    }
};
int main(){
    WidgetsOfHmiScreen w;
    w.displayDynamicWidgets();
    w.findStaticWidget("WarningLights");
    w.copyWidgets();
    w.findInAllWidgets("Logo");

}

