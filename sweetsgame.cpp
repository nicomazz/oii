

//
//  main.cpp
//  sweet game
//
//  Created by Nicolò Mazzucato on 21/07/15.
//  Copyright (c) 2015 Nicolò Mazzucato. All rights reserved.
//

#include <iostream>
#include <bitset>
#include <assert.h>
using namespace std;
int mat[6][6] = {
    {1,2,3,-1,-1,-1},
    {4,5,6, 7,-1,-1},
    {8,9,10,11,12,-1},
    {13,14,15,16,-1,-1},
    {17,18,19,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1}};

pair<int,int> i_pos[20];
bool dp[1<<19];
bool lookup[1<<19];

int dtr[3] = {0,1,1};

int dtc[19][3] = {
    {1,1,0},
    {1,1,0},
    {1,1,0},
    {1,1,0},
    {1,1,0},
    {1,1,0},
    {1,1,0},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1},
    {1,0,-1}
};

#define notOut(kR,kC) (kR >= 0 && kC >= 0 && mat[kR][kC] != -1)
#define corI(kR,kC) (mat[kR][kC]-1)
#define occ(i) (bitmask & (1<<i))

int startBitmask = 0;

void print(int bitmask)
{
    bitset<19> b(bitmask);
    
    cout<<"  "<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
    cout<<" "<<b[3]<<" "<<b[4]<<" "<<b[5]<<" "<<b[6]<<endl;
    cout<<b[7]<<" "<<b[8]<<" "<<b[9]<<" "<<b[10]<<" "<<b[11]<<endl;
    cout<<" "<<b[12]<<" "<<b[13]<<" "<<b[14]<<" "<<b[15]<<endl;
    cout<<"  "<<b[16]<<" "<<b[17]<<" "<<b[18]<<endl;
    cout<<endl;
}
bool win(int bitmask)
{
    if ( bitmask == 0) return false; // perdita
    if (lookup[bitmask]) return dp[bitmask];
    lookup[bitmask] = true;
    
    bool & res = dp[bitmask];
    int r_att,c_att;
    int _bitmask;
    for (int i = 0; i < 19; i++)
        if (occ(i)) {
            _bitmask = bitmask;
            _bitmask &= ~(1<<i);
            if ( !win(_bitmask)) return res = true; // avversario perde
            
            for (int dir = 0; dir < 3; dir++){
                _bitmask = bitmask;
                _bitmask &= ~(1<<i);

                 r_att = i_pos[i+1].first + dtr[dir];
                 c_att = i_pos[i+1].second+ dtc[i][dir];
                while ( notOut(r_att, c_att) && (bitmask & (1<<corI(r_att, c_att)))){
                    _bitmask &= ~(1<<(mat[r_att][c_att]-1));
                    if ( !win(_bitmask)) return res = true;
                    c_att += dtc[corI(r_att, c_att)][dir];
                    r_att += dtr[dir];
                }
            }
        }
   
   return res = false; // perdi, l'avversario vince sempre
}
int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++){
            if ( mat[i][j] == -1) continue;
            i_pos[mat[i][j]] = {i,j};
        }
    
    int i = 0;
    char c;
    while ( i < 19){
        cin>>c;
        if ( c == 'O') startBitmask |= (1<<i);
        i++;
    }
    
    if (win(startBitmask))
        cout<<"Karlsson";
    else cout<<"Lillebror";
    
    
    return 0;
}
/*
 . . . . . O .. . O O .. . . .. . .
 */

