/* Title: hw2-3.cpp​
 * Abstract: This program reads bank data from a file, inserts it into a structure and displays search able data
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 3h
 * Date: 01/30/2020
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // Student structure
  struct Customer {
    string name;
    int id;
    double balance;
  };

  // Read from file
  cout << "Enter an input file: ";
  string file_name;
  cin >> file_name;
  ifstream f_input(file_name);
  if (f_input.fail()) {
    cout << "Error: Input file open failed.\n";
    return 0;
  }

  Customer account[30];
  int size = 0;

  // insert data from file to structure
    for (int i = 0; i < 30; i++) {

      f_input >> account[i].name >> account[i].id >> account[i].balance;

      if (account[i].name == "STOP") {
        size = i;
        break;
      }

    }

  // print out the account information
  string search;
  char continueOption = 'y';
  bool searchCheckError = true;

  while (continueOption == 'y') {

    cout << "---------------------------------------------------" << endl;
    cout << "  Record Finder - Enter a customer name: ";
    cin >> search;
    cout << "---------------------------------------------------" << endl;


    for (int i = 0; i < size; i++) {

      if (search == account[i].name) {
        cout << endl;
        cout << "  Name: " << account[i].name << endl;
        cout << "  Account: " << account[i].id << endl;
        cout << "  Balance: " << account[i].balance << endl;
        searchCheckError = false;
      }
    }

    if (searchCheckError) {
      cout << "Fail. " << search << " doesn't exist." << endl;
    }

    cout << "---------------------------------------------------" << endl;
    cout << "  Do you want to continue? (y/n) ";
    cin >> continueOption;

    searchCheckError = true;

    if (continueOption != 'y') {
      cout << endl;
      cout << "  BYE!";
    }

  }

}
