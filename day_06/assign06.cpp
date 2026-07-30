// 1. Modify the chair class so that you can count all the chair objects created in the program. Display the count in main() before exit.
// 2. Create class date (with fields day, month, year and relevant methods), class address (with fields city, country, pin and relevant methods), class product (with fields id, name and relevant methods). Now create the class order with fields order_id, status (PENDING/DELIVERED), order_date, delivery_address, and product. Write relevant methods like ctors, getter/setters, accept(), display().
// Notice the order of constructor and destructor calling when you create object of order class. What will happen, if you change the order of data members in the order class?



#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

// 1.
class chair {
private:
    int color;
    int weight;
    static int price;
    static int count;

public:
    chair(int color = 0, int weight = 2){
        this->color = color;
        this->weight = weight;
        cout << "chair() called" << endl;
        counter();
    }
    ~chair(){
        cout << "~chair() called" << endl;
        counter(1);
    }
    void accept(){
        cout << "Enter color and weight: ";
        cin >> color >> weight;
    }
    void display() {
    cout << "color: " << this->color << ", weight: " << this->weight << endl;
    }
    
    static void counter(int op = 0){
        if (op == 0){
            chair::count++;
            cout << "Chair object count: " << chair::count << endl;
        }
        else if (op == 1)
        {
            chair::count--;
            cout << "Chair object count: " << chair::count << endl;
        }
        else{
            cout << "Chair object count: " << chair::count << endl;
        }
        
    }
    
};

// 2.

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
        cout << "date() called" << endl;
    }
    ~date(){
        cout << "~date() called" << endl;
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

class address {

private:
    string city;
    string country;
    int pin;

public:

    address(string city = "", string country = "", int pin = 0){
        this->city = city;
        this->country = country;
        this->pin = pin;
        cout << "address() called" << endl;
    }
    ~address(){
        cout << "~address() called" << endl;
    }
    void set_city(string city){
        this->city = city;
    }
    void set_country(string country){
        this->country = country;
    }
    void set_pin(int pin){
        assert(pin >= 0);
        this->pin = pin;
    }
    string get_city(){
        return this->city;
    }
    string get_country(){
        return this->country;
    }
    int get_pin(){
        return this->pin;
    }

    void accept(){
        cout << "Enter address (city country pin): ";
        cin >> city >> country >> pin;
    }

    void display() {
    cout << this->city << "," << this->country << "," << this->pin << endl;
    }
};

class product {
    int id;
    string name;

public:
    product(int id = 0, string name = ""){
        this->id = id;
        this->name = name;
        cout << "product() called" << endl;
    }
    ~product(){
        cout << "~product() called" << endl;
    }
    void set_id(int id){
        this->id = id;
    }
    void set_name(string name){
        this->name = name;
    }

    int get_id(){
        return this->id;
    }
    string get_name(){
        return this->name;
    }


    void accept(){
        cout << "Enter product id and name: ";
        cin >> id >> name;
    }

    void display() {
    cout << this->id << ":" << this->name << endl;
    }
};

// Now create the class order with fields order_id, status (PENDING/DELIVERED), 
// order_date, delivery_address, and product. 
// Write relevant methods like ctors, getter/setters, accept(), display().
// // Notice the order of constructor and destructor calling when you create object of order class. What will happen, if you change the order of data members in the order class?
class order {
// date, address, product classes made
private:
    int order_id;
    string status;
    date order_date;
    address delivery_address;
    product prod;

public:

    order(){
    }
    ~order(){
    }

    void accept(){
        int d, m, y, pin, id;
        string city, country, name;
        cout << "order_id, status" << endl;
        cin >> order_id >> status;
        this->order_id = order_id;
        this->status = status;
        order_date.accept();
        delivery_address.accept();
        prod.accept();
    }

    void display(){
        cout << "Order ID: " << this->order_id << "Status: "<< this->status << endl;
        order_date.display();
        delivery_address.display();
        prod.display();
    }
};


int chair::price = 2000;
int chair::count = 0;

int main(){
// 1 done:
//     chair c1(1, 4);
//     chair c2(1, 5);
//     chair c3(1, 8);
//     chair c4(4, 2);
//     chair c5(8, 3);
//     chair c6(1, 6);
//     chair c7(9, 7); 

// 2 done:
    // order o1;
    // o1.accept();
    // o1.display();
}