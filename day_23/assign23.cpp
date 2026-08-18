// 1. Implement a Fraction class with fields numerator and denominator.
//  Provide appropriate conversion functions. Overload relevant operators.
//  Implement a function object to check if the given Fraction is proper object or not.

#include <iostream>
using namespace std;

class Fraction{
private:
    int num;
    int den;

public:
Fraction(int num, int den){
    this->num = num;
    this->den = den;
}
explicit operator double(){
    return (this->num)/(this->den);
}

void operator=(int num){
    this->num = num;
    this->den = 1;
}

double operator+(Fraction f){
    double temp = (double)*this + (double)f;
    return temp;
}


};

int main(){
    Fraction f1(3, 4);
    double temp = (double) f1;
    cout << temp << endl;
    
    return 0;
}


// Overload cout for fraction and implement functor for 3rd req in question.