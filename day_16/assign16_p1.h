// 1. Implement complete Product shop assignment in modular fashion (.h & .cpp files per class).
#include <string>
#include <iostream>
#pragma once
using namespace std;

class product{
private:
    string title;
protected:
    int cost;
public:
    product(string title = "", int cost = 0);
    ~product();
    virtual void accept();
    virtual void display();
    virtual int calc_price();
    int get_price();
};

class book: public product{
private:
    int pages;
public:
    book(int pages = 0, string title = "", int cost = 0);
    ~book();
    void accept();
    void display();
    int calc_price();
};

class tape: public product{
private:
    int duration;
public:
    tape(int duration = 0, string title = "", int cost = 0);
    ~tape();
    void accept();
    void display();
    int calc_price();
};

// only write func signature and end it with; ,dont open curly braces in header files for funcs
// also base member init lists are to be only written in .cpp files, not in headers