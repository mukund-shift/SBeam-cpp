// 1. Distance class - overload+, -, ++, --, <<, >> operators. 
// Also consider adding number (feet) to the distance object.
//  Implement all operators as friend functions.
// 2. Time class - overload++, -- operators as member functions.

#include <iostream>
using namespace std;

class Distance{
    int feet;
    int inches;
    public:
    Distance(int f = 0, int i = 0): feet(f), inches(i){}
    ~Distance(){}
    void display(){
        cout << "Distance: " << feet << "' " << inches << "\"" << endl; 
    }

    Distance operator+(const Distance &d){
        Distance temp;
        temp.feet = this->feet + d.feet;
        temp.inches = this->inches + d.inches;
        if (temp.inches >= 12){
            temp.feet++;
            temp.inches -= 12;
        }
    }
    Distance operator-(const Distance &d){      // allows negative distance if d1 < d2 in (d1 - d2)
        Distance temp;
        temp.feet = this->feet - d.feet;
        temp.inches = this->inches - d.inches;
        if (temp.inches < 0){
            temp.feet--;
            temp.inches += 12;
        }
    }
    Distance operator++(int dummy){                 // postfix  
        Distance temp = *this;
        this->inches++;
        if (temp.inches >= 12){
            temp.feet++;
            temp.inches -= 12;
        }
        return temp;
    }
    Distance operator--(int dummy){      // allows negative distances           // postfix
        Distance temp = *this;
        this->inches--;
        if (temp.inches < 0){
            temp.feet--;
            temp.inches += 12;
        }
        return temp;
    }
    Distance& operator++(){                     //prefix
        this->inches++;
        if (this->inches >= 12){
            this->feet++;
            this->inches -= 12;
        }
        return *this;
    }
    Distance& operator--(){      // allows negative distances               //prefix
        this->inches--;
        if (this->inches < 0){
            this->feet--;
            this->inches += 12;
        }
        return *this;
    }
};