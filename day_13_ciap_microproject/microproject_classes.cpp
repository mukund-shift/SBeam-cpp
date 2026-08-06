
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class service{                                  // Abstract Class
    string desc;

public:

    service(string desc = "Generic Service"){
        this->desc = desc;
    }

    inline string get_desc(){
        return this->desc;
    }

    inline void set_desc(string desc){
        this->desc = desc;
    }

    virtual void display() = 0{
        cout << "Service Description: " << this->service::desc << endl;
    }

    virtual void input() = 0{
        cout << "Enter Service Description: " << endl;
        cin >> desc;
    }

    virtual double price() = 0{
        // Redefine this in derived classes
    }


};

class oil : public service{
    double cost;

public:
    oil(string desc = "Generic Service", double cost = 0) : service(desc)
    {
        this->cost = cost;
    }

    inline double get_cost(){
        return this->cost;
    }
    inline void set_cost(double cost){
        this->cost = cost;
    }

    void display(){
        this->service::display();
        cout << "Oil Cost: " << this->cost << endl;
    }

    void input(){
        this->service::input();
        cout << "Enter Oil Cost: " << endl;
        cin >> cost;
    }

    double price(){
        return cost;
    }
};

class maintenance: public service{
    list<part> part_list;
    double labor_charges;

public:
    // oil(string desc = "Generic Service", double cost = 0) : service(desc)
    // {
    //     this->cost = cost;
    // }

    inline double get_labor_charges(){
        return labor_charges;
    }
    
    inline void set_labor_charges(double labor_charges){
        this->labor_charges = labor_charges;
    }

    // void display(){
    //     this->service::display();
    //     cout << "Oil Cost: " << this->cost << endl;
    // }

    // void input(){
    //     this->service::input();
    //     cout << "Enter Oil Cost: " << endl;
    //     cin >> cost;
    // }

    // double price(){
    //     return cost;
    // }
};



class part{
    string desc;
    double rate;
    
public:
    part(string desc = "generic part", double rate = 0){
        this->desc = desc;
        this->rate = rate;
    }

    inline string get_desc(){
        return this->desc;
    }

    inline double get_rate(){
        return this->rate;
    }

    void input(){
        cout << "Enter part desc: ";
        cin >> desc;
        cout << "Enter part rate: ";
        cin >> rate;
    }

    inline void set_desc(string desc){
        this->desc = desc;
    }

    inline void set_rate(double rate){
        this->rate =  rate;
    }


};


class service_request{
    string cust_name;
    list<service> serv_list;
    string veh_number;
public:
};


class vehicle{
    string company;
    string model;
    string number;
public:

    vehicle(string company = "Generic Company", string model = "Generic Model", string number ="0000")
    {
        this->company = company;
        this->model = model;
        this->number = number;
    }
    inline string get_company(){
        return this->company;
    }
    inline string get_model(){
        return this->model;
    }
    inline string get_number(){
        return this->number;
    }

    inline void set_company(string company){
        this->company = company;
    }
    inline void set_model(string model){
        this->model = model;
    }
    inline void set_number(string number){
        this->number = number;
    }

    void input(){
        cout << "Enter vehicle's company " << endl;
        cin >> company;
        cout << "Enter vehicle's model " << endl;
        cin >> model;
        cout << "Enter vehicle's number " << endl;
        cin >> number;
    }

};

class customer{
    string address;
    string mobile;
    string name;
    vector<vehicle> veh_list;
};

class bill{
    double amount;
    double paid_amount;
    service_request* req;

public:

};

class service_station{
    list<bill> bill_list;
    list<customer> customer_list;
    string name;

public:
};
