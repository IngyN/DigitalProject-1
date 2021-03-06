//
//  Table2.h
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/8/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#ifndef __DigitalProject_1__Table2__
#define __DigitalProject_1__Table2__

#include "Table1.h"
#include "Implicant.h"

class Table2
{
    
private:
    
    vector <short> minterms;
    vector <Implicant> primeImplicants;
    vector <Implicant> Essentials;
    vector<bitset<16384>> table;
    
public:
    
    Table2(vector<Implicant> & , set<short> &);
    ~Table2();
    
    bool reduceDominatingRows();
    bool reduceDominatingColumns();
    bool findEssentialPrimeImplicants();
    void reduce();
    void display ();
    void displayEssentials()const;
    static bool vectorDominates(vector<short> *,vector<short> *);
    static bool vectorFind(vector<short> *,short);
};

#endif /* defined(__DigitalProject_1__Table2__) */
