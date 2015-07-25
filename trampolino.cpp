//
//  main.cpp
//  trampolino
//
//  Created by nicomazz on 01/03/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>


#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <climits>
#include <algorithm>
#include <queue>
#include <set>
#include <string.h>


using namespace std;
#include <stdio.h>
#include <assert.h>

#define MAXN 100100

int salta(int N, int E[]) {

    int att = 0;
    int cnt = 1;
    
    while (att + E[att] < N)
    {
        int val_magg = 0,  pos_magg = 0;
        for (int i = 1; i <= E[att] ; i++)
            if ( att+i < N && val_magg < att+i+E[att+i])
            {
                val_magg = att+i+E[att+i];
                pos_magg = att+i;
            }
        att = pos_magg;
        cnt++;
    }
    return cnt;
}


int E[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &E[i]));
    
    fprintf(fw, "%d\n", salta(N, E));
    fclose(fr);
    fclose(fw);
    return 0;
}
