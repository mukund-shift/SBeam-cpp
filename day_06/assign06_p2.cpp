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

class item{
private:
    int id;
    string name;
    static int price;
    static int curr_id;

public:
    item(){
        this->id = item::curr_id;
        conc_inc();

        
    }
    static void conc_inc(){
        item::curr_id++;
    }
    void price_inc(){
        this->price += 100;
    }
};

int item::curr_id = 1
