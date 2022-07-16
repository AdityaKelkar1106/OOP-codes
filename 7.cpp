/* Name: Aditya Nitin Kelkar  Panel: C   Roll no: 39     Batch: C3
OOP Lab Assignment 7
Problem Satement: Perform bubble sort operation using the template for integer and float data type*/
#include <iostream>
using namespace std;
template<typename K>
class bubblesort
{
 private:
 K array[50], temp;
 int n;
 
 public:
 void input()
 {
  cout <<"Enter size of the array: \n";
  cin >>n;
  cout <<"Enter elements in the array:\t "<<endl;
  for(int i=0;i<n;i++)
  {
   cin >> array[i];
  }
 }
 void bubble_sort()
 {
  for(int i=0;i<n;i++)
  {
   for(int j=0; j<(n-i-1); j++)
   {
    if(array[j]>array[j+1])
    {
     temp = array[j];
     array[j] = array[j + 1];
     array[j + 1] = temp;
    }
   }
  }
 }
 void display()
 {
  cout <<"Array after sorting: "<< endl;
  for (int i = 0; i < n; i++)
  {
   cout <<" "<<array[i]<<" ";
  }
 }
};
int main()
{
  cout<<"Enter integer values! \n";
  bubblesort <int>b1;
  b1.input();
  b1.bubble_sort();
  b1.display();
 
  cout<<"\nEnter float values! \n";
  bubblesort <float>b2;
  b2.input();
  b2.bubble_sort();
  b2.display();
  return 0;
}