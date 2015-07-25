//
//  main.cpp
//  essenza
//
//  Created by nicomazz on 16/02/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>

#define  REP(i,d,a) for (int i = (d); i < (a); i++)


using namespace std;

int MAX;

int costi[1001];
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int S, G;
    
    in>>S>>G;
    
    REP(i, 0, G) in>>costi[i];
    
   
    for (int i = 0; i<= G-S; i++)
        REP(j,i,i+S+1)
            REP(z, j+1, i+S+1)
                if (costi[z]-costi[j] > MAX)
                    MAX = costi[z]-costi[j];
               
    
    out<<MAX;
    

   
    
    return 0;
}

