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
#include <vector>
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
    bool areEqual(const Implicant &) const;
    
    short numberOfOnes() const;
    void printBinary(short);
    void printImpl();
    void printRepresentation();
    short numberOfMinterms();
    
    Implicant * combineWith(Implicant &);
    
    short returnFirstMinterm() const;
    vector<short> * returnMinterms();
    static bool isPowerof2(short a);
    static bool setsAreEqual (const set<short> &, const set <short>&);
    
    bool contains(short);
    
    bool operator == (const Implicant &) const;
    bool operator < (const Implicant &) const;
    
};

#endif /* defined(__DigitalProject_1__Implicant__) */
