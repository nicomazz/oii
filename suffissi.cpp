//
//  main.cpp
//  suffisi
//
//  Created by nicomazz on 06/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <map>
#include <set>


using namespace std;

#define MAXN 100001
#define MAXM MAXN
#define MAXNUM 100001


int n,m;
int ai[MAXN];
int parziali[MAXN];
int query[MAXM];
set<int> ins;

inline void scanInt(int& x)
{
    register char c = getchar_unlocked();
    x = 0;
    for(; (c<48)||(c>57);c = getchar_unlocked());
    for(; (c>47)&&(c<58);c = getchar_unlocked())
        x = (int)((((x)<<1) + ((x)<<3)) + c - 48);
}

void costruisci()
{
    for (int i = n; i > 0; i--)
    {
        ins.insert(ai[i]);
        parziali[i] = ins.size();
    }
}

int main(int argc, const char * argv[])
{
    scanInt( n); scanInt( m);
    for (int i = 1; i <= n; i++)
        scanInt(ai[i]);
    
    int tmp;
    costruisci();
    for (int i = 0; i < m; i++)
    {
        scanInt(query[i]);
    }
    for (int i = 0; i < m; i++)
        printf("%d\n",parziali[query[i]]);
    
    return 0;
}

