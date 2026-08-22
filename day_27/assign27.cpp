// 1. Complete LinkedList template class with remaining operations.
// 2. Implement Stack and Queue using above LinkedList class.

#include <iostream>
using namespace std;

template <typename T>
class Node{
    T data;
    Node* next;

public:
    Node(T d): data(d), next(nullptr){}

    template<>
    friend LinkedList;

};

template<typename T>
class LinkedList{
    Node* head;             // to move, use head->next. head is just a node ptr, not a node

public:
    LinkedList(): head(nullptr){}

    void add_last(T data){

        Node* nn = new Node(data);

        // Traversal Logic start

        if (head == nullptr) {
            head = nn;                   // maybe we cant do unless we create a dummy node
            // First thought: head->next == nn, Takeaway: head is only a ptr to the first node
        }
        else{
            Node* curr = head;
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
            Node* curr = head;
            while (curr->next != nullptr)       // curr will be at last node after while loop completes;
            {   
                Node* temp = curr;              // OG curr
                curr = curr->next;              // New curr
                if (curr->next == nullptr){     // Checking if new curr is last node. Last node: next == nullptr
                    T temp_data = curr->data;
                    delete curr;
                    return temp_data;
                } 
            }

        // Traversal Logic end
        }
    }

    void add_first(T data){
        Node* nn = new Node(data);
        if (head == nullptr){
            head = nn;
        }
        else{
            // Node* temp_next = head->next;       // To keep track of next node address;
            // nn->next = temp_next;
            // head = nn;                           1st attempt: Wrong bcz this replaces head node with new head node

            Node* old_head = head;
            head = nn;
            head->next = old_head;
        }
    }

    T del_first(){
        if (head == nullptr){
            cout << "Empty list!!!" << endl;
        }
        else{
            old_head = head;
            head = head->next;
            temp_data = old_head->data;
            delete old_head;
            return temp_data;
        }
    }
    
    void display_list(){
        if (head == nullptr){
            cout << "Empty list!" << endl;
        }
        else{
            Node* curr = head;
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