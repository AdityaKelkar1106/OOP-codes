/*Name:Aditya Nitin Kelkar  Panel:C
Roll no:39     Batch:C3
OOP Lab Assignment 3
Problem Statement:Employee class has Emp_name, Emp_id, Address, Mail_id, and Mobile_no as members.Inherit the classes: Programmer, Team Lead, Assistant Project Manager and Project Manager from employee class. 
Add Basic Pay as the member of all the inherited classes with 97% of Basic Pay as DA, 10 % of Basic Pay as HRA, 12% of Basic Pay as PF, 0.1% of Basic Pay for staff club fund. 
Generate pay slips for the employees with their gross and net salary.*/
#include<iostream>
using namespace std;
class Employee
{
 protected:
  string Emp_name;
  int Emp_ID;
  string address;
  string Mail_ID;
  long int Mob_no;
  float basic_salary;
  float DA;
  float HRA;
  float PF;
  float CF;
  float total_salary;
 public:
  void getdata()
  {
    cout<<"\nEnter employee name: ";
    cin>>Emp_name;
    cout<<"Enter employee ID: ";
    cin>>Emp_ID;
    cout<<"Enter the address:";
    cin>>address;
    cout<<"Enter mail ID:";
    cin>>Mail_ID;
    cout<<"Enter mobile number:";
    cin>>Mob_no;
   }
  void showdata()
  {
   cout<<"\t"<<Emp_name;
   cout<<"\t"<<Emp_ID;
   cout<<"\t"<<address;
   cout<<"\t"<<Mail_ID;
   cout<<"\t"<<Mob_no;
  }
  void show_salary()
  {
   cout<<" "<<total_salary<<endl;
  }
};
class Programmer:public Employee
{
public:
  Programmer()
  {
   basic_salary = 40000;
   DA = 0.97*basic_salary;
   HRA = 0.10*basic_salary;
   PF = 0.12*basic_salary;
   CF = 0.01*basic_salary;
   total_salary = basic_salary + DA + HRA + PF + CF;
  }
};
class TeamLeader:public Employee
{
public:
  TeamLeader()
  {
   basic_salary = 60000;
   DA = 0.97*basic_salary;
   HRA = 0.10*basic_salary;
   PF = 0.12*basic_salary;
   CF = 0.01*basic_salary;
   total_salary = basic_salary + DA + HRA + PF + CF;
  }
};
class Assistant_PM:public Employee
{
public:
  Assistant_PM()
  {
   basic_salary = 80000;
   DA = 0.97*basic_salary;
   HRA = 0.10*basic_salary;
   PF = 0.12*basic_salary;
   CF = 0.01*basic_salary;
   total_salary = basic_salary + DA + HRA + PF + CF;
  }
};
class Project_Manager:public Employee
{
public:
  Project_Manager()
  {
    basic_salary = 90000;
    DA = 0.97*basic_salary;
    HRA = 0.10*basic_salary;
    PF = 0.12*basic_salary;
    CF = 0.01*basic_salary;
    total_salary = basic_salary + DA + HRA + PF + CF;
  }
};
int main()
{
  int x;
  int n1,n2,n3,n4,i;
  cout<<"\nEnter number of records you wish to input for programmers: ";
  cin>>n1;
  Programmer P[n1];
  cout<<"Enter number of records you wish to input for team leaders: ";
  cin>>n2;
  TeamLeader T[n2];
  cout<<"Enter number of records you wish to input for assistant project managers: ";
  cin>>n3;
  Assistant_PM A[n3];
  cout<<"Enter number of records you wish to input for project managers: ";
  cin>>n4;
  Project_Manager M[n4];
  do
  {
   cout<<"\n---------Menu----------"<<endl;
   cout<<"\nPlease choose the role for which you wish to input data!!!!";
   cout<<"\n1.Programmer";
   cout<<" 2.Team leader";
   cout<<" 3.Assistant project manager";
   cout<<" 4.Project Manager";
   cout<<" 5.Exit";
   cout<<"\nPlease enter your choice:";
   cin>>x;
   switch(x)
   {
    case 1:
    for(i=0;i<n1;i++)
    {
     cout<<"\nEnter details for programmer "<<i+1;
     P[i].getdata();
     }
     cout<<"\n-------Programmer details---------"<<endl;
     cout<<"\nSrno\tName\tId\tAddress\tEmail id\tMobileno Salary";
     for(i=0;i<n1;i++)
     {
      cout<<endl<<i+1;
      P[i].showdata();
      P[i].show_salary();
     }
     break;
     case 2:
     for(i=0;i<n2;i++)
     {
      cout<<"\nEnter details for Team leader "<<i+1;
      T[i].getdata();
     }
      cout<<"\n-------Team Leader details---------"<<endl;
      cout<<"\nSrno\tName\t\tId\tAddress\tEmail id\tMobileno Salary";
      for(i=0;i<n2;i++)
      {
       cout<<endl<<i+1;
       T[i].showdata();
       T[i].show_salary();
      }
     break;
     case 3:
     for(i=0;i<n3;i++)
     {
      cout<<"\nEnter details for Assistant Project Manager "<<i+1;
      A[i].getdata();
     }
      cout<<"\n-------Assistant Project Manager details---------"<<endl;
      cout<<"\nSrno\tName\t\tId\tAddress\tEmail id\tMobileno Salary";
      for(i=0;i<n3;i++)
      {
        cout<<endl<<i+1;
        A[i].showdata();
        A[i].show_salary();
     }
      break;
     case 4:
     for(i=0;i<n4;i++)
     {
      cout<<"\nEnter details for Project Manager "<<i+1;
      M[i].getdata();
     }
     cout<<"\n-------Project Manager details---------"<<endl;
     cout<<"\nSrno\tName\t\tId\tAddress\tEmailid\tMobileno Salary";
     for(i=0;i<n4;i++)
     {
      cout<<endl<<i+1;
      M[i].showdata();
      M[i].show_salary();
     }
     break;
     case 5:
     exit(0);
     break;
     default:
     cout<<"\nPlease enter a valid choice!\n";
     break;
  }
}while(i!=5);
return 0;
}



