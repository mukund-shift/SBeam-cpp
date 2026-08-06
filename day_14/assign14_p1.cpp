// 1. Design a payment system using an interface Payment. Implement different payment methods like Credit Card, UPI, and Cash, each providing its own payment processing logic.

#include <iostream>
#include <string>
using namespace std;

class payment{
public:
    virtual void CreditCard(int amout) = 0{}
    virtual void UPI(int amount) = 0{}
    virtual void Cash(int amount) = 0{}
};

class BankAccount: public payment{
    bool logged_in;
    double balance;

public:
    BankAccount(double balance = 0){
        this->balance = balance;
        this->logged_in = false;
    }

    void login(){
        this->logged_in = true;
    }
    void logout(){
        this->logged_in = false;
    }

    void CreditCard(int amount){
        if (logged_in){
            if (this->balance >= amount){
            cout << "INR " << amount << " paid successfully using Credit Card." << endl;
            this->balance -= amount;
            }
            else{
            cout << "Payment Failed. Insufficient Balance." << endl;
            }
        }
        else{
            cout << "Login first to pay." << endl;
        }
    }
    void UPI(int amount){
        if (logged_in){
            if (this->balance >= amount){
            cout << "INR " << amount << " paid successfully using UPI." << endl;
            this->balance -= amount;
            }
            else{
            cout << "Payment Failed. Insufficient Balance." << endl;
            }
        }
        else{
            cout << "Login first to pay." << endl;
        }
    }
    void Cash(int amount){
        if (logged_in){
            if (this->balance >= amount){
            cout << "INR " << amount << " paid successfully using Cash." << endl;
            this->balance -= amount;
            }
            else{
            cout << "Payment Failed. Insufficient Balance." << endl;
            }
        }
        else{
            cout << "Login first to pay." << endl;
        }
    }
    void display_bal(){
        if (logged_in){
            cout << "Current Balance: " << this->balance << endl;
        }
        else{
            cout << "Login first to check balance." << endl;
        }
    }
};

int main(){
    BankAccount b1(50000);
    b1.login();
    b1.display_bal();
    b1.Cash(40);
    b1.display_bal();
    b1.UPI(4000);
    b1.display_bal();
    b1.CreditCard(7000);
    b1.display_bal();
    b1.logout();
}