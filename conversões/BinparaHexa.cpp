    #include"stdio.h"
    #include <cstdlib>
    #include"curses.h"
    #include"math.h"
    #define T 100
    char tnum;
    int tnumb;
int main(void){
void tabela( char num);
void tabela1(char knum);
    int j,i,ok,ko=0,Hug,vetor[T],pos,k,num,numm;
    char knum,op,Hex,Hx;
    while(ko==0){
        printf("\e[1;1H\e[2J");
        Hug=0;
        ok=0;
        while(Hug==0){
            i=0;
            Hug=1;
            printf("\nEntre com o valor em base 2 para conversao = ");
                while((knum=getchar()) != '\n'){
                    tabela1(knum);
                    vetor[i]=tnumb;
                        if(vetor[i]==3)
                            Hug=0;
                    i++;
                }
            if(Hug==0)
                printf("\nO numero digitado nao eh binario");
        }
        pos=0;
        k=0;
            for(j=i-1;j>=0;j--){
                pos=pos+(vetor[j]*(pow(2,k)));
                k++;
            }
        printf("\nO valor em base 2 eh = %d em decimal",pos);
    num=pos;
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
        ok=0;
        op=' ';
        while(ok==0){
            printf("\nDeseja realizar o programa novamente Y ou N");
            op=getchar();
            if((op=='y')||(op=='Y')||(op=='n')||(op=='N'))
                ok=1;
        }
            if((op=='N')||(op=='n'))
                ko=1;
        getchar();
    }
}
void tabela1(char knum){
    if(knum=='0')
        tnumb=0;
    else
        if(knum=='1')
            tnumb=1;
        else
            tnumb=3;
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
                                tnum='1';
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
