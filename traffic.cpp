//
//  main.cpp
//  traffic congestion
//
//  Created by nicomazz on 11/01/15.
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

//#define TEST
#define MAXN 1000010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
vector<pii> strade[MAXN];
int persone[MAXN];
int minima_congestione = INT_MAX;
int trova_congestione(int partenza,int padre, pii &arco)
{
    if (arco.second != -1) return arco.second;
    int somma = persone[partenza];
    for (int i = 0; i< strade[partenza].size();i++)
        if (strade[partenza][i].first != padre)
            somma+= trova_congestione(strade[partenza][i].first, partenza,strade[partenza][i]);
    return arco.second = somma;
}
int congestione_massima(int nodo)
{
    int massimo = -1;
    for (int i = 0; i< strade[nodo].size();i++)
        massimo = max(massimo,trova_congestione(strade[nodo][i].first, nodo,strade[nodo][i]));//strade[nodo][i].second);
    return massimo;
}
int main()
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int N;
    scanInt(N);
    for (int i = 0; i < N; i++)
        scanInt(persone[i]);
    int da,a;
    for (int i = 1; i < N; i++)
    {
        scanInt(da); scanInt(a);
        strade[da].push_back(pii(a,-1));
        strade[a].push_back(pii(da,-1));
    }
    for (int i = 0; i<  N; i++)
        minima_congestione = min(minima_congestione,congestione_massima(i));
    printf("%d",minima_congestione);
    
    return 0;
}

