//
//  Implicant.h
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/3/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#ifndef __DigitalProject_1__Implicant__
#define __DigitalProject_1__Implicant__

#include <iostream>
#include <set>
using namespace std;

class Implicant
{
    
private:
    //short value;
    set <short> minterms;
    set <short> diff;
    bool combined;
    
public:
    Implicant();
    Implicant(short);
    Implicant(const Implicant &);
    ~Implicant();
    
    bool isCombined();
    void setCombinedToFalse();
    void setCombinedToTrue();
    bool canCombine (Implicant & other) const;
    bool areEqual(Implicant &);
    
    short numberOfOnes();
    void printBinary(short);
    void printImpl();
    
    Implicant * combineWith(Implicant &);
    
    short returnFirstMinterm() const;
    static bool isPowerof2(short a);
    static bool setsAreEqual (const set<short> &, const set <short>&);
    
    bool operator == (Implicant &);
    
};

#endif /* defined(__DigitalProject_1__Implicant__) */
