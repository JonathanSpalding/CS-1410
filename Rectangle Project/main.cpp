#include <iostream>
#include "Rectangle.h"
#include <vector>
using namespace std;
int main(){
    //Create rect1 using the defualt constructor
    Rectangle rect1;
    //Create rect2 using the parameterized constructor
    Rectangle rect2(7, 4);
    //Here we call a getter, and we are also calling a function
    cout << "Area of the " << rect1.getName() << " is " << rect1.CalcArea() << endl;
    cout << "Area of the " << rect2.getName() << " is " << rect2.CalcArea() << endl;
    //Here we are calling our setters to set the length and width
    rect1.setLength(8);
    rect1.setWidth(8);
    //When you call it this time, .getName() returns "rectangle"!
    cout << "Area of the " << rect1.getName() << " is " << rect1.CalcArea() << endl;
    //Call Static Function to getArea without using an object
    int area = Rectangle::CalcArea(3, 5);
    cout << "the area is " << area << endl;
    //Call Static Function to CalcArea with object
    cout << "the area is " << rect1.CalcArea(2, 5) << endl;
    //Create an outputStream
    ofstream outputStream("employee.dat");
    if (!outputStream){
        cout << "Could not open file";
    }
    rect1.write(outputStream);
    rect2.write(outputStream);
    //outputStream.close();
    outputStream.flush();
    ifstream inputStream("rectangle.txt");
    //rect1.write(outputStream);
    //inputStream is open.  Can we write?
    //outputStream.flush();
    if (inputStream.fail()){
        cout << "Could not open file for input" << endl;
        
    }
    vector<Rectangle> MyRectangles;
    try{
        MyRectangles.push_back(Rectangle::read(inputStream));
        MyRectangles.push_back(Rectangle::read(inputStream));
        
    }
    catch(runtime_error err){
        cout << "runtime_error exception thrown: " << err.what() << endl;
        
    }
    for (int  i = 0; i < MyRectangles.size(); i++)
    {
        cout << "Area of the " << MyRectangles[i].getName() << " is " << MyRectangles[i].CalcArea() << endl;
        
    }
}













