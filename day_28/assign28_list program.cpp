// 1. Create a class Employee (id, name, sal).                     
//  Implement menu driven program to manage employee in a vector.   
//   Menu options: Add Emp, Display All Emp, Find Emp, Delete Emp, Save to file, Load from file.
// 2. Reimplement above program using STD list.                     


#include <iostream>
#include <list>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

class Employee {
    int id;
    char name[20];
    int sal;
public:
    Employee(int id = -1, const char name[20] = "Generic Name", int sal = 0){
        this->id = id;
        strcpy(this->name, name);
        this->sal = sal;
    }
    ~Employee(){}

    inline int get_id(){return this->id;}
    inline char* get_name(){return this->name;}

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
};

void Save_to_file(list<Employee> Emp_list , const char filename[20] = "Employees.dat"){
    fstream file(filename, ios::app|ios::binary);
    list<Employee>::iterator itr = Emp_list.begin();
    while (itr != Emp_list.end()){
        file.write((char*)&(*itr), sizeof(Employee));
        itr++;
    }
    cout << "Saved records successfully to " << filename << endl;
}

list<Employee> Load_from_file(const char filename[20] = "Employees.dat"){
    list<Employee> output;
    fstream file(filename, ios::in|ios::binary);
    Employee temp;
    int count = 0;
    while (file.read((char*)&temp, sizeof(temp))){
        count++; 
        output.push_back(temp);
    }
    cout << "Loaded " << count << " records to O/P of this function succesfully!" << endl;
    return output;
}

void search_list(int &target_id, list<Employee> &emps){      // Displays Employee if found
    list<Employee>::iterator itr = emps.begin();
    bool found = false;
    while (itr != emps.end()){
        if (itr->get_id() == target_id){
            found = true;
            itr->display();
            return;
        }
        itr++;
    }
    if (!found){
        cout << "Not found" << endl;
    }       // if not found: itr == emps.end()
}           // search by index doesnt make sense for linked list

void delete_node(int target_id , list<Employee> &emps){
    list<Employee>::iterator itr = emps.begin();
    bool found = false;
    while (itr != emps.end())
    {
        if (itr->get_id() == target_id){
            emps.erase(itr);
            found = true;
            cout << "Deleted successfully." << endl;
            return;                      // must return/break when youre deleting due to itr invalidation on erasure.
        itr++;
    }
    if (!found){
        cout << "No such id was found" << endl;
    }
    }
}

int main(){
    list<Employee> employees;
    int choice = 0;
    while (choice != -1){
        cout << "Enter choice: " << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Find Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Save Employees to File" << endl;
        cout << "6. Load Employees from a File" << endl;
        cout << "-1. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:{    // Add emp
            Employee e1;
            e1.accept();
            employees.push_back(e1);
            break;
        }
        case 2:{    // Display emps
            list<Employee>::iterator itr = employees.begin();
            while(itr != employees.end()){
                itr->display();
                itr++;
            }
            break;
        }
        case 3:{    // Find emp
            int target_id;
            cout << "Enter id of emp to be found: " << endl;
            cin >> target_id;
            search_list(target_id, employees);
            break;
        }
        case 4:{    // Delete emp
            int target_id;
            cout << "Enter id of emp to be deleted: " << endl;
            cin >> target_id;
            delete_node(target_id, employees);
            break;
        }
        case 5:{    // Save list to file
            Save_to_file(employees);                // appends to file, records will repeat if you push after loading from the file
            break;
        }
        case 6:{    // Load emp list from file
            employees = Load_from_file();
            break;
        }
        case -1:{   // Exit. Needed to not run the default case when prompted to exit
            cout << "Exiting..." << endl;
            break;
        }

        default:
            cout << "Invalid Choice. Read before you act." << endl;
            break;
        }
    }
}