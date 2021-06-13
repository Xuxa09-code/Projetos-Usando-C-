    #include<time.h>
    #include<math.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<curses.h>
    #include<unistd.h>
    #define T 31
// Programa para testar o algoritmo de Ordenacao Direta
int main(void){
    int a[T],i,j,x,n=0,k=0,aux;
        i=0;
        j=0;
        x=1;
        srand(time(NULL));
        system("tput clear");
        while(k==0){
            printf("\nEntre com a quantidade de elementos do vetor no maximo 30");
            scanf("%d",&n);
            if((n>=0)&&(n<=30))
                k=1;
        }
        while(i<=n){
            a[i]=0;
            i++;
        }

        for(i=0;i<n;i++){
            a[i]=rand()%100;
        }
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\nVetor ordenado \n\n");
        //Ordenação do Vetor
        for(i=1;i<n;i++){
            x=a[i];
            j=i;
            while(x<a[j-1]){
                a[j]=a[j-1];
                j--;
            }
            a[j]=x;
        }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
}
