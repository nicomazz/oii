#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

#define MAXN 100000
#include <stdio.h>
#include <assert.h>

#define MAXN 100000

void myReplace(string& str, string oldStr,string newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}
void ripulisci(int N, char remix[], char testo[]) {

    string p1 = "PaH";
    string p2 = "TuNZ";

    string rem(remix);
    myReplace(rem,p1," ");
    myReplace(rem,p2," ");

    int ind = 0;
    int indTesto = 0;

    bool prev_spazio = false;

    while (rem[ind] == ' ') ind++;

    for (; ind < rem.size();ind ++)
    {
        if (prev_spazio && rem[ind] == ' ') continue; // va avanti

        if (rem[ind] == ' ')
        {
         //   cout<<"ora spazio"<<rem[ind]<<endl;
            testo[indTesto++] = rem[ind];
            prev_spazio = true;
        }
        else
        {
            //cout<<"ora parola"<<rem[ind]<<endl;
            prev_spazio = false;
            testo[indTesto++] = rem[ind];
        }
    }


  //  int ind1 = 0, ind2 = 0;
   // int ind_ris = 0;
    /*for (int i = 0; i<  N; i++)
    {
        if (remix[i] == p1[0])
        {
            bool diverso = false;
            for (int j = 1; j < 3; j++)
                if (remix[i+j] != p1[j]) {diverso =true; break;}
            if (diverso == true)
            {
                 for (int j = 0; j < 3; j++)
                    testo[ind_ris++] = remix[i];
            }
            else i+= 3;
        }
        else if (remix[i] == p2)
        {
            bool diverso = false;
            for (int j = 1; j < 4; j++)
                if (remix[i+j] != p2[j]) {diverso =true; break;}
            if (diverso == true)
            {
                 for (int j = 0; j < 4; j++)
                    testo[ind_ris++] = remix[i];
            }
            else i+= 3;
        }
    }
    */
}


char remix[MAXN+1], testo[MAXN+1]; // Maggiore di MAXN per contenere newline

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(remix == fgets(remix, N + 1, fr));

    ripulisci(N, remix, testo);
    fprintf(fw, "%s\n", testo);
    fclose(fr);
    fclose(fw);
    return 0;
}
