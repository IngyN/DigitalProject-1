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
    combined =false;
}

Implicant::Implicant(short a)
{
    combined=false;
    this->minterms.insert(a);
}

Implicant:: Implicant(const Implicant & other)
{
    this->combined= other.combined;
    this->diff=other.diff;
    this->minterms=other.minterms;
}

Implicant:: ~Implicant()
{}

short Implicant:: returnFirstMinterm() const
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

void Implicant:: printImpl()
{
    // WE NEED TO ACCOUNT FOR THE Xs (differences)
    cout << "(";
    set <short> :: iterator i= this->minterms.begin();
    cout << *i;
    i++;
    
    for( ; i!=this->minterms.end(); i++)
    {
        cout << "," << *i;
    }
    cout << ")";
}

Implicant * Implicant:: combineWith(Implicant &other)
{
    Implicant * temp = new Implicant;
    
    for (set <short> :: iterator i= this->minterms.begin(),j=other.minterms.begin(); i!=this->minterms.end(); i++, j++)
    {
        temp->minterms.insert(*i);
        temp->minterms.insert(*j);
    }
    
    for (set <short> :: iterator i= this->diff.begin(); i!=this->diff.end(); i++)
    {
        temp->diff.insert(*i);
    }
    
    // We add the new difference
    
    temp->diff.insert(abs(other.returnFirstMinterm()-this->returnFirstMinterm()));
    
    // Old one
    other.setCombinedToTrue();
    this->setCombinedToTrue();
    
    temp->setCombinedToFalse();
    
    return temp;
}

bool Implicant::areEqual(Implicant& other)
{
    
    if(other.minterms.size()!= this->minterms.size())
    {
        for (set <short> :: iterator i= minterms.begin(), j=other.minterms.begin(); i!=minterms.end(); i++, j++)
        {
            if(*i != *j)
                return false;
        }
    }
    else
    {
        return false;
    }
    
    return true;
}

bool Implicant :: setsAreEqual(const set<short> & S, const set<short> & S2)
{
    
    if (S.size()!= S2.size())
        return false;
    
    else
        for (set <short> :: iterator i= S.begin(), j=S2.begin(); i!=S.end(); i++, j++)
        {
            if(*i != *j)
                return false;
        }
    
    return true;
}

bool Implicant:: isPowerof2(short a)
{
    return ((a &(a-1)) ==0);
}

bool Implicant:: canCombine(Implicant& other) const
{
    if (!setsAreEqual(diff, other.diff))
        return false;
    
    if(isPowerof2(abs(this->returnFirstMinterm()-other.returnFirstMinterm())))
        return true;
    else
        return false;
}

bool Implicant::contains(short k)
{
    for(set <short> :: iterator i= this->minterms.begin(); i!=this->minterms.end(); i++)
    {
        if (*i==k)
        {
            return true;
        }
    }
    return false;
}

bool Implicant:: operator==(Implicant & other)
{
    return this->areEqual(other);
}
           
