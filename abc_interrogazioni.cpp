//
//  main.cpp
//  interrogazioni
//
//  Created by nicomazz on 27/05/15.
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
#define MAXN 200010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
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

int max_C;
int fen[int(1e7)+10];
void update(int k)
{
    for (int i = k; i <= max_C; i+= (i&(-i))) fen[i]++;
}
int get(int k)
{
    int cnt = 0;
    for (int i = k; i > 0; i-= (i&(-i))) cnt+= fen[i];
    return cnt;
}
int query(int da, int a)
{
    return get(a)-get(da-1);
}

int stud[MAXN];
int stud_ord[MAXN];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    scanInt(N);
    
    for (int i = 0; i < N; i++)
        scanInt(stud[i]), stud_ord[i] = stud[i], max_C = max(max_C,stud[i]);

    sort(stud_ord,stud_ord+N);
    ull risp = 0;
    for (int i = 0; i < N; i++)
    {
        int pos_new = lower_bound(stud_ord, stud_ord+N, stud[i]) - stud_ord;
        risp += (N-i-1) - ((N-pos_new-1) - query(stud[i],max_C));
     //   cout<<"pos_new: "<<pos_new<<" risp: "<<risp<<endl;
        update(stud[i]);
    }
    cout<<risp;
    return 0;
}


