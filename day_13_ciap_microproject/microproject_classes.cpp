
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

    virtual void display(){
        cout << "Service:" << this->desc << endl;
    }

    virtual void input(){
        cout << "Enter Service Description" << endl;
        cin >> this->desc;
    }

    virtual double price() = 0;


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
    maintenance(string desc = "Generic Service", double labor_charges = 0) : service(desc)
    {
        this->labor_charges = labor_charges;
    }

    inline double get_labor_charges(){
        return labor_charges;
    }
    
    inline void set_labor_charges(double labor_charges){
        this->labor_charges = labor_charges;
    }

    inline void add_part(const part& new_part){
        part_list.push_front(new_part);
    }

    inline list<part>& get_part_list(){
        return this->part_list;
    }

    void display(){
        cout << "Part list:" << endl;
        for (auto itr = part_list.begin(); itr != part_list.end(); itr++){
            cout << itr->get_desc() << " | " << "Cost: " << itr->get_rate() << endl;
        }
        cout << "Labor Charges: " << this->labor_charges << endl;
    }

    void input(){
        this->service::input();
        cout << "Enter no of parts :" << endl;
        int n;
        cin >> n;
        part temp_part;
        for (int i = 0; i < n; i++){
            temp_part.input();
            part_list.push_front(temp_part);
        }
        cout << "Enter Labor Charges" << endl;
        cin >> this->labor_charges;
    }

    double price(){
        double total = 0;
        for (auto itr = part_list.begin(); itr != part_list.end(); itr++){
            total += itr->get_rate();
        }
        total += labor_charges;
    }
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
    list<service*> serv_list;
    string veh_number;
public:
    service_request(string name, string veh_no){
        this->cust_name = name;
        this->veh_number = veh_no;
    }

    inline void set_cust_name(const string& name){
        this->cust_name = name;
    }
    inline void set_veh_number(const string& veh_no){
        this->veh_number = veh_no;
    }
    inline string& get_cust_name(){
        return this->cust_name;
    }
    inline string& get_veh_number(){
        return this->veh_number;
    }
    
    inline void add_item(service* serv){
        serv_list.push_front(serv);
    }
    inline list<service*>& get_serv_list(){
        return this->serv_list;
    }
    
    void process_request(){
        double total = 0;
        for (auto serv_itr = serv_list.begin(); serv_itr != serv_list.end(); serv_itr++){
            auto temp_ptr = *serv_itr;
            total += temp_ptr->price();
        }
    }

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
    
    public:
    customer(const string& name = "Generic Name", const string& address = "Generic Address", const string& mobile = "0101"){
        this->address = address;
        this->mobile = mobile;
        this->name = name;
    }

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
