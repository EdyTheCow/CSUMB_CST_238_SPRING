/* Title: lab1_2.cpp​
 * Abstract: This program draws a square and a triangle of the length​ size that isgiven by a user
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 20 min
 * Date: 01/24/2020
*/

#include <iostream>
using namespace std;

int main() {

  int length;

  cout << "Enter a length: ";
  cin >> length;

  for (int n = 0; n < length; n++) {

    for (int i = 0; i < length; i++) {
      cout << " *";
    }

    cout << endl;

  }

  cout << endl;

  for (int n = 0; n < length; n++) {

    for (int i = 0; i < n +1; i++) {
      cout << " *";
    }

    cout << endl;

  }

}
