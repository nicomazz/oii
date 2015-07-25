//
//  main.cpp
//  nanga
//
//  Created by nicomazz on 03/01/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>


using namespace std;

int altitudini[200001];

int main()
{

    for (int i = 0; i < 200001; i++)
        altitudini[i] = -1;
    
    int aMeta = 200000/2; // cioè 5000
    
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    in>>N;
   
    
    for (int i = 0; i < N; i++)
    {
        int P;
        in>>P;
        
        altitudini[aMeta+P]++;
        aMeta+= P;
        
    }
    aMeta = 200000/2;
    
  /*  for (int i = 0; i < 200000; i++)
    {
        if (altitudini[i] != -1)
            cout<<altitudini[i]<<" "<<5000-(aMeta-i)<<endl;
    }
   */
    
    int AltitudinePiuGrande = -1;
    
    int max = -1;
    for (int i = 0; i < 200000; i++)
    {
        if (altitudini[i] > max)
        {
            max = altitudini[i];
            AltitudinePiuGrande =  5000-(aMeta-i);
        }
    }
    out<<AltitudinePiuGrande;
    
    
    
    return 0;
}

