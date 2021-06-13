/* Conversão de Base 16 para base 10

 Programa para ler um numero Hexadecimal fornecido pelo usuário 

 Realizar a mudança de base 16 para base 10
 Enguanto o usuário desejar

 */

#include "stdio.h"
#include "curses.h"
#include "math.h"
#include "stdlib.h"
#define T 100
int tnum;
int knum;

int main(void){
    void tabela(char num); // função - tabela de conversão de letras a,b,c,d,e,f para numeros
    int i,j,k,calc;
    char num; //para ler os valor um por um com o char
    char op;
    int vetor[T];
    int ok,ko;
    knum=0;
    ko=0;
    while(ko==0){
        i=0;
        system("cls");
        calc=0;
        printf("\n\nEntre com valor na Base 16 para converter  = ");
        while(num=getchar() != '\n'){ //faça enquanto o usuário não digitar ENTER, 13 é o enter na tabela ascii
            tabela(num); // converte o char em numero
            vetor[i]=tnum; //transf para um vetor para poder ter as posições relativas
            i++;
        }
        printf("Chegou até aqui");
        k=0;
		for(j=i-1;j>=0;j--){
            calc=calc+(vetor[j]*(pow(16,k))); // varre o vetor de traz para frente calculando. O k faz o papel das posições relatiovas
            k++;
        }
        printf("\n\nO valor na Base 10 = %d",calc);
        ok=0;
        op=' ';
        while(ok==0){ // consistencia da resposta para executar novamente
            printf("\n\nDeseja executar novamente Y ou N ?");
            op=getchar();	
            if((op=='y' )|| (op=='Y') || (op=='n') || (op=='N'))
            ok=1;
        }
        // note que são apostrofos ' e não aspas " 
        if((op=='n') || (op=='N'))
	    ko=1;
    }
}

void tabela(char num){
    if((num=='A')|| (num=='a'))
        tnum=10;
    else
        if((num=='B') || (num=='b'))
            tnum=11;
        else
        if((num=='C') || (num=='c'))
            tnum=12;
        else
            if((num=='D') || (num=='d'))
                tnum=13;
            else
                if((num=='E') || (num=='e'))
                    tnum=14;
                else
                    if((num=='F') || (num=='f'))
                        tnum=15;
                    else
                        switch(num){
                            //  printf("Entrei no case");
                            case '0' :tnum=0; break;
                            case '1' :tnum=1; break;
                            case '2' :tnum=2; break;
                            case '3' :tnum=3; break;
                            case '4' :tnum=4; break;
                            case '5' :tnum=5; break;
                            case '6' :tnum=6; break;
                            case '7' :tnum=7; break;
                            case '8' :tnum=8; break;
                            case '9' :tnum=9; break;
                        }
}
