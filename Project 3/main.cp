#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

// Enter your 4 functions here
/*void swap(int& i, int& j) {
    int t = i;
    i = j;
    j = t;
}*/

void sortHelper(int arr[], int first, int last)
{
  //Base case
  if(first < last) {   
    //find min value in arr
    int minIdx = first;
    
   for(int i = first; i < last; i++) {
      if(arr[i] < arr[minIdx]) {
        minIdx = i;
      }
    }
    swap(arr[first], arr[minIdx]);
    sortHelper(arr, first + 1, last);
  }
}

void mysort(int arr[], int size) {
   sortHelper(arr, 0 , size);
}
  
void HiLoHelper(int start, int stop) {
  if (start == stop) {
    cout << "Your number is " << start << endl << endl;
  } else if (start > stop) {
    cout << "You cheated." << endl;
  } else {
    int guess = (start + stop) / 2;
    cout << "Is it " << guess << " (l,y,h)?" << endl;
    char c;
    cin >> c;
    if (c == 'y') {
      return HiLoHelper(guess, guess);
    } else if (c == 'l') {
      return HiLoHelper(guess + 1, stop);
    } else {
      return HiLoHelper(start, guess - 1);
    }
  }
}
void hilo(int n) {
   HiLoHelper(1, n);
}


int main() {
  cout << "Think of a number between 1 and 100 " << endl << "I will try and guess it with your help." << endl << endl;
  
    // Guess a number between 1 and 100
    // Your hilo() will call a slightly modified GuessNumber
    hilo(100);

    // Sort an array
    // Your mysort() will call a recursive helper function.
    int a[] = {5,4,3,2,1};
    const int n = 5;
    mysort(a,n);
    cout << "Sorted result:\n";
    for (int n: a)
        cout << n << endl;
    cout << endl;
}
