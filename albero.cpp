//
//  main.cpp
//  albero
//
//  Created by nicomazz on 09/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <climits>
#include <queue>
#include <set>
#include <string.h>
#include <cstdio>

using namespace std;

#define MAXN 100001

typedef pair<int,bool> pib;
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, greater<int>> queue_min_first;


list<pib> grafo[MAXN];
int N;
int rossi_verdi_fino[MAXN][2]; // rossi, verdi

inline void scanInt(int &x){
    
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int visita(int root)
{
    
    queue<pii> s; // nodo, padre
    s.push(pii(root,-1));
    
    int rossi_tot = 0;
    
    while (!s.empty())
    {
        pii attuale = s.front();
        s.pop();
//        cout<<"attuale: "<<attuale.first<<" "<<attuale.second<<endl;
        
        for (list<pib>::iterator node = grafo[attuale.first].begin(); node != grafo[attuale.first].end(); node++)
            if (node->first !=attuale.second) // divero dal padre
            {
                if (!node->second)
                {
                    rossi_verdi_fino[node->first][0] = rossi_verdi_fino[attuale.first][0]+1; // diretta? i rossi sono uguali
                    rossi_verdi_fino[node->first][1] = rossi_verdi_fino[attuale.first][1]; // indieretta? aumenta i rossi
                    rossi_tot++;
                }
                else
                {
                    rossi_verdi_fino[node->first][0] = rossi_verdi_fino[attuale.first][0]; // diretta? i rossi sono uguali
                    rossi_verdi_fino[node->first][1] = rossi_verdi_fino[attuale.first][1]+1; // indieretta? aumenta i rossi
                }
                
               
                s.push(pii(node->first,attuale.first));
            }
        
    }
    return rossi_tot;

}

#define costo_capitale(x) rossi_tot-rossi_verdi_fino[x][0]+rossi_verdi_fino[x][1]

int main()
{
    scanInt(N);
    
    int a,b;
    for (int i = 1; i < N; i++)
    {
        scanInt(a); scanInt(b);
        grafo[a].push_back(pib(b,true));
        grafo[b].push_back(pib(a,false));
    }
    int rossi_tot = visita(1);
    
    
    int costoMin = rossi_tot;
    queue_min_first coda;
    coda.push(1);
    
    int costo;
    for (int i = 2; i<=N; i++)
    {
        costo = costo_capitale(i);
        if (costo < costoMin)
        {
            costoMin = costo;
            coda = queue_min_first();
            coda.push(i);
        }
        else if (costo == costoMin)
            coda.push(i);
    }

    printf("%d\n",costoMin);
    
    int sz = coda.size();
    for (int i = 0; i <sz; i++)
    {
        printf("%d ",coda.top());
        coda.pop();
    }
    
  
    
    
    return 0;
}

