/* Busca Binária sem a participção do usuário O programa pede para o usuário entrar com a dimensão do vetor N que deve ser >=1 e <=10000
Faz a geração randomica dos elementos não permitindo elementos duplicados no vetor Ordena o vetor em ordem crescente
utilizando o algoritmo de ordenação por permutação Imprime o vetor ordenado e Solicita ao usuário qual elemento deve procurar Realiza a busca
*/
    #include "stdio.h"
    #include "curses.h"
    #include "math.h"
//    #include "dos.h"
    #include "stdlib.h"
    #include "time.h"
int main(void){
    int mat[10001],n,r,i,j,pos,ele,temp,found,ok,ko;
    char op;
    ko=0;
    while(ko==0){
        srand(time(NULL));
        ok=0;
        while(ok==0){
            system("cls");
            printf("Programa para executar busca binaria em um vetor def p/ usuario\n\n");
            printf("Entre com a dimensao do vetor no max 10000:");
            scanf("%d",&n);
            if((n>=1) && (n<=10000))
                ok=1;
        }
        // Geração randomica de elementos não permitindo elemento repetido
        printf("\n\nGeração dos Elementos Randomicamente \n");
        for(i=1;i<=n;i++){
            mat[i]=rand()%10001;
            for(j=1;j<=i;j++){
                if((mat[i]==mat[j]) && (i!=j)){
                    i--;
                }
            }
        }
        // Ordenação por permutação
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(mat[i]<mat[j]){
                    temp=mat[i];
                    mat[i]=mat[j];
                    mat[j]=temp;
                }
            }
        }
        // impressão do vetor ordenado
        printf("\nElementos Gerados e Ordenados !\n");
        for(i=1;i<=n;i++){
            printf("%d ",mat[i]);
        }
        // Busca Binária com a participação do Usuário
        printf("\n\nEntre com elemento a ser encontrado :");
        scanf("%d",&ele);
        i=1;r=n;found=1; // inicia i em 1 como limite inferior e r em n como limite superior e found=1,
        // found eh uma var que muda quan do o elemento eh encontrado
        while((i<=n) && (found==1)){ // faz enquanto o limite inferior em i seja menor que o limite superior em n e found=1
            pos=(i+r)/2;
            if(((i>r) || (r<i)) && (mat[pos] != ele)){ // se o limite inferior chegar ao limite superior ou vise versa e o elemento desta
            //posição não for igual a que se esta procurando, avisa que não existe e muda o valor do found
                printf("Elemento %d nao encontrado!",ele);
                found=0;
            }
                if(mat[pos]==ele){ // elemento encontrado
                    printf("Elemento %d encontrado na posicao %d",ele,pos);
                    found=0;
                }else{
                // altera dos limites de procura
                    if(mat[pos]<ele)
                        i=pos+1; // se o elemento da posição for < que o elemento que se deseja encontrar, faz o limite inferior (i) subir para pos+1
                    else
                        r=pos-1; // se o elemento da posição for > que o elemento que se deseja encontrar, faz o limite superior (r) descer para pos-1;
                }
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
