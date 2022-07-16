/* Name: Aditya Nitin Kelkar  Panel: C   Roll no: 39     Batch: C3
OOP Lab Assignment 8
Problem Statement: Write a program to manage a shopping list. Each shopping list item is represented by a string stored in a container. 
Your design requires a print function that prints out the contents of the shopping list.
1.Create an empty list.
2.Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print the list.
3.Remove the first element from the list. Print the list.
4.Insert the item, "coffee" at the beginning of the list. Print the list.
5.Find the item, "sugar" and replace it with "honey." Print the list.
6.Insert the item, "baking powder" before "milk" in the list. Print the list.
7.Sort and Search the item in the list.*/
#include<iostream>
#include<list>
using namespace std;

void showlist(list<string> show_list)//showing list
{
    int i=0;
    list<string>::iterator it; //declaring the iterator
    for(it = show_list.begin(); it != show_list.end(); it++)
    {
        i++;
        cout << "\t" << i << "."<< *it<< "\n";
    }
}

int main()
{
    //creating empty list
    list <string> show_list;
    //appending items to list
    show_list.push_back("eggs");
    show_list.push_back("milk");
    show_list.push_back("sugar");
    show_list.push_back("chocolate");
    show_list.push_back("flour");
    //declaring iterator for list
    list <string> :: iterator it;
    //printing initial list
    cout<<"\nInitial list:\n";
    showlist(show_list);
    //deleting 1st element
    show_list.pop_front();
    cout<<endl<<"List after removing first element: "<<endl;
    showlist(show_list);
    //inserting 1st element
    show_list.push_front("coffee");
    cout<<endl<<"List after inserting first element as coffee: "<<endl;
    showlist(show_list);
    //searching for sugar
    for(it = show_list.begin(); it != show_list.end(); ++it)
    {
        if(*it=="sugar")//if found replace with honey
        {
            *it="honey";
            break;
        }
    }
    cout<<endl<<"List after changing Sugar with Honey: "<<endl;
    showlist(show_list);
    //searching for milk
    for(it = show_list.begin(); it != show_list.end(); ++it)
    {
        if(*it=="milk")
        {
            break;
        }
    }
    //appending baking powder before milk by using iterator
    show_list.insert(it,"baking powder");
    cout<<endl<<"List after adding element before Milk: "<<endl;
    showlist(show_list);
    //sorting the list using sort function
    cout<<endl<<"List after sorting: "<<endl;
    show_list.sort();
    showlist(show_list);
    string str;
    int flag=0,i=0;
    //accept element to be searched
    cout<<"\nEnter element to search in list: ";
    getline(cin,str);
    //searching element
    for(it = show_list.begin(); it != show_list.end(); ++it)
    {
        if(*it==str)
        {
            flag++;//counter if found gets 1
            break;
        }
        i++;
    }
    //checking if element present in list or not
    if(flag==0)
        cout<<"\nElement not found.....";
    else
    {
        cout<<"\nElement "<<str<<" found at location: "<<i+1<<endl;
    }
}