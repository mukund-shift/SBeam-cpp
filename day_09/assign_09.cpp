// 1. Implement SalesManager class inherited from Salesman and Manager, which in turn inherited from Employee. Refer the screenshot.

// Classic Diamond Inheritance (must be virtual)

#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
    int id;
    int sal;
public:
    Employee(int id, int sal){
        this->id = id;
        this->sal = sal;
        cout << "Employee() called" << endl;
    }
    ~Employee(){
        cout << "~Employee() called" << endl;
    }
};

class Salesman: public virtual Employee{
private:
    int comm;

public:
    Salesman(int id, int sal, int comm)
        : Employee(id, sal)
    {
        this->comm = comm;
        cout << "Salesman() called" << endl;
    }
    ~Salesman(){
        cout << "~Salesman() called" << endl;
    }
    
};

class Manager: public virtual Employee{
private:
    int bonus;

public:
    Manager(int id, int sal, int bonus)
        : Employee(id, sal)
    {
        this->bonus = bonus;
        cout << "Manager() called" << endl;
    }
    ~Manager(){
        cout << "~Manager() called" << endl;
    }
};

class SalesManager: public Salesman, public Manager{
private:
    int incentives;

public:
    SalesManager(int id, int sal, int comm, int bonus, int incentives)
        : Employee(id, sal), Salesman(id, sal, comm), Manager(id, sal, bonus)
    {
        this->incentives = incentives;
        cout << "SalesManager() called" << endl;
    }
    ~SalesManager(){
        cout << "~SalesManager() called" << endl;
    }
};

int main(){
    SalesManager s1(41, 40000, 5800, 4000, 5300);

}