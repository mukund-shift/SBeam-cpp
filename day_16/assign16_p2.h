#include <iostream>
#include <string>
#pragma once
using namespace std;

class Employee{
private:
    int id;
    int salary;
    static int id_ctr;
public:
    Employee(int salary = 0);
    ~Employee();
    virtual void display();
};

class Salesman: virtual public Employee{
private:
    int comm;
public:
    Salesman(int comm = 0, int salary = 0);
    ~Salesman();
    void display();
};

class Manager: virtual public Employee{
private:
    int bonus;
public:
    Manager(int bonus = 0, int salary = 0);
    ~Manager();
    void display();
};

class SalesManager: public Salesman, public Manager{
private:
    int incentives;
public:
    SalesManager(int incentives, int comm, int bonus, int salary = 0);
    ~SalesManager();
    void display();
};

// only write func signature and end it with; ,dont open curly braces in header files for funcs
// also base member init lists are to be only written in .cpp files, not in headers