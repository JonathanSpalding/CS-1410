#pragma once

using namespace std;

class DynArray
{
private:
  int _size;
  int _capacity;
  int* myArray;
  
  void DoubleArray();
  
  
public:
  DynArray();
  DynArray(int n);
  ~DynArray();
  int size();
  int capacity();
  void clear();
  void push_back(int n);
  void pop_back();
  int at(int n);
  
  
};




