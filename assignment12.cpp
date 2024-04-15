#include <iostream>
using namespace std;
class smallUnit {
private:
    double inches;

public:
    smallUnit(double inches) : inches(inches) {}

    operator double() const {
        return inches;
    }
};

class largerUnit {
private:
    double feet;

public:
    largerUnit(double feet) : feet(feet) {}

    void display() const {
        cout << "Measurement in feet: " << feet << endl;
    }

    largerUnit& operator=(const smallUnit& su) {
        feet = su; 
        return *this;
    }
};

int main() {
	
    smallUnit smallObj(12.0); 

    largerUnit largeObj = smallObj;

    largeObj.display();

    cout << "Measurement in inches: " << static_cast<double>(largeObj) << endl;

    return 0;
}

