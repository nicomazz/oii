//
//  main.cpp
//  zigzag
//
//  Created by nicomazz on 08/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <bitset>

#define maxN 100001

using namespace std;
int s[maxN];
bool zero[maxN];
bool pos[maxN];

inline void scanInt(int &x){
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
int main(int argc, const char * argv[])
{
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    scanInt(N);
    
    if (N <=2){ printf("%d",N); return 0;}
    
    int i;
    for (i = 0; i<N; i++)
        scanInt(s[i]);
    
    int sum;
    for (i = 0; i < N-1; i++)
    {
        sum = s[i]-s[i+1];
        if (sum > 0 )pos[i] = true;
        else if ( sum == 0) zero[i] = true;
    }
    
    bool att = !pos[0];
    int cnt = 1;
    
    for (i = 0; i < N-1; i++)
        if (!zero[i] && pos[i]^att)
            cnt++, att ^= true;
    
    printf("%d",cnt);
    
    return 0;
}

