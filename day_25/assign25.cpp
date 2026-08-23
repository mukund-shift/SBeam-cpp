// 1. Create a class User with fields id, name, email, mobile, passwd.
//  Write user management program that stores users data into file and
//  provide facility to add, display, delete, edit users.
//  Also write a function that inputs email & passwd and check if
//  login is successful.

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class User{
public:
    int id;
    char name[20];
    char email[30];
    char mobile[10];
    char password[20];
public:
    User(int id = 1){
        this->id = id;
        strcpy(this->name, "Generic Name");
        strcpy(this->email, "xyz@gmail.com");
        strcpy(this->mobile, "1010101010");
        strcpy(this->password, "Password123");
    }
    void accept(){
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter mobile: ";
        cin >> mobile;
        cout << "Enter password: ";
        cin >> password;
    }
    void deleted_user(){
        id = -1;
        strcpy(name, "Deleted");
        strcpy(this->email, "Deleted");
        strcpy(this->mobile, "Deleted");
        strcpy(this->password, "Deleted");
    }
    void display(){
        cout << "----------------------------------------" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Mobile: " << mobile << endl;
        cout << "Password: " << password << endl;
        cout << "----------------------------------------" << endl;
    }
};

void login(){
    cout << "Enter email: ";
    char temp_email[30];
    cin >> temp_email;
    cout << "Enter password: ";
    char temp_pw[20];
    cin >> temp_pw;

    // TODO: read file and compare email and passwd strings logic here
    fstream file("Users.dat", ios::in|ios::binary);
    User u1;
    bool valid = false;
    auto start_ptr = file.tellp();                  // to mantain track of cursore before it reads
    while (file.read((char*) &u1, sizeof(u1))){
        if (strcmp(u1.email, temp_email) == 0 && strcmp(u1.password, temp_pw) == 0)
        {   
            valid = true;
            cout << "----------------" << endl;
            cout << "Login Succesful!" << endl;
            cout << "----------------" << endl;
            break;
        }
        start_ptr = file.tellp();               // increment tracker to next record
    }
    if (!valid){
        cout << "--------------------" << endl;
        cout << "Invalid credentials." << endl;
        cout << "--------------------" << endl;
    }
}

int main(){
    
    int choice;
    while (choice != -1){
        cout << "Enter choice" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Display all users" << endl;
        cout << "3. Delete User" << endl;
        cout << "4. Edit User" << endl;
        cout << "5. User Login" << endl;
        cout << "-1. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1: {
            User u1;                // why User u1(); causes error?
            u1.accept();
            fstream file("Users.dat", ios::app|ios::out|ios::binary);
            file.write((char*)&u1, sizeof(u1));
            break;
        }
            
        case 2: {
            fstream file("Users.dat", ios::in|ios::binary);
            if (!file)
                cout << "File open failed :(" << endl;
            User u1;
            int i = 1;
            while (file.read((char*)&u1, sizeof(u1))){
                cout << "User " << i++ << ": "<< endl;
                u1.display();
                cout << "==================================================================" << endl;
            }
            break;
        }

        case 3: {
            int temp_id;
            cout << "Enter id to delete: ";
            cin >> temp_id;
            fstream file("Users.dat", ios::in|ios::out|ios::binary);
            User u1;
            bool found = false;
            auto start_ptr = file.tellp();                  // to mantain track of cursore before it reads
            while (file.read((char*) &u1, sizeof(u1))){
                if (u1.id == temp_id){
                    User del;
                    found = true;
                    file.seekp(start_ptr);
                    del.deleted_user();      // cleans up obj to a "deleted" placeholder to replace old record with
                    file.write((char*)&del, sizeof(del));
                    cout << "Deleted." << endl;
                }
                start_ptr = file.tellp();               // increment tracker to next record
            }
            if (!found)
                cout << "No such user id found." << endl;
            break;
        }

        case 4: {
            int temp_id;
            cout << "Enter id to edit: ";
            cin >> temp_id;
            fstream file("Users.dat", ios::in|ios::out|ios::binary);
            User u1;
            bool found = false;
            auto start_ptr = file.tellp();
            while (file.read((char*) &u1, sizeof(u1))){
                if (u1.id == temp_id){
                    User nu;
                    found = true;
                    file.seekp(start_ptr);
                    cout << "Enter new details: " << endl; 
                    nu.accept();      // new object to replace old record with.
                    file.write((char*)&nu, sizeof(nu));
                    cout << "Edited." << endl;
                }
                start_ptr = file.tellp();
            }
            if (!found)
                cout << "No such user id found." << endl;
            break;
        }

        case 5:{
            login();
            break;
        }
        
        case -1:{
            cout << "Exiting..." << endl;
            break;
        }

        default:
            cout << "You are not smart. Invalid choice." << endl;
        }
    }
}