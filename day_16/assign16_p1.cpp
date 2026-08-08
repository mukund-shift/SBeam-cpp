#include "assign16_p1.h"


product::product(string title, int cost){
    this->title = title;
    this->cost = cost;
}
product::~product(){
    cout << "~product() called" << endl;
}
void product::accept(){
    cout << "Enter Title: " << endl;
    cin >> this->title;
    cout << "Enter Price: " << endl;
    cin >> this->cost;
}
void product::display(){
    cout << "Title: " << title << endl;
    cout << "Price: " << cost << endl;
}
int product::calc_price(){
    return cost;
}
int product::get_price(){
    return cost;
}


book::book(int pages, string title, int cost): product(title, cost)
    {
        this->pages = pages;
    }
void book::accept(){
    product::accept();
    cout << "Enter no of pages: " << endl;
    cin >> this->pages;
}
void book::display(){
    product::display();
    cout << "No of pages: " << pages << endl;
}
int book::calc_price(){
    return this->cost * 1.05;
}

tape::tape(int duration, string title, int cost): product(title, cost)
    {
        this->duration = duration;
    }
void tape::accept(){
    product::accept();
    cout << "Enter duration: " << endl;
    cin >> this->duration;
}
void tape::display(){
    product::display();
    cout << "Duration: " << duration << endl;
}
int tape::calc_price(){
    return this->cost * 1.1;
}

// dont write default args in .cpp module