//
//  main.cpp
//  cannoniere
//
//  Created by nicomazz on 30/03/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>

#define REP(i,d,a) for (int i = (d); i < (a); i++)

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,g,r;
    in>>n;
    
    map<int,int> mappa;
    
    REP(i, 0, n)
    {
        in>>g>>r;
        mappa[g] += r;
    }
    
    pair<int,int> max(0,0);

    
    for (map<int, int>::iterator it = mappa.begin(); it != mappa.end(); it++)
        if (it->second > max.second)max = *it;
    
    out<<max.first<<" "<<max.second;
    

   
    return 0;
}

