/*Este programa vai coletar o nome de um aluno, suas notas  dos 4 bimestres e dizer se ele foi aprovado ou nao*/
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
    int main(void){
        struct dados_do_aluno{
            float notas[T];
            char materia[T],materia2[T],nome[T];
        };
        struct dados_do_aluno aluno;
        int i,espaco_c=0,espaco_m=0,dim_materia,ko;
        float soma=0;
        char sf[12];
        i=0;
        printf("\n\nEntre com o nome do aluno: ");
        scanf("%[^\n]s",aluno.nome);
        getchar();
        printf("\n\nEntre com a materia que sera analisada: ");
        while((aluno.materia[i]=getchar())!='\n'){
            aluno.materia2[i]=aluno.materia[i];
            i++;
        }
        dim_materia=i-1;
        printf("\nEntre com as notas dos 4 bimestres");
        for(i=0;i<4;i++){
            printf("\nNota %d bimestre: ",i+1);
            scanf("%f",&aluno.notas[i]);
            soma=soma+aluno.notas[i];
        }
        aluno.notas[i]=soma/4;
        if(aluno.notas[i]>=6)
            strcpy(sf,"aprovado");
        else
            strcpy(sf,"reprovado");
        if(dim_materia>7){
            ko=0;
        }else{
            ko=1;
        }
        printf("\nAluno: %s",aluno.nome);
        printf("\n\t\t\tNotas");
        printf("\nMateria");
        if(ko==0){
            for(i=7;i<=dim_materia;i++)
                printf(" ");
        }
        printf("|  1  |  2  |  3  |  4  | M.F.| Situacao final ");
        printf("\n--------------------------------------------------------");
        printf("\n%s",aluno.materia2);
        /*if(ko==1){
            for(i=dim_materia;i<=7;i++)
                printf(" ");
        }*/
        for(i=0;i<5;i++){
            if(aluno.notas[i]>=10)
                printf("|%.2f",aluno.notas[i]);
            else
                printf("|0%.2f",aluno.notas[i]);
        }
        printf("|   %s\n",sf);
    }
