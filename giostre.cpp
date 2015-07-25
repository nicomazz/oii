//
//  main.cpp
//  giostre
//
//  Created by nicomazz on 17/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;
int quanti(int A, int B)
{
    bitset<32000> visitato;
    int att = 0;
    int visit = 0;
    while (visitato[att] == false)
    {
        visitato[att] = true;
        att = (att + B) % A;
        visit++;
    }
    return visit;
    
}
int main(int argc, const char * argv[])
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int A,B;
    cin>>A>>B;
    
    cout<<quanti(A, B)<<" ";
    
    int att = 20;
    while (quanti(A, att) != A) att++;
    cout<<att;
  

    
    return 0;
}

// 0    5   10  15  20  25  30  35  40  45
// 1    6   11  4   9   2