//
// Created by mukund on 19-08-2026.
//
// 1. Write distance class with data members feet & inches.
// Write constructors, getter/setter, add() to add two distances.
// Implement exception handling as appropriate.

#include <iostream>
using namespace std;

class Distance {
    int feet;
    int inches;

public:
    Distance(int feet = 0, int inches = 0) {
        this->feet = feet;
        this->inches = inches;
    }
    ~Distance() {
        cout << "~Distance() called" << endl;
    }
    void set_feet(int feet) {
        if (feet < 0)
            throw "Feet can't be negative";
        this->feet = feet;

    }
    void set_inches(int inches) {
        if (inches < 0 || inches > 11)
            throw "Inches must be between 0 and 12";
        this->inches = inches;
    }

    int get_feet() {
        return this->feet;
    }
    int get_inches() {
        return this->inches;
    }

    void add(Distance d) {
        this->feet += d.feet;
        this->inches += d.inches;
        if (this->inches >= 12) {
            this->inches -= 12;
            this->feet += 1;
        }
    }

    void display(){
        cout << "Distance: " << feet << "'" << inches << "\"" << endl;
    }
};

int main() {
    Distance d1(12, 3);
    Distance d2(7, 11);
    try {
        d1.display();
        d2.display();
        d1.add(d2);
        d1.display();
        d1.set_feet(11);
        d1.set_inches(32);
    }
    catch (const char* err){
        cout << err << endl;
    }
    return 0;
}