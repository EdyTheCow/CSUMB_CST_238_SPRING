
/* Title: lab1_1.cpp​
 * Abstract: This program displays a max number out of 4 entered
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 5 min
 * Date: 01/24/2020
*/

#include <iostream>
using namespace std;

int main() {

  int num1, num2, num3, num4, max;

  cout << "Enter 4 numbers ";
  cin >> num1;
  cin >> num2;
  cin >> num3;
  cin >> num4;

  max = num1;

  if (max < num2) {
    max = num2;
  }

  if (max < num3) {
    max = num3;
  }

  if (max < num4) {
    max = num4;
  }

  cout << "Max is: " << max;

}
