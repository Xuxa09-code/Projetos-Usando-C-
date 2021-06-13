/*LALLIER PALLU CARDOSO DE FARIA 1C*/
#include<iostream>
#include<math.h>
#include<curses.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#define T 1000
    int bus_lin(int e,int vetor[T],int vet[T]){
        int cont_e=0,i;
        // Buscando o elemento no vetor
        for(i=0;vetor[i]!='*';i++){ // vare o vetor procurando pela ocorrência do elemento desejado
            if(vetor[i]==e){
                vet[cont_e]=i;
                cont_e++;
            }
        }
        // imprimindo o total de elementos se encontrados
        if(cont_e>0){
            vet[cont_e]=cont_e;
            vet[cont_e+1]='*';
            return 0;
        }else{
            return(-1);
        }
        exit(0);
    }
    int verifica(int vetor[T]){
        int i,dim;
        for(i=0;vetor[i]!='*';i++){
            for(int h=0;h<i;h++){
                if(vetor[i]==vetor[h]){
                    return (-1);
                    exit(0);
                }
            }
            dim=i;
            for(i=0;i<dim;i++){
                for(int n=dim-1;n>=i;n--){
                    if(vetor[i]>vetor[n]){
                        return (-2);
                        exit(0);
                    }
                }
            }
        }
        return dim;
    }
    int bus_bin(int ele,int vetor[T]){
        int found,i,r,pos;
        int dim=verifica(vetor);
        i=0;r=dim;found=1; // inicia i em 1 como limite inferior e r em n como limite superior e found=1,
        switch(dim){
            case (-1):
                return dim;
                exit(0);
            break;
            case (-2):
                return dim;
                exit(0);
            break;
        }
        // found eh uma var que muda quan do o elemento eh encontrado
        while((i<=dim) && (found==1)){ // faz enquanto o limite inferior em i seja menor que o limite superior em n e found=1
            pos=(i+r)/2;
            if(((i>r) || (r<i)) && (vetor[pos] != ele)){ // se o limite inferior chegar ao limite superior ou vise versa e o elemento desta
                //posição não for igual a que se esta procurando, avisa que não existe e muda o valor do found
                found=0;
                return (-3);
                exit(0);
            }
            if(vetor[pos]==ele){ // elemento encontrado
                    return pos;
                    exit(0);
                    found=0;
            }else{
                // altera dos limites de procura
                if(vetor[pos]<ele)
                    i=pos+1; // se o elemento da posição for < que o elemento que se deseja encontrar, faz o limite inferior (i) subir para pos+1
                else
                    r=pos-1; // se o elemento da posição for > que o elemento que se deseja encontrar, faz o limite superior (r) descer para pos-1;
            }
        }
        return (-3);
    }
