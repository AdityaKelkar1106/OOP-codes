/*Name: Aditya Nitin Kelkar   Panel:C
Roll no:39     Batch:C3
OOP Lab Assignment 4 
Problem Statement: Define a class Box consisting of the following: Data members: length, breadth, height Member Functions: One default constructor Two overloaded operator member functions “<<” and “>>” to display and read Box dimensions. 
One-member function “+” to add the two box objects. One friend function to compute the volume of this box using operator overloading.*/
#include<iostream>
using namespace std;
class box
{
 double length,breadth,height;
 public:
  box()
  {
   length=0.0;breadth=0.0;height=0.0;
  }
 friend ostream & operator << (ostream &out, box &b);
 friend istream & operator >> (istream &in, box &b);

 box operator +(box b2)
 {
  box b1;      //create box b1 to hold the info
  b1.length=length + b2.length;
  b1.breadth=breadth + b2.breadth;
  b1.height=height + b2.height;
  return(b1);
 }

 friend double volume(box b4)
 {
  return b4.length*b4.breadth*b4.height;
 }
};

istream &operator >> (istream &in, box &b)
{
 in>>b.length;
 in>>b.breadth;
 in>>b.height;
 return in;
}

ostream &operator << (ostream &out, box &b)
{
 out<<"Length:"<<b.length<<endl;
 out<<"Breadth:"<<b.breadth<<endl;
 out<<"Height:"<<b.height<<endl;
 return out;
}

int main()
{
 box b1,b2,b3;
 cout<<"Enter the length, breadth, height of box1:"<<endl;
 cin>>b1;
 cout<<b1<<endl;
 cout<<"Enter the length, breadth, height of box2:"<<endl;
 cin>>b2;
 cout<<b2<<endl;
 cout<<"Addition of box1 and box2 is:"<<endl;
 b3=b1+b2;
 cout<<b3<<endl;
 cout<<"Volume of box1:"<<volume(b1)<<endl;
 cout<<"Volume of box2:"<<volume(b2)<<endl;
 cout<<"Volume of box3:"<<volume(b3)<<endl;

}


