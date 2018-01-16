#include <iostream>
using namespace std;

int main () {
  
  // set output format to show 2  decimals
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  // stating all variables
  double taxableIncome = -1.0;
  double subtractTax = 0.0;
  double taxRate = 0.0;
  double addTax = 0.0;
  double taxTotal = 0.0;
  string marriageStatus = "";
  string repeatCalculation = "y";
  
  //while loop to allow repeat if they would like to make more calculations
  while (repeatCalculation == "y") {
    // Asking to enter taxable income values and stores it in taxableIncome
    while (taxableIncome < 0) {
    cout << "Please enter in your taxable income." << endl;
    cout << "(This must be a positive value): ";
    cin >> taxableIncome;
    cout << endl << endl;
    }
    
    // asking to enter marriage status and stores it in marriageStatus.
    cout << "Please enter m if married and filing joint return," << endl;
    cout << "or s if filing a single return:";
    cin >> marriageStatus;
    cout << endl << endl;
    
    //while loop to repeat if they enter something other than m or s.
    while (marriageStatus != "m" && marriageStatus != "s") {
      cout << "Please enter a valid Marriage Status, m or s: ";
      cin >> marriageStatus;
      cout << endl;
    }
    
    // if else statement to determine if they're married or not.
    if (marriageStatus == "s") {
      marriageStatus = "single return"; //allows the string to say single return if they're single.
      if (taxableIncome <= 863) {
        taxRate =     0.023;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else if (taxableIncome <= 2588) {
        subtractTax = 863.0;
        taxRate =     0.033;
        addTax =      25.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else if (taxableIncome <= 4313) {
        subtractTax = 2588.0;
        taxRate =     0.052;
        addTax =      25.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else {
        subtractTax = 4313.0;
        taxRate =     0.075;
        addTax =      181.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      }
    } else {
      marriageStatus = "joint return"; //allows the string to say joint return if they're married.
      if (taxableIncome <= 1726) {
        taxRate =     0.023;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else if (taxableIncome <= 5176) {
        subtractTax = 1726.0;
        taxRate =     0.033;
        addTax =      40.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else if (taxableIncome <= 8626) {
        subtractTax = 5176.0;
        taxRate =     0.052;
        addTax =      175.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      } else {
        subtractTax = 8626.0;
        taxRate =     0.075;
        addTax =      390.0;
        taxTotal = (taxableIncome - subtractTax) * taxRate + addTax;
      }
    }
    
    // output the results
    cout << "Your taxable income is $" << taxableIncome << endl;
    cout << "and you are filing a " << marriageStatus << "."<< endl;
    cout << "Your income tax will be $" << taxTotal << endl << endl;
    
    // ask if they want to make another calculation, and repeat if they do.
    cout << "Would you like to do another calculation (y or n)?";
    cin >> repeatCalculation;
    cout << endl;
    if (repeatCalculation == "y") {
      taxableIncome = -1;
    }
  }  
}