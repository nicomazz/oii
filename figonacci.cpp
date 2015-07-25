#include <stdio.h>
#include <assert.h>

long long seq[10000001];


int enumera(int N, int M) {
    
    seq[0] = -1;
    seq[1] = 0;
    long long sommaParziale = -1;
    
    for (int i = 2; i<= N; i++)
    {
        seq[i] = (seq[i-1]*(i-1)-sommaParziale % M + M)% M;
        sommaParziale+=seq[i-1];
    }
    
    
    return seq[N];
}



int main() {
    FILE *fr, *fw;
    int N, M;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &M));

    fprintf(fw, "%d\n", enumera(N, M));
    fclose(fr);
    fclose(fw);
    return 0;
}
