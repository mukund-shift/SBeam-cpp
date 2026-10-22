// 1. Implement increment() function in today's time class. Increment seconds by 1. Ensure that max time can be 23:59:59.
// 2. Modify display() function in in today's time class to display time with AM/PM (12-hour format).
// 3. Write class date with appropriate data members and member functions.

#include <iostream>
using namespace std;

class Time{
    private:
    int hours;
    int mins;
    int secs;

    public:
    Time(int h = 0, int m = 0, int s = 0){
        this->hours = h;
        this->mins = m;
        this->secs = s;
    }
    ~Time(){cout << "Time Dtor Called."<< endl;}
    
    void input(){
        cout << "Enter hours, minutes and seconds" << endl;
        cin >> hours >> mins >> secs;
    }
    void display(){
        if (hours > 12){
            cout << hours - 12 << ":" << mins << ":" << secs << " P.M." << endl;
        }
        else {
            cout << hours << ":" << mins << ":" << secs << " A.M." << endl;
        }
    }
    void increment(){
        secs++;
        if (secs >= 60){
            secs = 0;
            mins++;
            if (mins >= 60){
                mins = 0;
                hours += 1;
                if (hours >= 24){
                    cout << "Day Ends" << endl;
                    hours = 0;
                }
            }
        }
    }
};

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date(int d = 1, int m = 1, int y = 1){
        this->day = d;
        this->month = m;
        this->year = y;
    }
    ~Date(){cout << "Date Dtor Called."<< endl;}
    
    void input(){
        cout << "Enter hours, minutes and seconds" << endl;
        cin >> day >> month >> year;
    }
    void display(){
        cout << day << "/" << month << "/" << year << endl;
    }
    void increment(){
        day++;
        if (day > 30){
            day = 1;
            month++;
            if (month > 12){
                month = 1;
                year += 1;
            }
        }
    }
};


int main(){
    Time t2;
    t2.display();
    for (int i = 0; i < 86399; i++){
        t2.increment();
    }
    t2.display();
    Date d1;
    d1.display();
    Date d2(11, 11, 2005);
    d2.display();
    for (int i = 0; i < 729310; i++){
        d1.increment();
    }
    d1.display();
    return 0;
}