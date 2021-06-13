
#include "stdio.h"
 #include "curses.h"
 #include "math.h"
int main(void)
{
int Hex,ok=0;
while(ok==0)
{
printf("\nEntre com o numero em base 16 = ");
scanf("%x", &Hex);
printf("\nO valor em base Hexadecimal %x, em base decimal = %d",Hex,Hex);
getchar();
getchar();
printf("\nDeseja realizar o programa novamente\n0-sim 1-nao\n");
scanf("%d",&ok);
}
}
