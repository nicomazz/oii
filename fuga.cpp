//
//  main.cpp
//  fuga
//
//  Created by nicomazz on 21/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>


using namespace std;

#define MAXN 100010

#define DFS_WHITE   0
#define DFS_GRAY    1
#define DFS_BLACK   2

typedef pair<int, int> pii;

list<pii> grafo[MAXN];
vector<int> soluzione;
int genitore[MAXN];
bitset<MAXN> visitato;

inline void scanInt(int &x)
{
    register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

#define dest second

list<pii>::iterator it;
pii att; int nodoDest;

bool cercaCiclo(int inizio)
{
    if (visitato[inizio]) return false;
    
    stack<pii> pila;
    
    
    for (list<pii>::iterator it = grafo[inizio].begin(); it != grafo[inizio].end();it++)
        {
            genitore[it->second] = inizio;
            pila.push(*it);
        }
    visitato[inizio] = true;
    
       while (!pila.empty())
    {
        att = pila.top();
        pila.pop();
        
     //   cout<<"inizio, fine:"<<att.first.first<<" "<<att.first.second<<endl;
        
        nodoDest = att.second;
        visitato[nodoDest] = true;
        
        for (it = grafo[nodoDest].begin(); it != grafo[nodoDest].end();it++)
            if (it->dest == genitore[it->first]) continue; // genitore
            else if (visitato[it->dest] == true) // già visitato e non genitore
            {
                int finale = it->dest;
                int attuale = nodoDest;
                soluzione.push_back(finale);
                while (attuale != finale)
                {
                    soluzione.push_back(attuale);
                    attuale = genitore[attuale];
                }
                return true;
            }
            else // arco verde
            {
                genitore[it->dest] = nodoDest; // cioè l'attuale
                pila.push(*it);
            }
    }
    return false;
}

int main(int argc, const char * argv[])
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int Nodi, Archi;
    
    scanInt(Nodi); scanInt(Archi);
    
    int da, a, rosso;
    for (int i = 0; i < Archi; i++)
    {
        scanInt(da); scanInt(a); scanInt(rosso);
        if (rosso == 0) continue;
        grafo[da].push_back(pii(da,a));
        grafo[a].push_back(pii(a,da));
    }
    
    for (int i = 0; i < Nodi; i++)
    {
        if (cercaCiclo(i))
        {
            int size = soluzione.size();
            printf("%d\n",size);
            for (int j = 0; j < size; j++)
                printf("%d ",soluzione[j]);
            
            return 0;
        }
    }
    
    return 0;
}
/*3
5
1 2 1
2 3 1
1 3 0
3 4 1
4 1 1*/

