//
//  main.cpp
//  turni
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
#define MAXN 60

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

pii turni[MAXN];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int G,N;
    
    scanInt(G); scanInt(N);
    
    for (int i = 0; i < N; i++)
        scanInt(turni[i].first), scanInt(turni[i].second);
    
    sort(turni,turni+N);
    
    int g_Att = -1;
    int p_att = 0;
    int fino = 0;
    int ris = 0;
    
    while (g_Att < G-1)
    {
        while (p_att < N && turni[p_att].first <= g_Att+1)
        {
            fino = max(fino,turni[p_att].second);
            p_att++;
        }
        ris++;
        g_Att = fino;
        fino = 0;
    }
    cout<<ris;
    return 0;
}

/*
 8 5 3 5 0 2 1 3 5 6 4 7
 10 6 2  5 0 2 1 3 5 6 4 7 7 9
 */
