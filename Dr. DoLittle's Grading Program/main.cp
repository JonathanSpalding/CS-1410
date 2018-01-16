#include <iostream>
#include <vector>
using namespace std;
// Function that checks for valid input.
int GetUserInput(const string& s) {
  // create a value so that the while loop starts
  int val;
  while (true) {
    // output the entered string parameter
    cout << s;
    // get user input
    cin >> val;
    // output a space
    cout << endl;
    // if end of file, returns -1. This returns break; later in main.
   if (cin.eof()) {
      return -1;
      // if not a number, ask user to enter an integer.
    } else if (!cin) {
      cout << "\nSorry, your input must be an integer. Please try again.";
      cin.clear();
      cin.ignore(80, '\n');
      // checks to see if the number is between 0 and 100.
    } else if (val < 0 || val > 100) {
      cout << "\nSorry, your input must be between 0 and " << 100 << " Please try again.";
    }
    else
      break;
  }
  // if valid, returns user input.
  return val;
}

int main() {
  // states all variables.
  string finalGrade = "";
  int median = 0;
  vector<int> homeworkScores;
  int totalScore = 0;
  int i=0;
  // program title
  cout << "\nDr. DoLittle's Grading Program .....\n";
  // asks for scores of all three exams. (These call back to GetUserInput before main())
  int firstExam = GetUserInput("\nPlease enter in the score for the first Exam: ");
  int secondExam = GetUserInput("\nPlease enter in the score for the second Exam: ");
  int thirdExam = GetUserInput("\nPlease enter in the score for the final Exam: ");
  // asks user for all homework scores.
  while (true) {
    int score = GetUserInput("\nEnter the score for a homework assignment (signal EOF when done): ");
    // when End of File, GetUserInput returns -1, and then this returns break; ending the program.
    if(score == -1) {
      break;
    } else {
      // pushes all scores into a vector.
      homeworkScores.push_back(score);
    }
  }
  // median returns the median (This is hard coded just a little)
  median = (homeworkScores.at(2) + homeworkScores.at(3)) / 2;
  // total score is the median, plus all exams.
  totalScore = median + firstExam + secondExam + thirdExam;
  // if/else statement sets the finalGrade to the appropriate letter grade.
  if (totalScore >= 381) {
    finalGrade = "A";
  } else if (totalScore >= 361){
    finalGrade = "A-";
  } else if (totalScore >= 341){
    finalGrade = "B+";
  } else if (totalScore >= 321){
    finalGrade = "B";
  } else if (totalScore >= 301){
    finalGrade = "B-";
  } else if (totalScore >= 281){
    finalGrade = "C+";
  } else if (totalScore >= 261){
    finalGrade = "C";
  } else if (totalScore >= 241){
    finalGrade = "C-";
  } else if (totalScore >= 221){
    finalGrade = "D+";
  } else if (totalScore >= 201){
    finalGrade = "D";
  } else if (totalScore >= 181){
    finalGrade = "D-";
  } else {
    finalGrade = "fail";
  }
  // outputs the median, total points, and the letter grade.
  cout << endl;
  cout << "The median homework score was " << median << endl;
  cout << "The total points earned was " << totalScore << endl;
  cout << "The letter calculated letter grade is " << finalGrade << endl;
  return 0;
}