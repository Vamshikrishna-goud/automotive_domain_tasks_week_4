/*
Task 5: Implementing Design Patterns in HMI
Goal: Implement and understand the Singleton, Factory, Observer, and Strategy design patterns.
Steps:
Singleton:
Implement a singleton class HMISystem to manage the overall HMI state.
Factory:
Create a factory to instantiate different types of controls (Button, Slider, etc.).
Observer:
Implement an observer to notify widgets when the system switches modes (e.g., Day/Night mode).
Strategy:
Use the strategy pattern to define different rendering behaviors (e.g., 2D vs. 3D).
Implementation Example (Observer Pattern):
 
class ModeObserver {
public:    
virtual void update(const std::string& mode) = 0;
};
class Button : public ModeObserver {
    void update(const std::string& mode) override {
            if (mode == "Night") {
                        // Adjust visibility        
            }   
    }
}; 
*/
#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>
using namespace std;

//singleton pattern
class HMISystem{
    static HMISystem* instance;
    string state;
    HMISystem(){
        state="idle";
    }
    HMISystem(const HMISystem &) = delete;
    HMISystem& operator=(const HMISystem &)= delete;

    public:
    static HMISystem* getInstance(){
        if(instance==nullptr)
            instance=new HMISystem();
        return instance;
    }
    void setState(const string& s){
        this->state=s;
    }
    string getState(){
        return this->state;
    }

};

HMISystem* HMISystem::instance=nullptr;


//abstract factory
class Control{
    public:
    virtual void createControl()=0;
};

//concrete factories
class SlideControl : public Control{
    public:
    void createControl(){
        cout<<"slide control created..!"<<endl;
    }
};
class ButtonControl : public Control{
    public:
    void createControl(){
        cout<<"button control created..!"<<endl;
    }
};

//factory class
class ControlFactory{
    public:
    static Control* createControl(const string& s){
        if(s=="SlideControl"){
            return new SlideControl();
        }else if(s=="ButtonControl"){
            return new ButtonControl();
        }else{
            return nullptr;
        }
    }
};


//observer pattern
class ModeObserver {
public:    
virtual void update(const std::string& mode) = 0;
};

class Mode{
    public:
    virtual void attach(ModeObserver* observer)=0;
    virtual void detach(ModeObserver* observer)=0;
    virtual void notify()=0;
};

class Button : public ModeObserver {
    void update(const std::string& mode) override {
        cout<<"Button updated : ";
            if (mode == "Night") {    
                cout<<"mode is night"<<endl;
            }else{
                cout<<"mode is day"<<endl;
            }
    }
}; 
class Slider : public ModeObserver {
    void update(const std::string& mode) override {
        cout<<"Slider updated : ";
            if (mode == "Night") {    
                cout<<"mode is night"<<endl;
            }else{
                cout<<"mode is day"<<endl;
            }  
    }
}; 

class ConcreteMode : public Mode{
    list<ModeObserver*> observers;
    string mode;
    public:
    void setMode(const string& mode){
        this->mode=mode;
        notify();
    }
    void attach(ModeObserver* observer){
        observers.push_back(observer);
    }
    void detach(ModeObserver* observer){
        auto it=find_if(observers.begin(),observers.end(),[&](ModeObserver* observer){
            return observer==observer;
        });
        observers.erase(it);
    }
    void notify(){
        for(auto i:observers){
            i->update(mode);
        }
    }
};



//strategy model
class Behaviour{
    public:
    virtual void setStrategy()=0;
};

class Behavior_2D : public Behaviour{
    public:
    void setStrategy(){
        cout<<"This is 2D behaviour...!"<<endl;
    }
};
class Behavior_3D : public Behaviour{
    public:
    void setStrategy(){
        cout<<"This is 3D behaviour...!"<<endl;
    }
};

class Behaviour_Strategy{
    Behaviour* instance;
    public:
    void makeStrategy(Behaviour* instance){
        this->instance=instance;
    }
    void setStrategy(){
        if(instance){
            instance->setStrategy();
        }else{
            cout<<"strategy not set...!"<<endl;
        }
    }
};


int main(){
    HMISystem* hmi=HMISystem::getInstance();
    cout<<hmi->getState()<<endl;
    hmi->setState("sleepmode");
    cout<<hmi->getState()<<endl;

    cout<<endl;
    // Control* ptr=ControlFactory::createControl("ButtonControl");
    Control* ptr=ControlFactory::createControl("SlideControl");
    if(ptr){
        ptr->createControl();
    }else{
        cout<<"no control is created...!"<<endl;
    }

    cout<<endl;
    //observer pattern
    ConcreteMode c;
    Button b;
    Slider s;
    c.attach(&b);
    c.attach(&s);
    c.setMode("Night");

    cout<<endl;
    Behaviour_Strategy bs;

    Behavior_3D obj;
    bs.makeStrategy(&obj);
    bs.setStrategy();

}