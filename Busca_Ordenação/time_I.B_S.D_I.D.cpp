//Lallier Pallu C. de Faria
/*um programa em C para gerar um vetor randomicamente de dimensão definida pelo usuário no max de 10000 posições (fazer a consistência), imprimir o vetor gerado, 
o programa deve permitir realizar a Busca Linear ou Binária( sem duplicado escolher um dos jeitos de permutaçao ou inserçao), conforme o usuário escolha, estas 
opções devem ser funções, se busca linear o vetor poder ter elementos publicados e não é necessário estar ordenado, mostrar onde o elemento foi encontrado e 
quantas vezes.
Se Busca Binária, o vetor não pode ter elementos duplicados e deve estar ordenado por I.B, S.D ou I.D conforme escolha do usuário, estas rotinas devem ser 
funções.
O programa deve ser executado enquanto o usuário desejar e deve ser contabilizado e impresso o tempo gasto na ordenação escolhida ate a impressao da ordenaçao.*/
#include "stdio.h"
#include "curses.h"
#include "math.h"
#include <unistd.h>
#include "stdlib.h"
#include "time.h"
#include "locale.h"
#define T 10000
    int mat[T],dim,r,n,i,j,pos,ele,temp,found,ok,op,ord;
     int qual,busc,e,cont_e;
