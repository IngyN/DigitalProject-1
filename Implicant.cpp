//
//  Implicant.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/3/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Implicant.h"
#include <string>

Implicant:: Implicant()
{
    
}

Implicant:: Implicant(const Implicant &)
{
    
}

Implicant:: ~Implicant()
{
    
}

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

short Implicant:: numberOfOnes()
{
    return 0;
    //minterms.subs
}

void Implicant:: printBinary()
{
    
}

void Implicant:: printImpl()
{
    
}

Implicant * Implicant:: combine(Implicant &)
{
    return NULL;
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


