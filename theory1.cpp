/*Problem Statement: Write C++ program for matrix addition using operator 
overloading*/
#include<iostream>
using namespace std;
class matrix
{
 int a[3][3];
 public:
 void get_data();
 void display_info();
 void operator +(matrix x);
};
void matrix::get_data()
{
 cout<<"\nPlease enter your matrix(of order 3X3):\n";
 for(int i=0; i<3; i++)
 {
 for(int j=0; j<3; j++)
 {
 cout<<"";
 cin>>a[i][j];
 }
 }
}
void matrix::display_info()
{
 for(int i=0; i<3; i++)
 {
 cout<<" ";
 for(int j=0; j<3; j++)
 {
 cout<<a[i][j]<<"\t";
 }
 cout<<"\n";
 }
}
void matrix::operator +(matrix x)
{
 int mat[3][3];
 for(int i=0; i<3; i++)
 {
 for(int j=0; j<3; j++)
 {
 mat[i][j]=a[i][j]+x.a[i][j];
 }
 }
 cout<<"\n Addition of the matrices : \n\n";
 for(int i=0; i<3; i++)
 {
 cout<<" ";
 for(int j=0; j<3; j++)
 {
 cout<<mat[i][j]<<"\t";
 }
 cout<<"\n";
 }
}
int main()
{
 matrix m,n;
 m.get_data(); // Accepting the row elements
 n.get_data(); // Accepting the column elements
 cout<<"\n First Matrix : \n\n";
 m.display_info(); // Displaying the First Matrix
 cout<<"\n Second Matrix : \n\n";
 n.display_info(); // Displaying the Second Matrix
 m+n; // Addition of the Two Matrices. Overloaded '+' Operator
 return 0;
}