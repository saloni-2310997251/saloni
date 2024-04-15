#include <iostream>
using namespace std;
class Matrix3x3 {
private:
    int data[3][3];

public:
   
    Matrix3x3() {
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0;
            }
        }
    }

    
    Matrix3x3 operator+(const Matrix3x3& other) const {
        Matrix3x3 result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    void setValue(int row, int col, int value) {
        data[row][col] = value;
    }


    void display() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << data[i][j] << " ";
            }
            cout <<endl;
        }
    }
};

int main() {

    Matrix3x3 OBJ1;

    OBJ1.setValue(0, 0, 1);
    OBJ1.setValue(1, 1, 1);
    OBJ1.setValue(2, 2, 1);

    Matrix3x3 OBJ2;

    OBJ2.setValue(0, 0, 2);
    OBJ2.setValue(1, 1, 2);
    OBJ2.setValue(2, 2, 2);

    Matrix3x3 OBJ3 = OBJ1 + OBJ2;

    cout << "Result of matrix addition:" <<endl;
    OBJ3.display();

    return 0;
}

