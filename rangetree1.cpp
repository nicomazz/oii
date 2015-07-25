//
//  main.cpp
//  rangetree1
//
//  Created by nicomazz on 14/05/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;
//#define TEST
#define MAXN (1<<19)
inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
struct bounds
{
    bounds(int a, int b){ s = a, d = b;}
    int s, d;
};
int v[MAXN];
int rif[MAXN];
bool updated[MAXN];
bool figli_da_invertire[MAXN];

void rmq_init(bounds b, int att)
{
    v[att] = 0;
    rif[att] =  b.d-b.s + 1;
    updated[att] = true;
    if ( b.s == b.d) return;
    int mid = (b.s+b.d)/2;
    rmq_init(bounds(b.s, mid), att*2);
    rmq_init(bounds(mid+1,b.d), att*2+1);
}
void rmq_init(int n)
{
    rmq_init(bounds(0,n), 1);
}
int N;

void change_update( bounds att, int ind)
{
    if ( !updated[ind])
    {
        int mid = (att.s+att.d )/ 2;
        change_update(bounds(att.s,mid),ind*2);
        change_update(bounds(mid+1,att.d), ind*2+1);
        v[ind] = v[ind*2]+v[ind*2+1];
        updated[ind] = true;
    }
}
void update_figli( int att)//, bounds b = bounds(-1,-1))
{
    int sx = att*2, dx = att*2+1;
    v[sx] = rif[sx]-v[sx];
    figli_da_invertire[sx] ^= 1;
    v[dx] = rif[dx]-v[dx];
    figli_da_invertire[dx] ^= 1;
    figli_da_invertire[att]= false;
}
void rmq_update( bounds target, bounds att, int ind)
{
    if ( att.s >= target.s && att.d <= target.d) { // interno
         change_update(att, ind); // questo dal basso
        if( att.s != att.d) figli_da_invertire[ind] ^= 1; // se è un range
        v[ind] = rif[ind]-v[ind];
        return;
    }
    else if ( att. d < target.s || att. s > target.d || att.d == att.s) return;
    else updated[ind] = false;

    if ( figli_da_invertire[ind]) update_figli(ind);
    int mid = (att.s+att.d) / 2;
    
    rmq_update(target, bounds(att.s, mid), ind*2); // sinistro
    rmq_update(target, bounds(mid+1, att.d),  ind*2+1); // destro
}
void rmq_update( int da, int a){
    rmq_update(bounds(da,a), bounds(0,N),  1);
}
int get_index(bounds target, bounds att, int ind){
    if ( att. d < target.s || att. s > target.d) return 0; // esterno

    int mid = (att.s+att.d)/2;
    
    if ( figli_da_invertire[ind]) update_figli(ind);
    if ( att.s >= target.s && att.d <= target.d) { // interno
        change_update(att, ind);
        return v[ind];
    }
    int sx = get_index(target, bounds(att.s, mid), ind*2);
    int dx = get_index(target, bounds( mid+1,att.d), ind*2+1);
    return sx+dx;
}
int get_index(int da, int a){
    return   get_index(bounds(da,a), bounds(0,N), 1);
}

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
   
    int q;
    scanInt(N); scanInt(q);
    rmq_init(N);
    int c, a, b;
    for (int i = 0; i < q; i++)
    {
      //  scanInt(c), scanInt(a),scanInt(b);
        cin>>c>>a>>b;
        if ( c == 0) //flip
            rmq_update(a, b);
        else
            printf("%d\n",get_index(a, b));
    }
    return 0;
}
/**
 4 10
 0 0 4
 1 0 4
 1 0 2
 1 0 3
 1 0 1
 1 0 0
 0 0 1
 1 0 4
 
 output:
 0
 5
 3
 4
 2
 1
 3
 */