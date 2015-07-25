#include <iostream>
#include <stdio.h>
#include <assert.h>

#define MAXN 100000

using namespace std;
int cnt[11];
void permuta(int N, int G[], int Gtilde[])
{
    //for (int n = 0; n < 10000; n+= 180)
     //)   cout<<n<<endl;
    for (int n = 0; n < N; n++)
        cnt[G[n]]++;


    cnt[0]--;
    Gtilde[N-1] = 0;
    for (int i = 0; i < 9; i+=2)
        if (cnt[i]) { Gtilde[N-2] = i; cnt[i]--; break;}

    int ind_gTilde = 0;
    for (int i = 9; i >= 0; i--)
        while (cnt[i]--)
        {
            Gtilde[ind_gTilde++] = i;
        }

  //  for (int i = 0; i < N; i++)
    //    cout<<Gtilde[i];
    // Mettete qui il codice della soluzione
}


int G[MAXN], Gtilde[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &G[i]));

    permuta(N, G, Gtilde);
    for (i=0; i<N; i++)
        fprintf(fw, "%d ", Gtilde[i]);
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
