//
//  main.cpp
//  ricehub
//
//  Created by nicomazz on 03/01/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <algorithm>


using namespace std;

//#define TEST

typedef  unsigned long ll;

inline void scanInt(ll &x)
{
    char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int RISAIE;
ll SOLDI;
ll *risaie;
ll *somme;

ll sommE(int ind)
{
    if (ind < 2 ) return 0;
    ind-=2;
    if (ind % 2 == 0) return somme[ind/2];
    return somme[ind/2]+risaie[ind];
}

bool testa1(int da, int a)
{
    int p = (da+a)/2;
    return (p-da)*risaie[p]- (sommE(p)-sommE(da))+(sommE(a+1)-sommE(p+1))-(a-p)*risaie[p] <= SOLDI;
}
bool testa2(int da, int a)
{
    int p = (da+a)/2;
    return (p-da)*risaie[p]- (somme[p]-somme[da])+(somme[a+1]-somme[p+1])-(a-p)*risaie[p] <= SOLDI;
}

int main()
{
#ifndef TEST
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
    scanf("%d",&RISAIE); scanInt(SOLDI);
    if (RISAIE > 500000)
    {
        risaie = new ll[RISAIE];
        somme = new ll[RISAIE/2 +10]; // comica come cosa, continee solo i pari
        scanInt(risaie[0]);
        
        somme[0] = risaie[0];
        
        int indSomme = 1 ;
        risaie[0] = 0;
        for (int i = 1; i < RISAIE; i++)
        {
            scanInt(risaie[i]);
            if (i % 2 == 0)
            {
                somme[indSomme] = somme[indSomme-1]+risaie[i]+risaie[i-1];
                indSomme++;
            }
        }
        /*for (int i = 0; i < RISAIE; i++)
         cout<<sommE(i)<<"  ";
         cout<<endl;
         */
        int massime_risaie = 1;
        
        int inizio = 0;
        int fine = 0;
        
        
        while(fine < RISAIE)
        {
            
            while (fine < RISAIE && testa1(inizio, fine))
                ++fine;// cout<<++fine<<endl;
            massime_risaie = max(massime_risaie,fine-inizio);
            inizio++;
            fine++;
        }
        
        cout<<massime_risaie;
    }
    else
    {
        risaie = new ll[RISAIE];
        somme = new ll[RISAIE+1];
        somme[0] = 0;
        somme[1] = risaie[0];
        
        for (int i = 1; i < RISAIE; i++)
        {
            scanInt(risaie[i]);
            somme[i+1] = somme[i]+risaie[i];
        }
        
     
        int massime_risaie = 1;
        //ll pos_risaia;
        
        // ll media;
        int inizio = 0;
        int fine = 0;
        
        //ll somma = risaie[0];
        
        while(fine < RISAIE)
        {
            // media = (somme[fine+1]-somme[inizio])/ (fine-inizio+1);
            
            while (fine < RISAIE && testa2(inizio, fine))
            {
                fine++;
                // somma+=risaie[++fine];
                //         media = (somme[fine+1]-somme[inizio])/ (fine-inizio+1);
            }
            
            massime_risaie = max(massime_risaie,fine-inizio);
            
            inizio++;
            fine++;
        }
        
        cout<<massime_risaie;
        // cerr<<"massime risaie: "<<massime_risaie;//<<" posizione: "<<pos_risaia;
    }
    return 0;
}

