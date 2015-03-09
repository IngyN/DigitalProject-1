//
//  Table2.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table2.h"
#include <iomanip>


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

void Table2:: reduce()
{
    
    while ((findEssentialPrimeImplicants())&&(reduceDominatingColumns())&&(reduceDominatingRows()));

}

bool Table2::reduceDominatingRows()
{
    vector<short> * covered = new vector<short>, * covered2 = new vector <short>;
    bool done=true;
    
    for(int i=0; i<primeImplicants.size();i++)
    {
        covered->clear();
        covered2->clear();
        
        covered= primeImplicants[i].returnMinterms();
        
        for(int j=i+1;j<primeImplicants.size(); j++)
        {
            covered2= primeImplicants[j].returnMinterms();
            
            if(vectorDominates(covered, covered2))
                // code comes here if covered2 dominates covered.
            {
                // Delete row i
                for(int l=0; l<minterms.size(); l++)
                    table[l].reset(i);
                done=false;
            }
            
            else if (vectorDominates(covered2, covered))
            {
                // code comes here if covered dominates covered2.
                // Delete row j
                for(int l=0; l<minterms.size(); l++)
                    table[l].reset(j);
                done =false;
            }
        }
    }
    return done;
    
}

// returns true if two dominates one
bool Table2::vectorDominates(vector<short> * one, vector<short> * two)
{
    for (short i: *one)
        if(!vectorFind(two, i))
            return false;
    
    if (one->size()<two->size())
        return true;
    
    else return false;
    
}

bool Table2::vectorFind(vector<short> * v, short e)
{
    for (short i: *v)
        if(e==i)
            return true;
    
    return false;
}

bool Table2::reduceDominatingColumns()
{
    vector<short> * covered = new vector<short>, * covered2 = new vector <short>;
    bool done = true;
    for(int i=0; i<minterms.size();i++)
    {
        covered->clear();
        covered2->clear();
        
        for (int k=0; k<primeImplicants.size(); k++)
            if(primeImplicants[k].contains(minterms[i]))
                covered->push_back(k);// column of minterm [i]
        
        for(int j=i+1;j<minterms.size(); j++)
        {
            for (int k=0; k<primeImplicants.size(); k++)
                if(primeImplicants[k].contains(minterms[j]))
                    covered2->push_back(k); // column of minterm [j]
            
            if(vectorDominates(covered, covered2))
                // code comes here if covered2 dominates covered.
            {
                // Delete column i
                table[i].reset();
                done = false;
            }
            
            else if (vectorDominates(covered2, covered))
            {
                // code comes here if covered dominates covered2.
                // Delete column j
                table[j].reset();
                done=false;
            }
        }
    }
    
    return done;
}

bool Table2::findEssentialPrimeImplicants()
{
    bool onlyOne, done=true;
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
                done=false;
            }
        }
        
    }
    
    return done;
}

void Table2::display()
{
    for (short i:minterms)
        cout << setw(4) <<i;
    
    for ( int i=0; i<primeImplicants.size(); i++)
    {
        for (int j=0; j <minterms.size(); j++ )
        {
            primeImplicants[i].printImpl();
            
            if(table [j][i]==0)
                cout <<setw(4)<< " ";
            else
                cout << setw(4)<<"@";
        }
        cout <<endl;
    }
}











