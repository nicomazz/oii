void Vernicia(int indice, int colore);



void Diversifica(int N, int colore[]) {
    bool coloreUsato[N+1];
    bool daColorare[N+1];
    for (int i = 0; i <= N;i++)
        coloreUsato[i] = daColorare[i] = false;
    
    
    for (int i = 0; i < N; i++)
        if (coloreUsato[colore[i]])
            daColorare[i] = true;
        else coloreUsato[colore[i]] = true;
    
    int att = 1;
    for (int i = 1; i < N; i++)
        if (daColorare[i])
        {
            while (coloreUsato[att]) att++;
            coloreUsato[att] = true;
            Vernicia(i,att++);
        }
}
