/*Name:Aditya Nitin Kelkar  Panel:C
Roll no:39     Batch:C3
OOP Lab Assignment 1 
Problem Statement: An airline information system wants to maintain the information of passengers travelling by their airways. 
Following is the information that is to be maintained for the passengers.
Name of passenger 
Age of passenger 
flight no.  
departure time
source 
destination
Design a C++ class to accept and display information for the airlines.
*/
#include<iostream>
using namespace std;
class airline
{
private:
 int age=0;
 string f_no,dept_time,ps_name, source, destination;
public:
 void get_data()
 {
  cout<<"Enter name of the passenger : ";
  cin>>ps_name;
  cout<<"Enter age of the passenger : ";
  cin>>age;
  cout<<"Enter flight number : ";
  cin>>f_no;
  cout<<"Enter time of departure : ";
  cin>>dept_time;
  cout<<"Source of airline : ";
  cin>>source;
  cout<<"Destination of airline : ";
  cin>>destination;
 }
 void display()
 {
  cout<<"Name of passenger : "<<ps_name<<endl;
  cout<<"Age of passenger : "<<age<<endl;
  cout<<"Flight number : "<<f_no<<endl;
  cout<<"Time of Departure : "<<dept_time<<endl;
  cout<<"Source of Airline : "<<source<<endl;
  cout<<"Destination of Airline : "<<destination<<endl;
 }
};
int main()
{
airline a1[10];
int choice;
int flag = 1;
 do
 {
  cout<<"-----Menu-----";
  cout<<"\n1.Add more record(s) of passengers\n2.Display the records of passengers \n3.Exit"<<endl;
  cin>>choice;
  int i;
  switch(choice)
  {
    case 1:
    int num;
    cout<<"Please enter the number of record(s) to be added in our directory : ";
    cin>>num;
    for(i = 0; i < num; i++)
     {
      a1[i].get_data();
      }
    break;
    case 2:
    for(i = 0; i < 10; i++)
    {
     cout<<"Passenger "<<i+1<<" : "<<endl;
     a1[i].display();
    }
    break;
    case 3:
    flag = 0;
    break;
    default:
    cout<<"Please enter a valid option!"<<endl;
    break;
   }
 }while (flag == 1);
cout<<endl;
return 0;
}


