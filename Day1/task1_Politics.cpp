#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(){};
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Driver : public Person{
    public:
    Driver(){};
    Driver(string name, int age) : Person(name,age){};

    string getDriver(){
        return name;
    }

};

class MP:public Person {
public:
    int spendingLimit, expenditure;
    string consistuency;
    MP(){};
    MP(int spendingLimit, int expenditure,string consistuency, string name, int age):Person(name,age) {
        this->spendingLimit = spendingLimit;
        this->expenditure = expenditure;
        this->consistuency = consistuency;
    }

    bool canArrest() {
        if(expenditure > spendingLimit) 
            return true;
        return false;
    }

    string getConsistuency(){
        return consistuency;
    }
};


class PM : public MP{
public:
    PM(){};
    PM(int spendingLimit, int expenditure,string consistuency, string name, int age):MP(spendingLimit,expenditure,consistuency,name,age){}
    bool canArrest() {
        return false;
    }

    bool haveSpecialPermission() {
        return true;
    }
};

class Ministers : public MP {
public: 
    // You need to pass spendingLimit and expenditure to the Ministers constructor
    Ministers(int spendingLimit, int expenditure,string consistuency, string name,int age) : MP(spendingLimit, expenditure,consistuency,name,age) {}
    Ministers(){};
    bool canArrest() {
        PM pm; // Create an instance of PM
        if(expenditure > spendingLimit && pm.haveSpecialPermission()) {
            return true;
        }
        return false;
    }
};


int main() {
// (spending Limit, Expenditure,name,age)
    MP mp(100000, 1200, "Rahul","Waiynad", 47);
    if(mp.canArrest()) {
        cout << "MP can arrest"<<endl;
    }
    else {
        cout << "MP Not arrested"<<endl;
    }

    Ministers minister(1000000, 2800,"Anubhav","Varanasi",28);
    if(minister.canArrest()){
        cout << " Minister can arrest, Name = "<< minister.name<<endl;
    }
    else{
        cout << "Minister Not Arrested"<<endl;
    }

    PM pm(10000000,44845,"Narender Modi","Gujrat", 70);

    if(pm.canArrest()){
        cout << "PM arrested";
    }
    else{
        cout << "PM not arrested, " <<pm.name<<endl;
    }
    cout << "consistuency : "<<pm.getConsistuency()<<endl;
}
