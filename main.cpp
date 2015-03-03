//
//  main.cpp
//  DigitalProject-1
//
//  Created by Ingy on 3/1/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<short> A;
    A.insert(5);
    A.insert(3);
    A.insert(8);
    
    for(short i : A)
    {
        cout << i << endl;
    }
}