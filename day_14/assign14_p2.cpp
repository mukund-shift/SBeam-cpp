// 2. Create a notification interface with a common method to send messages. 
// Implement Email, SMS, and Push Notification classes using the interface.

#include <iostream>
#include <string>
using namespace std;

class notification{
public:
    virtual void Email() = 0{}
    virtual void SMS() = 0{}
    virtual void Push() = 0{}
};

class Application: public notification{
    string alert;
    string email;
    string number;

public:
    Application(){
        this->alert = "Generic Alert";
        this->email = "genericmail@gmail.com";
        this->number = "9876598765";
    }

    void Email(){
        cout << "Mailed notification succesfully to " << this->email << endl;
    }
    void SMS(){
        cout << "Notification sent to number: " << this->number << " successfully!" << endl;
    }
    void Push(){
        cout << this->alert << " published to push notifications successfully!" << endl;
    }
};

int main(){
    Application a1;
    a1.Email();
    a1.SMS();
    a1.Push();
    return 0;
}