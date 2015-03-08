//
//  main.cpp
//  DigitalProject-1
//
//  Created by Ingy on 3/1/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
using namespace std;
//#include "Implicant.h"
#include "Table1.h"
//bool isPowerof2(short);

bool existsIn(short, vector<short> &) ;

int main()
{
    
    cout << "Please enter the number of variables that your function has.\n" ;
    short variables;
    cin >> variables;
    while(variables<=0 ||variables>16)
    {
        cout << "The number you entered was inappropriate please enter an integer from 1 to 16.\n";
        cin >> variables;
    }
    
    vector<short> minterms;
    
    short temp,counter=0;
    cout << "Please enter the minterms of the function.\n";
    do
    {
       cin >>temp;
       while(temp<0 ||temp>variables)
        {
            cout << "The number you entered was inappropriate please enter an integer from 0 to " << variables<<".\n";
            cin >> temp;
        }
       if(temp!=-1)
        minterms.push_back(temp);
       counter++;
    }while(temp!=-1 && counter<variables);
    
    
    vector <short> dontcares;
    cout << "Please enter the dont cares of the function.\n";
    counter=0;
   do
    {
        cin >>temp;
        while(temp<0 ||temp>variables||existsIn(temp,minterms))
        {
            cout << "The number you entered was inappropriate please enter an integer from 0 to " << variables<<".\n";
            cin >> temp;
        }
        if(temp!=-1)
            dontcares.push_back(temp);
        counter++;
    }while(temp!=-1 && counter<variables-minterms.size());
    
    for(int i=0;i<dontcares.size();i++)
    {
        minterms.push_back(dontcares[i]);
    }
    
    Table1 tester;
    for(int i=0;i<minterms.size();i++)
        tester.insert(minterms[i]);
    
    tester.traverseAndCompare();
}

bool existsInMinterms(short k, vector<short> & minterms)
{
    bool found =false;
    for(int i=0;i<minterms.size()&& found ==false;i++)
    {
        if(k== minterms[i])
        {
            found = true;
        }
        
    }
    return found;
}




//    set<short> A;
//    A.insert(5);
//    A.insert(3);
//    A.insert(8);
//    
//    
//    cout << "(";
//    set <short> :: iterator i= A.begin();
//    cout << *i;
//    i++;
//    
//    for( ;i!=A.end(); i++)
//    {
//            cout << "," << *i;
//        
//    }
//    cout << ")";
//    for(short i : A)
//    {
//        cout << i;
//    }


//bool isPowerof2(short a)
//{
//    return ((a &(a-1)) ==0);
//}