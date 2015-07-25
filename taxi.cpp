#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int viaggia(int N, int C[]) {

    int costoAtt = C[0];
    int somma = costoAtt;
    
    for (int i = 1; i < N; i++)
    {
        costoAtt++;
        if (C[i] < costoAtt) costoAtt = C[i];
        somma+=costoAtt;
    }
       
    return somma;
}


int C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));
    
    fprintf(fw, "%d\n", viaggia(N, C));
    fclose(fr);
    fclose(fw);
    return 0;
}