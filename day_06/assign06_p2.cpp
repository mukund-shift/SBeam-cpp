// 3. Create class item with fields id, name, and price. We will create an array of the item class 
// objects dynamically as per size given by end user. 
// Ensure that item ids and prices are auto-assigned in param-less ctor of the class. e.g. If user 
// want to create array of 3 objects, 
// then their ids should be 1, 2, 3 and their prices should be 100, 200, 300. 
// You can keep their names blank. Write a static method in the class display_all(array) to display 
// all the items passed to it.

// 4. Design a class **Ticket** for a movie theater. Each ticket is either **Full** or **Half**,
//  with fares of Rs. 10 and Rs. 5 respectively. Create suitable data members and member functions to 
//  keep track of the total number of tickets sold and the total collection, choosing class and object 
//  members appropriately.

#include <iostream>
#include <string>
using namespace std;

// 3 wip, to do: write display_all class
class item{
private:
    int id;
    string name;
    int price;
    static int curr_price;
    static int curr_id;

public:
    item(){
        this->id = item::curr_id;
        this->name = "test";
        this->price = item::curr_price;
        item::curr_id++;
        item::curr_price += 100;
    }
    ~item(){
    }

    void set_id(int id){
        this->id = id;        
    }
    void set_name(string name){
        this->name = name;
    }
    void set_price(int price){
        this->price = price;
    }

    int get_id(){
        return this->id;
    }
    string get_name(){
        return this->name;
    }
    int get_price(){
        return this->price;
    }

    

    static void display_all(item* array, int size){
        for (int i = 0; i < size; i++){
            cout << "Element no " << i + 1 << ": " << "ID-" << array[i].get_id() << " Name-" << array[i].get_name() << " Price-" << array[i].get_price() << endl;
        }
    }
};

int item::curr_id = 1;
int item::curr_price = 100;

int main(){
    int n;
    cout << "Enter size:" << endl;
    cin >> n;
    item* array = new item[n];

    item::display_all(array, n);
}
