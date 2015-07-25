#include <iostream>

using namespace std;
#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int passeggia(int N, int H[]) {

    int segno[MAXN];

    for (int i = 0; i < N-1;i++)
    {
        if (H[i] < H[i+1]) segno[i] = 1;
        else segno[i] = -1;
    }

    int att = segno[0] == 1 ? -1:1;

    int ris = 1;
    for (int i = 0; i< N-1; i++)
    {
        if (segno[i] != att) {att = segno[i]; ris++;}
    }
    return ris;
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", passeggia(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
