//
//  main.cpp
//  somme di sequenze
//
//  Created by nicomazz on 03/03/15.
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
#define MAXN 510

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

int numeri[MAXN];
int dp[MAXN][MAXN];
int somme[MAXN];

int sum_da_a(int da, int a)
{
    return somme[a+1]-somme[da];
}
int f(int da, int a)
{
    
    if (da == a) return 0;//numeri[da];
    if (a == da+1) return abs(numeri[da]+numeri[a]);
    
    if (dp[da][a] != -1) return dp[da][a];
    
    int minimo = 2000000000;
    
    int sum = sum_da_a(da, a);
    for (int i = da; i < a; i++)
        minimo = min(minimo, max(max( f(da,i),f(i+1,a)),abs(sum)));//abs( sum_da_a(da,  a) )));
    
    return dp[da][a] = minimo;
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    scanInt(N);
    for (int i = 0; i < N; i++)
        scanIntNeg(numeri[i]);
    memset(dp, -1, sizeof dp);
    
    somme[1] = numeri[0];
    for (int i = 1; i < N; i++)
        somme[i+1] = somme[i]+numeri[i];
    
    cout<<f(0,N-1);

    
 /*   for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            cout<<"da: "<<i<<" a "<<j<<"  "<<f(i,j)<<endl;
   */
    return 0;
}
/*
 4 4 7 -9 8
 5 4 7 -9 8 -10
 6 11 -4 52 -7 -2 -20
 */

