#include <iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;

    string V[N];

    for (int i = 0; i < N; i++)
        cin>>V[i];

    /// qui marsietta deve scrivere la soluzione
    int LMAX = V[N].size();
    int lPref = 0;

   for (int a=0; a<LMAX; a++){
       char c= V[0][a];
      for(int b=1; b< N; b++){
        if (V[b][a] != c)
        {
            cout<<lPref;
            return 0;
        }
      }
      lPref++;
   }
      return 0;
}
