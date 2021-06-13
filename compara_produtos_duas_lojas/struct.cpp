/*O programa deve coletar dados de produtos de dois supermecados: nome, peso e preco. Depois calcular o preco por quilo
O programa deve guardar as informacoes de todos pares de produtos e indicar qual dos supermecados compensa mais*/
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
    int main(int argc, char*argv[]){
        int ok=0,i=0,quantidade;
        struct dados_do_supermecado_1{
            char nome[200];
            char produto[200][200];
            float  preco=1;
            float peso;
            float soma=0;
        };
        struct dados_do_supermecado_1 sup1;
        struct dados_do_supermecado_2{
            char nome[200];
            char produto[200][200];
            float preco=1;
            float peso;
            float soma=0;
        };
        struct dados_do_supermecado_2 sup2;
        while(ok==0){
            printf("\nEntre com o nome do primeiro supermercado: ");
            scanf("%[^\n]s",sup1.nome);
            getchar();
            printf("\nEntre com o nome do segundo supermercado: ");
            scanf("%[^\n]s",sup2.nome);
            printf("\nEntre com os produtos, pesos e precos do supermercado %s, para parar digite 0 no campo preco",sup1.nome);
            getchar();
            printf("\n\nSupermecado %s",sup1.nome);
            while(sup1.preco!=0){
                printf("\nEntre com o nome do %d produto: ",i+1);
                scanf("%[^\n]s",sup1.produto[i]);
                printf("\nEntre com o peso em quilos do %s: ",sup1.produto[i]);
                scanf("%f",&sup1.peso);
                printf("\nEntre com o preco do %s: ",sup1.produto[i]);
                scanf("%f",&sup1.preco);
                if(sup1.preco!=0){
                    strcpy(sup2.produto[i],sup1.produto[i]);
                    sup1.soma=sup1.soma+(sup1.preco/sup1.peso);
                }
                i++;
                getchar();
            }
            quantidade=i-1;
            printf("\n\nSupermecado %s",sup2.nome);
            i=0;
            while(i<quantidade){
                printf("\nEntre com o peso em quilos do %s: ",sup2.produto[i]);
                scanf("%f",&sup2.peso);
                printf("\nEntre com o preco do %s: ",sup2.produto[i]);
                scanf("%f",&sup2.preco);
                i++;
                sup2.soma=sup2.soma+(sup2.preco/sup2.peso);
            }
            if(sup2.soma>sup1.soma)
                printf("\n\nO supermercado %s eh o mais barato",sup1.nome);
            else{
                if(sup1.soma>sup2.soma)
                    printf("\n\nO supermercado %s eh o mais barato",sup2.nome);
                else
                    printf("\n\nA compra nos dois supermercados tem o mesmo preco por peso");
            }
            getchar();
            char op=' ';
            while((op!='S')&&(op!='N')){
                printf("\nDeseja Realizar mais uma comparacao de precos?\n\tS-Sim\n\tN-Nao");
                op=toupper(getchar());
                if(op=='N')
                    ok=1;
                if((op!='S')&&(op!='N'))
                    printf("\nOpcao invalida!\n");
            }
        }
    }
