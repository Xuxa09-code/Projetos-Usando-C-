/*LALLIER PALLU CARDOSO DE FARIA 1C*/
#include "conio.h"
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"
    char op,mensav[81],pchave[100],mensa[81][81],vet[81][81];
    char min,cripto[80],e,alfa[100],sub[100],alfa_poli[100][100];
    int tam_linha,tam_mensa,tam_chave,tam_coluna,cont,chave,chave1,l,inicio,destino,origem,coluna,linha,k;
    void solucao_espaco(void){
        int i;
        for(i=1;i<=(tam_linha*tam_coluna);i++){
            if(cripto[i]=='@')
                cripto[i]=' ';
        }
    }
/////////////////////Criptografia por substuicao simples//////////////////////////
    void inici_substituicao(void){
        int i,letra;
        char k;
        k=240;
        printf("\n\nCriando o alfabeto e o Sub\n");
        i=1;
        letra=65;
        while(i<=52){
            alfa[i]=letra;
            i++;
            letra++;
            if(i==27)
                letra=97;
        }
        alfa[i]=' ';
        printf("\n\nImpressao do Alfabeto\n");
        for(i=1;i<=53;i++)
            printf("%c",alfa[i]);
        i=1;
        letra=90;
        while(i<=52){
            sub[i]=letra;
            i++;
            letra--;
            if(letra==64)
                letra=122;
        }
        sub[i]=' ';
        printf("\n\nImpressao do Sub\n");
        for(i=1;i<=53;i++)
            printf("%c",sub[i]);
    }
    void descriptografia_substituicao(void){
    int i,t;
        i=1;
        while(i<=tam_mensa){ // variando o i para o mensa atй o tamanho da frase digitada
            t=1;
            while(t<=52){ // variando t para o vetor alfa
                if(mensav[i]==sub[t]){
                    cripto[i]=alfa[t]; // atribuiзгo do elemento na posiзгo sub para o cripto.
                }
                if(mensav[i]==' ')
                    cripto[i]='@';
                t++;
            }
            i++;
        }
//        printf("\n\nImpressao do vetor criptografado\n\n");
        for(i=1;i<tam_mensa;i++){
            printf("%c",cripto[i]);
        }
    }
    void criptografia_substituicao(void){
    int i,t;
      // criptografando
        i=1;
        while(i<=tam_mensa){ // variando o i para o mensa atй o tamanho da frase digitada
            t=1;
            while(t<=52){ // variando t para o vetor alfa
                if(mensav[i]==alfa[t]){
                    cripto[i]=sub[t]; // atribuiзгo do elemento na posiзгo sub para o cripto.
                }
                    if(mensav[i]==' ')
                        cripto[i]='@';
                t++;
            }
            i++;

        }
        // impressгo do vetor cripto
//        printf("\n\nImpressao do vetor criptografado\n\n");
        for(i=1;i<tam_mensa;i++){
            printf("%c",cripto[i]);
        }
    }
///////////////////////////////////////////////////////////////////////////
//////////////////////criptografia por cesar///////////////////////////////
    void chave_cesar(void){
        int i=1;
        while(i==1){
            printf("\n\nEntre com um valor maior que 0!\n");
            scanf("%d",&chave);
            if(chave>=0)
                i=0;
            else
                printf("\nOpção Invalida, tente novamente!");
        }
        getchar();
    }
    void criptografia_cesar(void){
        int t,c,i;
        // criptografia
        for(i=1;i<=tam_mensa;i++){ // variando ate o tamanho da mensagem
            for(t=0;t<=52;t++){ // variando o alfabeto
                if(mensav[i]==alfa[t]){ // procurando a letra da mensagem no alfabeto
                    c=t+chave; // calculando o cripto
                    c=c%52; // resto da divisão por 27
                    cripto[i]=alfa[c];
                }
            }
        }
        // impressão da criptografia
//        printf("\n\nImpressão da mensagem Criptografa pelo Algoritmo da Cifra de Cesar\n");
        for(i=1;i<=tam_mensa;i++)
            printf("%c",cripto[i]);
        getchar();
    }
    void descriptografia_cesar(void){
        int t,c,i;
        // criptografia
        for(i=1;i<=tam_mensa;i++){ // variando ate o tamanho da mensagem
            for(t=0;t<=52;t++){ // variando o alfabeto
                if(mensav[i]==alfa[t]){ // procurando a letra da mensagem no alfabeto
                    c=t-chave; // calculando o cripto
                    c=c%52;
                    if(c<0)
                        c=c+52; // resto da divisão por 27
                    cripto[i]=alfa[c];
                }
            }
        }
        // impressão da criptografia
//        printf("\n\nImpressão da mensagem Criptografa pelo Algoritmo da Cifra de Cesar\n");
        for(i=1;i<=tam_mensa;i++)
            printf("%c",cripto[i]);
        getchar();
    }
    void inicio_cesar(void){
        int letra,letra2,i;
        alfa[0]=' ';
        i =1;
        letra=65;
        while(i<=52){
            alfa[i]=letra;
            letra++;
            i++;
            if(i==27)
                letra=97;
        }
        printf("\n\nImpressão do vetor ALfa \n\n ");
        for(i=0;i<=52;i++)
            printf("%c",alfa[i]);
    }
