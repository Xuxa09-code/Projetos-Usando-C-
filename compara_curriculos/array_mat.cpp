/*O programa vai analisar dados de n candidatos, como quantidade de diplomas, tempo de
experiencia na area etc. E no fim dizer quais deles sao qualificados para a entrevista de emprego.*/
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define T 1000
    void informacoes(void){
        printf("\n\tLegenda:");
        printf("\n\t\t1-Quantidade de dipliomas na area");
        printf("\n\t\t2-Anos de experiencia na area");
        printf("\n\t\t3-Quantidade de Linguagens domina");
        printf("\n\t\t4-Se for full stakt digite 1, se nao 0");
        printf("\nE importante que o usuario digite apenas numeros\n");
    }
    int main(void){
        struct dados_do_candidato{
            float notas[T][T];
            char materia[T],materia2[T],nome[T][T],nome1[T][T];
        };
        struct dados_do_candidato candidato;
        int i,j,espaco_c=0,espaco_m=0,dim_nome[T],ko,max=0,ok=0;
        float soma=0;
        char sf[T][T],e=' ';
        i=0;
        printf("\nVoce devera colocar um nome de cada vez e se desejar sair, digite '0' ao inves de colocar o nome de um candidato!");
        while(i<T){
            printf("\n\nEntre com o nome do candidato %d: ",i+1);
            while((candidato.nome1[i][j]=getchar())!='\n'){
                candidato.nome[i][j]=candidato.nome1[i][j];
                j++;
            }
            dim_nome[i]=j-1;
            if(dim_nome[i]>=max)
                max=dim_nome[i];
            if(candidato.nome[i][j-1]=='0')
                break;
            informacoes();
            printf("\nSe o usuaria desejar ver o manual novamente digite ");
            printf("\nEntre com as informacoes do candidato %s",candidato.materia2);
            for(j=0;j<4;j++){
                printf("\nInformacao %d: ",j+1);
                candidato.notas[i][j]=toupper(getchar());
                if(candidato.notas[i][j]=='M'){
                    informacoes();
                    j=0-1;
                }
                candidato.notas[i][j]=candidato.notas[i][j]-'0';
                soma=soma+candidato.notas[i][j];
                getchar();
            }
            candidato.notas[i][j]=soma;
            if(candidato.notas[i][j]>=6)
                strcpy(sf[i],"Qualificado");
            else
                strcpy(sf[i],"Desqualificado");
            j=0;
            i++;
            soma=0;
        }
        int dim_nomes=i-1;
        for(i=0;i<=dim_nomes;i++){
            j=dim_nome[i];
            if(dim_nome[i]<=max){
                for(j=dim_nome[i]+1;j<=max;j++)
                    candidato.nome[i][j]=' ';
            }
            candidato.nome[i][j]='|';
        }
        float auxfloat;
        char aux[T];
        for(i=0;i<=dim_nomes;i++){
            for(j=dim_nomes;j>i;j--){
                if(candidato.notas[i][4]<candidato.notas[j][4]){
                    for(int k=0;k<=max+1;k++){
                        aux[k]=candidato.nome[i][k];
                        candidato.nome[i][k]=candidato.nome[j][k];
                        candidato.nome[j][k]=aux[k];
                    }
                    for(int k=0;k<5;k++){
                        auxfloat=candidato.notas[i][k];
                        candidato.notas[i][k]=candidato.notas[j][k];
                        candidato.notas[j][k]=auxfloat;
                    }
                    strcpy(aux,sf[i]);
                    strcpy(sf[i],sf[j]);
                    strcpy(sf[j],aux);
                }
            }
        }
        printf("\nArea: T.I.");
        printf("\n\t\t\tInformacoes");
        printf("\nNome");
        for(i=4;i<=max;i++)
            printf(" ");
        printf("||  1  |  2  |  3  |  4  | M.F.| Situacao final ");
        for(i=0;i<=dim_nomes;i++){
            printf("\n--------------------------------------------------------");
            printf("\n%s",candidato.nome[i]);
            for(j=0;j<5;j++){
                if(candidato.notas[i][j]>=10)
                    printf("|%.2f",candidato.notas[i][j]);
                else
                    printf("|0%.2f",candidato.notas[i][j]);
            }
            printf("|   %s",sf[i]);
        }
        getchar();
    }


