// 1. Create a class Employee (id, name, sal).                     
//  Implement menu driven program to manage employee in a vector.   
//   Menu options: Add Emp, Display All Emp, Find Emp, Delete Emp, Save to file, Load from file.             
// 3. Store n integers in a vector and find the maximum and minimum elements using vector operations.


#include <iostream>
#include <vector>
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

    void clean(){           // not needed since we have vector.erase();
        // replaces all data of obj to a "deleted/cleansed" state
        id = -1;
        strcpy(name, "Deleted");
        sal = -1;
    }
};

void Save_to_file(vector<Employee> Emp_vector , const char filename[20] = "Employees.dat"){
    fstream file(filename, ios::app|ios::binary);
    vector<Employee>::iterator itr = Emp_vector.begin();
    while (itr != Emp_vector.end()){
        file.write((char*)&(*itr), sizeof(Employee));
        itr++;
    }
    cout << "Saved " << itr - Emp_vector.begin() << " records successfully to " << filename << endl;
    // (itr - Emp_vector.begin()) evaluates to no of records saved, since itr==Emp_vector.end() after done saving
}

vector<Employee> Load_from_file(const char filename[20] = "Employees.dat"){
    vector<Employee> output;
    output.reserve(10);
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

void search_vector(int &target_id, vector<Employee> &emps){      // Displays Employee if found
    vector<Employee>::iterator itr = emps.begin();
    bool found = false;
    while (itr != emps.end()){
        if (itr->get_id() == target_id){
            found = true;
            itr->display();
        }
        itr++;
    }
    if (!found){
        cout << "Not found" << endl;
    }
}

void delete_from_vector(int &target_id, vector<Employee> &emps){      // Deletes Employee if found
    vector<Employee>::iterator itr = emps.begin();
    bool found = false;
    while (itr != emps.end())
    {
        if (itr->get_id() == target_id){
            emps.erase(itr);
            found = true;
            cout << "Deleted succesfully." << endl;
            break;              // must break when youre deleting due to itr invalidation on erasure.
        }
        itr++;
    }
    if (!found){
        cout << "No such id was found" << endl;
    }
}

int main(){
    vector<int> numbers = {42, 32, 53, 89, 31, 81, 58};
    auto itr = max_element(numbers.begin(), numbers.end());
    cout << "Max element: " << *itr << endl;
    itr = min_element(numbers.begin(), numbers.end());
    cout << "Min element: " << *itr << endl;
}

// int main(){
//     vector<Employee> employees;
//     int choice = 0;
//     while (choice != -1){
//         cout << "Enter choice: " << endl;
//         cout << "1. Add Employee" << endl;
//         cout << "2. Display Employees" << endl;
//         cout << "3. Find Employee" << endl;
//         cout << "4. Delete Employee" << endl;
//         cout << "5. Save Employees to File" << endl;
//         cout << "6. Load Employees from a File" << endl;
//         cout << "-1. Exit" << endl;
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:{    // Add emp
//             Employee e1;
//             e1.accept();
//             employees.push_back(e1);
//             break;
//         }
//         case 2:{    // Display emps
//             vector<Employee>::iterator itr = employees.begin();
//             while(itr != employees.end()){
//                 itr->display();
//                 itr++;
//             }
//             break;
//         }
//         case 3:{    // Find emp
//             int target_id;
//             cout << "Enter id of emp to be found: " << endl;
//             cin >> target_id;
//             search_vector(target_id, employees);
//             break;
//         }
//         case 4:{    // Delete emp
//             int target_id;
//             cout << "Enter id of emp to be deleted: " << endl;
//             cin >> target_id;
//             delete_from_vector(target_id, employees);
//             break;
//         }
//         case 5:{    // Save vector to file
//             Save_to_file(employees);                // appends to file, records will repeat if you push after loading from the file
//             break;
//         }
//         case 6:{    // Load emp vector from file
//             employees = Load_from_file();
//             break;
//         }
//         case -1:{   // Exit. Needed to not run the default case when prompted to exit
//             cout << "Exiting..." << endl;
//             break;
//         }

//         default:
//             cout << "Invalid Choice. Read before you act." << endl;
//             break;
//         }
//     }
// }