//
//  main.cpp
//  borse
//
//  Created by nicomazz on 06/06/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partizioni[1000];
int N;
ofstream out("output.txt");

void sampa(int qnt)
{
    for (int i = 1; i < qnt; i++)
        out<<partizioni[i]<<" ";
    out<<endl;
}
void sol(int assegnabili, int pos)
{
    if (assegnabili == 0)
    {
        sampa(pos);
        return;
    }
    
    int alMassimo = partizioni[pos-1];
    
    int distribuibili = min(alMassimo, assegnabili);
    
    for (int i = 1; i <= distribuibili; i++)
    {
        partizioni[pos] = i;
        sol(assegnabili-i, pos+1);
    }
}

int main()
{
    ifstream in("input.txt");
    in>>N;
    
    partizioni[0] = N;
    
    sol(N,1);
    
    return 0;
}