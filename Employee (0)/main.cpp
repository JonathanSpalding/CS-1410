#include <iostream>
#include "employee.h"
using namespace std;
int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    //Create employee1 using the defualt constructor
    Employee employee1(37, 10.00, 45.00, "Joe Brown", "123 Main St.", "123-6788");
    //Create employee2 using the parameterized constructor
    Employee employee2(37, 12.50, 30.00, "Sam Jones", "45 East State", "661-9000");
    
    
    cout << "Employee Name: " << employee1.getName() << endl;
    cout << "Employee Number: " << employee1.getEmployeeNumber() << endl;
    cout << "Address: " << employee1.getAddress() << endl;
    cout << "Phone: " << employee1.getPhone() << endl;
    
    cout << endl << endl << endl << "....................UVU Computer Science Dept................................." << endl << endl << endl;
    cout << "Pay to the order of "<< employee1.getName() << "....................................$";
    cout << employee1.PrintCheck() << endl;
    cout << endl << endl << "United Community Credit Union" << endl;
    cout << ".............................................................................." << endl << endl;
    cout << "Hours worked: " << employee1.getHoursWorked() << endl;
    cout << "Hourly wage: " << employee1.getHourlyWage() << endl;
    cout << endl << endl << endl << endl << endl;
    
    cout << "Employee Name: " << employee2.getName() << endl;
    cout << "Employee Number: " << employee2.getEmployeeNumber() << endl;
    cout << "Address: " << employee2.getAddress() << endl;
    cout << "Phone: " << employee2.getPhone() << endl;
    
    cout << endl << endl << endl << "....................UVU Computer Science Dept................................." << endl << endl << endl;
    cout << "Pay to the order of "<< employee2.getName() << "....................................$";
    cout << employee2.PrintCheck() << endl;
    cout << endl << endl << "United Community Credit Union" << endl;
    cout << ".............................................................................." << endl << endl;
    cout << "Hours worked: " << employee2.getHoursWorked() << endl;
    cout << "Hourly wage: " << employee2.getHourlyWage() << endl;
    
}
