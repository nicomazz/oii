//
//  main.cpp
//  salti
//
//  Created by nicomazz on 05/03/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>

#define REP(i,d,a) for (int i = (d); i < (a); i++)


using namespace std;

typedef unsigned long long ll;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    ll D;
    
    in>>D;
    
    int cnt = 0;

    while (D)
    {
        if (D%2 != 0) cnt++;
        D/=2;
    }

    out<<cnt;
    
    return 0;
}

