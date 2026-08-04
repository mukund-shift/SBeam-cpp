#include <iostream>
using namespace std;

#pragma pack(1)

class A {
public:
    int a;
    A() {
        a = 1;
        // Early binding or Late binding => Early binding
        // A::f2 or B::f2 called? => A::f2
    }
    void f1() {
        cout << "A::f1() called" << endl;
    }
    virtual void f2() {
        cout << "A::f2() called" << endl;
    }
    void f3() {
        cout << "A::f3() called" << endl;
    }
    virtual void f4() {
        cout << "A::f4() called" << endl;
    }
    void funA() {
        cout << "A::funA() called" << endl;
        this->f2(); 
        // Early binding or Late binding => Late binding
        // A::f2 or B::f2 called? => B::f2 -- when obj is of B (objB)
    }
};

class B : public A {
public:
    int b;
    B() {
        b = 2;
        // Early binding or Late binding => Early binding
        // A::f2 or B::f2 called? => B::f2
    }
    void f1() {
        cout << "B::f1() called" << endl;
    }
    virtual void f2() {
        cout << "B::f2() called" << endl;
    }
    virtual void f3() {
        cout << "B::f3() called" << endl;
    }
    void f5() {
        cout << "B::f5() called" << endl;
    }
    virtual void f6() {
        cout << "B::f6() called" << endl;
    }
};


int main() {
    //A objA;
    B objb;
    A* ptrA = &objb;

    B* ptrB = &objb;

    // ptrA->f1();
    // ptrA->f2();
    // ptrA->f3();
    // ptrA->f4();


    // ptrA->f5(); // through base class ptr pointing to derived class obj,  we can only call functions defined in base class (even if its overriden later in class of derived object)
    // ptrA->f6();

    ptrB->f1();
    ptrB->f2();
    ptrB->f3();
    ptrB->f4();


    ptrB->f5(); // through base class ptr pointing to derived class obj,  we can only call functions defined in base class (even if its overriden later in class of derived object)
    ptrB->f6();




    return 0;
}