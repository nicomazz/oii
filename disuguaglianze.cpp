#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
string versi;
int N;

#define MAXN 1000100
int sol[MAXN];
void inserisci(int i, int pos)
{
    if (pos == 0) sol[0] = i;
    else if (versi[pos-1] == '<')
    {
        if (sol[pos-1] < i)
        {
            sol[pos] = i;
        }
        else
        {
            sol[pos] = sol[pos-1];
            inserisci(i,pos-1);
        }
    }
    else if (versi[pos-1] == '>')
    {
        if (sol[pos-1] > i)
        {
            sol[pos] = i;
        }
        else
        {
            sol[pos] = sol[pos-1];
            inserisci(i,pos-1);
        }
    }
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");


    in>>N;
    in>>versi;

    for (int i = 1; i <=N; i++)
    {
        inserisci(i,i-1);
    }
    for (int i = 0; i < N; i++)
        out<<sol[i]<<" ";

    return 0;
}
