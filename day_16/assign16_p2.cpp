#include "assign16_p2.h"

int Employee::id_ctr = 1;

Employee::Employee(int salary){
    this->id = Employee::id_ctr;
    Employee::id_ctr++;
    this->salary = salary;
}
Employee::~Employee(){
    cout << "~Employee() called." << endl;
}
void Employee::display(){
    cout << "ID: " << this->id << endl;
    cout << "Salary: " << this->salary << endl;
}

Salesman::Salesman(int comm, int salary): Employee(salary)
{
    this->comm = comm;
}
Salesman::~Salesman(){
    cout << "~Salesman() called." << endl;
}
void Salesman::display(){
    Employee::display();
    cout << "Commission: " << this->comm << endl;
}

Manager::Manager(int bonus, int salary): Employee(salary)
{
    this->bonus = bonus;
}
Manager::~Manager(){
    cout << "~Manager() called." << endl;
}
void Manager::display(){
    Employee::display();
    cout << "Bonus: " << this->bonus << endl;
}

SalesManager::SalesManager(int incentives, int comm, int bonus, int salary)
: Employee(salary), Salesman(comm, salary), Manager(bonus, salary)
{
    this->incentives = incentives;
}
SalesManager::~SalesManager(){
    cout << "~SalesManager() called." << endl;
}
void SalesManager::display(){
    Salesman::display();
    Manager::display();
    cout << "Bonus: " << this->incentives << endl;
}

// dont write default args in .cpp module