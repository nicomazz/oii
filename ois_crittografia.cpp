#include <stdio.h>
#include <assert.h>
#include <math.h>
int codifica(int N) {

    int K=N;
    int r;
    int d=0;

    int cnt= 0;
    while(K > 0) K/= 10, cnt++;

    K=N;


    while(K!=0){
        r=K%10;
        K/=10;
        d+= r*pow(10,--cnt);

    }


    return N+d;
}


int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", codifica(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
