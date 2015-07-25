//
//  main.cpp
//  grandprix
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


int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, S;
    
    scanInt(N); scanInt(S);
    
    int primo;
    scanInt(primo);
    int tmp;
    for (int i = 1; i < N;i++) scanInt(tmp);
    
    int da, a;
    for (int i = 0; i < S; i++)
    {
        scanInt(da); scanInt(a);
        if (a == primo) primo = da;
    }
    cout<<primo;
    return 0;
}

/*
 3 4 2 1 3 3  1 3 2 1 2 2 1
 */
