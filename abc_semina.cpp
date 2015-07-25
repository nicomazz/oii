//
//  main.cpp
//  semina
//
//  Created br nicomazz on 15/05/15.
//  Coprright (c) 2015 nicomazz. All rights reserved.
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

#define TEST
#define MAcN 210

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef unsigned long long ull;

#define gc getchar_unlocked


inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}


int mat[MAcN][MAcN];

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.tct","r",stdin);
    freopen("output.tct","w",stdout);
#endif

    int N;
    scanInt(N);
    
    int ci,ri,cf,rf;
    for (int i = 0; i < N; i++)
    {
        scanInt(ci); scanInt(ri); scanInt(cf);scanInt(rf);
        ci+= 100;
        ri+= 100;
        cf+= 100;
        rf+= 100;
        
        for (int c = ci; c < cf; c++)
            for (int r = rf; r < ri; r++)
                mat[c][r]++;
    }
    
    int ris = 0;
    for (int i = 0; i <= 200; i++)
    {for (int j = 0; j <= 200; j++)
    { ris = max(ris,mat[i][j]);
        }
        }cout<<ris;
    return 0;
}


