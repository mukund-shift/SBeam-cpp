// 1. Write class date with appropriate data members and member functions. Write constructors, getters, setters, facilitators, destructors.
// 2. Write a class distance with data members feet and inches. Write constructors, getters, setters, facilitators, destructors. Also write a method to add a distance to another distance i.e. d3 = d1.add(d2);

#include <iostream>
#include <assert.h>
using namespace std;

class date {

private:
    int day;
    int month;
    int year;

public:

    date(int day = 1, int month = 1, int year = 2000){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~date(){
    }
    void set_day(int day){
        assert(day > 0 && day < 32);
        this->day = day;
    }
    void set_month(int month){
        assert(month > 0 && month < 13);
        this->month = month;
    }
    void set_year(int year){
        assert(year > 0);
        this->year = year;
    }
    int get_day(){
        return this->day;
    }
    int get_month(){
        return this->month;
    }
    int get_year(){
        return this->year;
    }

    void display() {
    cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};

class distance_ {

private:
    int feet;
    int inches;

public:

    distance_(int feet = 0, int inches = 0){
        this->feet = feet;
        this->inches = inches;
    }
    ~distance_(){
    }
    void set_feet(int feet){
        assert(feet >= 0);
        this->feet = feet;
    }  
    void set_inches(int inches){
        assert(inches >= 0 && inches < 12);
        this->inches = inches;
    }

    int get_feet(){
        return this->feet;
    }
    int get_inches(){
        return this->inches;
    }

    void display() {
    cout << this->feet << "\"" << this->inches << "'" << endl;
    }

    void sum(distance_ d){
        this->feet += d.feet;
        this->inches += d.inches;
        if (this->inches >= 12){
            this->inches -= 12;
            this->feet += 1;
        }
    }
};


int main(){
    date t1(21, 2, 2015); // declare var & init it
    date t2; // declare var
    t2.set_day(10);
    t2.set_month(10);
    t2.set_year(2000);
    t1.display();
    t2.display();
    ///////////////////////////
    distance_ d1(5, 3);
    distance_ d2(4, 11);
    d1.sum(d2);
    d1.display();
    return 0;
}