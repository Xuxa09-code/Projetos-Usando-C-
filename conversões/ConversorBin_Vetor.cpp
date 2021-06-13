#include<stdio.h> 
#include<curses.h> 
#include<math.h> 
#define I 9
int main(void)
{
unsigned int pos;
int V[I+2],i,k;
for(i=0;i<I;i++)
{
	V[i]=0;
}
for(i=0;i<I;i++)
{
	printf("\nEntre com o valor binário na posicao [%d] = ",i);
	scanf("%d", &V[i]);
	if((V[i]<0) || (V[i]>1))
	{
		printf("\nValor invalido, digite outro!\n");
		i--;
	}
}
for(i=0;i<I;i++)
{
	printf("%d ",V[i]);
}
printf("\n");
pos=0;
k=1;
for(i=I-1;i>=0;i--)
{
pos=pos+(V[i]*(pow(2,(k-1))));
printf("\n%u ",pos );
k++;
}
printf("\nO numero Binario: ");
for(i=0;i<I;i++)
{
	printf("%d",V[i]);
}
printf(" eh = %u na base decimal",pos );
getchar();
getchar();
}

