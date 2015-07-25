//
//  main.cpp
//  trasporti pericolosi
//
//  Created by nicomazz on 03/06/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//


#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <bitset>

using namespace std;

#define TEST
#define MAXN 100010

typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

#define iOS ios_base::sync_with_stdio(false)
#define error(x) cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()
#define pb push_back
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#define gc getchar // getchar_unlocked
#define LOG_ 19
inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}


vi graph[MAXN];
int deep[MAXN];
int parent[MAXN][LOG_];
int max_parent[MAXN][LOG_];
int *br;
void dfs(int att, int d = 1)
{
    deep[att] = d;
    max_parent[att][0] = br[att];
    for (int figlio: graph[att])
        if ( figlio != parent[att][0])
        {
            parent[figlio][0] = att;
            dfs(figlio,d+1);
        }
}
void go_up(int & a, int liv)
{
    for (int i = 0; i < LOG_; i++)
        if ( liv & (1<<i))
            a = parent[a][i];
}
int max_da_per(int a, int liv)
{
    int risp = br[a];
    if (liv == 0) return risp;
    for (int i = 0; i < LOG_; i++)
        if ( liv & (1<<i))
        {
            smax( risp,  max_parent[a][i]);
            a = parent[a][i];
        }
    return risp;
}
int lca(int a, int b)
{
    if ( a == 0 || b == 0) return 0;
    
    go_up(a, deep[a]-deep[b]);
    if ( a == b) return a;
    for (int i = LOG_; i >= 0; i--)
        if (deep[a]- (1<<i) >= 0 &&  parent[a][i] != parent[b][i])
            a = parent[a][i], b = parent[b][i];
    a = parent[a][0];
    
    return a;
    
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol){
	
    br = briganti;
    for (int i = 0; i < N-1; i++)
    {
        graph[A[i]].pb(B[i]);
        graph[B[i]].pb(A[i]);
    }
    dfs(0);
    for (int pot = 1; pot < LOG_; pot++)
        for (int n = 0; n < N; n++)
            if ( deep[n] - (1<<pot) >= 0)
                parent[n][pot] = parent[parent[n][pot-1]][pot-1];
    
    for (int pot = 1; pot < LOG_; pot++)
        for (int n = 0; n < N; n++)
            if ( deep[n] - (1<<pot) >= 0)
                max_parent[n][pot] = max(max_parent[n][pot-1], max_parent[parent[n][pot-1]][pot-1]);
    
    int a,b, LCA;
    for (int i = 0; i < Q; i++)
    {
         a = start[i], b = end[i];
        if ( a == b) {sol[i] = briganti[a]; continue;}
        if ( deep[a] < deep[b]) swap(a,b);
        LCA = lca(a,b);
        int max_da_A =max_da_per(a, deep[a]-deep[LCA]);
        int max_da_B =max_da_per(b, deep[b]-deep[LCA]);
        sol[i] = max(br[LCA],max(max_da_A,max_da_B));
    }


}
/**
 9 6
 100 50 50 25 25 25 25 12 12
 0 1 
 0 2
 1 3
 1 4
 2 5
 2 6
 4 7
 4 8
 
 3 8
 3 4
 3 2
 7 0
 7 6
 2 3
 
 5 3
 1 3 7 24 1
 0 1
 1 2
 2 3
 3 4
 
 0 4
 3 0
 0 2

 */
/*
int brig[MAXN];
int start[MAXN];
int e[MAXN];
int a[MAXN];
int b[MAXN];
int sol[MAXN];

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, Q;
    
    scanInt(N), scanInt(Q);
    for (int i = 0; i < N; i++) scanInt(brig[i]);
    for (int i = 0; i < N-1; i++)
    {
        scanInt(a[i]); scanInt(b[i]);
    }
    for (int i = 0; i < Q; i++)
        scanInt(start[i]),scanInt(e[i]);
    
    solve(N, Q, brig, a, b, start, e, sol);
    
    for (int i = 0; i < Q; i++) cout<<sol[i]<<" ";
    return 0;
}*/
