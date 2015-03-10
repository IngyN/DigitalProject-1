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
#include <vector>
using namespace std;

class Table1
{
private:
    
    vector <vector<Implicant>> initial;
    vector <vector<Implicant>> intermediate;
    vector <vector<Implicant>> final;
    bool done;
    
    //which data structure? another set >> a set of implicants?
    // I don't think we should use a set for the sake of being able to retrieve and  access elements freely
    //how do we account for the different 'levels'?
    // 2D structure: the first index represents the number of ones
    
public:
    Table1();
    ~Table1();
    void insert (short);
    void traverseAndCompare();
    bool combine(short index, bool initial);
    bool implicantDoesNotExist(short index, const Implicant &, bool initial);
    void putInFinal (short, bool);
    
    void display(vector<vector<Implicant>> & toDisplay);
    //function to traverse column and compare in the 'initial'
    //function to call the implicant combine function and shift implicant to 'intermediate'?
    //function to reset all combined implicants in 'intermediate' column to uncombined ie return to initial stage
    
    
};

#endif /* defined(__DigitalProject_1__Table1__) */
