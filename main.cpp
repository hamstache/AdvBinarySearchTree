/*
 Programmer: Josh Moynihan
 Date: 11/5/14
 Class:CPSC131
 Time: 1:00pm-2:15pm
 Instructor: Dr. Ray Ahmadnia
 Project: Project No. 10 - constructing BST
 */

#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
using namespace std;

struct node{
    string month;
    int days;
};


int main()
{
    time_t g;
    time(&g);
    cout << "Today's date and time is: " << ctime(&g) << endl;
    
    cout << "----------Part 1----------\n";
    
    node x[12];
    fstream f;
    f.open("/Users/Hamstache/pro10.txt", ios::in);
    for (int i = 0; i<12; ++i){
        f>>x[i].month>>x[i].days;
    }
    f.close();
    
    //string months[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug","Sep","Oct","Nov","Dec"};
    BST t;
    
    for (int i = 0;i<12;i++)
    {
        t.insert(x[i].month,x[i].days);//overload insert function
    }
    
    
    
    //OUTPUT
    //display the name of months in alphabetical order (in order) followed by the number of days in the month
    cout << "\nMonth's name | No.Days" <<endl <<"-------------------------\n";
    t.display();
    //Display leaves of the tree in alphabetical order:
    cout<< endl << "The leaves of the tree are: "; t.DisplayLeaves();
    //Display parents with two children
    cout << "Parents with two children are: "; t.displayp2c();
    //Display parents with only one child
    cout << "\nParents with only one child are: ";t.displayp1c();
    //Enter name of a month and have program search and display the number of days in that month
    string input;
    cout << endl <<"Please enter the month to see its number of days: ";
    //cin>>input;
    //cout <<"The number of days in " << input << " are " << t.findDays(input)<<".";
    //Find the number of nodes in the tree
    cout << endl << "There are " << t.CountNodes() << " nodes in the tree.";
    //Find the height of the tree
    cout << endl << "The height of the tree is " << t.HeightTree()<<"." << endl;
    
    
    return 0;
}