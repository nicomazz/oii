//
//  main.cpp
//  fulcro del gioco
//
//  Created by nicomazz on 30/03/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <queue>
#include <fstream>

using namespace std;

#define REP(i,d,a) for (int i = (d); i < (a); i++)
#define FOREACH(i,s) for (list<int>::iterator i = s.begin(); i != s.end(); i++)

list<int> nodi[13];

pair<int, int> da_togliere(0,99); // giocatore, valuta

void BFStranne(int tranne)
{
    queue<int> coda;
    coda.push(1);
    
    bool visitati[12];
    fill(visitati, visitati+12, false);
    
    int raggiungibili = 1;
    visitati[1] = true;

    while (!coda.empty())
    {
        int attuale = coda.front();
        coda.pop();
        
       
        FOREACH(i, nodi[attuale])
        {
            if (!visitati[*i] && *i != tranne)
            {
                raggiungibili++;
                coda.push(*i);
                visitati[*i] = true;
            }
        }
    }
    if (raggiungibili < da_togliere.second)
    {
        da_togliere.first = tranne;
        da_togliere.second = raggiungibili;
    }
}

int main()
{
    
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n, da, a;
    
    in>>n;
    
    REP(i, 0, n)
    {
        in>>da>>a;
        nodi[da].push_back(a);
    }
    
    REP(i, 2, 12)
        BFStranne(i);
    
    out<<da_togliere.first;
    
    return 0;
}

