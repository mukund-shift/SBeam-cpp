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
        cout << "Enter ID, Name, Runs and Wickets: " << endl;
        cin >> id >> name >> runs >> wickets;
    }
    void display(){
        cout << "Cricketer: " << endl;
        cout << "ID: " << id << ", Name: " << name << ", Runs: " << runs << ", Wickets: " << wickets << endl;
    }
    ~CricketPlayer(){}
};

int main(){
    int choice;
    cout << "Enter your choice:" << endl;
    cout << "1. Append to records:" << endl;
    cout << "2. Display records:" << endl;
    cout << "3. Exit:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:{
        CricketPlayer c1;
        c1.accept();
        ofstream file("Cricketers.txt", ios::app);
        file << "Cricketer: " << endl;
        file << "ID, Name, Runs and Wickets: " << endl;
        file << c1.id << ", " << c1.name << ", " << c1.runs << ", " << c1.wickets << endl << endl;
        break;
    }

    case 2: {
        ifstream file("Cricketers.txt", ios::in);
        char temp[50];
        while (file.getline(temp, sizeof(temp)))
            cout << temp << endl;
    }
    
    case 3: {
        cout << "Exiting..." << endl;
        break;
    }
    default:
        cout << "You are a stupid user. Invalid Choice." << endl;
    }
    return 0;
}

