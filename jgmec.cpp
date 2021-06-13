    #include<stdio.h>
    int contt=0;
int main(void){
    void fribonaci(int contt);
    void soldadinho(int contt);
    void euler(int contt);
    int can,a,b,c,d,rod,contp,contf,ok=0,ko;
        while(ok==0){
            a=0;b=0;c=0;d=0;
            contf=0;
            for(rod=0;rod<5;rod++){
                ko=0;
                contp=0;
                while(ko==0){
                    printf("\nEntre com a canaleta q deseja jogar 0 - 2 - 1 ");
                    scanf("%d",&can);
                    if((can>=0)&&(can<=2))
                        ko=1;
                    else
                        printf("\nNumero de canaleta incorreto, digite novamente!");
                }
        if(can==0){
            if(a==0){
                contp=contp+10;
                a=1;
            }
            else{
                a=0;
                if(d==0){
                    contp=contp+10;
                    d=1;
                }else{
                    d=0;
                    contp=contp+20;
                }
            }
    }
        if(can==1){
            if(b==0){
                b=1;
                if(d==0){
                    contp=contp+10;
                    d=1;
                }else{
                        d=0;
                        contp=contp+20;
                }
            }else{
                        contp=contp+20;
                        b=0;
            }
            }
                if(can==2){
                    if(c==0){
                        c=1;
                        if(a==0){
                            contp=contp+10;
                            a=1;
                        }else{
                            a=0;
                                if(d==0){
                                    contp=contp+10;
                                    d=1;
                                }else{
                                    d=0;
                                    contp=contp+20;
                                }
                        }
                }else{
                    if(b==0){
                    b=1;
                    if(d==0){
                        contp=contp+10;
                        d=1;
                    }else{
                            d=0;
                            contp=contp+20;
                    }
                }else{
                            contp=contp+20;
                            b=0;
                    }
            }
        }
                printf("\nPontucao da rodade = %d",contp);
                contf=contf+contp;
            }
            printf("\n\\nPontuacao da partida = %d",contf);
            contt=contt+contf;
            printf("\nDeseja executar o programa novamente 1-nao 0-sim = ");
            scanf("%d",&ok);
        }
    printf("\nPontuacao de todas as partida = %d",contt);
    getchar();
    fribonaci(contt);
    getchar();
    soldadinho(contt);
    getchar();
    euler(contt);
    getchar();
}
    void fribonaci(int contt){
        printf("\nSequência fribonaci\n");
        int A=0,B=1,i;
        unsigned int C=0;
        printf("%d %d ",A,B);
        for(i=0;i<contt;i++){
            C=A+B;
            printf("%u ",C);
            A=B;
            B=C;
        }
}

void soldadinho(int contt){
    int sol,sol_ulti_fila,fila;
        printf("\nSoldadinho\n");
        sol=contt;
        fila=1;
        sol_ulti_fila=sol;
            while(sol_ulti_fila > fila){
                sol_ulti_fila=sol_ulti_fila-fila;
                fila=fila+1;
            }
        printf("\n\nNumero de Soldados = %d",sol);
        printf("\nNumero de filas = %d",fila);
        printf("\nNumero de soldados na ultima fila = %d",sol_ulti_fila);
    }
void euler(int contt){
    printf("\nEuler\n");
    int i,n,x;
    float fat,e;
    e=1; // e começa em 1
    n=contt;
        for(i=1;i<=n;i++){
            fat=1;
                for(x=1;x<=i;x++)
                    fat=fat*x; //calculo do fatorial para cada um dos termos
                    e = e + (1/fat); //somatoria da divisaõ de 1 pelo fatorial do termo

            }
        printf("O numero de Euler = %.50f",e); //impressão do numero com 50 decimais

    }
