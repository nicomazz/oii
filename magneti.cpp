#include <stdio.h>
#include <assert.h>

#define MAXN 100000


int gira(int N, char descrizione[]) {

    int piu_meno = 0, meno_piu = 0;
    
    int prec = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (descrizione[i] == '+')
        {
            if (prec == '-') meno_piu++,prec = 0;
            else prec = '+';
        }
        else if (descrizione[i] == '-')
        {
            if (prec == '+')piu_meno++,prec = 0;
            else prec = '-';
        }
    }
    
    if (piu_meno < meno_piu) return piu_meno;
    return meno_piu;
    
}


char descrizione[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(descrizione, MAXN + 5, fr) == descrizione);
    descrizione[N] = 0;
    
    fprintf(fw, "%d\n", gira(N, descrizione));

//    printf("%d\n", gira(N, descrizione));

    fclose(fr);
    fclose(fw);
    return 0;
}
