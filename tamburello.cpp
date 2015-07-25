//
//  main.cpp
//  tamburello
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

int seq[MAXN];

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    
    scanInt(N);
    
    for (int i = 0; i < N; i++)
        scanInt(seq[i]);
    
    for (int p = 1; p <= N/2; p++)
    {
        if (N % p != 0) continue;
        
        int att;
        for ( att = p; att< N; att++)
        {
            if (seq[att] != seq[att%p]) break;
        }
        if (att == N)
        {
            for (int i = 0; i < p; i++)
                cout<<seq[i]<<" ";
            return 0;
        }
    }
    
    cout<<"2";
    return 0;
}

/*
 12 1 0 1 0 1 0 1 0 1 0 1 0
 
 22 1 0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 1 0 1 0 0 0

 8 1 1 0 1 1 0 1 1
 */

