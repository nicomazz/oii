#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int licenzia(int N, int B[], int C[]) {

    int cnt = 0;

    for (int i = 1; i < N; i++)
    {
        int att = C[i];
        do
        {
            if (att == -1)
            {
                if (B[i] > B[0])
                {
                    cnt++; break;
                }
            }
            else if (B[i] > B[att])
            {
                cnt++; break;
            }
            if (att != -1) att = C[att];
        } while (att != -1);
    }
        //if (B[i] > B[C[i]]) cnt++;

    return cnt;
}


int B[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));

    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
