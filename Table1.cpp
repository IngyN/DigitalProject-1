//
//  Table1.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/4/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table1.h"
#include "Table2.h"
#include "iostream"
#include "iomanip"
#include <cmath>
using namespace std;


Table1::Table1()
{
    done =false;
}

Table1::Table1(short num)
{
    initial.resize(num+1);
    intermediate.resize(num+1);
    final.resize(num+1);
    done=false;

}

Table1::~Table1()
{
    
}

//Initial insert of the individual non-combined implicants
void Table1::insert(short a)
{
    Implicant one (a);

    initial [one.numberOfOnes()].push_back(one);
    
}


// Compare and combine one category and the next
// if two elements can be combined, they are combined
// In the function combine with the booleans Combined of each of the three implicants is updated
// i and j are set to combined
// n the new implicant is set to not combined.
// Does not insert duplicates.

void Table1:: display( vector<vector<Implicant>> & toDisplay)
{

    for(int i=0; i< toDisplay.size(); i++)
    {
        for(int j=0; j< toDisplay[i].size(); j++)
        {
            toDisplay[i][j].printImpl();
            toDisplay[i][j].printRepresentation();
            cout<<endl;
        }
        if(toDisplay[i].size()>0)
        cout << " --------------------------------"<<endl;
    }
    cout << endl;

}


void Table1::traverseAndCompare(set<short> & m)
{
    bool initial= true;
    
    cout <<"\n Initial Table\n";
    display(this->initial);
    
    while (!done)
    {
        done =true;
        
        if (initial)
        {
            //intermediate.clear();
            intermediate.assign(this->initial.size(), vector<Implicant>());
            if(this->initial.size()>0)
            {
                for(int i=0; i< this->initial.size()-1; i++)
                {
                    done &= !(combine(i, initial));
                    this->putInFinal(i, initial);
                    
                }
            }
            this->putInFinal(this->initial.size() - 1, initial);
            initial=false;
            
        }
        else
        {
            //initial.clear();
            this->initial.assign(this->intermediate.size(), vector<Implicant>());
            
            if(this->intermediate.size()>0)
            {
                for(int i=0; i< this->intermediate.size()-1; i++)
                {
                    done &=!(combine(i, initial));
                    this->putInFinal(i, initial);
                    
                }
                this->putInFinal(intermediate.size() - 1, initial);
            }
            
            initial =true;

        }
    }
    
    cout <<"\n Final Table\n";
    this->display(final);
    
    vector <Implicant> temp;
    for(int i=0; i<final.size(); i++)
        for(Implicant &j : final[i])
            temp.push_back(j);
            
    Table2 t (temp, m);
    t.reduce();
}

// loops over one vector if one of the elements were not combined put in final
void Table1::putInFinal (short index, bool init)
{
    
    if(init)
    {
        for( Implicant& i: initial[index])
            if (!i.isCombined() && !implicantExists(final, i, index))
                final[i.numberOfOnes()].push_back(i);
        
    }
    else
        for( Implicant& i: intermediate[index])
            if (!i.isCombined()  && !implicantExists(final, i, index))
                final[i.numberOfOnes()].push_back(i);
    
}


// Compare and combine one category and the next
// if two elements can be combined, they are combined
// In the function combine with the booleans Combined of each of the three implicants is updated
// i and j are set to combined
// n the new implicant is set to not combined.
// Does not insert duplicates.
bool Table1::combine(short index, bool initial)
{
    bool flag= false;
    
    if(initial)
    {
        if(this->initial[index].size()>0 && this->initial[index+1].size()>0)
        {
            for (Implicant& j:this->initial[index])
                for (Implicant& i: this->initial[index+1])
                    if (i.canCombine(j))
                    {
                        flag =true;
                        Implicant n= *i.combineWith(j);
                        if (this->implicantDoesNotExist(n.numberOfOnes(), n, initial))
                            this->intermediate[n.numberOfOnes()].push_back(n);
                    }
        }
    }
    else
    {
        if(this->intermediate[index].size()>0 && this->intermediate[index+1].size()>0)
        {
            for (Implicant& j:this->intermediate[index])
                for (Implicant& i: this->intermediate[index+1])
                    if (i.canCombine(j))
                    {
                        flag = true;
                        Implicant n= *i.combineWith(j);
                        
                        if (this->implicantDoesNotExist(n.numberOfOnes(), n, initial))
                            this->initial[n.numberOfOnes()].push_back(n);
                    }
        }
        
    }
    
    return flag;
    
}

bool Table1::implicantDoesNotExist(short index, const Implicant & n, bool initial)
{
    if(initial)
    {
        for(Implicant& i: this->intermediate[index])
            if(n == i)
                return false;
    }
    else
    {
        for(Implicant& i: this->initial[index])
            if(n == i)
                return false;
    }
    
    return true;
}

bool Table1::implicantExists(vector<vector<Implicant>> & v, Implicant & i, short index)
{
    for (Implicant& n: v[index])
        if(n==i)
            return true;
    
    return false;
    
}