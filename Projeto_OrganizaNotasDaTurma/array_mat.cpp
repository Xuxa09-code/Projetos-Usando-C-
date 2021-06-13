/*O programa vai analisar dados de n alunos, com a nota dos 4 bimestres,
formar um boletim em ordem de nota, da maior para menor de acordo com a
media dos 4 bim. E no fim indicar a media da sala*/
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 1000
    int main(void){
        struct dados_do_aluno{
            float notas[T][T];
            char materia[T],materia2[T],nome[T][T],nome1[T][T];
        };
        struct dados_do_aluno aluno;
        int i,j,espaco_c=0,espaco_m=0,dim_nome[T],ko,max=0,ok=0;
        float soma=0,soma_sala=0;
        char sf[T][T],e=' ';
        i=0;
        printf("\n\nEntre com a materia que sera analisada: ");
        while((aluno.materia[i]=getchar())!='\n'){
            aluno.materia2[i]=aluno.materia[i];
            i++;
        }
        i=0;
        j=0;
        printf("\nVoce devera colocar um nome de cada vez e se desejar sair, digite '0' ao inves de colocar o nome de um aluno!");
        while(i<T){
            printf("\n\nEntre com o nome do aluno %d: ",i+1);
            while((aluno.nome1[i][j]=getchar())!='\n'){
                aluno.nome[i][j]=aluno.nome1[i][j];
                j++;
            }
            dim_nome[i]=j-1;
            if(dim_nome[i]>=max)
                max=dim_nome[i];
            if(aluno.nome[i][j-1]=='0')
                break;
            printf("\nEntre com as notas dos 4 bimestres do aluno %s",aluno.nome[i]);
            for(j=0;j<4;j++){
                printf("\nNota %d bimestre: ",j+1);
                scanf("%f",&aluno.notas[i][j]);
                soma=soma+aluno.notas[i][j];
            }
            aluno.notas[i][j]=soma/4;
            if(aluno.notas[i][j]>=6)
                strcpy(sf[i],"aprovado");
            else
                strcpy(sf[i],"reprovado");
            soma_sala=soma_sala+aluno.notas[i][j];
            j=0;
            i++;
            soma=0;
            getchar();
        }
        int dim_nomes=i-1;
        float auxfloat;
        char aux[T];
        for(i=0;i<=dim_nomes;i++){
            j=dim_nome[i];
            if(dim_nome[i]<=max){
                for(j=dim_nome[i]+1;j<=max;j++)
                    aluno.nome[i][j]=' ';
            }
            aluno.nome[i][j]='|';
        }
        for(i=0;i<=dim_nomes;i++){
            for(j=dim_nomes;j>i;j--){
                if(aluno.notas[i][4]<aluno.notas[j][4]){
                    for(int k=0;k<=max+1;k++){
                        aux[k]=aluno.nome[i][k];
                        aluno.nome[i][k]=aluno.nome[j][k];
                        aluno.nome[j][k]=aux[k];
                    }
                    for(int k=0;k<5;k++){
                        auxfloat=aluno.notas[i][k];
                        aluno.notas[i][k]=aluno.notas[j][k];
                        aluno.notas[j][k]=auxfloat;
                    }
                    strcpy(aux,sf[i]);
                    strcpy(sf[i],sf[j]);
                    strcpy(sf[j],aux);
                }
            }
        }
        printf("\nMateria: %s",aluno.materia);
        printf("\n\t\t\tNotas");
        printf("\nNome");
        for(i=4;i<=max;i++)
            printf(" ");
        printf("||  1  |  2  |  3  |  4  | M.F.| Situacao final ");
        for(i=0;i<=dim_nomes;i++){
            printf("\n--------------------------------------------------------");
            printf("\n%s",aluno.nome[i]);
            for(j=0;j<5;j++){
                if(aluno.notas[i][j]>=10)
                    printf("|%.2f",aluno.notas[i][j]);
                else
                    printf("|0%.2f",aluno.notas[i][j]);
            }
            printf("|   %s",sf[i]);
        }
        float dim_dim=dim_nomes;
        printf("\n\n\tA media da sala foi: %.2f",(soma_sala/(dim_dim+1)));
        getchar();
    }

