//
//  main.cpp
//  matita
//
//  Created by nicomazz on 06/01/15.
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
#define MAXN 100010
#define MAXM 1000010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef pair<int, bool*> pib; // arrivo, usato
typedef pair<int, pib> piib;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;


inline void scanInt(int &x)
{
    register char  c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int N, M,A,B; // veritci, archi, partenza arrivo
vector<pib> *grafo;//[MAXN];

int sol[MAXM];
int indSol;
bool *archiUsati;

pib v;

void EulerTour(int u) {
    int sz =(int)grafo[u].size();
    for (int j = 0; j < sz; j++)
    {
        v = grafo[u][j];
        if (*(v.second) == false)
            *(v.second) = true,EulerTour(v.first);
        
    }
    sol[indSol++] = u;
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    scanInt(N); scanInt(M);scanInt(A); scanInt(B);
    
    archiUsati = new bool[M+10];
    grafo = new vector<pib>[N+2];
    memset(archiUsati, 0, sizeof(bool)*(M+10));
    
    int da, a;
    for (int i = 0; i < M; i++)
    {
        scanInt(da); scanInt(a);
        grafo[da].push_back(pib(a,&archiUsati[i]));
        grafo[a].push_back(pib(da,&archiUsati[i]));
    }
    grafo[B].push_back(pib(N+1,&archiUsati[M+1])); // dummy
    
    EulerTour( A);
    
    printf("%d ",sol[indSol-1]);
    for (int i = indSol-2; i >1;i--) printf("%d\n%d ",sol[i],sol[i]);
    cout<<sol[1]<<endl;

    
    return 0;
}

