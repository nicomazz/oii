#include <iostream>
#include <fstream>

using namespace std;

int mat[101][101];
int sol[101][101];

int sX[] = {-1,0};

void visita(int r,int c)
{
    for (int i = 0; i < 2; i++)
    {
        if (c+sX[i] >= r || c+sX[i] < 0 || r < 0);
        else if (sol[r][c] + mat[r-1][c+sX[i]] > sol[r-1][c+sX[i]])
        {
            sol[r-1][c+sX[i]] =sol[r][c] + mat[r-1][c+sX[i]];
            visita(r-1,c+sX[i]);
        }
    }
}

int main()
{
    ifstream in("input.txt");
	ofstream out("output.txt");
    
    int N;
    in>>N;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++ )
            in>>mat[i][j];
    
    for (int i = 0; i < N; i++)
    {
        sol[N-1][i] = mat[N-1][i];
    }
    
    for (int i = 0; i < N; i++)
        visita(N-1,i);
    
  out<<sol[0][0];
}