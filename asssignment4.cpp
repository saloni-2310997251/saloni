#include <iostream>
using namespace std;
class Computation {
	
public:
   
    int compute(int a, int b) const {
        return a + b;
    }

   
    float compute(int a, float b) const {
        return a + b;
    }

    
    double compute(int a, double b) const {
        return a + b;
    }

    
    int compute(char a, char b) const {
        return static_cast<int>(a) + static_cast<int>(b);
    }

   
    int compute(char a, int b) const {
        return static_cast<int>(a) + b;
    }

   
    int compute() const {
        
        return 0;
    }
};

int main() {
    Computation calculator;

    
    cout << "Result 1: " << calculator.compute(2, 3) << endl;
    cout << "Result 2: " << calculator.compute(5, 2.5f) << endl;
    cout << "Result 3: " << calculator.compute(7, 4.8) << endl;
    cout << "Result 4: " << calculator.compute('A', 'B') << endl;
    cout << "Result 5: " << calculator.compute('C', 10) << endl;
    cout << "Result 6: " << calculator.compute() << endl;

    return 0;
}

