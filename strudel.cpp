//
//  main.cpp
//  strudel scritto bene
//
//  Created by nicomazz on 22/03/15.
//  Copyright (c) 2015 nicomazz. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

#define MAXN 100100

typedef unsigned long long  ull;
typedef pair<int,int> pi;

int somma_mandorle = 0;
int somma_cannella = 0;

int l_max = 0;

int sum[MAXN];

// for (int i = 0; i < N; i++)
//   sum[i+1] = sum[i]+bonta[i];


int porziona(int N, int mandorle[], int cannella[]) {
    
    vector<int> bonta(N);
    vector<int> sum(N+1);

    //Il vettore bonta conterrà la differenza di cannella e mandorle
    for (int i = 0;i < N; i++)
        bonta[i] = (cannella[i]-mandorle[i]);
    
    //Creazione somme cumulate
    //all'indice 0 di sum è presente uno 0
    partial_sum(bonta.begin(),bonta.end(),sum.begin()+1);
    
    
    vector<int> minimi_parziali;
    vector<int> massimi_parziali;
    
    //Popolamento minimi parziali
    //il primo valore sarà senz'altro 0
    minimi_parziali.push_back(0);
    
    for (int i = 1; i<= N; i++) {
        // Se ci sono valori minori dell'ultimo presente nel vettore
        if ( sum[i] < sum[minimi_parziali.back()])
            //Mettiamo il loro indice in coda
            minimi_parziali.push_back(i);
    }
    
    //Popolamento massimi parziali
    massimi_parziali.push_back(N);
    for (int i = N-1; i >= 0; i--) {
        // Se ci sono valori maggiori dell'ultimo presente nel vettore
        if (sum[i]>= sum[massimi_parziali.back()])
            //Mettiamo il loro indice in coda
            massimi_parziali.push_back(i);
    }
    
    //Variabili che indicano i due cursori
    int fine = (int)massimi_parziali.size()-1;  // agirà sui massimi
    int inizio = 0;                             // agirà sui minimi
    int sol = 0;
    
    for (; inizio < minimi_parziali.size() && fine != 0; inizio++) {
        
        // Finchè possiamo scorrere avanti gli indici di fine, scorriamoli
        // in modo tale da aver la fetta più grande a partire dal minimo_parziale[inizio]
        // massimi_parziali[fine-1] indica il successivo massimo
        while (fine > 0 && sum[massimi_parziali[fine-1]] >= sum[minimi_parziali[inizio]]) fine--;
        
        //if (sum[massimi_parziali[fine]] - sum[minimi_parziali[inizio]] >= 0)
            sol = max(sol, massimi_parziali[fine] - minimi_parziali[inizio]);
    }
    
    return sol;
}
/*&& N-minimi_parziali[i].second > l_max */

int mandorle[MAXN], cannella[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &mandorle[i]));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &cannella[i]));
    
   //printf("%d",porziona(N, mandorle, cannella));
    fprintf(fw, "%d\n", porziona(N, mandorle, cannella));
    fclose(fr);
    fclose(fw);
    return 0;
}
