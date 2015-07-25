//
//  main.cpp
//  touristic plan
//
//  Created by Nicolò Mazzucato on 20/07/15.
//  Copyright (c) 2015 Nicolò Mazzucato. All rights reserved.
//

#include <iostream>
#include <set>
#include <assert.h>

using namespace std;

int GreatestHappiness(int N, int K, int *C) {
    
    int always_possible = (K+1)/2;
    if ( always_possible >= N) always_possible  = N;
    
    multiset<int> taken;
    int sum = 0;
    for (int i = 0; i < always_possible; i++){
        sum+= C[i];
        taken.insert(C[i]);
    }
    int max_ris = sum;
    int travel_use = always_possible;
    multiset<int>::iterator it;
    
    for (; travel_use < N; travel_use++)
    {
        int disp = K-travel_use;
        if ( disp == 0) return max_ris;
        if ( taken.size() == 0) return max_ris;
        while ( taken.size() > disp)
        {
            it = taken.begin();
            sum-= *it;
            taken.erase(it);
        }
        //assert(taken.size() > 0);
        if ( taken.size() == 0) return max_ris;
        if ( *(taken.begin()) < C[travel_use])
        {
            it = taken.begin();
            sum-= *it;
            taken.erase(it);
            taken.insert(C[travel_use]);
            sum+= C[travel_use];
        }
        max_ris = max(max_ris, sum);
    }
    return max_ris;
    
}
/*
#define MAXN 1000001
int H[MAXN];
int main(int argc, const char * argv[]) {
    
    int N, K;
    cin>>N>>K;
    for (int i = 0; i< N; i++){
        cin>>H[i];
    }
    cout<<GreatestHappiness(N, K, H);
    return 0;
}*/
/*
 4 3
 4 5 2 7
 */
