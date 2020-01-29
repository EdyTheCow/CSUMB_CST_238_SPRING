/* Title: hw1-3.cpp​
 * Abstract: This program reads data from file and draw a horizontal histogram for the numbers
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 4h
 * Date: 01/25/2020
*/

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main() {

  cout << "Enter input file name: ";
  string file_name;
  cin >> file_name;

  // Open the input file.
  // Variable "f_input" is an input file stream object
  // from which you can read data similarly to
  // the standard input stream cin.
  ifstream f_input(file_name);

  if (f_input.fail()) {
      cout << "Error: Input file open failed.\n";
      return 0;
  }

  int size;
  int value[7];
  int n;
  int maxNumber;
  int counter = 0;

  cout << endl;
  cout << "===== Vertical Histogram =====" << endl;

  while (f_input >> n) {
    value[counter] = n;
    counter++;
  }

  maxNumber = value[0];

  // Check if maxNumber is the highest number
  for (int i = 0; i < 7; i++) {
    if (value[i] > maxNumber) {
      maxNumber = value[i];
    }
  }

  // Print stars and spaces
  for(int i = maxNumber; i >= 1; i--) {

    for(int n = 0; n < 7; n++) {
      if(value[n] >= i) {
          cout << ("* ");
      }
      else {
        cout << ("  ");
      }
    }
    cout << endl;
  }

  cout << ("-------------") << endl;

  // Print numbers from file
  for (int i = 0; i < 7; i++) {
    cout << value[i] << (" ");
  }
  cout << endl;

  // Close the input file stream object.
  f_input.close();

  return 0;
}
