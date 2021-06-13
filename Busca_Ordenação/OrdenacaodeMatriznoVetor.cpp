#include "stdio.h"
#include "stdlib.h"
#include "curses.h"
#include "time.h"
int main(void)
{
	int ok,e,n,g,m,aux,h,dim,dim_l,dim_c,cont_e;
	int i,j, Mat[10][10],vet[100];
	ok=0;
	e=0;
	cont_e=0;
	srand(time(NULL));

    system("color 05"); // fundo preto e letra lilas
	system("cls"); // limpa a tela
	while(ok==0)
	{
	
        printf("\nEntre com a dimensao da linha da Matriz com no max 10 = ");
        scanf("%d",&dim_l);
		if((dim_l>=0) && (dim_l<10)) // se a dimensão estiver nos limites (>=0 e <= 7) o prog sai da conistencia
		   ok=1;
	    else
	        printf("\n Valor Invalido ! Tente Novamente");
	}
	ok=0;
	while(ok==0)
	{
        printf("\nEntre com a dimensao das colunas da Matriz com no Max 10 = ");
        scanf("%d",&dim_c);
		if((dim_c>=0) && (dim_c<10)) // se a dimensão das linhas estiver nos limites (>=0 e <= 4) o prog sai da conistencia
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
dim=dim_l*dim_c;
for(h=0;h<=dim;h++)
{
	vet[h]=0;
}
h=0;
	for(i=0;i<dim_l;i++)
	{
		for(j=0;j<dim_c;j++)
	{

		vet[h]=Mat[i][j];
		h++;

	}
	}
    system("color 09"); // Fundo preto , letra azul
    
    printf("\nEntre com os elementos do Vetor ");
	for(h=0;h<dim;h++)
	{
		vet[h]=rand()%100;
	      printf("\nElemento da vet[%d] = %d ",h,vet[h]);
	for(n=0;n<h;n++)
	 {
		if(vet[h]==vet[n])
		{
		n=h+1;
		h=h-1;
		}
	}
	}
for(h=0;h<dim;h++)
	 {
		for(n=dim-1;n>=h;n--) // laço para variar o vetor de traz para frente até j ser igual a i
		{
			if(vet[h]>vet[n]) // teste se o elemento do vetor na posição i é maior que o elemento do vetor da posição j
			 {
			 	aux=vet[h]; // se sim transf o elemento do vetor na posição para uma var aux
				vet[h]=vet[n]; // transf o que está na posição j do vetor para a posição i do vetor
				vet[n]=aux; // transf o que está na var aux para a posição j do vetor
			 }
		    }

	 }
    printf("\nMatriz Mat Organizada \n\n");

h=0;
for(i=0;i<dim_l;i++)
	{
printf("\n");
	for(j=0;j<dim_c;j++)
	{
	Mat[i][j]=vet[h];
 printf("%d ",Mat[i][j]);
	h++;
	}

	}



	printf("\nEntre com o elemento a ser encontrado = ");
	scanf("%d",&e);


	// Buscando o elemento no vetor
	for(i=0;i<dim_c;i++)
	{
		for(j=0;j<dim_l;j++)
	{

		if(Mat[i][j]==e)
		  {
		  	   cont_e=cont_e+1;
		  	   printf("\nElemento %d encontrado na posicao [%d][%d] da Matriz",e,i,j);
		  }
	}
	}
	// imprimindo o total de elementos se encontrados
	if(cont_e>0)
	   printf("\n\nTotal de elementos encontrador = %d\n",cont_e);
	else
	   printf("\nNao foram encontrados elementos %d na Matriz \n",e);

	   getchar();
	   getchar();

	// OBS Note que os laços fazem os teste de <dim, pois o vetor começa na posição 0	   
}
