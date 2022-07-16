/*Name:Aditya Nitin Kelkar  Panel:C
Roll no:39     Batch:C3
OOP Lab Assignment 6
Problem Statement: A school maintains the mark sheets of all standard students in the following form –
PRN   StudentName   Maths   Physics   Chemistry   Total %   Grade

A teacher put marks for the student by his/her PRN and the system checks whether marks for different subjects are negative or not. 
If it is negative, the system displays appropriate message, otherwise updates the file by storing the marks across the selected subject. 
The system calculates the total percentage after putting marks for all three subjects and accordingly finds the grade.
Whenever an administrator wants to search a student’s record, he/she inputs the student's PRN and the system searches in a file and displays whether 
it is available or not, otherwise an appropriate message is displayed. An administrator can also delete/modify a record of a student.
Design such system using C++ Program with file and exceptions handling.
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

class marksheet
{
    private:
        long int prn;
        char name[100];
        int maths;
        int physics;
        int chemistry;
        float percentage;
        char grade;
    public:
        marksheet()
        {
            prn=0;
            strcpy(name,"-------");
            maths=0;
            physics=0;
            chemistry=0;
            percentage=0.0;
            grade='-';
        }
        marksheet(long int prn,char n[100],int maths,int physics,int chemistry,float percentage,char grade)
        {
            this->prn=prn;
            strcpy(this->name,n);
            this->maths=maths;
            this->physics=physics;
            this->chemistry=chemistry;
            this->percentage=percentage;
            this->grade=grade;
        }
        void dispdata();
        void modify(int maths,int physics,int chemistry,float percentage,char grade)
        {
            this->maths=maths;
            this->physics=physics;
            this->chemistry=chemistry;
            this->percentage=percentage;
            this->grade=grade;
        }
        long int getPRN()
        {
            return prn;
        }
};

void marksheet::dispdata()
{
    cout<<"\t"<<prn;
    cout<<"\t\t"<<name;
    cout<<"\t"<<maths;
    cout<<"\t"<<physics;
    cout<<"\t"<<chemistry;
    cout<<"\t\t"<<percentage;
    cout<<"\t\t"<<grade;
}

class teacher:public marksheet
{
    public:
        void getdata();
        void display()
        {
            marksheet m;
            int i=0;
            cout<<"\n------------------------------------------------------------------------------------------";
            cout<<"\nSr.no\tPRN\t\tName\tMaths\tPhysics\tChemistry\tPercentage\tGrade";
            cout<<"\n------------------------------------------------------------------------------------------";
            ifstream file("student.txt",ios::in|ios::binary);
            file.read((char*)&m,sizeof(m));
            while(!file.eof())
            {
                if(m.getPRN()!=0)
                {
                    i++;
                    cout<<"\n"<<i;
                    m.dispdata();
                }
                else
                    break;
                file.read((char*)&m,sizeof(m));
            }
            cout<<"\n------------------------------------------------------------------------------------------";
            file.close();
        }
};

void teacher::getdata()
{
    long int prn;
    char n[100];
    int maths;
    int physics;
    int chemistry;
    float percentage;
    char grade;
    int p=0;
    cout<<"\n-----Enter the data for the students----------";
    try
    {
        fflush(stdin);
        cout<<"\n\nEnter the PRN of the student: ";
        cin>>prn;
        cout<<"\nEnter the name of the student: ";
        cin>>n;
        cout<<"\nEnter the marks of the following subjects: \n\tMaths: ";
        cin>>maths;
        if(maths<0)
            throw(maths);
        else
            p++;
        cout<<"\n\tPhysics: ";
        cin>>physics;
        if(physics<0)
            throw(physics);
        else
            p++;
        cout<<"\n\tChemistry: ";
        cin>>chemistry;
        if(chemistry<0)
            throw(chemistry);
        else
            p++;
    }
    catch(int i)
    {
        cout<<"\nError: You have entered negative marks!";
    }
    if(p==3)
    {
        fstream file("student.txt",ios::app|ios::binary);
        percentage=(maths+physics+chemistry)/3;
        if((percentage>90)&&(percentage<=100))
            grade='A';
        else if((percentage>80)&&(percentage<=90))
            grade='B';
        else if((percentage>70)&&(percentage<=80))
            grade='C';
        else if((percentage>60)&&(percentage<=70))
            grade='D';
        else if((percentage>40)&&(percentage<=60))
            grade='E';
        else if(percentage<40)
            grade='F';
        marksheet m(prn,n,maths,physics,chemistry,percentage,grade);
        file.seekp(0,ios::end);
        file.write((char*)&m,sizeof(m));
        cout<<"\nRecord entered successfully!";
        file.close();
    }
    else
    {
        cout<<"\nEntered marks are incorrect!";
    }
}

class admin:public marksheet
{
    public:
        void see()
        {
            marksheet m;
            long int num;
            int flag=0;
            cout<<"\n\nEnter the PRN of the student to search:";
            cin>>num;
            cout<<"\n------------------------------------------------------------------------------------------";
            cout<<"\nSr.no\tPRN\t\tName\tMaths\tPhysics\tChemistry\tPercentage\tGrade";
            cout<<"\n------------------------------------------------------------------------------------------";
            ifstream file("student.txt");
            file.read((char*)&m,sizeof(m));
            while(!file.eof())
            {
                if(num==m.getPRN())
                {
                    flag++;
                    cout<<"\n"<<flag;
                    m.dispdata();
                }
                file.read((char*)&m,sizeof(m));
            }
            cout<<"\n------------------------------------------------------------------------------------------";
            if(flag==0)
                cout<<"\n\nPRN not found!";
            file.close();
        }
        void del()
        {
            marksheet m;
            int flag=0;
            long int num;
            ifstream intf("student.txt",ios::binary);
            ofstream outf("temp.txt",ios::app|ios::binary);
            cout<<"\n\nEnter the PRN of the student to be deleted: ";
            cin>>num;
            intf.read((char*)&m,sizeof(m));
            while(!intf.eof())
            {
                if(num==m.getPRN())
                {
                    flag++;
                }
                else
                {
                    outf.write((char*)&m,sizeof(m));
                }
                intf.read((char*)&m,sizeof(m));
            }
            intf.close();
            outf.close();
            remove("student.txt");
            rename("temp.txt","student.txt");
            if(flag==0)
                cout<<"\n\nPRN not found!";
            else
            {
                cout<<"\nRecord deleted successfully!";
            }
        }
        void a_modify()
        {
            marksheet m;
            fstream file("student.txt",ios::in|ios::out|ios::binary);
            int flag=0,temp=0;
            long int num;
            cout<<"\n\nEnter the PRN of the student to be modified: ";
            cin>>num;
            file.read((char*)&m,sizeof(m));
            while(!file.eof())
            {
                if(num==m.getPRN())
                {
                    flag++;
                    break;
                }
                else
                {
                    temp++;
                }
                file.read((char*)&m,sizeof(m));
            }
            if(flag==1)
            {
                long int pos=file.tellp()-sizeof(m);
                file.seekp(pos);
                int maths,physics,chemistry;
                float percentage;
                char grade;
                int p=0;
                cout<<"\nEnter the marks of the following subjects:\n\tMaths:";
                cin>>maths;
                cout<<"\n\tPhysics:";
                cin>>physics;
                cout<<"\n\tChemistry:";
                cin>>chemistry;
                percentage=(maths+physics+chemistry)/3;
                if((percentage>90)&&(percentage<=100))
                    grade='A';
                else if((percentage>80)&&(percentage<=90))
                    grade='B';
                else if((percentage>70)&&(percentage<=80))
                    grade='C';
                else if((percentage>60)&&(percentage<=70))
                    grade='D';
                else if((percentage>40)&&(percentage<=60))
                    grade='E';
                else if(percentage<40)
                    grade='F';
                m.modify(maths,physics,chemistry,percentage,grade);
                file.write((char*)&m,sizeof(m));
                cout<<"\nRecord has been modified!";
            }
            else
                cout<<"\nPRN not found!";
            file.close();
        }
        void a_display()
        {
            marksheet m;
            ifstream file("student.txt",ios::in|ios::binary);
            int i=0;
            cout<<"\n------------------------------------------------------------------------------------------";
            cout<<"\nSr.no\tPRN\t\tName\tMaths\tPhysics\tChemistry\tPercentage\tGrade";
            cout<<"\n------------------------------------------------------------------------------------------";
            file.read((char*)&m,sizeof(m));
            while(!file.eof())
            {
                if(m.getPRN()!=0)
                {
                    i++;
                    cout<<"\n"<<i;
                    m.dispdata();
                }
                else
                    break;
                file.read((char*)&m,sizeof(m));
            }
            cout<<"\n------------------------------------------------------------------------------------------";
            file.close();
        }
};

int main()
{
    teacher t;
    admin a;
    int choice,i,ch;
    do
    {
        cout<<"\nLogin as \n1.Teacher\n2.Administrator";
        cout<<"\nEnter your choice:";
        cin>>ch;
        if(ch==1)
        {
            do
            {
                cout<<"\n----------------------------------------------";
                cout<<"\n--------Menu---------";
                cout<<"\n1.Add a student record";
                cout<<"\n2.Display student records";
                cout<<"\n----------------------------------------------";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1: t.getdata();
                            break;
                    case 2: t.display();
                            break;
                    default:cout<<"Wrong input";
                }
                cout<<"\nPress 1 to logout: ";
                cin>>i;
            }while(i!=1);
        }
        else if(ch==2)
        {
            do
            {
                cout<<"\n----------------------------------------------";
                cout<<"\n-----------Menu------------";
                cout<<"\n1.Display student records";
                cout<<"\n2.Search student records";
                cout<<"\n3.Delete student records";
                cout<<"\n4.Modify student records";
                cout<<"\n----------------------------------------------";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                    case 1: a.a_display();
                            break;
                    case 2: a.see();
                            break;
                    case 3: a.del();
                            break;
                    case 4: a.a_modify();
                            break;
                    default:cout<<"Wrong input";
                }
                cout<<"\nPress 1 to logout: ";
                cin>>i;
            }while(i!=1);
        }
        else
            cout<<"\nWrong input";
        cout<<"\nPress 1 to exit: ";
        cin>>i;
    }while(i!=1);
    return 0;
}
