#include <iostream>
#include <cstring>
using namespace std;

// forward class declaration
template<typename T>
class List;

template<typename T>
class Node {
private:
    T data;
    Node<T>* next;
public:
    Node() {
        data = T();
        next = NULL;
    }
    Node(T val) {
        data = val;
        next = NULL;
    }
    // friend class declaration
    friend class List<T>;      // this syntax work well with VS IDE & compiler

    //friend class List<T>; // this syntax works well with all compilers
};

// class definition
template<typename T>
class List {
private:
    Node<T>* head;
public:
    List() {
        head = NULL;
    }
    void add_last(T val) {
        Node<T>* nn = new Node<T>(val);
        if (head == NULL)
            head = nn;
        else {
            Node<T>* trav = head;
            while (trav->next != NULL)
                trav = trav->next;
            trav->next = nn;
        }
    }
    void display() {
        Node<T>* trav = head;
        while (trav != NULL) {
            cout << trav->data << ", ";
            trav = trav->next;
        }
        cout << endl;
    }
    void clear() {
        while (head != NULL) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    ~List() {
        clear();
    }
    // ...
};

// Stack is a LinkedList in which push(), pop(), ops are implemented.
template <typename T>
class Stack : private List<T> {
public:
    List<T>::display;
    void push(T val) {
        List<T>::add_last(val);
    }
    T pop() {
        // ...
    }
};

class Person {
private:
    char name[32];
    int age;
public:
    Person(const char* nm = "", int a = 0) {
        strcpy(name, nm);
        age = a;
    }
    friend ostream& operator<<(ostream& out, Person& p);
};

ostream& operator<<(ostream& out, Person& p) {
    out << "(" << p.name << ", " << p.age << ")";
    return out;
}

int main() {
    List<int> l1;
    l1.add_last(11);
    l1.add_last(22);
    l1.add_last(33);
    l1.display();
    cout << endl;

    List<double> l2;
    l2.add_last(1.1);
    l2.add_last(2.2);
    l2.add_last(3.3);
    l2.display();
    cout << endl;

    Person p1("James Bond", 65);
    Person p2("Superman", 876);
    Person p3("Batman", 40);
    List<Person> l3;
    l3.add_last(p1);
    l3.add_last(p2);
    l3.add_last(p3);
    l3.display();
    cout << endl;

    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.display();
    return 0;
}