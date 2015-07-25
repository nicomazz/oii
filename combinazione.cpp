//
//  main.cpp
//  combinazione
//
//  Created by Nicolò Mazzucato on 16/06/15.
//  Copyright (c) 2015 Nicolò Mazzucato. All rights reserved.
//

#include <iostream>
#include <fstream>
#define MAXN 5000010
int med[MAXN];
int N;
using namespace std;

bool tenta(  int n ,int da = 0)
{
    // in avanti:
    int att = n;
    for (int i =0; i< N; i++)
    {
        int succ = med[i]*2 - att;
        if ( succ < att) return false;
        att = succ;
    }
    return true;
}

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
int main(int argc, const char * argv[]) {
   
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie();
    

    scanInt(N);

    for (int i = 0; i < N; i++)
        scanInt(med[i]);
        
    

    int l_bound = med[0]-med[1];
    int h_bound = med[0];
    
   // cout <<l_bound<<" "<<h_bound<<endl;
    
    // dal basso
    bool trovato = false;
    int val_l;
    for ( int i = l_bound; i <= h_bound; i++)
        if (tenta(i)) {trovato = true; val_l = i; break;}
    
    if (!trovato) { cout<<"0"; return 0;}
    
    int val_h;
    trovato = false;
    for (int i = h_bound;; i--)
        if (tenta(i)) {trovato = true; val_h = i; break;}
    
    cout<<val_h-val_l+1;
    
    return 0;
}
