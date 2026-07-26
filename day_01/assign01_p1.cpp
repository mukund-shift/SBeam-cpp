// 1. Implement increment() function in today's time class. Increment seconds by 1. Ensure that max time can be 23:59:59.
// 2. Modify display() function in in today's time class to display time with AM/PM (12-hour format).
// 3. Write class date with appropriate data members and member functions.

#include <iostream>
#include <assert.h>
using namespace std;

class timer {

private:
    int hours;
    int mins;
    int seconds;

public:

    timer(int hours = 0, int mins = 0, int seconds = 0){
        this->hours = hours;
        this->mins = mins;
        this->seconds = seconds;
    }
    void set_hrs(int hours){
        assert(hours >= 0 && hours < 24);
        this->hours = hours;
    }
    void set_mins(int mins){
        assert(mins >= 0 && mins < 60);
        this->mins = mins;
    }
    void set_seconds(int seconds){
        assert(seconds >= 0 && seconds < 60);
        this->seconds = seconds;
    }
    int get_hrs(){
        return this->hours;
    }
    int get_mins(){
        return this->mins;
    }
    int get_seconds(){
        return this->seconds;
    }
    void increment(){
        if (this->seconds >= 59){
            this->seconds = 0;

            if (this->mins >= 59){
                this->mins = 0;

                if (this->hours >= 23) {
                    this->hours = 0;
                }
                else {
                    hours++;
                }
            }
            else {
                mins++;
            }
        }
        else {
            seconds++;
        }
    }
    void display() {
    cout << this->hours << ":" << this->mins << ":" << this->seconds << endl;
    }
};

int main()
{
    timer t1(21, 2, 15); // declare var & init it
    timer t2; // declare var
    t2.set_hrs(10);
    t2.set_mins(20);
    t2.set_seconds(40);
    t1.display();
    t2.display();
    return 0;
}