//
//  main.cpp
//  dieta di poldo
//
//  Created by nicomazz on 06/06/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in>>N;
    
    int panini[N];
    
    for (int i = 0; i < N; i++)
        in>>panini[i];
    
    int soluzione[N];
    soluzione[0] = 1;
    
    for (int i = 1; i < N; i++)
    {
        int maxSol = 0;
        for (int j = i-1; j >= 0; j--)
            if (panini[j] > panini[i])
                maxSol = max(maxSol,soluzione[j]);
         soluzione[i] = maxSol+1;
    }
    
    int massimo = soluzione[0];
    for (int i = 0; i<N; i++)
        massimo = max(massimo,soluzione[i]);
        
       out<<massimo;
    
    return 0;
}

