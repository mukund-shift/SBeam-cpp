// 1. Implement generic Array class with appropriate members.
// 2. How to use our generic Stack<T> class with char str[20];?

#include <iostream>
#include <string>
#include <cstring>
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

template <>
class Stack<char*>{
    char* arr[100];             // array of 100 char ptrs
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(const char* str){
        char* temp = new char[30];  // very impt to use dyn_alloc else temp gets same address always and all 
                                    // char* of stack point to same location
        strcpy(temp, str);
        top++;
        arr[top] = temp;
        cout << "Pushed: " << temp << endl;
    }
    string pop(){
        cout << "Popping..." << endl;
        string temp;
        temp = arr[top];
        delete[] arr[top--];
        return temp;                        // must use string here since returning char* causes dangling ptr
    }                                       // or you can use char* but u cant return anything from pop() then.
    void display(){
        cout << "----------------------------------" << endl;
        cout << "Stack: " << endl;
        for (int i = 0; i <= top; i++){
            cout << arr[i] << ", ";
        }
        cout << " <-- TOP" << endl;
        cout << "----------------------------------" << endl;
    }
    ~Stack() {
        while (top >= 0) {
            delete[] arr[top];
            top--;
        }
    }
};


int main(){
    Stack<char*> s1;
    s1.push("Hi");
    s1.push("I");
    s1.push("See");
    s1.push("You");
    s1.push("Do");
    s1.push("You?");
    s1.display();
    string popped = s1.pop();
    cout << "Popped: " << popped << endl;
    s1.display();
    s1.pop();
    s1.display();
    s1.push("There.");
    s1.display();
}