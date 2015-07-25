

#include <stdio.h>
#include <assert.h>
#include "math.h"


int allocaa(int N) {

    if (N == 1 || N == 2 || N == 3) return 1;

    int rad = (int) sqrt(N);
    
    int Maxim = 0;
    for (int i = 2; i <= rad; i++)
    {
        int tmp = i*i;
        while( tmp<=N )
        {
            if (tmp > Maxim) Maxim = tmp;
            tmp*=i;
        }
        if (Maxim == N) return Maxim;
    }
    
    
    return Maxim;
}


int main() {
    FILE *fr, *fw;
    int N;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", allocaa(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
