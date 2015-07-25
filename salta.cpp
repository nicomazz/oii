//
//  main.cpp
//  salta
//
//  Created by nicomazz on 19/02/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

#define REP(i,d,a) for (int i = (d); i < (a); i++)

using namespace std;

int V[1000001];
int Ceck[1000001];

int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    in>>N;
    
    REP(I, 0, N)
        in>>V[I];
    
    int PosConiglio = 1;
    Ceck[1]++;
    REP(i, 0, 10000000)
    {
        PosConiglio = ((PosConiglio+V[PosConiglio-1]) % N)+1;
        Ceck[PosConiglio]++;
    }
    
    vector<int> mai;
    REP(i, 1, N+1)
    if (!Ceck[i]) mai.push_back(i);
    
    out<<mai.size()<<endl;
    REP(i, 0, mai.size())
    {
        out<<mai.at(i)<<" ";
    }
    
    return 0;
}

