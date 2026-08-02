// 1. Implement Person (name, age), Employee (id, sal), and Student (roll, marks). 
// Write virtual functions accept() and display() in base and override them in derived classes.

#include <iostream>
#include <string>
using namespace std;

class Person{
    string name;
    int age;
public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

    virtual void accept(){
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter age: " << endl;
        cin >> age;
    }

    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee: public Person{
    int id;
    int sal;
public:
    Employee(int id, int sal, string name, int age): Person(name, age)
    {
        this->id = id;
        this->sal = sal;
    }
    void accept(){
        Person::accept();
        cout << "Enter id: " << endl;
        cin >> id;
        cout << "Enter sal: " << endl;
        cin >> sal;
    }

    void display(){
        Person::display();
        cout << "id: " << id << endl;
        cout << "salary: " << sal << endl;
    }
};

class Student: public Person{
    int roll;
    int marks;
public:
    Student(int roll, int marks, string name, int age): Person(name, age)
    {
        this->roll = roll;
        this->marks = marks;
    }
    void accept(){
        Person::accept();
        cout << "Enter roll: " << endl;
        cin >> roll;
        cout << "Enter marks: " << endl;
        cin >> marks;
    }

    void display(){
        Person::display();
        cout << "roll: " << roll << endl;
        cout << "marks: " << marks << endl;
    }
};

int main(){
    Employee e1(11, 50000, "mknd", 32);
    Student s1(21, 94, "kira", 18);
    e1.display();
    cout << endl;
    s1.display();
    cout << endl;

    Person* p1 = &e1;
    p1->display();
    cout << endl;
    Person* p2 = &s1;
    p2->display();

    return 0;
}