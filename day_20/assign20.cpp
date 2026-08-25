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

    friend Distance operator+(Distance &d1, Distance &d2);
    friend Distance operator-(Distance &d1, Distance &d2);
    friend Distance operator++(Distance &d1, int);
    friend Distance operator--(Distance &d1, int);
    friend Distance& operator++(Distance &d1);
    friend Distance& operator--(Distance &d1);
    friend ostream& operator<<(ostream& out, Distance &d);
    friend istream& operator>>(istream& in, Distance &d);

};

Distance operator+(Distance &d1, Distance &d2){
    Distance temp;
    temp.feet = d1.feet + d2.feet;
    temp.inches = d1.inches + d2.inches;
    if (temp.inches >= 12){
        temp.feet++;
        temp.inches -= 12;
    }
    return temp;
}

Distance operator-(Distance &d1, Distance &d2){
    Distance temp;
    temp.feet = d1.feet - d2.feet;
    temp.inches = d1.inches - d2.inches;
    if (temp.inches < 0){
        temp.feet--;
        temp.inches += 12;
    }
    return temp;
}

Distance operator++(Distance &d1, int){
    Distance temp = d1;
    d1.inches++;
    if (d1.inches >= 12){
        d1.feet++;
        d1.inches -= 12;
    }
    return temp;
}
Distance operator--(Distance &d1, int){
    Distance temp = d1;
    d1.inches--;
    if (d1.inches < 0){
        d1.feet--;
        d1.inches += 12;
    }
    return temp;
}
Distance& operator++(Distance &d1){
    d1.inches++;
    if (d1.inches >= 12){
        d1.feet++;
        d1.inches -= 12;
    }
    return d1;
}
Distance& operator--(Distance &d1){
    d1.inches--;
    if (d1.inches < 0){
        d1.feet--;
        d1.inches += 12;
    }
    return d1;
}

ostream& operator<<(ostream& out, Distance &d){
    out << "Distance: " << d.feet << "'" << d.inches << "\"" << endl;
    return out;
}

istream& operator>>(istream& in, Distance &d){
    in >> d.feet >> d.inches;
    return in;
}

class Time{
    int hrs;
    int mins;
    int secs;
public:
    Time(int s = 0, int m = 0, int h = 0): secs(s), mins(m), hrs(h)
    {}
    void display(){
        cout << "Time: " << hrs << ":" << mins << ":" << secs << endl;
    }
    Time operator++(int){
        Time temp = *this;
        secs++;
        if (secs >= 60){
            secs = 0;
            mins++;
            if (mins >= 60){
                mins = 0;
                hrs++;
                if (hrs >= 24){
                    hrs = 0;
                }
            }
        }
        return temp;
    }

    Time operator--(int){
        Time temp;
        secs--;
        if (secs < 0){
            secs = 59;
            mins--;
            if (mins < 0){
                mins = 59;
                hrs--;
                if (hrs < 0){
                    hrs = 23;
                }
            }
        }
        return temp;
    }

    Time& operator++(){
        secs++;
        if (secs >= 60){
            secs = 0;
            mins++;
            if (mins >= 60){
                mins = 0;
                hrs++;
                if (hrs >= 24){
                    hrs = 0;
                }
            }
        }
        return *this;
    }

    Time& operator--(){
        secs--;
        if (secs < 0){
            secs = 59;
            mins--;
            if (mins < 0){
                mins = 59;
                hrs--;
                if (hrs < 0){
                    hrs = 23;
                }
            }
        }
        return *this;
    }
};

int main(){
    Distance d1(3, 8);
    Distance d2(8, 5);
    d1.display();
    d2.display();
    Distance d3 = d2 + d1;
    d3--;d3.display();
    d3--;d3.display();
    d3--;d3.display();
    d3--;d3.display();
}