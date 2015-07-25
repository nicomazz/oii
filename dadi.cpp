//
//  main.cpp
//  dadi
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


int dado[4][3] = {
    {0, 6, 0},
    {0, 5, 0},
    {4, 1, 3},
    {0, 2, 0}};

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    scanInt(N);
    
    string comandi;
    cin>>comandi;
    
    for (int i = 0; i < comandi.size();i++)
    {
        if (comandi[i] == 'T')
            cout<<dado[2][1]<<" ";
        else if (comandi[i] == 'F')
            cout<<dado[3][1]<<" ";
        else if (comandi[i] == 'R')
            cout<<dado[2][2]<<" ";
            
        else if (comandi[i] == 'X')
        {
            int tmp = dado[3][1];
            dado[3][1] = dado[2][1];
            dado[2][1] = dado[1][1];
            dado[1][1] = dado[0][1];
            dado[0][1] = tmp;
        }
        
        else if (comandi[i] == 'Y')
        {
            int tmp = dado[2][0];
            dado[2][0] = dado[2][1];
            dado[2][1] = dado[2][2];
            dado[2][2] = dado[0][1];
            dado[0][1] = tmp;
        }
        else if (comandi[i] == 'Z')
        {
            int tmp = dado[1][1];
            dado[1][1] = dado[2][2];
            dado[2][2] = dado[3][1];
            dado[3][1] = dado[2][0];
            dado[2][0] = tmp;
        }
    }
    
    return 0;
}
//  10 TZZYXFRTXR
// 9 XYYTZFXFR
// 1  XTFRXXXYTFRYYYZTFR

