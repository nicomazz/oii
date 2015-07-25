//
//  main.cpp
//  depura
//
//  Created by nicomazz on 13/04/15.
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

bool presenti[MAXN];
vector<int> necessarie[MAXN];
int inserisci(int N)
{
    if (presenti[N] == true) return 0;
    
    int cnt = 1;
    if (necessarie[N].size() == 0) return -1;
    for (auto i:necessarie[N])
    {
        if (presenti[i]) continue;
        
        int n = inserisci(i);
        if (n == -1) return -1;
        else cnt+=n;
    }
    presenti[N] = true;
    return cnt;
}

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int K,R;
    
    scanInt(K); scanInt(R);
    
    int pres;
    for (int i = 0; i < K;i++)
    {
        scanInt(pres); presenti[pres] = true;
    }
    
    int s, q;
    for (int i = 0; i < R; i++)
    {
        scanInt(s); scanInt(q);
        while (q--)
        {
            scanInt(pres);
            necessarie[s].push_back(pres);
        }
    }
    cout<<inserisci(1);
    return 0;
}
/*
 2 4 2 3 4 1 2 5 2 2 3 7 2 2 4 1 3 3 7 4
 
 4 2 6 2 8 3 5 2 2 6 1 2 3 6
 
 2 3 1 3 4 1 2 5 1 3 6 2 2 4
 
 3 4 2 4 8 5 2 2 4 7 2 4 3 6 2 5 7 1 3 5 2 6
 */

