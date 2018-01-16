#include "Rectangle.h"
//In The .cpp file, make sure to #include the .h file
#include <iostream>
//Default Constructer
Rectangle::Rectangle(){
    this->length = 1;
    //Set defualt values for
    this->width = 1;
    
}
//Parameterized Constructor
Rectangle::Rectangle(int length, int width){
    this->length = length;this->width = width;
}
//Destructor.  Dont' worry about this for now
Rectangle::~Rectangle(){
}
//CODE FOR GETTERS
int Rectangle::getLength() const{
    return length;
    
}int Rectangle::getWidth() const{
    return this->width;
    //You can use this-> if you want to.
}
string Rectangle::getName(){
    return length == width ? "Square" : "Rectangle";
    
}
//CODE FOR SETTIERS
void Rectangle::setLength(int length){
    this->length = length;
    //This is needed here to distinguish which length you are talking about
}
void Rectangle::setWidth(int width){
    this->width = width;
}
//Functions.
int Rectangle::CalcArea()
{
    return width * length;
}int Rectangle::CalcPerimeter(){
    return (width * 2) + (length * 2);
    
}
//Static Function code
int Rectangle::CalcArea(int length, int width){
    return length * width;
}
Rectangle Rectangle::read(ifstream & inputStream){
    Rectangle r;
    string input;
    if (!getline(inputStream, input))throw runtime_error("error reading length");
    r.setLength(stoi(input));
    if (!getline(inputStream, input))throw runtime_error("error reading width");
    r.setWidth(stoi(input));
    return r;
}
void Rectangle::write(ofstream & outputStream){
    outputStream << length << '\n';
    outputStream << width << '\n';
}














