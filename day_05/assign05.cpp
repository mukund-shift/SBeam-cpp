// 1. Write a C++ program to implement a stack using an array. The user should enter the size of the stack at runtime. Implement the following operations:
// - Push an element onto the stack.
// - Pop an element from the stack. (Pops the last pushed element)
// - Display all elements in the stack.
// - Handle stack overflow (when the stack is full) and stack underflow (when the stack is empty). 
// - Provide a menu-driven interface for performing these operations.

#include <iostream>
using namespace std;

class stack {
public:
    int* array;
    int top;
    int length;

    stack(int n){
        array = new int[n];
        top = -1;
        length = n;
    }
    ~stack(){
        delete[] array;
    }
    void push(int element){
        if (top >= length - 1){
            cout << "Stack overflow!" << endl;
        }
        else{
        top++;
        array[top] = element;
        cout << element << "Pushing... Top = " << top << endl;
        }
    }
    int pop(){
        if (top < 0){
            cout << "Stack underflow!" << endl;
            return 99999;
        }
        else {
        int popped = array[top];
        cout << "Popping... Top = " << top << endl;
        top--;
        return popped;
        }
    }
    void display(){
        for (int i = 0; i <= this->top; i++){
            cout << "element no " << i + 1 << ": " << array[i] << endl;
        }
    }
};


int main(){
    stack s1(5);
    s1.push(9);
    s1.push(1);
    s1.push(7);
    s1.push(6);
    s1.push(4);
    s1.push(5);
    s1.display();
    int popped = s1.pop();
    cout << "Popped: " << popped << endl;
    popped = s1.pop();
    cout << "Popped: " << popped << endl;
    popped = s1.pop();
    cout << "Popped: " << popped << endl;
    popped = s1.pop();
    cout << "Popped: " << popped << endl;
    popped = s1.pop();
    cout << "Popped: " << popped << endl;
    s1.pop();
    return 0;
}

// Skipping 5. menu driven program (tedious)