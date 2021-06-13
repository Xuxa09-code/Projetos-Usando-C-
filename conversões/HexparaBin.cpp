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
        int ok,ko,resto;
        knum=0;
        ko=0;
        while(ko==0){
            i=0;
            printf("\e[1;1H\e[2J");
            calc=0;
            ok=0;
            while(ok==0){
                ok=1;
                printf("\n\nEntre com valor na Base 16 para converter  = ");
                while((num=getchar()) != '\n'){
                    tabela(num); // converte o char em numero
                    vetor[i]=tnum;
                        if(tnum==20)
                            ok=0;
                    i++;
                }
            if(ok==0)
                printf("\nNumero digitado nao pertence a base 16\n");
            }
        k=0;
        for(j=i-1;j>=0;j--){
            calc=calc+(vetor[j]*(pow(16,k))); // varre o vetor de traz para frente calculando. O k faz o papel das posições relatiovas
            k++;
        }

        printf("\n\nO valor na Base 10 = %d",calc);
        ok=0;
        op=' ';
        i=0;
        while(calc>1){
            resto=calc%2;
            vetor[i]=resto;
            i++;
            calc=calc/2; // atribui a parte inteira da divisão pois num é int
        }
        vetor[i]=calc;

        printf("\n\n\tNa base 2 e igual a ");
        for(j=i;j>=0;j--){
            printf("%d ",vetor[j]);
        }
        ok=0;
        op=' ';
        while(ok==0){
            printf("\n\nDeseja executar novamente Y ou N ?");
            op=getchar();
            if((op=='y' )|| (op=='Y') || (op=='n') || (op=='N'))
                ok=1;
        }
        if((op=='n') || (op=='N'))
            ko=1;
        getchar();
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
                     if(num=='0')
                            tnum=0;
                        else
                            if(num=='1')
                                tnum=1;
                            else
                                if(num=='2')
                                    tnum=2;
                                else
                                    if(num=='3')
                                        tnum=3;
                                    else
                                        if(num=='4')
                                            tnum=4;
                                        else
                                            if(num=='5')
                                                tnum=5;
                                            else
                                                if(num=='6')
                                                    tnum=6;
                                                else
                                                    if(num=='7')
                                                        tnum=7;
                                                    else
                                                        if(num=='8')
                                                            tnum=8;
                                                        else
                                                            if(num=='9')
                                                                tnum=9;
                                                            else
                                                                tnum=20;
}
