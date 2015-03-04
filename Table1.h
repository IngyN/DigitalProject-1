//
//  Table1.h
//  DigitalProject-1
//
//  Created by Alia Hassan  on 3/4/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#ifndef __DigitalProject_1__Table1__
#define __DigitalProject_1__Table1__

#include "Implicant.h"
#include <string>
using namespace std;

class Table1
{
private:
    
    //which data structure? another set >> a set of implicants?
    //how do we account for the different 'levels'?
    
public:
    void traverseAndCompare();
    //function to traverse column and compare in the 'initial'
    //function to call the implicant combine function and shift implicant to 'intermediate'?
    //function to reset all combined implicants in 'intermediate' column to uncombined ie return to initial stage
    
    
};

#endif /* defined(__DigitalProject_1__Table1__) */
