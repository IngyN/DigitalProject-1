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
    set <Implicant> Essentials;
    vector<bitset<16384>> table;
    
public:
    
    Table2(set<Implicant> & , set<short> &);
    ~Table2();
    
    void reduceDominatingRows();
    void reduceDominatingColumns();
    void findEssentialPrimeImplicants();    
};

#endif /* defined(__DigitalProject_1__Table2__) */