///////////////////////////////////////////////////////////////////////////
////////////////////////// cifra poli alfa ////////////////////////////////
    void matriz_poli(void){
        // para cada letra da mensagem da linha 1 vamos assossiar na linha 2 uma letra da palavra chave
        int i=1,j=1;
        for(i=1;i<=tam_mensa;i++)
            mensa[1][i]=mensav[i];
        i=1,j=1;
        while(i<=tam_mensa){ // variando para cada letra da mensagem
            mensa[2][i]=pchave[j];
            // printf("\n%c",pchave[j]);// colocamos na linha 2 as letras da palavra chave para cada letra da mensagem
            j++;
            if(j>tam_chave) // se j for maior que o tamanho da palavra chave, voltamos para primeira posiþÒo da palavra chave
                j=1;
            i++;
        }
        // impressÒo da matriz mensa
        printf("\n\nImpressao da matriz Mensagem \n");
        for(i=1;i<=2;i++){ // variando as linhas
            printf("\n");
            for(j=1;j<=tam_mensa;j++) // variando as colunas assossiada a tamanho da mensagem
                printf("%c",mensa[i][j]);
        }
    }
    void alfabeto_polialfa(void){
        int letra,i,j;
        //Montagem da alfa
        // limpando a matriz
        for(i=1;i<=53;i++){
            for(j=1;j<=81;j++)
                alfa_poli[i][j]=' ';
        }
        letra=65;
        i=1; //variando as colunas da matriz alfa
        while(i<=52){
            alfa_poli[1][i]=letra;
            if(letra==90){
                letra=96;
//                alfa[1][27]=' ';
//                i=27;
            }
            i++;
            letra++;
        }
        // Vamos colocar a chave digitada pelo usußrio na coluna 1 da matriz a partir da linha 2.
        j=2;
        for(i=1;i<=tam_chave;i++){
            alfa_poli[j][1]=pchave[i];
            j++;
        }
        // impressÒo do alfa para ver se esta ok
        for(i=1;i<=tam_chave+1;i++){ // as linhas da matriz sÒo o tamanho da palavra chave + 1
            printf("\n");
            for(j=1;j<=53;j++) // j esta variando as colunas que sÒo de 1 a 26
                printf("%c",alfa_poli[i][j]);
        }
        getchar();
        // Preenchendo a matriz alfa com o restantes das letras baseado na palavra chave fornecida
        for(i=2;i<=tam_chave+1;i++){
            letra=alfa_poli[i][1]+1;
            for(j=2;j<=52;j++){
                if(letra=='!')
                    letra=65;
                if(letra>'z') // verifica se chegou em Z se sim volta para Letra A
                    letra=65;
                alfa_poli[i][j]= letra;
                if(letra==90)
                    letra=96;
                if(letra=='z') // verifica se chegou em Z se sim volta para Letra A
                    letra=65;
                else
                    letra++; // soma um a letra para poder obter o proximo caracter
            }

        }
        // impressÒo do alfa completo para ver se estß ok
        for(i=1;i<=tam_chave+1;i++){
            printf("\n");
            for(j=1;j<=53;j++)
                printf("%c",alfa_poli[i][j]);
        }
        getchar();
    }
    void criptografia_polialfa(void){
        int i,j,k;
        // Algoritmo de Cripoto Polialfa
        for(i=1;i<=tam_mensa;i++){ // o i tem as posiþ§es das letras da mensagem
            for(j=1;j<=52;j++){ // o j tem as colunas da linha do alfabeto
                if(mensa[1][i]==alfa_poli[1][j]){ // o j tem a coluna
                    for(k=2;k<=tam_chave+1;k++){ // o k tem a linha, tam_chave+1 para pegar todas as letras da palavra chave, pois estamos comencando na linha 2
                        if(mensa[2][i]==alfa_poli[k][1]){
                            cripto[i]=alfa_poli[k][j];
                             k=tam_chave+1;
                             j=53;
                        }
                    }
                }
            }
            if(mensa[1][i]==' ')
                cripto[i]='@';
        }
        // impressÒo da criptografia
        printf("\n\nVetor Criptografado pelo Algoritmo Polialfabetico\n\n");
        for(i=1;i<=tam_mensa;i++)
            printf("%c", cripto[i]);
        getchar();
    }
    void descriptografia_polialfa(void){
        int i,j,k;
        // Algoritmo de Cripoto Polialfa
        for(i=1;i<=tam_mensa;i++){ // o i tem as posiþ§es das letras da mensagem
            for(k=2;k<=tam_chave+1;k++){ // o k tem a linha, tam_chave+1 para pegar todas as letras da palavra chave, pois estamos comencando na linha 2
                if(mensa[2][i]==alfa_poli[k][1]){
                    for(j=1;j<=52;j++){
                        if(alfa_poli[k][j]==mensa[1][i]){
                            cripto[i]=alfa_poli[1][j];
                            k=tam_chave+2;
                            j=53;
                        }
                    }
                }
            }
            if(mensa[1][i]==' ')
                cripto[i]='@';
            if(mensa[1][i]=='@')
                cripto[i]=' ';
        }
        // impressÒo da criptografia
        printf("\n\nVetor Criptografado pelo Algoritmo Polialfabetico\n\n");
        for(i=1;i<=tam_mensa;i++)
            printf("%c", cripto[i]);
        getchar();
    }
