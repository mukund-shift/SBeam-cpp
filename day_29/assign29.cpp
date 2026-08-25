// 1. Create vector<Employee>. Count number of emps with sal > 75000.0
// 2. Refer the slides - Implement small code snippets from all algorithms.


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Employee {
    int id;
    string name;
    int sal;
public:
    Employee(int id = -1, const string name= "Generic Name", int sal = 0){
        this->id = id;
        this->name = name;
        this->sal = sal;
    }
    ~Employee(){}

    inline int get_id(){return this->id;}
    inline string get_name(){return this->name;}

    void display(){
        cout << "----------------------------" << endl;
        cout << "Emp ID: " << id << endl;
        cout << "Emp name: " << name << endl;
        cout << "Emp salary: " << sal << endl;
        cout << "----------------------------" << endl;
    }
    void accept(){
        cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        cout << "Enter Employee ID: " << endl;
        cin >> id;
        cout << "Enter Employee Name: " << endl;
        cin >> name;
        cout << "Enter Employee Salary: " << endl;
        cin >> sal;
        cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
    }
    inline int get_sal(){return this->sal;}
};
struct SalGreaterThan75K{
    bool operator()(Employee &e){
        return e.get_sal() > 75000;
    }
};
int main(){
    vector<Employee> v1;
    Employee e1 = {1, "Mukund", 50000};
    Employee e2 = {2, "Kush", 999999};
    Employee e3 = {3, "Mehetab", 7000};
    Employee e4 = {4, "Aryan", 99999};
    Employee e5 = {5, "Swaraj", 120000};
    v1.push_back(e1);
    v1.push_back(e2);
    v1.push_back(e3);
    v1.push_back(e4);
    v1.push_back(e5);
    int count = count_if(v1.begin(), v1.end(), SalGreaterThan75K());
    cout << "Number of employees with sal more than 75K: " << count << endl;
    return 0;
}