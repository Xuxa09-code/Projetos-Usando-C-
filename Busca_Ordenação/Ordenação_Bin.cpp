/*Program para gerar um vetor de no max 1000 elementos randomicamente
e imprimir o vetor gerado e ordenar o vetor pelo algoritmo de Inserção Binária
imprimindoo o vetor ordenado
O Programa deve executar enguanto o usuario desejar
*/
    #include "stdio.h"
    #include "curses.h"
    #include "time.h"
    #include "stdlib.h"
    #define T 1000
    int dim,vetor[T];
int main(void){
    void ordenacao_insercao_binaria(void);
    int i;
    int ok,ko;
    srand(time(NULL));
    ko=0;
    while(ko==0){
        ok=0;
        while(ok==0){
            printf("\n\nEntre com a dimensao do Vetor maior que zero e menor que %d ",T);
            scanf("%d",&dim);
            if((dim>0) && (dim<=T))
                ok=1;
        }
        // geração e impressão do vetor
        for(i=0;i<dim;i++){
            vetor[i]=rand()%100; // geracao randomica limite ao valor 100
        }
        printf("\n\nImpressao do vetor Gerado e Fora de Ordem \n");
        for(i=0;i<dim;i++){
            printf("%d ",vetor[i]);
        }
        // chamada da fução para ordenar por Inserção Binária
        ordenacao_insercao_binaria();
        ok=0;
        while(ok==0){
        printf("\n\nDeseja executar novamente ? 0-sim  1-nao");
        scanf("%d",&ko);
        if((ko==0)||(ko==1))
            ok=1;
        }
    }
}


// declaração da funcao para ordenar por Inserção Binária
void ordenacao_insercao_binaria(void){
    int i,j,temp,l,r,pos;
        // rotina de ordenacao
        for(i=1;i<dim;i++){
            temp=vetor[i];
            l=0;
            r=i;
            while(l < r){
                pos = (l + r) / 2;
                if(vetor[pos] <= temp)
                    l = pos + 1;
                else
                    r = pos;
            }
            for(j=i;j>=r+1;j--)
                vetor[j]=vetor[j-1];
                vetor[r]=temp;
        }
    // impressão do vetor ordenado
    printf("\n\nImpressão do Vetor Ordenado por Insercao Binaria \n");
    for(i=0;i<dim;i++){
           printf("%d ",vetor[i]);
    }
}
