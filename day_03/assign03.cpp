// 1. Create person class with name and age data members. Implement constructors, accept() and display() facilitators using cin/cout.
// 2. Add accept() and display() method in our time class. Make getter/setter methods as "inline".

#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;

class person {

private:
    char name[50];
    int age;

public:
    person(const char* name = "", int age = 0){
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
        this->age = age;
    }
    ~person(){
    }

    void set_name(const char* name){
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }
    void set_age(int age){
        this->age = age;
    }

    char* get_name(){
        return this->name;
    }
    int get_age(){
        return this->age;
    }

    void accept(){
        cout << "Enter person's first name only: ";
        // Directly read into the array (limiting input to prevent buffer overflow)
        cin.width(sizeof(this->name));
        cin >> this->name;

        cout << "Enter person's age: ";
        cin >> this->age;
    }

    void display(){
        cout << "name: " << this->name << ", age: " << this->age << endl;
    }

};


class time_ {

private:
    int hours;
    int mins;
    int seconds;

public:

    time_(int hours = 0, int mins = 0, int seconds = 0){
        this->hours = hours;
        this->mins = mins;
        this->seconds = seconds;
    }
    ~time_(){
    }
    inline void set_hours(int hours){
        assert(hours >= 0 && hours < 24);
        this->hours = hours;
    }
    inline void set_mins(int mins){
        assert(mins >= 0 && mins < 60);
        this->mins = mins;
    }
    inline void set_seconds(int seconds){
        assert(seconds >= 0 && seconds < 60);
        this->seconds = seconds;
    }
    inline int get_hours(){
        return this->hours;
    }
    inline int get_mins(){
        return this->mins;
    }
    inline int get_seconds(){
        return this->seconds;
    }

    void accept(){
    cout << "Enter hours, mins, seconds";
    // Directly read into the array (limiting input to prevent buffer overflow)
    cin >> this->hours >> this->mins >> this->seconds;
    }

    void display(){
        cout << this->hours << ":" << this->mins << ":" << this->seconds << endl;
    }
};


int main(){
    // person p1;
    // p1.accept();
    // p1.display();

    time_ t1;
    t1.accept();
    t1.display();
}

