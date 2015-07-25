//
//  main.cpp
//  maratona 2.0
//
//  Created by nicomazz on 10/07/15.
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
#include <assert.h>
using namespace std;

#define TEST

typedef pair<int, int> pi;
typedef pair<int,pi> pii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef  long long ll;

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

#define iOS ios_base::sync_with_stdio(false)
#define error(x) //cerr << #x << " = " << (x) <<endl
#define all(x) (x).begin(), (x).end()
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

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


#define MAXN 100001
#define MAXLOG 17

using namespace std;

struct punto {
    int x, y;
};

punto strade[MAXN];
punto fx[MAXN];
punto fy[MAXN];

int rmqx[MAXN][MAXLOG];
int rmqy[MAXN][MAXLOG];
int ofset[MAXN];
int S, F;

inline bool cmpX(const punto & a,const punto & b){
    if ( a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
inline bool cmpY(const punto &a,const punto &b){
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
#define distanza_punti(x,y,xn,yn) (abs(x-xn) + abs(y-yn))
#define pointDist(p1,p2) (abs(p1.x - p2.x) + abs(p1.y - p2.y))
void buildRMQ(){
    F--;
    for (int i = 0; i < F; i++)
        rmqx[i][0] = pointDist(fx[i], fx[i+1]),
        rmqy[i][0] = pointDist(fy[i], fy[i+1]);
    F++;
    
    for (int i = 1; i < MAXLOG; i++)
    {
        for (int j = 0; j < F - ( 1<<(i-1)); j++)
            rmqx[j][i] = max(rmqx[j][i-1],rmqx[j+ (1<<(i-1))][i-1]),
            rmqy[j][i] = max(rmqy[j][i-1],rmqy[j+ (1<<(i-1))][i-1]);
    }
    
    
    int p = 0;
    for(int i = 1; i < F; i++){
        if (2<<p <= i) p++; // 1+1 = 2
        ofset[i] = p;
    }
}
int rmq_x(int da, int a)
{
    assert(da>=0);
    assert(a < F);
    if ( da == a) return 0;
    if ( a == da +1 ) return rmqx[da][0];
    
    int off = ofset[a-da];
    return max(rmqx[da][off], rmqx[a-(1<<off)][off]);
}
int rmq_y(int da, int a)
{
    assert(da>=0);
    assert(a < F);
    if ( da == a) return 0;
    if ( a == da +1 ) return rmqy[da][0];
    
    int off = ofset[a-da];
    return max(rmqy[da][off], rmqy[a-(1<<off)][off]);
}
inline void scanInt(int &x){
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
int l_senza;
int max_dist;
void XX(int i) // -
{
    punto da = strade[i];
    punto a = strade[i+1];
    
    // sempre da sx a dx
    bool swapped = false;
    if ( a.x < da.x) swap(da, a), swapped = true;
    
    punto *prima = lower_bound(fy, fy+F, da, cmpY);
    punto *ultima = upper_bound(fy, fy+F, a, cmpY);
    ultima--;

    if (prima == fy+F || prima->y != da.y || ultima < prima)
    { l_senza += pointDist(strade[i], strade[i+1]); return; }
    
    int ind_prima = prima - fy;
    int ind_ultima = ultima - fy;
    error(ind_prima);
    error(ind_ultima);

    int RMQX =rmq_y(ind_prima,ind_ultima);
    error(RMQX);
    smax(max_dist, RMQX);
    if ( !swapped){
        smax(max_dist, l_senza+ pointDist(strade[i], (*prima)));
        l_senza = pointDist((*ultima), a);}
    else
    {
        smax(max_dist, l_senza+ pointDist(strade[i],(*ultima)));
        l_senza = pointDist((*prima), da);
    }

    error(max_dist);
}
void YY(int i) // |
{
    punto da = strade[i];
    punto a = strade[i+1];
    
    bool swapped = false;
    // sempre dal basso verso l'alto
    if ( a.y < da.y) swap(da, a),swapped = true;;
    
    punto *prima = lower_bound(fx, fx+F, da, cmpX);
    punto *ultima = upper_bound(fx, fx+F, a, cmpX);
    ultima--;
    
    if (prima == fx+F || prima->x != da.x|| ultima < prima)
    { l_senza += pointDist(strade[i], strade[i+1]); return; }
    
    int ind_prima = prima - fx;
    int ind_ultima = ultima - fx;
    
    error(ind_prima);
    error(ind_ultima);
    
    int RMQY = rmq_x(ind_prima,ind_ultima);
    error(RMQY);
    smax(max_dist, RMQY);
    if ( !swapped){
        smax(max_dist, l_senza+ pointDist(strade[i], (*prima)));
        l_senza = pointDist((*ultima), a);}
    else
    {
        smax(max_dist, l_senza+ pointDist(strade[i], (*ultima)));
        l_senza = pointDist((*prima), da);
    }
    error(max_dist);
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanInt(S); scanInt(F);
    
    for (int i = 0; i <= S; i++) scanInt(strade[i].x),scanInt(strade[i].y);
    for (int i = 0; i < F; i++) scanInt(fx[i].x),scanInt(fx[i].y);
    
    for (int i = 0; i < F; i++) fy[i] = fx[i];
    
    sort(fx,fx+F, cmpX);
    sort(fy,fy+F, cmpY);
    
    if ( F < 50000 || S == 1)
        buildRMQ();
    for (int i = 0; i < S; i++)
        if ( strade[i].x == strade[i+1].x)
            YY(i);
        else
            XX(i);
    smax(max_dist, l_senza);
    
    if (max_dist > 100) cout<<max_dist-100;
    else cout <<0;
    return 0;
}
/*
 1 3
 
 0 0
 1000 0
 100 0
 200 0
 1000 0
 
 7 4
 0 400
 300 400
 300 0
 600 0
 600 700
 800 700
 800 500
 400 500
 300 100
 600 500
 600 600
 600 100
 */
