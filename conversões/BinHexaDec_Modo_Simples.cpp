
/* Conversão de Base 2 para base 10

 Programa para ler um Vetor de 8 elementos posições de 0 a 7
com elementos obrigatoriamente entre 0 e 1 (consistir)
 Realizar a mudança de base 2 do elemento para base 10
 
 
 */
 
 #include "stdio.h"
 #include "curses.h"
 #include "math.h" // para poder usar a função pow - exponenciação - pow(elemento,expoente)
 #define T 7
 
 int main(void)
 {
 	int i,k;
	 float calc;
 	int vetor[T];
 	int ok,Hex,I;
 	calc=0;
 	ok=0;
 	
 	printf("\n\nEntre com os Elementos do Vetor, valores de 0 ou 1\n");
 	i=0;
 	// le e faz a consistencia para valores serem 0 e 1
	while(i<=T)
 	{
 		printf("Vetor[%d] = ",i);
 		scanf("%d",&vetor[i]);
 		if((vetor[i]>=0) && (vetor[i]<=1))
 		   i++;
 		
 		   
 		   
    }
    // impressao do vetor lido
    printf("\n\nImpressao do Vetor Lido\n\n");
    for(i=0;i<=T;i++)
    {
    	printf("%d ",vetor[i]);
	}
	calc=0;
	k=1;
	for(i=T;i>=0;i--)
	{
		calc=calc+(vetor[i]*(pow(2,(k-1))));
		printf("\n%f",calc); // impressão para poder acompanhar as parciais da totalização
		k++;
	}
	//impressao do elemento na base 100
	
	printf("\n\nO valor do vetor na base 2 eh = %f na Base 10 ",calc); 
	getchar();
 	getchar();
Hex=calc;
printf("\nNumero em base 2 em Hexadecimal eh =  %x",Hex);

getchar();
}
