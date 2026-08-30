// 1. Implement a class Person (with char name[20], age).
// Implement a class Car (with model, price, Person *driver).
// Consider that Person object is allocated dynamically
// e.g. Car c1("i10", 700000, new Person("Nilesh", 42));

// ==============================Done till here======================================= 

// Now implement copy constructor and assignment operator for Person and Car class.

#include <iostream>
#include <cstring>
using namespace std;

class Person{
    char name[20];
    int age;
    public:
    Person(const char* n = "Generic Name", int a = 0){
        strcpy(name, n);
        age = a;
    }
    void display(){
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    void accept(){
        cout << "Enter name: ";
        cin >> name;
        cout << endl;
        cout << "Enter age: ";
        cin >> age;
        cout << endl;
    }
};

class Car{
    char model[20];
    int price;
    Person* driver;
    public:
    Car(const char* m = "Generic Model", int p = 0, Person* d = nullptr){
        price = p;
        strcpy(model, m);
        driver = d;
    }
    void display(){
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Driver: " << endl;
        driver->display();
    }
};

int main(){
    Car c1("i10", 700000, new Person("Nilesh", 42));
    c1.display();
    return 0;
}