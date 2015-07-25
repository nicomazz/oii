//
//  main.cpp
//  bath
//
//  Created by nicomazz on 12/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
typedef priority_queue<int,vector<int>, std::greater<int>> priority_min_first;

inline void scanInt(int &x){
    register char c=getchar_unlocked();
    x = 0;
    while( c<48 || c>57) c=getchar_unlocked();
    for(;c>47 && c<58;c = getchar_unlocked()){x = (x<<1) + (x<<3) + c - 48;}
}

int monete[10001];

int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    
    scanInt(N);
    
    int i,somma, att, n;
    bool trovato;
    
    while (N--)
    {
        scanInt(M);
        priority_min_first queue;
        
        for ( i = 0; i < M; i++)
        {
            scanInt(monete[i]);
            queue.push(monete[i]);
        }
        
        n = 0;
        trovato = false;
        att;
        
        for (i = 0; i < M; i++)
        {
            att= queue.top();
            queue.pop();
            if (att> n+1){ printf("%d\n",n+1); trovato = true; break;}
            n+=att;
        }
        if (!trovato) printf("%d\n",n+1);
    }
    
    return 0;
}

