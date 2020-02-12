/* Title: hw3-2.cpp​
 * Abstract: List operations
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 4h
 * Date: 02/05/2020
*/

const int MAX = 20;

class List {

public:
  List();
  // Setters
  void append(int value); // done
  void append(const List l); // Wasn't sure how to use the built in function
  bool remove(int value); // Wasn't sure how to use the built in function
  // Getters
  int getSize() const; // done
  int getValue(int pos) const; // done
  bool hasDuplicates() const; // done
  bool isSorted() const; // done
  void printAll() const; // done

private:
  int mySize;
  int myArray[MAX];
};


#include <iostream>
using namespace std;

int main() {

  List intList;
  intList.append(10);
  intList.append(20);
  intList.append(30);
  intList.append(100);

  intList.isSorted();
  intList.hasDuplicates();

  intList.printAll();

}

List::List()
: mySize(0) {}

// Setter functions
void List::append(int value) {
    myArray[mySize] = value;
    mySize++;
}

void List::append(const List l) {

}

bool List::remove(int value) {
  return true;
}



// Getter functions
int List::getSize() const {
  return mySize;
}

int List::getValue(int pos) const {
  return myArray[pos];
}


bool List::hasDuplicates() const {

  for(int i = 0; i < mySize; i++) {

    for(int j = i+1; j < mySize; j++) {

      if(myArray[i] == myArray[j]) {
        cerr << "Array has duplicates!" << endl;
        return true;
      }
    }
  }
  return false;
}


bool List::isSorted() const {

  int max = myArray[0];
  for(int i = 1; i < mySize; i++) {
    if(max <= myArray[i]) {
      max = myArray[i];
    } else {
      cerr << "Array is not sorted!" << endl;
      return false;
    }
  }
  return true;
}

void List::printAll() const {
  for(int i = 0; i < mySize; i++) {
    cout << myArray[i] << " ";
  }
}
