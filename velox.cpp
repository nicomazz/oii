//
//  main.cpp
//  velox
//
//  Created by nicomazz on 30/01/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <iostream>

using namespace std;
#include <stdio.h>
#include <assert.h>
#include <vector>
#include <stack>
#include <algorithm>


inline void scanInt(int &x)
{
    register char c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
}

#define MAXM 100000
#define MAXN 10010
struct arco
{
    int a, vel, dist;
    arco(int _a,int _vel){a = _a; vel = _vel; dist = -1;}
};

vector<arco> grafo[MAXN];

int l_max = 1;
int N_vertici;

int attuale = 1;


int trova_dist_max(arco &att, int cnt)
{
    if (att.dist != -1) return att.dist;
    
    int massimo = 0;
    for (vector<arco>::iterator i = grafo[att.a].begin() ; i != grafo[att.a].end(); i++)
    {
        if (i->vel > att.vel)
            massimo = max(massimo,trova_dist_max(*i, cnt+1));
    }
    return att.dist = massimo+1;
}

int accelera(int N, int M, int da[], int a[], int V[]) {
    N_vertici = N;
    for (int i = 0; i < M; i++)
        grafo[da[i]].push_back(arco(a[i],V[i]));
    
    
    int dist_max = 0;
    for (int i = 0; i < N; i++)
        for (int j =0 ; j < grafo[i].size();j++)
            dist_max = max(dist_max,trova_dist_max(grafo[i][j], 1));
        
//    cerr<<dist_max;
    return dist_max;
}


int da[MAXM], a[MAXM], V[MAXM];

int main() {
    int N,M;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanInt(N), scanInt(M);
    for(int i=0; i<M; i++)
        scanInt(da[i]),scanInt(a[i]),scanInt(V[i]);
    
    
    cout<<accelera(N, M, da, a, V);
    return 0;
}
