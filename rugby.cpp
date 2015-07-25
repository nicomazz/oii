//
//  main.cpp
//  rugby
//
//  Created by nicomazz on 29/05/15.
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
#define MAXN 10010

vector<int> t[MAXN];
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

int bravura[MAXN];

int f(int att)
{
    if (t[att].size() == 0) return bravura[att];
    
    int sum = 0;
    for( int figli: t[att]) sum+= f(figli);
    
    return max(sum,bravura[att]);
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;scanInt(N);
    int b, c;
    scanInt(b); scanInt(c);
    bravura[0] = b;
    for (int i = 1; i < N; i++)
    {
        scanInt(bravura[i]);scanInt(c);
        t[c].push_back(i);
    }
    cout<<f(0);
    
    return 0;
}


