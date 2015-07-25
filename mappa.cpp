//
//  main.cpp
//  mappa antica
//
//  Created by nicomazz on 20/12/14.
//  Copyright (c) 2014 nicomazz. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
int mappa[100][100];
int N;
void attraversa(int i, int j)
{
    for (int r=-1; r<2; r++)
        for (int s=-1; s<2; s++)
        {
            if (i+r<0 || i+r>N-1 || j+s < 0 || j+s > N-1);
            else if (mappa[i+r][j+s] == 0 || mappa[i+r][j+s] > mappa[i][j] + 1
                     )
            {
                mappa[i+r][j+s] = mappa[i][j] + 1;
                attraversa(i+r,j+s);
            }
        }
}
int main()
{
    fstream in,out;
    in.open("input.txt",ios::in);
    out.open("output.txt",ios::out);
    in >> N;
    for (int i=0;i < N;i++)
        for (int j=0;j <N ;j++)
        {
            char c;
            in >> c;
            if (c=='*')
                mappa[i][j]=0;
            else
                mappa[i][j]=-1;
        }
    mappa[0][0] = 1;
    attraversa(0,0);
    out << mappa[N-1][N-1];
    return 0;
}