// 1. Implement class Manager inherited from Employee class. 
// Employee has protected field salary and private field id. Manager has private field bonus. 
// Implement calc_gross_salary() method in both classes with appropriate logic. 
// Also implement constructors, destructors, getter/setters, facilitators, and test these methods in main().

#include <iostream>
using namespace std;

class Employee{
private:
    int id;
protected:
    int salary;
public:
    Employee(int id, int salary){
        this->id = id;
        this->salary = salary;
        cout << "Employee() called." << endl;
    }
    ~Employee(){
        cout << "~Employee() called." << endl;
    }
    int calc_gross_salary(){
        return this->salary;
    }
};

class Manager : public Employee{
private:
    int bonus;
public:
    Manager(int id, int salary, int bonus)
        : Employee(id, salary)
    {
        this->bonus = bonus;
        cout << "Manager() called." << endl;
    }
    ~Manager(){
        cout << "~Manager() called." << endl;
    }
    int calc_gross_salary(){
        return (this->salary + this->bonus);
    }
};

int main(){
    Employee e1(1, 4000);
    int test = e1.calc_gross_salary();
    cout << "e1 gross salary: " << test << endl;
    Manager m1(2, 40000, 5000);
    Manager m2(3, 32000, 3000);
    Manager m3(4, 35000, 6000);
    test = m1.calc_gross_salary();
    cout << "m1 gross salary: " << test << endl;
    test = m2.calc_gross_salary();
    cout << "m2 gross salary: " << test << endl;
    test = m3.calc_gross_salary();
    cout << "m2 gross salary: " << test << endl;
    return 0;
}
