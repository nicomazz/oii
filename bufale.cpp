#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/*
int findKth(int kth, long long * v, int s)
{
    int pivot;
    int minori, uguali;
    
    while (true)
    {
        minori = 0;
        uguali = -1;
        
        pivot = rand() % s;
        
        for (int i = 0; i < s; i++ )
        {
            if (v[i] < v[pivot]) minori++;
            else if (v[i] == v[pivot]) uguali++;
        }
        
        if (minori >= kth-uguali && minori <=kth) return v[pivot];
    }
}
*/


struct val
{
    long long V;
    int indice;
    bool operator<(const val &b)const
    {
        return (V < b.V);
    }
};
long long solve(int N, int* M, int* P)
{

    val ris[N];
    
    for (int i = 0; i < N; i++)
    {
        ris[i].V=  M[i]-P[i];
        ris[i].indice = i;
    }
    
    nth_element(ris, ris+N/2, ris+N);
    

    
    long long sum = 0;
    
    for (int i = 0; i < N/2 ; i++)
        sum += P[ris[i].indice];
    for (int i = N/2; i < N; i++)
        sum += M[ris[i].indice];
    

    return sum;
}
/*
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    srand (time(NULL));
    
    int N; in>>N;
    
    int M[N],P[N];
    
    for (int i = 0; i < N; i++)
        in>>M[i]>>P[i];
    
    out<<solve(N,M,P);

}*/