//
//  main.cpp
//  classifica
//
//  Created by nicomazz on 12/04/15.
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
#define MAXN 21

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

int squadre[MAXN];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    scanInt(N);
    
    int fino = ( N * (N-1)) / 2;
    
    int a,b,ga,gb;
    for (int i = 0; i < fino; i++ )
    {
        scanInt(a), scanInt(b),scanInt(ga),scanInt(gb);
        
        if ( ga == gb) squadre[a]++, squadre[b]++;
        else if ( ga > gb) squadre[a] += 3;
        else squadre[b] += 3;
    }
    
    int punti_max = 0, squadra_max = 0;
    
    for (int i = 1; i <= N; i++)
        if (squadre[i] > punti_max)
        {
            punti_max = squadre[i];
            squadra_max = i;
        }
    
    cout<<squadra_max<<" "<<punti_max;
    
    return 0;
}
/**
 4
 1 2 2 0
 3 4 1 1
 1 3 1 1
 2 4 0 0
 1 4 2 2
 2 3 0 0
 */

