#pragma once
#include<string>
#include<fstream>
using namespace std;
//Class Declaration
class Rectangle{
    //Private Class Members
private:
    int length;
    int width;
    //Public Class Members
public:Rectangle(); //Default Constructor
    Rectangle(int length, int width); //Parameterized Constructor
    ~Rectangle(); //Destructor (We will worry about this later)
    //Getters
    int getLength() const;
    int getWidth() const;
    string getName();
    //Note that you can have getters that aren't tied to a private member variable!
    //Setters
    void setLength(int length);
    void setWidth(int width);
    //Functions
    int CalcArea();
    int CalcPerimeter();
    //Static Function
    static int CalcArea(int length, int width);
    static Rectangle read(ifstream&);
    void write(ofstream&);
};
