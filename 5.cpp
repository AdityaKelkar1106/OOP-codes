/*Name:Aditya Nitin Kelkar Panel:C
Roll no:39 Batch:C3 Date: 22/12/21
OOP Lab Assignment 5
Problem Statement: Write a C++ program with base class Employee and derive classes 
Class1_Employee, Class2_Employee and Class3_Employee. 
Salary of an employee is calculated as per his/her designation. 
Declare calculate salary () as a pure virtual function in base class and define it in respective derive 
classes to calculate salary of an employee.
*/
#include<iostream>
using namespace std;
class Employee
{
protected:
 string name, city, contact;
int id;
 float grossSal, da, ta, pf;
public:
 virtual float calculate_salary() = 0; //Virtual function declared
 void getData();
 void display();
};
void Employee::getData() //accept details
{
 cout<<"\nEnter the name of the employee: ";
 cin>>name;
 cout<<"Enter the ID of the employee: ";
 cin>>id;
 cout<<"Enter the Phone Number of the employee: ";
 cin>>contact;
 cout<<"Enter the city of the employee: ";
 cin>>city;
}
void Employee::display() //display the details
{
 cout<<"Employee Name: "<<name<<endl;
 cout<<" Employee Id: "<<id<<endl;
 cout<<" Employee Mobile Number: "<<contact<<endl;
 cout<<" Employee City: "<<city<<endl;
}
class class1_Employee : public Employee //class defined for employee of class 1
{
 float basic_sal;
 public:
 float calculate_salary() 
 {
 basic_sal = 100000;
 da = 0.97 * basic_sal;
 ta = 0.1 * basic_sal;
 pf = 0.12 * basic_sal;
 grossSal = (basic_sal + da + ta + pf);
 return grossSal;
 }
 void display_gross()
 {
 getData();
 cout<<"\nThe details given are as follows:\n ";
 display();
 cout<<"Gross salary of Manager: "<<calculate_salary()<<endl;
 }
};
class class2_Employee : public Employee //class defined for employee of class 2
{
 float basic_sal;
 public:
 float calculate_salary()
 {
 basic_sal = 80000;
 da = 0.97 * basic_sal;
 ta = 0.1 * basic_sal;
 pf = 0.12 * basic_sal;
 grossSal = (basic_sal + da + ta + pf);
 return grossSal;
 }
 void display_gross()
 {
 getData();
 cout<<"\nThe details given are as follows:\n ";
 display();
 cout<<"Gross salary of Team Lead: "<<calculate_salary()<<endl;
 }
};
class class3_Employee : public Employee //class defined for employee of class 3
{
 float basic_sal;
 public:
 float calculate_salary()
 {
 basic_sal = 60000;
 da = 0.97 * basic_sal;
 ta = 0.1 * basic_sal;
 pf = 0.12 * basic_sal;
 grossSal = (basic_sal + da + ta + pf);
 return grossSal;
 }
 void display_gross()
 {
 getData();
 cout<<"\nThe details given are as follows:\n ";
 display();
 cout<<"Gross salary of Programmer: "<<calculate_salary()<<endl;
 }
};
int main() //main function
{
 Employee *e1;
 cout<<"\n----------Let's demonstrate a pure virtual function!--------------";
 
 cout << "\nManager: " << endl;
 class1_Employee cs1_emp;
 e1 = &cs1_emp;
 cs1_emp.display_gross();
 cout << endl << "Team Lead: " << endl;
 class2_Employee cs2_emp;
 e1 = &cs2_emp;
 cs2_emp.display_gross();
 cout << endl << "Programmer: " << endl;
 class3_Employee cs3_emp;
 e1 = &cs3_emp;
 cs3_emp.display_gross();
 return 0;
}


