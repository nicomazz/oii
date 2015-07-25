#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>


#define REP(i,d,a) for (int i = (d); i < (a); i++)
#define x first
#define y second

using namespace std;
typedef pair<int,int> coord;

struct persona
{
    coord inizio;
    coord fine;
    bool operator<(const persona &B)const
    {
        if (inizio.x < B.inizio.x) return true;
        else if (inizio.x > B.inizio.x) return false;
        else if (inizio.x == B.inizio.x)
        {
            if (inizio.y < B.inizio.y) return true;
            else return false;
        }
    }
};

set<int> PallaToccata;

vector<persona> giocatori;

int distanza(coord uno, coord due)
{
    return abs(uno.x - due.x) + abs(uno.y- due.y);
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int x, y, Xm, Ym, N;

    in>>x>>y>>Xm>>Ym>>N;

    coord cane(Xm,Ym);
    REP(i,0,N)
    {
        persona tmp;
        in>>tmp.inizio.x>>tmp.inizio.y>>tmp.fine.x>>tmp.fine.y;
        giocatori.push_back(tmp);
    }
    sort(giocatori.begin(),giocatori.end());

    int Vicino = 10000;
    int giocatore = -1;
    REP(i,0,N)
    {
        int dist = distanza(cane,giocatori[i].inizio);
        if (dist < Vicino)
        {
            Vicino = dist;
            giocatore = i;
        }
    }

    PallaToccata.insert(giocatore);

    int arrivo[N];

    REP(i,0,N)
    {
        coord Iniz = giocatori[i].fine;
        int distMin = 10000;
        int k = -1;
        REP(j,0,N)
        {
            int dist = distanza(Iniz,giocatori[j].inizio);
            if (dist < distMin)
            {
                distMin = dist;
                k = j;
            }
        }
        arrivo[i] = k;
    }

    int Futuro = arrivo[giocatore];
    while (true)
    {
        if (PallaToccata.find(Futuro) != PallaToccata.end())
        {
            out<<PallaToccata.size();
            return 0;
        }
        else
        {
            PallaToccata.insert(Futuro);
            Futuro = arrivo[Futuro];
        }
    }

    out.close();
    return 0;
}
