/* Title: hw2-2.cpp​
 * Abstract: This program reads from a file with quiz score data to calculate and display avarage
 * Author: Edgaras Slezas
 * Email: eslezas@csumb.edu
 * Estimate: 5h
 * Date: 01/30/2020
*/

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {

  // Student structure
  struct Student {
    string name;
    int id;
    int ignore;
    double avg;
    double quiz[5] = {0, 0, 0, 0, 0};
  };

  // Read from file
  cout << "Enter input file name: ";
  string file_name;
  cin >> file_name;
  ifstream f_input(file_name);
  if (f_input.fail()) {
    cout << "Error: Input file open failed.\n";
    return 0;
  }

  Student studentRecords[30];

  // insert data from file to structure
  int size = 0;
  for (int i = 0; i < 30; i++) {

    f_input >> studentRecords[i].name;
    f_input >> studentRecords[i].id;

    for (int j = 0; j < 5; j++) {
      f_input >> studentRecords[i].quiz[j];
    }

    if (studentRecords[i].name == "STOP") {
      size = i;
      break;
    }


  }

  // Add quiz data into strucutre and find quiz min and add it to ignore
  for (int i = 0; i < size; i++) {
    int index = 0;
    int min = studentRecords[i].quiz[0];

    for (int j = 1; j < 5; j++) {
      if (min > studentRecords[i].quiz[j]) {
        min = studentRecords[i].quiz[j];
        index = j;
      }
    }
    studentRecords[i].ignore = index;
  }


  // Calculate quiz average
  for (int i = 0; i < size; i++) {

    for (int j = 0; j < 5; j++) {

      if (j != studentRecords[i].ignore) {
        studentRecords[i].avg += studentRecords[i].quiz[j];

      }

    }

  }


  cout << "--------------------------------------------------" << endl;
  cout << "  Course Report: Quiz Average" << endl;
  cout << "--------------------------------------------------";

  // print out the quiz data
  for (int i = 0; i < size; i++) {


    cout << endl;

    if (studentRecords[i].name == "STOP") {
      break;
    }

    cout << "  " << studentRecords[i].name << " (" << studentRecords[i].id << "): " << studentRecords[i].avg / 4;

  }

  cout << "\n--------------------------------------------------" << endl;
  // close the file
  f_input.close();

}
