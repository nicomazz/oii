//
//  main.cpp
//  domino
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
#define MAXN 11

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

struct tessera
{
    int a,b;
};
int N;
int maxLen;
tessera tessere[MAXN];
bool usate[MAXN];
void ric(int n, int prec)
{
    maxLen = max(maxLen,n);
    
    for (int i = 0; i < N; i++)
    {
        if (usate[i] == false && ((prec == -1) || tessere[i].a == prec))
        {
            usate[i] = true;
            ric(n+1, tessere[i].b);
            usate[i] = false;
        }
        if (usate[i] == false && ((prec == -1) || tessere[i].b == prec))
        {
            usate[i] = true;
            ric(n+1, tessere[i].a);
            usate[i] = false;
        }
    
    }
    
}

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    
    scanInt(N);
    
   for (int i = 0; i < N; i++)
        scanInt(tessere[i].a), scanInt(tessere[i].b);
    
    ric(0,-1);
    cout<<maxLen;
    return 0;
}
/*
 6 3 0 4 0 2 6 4 4 0 1 1 0
 */

