#include "assign16_p2.h"
using namespace std;

int main(){
    SalesManager s1(5800, 4000, 5300, 40000);
    Employee e1(12000);
    Salesman sm1(3000, 12000);
    Manager m1(5000, 15000);
    s1.display();
    m1.display();
    e1.display();
    sm1.display();
    return 0;
}
