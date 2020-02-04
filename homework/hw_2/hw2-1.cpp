/* Title: hw2-1.cpp​
 * Abstract: This program reads from array and provides options to manipulate an array
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 5h
 * Date: 01/30/2020
*/

#include <iostream>
#include <climits>
using namespace std;

int main() {

  int arr[10] = {10, 20, 30, 40, 50, 15, 25, 35, 45, 55};
  char option = 'y';
  int operation;
  int size = 10;

  cout << "Array values: ";

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  while (option == 'y') {

    cout << "This is a list of operations" << endl;
    cout << "   1. Delete the max" << endl;
    cout << "   2. Append a number" << endl;
    cout << "   3. Reverse array" << endl;
    cout << endl;
    cout << "Enter your option: ";

    // Select operation
    cin >> operation;

    // Delete max from array
    if (operation == 1) {

      int max = arr[0];
      int index = 0;

      for (int i = 1; i < 10; i++) {
        if (max < arr[i]) {
          max = arr[i];
          index = i;
        }
      }
      size--;
      arr[index] = 0;

      for (int i = index; i < size; i++) {
        // Swap variables
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
      }
    }


    // Append new value to array
    if (operation == 2) {

      if (size == 10) {
        cout << "Array is full and can’t append anymore." << endl;
      } else {

        int userInput;
        cout << "Enter the number to append: ";
        cin >> userInput;

        arr[size] = userInput;
        size++;

      }
    }

    // Reverse array
    if (operation == 3) {

      int n = size-1;
      for (int i = 0; i < size / 2; i++) {
        // Swap variables
        int temp = arr[n];
        arr[n] = arr[i];
        arr[i] = temp;
        n--;
      }

    }

    // print array
    cout << "New array values: ";
    for (int i = 0; i < 10; i++) {
      cout << arr[i] << " ";
    }

    // Ask to continue
    cout << endl;
    cout << "Continue? (Y/N): ";
    cin >> option;

  }

}
