//
//  main.cpp
//  rangetree2 ( multipli3)
//
//  Created by nicomazz on 21/05/15.
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
//#define MAXN 100

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;
#define MAXN (1<<20)
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
int v[MAXN*3][3]; // resto 0,1,2
int per_figli[MAXN*3];
bool update[MAXN*3];

void rmq_init(bounds b, int att)
{
    v[att][0] = b.d-b.s+1;
    update[att] = true;
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

void aggiungi_uno(int* iniz)
{
    int tmp = iniz[2];
    iniz[2] = iniz[1];
    iniz[1] = iniz[0];
    iniz[0] = tmp;
}
void metti_a_posto(int ind,int volte)
{
    for (int i = 0; i < volte; i++)
        aggiungi_uno(&v[ind][0]);
}
void update_figli( int att)
{
    if ( per_figli[att] != 0)
    {
        metti_a_posto(att*2, per_figli[att]);
        per_figli[att*2]    =  (per_figli[att*2] + per_figli[att])%3;
        metti_a_posto(att*2+1, per_figli[att]);
        per_figli[att*2+1]  = (per_figli[att*2+1] + per_figli[att])%3;
        per_figli[att] = 0;
    }
}

void update_da_figli(int ind, bounds att)
{
    if ( !update[ind])
    {
        int mid = (att.s+att.d)/2;
        update_figli(ind);
        update_da_figli(ind*2,bounds(att.s,mid) );
        update_da_figli(ind*2+1, bounds(mid+1,att.d));
        for (int i = 0; i < 3; i++) v[ind][i] = v[ind*2][i]+v[ind*2+1][i];
        update[ind] = true;
    }
}

void rmq_update( bounds target, bounds att, int ind)
{
    if ( att.s >= target.s && att.d <= target.d) { // interno
        if ( att.s != att.d) per_figli[ind] = (per_figli[ind]+1)%3; // figli da up
          aggiungi_uno(&(v[ind][0]));
        return;
    }
    else if ( att. d < target.s || att. s > target.d || att.d == att.s) return; // fuori
    else update[ind] = false;
    
    int mid = (att.s+att.d) / 2;
    
    rmq_update(target, bounds(att.s, mid), ind*2); // sinistro
    rmq_update(target, bounds(mid+1, att.d),  ind*2+1); // destro
}
void rmq_update( int da, int a){
    rmq_update(bounds(da,a), bounds(0,N-1),  1);
}
int get_index(bounds target, bounds att, int ind){
    
    
    //cout<<"get_index da:"<<att.s<<" a:"<<att.d<<endl;
    if ( att.s >= target.s && att.d <= target.d) { // interno
      //  cout<<"interno sx: "<<att.s<<"  dx:"<<att.d<<endl;
        update_da_figli(ind, att);
        return v[ind][0];
    }
    if ( att.d < target.s || att.s > target.d) return 0; // fuori

    update_figli(ind);
    
    int mid = (att.s+att.d)/2;
    int sx = get_index(target, bounds(att.s, mid), ind*2);
    int dx = get_index(target, bounds( mid+1,att.d), ind*2+1);
    return sx+dx;
}
int get_index(int da, int a){
    return   get_index(bounds(da,a), bounds(0,N-1), 1);
}

int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
     int q;
    scanInt(N); scanInt(q);
    rmq_init(N-1);
    int c, a, b;
    for (int i = 0; i < q; i++)
    {
       // if ( i % 100 == 0) cerr<<i<<endl;
        scanInt(c), scanInt(a),scanInt(b);
        if ( c == 0) //aumenta valore
            rmq_update(a, b);
        else
            printf("%d\n",get_index(a, b));
        
    }
    return 0;
}
/**
 4 8
 1 0 3
 0 1 2
 0 1 3
 1 0 0
 0 0 3
 1 3 3
 1 0 3
 1 0 3
 
 4 10
 1 0 3
 0 0 0 
 1 0 3
 0 2 3
 1 0 3
 0 1 2 
 1 0 3
 */
