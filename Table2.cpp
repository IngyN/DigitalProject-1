//
//  Table2.cpp
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Table2.h"
#include <iomanip>


Table2::Table2(vector<Implicant> & primes, set<short> & mintermsLocal)
{
    
    primeImplicants = primes;
    
    for (short i: mintermsLocal)
        minterms.push_back(i);
    
    //    rows=primes.size();
    //    columns = minterms.size();
    
    table.resize(minterms.size());
    
    for(int i=0; i<primeImplicants.size(); i++)
    {
        for(int j=0; j<minterms.size(); j++)
            if(primeImplicants[i].contains(minterms[j]))
                table[j][i]=true;
            else
                table[j][i]=false;
    }
    
}

Table2::~Table2()
{
}

void Table2:: reduce()
{
    this->display();
    
    bool flag = true;
    while (flag)
    {
        bool f1 = findEssentialPrimeImplicants();
        bool f2 = reduceDominatingColumns();
        bool f3 = reduceDominatingRows();
        
        flag = !(f1 && f2 && f3);
    }
    
    this->displayEssentials();

}

bool Table2::reduceDominatingRows()
{
    vector<short> * covered = NULL, * covered2 = NULL;
    bool done=true;
    
    for(int i=0; i<primeImplicants.size();i++)
    {
        if(covered) covered->clear();
        if(covered2) covered2->clear();
        
        if(covered) delete covered;
        covered= primeImplicants[i].returnMinterms();
        
        for(int j=i+1;j<primeImplicants.size(); j++)
        {
            if(covered2) delete covered2;
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
    
    delete covered; delete covered2;
    if(!done)
        this->display();
    
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

bool Table2::reduceDominatingColumns() // remove dominating
{
    vector<short> * covered = new vector<short>, * covered2 = new vector <short>;
    bool done = true;
    for(int i=0; i<minterms.size();i++)
    {
        if(covered != nullptr) covered->clear();
        if(covered2 != nullptr) covered2->clear();
        
        for (int k=0; k<primeImplicants.size(); k++)
            if(primeImplicants[k].contains(minterms[i]) && table[i][k])
                covered->push_back(k);// include all the indeces of the implicants that cover minterm [i]
        
        for(int j=i+1;j<minterms.size(); j++)
        {
            for (int k=0; k<primeImplicants.size(); k++)
                if(primeImplicants[k].contains(minterms[j]) && table[j][k])
                    covered2->push_back(k); // include all the indeces of the implicants that cover minterm [j]
            
            if(vectorDominates(covered, covered2))
                // code comes here if covered2 dominates covered.
            {
                // Delete column j
                table[j].reset();
                done = false;
            }
            
            else if (vectorDominates(covered2, covered))
            {
                // code comes here if covered dominates covered2.
                // Delete column i
                table[i].reset();
                done=false;
            }
        }
    }
    delete covered; delete covered2;
    if(!done)
        this->display();
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
                if(table[i][j]==true && onlyOne==false)
                {
                    onlyOne =true;
                    essenRow= j;
                }
                else if(table[i][j]==true && onlyOne==true)
                {
                    onlyOne=false;
                    break;
                }
            }
            if(onlyOne==true)
            {
                Essentials.push_back(primeImplicants[essenRow]);
                table[i].reset();
                for(int k=0; k<minterms.size(); k++)
                {
                    if(table[k][essenRow] == true){
                        table[k].reset();
                    }
                    table[k].reset(essenRow);
                    
                }
                done=false;
            }
        }
        
    }
    if(!done)
        this->display();
    return done;
}

void Table2::display()
{
    cout <<endl;
    for (int i=0; i<15; i++) cout << ' ';
    for (vector <short> ::iterator i= minterms.begin(); i!=minterms.end(); i++)
    {
        cout.width(5);
        if((i==minterms.begin()))
            cout<<left <<*i;
        else cout << left <<*i;
    }
    
    cout <<endl;
    
    for ( int i=0; i<primeImplicants.size(); i++)
    {
        
        primeImplicants[i].printImpl();
        
        for (int j=0; j <minterms.size(); j++ )
        {
            cout.width(5);
            if(table [j][i]==0)
                cout << left<< " ";
            else
                cout <<left<<"@";
        }
        cout <<endl;
    }
}

void Table2::displayEssentials() const
{
    if(Essentials.size()>0)
    {
        cout << "\nEssential prime implicants"<<endl;
        for (Implicant i: Essentials)
        {
            (i).printImpl();
            cout <<setw(5);
            i.printRepresentation();
            cout<<endl;
        }
        cout <<endl;
    }
    else
        cout << "There are no essential prime implicants";
    
}










