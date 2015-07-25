//
//  main.cpp
//  medaglie
//
//  Created by nicomazz on 09/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAXN 100001

inline void scanInt(int &x){
    register int c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
}


typedef pair<int,short> pii;

pii dp[MAXN];
int v[MAXN];
int N;

int main(int argc, const char * argv[])
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanInt(N);
    for (int i = 0; i < N; i++)
    {
        scanInt(v[i]);
        if (v[i] == 0) v[i] = 1;
        else if (v[i] == 1) v[i] = 3;
        else v[i] = 5;
    }
    
    dp[0] = pii(v[0],1);
    dp[1] = pii(v[1]+dp[0].first,2);
    dp[2] = pii(v[2]+dp[1].first,3);
    
    int tmp,ind,att,r;
    pii massimo;
    for (int i = 3; i < N; i++)
    {
        tmp = 0;
        massimo = pii(0,0);
        for (r = 0; r < 3; r++)
        {
            tmp+=v[i-r];
            ind =i-r-1-dp[i-r-1].second;
            att = tmp;
            if (ind >= 0) att += dp[ind].first;
            if (att > massimo.first)
                massimo = pii(att,r+1);
        }
        dp[i] = massimo;
    }
    cout<<dp[N-1].first*100;
    
    return 0;
}

