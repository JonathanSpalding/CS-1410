#include "employee.h"
#include <string>
//Default Constructor
Employee::Employee(){
    this->name = "";
    this->address = "";
    this->phone = "";
    this->employeeNumber = 0;
    this->hourlyWage = 0;
    this->hoursWorked = 0;
}
//Parameterized Constructor
Employee::Employee(int employeeNumber, double hourlyWage, double hoursWorked, string name, string address, string phone){
    this->name = name;
    this->address = address;
    this->phone = phone;
    this->employeeNumber = employeeNumber;
    this->hourlyWage = hourlyWage;
    this->hoursWorked = hoursWorked;
}

//Destructor
/*Employee::~Employee(){
 }*/
//Getters code
string Employee::getName() const{
    return name;
}
string Employee::getAddress() const{
    return address;
}
string Employee::getPhone() const{
    return phone;
}
int Employee::getEmployeeNumber() const{
    return employeeNumber;
}
double Employee::getHourlyWage() const{
    return hourlyWage;
}
double Employee::getHoursWorked() const{
    return hoursWorked;
}

//Setters code
/*
 void Employee::setName(string name){
 this->name = name;
 }
 void Employee::setAddress(string address){
 this->address = address;
 }
 void Employee::setPhone(string phone){
 this->phone = phone;
 }
 void Employee::setHourlyWage(double hourlyWage){
 this->hourlyWage = hourlyWage;
 }
 void Employee::setHoursWorked(double hoursWorked){
 this->hoursWorked = hoursWorked;
 }*/
//Functions code
double Employee::CalcPay(){
    double federalTax = .2;
    double overtimeHours = 0;
    double overtimeTotal = 0;
    double netIncome = 0;
    int notOvertimeHours = hoursWorked;
    if (hoursWorked > 40) {
        overtimeHours = (hoursWorked - 40);
        notOvertimeHours = 40;
        overtimeTotal = overtimeHours * (hourlyWage * 1.5);
    }
    double grossIncome = notOvertimeHours * hourlyWage + overtimeTotal;
    double stateTax = .075 * grossIncome;
    federalTax = .2 * grossIncome;
    netIncome = grossIncome - stateTax - federalTax;
    return netIncome;
}
double Employee::PrintCheck(){
    return CalcPay();
}







