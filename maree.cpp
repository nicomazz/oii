//
//  main.cpp
//  maree a venezia
//
//  Created by nicomazz on 29/01/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>


using namespace std;

#define MAXN 200010

typedef pair<int, int> pii;
typedef vector<int> vii;
typedef long long ll;
#define MAXM 3000000



vii grafo_dritto[MAXN];

#define inf 2000000000
int minimo_percorso = inf;
int arrivi_dritti[MAXN];
bool visitati[MAXN];
bool vis_ritorno[MAXN];
int Tempo;

pii coda[MAXN*4];
ll C_front, C_push;

#define push(x) coda[C_push++] = x
#define empty() (C_front != C_push)
#define front() coda[C_front++]

void bfs_andata(int partenza, int* arrivi)
{
    push(pii(partenza,0)); // parte dal nodo 0, con dist 0
    pii att;
    while (empty()) {
        att = front();
        arrivi[att.first] = att.second;
        for (int i = 0; i<  grafo_dritto[att.first].size(); i++)
            if (att.second < Tempo && !visitati[grafo_dritto[att.first][i]])
            {
                push(pii(grafo_dritto[att.first][i],att.second+1)); // nodo nuovo
                visitati[grafo_dritto[att.first][i]]  = true;
            }

    }
}

void bfs_ritorno(int partenza)
{
    C_front = C_push = 0;
    
    push(pii(partenza,0)); // parte dal nodo 0, con dist 0
    pii att;
    while (empty()) {
         att = front();
        if (arrivi_dritti[att.first] < inf)
            minimo_percorso = min(Tempo+att.second,minimo_percorso);
        for (int i = 0; i<  grafo_dritto[att.first].size(); i++)
            if (!vis_ritorno[grafo_dritto[att.first][i]])
            {
                vis_ritorno[grafo_dritto[att.first][i]] = true;
                push(pii(grafo_dritto[att.first][i],att.second+1)); // nodo nuovo
            }
    }
}


int solve(int N, int M, int T, int* S, int* E) {
    
    Tempo = T;
    
    for (int i = 0; i< M; i++)
        grafo_dritto[S[i]].push_back(E[i]);
    
    for (int i = 0;i  < N; i++) arrivi_dritti[i] = inf;
    
    bfs_andata(0,arrivi_dritti);
    if (arrivi_dritti[N-1] <= T)
        return arrivi_dritti[N-1];
    bfs_ritorno(N-1);
    
    if (minimo_percorso == inf) return -1;


    return minimo_percorso;
}

/*
int main(int argc, const char * argv[])
{

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    assert(3 == fscanf(fin, "%d%d%d", &N, &M, &T));
    for(i=0; i<M; i++) assert(2 == fscanf(fin, "%d%d", S+i, E+i));
    cout<<solve(N, M, T, S, E);
    fprintf(fout, "%d\n", solve(N, M, T, S, E));
    fclose(fin);
    fclose(fout);
    return 0;
}*/
