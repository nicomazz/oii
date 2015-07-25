//
//  main.cpp
//  spiedini
//
//  Created by nicomazz on 21/11/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//



#include <iostream>

int solve(int N, int K, int* S);

using namespace std;

/*
int main(int argc, const char * argv[])
{

    
    int n, k;
    
    cin>>n>>k;
    
    for (int i = 0; i < n; i++)
        cin>>vett[i];
    
    cout<<solve(n, k, vett);
    
    return 0;
}*/
#define maxN 1000001

//typedef  long long ll;

int solve(int N, int K, int* S) {
   
    int tol = 0;
    int zeri = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 0) zeri++;
        tol+= S[i];
    }
    
    int sx = 0,dx = 0;
    int massimo = 0;
    while (sx < N)
    {
        while (dx < N && tol > K)
        {
            tol-= S[dx];
            if (S[dx] == 0)
                zeri--;
            dx++;
        }
        
        if (dx == N && tol > K) break;
        
        if (sx <= dx) massimo = max(massimo,zeri);
        
        if (S[sx] == 0) zeri++;
        tol+= S[sx];
        sx++;
    }
    
    
    
    return massimo;
  
}
