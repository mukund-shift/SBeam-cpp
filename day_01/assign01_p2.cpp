// 1. Implement increment() function in today's time class. Increment year by 1. Ensure that max time can be 23:59:59.
// 2. Modify display() function in in today's time class to display time with AM/PM (12-hour format).
// 3. Write class date with appropriate data members and member functions.

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

int main()
{
    date t1(21, 2, 2015); // declare var & init it
    date t2; // declare var
    t2.set_day(10);
    t2.set_month(10);
    t2.set_year(2000);
    t1.display();
    t2.display();
    return 0;
}