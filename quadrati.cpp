//
//  main.cpp
//  quadrati
//
//  Created by nicomazz on 06/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include "math.h"

using namespace std;
typedef unsigned long long ll;

ll quanti(ll da, ll a)
{
   
    
    ll start = ceil(sqrt(da));
    if ( da == 2) start = 2;
    
    ll end = sqrt(a);
    
  //  cout<<"start: "<<start<<"  end: "<<end<<endl;


    return end-start+1;
}
int main(int argc, const char * argv[])
{

    ll a,b;
 
    
    cin>>a>>b;
   
    cout<<quanti(a,b)<<endl;
    
    return 0;
}

