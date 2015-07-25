//
//  main.cpp
//  convoglio
//
//  Created by nicomazz on 25/06/15.
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

//#define TEST
#define MAXN 100100
#define off  100010

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

#define gc  getchar_unlocked

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

bool visited[MAXN*2+100];
vi adj1[MAXN*2];
int N, M;

int scritti[MAXN];

short find_Cycle(int start)
{
    if ( visited[start])
    
        return ( start < off);
    visited[start] = true;
    short ris;
    for (int adj: adj1[start]){
        
        ris = find_Cycle(adj);
        
        if ( ris == 1 && adj < off)
        {
            if ( scritti[adj] == -1)
                scritti[adj] = start;
            else
                return 2;
        }
            
        if (ris != 0) return ris;
    }
    visited[start] = false;
    return 0;
}

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    memset(scritti, -1, sizeof scritti);
    scanInt(N); scanInt(M);
    if (M < N+2) {cout<<-1; return 0;}
    int da, a;
    for (int i = 0; i < N; i++)
    {
        scanInt(da); scanInt(a);
        
            adj1[da].push_back(a+off);
    }
    int rim = M - N;
    for (int i = 0; i < rim; i++){
        scanInt(da); scanInt(a);
        adj1[a+off].push_back(da);
    }
    for (int i = 0; i < N; i++){
        if ( find_Cycle(i))
        {
            for (int j = 0; j < N; j++)
            {
                if ( scritti[j] == -1) {
                    scritti[j] = adj1[j][0];
                }
            
                writeInt(j); pc(' '); writeInt(scritti[j]-off); pc('\n');
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}
/**
  3 6
 0 2
 1 0
 2 1
 0 0
 1 2 
 2 2
 */
