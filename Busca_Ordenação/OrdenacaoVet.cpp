#include<stdio.h>
#include<curses.h>
int main(void)
{
int cont=0;
int vet[100],i,h,n,dim,ok=0,ko=0,aux;
for(i=0;i<dim;i++)
{
	vet[i]=0;
}
while(ok==0)
{
printf("\nEntre com a dimensao do vet menor que 100 = \n");
scanf("%d", &dim);
if((dim>0) && (dim<100))
{
	ok=1;
}else
{printf("\nValor incorreto, entre com uma nova dimensao menor que 100 e maior que 0\n");
}
}
for(i=0;i<dim;i++)
{
printf("\nElemento [%d] = ", i);
scanf("%d", &vet[i]);
for(h=0;h<=i;h++)
{
if(vet[i]==vet[h] && i!=h)
{	printf("\nO elemento já foi usado, digite-o novamente\n");
	h=i+1;
	i--;
}
}
}

printf("\n");
for(i=0;i<dim;i++)
{

	printf("%d ",vet[i]);

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

	printf("%d ",vet[i]);


}
}
