//
//  main.cpp
//  messaggi
//
//  Created by nicomazz on 15/05/15.
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

#define TEST
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

map<string,vector<string> > ricevuti;
map<string,vector<string> > inviati;
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, Q;
    
    scanInt(N); scanInt(Q);
    
    string da, a;
    for (int i = 0; i < N; i++)
    {
        cin>>da>>a;
        
        ricevuti[a].push_back(da);
        inviati[da].push_back(a);
    }
    for (int i = 0; i < Q; i++)
    {
        cin>>da>>a;
        if ( a == "INVIATI")
        {
            vector<string> & v = inviati[da];
            printf("%d ",v.size());
            for (string & str:v)
                printf("%s ",str.c_str());
            printf("\n");
        }
        else
        {
            vector<string> & v = ricevuti[da];
            printf("%d ",v.size());
            for (string & str:v)
                printf("%s ",str.c_str());
            printf("\n");
        }

    }
    return 0;
}