/////////////////////////////////////////////////////////////////////////////////////
//////////////////////// transposicao simples ///////////////////////////////////////
    void organizacao_matriz(void){
        int i,t,j,min,min0;
        for(j=1;j<=tam_chave;j++){
            mensa[1][j]=pchave[j];
            mensa[0][j]=j;
        }
        t=1;
        i=2;
        while(t<=tam_mensa){
            for(j=1;j<=tam_chave;j++){
                mensa[i][j]=mensav[t];
                t++;
            }
            i++;
        }
        tam_linha=i-1;
        for(i=1;i<=tam_linha;i++){
            printf("\n");
            for(j=1;j<=tam_chave;j++)
                printf("%c",mensa[i][j]);
        }
        for(j=1;j<=tam_chave;j++){
            vet[1][j]=mensa[1][j];
            vet[0][j]=mensa[0][j];
        }
        for(j=2;j<=tam_chave;j++){
            min=vet[1][j];
            min0=vet[0][j];
            i=j;
            while(min<vet[1][i-1]){
                vet[1][i]=vet[1][i-1];
                vet[0][i]=vet[0][i-1];
                i--;
            }
            vet[1][i]=min;
            vet[0][i]=min0;
        }
    }
    void criptografia_transposicaoSimples(void){
        int k=1,i,j,t,min,min0;
        for(t=1;t<=tam_chave;t++){
            for(j=1;j<=tam_chave;j++){
                if(mensa[0][j]==vet[0][t]){
                    for(i=2;i<=tam_linha;i++){
                        cripto[k]=mensa[i][vet[0][t]];
                        if(cripto[k]!='\n')
                            k++;
                    }
                    cripto[k]='_';
                    k++;
                }
            }
        }
        printf("\n");
        for(i=1;i<k-1;i++)
           printf("%c",cripto[i]);
    }
    void desorganizacao_matriz(void){
        int i,j,min,min0,t;
        for(j=1;j<=tam_chave;j++){
            mensa[1][j]=pchave[j];
            mensa[0][j]=j;
        }
        for(j=1;j<=tam_chave;j++){
            vet[1][j]=mensa[1][j];
            vet[0][j]=mensa[0][j];
        }
        for(j=2;j<=tam_chave;j++){
            min=vet[1][j];
            min0=vet[0][j];
            i=j;
            while(min<vet[1][i-1]){
                vet[1][i]=vet[1][i-1];
                vet[0][i]=vet[0][i-1];
                i--;
            }
            vet[1][i]=min;
            vet[0][i]=min0;
        }
        t=1;
        tam_linha=0;
        for(i=1;i<=tam_chave;i++){
            for(j=2;j<=tam_mensa;j++){
                if(mensav[t]=='_'){
                    if(tam_linha<j)
                        tam_linha=j;
                    j=tam_mensa+2;
                }else{
                    vet[j][i]=mensav[t];
                }
                t++;
            }
        }
    }
    void descriptografia_transposicaoSimples(void){
        int t,k=1,i,j;
        for(t=1;t<=tam_linha;t++){
            printf("\n");
            for(i=1;i<=tam_chave;i++)
                printf("%c",vet[t][i]);
        }
        for(t=1;t<=tam_chave;t++){
            for(j=1;j<=tam_chave;j++){
                if(mensa[0][t]==vet[0][j]){
                    for(i=2;i<=tam_linha;i++){
                        if(vet[i][j]!='\n')
                            mensa[i][mensa[0][t]]=vet[i][j];
                    }
                }
            }
        }
        for(j=1;j<=tam_linha;j++){
            printf("\n");
            for(i=1;i<=tam_chave;i++)
                printf("%c",mensa[j][i]);
        }
        k=1;
        for(j=2;j<=tam_linha;j++){
            for(i=1;i<=tam_chave;i++){
                cripto[k]=mensa[j][i];
                k++;
            }
        }
        solucao_espaco();
        printf("\n");
        for(i=1;i<k;i++)
           printf("%c",cripto[i]);
    }
