#include "employee.h"
#include <iostream>
#include <istream>
#include <fstream>
using namespace std;
Employee::Employee(int employeeNum, std::string name, std::string address, std::string phoneNumber) {
    this->employeeNumber = employeeNum;
    this->name = name;
    this->address = address;
    this->phoneNumber = phoneNumber;
}
void Employee::readData(ifstream&) {
}
int Employee::getEmployeeNum() const {
    return employeeNumber;
}
string Employee::getName() const {
    return name;
    
}string Employee::getAddress() const {
    return address;
    
}
string Employee::getPhoneNumber() const {
    return phoneNumber;
    
}
void Employee::setName(string name) {
    this->name = name;
    
}void Employee::setAddress(string address) {
    this->address = address;
    
}
void Employee::setPhoneNumber(string phoneNum) {
    this->phoneNumber = phoneNum;
}
void Employee::write(ofstream &){
}
void HourlyEmployee::readData(ifstream& inputStream){}
HourlyEmployee::HourlyEmployee(int employeeNum, string name, string address, string phoneNumber, double hourlyWage, double hoursWorked)
: Employee(employeeNum, name, address, phoneNumber) { //What's going on with this :?
    this->hourlyWage = hourlyWage;
    this->hoursWorked = hoursWorked;
}
//HOURLY EMPLOYEE FUNCTIONS
double HourlyEmployee::getHourlyWage() const {
    return this->hourlyWage;
}
double HourlyEmployee::getHoursWorked() const {
    return this->hoursWorked;
}void HourlyEmployee::setHourlyWage(double wage) {
    this->hourlyWage = wage;
}void HourlyEmployee::setHoursWorked(double hoursWorked) {
    this->hoursWorked = hoursWorked;
}
void HourlyEmployee::write(ofstream& outputStream) {
    //opens file for writing and passes
    if (!outputStream) {
        throw runtime_error("Couldn't open file for input");
    }
    // takes data and writes it to the file
    outputStream << getEmployeeNum() << endl;
    outputStream << getName() << endl;
    outputStream << getAddress() << endl;
    outputStream << getPhoneNumber() << endl;
    outputStream << getHoursWorked() << endl;
    outputStream << getHourlyWage() << endl;
    outputStream.flush();
}
double HourlyEmployee::calcPay() {
    double netPay;
    double fedPay;
    double statePay;
    double finalPay;
    const double FED_TAX = 0.2;
    const double STATE_TAX = 0.075;
    const int OVERTIME = 40;
    double overTimeHours = 0.0;
    double overTimePay = 0;
    double overTimePayRate = 1.5;
    if (hoursWorked >OVERTIME) {
        overTimeHours = hoursWorked - OVERTIME;
        overTimePay = overTimeHours * (overTimePayRate * hourlyWage);
        netPay = (hoursWorked - overTimeHours) * hourlyWage;
    } else {
        netPay = hoursWorked * hourlyWage;
        
    } netPay += overTimePay;
    fedPay = netPay * FED_TAX;statePay = netPay * STATE_TAX;
    finalPay = netPay - fedPay - statePay;
    return finalPay;
}
void HourlyEmployee::printCheck(){}
HourlyEmployee * HourlyEmployee::read(ifstream& inputStream) {
    // takes data from a file
    string input;
    if (!inputStream){
        throw runtime_error("Couldn't open file for input");
        
    }
    // inputs that data to the class
    HourlyEmployee* Emp = new HourlyEmployee();
    getline(inputStream, input);
    Emp->employeeNumber = stoi(input);
    getline(inputStream, input);
    Emp->setName(input);
    getline(inputStream, input);
    Emp->setAddress(input);
    getline(inputStream, input);
    Emp->setPhoneNumber(input);
    getline(inputStream, input);
    Emp->setHourlyWage(stod(input));
    getline(inputStream, input);
    Emp->setHoursWorked(stod(input));
    return Emp;
}


void SalariedEmployee::readData(ifstream&){} // changed to pass by reference to fix this.
SalariedEmployee::SalariedEmployee(int employeeNum, string name, string address, string phoneNumber, double salary)
: Employee(employeeNum, name, address, phoneNumber) {
    this->salary = salary;
}
double SalariedEmployee::getSalary() const {
    return salary;
}
void SalariedEmployee::setSalary(double salary) {
    this->salary = salary;
}
void SalariedEmployee::write(ofstream& output){}
double SalariedEmployee::calcPay() {
    return salary / 26;
}
void SalariedEmployee::printCheck() {}
SalariedEmployee * SalariedEmployee::read(ifstream& input) {
    return nullptr;
}
//void Employee::readData(ifstream in)
//{
//
// declare a string to temporarily store an input line
//    string inputLine;
//
//
// Read common Employee data
//    getline(in, inputLine);
//    employeeNumber = stoi(inputLine);
//    getline(in, name);//    getline(in, address);
//    getline(in, phoneNumber);
//}
