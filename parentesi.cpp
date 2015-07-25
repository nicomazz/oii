#include <stdio.h>
#include <assert.h>
#include <stack>

#define MAXN 10000

using namespace std;

int controlla(int N, char E[]) {
    
    stack<int> pila;
    
    int i = 0;
    int top;
    while (i < N)
    {
        if (!pila.empty())
        {
            top = pila.top();
            if ((top == '<' && E[i] == '>') ||
                (top == '(' && E[i] == ')') ||
                (top == '[' && E[i] == ']') ||
                (top == '{' && E[i] == '}'))
                pila.pop();
            else pila.push(E[i]);
        }
        else pila.push(E[i]);
        i++;
    }
    if (pila.empty() == false) return -1;
    return  1;

}


char E[MAXN + 5]; // Maggiore di MAXN per contenere newline e null

int main() {
    FILE *fr, *fw;
    int N, i;
    
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d\n", &N));
    assert(fgets(E, MAXN + 5, fr) == E);
    E[N] = 0;
    
    if (controlla(N, E) < 0)
        fprintf(fw, "malformata\n");

    else
        fprintf(fw, "corretta\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
