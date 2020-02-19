/* Title: hw4-1.cpp​
 * Abstract: Convert numbers to binary
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 3h
 * Date: 02/12/2020
*/

/***********************************************************************
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap07/Figures7.4-5/
 * Updated by Dr. Byun for CST238
 * Basic operations:
 *   constructor:  Constructs an empty stack
 *   empty:        Checks if a stack is empty
 *   push:         Modifies a stack by adding a value at the top
 *   top:          Retrieves the top stack value; leaves stack unchanged
 *   pop:          Modifies stack by removing the value at the top
 *   display:      Displays all the stack elements
 ************************************************************************/

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 128;
typedef int StackType;

class Stack {
public:
  Stack();
  bool empty() const;
  void push(StackType value);
  void display() const;
  StackType top() const;
  void pop();

private:
  StackType myArray[STACK_CAPACITY];
  int myTop;
};


//--- Definition of Stack constructor
Stack::Stack()
: myTop(-1) {}

//--- Definition of empty()
bool Stack::empty() const {
  return (myTop == -1);
}

//--- Definition of push()
void Stack::push(StackType value) {
  if (myTop < STACK_CAPACITY - 1) {
    ++myTop;
    myArray[myTop] = value;
  }
  else {
    cerr << "*** Stack full -- can't add new value ***\n"
            "Must increase value of STACK_CAPACITY.\n";
    return;
  }
}

//--- Definition of display()
void Stack::display() const {

  for (int i = myTop; i >= 0; i--) {
    cout << myArray[i] << endl;
  }
}

//--- Definition of top()
StackType Stack::top() const {
  if (!empty()) {
    return (myArray[myTop]);
  }
  else {
    cerr << "*** Stack is empty -- returning garbage value ***\n";
    StackType garbage;
    return garbage;
  }
}

//--- Definition of pop()
void Stack::pop() {
  if ( !empty() ) {
    myTop--;
  }
  else {
    cerr << "*** Stack is empty -- can't remove a value ***\n";
  }
}

int main() {
  Stack s;
  int n;
  int userInput;
  int t = 0;
  cout << "Enter a number: ";
  cin >> n;
  userInput = n;

  while(n > 0) {
    t = n % 2;
    n /= 2;
    s.push(t);
  }

  cout << userInput << " => ";

  while(!s.empty()) {
    cout << s.top();
    s.pop();
  }

  cout << endl;

}
