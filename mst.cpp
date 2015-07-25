//
//  main.cpp
//  minimum spannig tree
//
//  Created by nicomazz on 13/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <bitset>


using namespace std;

#define MAXN 10001

typedef unsigned long long  ll;
typedef pair<int,int> pii;
typedef pair<pii,ll> arco;
struct cmp{bool operator()(const arco & a, const arco & b)const{ return a.second>b.second;} };
typedef priority_queue<arco,vector<arco>,cmp> queue_min_first;

// union set
vector<int> set;
void setInit(int size){set.resize(size+1); for (int i = 0; i <= size; i++) set[i] = i;}
int setFind(int i) { return set[i] == i? i: (set[i] = setFind(set[i]));}
void unionSet(int i, int j) { set[setFind(i)] = setFind(j);}
bool isSameSet(int i,int j) {return setFind(i) == setFind(j);}


int N,M;
queue_min_first coda;

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
inline void scanLL(ll &x)
{
    register ll c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int main(int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanInt(N); scanInt(M);
    
    int u,v;
    ll w;
    
    for (int i = 0; i < M; i++)
        scanInt(u), scanInt(v), scanLL(w),coda.push(arco(pii(u,v),w));
    
    arco sol[MAXN];
    int ind = 0;
    ll costo = 0;
    
    setInit(MAXN);
    
    while (!coda.empty())
    {
        arco att = coda.top();
        coda.pop();
        
        if (!isSameSet(att.first.first, att.first.second))
        {
            unionSet(att.first.first, att.first.second);
            costo+= att.second;
            sol[ind++] = att;
        }
    }
    
    printf("%llu\n",costo);
    for (int i = 0; i < ind; i++)
        printf("%d %d\n",sol[i].first.first,sol[i].first.second);
    
        
    
    return 0;
}

