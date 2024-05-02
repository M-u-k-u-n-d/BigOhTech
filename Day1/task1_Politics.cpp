#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class representing a Member of Parliament (MP)

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
    Driver(string name, int age):Person(name,age){};

    string getDriver(){
        return name;
    }
};

class MP : public Person {
public:
    string constituency;
    int spendingLimit, spendings;
    MP(){};
    MP(string constituency, string name, int age,int spendingLimit,int spendings) : Person(name,age), constituency(constituency),spendingLimit(spendingLimit),spendings(spendings) {};

    string getConstituency() {
        return constituency;
    }
    int getSpendingLimit(){
        return spendingLimit;
    }
    int getSpendings(){
        return spendings;
    }
};

// Class representing a Minister, inheriting from MP
class Minister : public MP {
public:
    Minister(string constituency,string name, int age,int spendingLimit,int spendings) : MP(constituency,name,age,spendingLimit,spendings) {}
    string getConstituency() {
        return constituency;
    }
    int getSpendingLimit(){
        return spendingLimit;
    }
    int getSpendings(){
        return spendings;
    }
};

// Class representing the Prime Minister, inheriting from MP
class PrimeMinister : public MP {
public:
    bool permission;
    PrimeMinister(string constituency,string name, int age,int spendingLimit,int spendings,bool permission) : MP(constituency,name,age,spendingLimit,spendings),permission(permission) {}  
    // Function to check if the Prime Minister can give permission to arrest
    bool canGivePermission() {
        return permission; 
    }
};

// Class representing the Commissioner
class Commissioner:public Person{
    public:
    Commissioner(){};
    Commissioner(string name,int age):Person(name,age){}
    bool canArrest(MP mp){
        if((mp.getSpendings()>mp.getSpendingLimit())){
            return true;
        }
       return false;
    }
    bool canArrest(PrimeMinister &pm){
        return false;
    }
    bool canArrest(PrimeMinister pm,Minister minister){ 
        if(minister.getSpendings()>minister.getSpendingLimit() && (pm.canGivePermission())){
            return true;
        }
        return false;
    }
};

int main() {
    Commissioner commissioner("comm_name",64);

    // Create some MPs, Ministers, and Prime Minister instances
    MP mp1("cons1","mp_name",65,100,103);
    Minister minister1("cons2","mini_name",47,5000,2100);
    PrimeMinister pm("cons3","pm_name",56,1000,2500,true);

    // Test arresting
    if(commissioner.canArrest(mp1)) cout <<"MP Arrested"<<endl;
    else cout << "MP Not Arrested"<<endl;
    if(commissioner.canArrest(minister1)) cout <<"Minister Arrested"<<endl;
    else cout << "Minister Not Arrested"<<endl;
    if(commissioner.canArrest(pm)) cout <<"PM Arrested"<<endl;
    else cout << "PM Not Arrested"<<endl;
}
