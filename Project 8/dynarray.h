#include <iostream>
using namespace std;

template<typename T>
class DynArray
{
private:
    int _size;
    int _capacity;
    T* myArray;
    
    void DoubleArray();
    
public:
    DynArray();
    DynArray(int n);
    ~DynArray();
    int size() const;
    int capacity() const;
    void clear();
    void push_back(int n);
    void pop_back();
    int at(int n);
    
    DynArray(const DynArray<T>&d);
    DynArray<T>& operator=(const DynArray<T>&d);
    T& front();//will give us the start of the array
    T& back();//will give us the end of the array
    T& operator[](int n);//overload array brackets 
};


// Double the capacity of the dynamic memory array by
// Creating a new pointer, allocating it to _capacity*2
// Copy over myArray to newArray.
// Delete myArray
// Set myArray = newArray

template<typename T>
void DynArray<T>::DoubleArray()
{
    cout<<"grow\n";
    
    _capacity *= 2;
    
    T* newArray = new T[_capacity];
    
    for (int i = 0; i < _size; i++)
    {
        newArray[i] = myArray[i];
    }
    delete[] myArray;
    
    myArray = newArray;
}

template<typename T>
DynArray<T>::DynArray()
{
    _size = 0;
    _capacity = 2;
    myArray = new T[_capacity];
}

template<typename T>
DynArray<T>::DynArray(int n)
{
    _size = 0;
    _capacity = n;
    myArray = new T[_capacity];
}

template<typename T>
DynArray<T>::~DynArray()
{
    delete[] myArray;
    myArray = nullptr;
}

template<typename T>
int DynArray<T>::size() const
{
    return _size;
}

template<typename T>
int DynArray<T>::capacity() const
{
    return _capacity;
}

template<typename T>
void DynArray<T>::clear()
{
    _size = 0;
    _capacity = 2;
    delete[] myArray;
    myArray = new T[_capacity];
}

template<typename T>
void DynArray<T>::push_back(int n)
{
    if (_size == _capacity)
    {
        DoubleArray();
    }
    myArray[_size++] = n;
}

template<typename T>
void DynArray<T>::pop_back()
{
    if (_size > 0)
    {
        _size--;
    }
}

template<typename T>
int DynArray<T>::at(int n)
{
    if (n >= _size)
    {
        throw runtime_error("invalid index");
    }
    return myArray[n];
}

//~~~~~~~new stuff
template<typename T>
DynArray<T>::DynArray(const DynArray<T>& d)
{
    cout<<"copy\n";
    
    myArray = new T[d.capacity()];
    _size = d.size();
    _capacity = d.capacity();
    
    for(int i = 0; i < d.size(); i++)
    {
        myArray[i] = d.myArray[i];
    }
}


template<typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray<T>& d)
{
    cout << "assign\n";
    
    if(this != &d)
    {
        delete [] myArray;
        myArray= new T[d.capacity()];
        _capacity = d.capacity();
        _size = d.size();
        
        for (int i = 0; i < d.size(); i++)
        {
            myArray[i] = d.myArray[i];
        }
        return *this;
    }
}

//front
template<typename T>
T & DynArray<T>::front()
{
    if(_size <= 0)
        throw runtime_error("No front in empty DynArray");
    return myArray[0];
}

template<typename T>
T & DynArray<T>::back()
{
    if(_size <= 0)
        throw runtime_error("No back in the empty DynArray");
    return myArray[_size - 1];
}

template<typename T>
T & DynArray<T>::operator[](int n)
{
    if(n < 0 || n >= _size)
    {
        throw runtime_error("Invalid index in operator[]");
        return myArray[n];
    }
}
