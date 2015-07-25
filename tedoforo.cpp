//
//  main.cpp
//  tedoforo
//
//  Created by nicomazz on 12/04/15.
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
#define MAXN 1010
#define INF 200000000
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register int c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
}

inline void scanIntNeg(int &x)
{
    register int c=getchar();
    x = 0;
    bool neg = false;
    
    while( c<48 || c>57) {if (c == '-')neg = true; c=getchar();}
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}

struct arco
{
    arco(){}
    arco(int _a,int _costo):a(_a),costo(_costo){}
    int a, costo;
};
vector<arco> grafo[MAXN];
bool visitati[MAXN];
int distanze_migliori[MAXN];

void djsk(int N)
{
    for (int i = 2; i <= N; i++)
        distanze_migliori[i] = INF;
    
    priority_queue<pii> coda; // dist, città
    
    coda.push(pii(0,1)); //
    
    while( !coda.empty())
    {
        pii att = coda.top();
        coda.pop();
        
        if (visitati[att.second]) continue;
        visitati[att.second] = true;
        
        for ( auto dest: grafo[att.second])
        {
            if (visitati[dest.a]) continue;
            distanze_migliori[dest.a] = min(distanze_migliori[dest.a], -att.first+dest.costo);
            coda.push(pii(-distanze_migliori[dest.a], dest.a));
        }
    }
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    int S;
    scanInt(N);
    scanInt(S);
    
    int da, a, tempo;
    for (int i = 0; i < S; i++)
    {
        scanInt(da); scanInt(a); scanInt(tempo);
        grafo[da].push_back(arco(a,tempo));
        grafo[a].push_back(arco(da,tempo));
    }
    
    djsk(N);
    int ris = 1;
    int * d = distanze_migliori;
    for (int i = 2; i <= N; i++)
        if ( d[i] <= i*10) ris++;
    
    cout<<ris;
        
    return 0;
}
/**
 5 6
 1 2 30
 4 3 5
 4 1 10
 2 3 10
 2 5 25
 1 3 35
 */

