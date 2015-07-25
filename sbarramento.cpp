//
//  main.cpp
//  sbarramento
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
#define MAXN 501

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


struct arm
{
    int r,c;
    bool operator<(const arm & b)const
    {
        if (c != b.c) return c < b.c;
        return r < b.r;
    }
};
#define dist(r1,c1,r2,c2) (abs( r2-r1) + abs(c2-c1))
arm armate[MAXN];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, R;
    
    scanInt(N); scanInt(R);
    
    int da, a, rosso;
    for (int i = 0;i < N; i++)
        scanInt(armate[i].r), scanInt(armate[i].c);
    
    sort(armate, armate+N);
    
    int ris = 0;
    for (int i = 0; i < N; i++)
        ris+= dist(armate[i].r,armate[i].c,R,i+1);
    
    cout<<ris;
    
    
    return 0;
}

/*
 8 3 5 5 1 6 2 2 6 5 3 2 7 1 1 2 8 1
 
 8 5 5 7 5 2 5 3 5 6 5 1 5 8 5 5 5 4
 */
