//
//  Table2.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table2.h"


Table2::Table2(vector<Implicant> & primes, vector<Implicant> & minterms)
{
    table = new char*[primes.size()];
    for(int i=0; i<primes.size(); i++)
        table[i]= new char[minterms.size()];
    
}

Table2::~Table2()
{
    
}

void Table2::reduceDominatingRows()
{
    
}

void Table2::reduceDominatingColumns()
{
    
}

void Table2::findEssentialPrimeImplicants()
{
    
}

