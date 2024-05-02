#include <bits/stdc++.h>
using namespace std;
// Base class for all inverters
class Inverter {
public:
    string type;
    double powerRating;

    Inverter(string type, double powerRating) : type(type), powerRating(powerRating) {}

    virtual void displayInfo() {
        cout << "Type: " << type << endl;
        cout << "Power Rating: " << powerRating << endl;
    }
};

// Solar Inverter
class SolarInverter : public Inverter {
public:
    bool hasSolarPanels;
    bool hasBattery;
    bool hasGrid;
    SolarInverter(string type, double powerRating, bool hasSolarPanels, bool hasBattery,bool hasGrid)
        : Inverter(type, powerRating), hasSolarPanels(hasSolarPanels), hasBattery(hasBattery), hasGrid(hasGrid) {}

    void displayInfo() {
        cout << "Solar Panels: " << (hasSolarPanels ? "Yes" : "No") << endl;
        cout << "Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << "Grid: "<<(hasGrid ? "Yes" : "No") <<endl;
    }
};

// PCU 
class PCU : public SolarInverter {
public:
    PCU(double powerRating, bool hasSolarPanels, bool hasBattery,bool hasGrid)
        : SolarInverter("PCU", powerRating, hasSolarPanels, hasBattery,hasGrid) {}

    void displayInfo() {
        cout << "Solar Panels: " << (hasSolarPanels ? "Yes" : "No") << endl;
        cout << "Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << "Power Rating: "<<powerRating <<endl;
        cout << "Grid: "<<(hasGrid ? "Yes" : "No") <<endl;
    }
};

// GTI 
class GTI : public SolarInverter {
public:
    GTI(double powerRating, bool hasSolarPanels,bool hasGrid)
        : SolarInverter("GTI", powerRating, hasSolarPanels, false,hasGrid) {}

    void displayInfo() {
        cout << "Solar Panels: " << (hasSolarPanels ? "Yes" : "No") << endl;
        cout << "Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << "Power Rating: "<<powerRating <<endl;
        cout << "Grid: "<<(hasGrid ? "Yes" : "No") <<endl;
    }
};

// Regalia Inverter
class Regalia : public SolarInverter {
public:
    Regalia(double powerRating, bool hasSolarPanels, bool hasBattery,bool hasGrid)
        : SolarInverter("Regalia", powerRating, hasSolarPanels, hasBattery, hasGrid) {}

    void displayInfo() {
        cout << "Solar Panels: " << (hasSolarPanels ? "Yes" : "No") << endl;
        cout << "Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << "Power Rating: "<<powerRating <<endl;
        cout << "Grid: "<<(hasGrid ? "Yes" : "No") <<endl;

    }
};



int main() {

    PCU pcu(5000, true, true,false);
    pcu.displayInfo();

    cout << endl;

    GTI gti(4000, true,true);
    gti.displayInfo();

    cout << endl;

    Regalia regalia(6000, true, false,false);
    regalia.displayInfo();

    return 0;
}
