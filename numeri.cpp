//
//  main.cpp
//  numeri antipatici
//
//  Created by nicomazz on 30/05/15.
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
#define MAXN 1000200

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef  long long ll;

inline void scanInt(ll &x)
{
    register char c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
}

ll cum[MAXN];
ll X, N;
inline ll sum(int from, int to) {
    return cum[to]-cum[from-1];
}

int ind(int from, int to, bool lower)
{
    int a = from, b = to;
    int risp = -1;
    
    while ( a <= b)
    {
        int mid = (a+b)/2;
        ll sum_att = sum(from,mid);
        if (sum_att == X)
        {
            risp = mid;
            if (lower)
                b = mid-1;
            else
                a = mid+1;
        }
        else if (sum_att < X)
            a = mid+1;
        else
            b = mid-1;
    }
    return risp;
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


    
    scanInt(X); scanInt(N);
    
    scanInt(cum[1]);
    ll att;
    for (int i = 1; i < N; i++)
    {
        scanInt(att);
        cum[i+1] = (ll) cum[i]+att;
    }
    //for (int i = 0; i < N+1; i++) cout<<cum[i]<<" ";
    ll risp = 0;
    for (int i = 1; i <= N; i++)
    {
        int l = ind(i,N,true);
        int h = ind(i,N,false);
       // cout<<i-1<<" :  "<<"l: "<<l<<" h: "<<h<<" aggiungo: "<<h-l<<"\n";
        if ( l != -1)
        risp+= h-l+1;

    }
    cout<<risp;
    return 0;
}


