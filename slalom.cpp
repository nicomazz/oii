//
//  macin.cpp
//  slalom
//
//  Created by nicomazz on 08/10/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
typedef int ll;

#define maxNum 400001


inline void scanInt(int& x)
{
    char c = getchar_unlocked();
    x = 0;
    for(; (c<48)||(c>57);c = getchar_unlocked()); // finchè non trova un numero
    for(; (c>47)&&(c<58);c = getchar_unlocked()) x = (int)((((x)<<1) + ((x)<<3)) + c - 48);
}




ll N;
ll costo[maxNum];

list<ll> lista[maxNum];
ll si[maxNum];
ll no[maxNum];
ll MAY[maxNum];

ll MAYBE(ll n, ll parent);

ll YES(ll n, ll parent)
{
    if (si[n]) return si[n];
    ll ris = costo[n];
    
    for (list<ll>::iterator it = lista[n].begin(); it != lista[n].end(); it++)
        if (*it != parent)
            ris+= MAYBE(*it, n);

    return si[n] = ris;
}
ll NO(ll n, ll parent)
{
    if (no[n]) return no[n];
    
    if (lista[n].size() == 1 && parent != -1)
        return 0;
    
    ll ris = 0;

    //aggiungere tutti i figli
    for (list<ll>::iterator it = lista[n].begin(); it != lista[n].end(); it++)
        if (*it != parent)
            ris += YES(*it,n);
    
    return no[n] = ris;
}
ll MAYBE(ll n, ll parent)
{
    if (MAY[n]) return MAY[n];
    
    ll Si = YES(n, parent);
    ll No = NO(n,parent);
    
    //cout<<"nodo "<<n<<"  si, no  "<<Si<<"  "<<No<<endl;
    
    if (Si <= No)
        return MAY[n] = Si;
    
    else
        return MAY[n] = No;
    
}
bool visitato[maxNum];
int migliori[maxNum];
int cntMigliori;
void visita()
{
    queue<ll> coda;
    
    int migliori[N];
    int cntMigliori = 0;
    
    coda.push(1);
    
    
    while (!coda.empty()) {
        ll att = coda.front();
        coda.pop();
        
        if (visitato[att]) continue;
        visitato[att] = true;
        
        //attuale
        if (si[att] < no[att])
        {
            migliori[cntMigliori++] = att;
            for (list<ll>::iterator it = lista[att].begin(); it != lista[att].end(); it++)
                if (!visitato[*it])
                    coda.push(*it);
        }
        //figli
        else
            for (list<ll>::iterator it = lista[att].begin(); it != lista[att].end(); it++)
            {
                if (!visitato[*it])
                {
                    migliori[cntMigliori++]= *it;
                    visitato[*it] = true;
                }
                for (list<ll>::iterator it2 = lista[*it].begin(); it2 != lista[*it].end(); it2++)
                    if (!visitato[*it2])
                        coda.push(*it2);
            }
        }
    
    printf("%d\n",cntMigliori);
    for (ll i = 0; i < cntMigliori; i++)
        printf("%d ",migliori[i]);
    
}
int main(int argc, const char * argv[])
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    
    scanInt(N);
    for (ll i = 1; i<= N; i++)
        scanInt(costo[i]);
    
    ll tmp1,tmp2;
    N--;
    for (ll i = 0; i <N; i++)
    {
        scanInt(tmp1); scanInt(tmp2);
        lista[tmp1].push_back(tmp2);
        lista[tmp2].push_back(tmp1);
    }
    
    MAYBE(1, -1);
   
    visita();
   
     return 0;
}

