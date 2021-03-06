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
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
#include "Implicant.h"
#include "Table1.h"
//bool isPowerof2(short);

bool existsIn(short, set<short> &) ;
void inputMinterms(set<short>&, short);
void inputDontCares(set<short>&, set<short> &,short);

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
    
    set<short> minterms;
    inputMinterms(minterms, variables);
    
    set<short> dontcares;
    
    char c;
    cout << "If you would like to input don't cares enter Y\n";
    cin>>c;
    
    if(c=='Y')
    {
        inputDontCares(dontcares, minterms,variables);
        
    }
    
    for(short i: minterms)
    {
        dontcares.insert(i);
    }
    
    Table1 tester(variables);
    
    if (dontcares.size()!= pow(2,variables))
    {
    for(short i: dontcares)
        tester.insert(i);
        tester.traverseAndCompare(minterms);
    }
    
    else
    {
        cout <<endl<< "The corresponding minimized Boolean expression is: " <<1<<endl<<endl;
    }
    
    
    system("pause");
    return 0;
}

bool existsIn(short k, set<short> & minterms)
{
    bool found =false;
    for(set <short> :: iterator i = minterms.begin(); i!=minterms.end()&& found ==false; i++)
    {
        if(k== *i)
        {
            found = true;
        }
        
    }
    return found;
}

void inputMinterms(set<short>& minterms, short variables)
{
    bool repeat;
    do
    {
        minterms.erase(minterms.begin(), minterms.end());
        int i=0;
        repeat=false;
        string temp;
        cout << "Please enter the minterms of the function.\n";
        cin.ignore();
        getline(cin, temp);
        
        stringstream ss(temp);
        string buff;
        while (ss >> buff)
        {  i=stoi(buff);
            minterms.insert(short(i));
        }
        if (i<0||i>=pow(2,variables))
            repeat=true;
    }while(minterms.size()>pow(2,variables)||repeat);
    

}

void inputDontCares(set<short>& dontcares, set<short> & minterms,short variables)
{
    //cout << "Please enter the dont cares of the function.\n";
    int i;
    bool repeat;
    do
    {
        dontcares.erase(dontcares.begin(), dontcares.end());
        repeat=false;
        string temp;
        cout << "Please enter the dontcares of the function.\n";
        cin.ignore();
        getline(cin, temp);
        
        stringstream ss(temp);
        string buff;
        while (ss >> buff)
        {  i=stoi(buff);
            dontcares.insert(short(i));
        }
        if (i<0||i>=pow(2,variables))
            repeat=true;
        
    }while(dontcares.size()>(pow(2,variables)-minterms.size())||existsIn(short(i), minterms)||repeat);
    
    
    
}

