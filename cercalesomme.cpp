//
//  main.cpp
//  cerca le somme
//
//  Created by nicomazz on 12/04/15.
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
// #define TEST
#define MAXN 100010

typedef pair<int, int> pii;
typedef pair<int,pii> piii;
typedef vector<int> vii;
typedef priority_queue<int,vii,greater<int> > priority_min_first;
typedef priority_queue<float,vii,greater<float> > priority_min_first_f;
typedef unsigned long long ull;

inline void scanInt(int &x)
{
    register int c=getchar();
    x = 0;
    while( c<48 || c>57) c=getchar();
    for(;c>47 && c<58;c = getchar()){x = (x<<1) + (x<<3) + c - 48;}
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

int somma;
int tot;
int N;
int n_da[11][11]; // da n, per n cifre
vector<int> sol;


int da_a(int da, int a)
{
    int n = 0;
    int k = 1;
    while (a >= da)
    {
        n += n_da[a][0]*k;
        k*= 10;
        a--;
    }
    return n;
}
void stampa_sol()
{
    for (int i = 0; i < sol.size()-1; i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}

void ric(int da)
{
    //cout<<"  "<<da<<"  ";
    if ( da == N+1 && somma == tot)
    {
        stampa_sol();
      //  cout<<"somma: "<<somma<<endl;

        return;
    }
    if  ( da > N+1)
    {      //  cout<<"somma: "<<somma<<endl;

        return;
    }
    
    int iniz_sum = somma;
    for (int i = 0; da+i <= N; i++)
    {
        somma = iniz_sum + n_da[da][i];
      //  cout<<"sommato: "<<n_da[da][i];//<<" da: "<<da<<"  per "<<i<<"   ";
        if ( somma > tot) return; // forse return
        sol.push_back(da+i);
        ric(da+i+1);
        sol.pop_back();
    }
}
int main(int argc, const char * argv[])
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    scanInt(N);
    
    for (int i = 1; i <= N; i++)
        scanInt(n_da[i][0]);
    
    scanInt(tot);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; i+j <= N; j++)
            n_da[i][j] = da_a(i, i+j);
    
    ric(1);
    
   /* for (int i = 1; i <= N; i++)
    {
        cout<<"da: "<<i<<" ";
        for (int j = 0; i+j <= N; j++)
        {
            cout<<"per: "<<j<<"   -> "<<n_da[i][j]<<endl;
        }
    }*/
    return 0;
}

/*
  7 1
 2 3 4 5 6 7
 100
 
 9 5
 4 3 2 1 2 3 4 5
 101
 
 8 2
 1 3 4 5 1 8 9
 105
 */