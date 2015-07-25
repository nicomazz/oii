//
//  main.cpp
//  dublicato
//
//  Created by nicomazz on 02/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <set>

#include <stdio.h>
#include <assert.h>

using namespace std;

#define MAXN 100000

int trova(int N, int P[]) {

    set<int> s;
    int fino = 2*N-1;
    for(int i = 0; i < fino; i++)
    {
        set<int>::iterator it = s.find(P[i]);
        if (it != s.end()) s.erase(it);
        else s.insert(P[i]);
    }
    return *s.begin();
}

int P[2 * MAXN];
int main() {
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<2*N-1; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", trova(N, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