void ordenacao_permutacao(void)
{
    // Ordenação por permutação
     int i,j,temp;
     for(i=1;i<=dim;i++)
        {
        for(j=1;j<=dim;j++)
            {
            if(mat[i]<mat[j])
                {
                temp=mat[i];
                mat[i]=mat[j];
                mat[j]=temp;
                }
            }
        }
        // impressão do vetor 
      printf("\nElementos Gerados ordenado\n");
     for(i=1;i<=dim;i++)
        {
        printf("%d ",mat[i]);
        }
}
// declaração da funcao para ordenar por Inserção Binária
void ordenacao_insercao_binaria(void)
{
       int i,j,temp,l,r,pos;
       // rotina de ordenacao
       for(i=1;i<dim;i++)
       {
            temp=mat[i];
            l=0;
            r=i;
            while(l < r)
            {
                pos = (l + r) / 2;
                if(mat[pos] <= temp)
                     l = pos + 1;
                else
                     r = pos;
            }
           for(j=i;j>=r+1;j--)
               mat[j]=mat[j-1];

           mat[r]=temp;
      }
    // impressão do vetor ordenado
    printf("\n\nImpressão do Vetor Ordenado por Insercao Binaria \n");
    for(i=1;i<dim;i++)
      {
           printf("%d ",mat[i]);
      }
}
// declaração da funcao para ordenar por Inserção Binária
void ordenacao_insercao_direta(void)
{
        int i,x,j;
        for(i=2;i<=dim;i++)
        {
            x=mat[i];
            mat[0]=x; // a posição 0 do vetor eh utilizada com limitar
            j=i;
            while(x < mat[j-1])
            {
                mat[j]=mat[j-1];
                j=j-1;
            }
            mat[j]=x;
        }
    // impressão do vetor ordenado
    printf("\n\nImpressão do Vetor Ordenado por Insercao Binaria \n");
    for(i=1;i<=dim;i++)
      {
           printf("%d ",mat[i]);
      }
}
void buscalin(void)
{   int cont_e,e,i;
    cont_e=0;
    printf("\n\nEntre com o elemento a ser encontrado = ");
    scanf("%d",&e);
    // Buscando o elemento no vetor
    for(i=0;i<=dim;i++)
    {
        if(mat[i]==e)
          {
               cont_e=cont_e+1;
               printf("\nElemento %d encontrado na posicao %d do vetor",e,i);
          }
    }
    // imprimindo o total de elementos se encontrados
    if(cont_e>0)
       printf("\n\nTotal de elementos encontrador = %d",cont_e);
    else
       printf("\nNao foram encontrados elementos %d no vetor ",e);
}
void buscabin(void)
{
     // Busca Binária
     printf("\nEntre com elemento a ser encontrado :");
     scanf("%d",&ele);
     i=1;r=dim;found=1;
     while((i<=dim) && (found==1))
        {
        pos=(i+r)/2;
        if(((i>r) || (r<i)) && (mat[pos] != ele))
                   {
                   printf("Elemento %d nao encontrado!",ele);
                   found=0;
                   }
        if(mat[pos]==ele)
                {
                printf("Elemento %d encontrado na posicao %d",ele,pos);
                found=0;
                }
        else
                {
                if(mat[pos]<ele)
                    i=pos+1;
                else
                    r=pos-1;
                }
              }
}
// declaração da funcao para ordenar por Inserção Binária
void ordenacao_selecao_direta(void)
{
      int i, k,x,j;
      for(i=1;i<=dim-1;i++)
      {
        k=i;
        x=mat[i];
        for(j=i+1;j<=dim;j++)
        {
           if(mat[j]<x)
             {
                k=j;
                x=mat[k];
             }
        }
        mat[k]=mat[i];
        mat[i]=x;
      }
    // impressão do vetor ordenado
    printf("\n\nImpressão do Vetor Ordenado por Insercao Binaria \n");
    for(i=1;i<=dim;i++)
      {
           printf("%d ",mat[i]);
      }
}
int main(void)
{
   int ok,ko;
   char op;
    time_t t_inicial,t_final;
    float t_gasto=0;
   setlocale(LC_ALL,"Portuguese");
   ko=0;
   while(ko==0) // laço para executar enquanto o usuário desejar
   {
    ok=0;
    while(ok==0)
    {
     printf("Entre com a dimensao do vetor maior que zero e no max 10000:");
     scanf("%d",&dim);
     if((dim>=1) && (dim<=T))
        ok=1;
   }
   //qual busca
   ok=0;
   while(ok==0)
   {
    printf("\n\nSe deseja realizar uma busca linear digite 0, se deseja realizar uma busca binaria digite 1 = ");
    scanf("%d",&busc);
    if((busc>=0) && (busc<2))
        ok=1;
    else
    {
    system("tput clear");
    printf("\n\nValor invalido, o valor deve ser 0 ou 1\n");
    }
   }
   if(busc==0)
   {
   // Geraçao randomica dos elementos
   srand(time(NULL));
     for(i=1;i<=dim;i++)
        {
        mat[i]=rand()%10001;
        }
     // impressão do vetor
     printf("\nElementos Gerados !\n");
     for(i=1;i<=dim;i++)
        {
        printf("%d ",mat[i]);
        }
        //qual ordenaçao
        ok=0;
        ord=0;
        /*while(ok==0)
        {
        printf("\nQual ordenação deseja executar 0-Permutação, 1-Inserção Binária, 2-Inserção Direta ou 3-Seleção Direta ?");
        scanf("%d",&ord);
        if((ord>=0) && (ord<=3))
        ok=1;
        }
        t_inicial=time(NULL);
        if(ord==0)
        ordenacao_permutacao();
        else
        if(ord==1)
        ordenacao_insercao_binaria();
        else
        if(ord==2)
        // chamada da fução para ordenar por Inserção direta
        ordenacao_insercao_direta();
        else
        // chamada da fução para ordenar por seleçao direta
        ordenacao_selecao_direta();
    //busca linear
    buscalin();*/
   }
   else
   {
    // Geraçao randomica dos elementos não permitindo elemento repetido
   srand(time(NULL));
     for(i=1;i<=dim;i++)
        {
        mat[i]=rand()%10001;
        for(j=1;j<=dim;j++)
            {
            if((mat[i]==mat[j]) && (i!=j))
                {
                i--;
                }
            }
        }
     // impressão do vetor
      printf("\nElementos Gerados e sem ordem\n");
     for(i=1;i<=dim;i++)
        {
        printf("%d ",mat[i]);
        }
   }
        //qual ordenaçao
        ok=0;
        ord=0;
        while(ok==0)
        {
        printf("\nQual ordenação deseja executar 0-Permutação, 1-Inserção Binária, 2-Inserção Direta ou 3-Seleção Direta ?");
        scanf("%d",&ord);
        if((ord>=0) && (ord<=3))
        ok=1;
        t_inicial=time(NULL);
        }
        if(ord==0)
        ordenacao_permutacao();
        else
        if(ord==1)
        ordenacao_insercao_binaria();
        else
        if(ord==2)
        // chamada da fução para ordenar por Inserção direta
        ordenacao_insercao_direta();
        else
        // chamada da fução para ordenar por seleçao direta
        ordenacao_selecao_direta();
        //busca binaria
        buscabin();
    t_final=time(NULL);
    t_gasto = difftime(t_final,t_inicial);
    printf("\nTempo Gasto foi de %f segudos",t_gasto);
      ok=0;
        op=' ';
        while(ok==0) // consistencia da resposta para executar novamente
        {
        printf("\n\nDeseja executar novamente Y ou N ?");
        op=getchar();
        if((op=='y' )|| (op=='Y') || (op=='n') || (op=='N'))
           ok=1;
         system("cls");
        }
        // note que são apostrofos ' e não aspas "
        if((op=='n') || (op=='N'))
           ko=1;
   }
}
