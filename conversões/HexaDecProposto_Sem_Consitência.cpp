
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
char tnum;
int knum;

int main(void){
    void tabela(char num); // função - tabela de conversão de letras a,b,c,d,e,f para numeros
    int i,j,k,calc,bin;
    int num,numm; //para ler os valor um por um com o char
    char op,res,Hx,Hd,Hex;
    int vetor[T];
    int ok,ko;
    knum=0;
    ko=0;
    while(ko==0){
        num=0;
        i=0;
        system("cls");
        calc=0;
    printf("\nEnter A Binary Number: \t");
    scanf("%d", &bin); //digitar um numero composto por zeros e uns tipo 10101
    for(i = 0; bin > 0; i++)
    {
        num = num + pow(2, i) * (bin % 10); // resto do numero por 10, vezes (*) o 2 elevado a potencia na posição relativa
        bin = bin / 10; // o numero dividido por 10, vai tirando unidade, dezena,centena, milhar, ect
    }
        printf("%d",num);
        Hx=num;
        if(Hx<=15){
        num=Hx;
        tabela(num);
        Hx=tnum;
        printf("\n%c\n",Hx);
    }else{
            numm=num;
            Hex=num/16;
            num=Hex;
            tabela(num);
            Hex=tnum;
            printf("\n%c",Hex);
            Hx=numm%16;
            num=Hx;
            tabela(num);
            Hx=tnum;
            printf("%c",Hx);
         }

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
    if(num==10)
        tnum='a';
    else
        if(num==11)
            tnum='b';
        else
        if(num==12)
            tnum='c';
        else
            if(num==13)
                tnum='d';
            else
                if(num==14)
                    tnum='e';
                else
                    if(num==15)
                        tnum='f';
                    else
                        if(num==0)
                            tnum='0';
                        else
                            if(num==1)
                                tnum=1;
                            else
                                if(num==2)
                                    tnum='2';
                                else
                                    if(num==3)
                                        tnum='3';
                                    else
                                        if(num==4)
                                            tnum='4';
                                        else
                                            if(num==5)
                                                tnum='5';
                                            else
                                                if(num==6)
                                                    tnum='6';
                                                else
                                                    if(num==7)
                                                        tnum='7';
                                                    else
                                                        if(num==8)
                                                            tnum='8';
                                                        else
                                                            if(num==9)
                                                                tnum='9';



}

