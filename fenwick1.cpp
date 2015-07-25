//
//  main.cpp
//  fenwick1
//
//  Created by nicomazz on 13/06/15.
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
#define MAXN 500010

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

vi tree[MAXN];
int start_wage[MAXN];
int in[MAXN],out[MAXN];
int t_att = 1;
void dfs(int att)
{
    in[att] = t_att++;
    for (int figlio: tree[att])
        dfs(figlio);
    out[att] = t_att;
}

int fenwick[MAXN];
int MAX_F;
void update(int pos, int dt){
    for (int i = pos; i < MAX_F; i += i & (-i))
        fenwick[i]+= dt;
}
int get_0_to(int x){
    int sum = 0;
    for (int i = x; i ; i -= i& (-i))
        sum+= fenwick[i];
    return sum;
}


int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
   // iOS;
    int N, M;
    
    scanInt(N); scanInt(M);
   // start_wage.resize(N+1);
  //  tree.resize(N+1);
    
    scanInt(start_wage[1]);
    int p;
    for (int i = 2; i <= N; i++)
    {
        scanInt(start_wage[i]);
        scanInt(p);
        tree[p].push_back(i);
    }
    
   // in.resize(N+1);
   // out.resize(N+1);
    
    dfs(1);
    MAX_F = out[1]+1;
    // fenwick.resize(MAX_F+1);
    char tipo;
    int A,X;
    for (int i = 0; i < M; i++)
    {
        tipo = gc();
        while (tipo != 'p' && tipo != 'u') tipo = gc();
        if ( tipo == 'p')
        {
            scanInt(A); scanInt(X);
            update(in[A]+1, X);
            update(out[A], -X);
        }
        else
        {
           scanInt(p);
            writeInt(start_wage[p]+get_0_to(in[p]));
            pc('\n');
        }
    }
    return 0;
}
