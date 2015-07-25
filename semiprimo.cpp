#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAXN 1000100
bool primo(int N)
{
    if (N == 2) return true;
    if (N % 2 == 0) return false;

    for (int i = 3; i*i <= N; i+=2 )
        if (N % i == 0) return false;
    return true;
}
int main()
{

    ifstream in("input.txt");
    ofstream out("output.txt");
/*
for(int i = 1; i < 1000; i++)
    if (primo(i)) cout<<i<<endl;
*/
    int N;
    in>>N;


    vector<int> divisori;
    int cnt_div = 0;
    for(int i = 2; i <= N/2; i++)
    {
        if (N % i == 0)
        {
            cnt_div++;
            if (cnt_div > 2) {out<<-1; return 0;}
            else
                divisori.push_back(i);
        }
    }
    if (cnt_div == 2 &&
        divisori[0]*divisori[1] == N &&
        primo(divisori[0]) && primo(divisori[1]))
    {
        out<<divisori[0]<<" "<<divisori[1];
        return 0;
    }
    else if (cnt_div == 1 &&
             divisori[0]*divisori[0] == N &&
             primo(divisori[0]))
    {
        out<<divisori[0]<<" "<<divisori[0];
        return 0;
    }

    out<<-1;

    return 0;
}
