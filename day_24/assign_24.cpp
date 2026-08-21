// 1. Create a class CricketPlayer with id, name, runs and wickets members.
//  Write a program that can append new player details in a text file and
//   display all the players info from file.

#include <iostream>
#include <string>
#include <fstream>
#pragma pack(1)
using namespace std;

class CricketPlayer{
public:
    int id;
    string name;
    int runs;
    int wickets;

    CricketPlayer(int id = 0, string name = "Generic Name", int runs = 0, int wickets = 0){
        this->id = id;
        this->name = name;
        this->runs = runs;
        this->wickets = wickets;
    }
    void accept(){
        cout << "Enter ID: " << endl;
        cin >> id;
        cout << "Enter Name: " << endl;
        cin >> name;
        cout << "Enter Runs: " << endl;
        cin >> runs;
        cout << "Enter Wickets: " << endl;
        cin >> wickets;
    }
    void display(){
        cout << "Cricketer: " << endl;
        cout << "ID: " << id << ", Name: " << name << ", Runs: " << runs << ", Wickets: " << wickets << endl;
    }
    ~CricketPlayer(){}
};

int main(){
    int choice;
    

while (true){
    cout << "Enter your choice:" << endl;
    cout << "1. Append to records:" << endl;
    cout << "2. Display records:" << endl;
    cout << "3. Exit:" << endl;
    cin >> choice;
    cout << "-------------------------------------------" << endl;

    switch (choice)
    {
    case 1:{
        CricketPlayer c1;
        c1.accept();
        ofstream file("Cricketers.txt", ios::app);
        if (!file)
            cout << "File open error" << endl;
        file << "Cricketer: " << endl;
        file << "ID: " << c1.id << endl;
        file << "Name: " << c1.name << endl;
        file << "Runs: " << c1.runs << endl;
        file << "Wickets: " << c1.wickets << endl << endl;
        break;
    }
    case 2: {
        ifstream file("Cricketers.txt", ios::in);
        char temp[50];
        while (file.getline(temp, sizeof(temp)))
            cout << temp << endl;
        break;
    }
    
    case 3: {
        cout << "Exiting..." << endl;
        break;
    }
    default:
        cout << "You are a stupid user. Invalid Choice." << endl;
    }
    cout << "-------------------------------------------" << endl;
    if (choice == 3)
        break;
}
    return 0;
}

