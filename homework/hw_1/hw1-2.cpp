/* Title: hw1-2.cpp​
 * Abstract: This program reads data from file and draw a horizontal histogram for the numbers
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 1h
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

	// Read the first number in the file.
    f_input >> size;

    int value[5];

    // Read values from the file.
    for (int i=0; i < size; i++) {
		// Read a value from the file and assign it to a variable "value".
    f_input >> value[i];

    }


    cout << endl;
    cout << "===== Horizontal Histogram =====" << endl;

    for (int n = 0; n < size; n++) {
      cout << value[n] << ": ";

      for (int i = 0; i < value[n]; i++) {
        cout << " *";
      }

      cout << endl;
    }


    // Close the input file stream object.
    f_input.close();


    return 0;
}
