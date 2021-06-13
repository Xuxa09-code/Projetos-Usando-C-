#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define I 20
int main(void)
{
int dec,cont=0,V[I],Bin,i,dec1;
printf("\nEntre com o Valor decimal desejado = ");
scanf("%d", &dec1);
Bin=dec1;
while(Bin>=1)
{
	Bin=Bin/2;
	cont++;
}
dec=dec1;
for(i=1;i<=cont;i++)
{
if(dec>1)
{
V[i]=dec%2;
dec=dec/2;
}else
{
V[i]=dec;
}
}
printf("\n");
printf("O numero decimal: %d eh ",dec1);
for(i=cont;i>=1;i--)
{
printf("%d",V[i]);
}
printf(" em binario");
getche();
getche();
}
