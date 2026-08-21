// 1. Implement generic Array class with appropriate members.
// 2. How to use our generic Stack<T> class with char str[20];?

#include <iostream>
using namespace std;

template<typename T>
class Stack{
    T arr[100];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(T ele){
        top++;
        arr[top] = ele;
    }
    T pop(){
        cout << "Popping..." << endl;
        return arr[top--];
    }
    void display(){
        cout << "Stack: " << endl;
        for (int i = 0; i <= top; i++){
            cout << arr[i] << ", ";
        }
        cout << " <-- TOP" << endl;
    }
};


int main(){
    Stack<int> s1;
    s1.push(31);
    s1.push(32);
    s1.push(33);
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();

}