////////////////////////////////////////////////////////////////////////////////
///////////////////////////transposicao rota////////////////////////////////////
    void veri_inici(void){
        switch(chave1){
            case 1: linha= 1; coluna= 1; break;
            case 2: linha= 1; coluna= tam_coluna; break;
            case 3: linha= tam_linha; coluna= tam_coluna; break;
            case 4: linha= tam_linha; coluna= 1; break;
        }
        if(e=='C')
            cripto[1]=mensa[linha][coluna];
        else
            mensa[linha][coluna]=mensav[1];
    }
    void verifica(void){
        if(chave=='H'){
            if((chave1==1)||(chave1==3)){
                inicio=1;
                switch(chave1){
                    case 1: origem=1; destino=tam_coluna; k=-1; l= 1; break;
                    case 3: origem=tam_coluna; destino=1; k= 1; l=-1; break;
                }
            }else{
                inicio=0;
                switch(chave1){
                    case 2: origem=1; destino=tam_linha; k=-1; l= 1; break;
                    case 4: origem=tam_linha; destino=1; k= 1; l=-1; break;
                }
            }
        }else{
            if((chave1==1)||(chave1==3)){
                inicio=0;
                switch(chave1){
                    case 1: origem=1; destino=tam_linha; k=-1; l= 1; break;
                    case 3: origem=tam_linha; destino=1; k= 1; l=-1; break;
                }
            }else{
                inicio=1;
                switch(chave1){
                    case 2: origem=tam_coluna; destino=1; k= 1; l=-1; break;
                    case 4: origem=1; destino=tam_coluna; k=-1; l= 1; break;
                }
            }
        }
    }
    void tamanhos(void){
        int cont=1;
        tam_coluna=sqrt(tam_mensa);
        tam_linha=tam_coluna;
        while(tam_mensa>(tam_coluna*tam_linha)){
            if(cont==1)
                tam_coluna++;
            else
                tam_linha++;
            cont++;
        }
    }
    void montagem_matriz_rota(void){
        tamanhos();
        int t,j,i;
        t=1;
        for(j=1;j<=tam_coluna;j++){
            for(i=1;i<=tam_linha;i++){
                mensa[i][j]=mensav[t];
                t++;
                if(t>tam_mensa){
                    i=tam_linha+1;
                    j=tam_coluna+1;
                }
            }
        }
        for(i=1;i<=tam_linha;i++){
            printf("\n");
            for(j=1;j<=tam_coluna;j++)
                printf("%c ",mensa[i][j]);
        }
    }
    void cripitografia_rota(void){
        int cont_destino=1,cont_origem=1,i,j,t=2,y=0,x=1;
        veri_inici();
        i=linha;
        j=coluna;
        while(t<=(tam_linha*tam_coluna)){
            verifica();
            if(cont_destino==4){
                y++;
                cont_destino=0;
            }
            if(cont_origem==6){
                x++;
                cont_origem=2;
            }
            if(destino>origem){
                if(inicio==0){
                    for(i=origem+(l*x);i<=destino+(k*y);i++){
                        cripto[t]=mensa[i][j];
                        t++;
                    }
                    i--;
                }else{
                    for(j=origem+(l*x);j<=destino+(k*y);j++){
                        cripto[t]=mensa[i][j];
                        t++;
                    }
                    j--;
                }
            }else{
                if(inicio==0){
                    for(i=origem+(l*x);i>=destino+(k*y);i--){
                        cripto[t]=mensa[i][j];
                        t++;
                    }
                    i++;
                }else{
                    for(j=origem+(l*x);j>=destino+(k*y);j--){
                        cripto[t]=mensa[i][j];
                        t++;
                    }
                    j++;
                }
            }
            cont_origem++;
            cont_destino++;
            if(chave=='H'){
                chave1++;
                if(chave1>4)
                    chave1=1;
            }
            if(chave=='A'){
                chave1--;
                if(chave1<1)
                    chave1=4;
            }
        }
        for(i=1;i<=(tam_coluna*tam_linha);i++)
            printf("%c",cripto[i]);
    }
    void desmontagem_matriz_rota(void){
        int cont_destino=1,cont_origem=1,i,j,t=2,y=0,x=1;
        tamanhos();
        veri_inici();
        i=linha;
        j=coluna;
        while(t<=(tam_linha*tam_coluna)){
            verifica();
            if(cont_destino==4){
                y++;
                cont_destino=0;
            }
            if(cont_origem==6){
                x++;
                cont_origem=2;
            }
            if(destino>origem){
                if(inicio==0){
                    for(i=origem+(l*x);i<=destino+(k*y);i++){
                        mensa[i][j]=mensav[t];
                        t++;
                    }
                    i--;
                }else{
                    for(j=origem+(l*x);j<=destino+(k*y);j++){
                        mensa[i][j]=mensav[t];
                        t++;
                    }
                    j--;
                }
            }else{
                if(inicio==0){
                    for(i=origem+(l*x);i>=destino+(k*y);i--){
                        mensa[i][j]=mensav[t];
                        t++;
                    }
                    i++;
                }else{
                    for(j=origem+(l*x);j>=destino+(k*y);j--){
                        mensa[i][j]=mensav[t];
                        t++;
                    }
                    j++;
                }
            }
            cont_origem++;
            cont_destino++;
            if(chave=='H'){
                chave1++;
                if(chave1>4)
                    chave1=1;
            }
            if(chave=='A'){
                chave1--;
                if(chave1<1)
                    chave1=4;
            }
        }
        getchar();
        for(i=1;i<=tam_linha;i++){
            printf("\n");
            for(j=1;j<=tam_coluna;j++)
                printf("%c",mensa[i][j]);
        }
    }
    void descripitografia_rota(void){
        char i,j,t=1;
        for(j=1;j<=tam_coluna;j++){
            for(i=1;i<=tam_linha;i++){
                cripto[t]=mensa[i][j];
                t++;
            }
        }
        solucao_espaco();
        printf("\n");
        for(t=1;t<=(tam_coluna*tam_linha);t++)
            printf("%c",cripto[t]);
    }
    void montagem_exemplo(void){
        int i,j;
        char vet_rota[6][6];
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++)
                vet_rota[i][j]='.';
        }
        vet_rota[1][1]='1';
        vet_rota[1][5]='2';
        vet_rota[5][5]='3';
        vet_rota[5][1]='4';
        for(i=1;i<=5;i++){
            printf("\n");
            printf("\t\t");
            for(j=1;j<=5;j++)
                printf("%c ",vet_rota[i][j]);
        }
    }
    void chave_rota(void){
        printf("\nComo chave, na criptografia por rota, voce tem que escolher o sentido sentido e ponto de inicio.");
        chave=' ';
        while((chave!='H')&&(chave!='A')){
            printf("\nSentido:\nH-Horario\tA-Anti-horário\n");
            chave=getchar();
            chave=toupper(chave);
            getchar();
        }
        chave1=5;
        while((chave1>4)||(chave1<1)){
            printf("\n\t    Ponto de Inicio:\n");
            montagem_exemplo();
            printf("\n1-Superior Esquerdo\t2-Superior Direito\n3-Inferior Direito\t4-Inferior Esquerdo\n");
            scanf("%d",&chave1);
        }
    }
    void zerando_mat(void){
        int i,j;
        for(i=1;i<=80;i++){
            for(j=1;j<=80;j++)
                mensa[i][j]='A';
        }
    }
