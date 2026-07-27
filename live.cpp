#include <iostream>
using namespace std;

#define BLACK   0
#define WHITE   1
#define RED     2
#define BLUE    3

class chair {
private:
    int height;     // instance members (non-static members)
    int weight;     // instance members (non-static members)
    int color;      // instance members (non-static members)
    static int price; // (class member) static data member declaration
public:
    chair() {
        height = 0;
        weight = 0;
        color = BLACK;
    }
    chair(int h, int w, int c) {
        height = h;
        weight = w;
        color = c;
    }
    // getters/setters
    void display() {
        // non-static member fns of class can access, static members of class directly
        cout << "chair: height=" << height << "\", weight=" << weight << "kg, color=" << color << ", ** price=" << price << endl;
    }

    // static member fn
    //    - to access/manipulate static data members of the class
    //    - class members -- classname::member() e.g. chair::get_price()
    static int get_price() {
        return price;
    }

    static void set_price(int price) {
        chair::price = price;
    }

    static void display_price() {
        cout << "price = " << price << endl;
        //cout << "height = " << height << endl; // compiler error - no object is available here (this pointer)
        
        //chair c;
        //c.height = 2; // allowed -- accessed on some object
    }

    // helper fns/util fns -- belongs to class -- from main() chair::calc_total_weight(arr);
    static int calc_total_weight(chair chairs[]) {
        // ... -- your assignment
        return 0;
    }
};

//static 
int chair::price = 2000; // static data member definition
// static data member -- life throughtout the program
//      -- scope limited to class in which it is declared
//          - accessible directly inside class
//          - accessible outside class using scope resolution (if public)

int main()
{
    //chair::price = 2500; // can access static members outside the class, if they are declared public
    chair::set_price(2500); // static member fns are recommended to be called on class name
        // since no object is involved, it doesn't have "this" pointer.

    chair c1(2, 1, BLACK);
    chair c2(1, 2, RED);
    chair c3(3, 2, BLUE);
    c1.display();
    c2.display();
    c3.display();
    //cout << "c2 price: " << c2.price << endl; // can access static outside class, if public
    //cout << "chair price: " << chair::price << endl; // can access static outside class, if public
        // classname::staticmember (recommended) or objname.staticmember
    cout << "chair price: " << chair::get_price() << endl;
    //cout << "c2 price: " << c2.get_price() << endl;
    // static member fns shared by all objs of class, so they can be called on object using . operator.
    //  however, we should avoid calling like that. it is misleading
    cout << "chair object size: " << sizeof(c1) << endl;
    return 0;
}