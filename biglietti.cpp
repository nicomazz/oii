#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
int compra(int N, int M, int A, int B) {
    int soldiUtilizzati = 0;
    int corseEffettuate = 0;
    int costoUnitarioCarnet = B/M;

    int resto = 0;
    if (costoUnitarioCarnet < A)
    {
        int carnetUtilizzati = N / M;
        resto = N % M;
        soldiUtilizzati = carnetUtilizzati*B;
        corseEffettuate = carnetUtilizzati*M;
        if (resto != 0)
        {
            if (A*resto < B) // convengono i biglietti
                soldiUtilizzati+= A*resto;
            else soldiUtilizzati+= B;
        }
    }
    else soldiUtilizzati = N*A;




    return soldiUtilizzati;
}

int main() {

    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
