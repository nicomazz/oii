//
//  main.cpp
//  fermata
//
//  Created by nicomazz on 22/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>

using namespace std;

#define MAXN 1000000

typedef pair<int, int> pii; // spostamento, nuovo stato
typedef vector<int> vii;
typedef vector<pii> vpp;


#define visitati(i,s) visitati[s*N+i]
bitset<MAXN> visitati;

#define completati(i,stato) completati[stato*N+i]
short completati[MAXN];
//vector<vpp> transizione; // stato, letto
#define transizione(stato,letto) transizione[N*stato+letto]
pii transizione[MAXN];
int nastro[MAXN];

int N, S,C;// lunghezza, stati,C

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

#define finisce 1
#define non_finisce 2

short evolvi(int i, int stato)
{
    if (completati(i,stato)) return completati(i,stato);
    else if (i == 0) return finisce;
    else if (visitati(i,stato) == true) return non_finisce;
    
    visitati(i,stato) = true;
    
    short ris = evolvi(i + transizione (stato,nastro[i]).first, transizione (stato,nastro[i]).second); // spostamento e nuovo stato
    
    return completati(i,stato) = ris;
}

int main(int argc, const char * argv[])
{
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    
    scanInt(N); scanInt(S); scanInt(C);

    int fino = S*C;
    int cur,letto,n_stato,spost;
    for (int i = 0; i < fino; i++)
    {
        scanInt(cur); scanInt(letto); scanInt(n_stato);scanf("%d",&spost);
        transizione(cur,letto) = pii(spost,n_stato);
    }
    completati[0] = finisce;
    
    for (int i = 0; i < N;i++)
        scanInt(nastro[i]);
    
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        visitati.reset();
        if (completati(i,0) == finisce || evolvi(i,0) == finisce) cnt++;
    }

    printf("%d\n",cnt);
    for (int i = 0; i < N; i++)
        if (completati(i,0) == finisce) // partendo dallo stato 0
            printf("%d\n",i);

    
    return 0;
}

