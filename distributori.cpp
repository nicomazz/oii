#include <stdio.h>
#include <assert.h>
#include <iostream>

#define MAXN 100000
using namespace std;
int rifornisci(int N, int M, int K, int D[]) {

   int Att = 0;
   int d = 0; // distributori usati
   for (int i = 0; i < N; i++)

       if (D[i] > Att+M)
       {
           if (D[i-1] > K) return d;
           d++;
           Att = D[i-1];
       }

    if (K - Att > M ) d++;

   return d;
}


int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, M, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%d %d %d", &N, &M, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", rifornisci(N, M, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}
