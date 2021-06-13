#include "curses.h"
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "math.h"
char mensav[81],pchave[100],mensa[81][81],vet[81][81],cripto[80],chave,e;
int chave1,tam_mensa,tam_coluna,tam_linha,k,l,coluna,linha,inicio,origem,destino;
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
        getchar();
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
        char descripto[100],i,j,t=1;
        for(j=1;j<=tam_coluna;j++){
            for(i=1;i<=tam_linha;i++){
                descripto[t]=mensa[i][j];
                t++;
            }
        }
        printf("\n");
        for(t=1;t<=(tam_coluna*tam_linha);t++)
            printf("%c",descripto[t]);
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
            getchar();
        }
    }
    int main(void){
        int i,j;
        e=' ';
        while((e!='D')&&(e!='C')){
            printf("\nEntre com a opção desejada:\nC-criptografia\nD-descriptografia\n");
            e=getchar();
            e=toupper(e);
            if((e!='D')&&(e!='C'))
                printf("\nOpçao Invalida, Tente novamente!\n");
        }
        while(e!='S'){
            getchar();
            for(i=1;i<=80;i++){
                for(j=1;j<=80;j++){
                    mensa[i][j]='A';
//                    vet[i][j]=' ';
                }
            }
            i=1;
            printf("\n\nEntre com a mensagem \n\n");
            while(((mensav[i]=getchar())!='\n')&&(i<=80))
                i++;
            tam_mensa=i-1;
            chave_rota();
            if(e=='D'){
                desmontagem_matriz_rota();
                printf("\nDESCRIPTOGRAFIA\n");
                descripitografia_rota();
                printf("\n");
            }
            if(e=='C'){
                montagem_matriz_rota();
                printf("\nCRIPTOGRAFIA\n");
                cripitografia_rota();
            }
            e=' ';
            while((e!='D')&&(e!='C')&&(e!='S')){
                printf("\nEntre com a opção desejada:\nC-criptografia\nD-descriptografia\nS-sair\n");
                e=getchar();
                e=toupper(e);
                if((e!='D')&&(e!='C')&&(e!='S'))
                    printf("\nOpçao Invalida, Tente novamente!\n");
            }
        }
    }

