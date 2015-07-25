//
//  main.cpp
//  collo di bottiglia
//
//  Created by nicomazz on 02/02/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <assert.h>
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

#define MAXN 100100
#define MAXM 1000100

static FILE *fr, *fw;

static int N, M, W, L;
static int R, C;
static int arco_da[MAXM], arco_a[MAXM], capacita[MAXM];

using namespace std;

struct arco
{
    int a, portata;
    arco(int _a, int _p){a = _a; portata = _p;}
};


typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef vector<arco> va;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;


vector<arco> grafo[MAXN];
int w,l;

bool visit[MAXN];
int limitante[MAXN];
int dist[MAXN];
void bfs()
{
    for (int i = 0; i <= MAXN; i++) limitante[i] = INT_MAX, dist[i] = INT_MAX;
    
    queue<int> coda;
    coda.push(w);
    dist[w] = 0;
    bool toccato = false;
    while (!coda.empty())
    {
        int att = coda.front();
        coda.pop();
        
        for (auto &it: grafo[att])
        {
            if (it.a == l) toccato = true;
            if (dist[it.a] > dist[att])
            {
            
                if (dist[it.a] == INT_MAX && !toccato) coda.push(it.a);
                dist[it.a] = dist[att]+1;
            
                limitante[it.a] = min(limitante[it.a], min(limitante[att],it.portata));
               // coda.push(it.a);
            }
        }
    }
}

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C)
{
    w = W; l = L;
    
    for (int i = 0; i<  M;i++)
    {
        grafo[arco_da[i]].push_back(arco(arco_a[i],capacita[i]));
        grafo[arco_a[i]].push_back(arco(arco_da[i], capacita[i]));
    }
    
    bfs();
    
    //  cout<<limitante[l];
    return limitante[l];
}
/*
 int main(){
 fr = fopen("input.txt", "r");
 fw = fopen("output.txt", "w");
 
 int i;
 assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &W, &L));
 assert(2 == fscanf(fr, "%d%d", &R, &C));
 for (i=0; i<M; i++)
 assert(3 == fscanf(fr, "%d%d%d", arco_da+i, arco_a+i, capacita+i));
 
 fprintf(fw, "%d\n", Analizza(N, M, W, L, arco_da, arco_a, capacita, R, C));
 
 fclose(fr);
 fclose(fw);
 return 0;
 }*/
