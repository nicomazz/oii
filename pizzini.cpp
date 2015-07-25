//
//  main.cpp
//  pizzini
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
#include <map>

using namespace std;

//#define TEST
#define MAXN 101

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

string originali[MAXN];
map<string,int> anagrammi;

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    
    scanInt(N);
    
    for(int i = 0; i < N;i++)
    {
        cin>>originali[i];
        string tmp = originali[i];
        sort(tmp.begin(), tmp.end());
        anagrammi[tmp]++;
    }
    
    for (int i = 0; i < N; i++)
    {
        string tmp = originali[i];
        //cout<<"tmp: "<<tmp<<endl;
        sort(tmp.begin(), tmp.end());
        
        cout<<originali[i][anagrammi[tmp]-1];
    }
    
    return 0;
    
}
/*
 6 1949 21 9419 12 4356373 9149
 */
