//
//  Table2.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table2.h"


Table2::Table2(set<Implicant> & primes, set<short> & mintermsLocal)
{
    
    for (Implicant i: primes)
        primeImplicants.push_back(i);
    
    for (short i: mintermsLocal)
        minterms.push_back(i);
    
    //    rows=primes.size();
    //    columns = minterms.size();
    
    table.resize(minterms.size());
    
    for(int i=0; i<primeImplicants.size(); i++)
    {
        for(int j=0; j<minterms.size(); j++)
            if(primeImplicants[i].contains(minterms[j]))
                table[i][j]=true;
            else
                table[i][j]=false;
    }
    
}

Table2::~Table2()
{
}

void Table2::reduceDominatingRows()
{
    
}

void Table2::reduceDominatingColumns()
{
<<<<<<< Updated upstream
    
=======
    for(int i=0; i<columns; i++)
    {
        
        for(int j=0; j<rows; j++)
        {
        
            
        }
    }
>>>>>>> Stashed changes
}

void Table2::findEssentialPrimeImplicants()
{
    bool onlyOne;
    int essenRow=0;
    for(int i=0; i<minterms.size(); i++)// Columns
    {
        onlyOne =false;
        if (table[i].any())
        {
            for(int j=0; j<primeImplicants.size(); j++)//rows
            {
                if(table[j][i]==true && onlyOne==false)
                {
                    onlyOne =true;
                    essenRow= j;
                }
                else if(table[j][i]==true && onlyOne==true)
                {
                    onlyOne=false;
                    break;
                }
            }
            if(onlyOne==true)
            {
                Essentials.insert(primeImplicants[essenRow]);
                table[i].reset();
                for(int i=0; i<minterms.size(); i++)
                    table[i].reset(essenRow);
            }
        }
        
    }
}












