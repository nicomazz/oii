//
//  main.cpp
//  missioni
//
//  Created by nicomazz on 04/04/15.
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
#define MAXN 101

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

struct missione
{
    int giorni,scadenza;
    missione(){}
    missione(int _g, int _s):giorni(_g),scadenza(_s){}
};

missione missioni[MAXN];
int dp[367];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    
    scanInt(N);
    
    int g, s;
    for (int i = 0; i < N; i++)
    {
        scanInt(g); scanInt(s);
        missioni[i] = missione(g,s);
    }
    for (int i = 0; i < N; i++) // per ogni missione
        for (int j = missioni[i].scadenza-missioni[i].giorni;  j >= 0; j--)
                dp[j+missioni[i].giorni] = max(dp[j+missioni[i].giorni], dp[j]+1);
    
    int massimo = *max_element(dp, dp+366);
   // for (int i = 0; i < 13; i++) cout<<dp[i]<<" ";
    
    cout<<massimo;
    
    return 0;
}


