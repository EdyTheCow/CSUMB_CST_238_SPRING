/* Title: hw1-1.cpp​
 * Abstract: This program reads data from file and displays them in formatted manner
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 3h
 * Date: 01/24/2020
*/

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

int main() {

    int max = 9999999;

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

	// Read the first number in the file.
    f_input >> size;

    int values[30];
    int output[30];
    int test;
	  int sum = 0;

    // Read a value from the file and assign it to array value
    for (int i=0; i < size; i++) {
      f_input >> output[i];

      // find min number
      if (output[i] < max) {
        max = output[i];
      }
    }

    for (int i = 0; i < size; i++) {


      for (int n = 0; n < size; n++) {
        if (output[i] != values[n]) {
          values[i] = output[i];
        }
      }


    }

    cout << "Min number: " << max << endl;
    cout << endl;

    cout << "Number" << endl;

    // print all numbers
    for (int i = 0; i < 5; i++) {

      cout << output[i] << endl;
    }





    // Close the input file stream object.
    f_input.close();


    return 0;
}
