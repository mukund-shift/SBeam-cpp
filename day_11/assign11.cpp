// assignment - every customer purchase 5 products - total bill
	//	product *arr[5];

#include <iostream>
#include <string>
using namespace std;

class product {
    string title;
protected:
    float price;
public:
    product(){
        this->title = "";
        this->price = 0;
    }
    product(string title, float price){
        this->title = title;
        this->price = price;
    }

    // accept, display, calc_total_price, get_price
    virtual void accept(){
        cout << "Enter title: " << endl;
        cin >> title;
        cout << "Enter price: " << endl;
        cin >> price;
    }

    virtual void display(){
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }

    virtual int calc_total_price(){
        return price;
    }

    int get_price(){
        return price;
    }
};

class tape : public product{
    int duration;
public:
    tape(){
        this->duration = 0;
    }
    tape(int duration, string title, float price)
    : product(title, price)
    {
        this->duration = duration;
    }

    // accept, display, calc_total_price, get_price
    void accept(){
        product::accept();
        cout << "Enter duration: " << endl;
        cin >> duration;
    }

    void display(){
        product::display();
        cout << "Duration: " << duration << endl;

    }

    int calc_total_price(){
        return price * 1.1;
    }
};

class book : public product{
    int pages;
public:
    book(){
        this->pages = 0;
    }
    book(int pages, string title, float price)
    : product(title, price)
    {
        this->pages = pages;
    }

    // accept, display, calc_total_price, get_price
    void accept(){
        product::accept();
        cout << "Enter page count: " << endl;
        cin >> pages;
    }

    void display(){
        product::display();
        cout << "Pages: " << pages << endl;

    }

    int calc_total_price(){
        return price * 1.05;
    }
};


int main(){
    int total_bill = 0;
    product* arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter product type:" << endl;
        cout << "1 : Tape" << endl;
        cout << "2 : Book" << endl;
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            arr[i] = new tape;
            arr[i]->accept();
            break;
        case 2:
            arr[i] = new book;
            arr[i]->accept();
            break;
        
        default:
            cout << "INVALID, RERUN THE PROGRAM" << endl;
            break;
        }
    }
    cout << "Products: " << endl;
    for (int i = 0; i < 5; i++)
    {
        total_bill += arr[i]->get_price();
        arr[i]->display();
        cout << endl;
    }
    cout << "Total bill: " << total_bill << endl;
    return 0;
}
