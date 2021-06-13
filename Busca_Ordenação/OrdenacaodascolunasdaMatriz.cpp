#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "time.h"
int main(void)
{
	int ok,e,n,m,aux,dim_l,dim_c,cont_e;
	int i,j, Mat[8][8];
	ok=0;
	e=0;
	cont_e=0;
	srand(time(NULL));

    system("color 05"); // fundo preto e letra lilas
	system("cls"); // limpa a tela
	while(ok==0)
	{
	
        printf("\nEntre com a dimensao da linha da Matriz com no max 7 = ");
        scanf("%d",&dim_l);
		if((dim_l>=0) && (dim_l<7)) // se a dimensão estiver nos limites (>=0 e <= 7) o prog sai da conistencia
		   ok=1;
	    else
	        printf("\n Valor Invalido ! Tente Novamente");
	}
	ok=0;
	while(ok==0)
	{
        printf("\nEntre com a dimensao das colunas da Matriz com no Max 7 = ");
        scanf("%d",&dim_c);
		if((dim_c>=0) && (dim_c<7)) // se a dimensão das linhas estiver nos limites (>=0 e <= 4) o prog sai da conistencia
		   ok=1;
	    else
	        printf("\n Valor Invalido para as colunas da Matriz ! Tente Novamente");
	}

// Zerando o vetor para dimensao definida
	for(i=0;i<dim_l;i++)
{
	for(j=0;j<=dim_c;j++)
{
	   Mat[i][j]=0;
}
}
    // Lendo os elementos do Vetor
    
    system("color 09"); // Fundo preto , letra azul
    
    printf("\nEntre com os elementos do Vetor ");
	for(i=0;i<dim_l;i++)
	{
		for(j=0;j<dim_c;j++)
	{
		Mat[i][j]=rand()%100;

	      printf("\nElemento da Mat[%d][%d] = %d ",i,j,Mat[i][j]);
	}
	}
	// Impressao do Vetor Lido
    printf("\nMatriz Mat \n");
	for(i=0;i<dim_l;i++)
	{
	    printf("\n");
		for(j=0;j<dim_c;j++)
	{

	      printf("%d ",Mat[i][j]);
		  
	}
	}
	printf("\n");
    printf("\nMatriz Mat Organizada \n");
for(j=0;j<dim_l;j++)
{
	for(i=0;i<dim_c;i++)
	 {
		for(n=dim_c-1;n>=i;n--) // laço para variar o vetor de traz para frente até j ser igual a i
		{
			if(Mat[j][i]>Mat[j][n]) // teste se o elemento do vetor na posição i é maior que o elemento do vetor da posição j
			 {
			 	aux=Mat[j][i]; // se sim transf o elemento do vetor na posição para uma var aux
				Mat[j][i]=Mat[j][n]; // transf o que está na posição j do vetor para a posição i do vetor
				Mat[j][n]=aux; // transf o que está na var aux para a posição j do vetor
			 }
		    }
		
	 }
   }
//mat ordenada
for(i=0;i<dim_l;i++)
	{
printf("\n");
	for(j=0;j<dim_c;j++)
	{
	      printf("%d ",Mat[i][j]);
	}

	}

	printf("\n");

}
