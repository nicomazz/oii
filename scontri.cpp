//
//  main.cpp
//  scontri
//
//  Created by nicomazz on 03/06/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//


#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <bitset>

using namespace std;

#define TEST
#define MAXN 100010

typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define iOS ios_base::sync_with_stdio(false)
#define error(x) cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#define gc getchar // getchar_unlocked

inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    bool neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}
#define pc(x) putchar_unlocked(x);
inline void writeInt (int n)
{
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); pc('\n'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}
int *fr;
int dp[MAXN];
int n;
int sum_cum[MAXN];
int sx_da_a(int da, int a)
{
    return sum_cum[a+1]-sum_cum[da];
}
int dx_da_a(int da, int a)
{
    //cout<<"sum da "<<da<<" a "<<a<< " = "<<sum_cum[a+1]-sum_cum[da]<<endl;

    return (a-da+1) - (sum_cum[a+1]-sum_cum[da]);
}
int f(int rim)
{
    if (!rim) return 0;
    
    int & ris = dp[rim];
    if ( ris != -1) return ris;
    ris = 2e8;
    
    int iniz = n-rim;
    for (int i = 2; i <= rim; i+=2)
    {
        int no = 0;
        no +=  sx_da_a(iniz, iniz+i/2 - 1);
        no +=  dx_da_a(iniz+i/2,iniz+i-1);
    //    cout<<"rim: "<<rim<<" i: "<<i<<" no: "<<no<<endl;
       /* for ( int dx = iniz; dx < iniz+i/2; dx++)
            if ( fr[dx] != 0) no++;
        for ( int sx = iniz+i/2; sx < iniz+i; sx++)
            if ( fr[sx] != 1) no++;*/
        smin(ris, no+f(rim-i));
    }
    return ris;
}
int Gira(int N, int *freccia)
{
    fr = freccia;
    n = N;
    memset(dp,-1,sizeof(dp));
    partial_sum(freccia, freccia+N, sum_cum+1);
    //for (int i = 0;i < N;i ++)
      //  cout<<sx_da_a(0, i)
    return f(N);
}
/*
int origin[MAXN];
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N;
    
    scanInt(N);
    int da, a, l;
    for (int i = 0; i < N; i++)
        scanInt(origin[i]);
    
    cout<<Gira(N, origin);
    return 0;
}*/
