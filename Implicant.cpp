//
//  Implicant.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/3/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Implicant.h"
#include <string>
#include <bitset>

Implicant:: Implicant()
{
    
}

Implicant:: Implicant(const Implicant & other)
{
    this->combined= other.combined;
    this->diff=other.diff;
    this->minterms=other.minterms;
}

Implicant:: ~Implicant()
{}

short Implicant:: returnFirstMinterm()
{
    set<short>::iterator i= minterms.begin();
    
    return *i;
}


bool Implicant:: isCombined()
{
    return combined;
}

void Implicant:: setCombinedToFalse()
{
    combined = false;
}

void Implicant:: setCombinedToTrue()
{
    combined = true;
}

short Implicant:: numberOfOnes()
{
    unsigned short count =1; short result=0;
    
    if (minterms.size()>1)
    {
        for( set <short> ::iterator i = minterms.begin(); i!=minterms.end(); i++)
            count= count & (*i);
    }
    
    while (count !=0)
    {
        result = count%2;
        count =count >>1;
    }
    
    return result;
}

void Implicant:: printBinary(short k)
{
    bitset<16> bit(k);
    cout << bit;
}

void Implicant:: printImpl() //SMALL ISSUE HERE , THE COMMA PRINTS ONE TOO MANY TIMES
{
    cout << "(";
    for(set <short> :: iterator i= this->minterms.begin(); i!=this->minterms.end(); i++)
    {
        if(i !=this->minterms.end())
            cout << *i << ",";
        else
            cout << *i;
    }
    cout << ")";
}

Implicant * Implicant:: combineWith(Implicant &other)
{
    Implicant * temp;
    for (set <short> :: iterator i= this->minterms.begin(),j=other.minterms.begin(); i!=this->minterms.end(); i++, j++)
    {
        temp->minterms.insert(*i);
        temp->minterms.insert(*j);
    }
    
    for (set <short> :: iterator i= this->diff.begin(),j=other.diff.begin(); i!=this->diff.end(); i++, j++)
    {
        temp->diff.insert(*i);
        temp->diff.insert(*j);
    }
    temp->setCombinedToTrue();
    
    return temp;
}

bool Implicant::areEqual(Implicant& other)
{
    bool flag = true;
    
    if(other.minterms.size()!= this->minterms.size())
    {
        for (set <short> :: iterator i= minterms.begin(), j=other.minterms.begin(); i!=minterms.end(); i++, j++)
        {
            if(*i != *j)
                flag = false;
        }
    }
    else
    {
        return false;
    }
    
    return flag;
}

bool Implicant:: isPowerof2(short a)
{
        return ((a &(a-1)) ==0);
}


