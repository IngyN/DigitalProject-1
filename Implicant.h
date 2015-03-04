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
    Implicant(const Implicant &);
    ~Implicant();
    
    bool isCombined();
    void setCombinedToFalse();
    void setCombinedToTrue();
    
    short numberOfOnes();
    void printBinary(short);
    void printImpl();
    
    Implicant * combineWith(Implicant &);
    bool areEqual(Implicant &);
    short returnFirstMinterm();
    bool isPowerof2(short a);
    
};

#endif /* defined(__DigitalProject_1__Implicant__) */
