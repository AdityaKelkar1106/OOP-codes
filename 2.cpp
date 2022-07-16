/*Name:Aditya Nitin Kelkar  Panel:C
Roll no:39     Batch:C3
OOP Lab Assignment 2 
Problem Statement: Develop an object-oriented program in C++ to create a database of employee information system 
containing the following information: Employee Name, Employee number, qualification, 
address, contact number, salary details (basic, DA, TA, Net salary), etc Construct the database 
with suitable inline member functions for initializing and destroying the data viz constructor, 
default constructor, Copy constructor, destructor. Use dynamic memory allocation concept while 
creating and destroying the object of a class. Use static data member concept wherever 
required. Also, Display the Employee information.*/
#include <iostream>
#include<string>
using namespace std;
class employee
{
 private:
  string emp_name;
  static int emp_id;
  string qualification,address;
  long int contact;
  double salary;
 public:
  employee()
{
 emp_name = "-";
 emp_id++;
 qualification = "-";
 address = "-";
 contact = 0;
 salary = 0.0;
}
employee(string name, string q, string a, long int number,double s)
{
 emp_name = name;
 emp_id++;
 qualification = q;
 address = a;
 contact = number;
 salary = s;
}
employee(employee &e)
{
 emp_name = e.emp_name;
 qualification = e.qualification;
 address = e.address;
 contact = e.contact;
 salary = e.salary;
 emp_id++;
}
inline void display()
{
 cout<<"\n*****Employee Database***\n"<<endl;
 cout<<"Employee name:: "<<emp_name<<endl;
 cout<<"Employee Id:: "<<emp_id<<endl;
 cout<<"Qualification:: "<<qualification<<endl;
 cout<<"Address:: "<<address<<endl;
 cout<<"Employee Contact Number:: "<<contact<<endl;
 cout<<"Employee Salary:: "<<salary<<"\n"<<endl;
}
~employee()
 {
  cout<<"\n Employee of ID Number "<<emp_id<<" is removed"<<endl;
  emp_id--;
 }
};
int employee :: emp_id;
int main()
{
 employee e1;
 e1.display();
 employee e2("Levi", "M.Tech", "MIT-WPU", 982477812, 57.40);
 e2.display();
 employee e3(e2);
 e3.display();
 employee *emp = new employee[3];
 emp[0] = e2;
 emp[1] = employee("Mikasa", "B.Tech", "MIT-WPU", 9846456341, 56.41);
 for(int i=0;i<3;i++)
 {
  emp[i].display();
 }
 delete [] emp;
 return 0;
}

