#include <stdio.h>
#include <assert.h>
#include <iostream>
#define MAXN 100000
using namespace std;

bool vivo[MAXN]; // inizialmente tutti vivi
int i,j;
bool f = false;


int mangia(int N, int direzione[], int dimensione[]) {

    // inizialmente tutti vivi
    for (i = 0; i < N; i++)
        vivo[i] = true;

    // controllare ogni volta
    for (i = N-1; i >= 0; i--)
    {
        f = false;
        if (direzione[i] == 1)
        {
            // tutti quelli a sx
            for (j = i-1; f == false && j >= 0 ; j--)
            {
                if (direzione[i] - direzione[j] == 1)
                {
                    if (dimensione[i] > dimensione[j])  vivo[j] = false;
                    else f = true;
                }
            }
            f = true;
        }
        else
        {
            // tutti quelli a dx
            for (j = i+1; j < N && !f; j++)
            {
                if (direzione[i] - direzione[j] == -1) // uno 0 e uno 1
                {
                    if (dimensione[i] > dimensione[j])
                        vivo[j] = false;
                    else
                        f = true;

                }
            }
            f = true;
        }
    }

    int sum = 0;
    for (i = 0; i < N; i++)
    {
        if (vivo[i]) ++sum;
    }
    return sum;
}


int direzione[MAXN], dimensione[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d%d", &direzione[i], &dimensione[i]));

    fprintf(fw, "%d\n", mangia(N, direzione, dimensione));
    fclose(fr);
    fclose(fw);
    return 0;
}
