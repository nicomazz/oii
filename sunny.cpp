//
//  main.cpp
//  sunny
//
//  Created by nicomazz on 04/03/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

#define REP(i,d,a) for (int i = (d); i < (a); i++)

using namespace std;

typedef pair<int, int> galleria;

vector<galleria> gallerie;
inline void scanInt(int &x)
{
     register int c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int N,M,H,S;
    
    cin>>N>>M>>H>>S;
    
    gallerie.resize(N+1);
    
    int a,b,l;
    REP(i,0, M)
    {
        scanInt(a); scanInt(b); scanInt(l);
        if (gallerie[a].second > l || gallerie[a].second == 0)  gallerie[a] = galleria(b,l);
        if (gallerie[b].second > l || gallerie[b].second == 0)  gallerie[b] = galleria(a,l);
    }
    
    int VicoloAttuale = H;
    int cnt = 0;
    int prec = 0;
    
    while (VicoloAttuale != S)
    {
        cnt++;
        if (prec == gallerie[VicoloAttuale].first || VicoloAttuale == 0){ cout<<-1; return 0;}
        prec = VicoloAttuale;
        VicoloAttuale = gallerie[VicoloAttuale].first;
   
    }
    cout<<cnt;
    

    return 0;
}

