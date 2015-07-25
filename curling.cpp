//
//  main.cpp
//  curling
//
//  Created by nicomazz on 31/05/15.
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
#define MAXN 2010

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
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}


vii succ, best_succ;
int best_len;
int from_best;
bool visited[MAXN];
int partenza;
vii graph[MAXN];
int N;


bool dfs(int att, int dist, int stop_at = -1)
{
    if ( dist == stop_at) {succ[att] = -1; return true;}
    
    visited[att] = true;
    
    bool almeno_uno = false;
    for ( int vicino: graph[att])
    {
        if ( !visited[vicino]){
            succ[att] = vicino;
            if (dfs(vicino, dist+1, stop_at)) {
                visited[vicino] = false;
                return true;}
            almeno_uno = true;
            visited[vicino] = false;

        }
    }
    if (almeno_uno == false && dist > best_len) {
        best_len = dist;
        from_best = partenza;
        if ( dist == N) return true;
    }
    return false;
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    scanInt(N);
    succ.resize(N+1), best_succ.resize(N+1);
    int da, a;
    int fino = (N*(N-1))/2;
    while ( fino--)
    {
        scanInt(da); scanInt(a);
        graph[da].push_back(a);
    }
    
    for (int i = 1; i <=N; i++)
    {
        visited[i-1] = false;
        if (dfs(partenza = i, 1)) break;;
    }
    
    dfs(from_best,1,best_len);
    
    writeInt(best_len-1);
    printf("\n");
    int att = from_best;
    while ( succ[att] != -1)
    {
        writeInt(att); printf(" "); writeInt(succ[att]);
        printf("\n");
        att = succ[att];
    }
    
    return 0;
}

/**
 3 
 1 2 
 3 2
 1 3
 */
