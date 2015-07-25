//
//  main.cpp
//  giardino
//
//  Created by nicomazz on 26/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define MAXN 501

typedef pair<int, int> pii;
typedef vector<int> vii;

inline void scanInt(int &x) // NON LEGGE NUMERI NEGATIVI!!!!!
{
    register int c=getchar_unlocked();
    x = 0;
    bool neg = false;
    
    while( c<48 || c>57) {if (c == '-')neg = true; c=getchar_unlocked();}
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
    if (neg) x*=-1;
}

pii punti[501];
int erba[501][501];
int minX,minY,maxX,maxY;


int main(int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
    
    int N, M;
    

    
    scanInt(N); scanInt(M);
    
    int x,y, i, j;
    
    minX  = 10000, maxX = -100000;  minY  = 10000, maxY = -100000;
    
    
    for (i = 0; i < M; i++)
    {
       // scanf("%d",&x); scanf("%d",&y);
        scanInt(x); scanInt(y);
        punti[i].first = x, punti[i].second = y;
        
        
        minX = min(minX,x);
        maxX = max(maxX,x);

        
        
        minY = min(minY,y);
        maxY = max(maxY,y);
    }
    
 
    for ( i = 0; i < M; i++)
    {
        punti[i].first -= minX;
        punti[i].second -= minY;
       // cout<<"punto: "<<i<<" "<<punti[i].first<<" "<<punti[i].second<<"  "<<endl;
    }
    

    
    for (i = 0; i < N; i++)
        for ( j = 0; j < N; j++)
            scanInt(erba[i][j]);
    
    
    
    int somma = 0;
    
    int altezzaY = maxY-minY;
    int altezzaX = maxX-minX;
    int xMax = 0, yMax = 0;
    int  somma_min = 5000001;
    
    int p;
    
    int finoY = N-altezzaY, finoX = N-altezzaX;
    for (i = 0; i < finoY; i++)
        for (j = 0; j < finoX; j++)
        {
            somma = 0;
            for (p= 0; p < M; p++)
                somma+= erba[punti[p].first +j][punti[p].second +i];
            if (somma < somma_min)
            {
                xMax = i, yMax = j;
                somma_min= somma;
            }
        }
    
    cout<<yMax-minX<<" "<<xMax-minY<<" "<<somma_min;
    
    
    
    
    return 0;
}

