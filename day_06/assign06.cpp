// 1. Modify the chair class so that you can count all the chair objects created in the program. Display the count in main() before exit.
// 2. Create class date (with fields day, month, year and relevant methods), class address (with fields city, country, pin and relevant methods), class product (with fields id, name and relevant methods). Now create the class order with fields order_id, status (PENDING/DELIVERED), order_date, delivery_address, and product. Write relevant methods like ctors, getter/setters, accept(), display().
// Notice the order of constructor and destructor calling when you create object of order class. What will happen, if you change the order of data members in the order class?



#include <iostream>
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
}