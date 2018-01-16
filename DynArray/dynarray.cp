#include "dynarray.h"
#include <stdexcept>

//this doubles the capacity of our Dynamic Memory Array by creating a new pointer, allocating it to _capacity*2, copy over myArray to NewArray, Delete old array, setmyArray = newArray.
void DynArray::DoubleArray() {
  
  _capacity *= 2;
  
  int* newArray = new int[_capacity];
  
  for (int i = 0; i < _size; i++) {
    newArray[i] = myArray[i];
  }
  delete[] myArray;
  
  myArray = newArray;
  
  //delete[] newArray;
}

DynArray::DynArray() { //Should this be outside of DynArray::DynArray()?
  _capacity = 2;
  _size = 0;
  myArray = new int[this->_capacity];
}

DynArray::DynArray(int n) {
  _capacity = n;
  _size = 0;
  myArray = new int[this->_capacity];
}

DynArray::~DynArray() {
  delete[] myArray;
  myArray = nullptr; //optional
}

int DynArray::size() {
  return _size;
}

int DynArray::capacity() {
  return _capacity;
}

void DynArray::clear() {
  _size = 0;
  //_capacity = 2;
  delete[] myArray;
  myArray = new int[this->_capacity];
}

void DynArray::push_back(int n) {
  if (_size == _capacity) {
    DoubleArray();
  }
  myArray[_size++] = n;
  //_size++;
}

void DynArray::pop_back() {
  if (_size > 0) {
    _size--;
  }
}
  
int DynArray::at(int n) {
  if(n >= _size || n < 0) {
    throw runtime_error("invalid index");
  }
  
  return myArray[n];
}















