//
//  main.cpp
//  alberoDaVisite
//
//  Created by nicomazz on 19/10/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

//#include <iostream>

#include <iostream>
#include <algorithm>
using namespace std;

#define max 1000000

struct postOrderNodo
{
    postOrderNodo()
    {}
    postOrderNodo(int i, int valore)
    {
        indice = i;
        val = valore;
    }
    int val, indice;
    
    bool operator<(const postOrderNodo & b )const
    {
        return val<b.val;
    }
};

bool foglie[max];
bool visitati[max];
postOrderNodo post[max];
int ind = 0;

void maketree(int *PRE, int & i, int* SIMM)
{
    int attuale = i;
    if (foglie[PRE[attuale]])
    {
        SIMM[ind++] = PRE[attuale];
    }
    else
    {
        maketree(PRE, ++i, SIMM); // sinistro
        SIMM[ind++] = PRE[attuale];
        maketree(PRE, ++i, SIMM); // destro
    }
}
void visita(int N, int *PRE, int *POST, int *SIMM )
{
    for (int i = 0; i < N; i++)
        post[i] = postOrderNodo(i,POST[i]);
    
    sort(post,post+N);

    // troviamo quali sono le foglie
    int ind;
    for (int i = 0; i < N; i++)
    {
        ind = post[PRE[i]-1].indice;
        if (visitati[ind-1] || ind == 0)
            foglie[PRE[i]] = true;
        visitati[ind] = true;
    }
    
    int i = 0;
    maketree(PRE, i, SIMM);
}
// 5 3 2 1
/*
int main()
{
    cout<<"lunghezza: "<<endl;

    int L;
    cin>>L;
    
    // +2 per l'inizio e le fine dove ci và -1
    int preOrder[L+2];
    int postOrder[L+2];
    int simm[L];
    // prende i dati da tastiera
    for (int i = 0; i < L; i++)
        cin>>preOrder[i];
    for (int i = 0; i < L; i++)
        cin>>postOrder[i];
    

    visita(L, preOrder, postOrder, simm );
    
    for (int i = 0; i < L ; i++)
        cout<<simm[i]<<" ";
    

    
    
    return 0;
}*/
/**
 
 7
 5 3 2 1 6 7 4
 2 6 7 1 3 4 5
 */

