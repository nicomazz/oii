//
//  main.cpp
//  talmart
//
//  Created by nicomazz on 12/06/15.
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

#define gc  getchar_unlocked

inline void scanInt(int &x)
{
    register char c=gc();
    x = 0;
    while( c<48 || c>57) { c=gc();}
    for(;c>47 && c<58;c = gc()){x = (x<<1) + (x<<3) + c - 48;}
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


int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int N, M;
    scanInt(N); scanInt(M);
    int ris = 1;
    int att= 0;
    bool giu = false;
    int tmp;
    while ( N--)
    {
        scanInt(tmp);
        if (giu)
        {
            if ( att < tmp) ris++, giu ^=1;
        }
        else
        {
            if ( att > tmp) ris++,giu^=1;
        }
        att = tmp;
    }
    writeInt(ris);
   
    return 0;
}
