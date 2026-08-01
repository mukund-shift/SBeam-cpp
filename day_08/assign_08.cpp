// 1. How will you create queue using Linked List?
// 2. Create two base classes, AcademicResult and SportsResult to store the score of academics and grade of sports.
//  Now create a class StudentProgressCard that stores a student's name and roll number, academic result and sports result.
//   Finally display the progress card.


// 1: We can use add_to_first and del_last methods in a linked list to simulate a queue with linked list, and make 
//      the facilitators of linked list to be private in our derived queue class and only redefine these 2 methods as public


// 2: We can use both composition and multiple inheritance for the Progress card, I'll use the latter
#include <iostream>
#include <string>
using namespace std;

class AcademicResult{
    int score;

public:
    AcademicResult(int score = 0){
        this->score = score;
    }

    inline int get_score(){
        return this->score;
    }

    ~AcademicResult(){}
};

class SportsResult{
    int grade;
public:
    SportsResult(int grade = 0){
        this->grade = grade;
    }
    inline int get_grade(){
        return this->grade;
    }
    ~SportsResult(){}
};

class StudentProgressCard: public AcademicResult, public SportsResult{
    string name;
    int roll;

public:
    StudentProgressCard(string name, int roll, int acad, int sport): AcademicResult(acad), SportsResult(sport)
    {
        this->name = name;
        this->roll = roll;
        cout << "StudentProgressCard() called" << endl;
    }
    ~StudentProgressCard()
    {
        cout << "~StudentProgressCard() called" << endl;
    }

    void display_card(){
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
        cout << "Academic Score: " << AcademicResult::get_score() << endl;
        cout << "Sports Result: " << SportsResult::get_grade() << endl;
    }
};

int main(){
    string name1 = "mknd";
    StudentProgressCard s1(name1, 32, 91, 8);
    s1.display_card();
}