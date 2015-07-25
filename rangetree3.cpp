//
//  main.cpp
//  rangetree3
//
//  Created by nicomazz on 26/05/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//


#include <cstdio>
#include <iostream>
using namespace std;
//#define TEST
#define MAXN (1<<17)
inline void scanInt(int &x)
{
    register char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
bool neg;
inline void scanIntNeg(int &x)
{
    register char c=getchar_unlocked();
    x = 0;
    neg = false;
    while( c<48 || c>57) {if (c == '-')neg = true; c=getchar_unlocked();}
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}

struct bounds
{
    bounds(int a, int b){ s = a, d = b;}
    int s, d;
};
struct nodo
{
    int s,m,d,sum;
};
nodo v[MAXN*2];
int N;

void rmq_update(bounds att, int ind, int target, int newv)
{
    if ( att.s == att.d && att.s == target)
    {
        v[ind] = {newv,newv,newv,newv};
        return;
    }
    //else if ( att. d < target || att.s > target) return;
    
    int mid = (att.s+att.d)>>1;
    int sx = ind<<1, dx = ind<<1 | 1;
    
    if ( target <= mid)
        rmq_update(bounds(att.s, mid),sx,target,newv);
    else
        rmq_update(bounds(mid+1,att.d),dx,target,newv);
    
    v[ind].s = max(v[sx].s, v[sx].sum+v[dx].s);
    v[ind].d = max(v[dx].d ,v[dx].sum+v[sx].d);
    v[ind].m = max( max(v[sx].m, v[dx].m), v[sx].d+v[dx].s);
    v[ind].sum = v[sx].sum+v[dx].sum;
}
inline void rmq_update( int pos, int new_val){
    rmq_update(bounds(0,N-1), 1, pos,new_val);
}
nodo get_index(bounds target, bounds att, int ind){
    
    if ( att.s == target.s && att.d == target.d) return v[ind];
    
    int mid = (att.s+att.d)/2;
    if ( target.s > mid) { // a sx
        return get_index(target, bounds(mid+1,att.d), ind<<1 | 1);
    }
    else if ( target.d <= mid){
        return get_index(target, bounds(att.s,mid), ind<<1);
    }
    
    nodo sx = get_index(bounds(target.s,mid), bounds(att.s, mid), ind<<1);
    nodo dx = get_index(bounds(mid+1,target.d), bounds( mid+1,att.d), ind<<1 | 1);

    return (nodo) {
        max(sx.s, sx.sum+dx.s),
        max( max(sx.m, dx.m),sx.d+dx.s),
        max(dx.d, dx.sum+sx.d),
        sx.sum +dx.sum
    };
}
inline int get_index(int da, int a){
    return   get_index(bounds(da,a), bounds(0,N-1), 1).m;
}


int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    

    int q;
     scanInt(N);
    int val;
    for (int i = 0; i < N; i++)
    {
        scanIntNeg(val);
        rmq_update(i, val);
    }
    scanInt(q);
    int c, a, b;
    for (int i = 0; i < q; i++)
    {
        scanInt(c), scanInt(a), scanIntNeg(b);
        if ( !c)
            rmq_update(a-1, b);
        else
            printf("%d\n",get_index(a-1, b-1));
    }
    return 0;
}
