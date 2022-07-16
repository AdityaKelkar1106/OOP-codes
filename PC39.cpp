/* Name: Aditya Nitin Kelkar
   Roll no: 39
   Batch: C3
   *****OOP Practical exam******
   Problem Statement: A company pays its employees on a weekly basis.The employees are of three types: teaching employees,non teaching employees,
   and housekeeping employees. Consider the appropriate formula to calculate the salary of each type of employee. Use late binding functionality
   to implement an OOP application.
   Date: 12/02/22
*/   
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
class employee  //base class
{
   public:
   int id,overtime,leaves;
   char name[20];
   virtual void get_data()              //virtual function declared
   {
       cout<<"This is a parent class";
   }
   virtual int salary(int basic_pay)  //virtual function declared
   {
       cout<<"This is a parent class";
       return 0;
   }
};

class designation:public employee //derived class
{
  public:
  void get_data()   //accept the details from the user 
  {
      cout<<"\nEnter the ID(non-negative): ";
      cin>>id;
      if(id<0)
      {
          cout<<"Id cannot be negative! Try again!";
          throw "Error!";
      }
      cout<<"Enter the name: ";
      cin>>name;
      cout<<"Enter the overtime working hours(should not be more than 12): ";
      cin>>overtime;
      if(overtime>12)
      {
        cout<<"According to our company policy, employees are not allowed to work more than 12 hours overtime!";
        throw "Error!";
      }
      cout<<"Enter the no of leaves: ";
      cin>>leaves;
  }
  int salary(int basic_pay)    //function for calculating basic pay, basic pay will be different for each type of employee,formula for calculating the salary
  {
      int final_salary;
      final_salary=basic_pay +(overtime*(basic_pay/240))-(leaves*(basic_pay/30));
      return final_salary;
  }
   
};

int main() //driver code
{
    int type,x=1;
    employee *emp; //pointer to the base class
    designation d;
    do
    {
        cout<<"\n-------Calculating income on a weekly basis-------";
        cout<<"\n1.Teacher";
        cout<<"\n2.Office staff";
        cout<<"\n3.Housekeeping employee";
        cout<<"\nPlease enter your choice: ";
        cin>>type;
        emp=&d;
        emp->get_data();//virtual function binded at runtime
        switch(type)
        {
           case 1:
           cout<<"\n\n(Teacher)Good evening, dear Sir/Madam! Your monthly salary is "<<"Rs"<<emp->salary(80000);//virtual function binded at runtime
           break;
           
           case 2:
           cout<<"\n\n(Office staff)Good evening, dear Sir/Madam! Your monthly salary is "<<"Rs"<<emp->salary(60000);//virtual function binded at runtime
           break;
           
           case 3:
           cout<<"\n\n(Housekeeping employee)Good evening,dear Sir/Madam! Your monthly salary is "<<"Rs"<<emp->salary(15000);//virtual function binded at runtime
           break;
        }
      cout<<"\n\nDo you want to continue?(1/0): ";
      cin>>x;   
    }while(x!=0);
  return 0;
}


/* *******************Test case 1:***************************
   -------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 1

Enter the ID(non-negative): 12
Enter the name: Aditya
Enter the overtime working hours(should not be more than 12): 4
Enter the no of leaves: 2


(Teacher)Good evening, dear Sir/Madam! Your monthly salary is Rs76000

Do you want to continue?(1/0): 1

-------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 2

Enter the ID(non-negative): 12
Enter the name: Aryan
Enter the overtime working hours(should not be more than 12): 6
Enter the no of leaves: 2


(Office staff)Good evening, dear Sir/Madam! Your monthly salary is Rs57500

Do you want to continue?(1/0): 1

-------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 3

Enter the ID(non-negative): 12
Enter the name: Arvan
Enter the overtime working hours(should not be more than 12): 6
Enter the no of leaves: 2


(Housekeeping employee)Good evening,dear Sir/Madam! Your monthly salary is Rs14372

Do you want to continue?(1/0): 0
PS D:\MIT Academics\SY\Trimester 5\OOP with C++\OOP codes C++>
  
*********************Test case 2***************************
-------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 1

Enter the ID(non-negative): 12
Enter the name: Aditya
Enter the overtime working hours(should not be more than 12): 1
Enter the no of leaves: 1


(Teacher)Good evening, dear Sir/Madam! Your monthly salary is Rs77667

Do you want to continue?(1/0): 1

-------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 2

Enter the ID(non-negative): 12
Enter the name: Aryan
Enter the overtime working hours(should not be more than 12): 1 
Enter the no of leaves: 1


(Office staff)Good evening, dear Sir/Madam! Your monthly salary is Rs58250

Do you want to continue?(1/0): 1

-------Calculating income on a weekly basis-------
1.Teacher
2.Office staff
3.Housekeeping employee
Please enter your choice: 3

Enter the ID(non-negative): 12
Enter the name: Arvan
Enter the overtime working hours(should not be more than 12): 1
Enter the no of leaves: 1


(Housekeeping employee)Good evening,dear Sir/Madam! Your monthly salary is Rs14562

Do you want to continue?(1/0): 0
PS D:\MIT Academics\SY\Trimester 5\OOP with C++\OOP codes C++> 
*/















