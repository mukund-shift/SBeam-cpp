// 1. Complete LinkedList template class with remaining operations.
// 2. Implement Stack and Queue using above LinkedList class.

#include <iostream>
using namespace std;

template<typename T>
class LinkedList;

template <typename T>
class Node{
    T data;
    Node* next;

public:
    Node(T d): data(d), next(nullptr){}

    friend class LinkedList<T>;

};

template<typename T>
class LinkedList{
    Node<T>* head;             // to move, use head->next. head is just a node ptr, not a node

public:
    LinkedList(): head(nullptr){}

    void add_last(T data){

        Node<T>* nn = new Node<T>(data);

        // Traversal Logic start

        if (head == nullptr) {
            head = nn;                   // maybe we cant do unless we create a dummy node
            // First thought: head->next == nn, Takeaway: head is only a ptr to the first node
        }
        else{
            Node<T>* curr = head;
            while (curr->next != nullptr)       // curr will be at last node after while loop completes;
            {
                curr = curr->next;
            }                                   // curr->next != nullptr used bcz we want to keep curr pointing
                                                // to the last node when loop ends

        // Traversal Logic end

            curr->next = nn;
        }
    }

    T del_last(){
        // Traversal Logic start
        
        if (head == nullptr) {
            cout << "List is empty!" << endl;
        }
        else{
            Node<T>* curr = head;
            while (curr->next != nullptr)       // curr will be at last node after while loop completes;
            {   
                Node<T>* temp = curr;              // OG curr
                curr = curr->next;              // New curr
                if (curr->next == nullptr){     // Checking if new curr is last node. Last node: next == nullptr
                    temp->next = nullptr;       // severing ties of last node from the list(pointed at by curr)
                    T temp_data = curr->data;
                    delete curr;                // freeing memory
                    
                    return temp_data;
                }
            }

        // Traversal Logic end
        }
    }

    void add_first(T data){
        Node<T>* nn = new Node<T>(data);
        if (head == nullptr){
            head = nn;
        }
        else{
            // Node* temp_next = head->next;       // To keep track of next node address;
            // nn->next = temp_next;
            // head = nn;                           1st attempt: Wrong bcz this replaces head node with new head node

            Node<T>* old_head = head;
            head = nn;
            head->next = old_head;
        }
    }

    T del_first(){
        if (head == nullptr){
            cout << "Empty list!!!" << endl;
        }
        else{
            Node<T>* old_head = head;
            head = head->next;
            T temp_data = old_head->data;
            delete old_head;
            return temp_data;
        }
    }
    
    void display_list(){
        if (head == nullptr){
            cout << "Empty list!" << endl;
        }
        else{
            Node<T>* curr = head;
            while (curr != nullptr)
            {   
                cout << "Data: " << curr->data << endl;
                curr = curr->next;
            }                               // curr != nullptr used bcz we dont need to keep curr at last node
                                            // when only displaying elements, i.e. its ok if we lose track of 
                                            // last node as long as we make sure to display everything along the way
        }
    }

};

template <typename T>
class Stack: private LinkedList<T>{
using LinkedList<T>::add_first;
using LinkedList<T>::del_first;
using LinkedList<T>::add_last;
using LinkedList<T>::del_last;

public:

    // void push(T ele){
    //     add_first(ele);
    // }
    // T pop(){
    //     cout << "Popping..." << endl;
    //     return del_first();
    // }

    void push(T ele){
        add_last(ele);
    }
    T pop(){
        cout << "Popping..." << endl;
        return del_last();
    }

    void display_stack(){
        cout << "---------------------------------------------------------------------" << endl;
        cout << "Stack Display: " << endl;
        LinkedList<T>::display_list();
        cout << "---------------------------------------------------------------------" << endl;
    }

};

int main(){
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(100);
    s1.push(40);
    s1.display_stack();
    s1.pop();
    s1.display_stack();
    s1.pop();
    s1.display_stack();
}