////////////////////////////////////////////////////////////////////////////////
    void chave_palavra(void){
        int i=1;
        // leitura da palavra chave
        printf("\nEntre com a palavra chave no Maximo 80 caracteres\n\n");
        while(((pchave[i]=getchar())!='\n') && (i<=80)){
            if(op=='T')
                pchave[i]=toupper(pchave[i]);
            i++;
        }
        tam_chave=i-1; //pois o I esta com um valor a mais
    }
    void escolha(void){
        e=' ';
        while((e!='D')&&(e!='C')&&(e!='d')&&(e!='c')){
            printf("\nDeseja:\nC- criptograr\tD- descriptografar\n");
            e=getchar();
            e=toupper(e);
            if((e!='D')&&(e!='C'))
                printf("\nOpção invalida, Tente novamente\n");
                getchar();
        }
    }
    void mensagem(void){
        int i;
        printf("\n\nEntre com uma mensagem de no max 800 caracteres\n\n");
        i=1;
        while(((mensav[i]=getchar()) !='\n' ) && (i<=80)){
            i++;
        }
        tam_mensa=i-1;
    }
    void problema_espaco(void){
        int i;
        for(i=1;i<=tam_mensa;i++){
            if(mensav[i]!=' ')
                mensav[i]=mensav[i];
            else
                mensav[i]='@';
        }
    }
    int main(void){
        int ko,ok,i,j;
        setlocale(LC_ALL,"Portuguese");
        op=' ';
        while(op!='S'){
            for(i=1;i<=80;i++){
                for(j=1;j<=80;j++){
                    mensa[i][j]=' ';
                    vet[i][j]=' ';
                }
            }
            op=' ';
            while((op!='S')&&(op!='C')&&(op!='A')&&(op!='T')&&(op!='R')&&(op!='I')){
                printf("\n\nO que você deseja Fazer ? S, C, A, T, T ou I");
                printf("\n\t\t Criptografia Substituição Simples - S ");
                printf("\n\t\t Criptografia Cifra de Cesar - C ");
                printf("\n\t\t Criptografia Poli-Alfa - A ");
                printf("\n\t\t Criptografia Transposição Simples - T ");
                printf("\n\t\t Criptografia Transposição por Rota - R ");
                printf("\n\t\t Sair - I\n");
                printf("\n\t\t Opção = ");
                op=getchar();
                op=toupper(op);
            }
            getchar();
            if(op=='I')
                exit(0);
            escolha();
            mensagem();
            problema_espaco();
            switch(op){
                case 'S':
                    inici_substituicao();
                    if(e=='C'){
                        printf("\n\nCRIPTOGRAFIA\n");
                        criptografia_substituicao();
                    }else{
                        printf("\n\nDESCRIPTOGRAFIA\n");
                        descriptografia_substituicao();
                    }
                break;
                case 'C':
                    inicio_cesar();
                    chave_cesar();
                    //mensagem();
                    //escolha();
                    if(e=='C'){
                        printf("\n\nCRIPTOGRAFIA\n");
                        criptografia_cesar();
                    }else{
                        printf("\n\nDESCRIPTOGRAFIA\n");
                        descriptografia_cesar();
                    }
                break;
                case 'A':
                    //mensagem();
                    chave_palavra();
                    //escolha();
                    alfabeto_polialfa();
                    matriz_poli();
                    if(e=='C'){
                        printf("\n\nCRIPTOGRAFIA\n");
                        criptografia_polialfa();
                    }else{
                        printf("\n\nDESCRIPTOGRAFIA\n");
                        descriptografia_polialfa();
                    }
                break;
                case 'T':
                    //mensagem();
                    chave_palavra();
                    //escolha();
                    if(e=='C'){
                        organizacao_matriz();
                        printf("\n\nCRIPTOGRAFIA\n");
                        criptografia_transposicaoSimples();
                    }else{
                        desorganizacao_matriz();
                        printf("\n\nDESCRIPTOGRAFIA\n");
                        descriptografia_transposicaoSimples();
                    }
                break;
                case 'R':
                    //escolha();
                    //mensagem();
                    chave_rota();
                    zerando_mat();
                if(e=='D'){
                    desmontagem_matriz_rota();
                    printf("\n\nDESCRIPTOGRAFIA\n");
                    descripitografia_rota();
                    printf("\n");
                }
                if(e=='C'){
                    montagem_matriz_rota();
                    printf("\n\nCRIPTOGRAFIA\n");
                    cripitografia_rota();
                }
            }
            getchar();
        }
    }

