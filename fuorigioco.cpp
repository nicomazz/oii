//
//  main.cpp
//  fuorigioco
//
//  Created by nicomazz on 30/03/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,d,a) for (int i = (d); i < (a); i++)


vector<int> attaccanti;
vector<int> difensori;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int d, A, D;
    
    in>>d>>A>>D;
    
    int tmp, Yi, Yf;
    int YFinale;
    REP(i, 0, A)
    {
        in>>tmp>>Yi>>tmp>>Yf;
        YFinale =  (float)(Yf*d-Yi*d)/10 + Yi;
        attaccanti.push_back(int(YFinale));
    }
    REP(i, 0, D)
    {
        in>>tmp>>Yi>>tmp>>Yf;
        YFinale = (float)(Yf*d-Yi*d)/10 + Yi;
        difensori.push_back(int(YFinale));
    }
    
    sort(difensori.begin(), difensori.end());
    sort(attaccanti.begin(), attaccanti.end());
    
    if (attaccanti[0] < difensori[0]) out<<"F";
    else out<<"R";
    
    return 0;
}

