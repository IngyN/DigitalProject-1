//
//  Table2.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table2.h"


Table2::Table2(vector<Implicant> & primes, vector<short> & minterms)
{
    rows=primes.size();
    columns = minterms.size();
    table = new bool*[rows];
    
    for(int i=0; i<rows; i++)
    {
        table[i]= new bool[columns];
        for(int j=0; j<columns; j++)
            if(primes[i].contains(minterms[j]))
                table[i][j]=true;
    }
        
    
}

Table2::~Table2()
{
    for(int i=0;i<rows;i++)
    {
        delete [] table[i];
    }
    delete [] table;
}

void Table2::reduceDominatingRows()
{
    
}

void Table2::reduceDominatingColumns()
{
    
}

void Table2::findEssentialPrimeImplicants()
{
    bool onlyOne;
    int essenRow;
    for(int i=0; i<columns; i++)
    {
        onlyOne =false;
        for(int j=0; j<rows; j++)
        {
            if(table[i][j]==true && onlyOne==false)
            {
                onlyOne =true;
                essenRow= i;
            }
            else if(table[i][j]==true && onlyOne==true)
            {
                onlyOne=false;
                break;
            }
        }
        if(onlyOne==true)
            Essentials.push_back(essenRow);
    }
}














