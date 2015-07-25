//
//  main.cpp
//  labirinto 2
//
//  Created by nicomazz on 14/06/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <set>

#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;


char mat[101][101];
int matSup[101][101];
bool visitate[101][101];
int r,c;

int Sx[] = {1,0};
int Sy[] = {0,1};

int visita()
{
    queue<pii> coda;
    coda.push(pii(0,0));
    matSup[0][0]  = 1;
    
    while (!coda.empty())
    {
    
        pii attuale = coda.front();
        coda.pop();
        if (visitate[attuale.f][attuale.s]) continue;
        else visitate[attuale.f][attuale.s] = true;
        
        for (int i = 0; i < 2; i++)
            if (attuale.f+Sx[i] < r && attuale.s+Sy[i] < c && mat[attuale.f+Sx[i]][attuale.s+Sy[i]] != '+')
            {
                matSup[attuale.f+Sx[i]][attuale.s+Sy[i]] += matSup[attuale.f ][attuale.s];
                coda.push(pii(attuale.f+Sx[i],attuale.s+Sy[i]));
            }
    }
    
    return matSup[r-1][c-1];
}

int main(int argc, const char * argv[])
{

    ifstream in("input.txt");
    ofstream out("output.txt");
  
    in>>r>>c;
    
    for(int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            in>>mat[i][j];
    
    out<<visita();
    
    return 0;
}

