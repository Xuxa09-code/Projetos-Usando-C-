/*LALLIER PALLU CARDOSO DE FARIA 1C*/
#include<math.h>
#include<time.h>
#include<unistd.h>
#include<curses.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#define T 1000
    /*int dim_vet(int vetor[T]){
        printf(".");
        int dim,i;
        for(i=0;vetor[i]!='*';i++);
        return dim-i;
    }*/
    int verificacao(int vetor[T]){
        int i,dim;
        for(i=0;vetor[i]!='*';i++){
            for(int h=0;h<i;h++){
                if(vetor[i]==vetor[h]){
                    return (-1);
                    exit(0);
                }
            }
        }
    }
    void ordenaca_permutacao(int vetor[T],int dim){
        int n,h,i,aux;
        for(h=0;h<dim;h++){
            for(n=dim-1;n>h;n--){ // laço para variar o vetor de traz para frente até j ser igual a i
                if(vetor[h]>vetor[n]){ // teste se o elemento do vetor na posição i é maior que o elemento do vetor da posição j
                    aux=vetor[h]; // se sim transf o elemento do vetor na posição para uma var aux
                    vetor[h]=vetor[n]; // transf o que está na posição j do vetor para a posição i do vetor
                    vetor[n]=aux; // transf o que está na var aux para a posição j do vetor
                }
            }
        }
    }
    int ordenacao_insercao_binaria(int vetor[T],int dim){
        int i,j,temp,l,r,pos;
        //int dim=dim_vet(vetor);
        int res=verificacao(vetor);
        // rotina de ordenacao
        for(i=0;i<dim;i++){
            temp=vetor[i];
            l=0;
            r=i;
            while(l<r){
                pos=(l+r)/2;
                if(vetor[pos]<=temp)
                    l=pos+1;
                else
                    r=pos;
            }
            for(j=i;j>=r+1;j--)
                vetor[j]=vetor[j-1];
                vetor[r]=temp;
        }
        return res;
    }
    int ordenacao_insercao_direta(int vetor[T],int dim){
        int aux,i,j;
        //int dim=dim_vet(vetor);
        //Ordenação do Vetor
        for(i=1;i<dim;i++){
            aux=vetor[i];
            j=i;
            while(aux<vetor[j-1]){
                vetor[j]=vetor[j-1];
                j--;
            }
            vetor[j]=aux;
        }
        return dim;
    }
    void selecao_direta(int vetor[T],int tamanho){
        int i,j,menor,aux;
        //int tamanho=dim_vet(vetor);
        for(i=0;i<tamanho-1;i++){
            menor=i;
            for(j=i+1;j<tamanho;j++){
                if(vetor[j]<vetor[menor])
                    menor=j;
            }
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
    void ordenacao_bolha(int vetor[T],int dim){
        int i,ind2,troquei,aux;
        //int dim=dim_vet(vetor);
        ind2=dim;
        troquei=0;
        do{
            troquei=0;
            for(i=0;i<ind2-1;i++){
                if (vetor[i]>vetor[i+1]){
                    aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
                    troquei=1;
                }
            }
            ind2=ind2-1;
        }while (troquei==1);
        // impressão do vetor ordenado
    }
