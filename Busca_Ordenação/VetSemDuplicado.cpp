#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
int ok=0,aux,cont_e,e;
long int dim,h,n,vet[1000],i;
srand(time(NULL));
cont_e=0;
while(ok==0)
{
printf("\nEntre com a dimensao do vet menor que 1000 = \n");
scanf("%ld", &dim);
if((dim>0) && (dim<=1000))
{
	ok=1;
}else
{printf("\nValor incorreto, entre com uma nova dimensao menor que 100 e maior que 0\n");
}
}
for(i=0;i<dim;i++)
{
	vet[i]=0;
}
for(i=0;i<dim;i++)
{
vet[i]=rand()%1000;
for(h=0;h<i;h++)
{
if(vet[i]==vet[h])
{	h=i+1;
	i--;
}
}
}

printf("\n");
for(i=0;i<dim;i++)
{
for(n=dim-1;n>=i;n--)
{
if(vet[i]>vet[n])
{
	aux=vet[i];
	vet[i]=vet[n];
	vet[n]=aux;
}
}
}
printf("\n");
for(i=0;i<dim;i++)
{

	printf(" %ld ",vet[i]);


}
/*	printf("\nEntre com o elemento a ser encontrado = \n");
scanf("%d", &e);*/

	for(i=0;i<dim;i++)
{
for(h=0;h<i;h++)
{
if(vet[i]==vet[h])
{
	cont_e++;
}
}
}
	printf("\nElementos repetidos = %d ",cont_e);
}

