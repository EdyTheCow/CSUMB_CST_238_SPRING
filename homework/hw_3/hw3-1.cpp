/* Title: hw3-1.cpp​
 * Abstract: Program which defines two classes, Student and Course
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 3h
 * Date: 02/05/2020
*/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

const int MAX = 30;

class Student {
public:
    Student();
    Student(string name, int id);
    Student(string name);
    int getID() const;
    string getName() const;
    void setName (string newName);
    void display() const;
private:
  string name;
  int id;
};

class Course {
public:
    Course();
    Course(string title, int number, string instructorName) ;
    // Getters
    void printAll() const;
    int getNumber() const;
    string getInstructor() const;
    string getTitle() const;
    Student get(int pos) const;
    // Setters
    bool add(Student s);
    bool remove(Student s);
    bool checkID(int id) const;

private:
  string title;
  int number;
  string instructorName;
  Student students[MAX];
  int enrolled;
  int mySize;
};

int main() {
  Course c1("Intro to Everything", 123, "Dr. Gross");
  Student s1("Jane", 1234);
  Student s2("Phillipe", 1235);
  Student s3("Lu", 1236);
  Student s4("Enrique", 1237);
  c1.add(s1);
  c1.add(s2);
  c1.add(s3);
  c1.add(s4);

  // Wasn't able to get the functions to work properly
  s1.setName("Bob");

  // This works on it'a own but doesn't work properøy when used in another function
  c1.checkID(1234);

  c1.printAll();
}

/*

STUDENT SECTION

*/

// Constructor
Student::Student()
: Student("", 0) {}

Student::Student(string name) {
  setName(name);
}

Student::Student (string name, int id)
: id(id), name(name) {}

// Getters
void Student::display() const {
  cout <<"    " << name << ": " << id << endl;
}

int Student::getID() const {
  return id;
}

string Student::getName() const {
  return name;
}

// Setters
void Student::setName(string newName) {
  name = newName;
}


/*

COURSE SECTION

*/

// Constructor
Course::Course (string title, int number, string instructorName)
: title(title), number(number), instructorName(instructorName) {}

Course::Course()
: mySize(0) {}

// Setter functions
bool Course::add(Student s) {

    if(mySize < MAX) {
      students[mySize] = s;
      mySize++;
      return true;
    } else {
      cout << "Course is at maximum capacity!\n";
      return false;
    }
  }

bool Course::remove(Student s) {
  return true;
}

// Getter functions

bool Course::checkID(int id) const {

  for (int i = 0; i < mySize; i++) {
    if (id == students[i].getID()) {
      cout << "Duplicate found!\n";
      return false;
    }
  }
  return true;
}


Student Course::get(int pos) const {
  return students[pos];
}

int Course::getNumber() const {
  return number;
}

string Course::getTitle() const {
  return title;
}

string Course::getInstructor() const {
  return instructorName;
}

void Course::printAll() const {
  cout << "Course Title: " << title << endl;
  cout << "Course Number: " << number << endl;
  cout << "Instructor: " << instructorName << endl;
  cout << "Enrolled: " << mySize << endl;

  for (int i = 0; i < mySize; i++) {
    students[i].display();
  }
}
