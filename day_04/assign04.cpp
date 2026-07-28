// 1. Create a date class with day, month, year fields. Create constructor with default arguments. Also implement getter/setters, accept/display methods.
// 2. How can you declare references to the following?
//    - int arr[5];
//    - int fun() { ... };
// 3. Implement int& max(int&, int&) that returns a reference to the larger integer, allowing the caller to modify it.
// 4. Dynamically allocate an array of "n" dates to store date objects. Accept and display them back.

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

    void accept(){
        cout << "Enter date (dd mm yyyy): ";
        cin >> day >> month >> year;
    }

    void display() {
    cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
};


// 3
int& max(int& a, int& b){
    int greater;
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}

// 4
int main(){
    // int n;
    // cout << "Enter numbers of dates" << endl;
    // cin >> n;
    // date* dates = new date[n];
    // for (int i = 0; i < n; i++){
    //     dates[i].accept();
    // }
    // for (int i = 0; i < n; i++){
    //     dates[i].display();
    // }
// 3
    int a = 63;
    int b = 78;
    int c;
    int greater = max(a, b);
    cout << "number to add to the greater int: " << endl;
    cin >> c;
    greater += c;
    printf("%d\n", greater);

// 
}



// 2. How can you declare references to the following?
//    - int arr[5];
//    - int fun() { ... };


// DOUBTS