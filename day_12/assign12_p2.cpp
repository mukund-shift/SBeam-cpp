#include <iostream>
using namespace std;

#pragma pack(1)

class B {
public:
	int b;
	virtual void bf1() {
        cout << "bf1() called" << endl;
    }
	virtual void bf2() {
        cout << "bf2() called" << endl;
    }
};
class C {
public:
	int c;
	virtual void cf1() {
        cout << "cf1() called" << endl;
    }
	virtual void cf2() {
        cout << "cf2() called" << endl;
    }
};
class D : public B, public C {
public:
	int d;
	virtual void df1() {
        cout << "df1() called" << endl;
    }
	virtual void df2() {
        cout << "df2() called" << endl;
    }
};
int main()
{
	B objB;
	C objC;
	D objD;
	cout << "sizeof(B) = " << sizeof(B) << endl; // 12
	cout << "sizeof(C) = " << sizeof(C) << endl; // 12
	cout << "sizeof(D) = " << sizeof(D) << endl; // 28
	B* pb = &objD;
	pb->bf1();
	pb->bf2();
	C* pc = &objD;
	pc->cf1();
	pc->cf2();
	D* pd = &objD;
	pd->bf1();
	pd->bf2();
	pd->df1();
	pd->df2();
	pd->cf1();
	pd->cf2();
	return 0;
}