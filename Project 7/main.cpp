#include <iostream>
#include "employee.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    
    vector<Employee*> payroll;
    int option;
    string file;
    
    cout << "This program has two options:\n1 - Create a data file";
    cout << "Please enter (1) to create a file or (2) to print ch";
    
    cin >> option;
    
    cout << "\n\nPlease enter a file name: ";
    
    cin >> file;
    
    if (option == 1) {
        payroll.push_back(new HourlyEmployee(1, "H. Potter", "Privet Drive", "201-9090", 40, 12.00));
        payroll.push_back(new SalariedEmployee(2, "A. Dumbledore", "Hogwarts", "803-1230", 1200));
        payroll.push_back(new HourlyEmployee(3, "R. Weasley", "The Burrow", "892-2000", 40, 10.00));
        payroll.push_back(new SalariedEmployee(4, "R. Hagrid", "Hogwarts", "910-8765", 1000));
        
        ofstream output(file);
        try {
            for(size_t i = 0; i < payroll.size(); i++) {
                payroll[i]->write(output);
            }
        }
        catch(runtime_error e) {
            cout << e.what() << endl;
        }
        
    } else {
        ifstream input(file);
        
        payroll.push_back(HourlyEmployee::read(input)); //H.Potter
        payroll.push_back(SalariedEmployee::read(input)); //A. Dumbledore
        payroll.push_back(HourlyEmployee::read(input)); //R. Weasley
        payroll.push_back(SalariedEmployee::read(input)); //R. Hagred
        
        for (size_t i = 0; i < payroll.size(); i++) {
            payroll[i]->printCheck();
        }
    }
}
