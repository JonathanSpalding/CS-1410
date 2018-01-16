#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

class Employee
{
private:
    
    string name;
    string address;
    string phoneNumber;
    
protected:
    int employeeNumber;
    Employee() = default;
    Employee(int, string, string, string);
    virtual ~Employee() = default;
    virtual void readData(ifstream&)= 0;
    
public:
    int HourlyEmployee() const;
    int getEmployeeNum()const;
    string getName()const;
    string getAddress()const;
    string getPhoneNumber()const;
    
    void setName(string name);
    void setAddress(string address);
    void setPhoneNumber(string phoneNum);
    
    virtual double calcPay() = 0;
    virtual void printCheck() = 0;
    virtual void write(ofstream&) = 0;
};

class HourlyEmployee : public Employee
{
    
private:
    double hourlyWage;
    double hoursWorked;
    
protected:
    HourlyEmployee() = default;
    void readData(ifstream&) override;
    
public:
    HourlyEmployee(int employeeNum, string name, string address, string phoneNumber, double hourlyWage, double hoursWorked);
    double getHourlyWage()const;
    double getHoursWorked()const;
    void setHourlyWage(double wage);
    void setHoursWorked(double hoursWorked);
    
    void write(ofstream&) override;
    double calcPay() override;
    void printCheck() override;
    static HourlyEmployee* read(ifstream&);
};

class SalariedEmployee : public Employee
{
private:
    double salary;
    
protected:
    SalariedEmployee() = default;
    void readData(ifstream&) override;
    
public:
    SalariedEmployee(int employeeNum, string name, string address, string phoneNumber, double salary);
    double getSalary() const;
    void setSalary(double);
    
    void write(ofstream&) override;
    double calcPay() override;
    void printCheck() override;
    
    //static void read(ifstream&);
    
    static SalariedEmployee* read(ifstream&);
};