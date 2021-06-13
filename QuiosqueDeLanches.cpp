// NOME: Joao Pedro Rodrigues Neves SÉRIE: 1D
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define T 100
    struct dados_mesa {
            int nMesa,nPedido[51],ntp;
            float totalP;
    }mesa[T];
    int op = 1;
    void pedidoAtual(int p){
        mesa[p].totalP = 0;
        printf("\n\tPEDIDO %d",p+1);
        printf("\n\t\tMESA %d", mesa[p].nMesa);
        printf("\n\t\tLANCHES:");
        for(int k = 0; k <= mesa[p].ntp; k++){
            switch(mesa[p].nPedido[k]){
                case 1:
                    mesa[p].totalP = mesa[p].totalP + 5;
                    printf("\n\t\t\t%d – Bauru ......................R$ 5,00", k);
                break;
                case 2:
                    mesa[p].totalP = mesa[p].totalP + 4.5;
                    printf("\n\t\t\t%d – X Salada ...................R$ 4,50", k);
                break;
                case 3:
                    mesa[p].totalP = mesa[p].totalP + 6;
                    printf("\n\t\t\t%d – X Frango ...................R$ 6,00", k);
                break;
                case 4:
                    mesa[p].totalP = mesa[p].totalP + 6;
                    printf("\n\t\t\t%d – X Pernil ...................R$ 6,00", k);
                break;
                case 5:
                    mesa[p].totalP = mesa[p].totalP + 8;
                    printf("\n\t\t\t%d – X Tudo .....................R$ 8,00", k);
                break;
                case 6:
                    mesa[p].totalP = mesa[p].totalP + 3;
                    printf("\n\t\t\t%d – Cacho quente ...............R$ 3,00", k);
                break;
            }
        }
        printf("\n\t\tTOTAL DO PEDIDO DA MESA %d = R%c %.2f",mesa[p].nMesa, 36, mesa[p].totalP);
    }
    void mesasDoDia(int fim){
        float totalR = 0;
        printf("\n\t\t\tLANCHONETE COMA BEM!\n");
        for(int p = 0; p <= fim; p++){
            pedidoAtual(p);
            totalR = totalR + mesa[p].totalP;
        }
        printf("\n\tTOTAL AO TODO: R%c %.2f",36,totalR);
    }
    int confere(int i){
        op=3;
        for(int j = 0; j<=i; j++){
            if (j != i) {
                if((mesa[i].nMesa == mesa[j].nMesa)){
                    while((op!=0)&&(op!=1)){
                        printf("\nEsta mesa já esta preenchida, deseja: \n\t0 - adicionar lanches ao pedido da mesa %d\n\t1 - Limpar a mesa %d e colocar um novo cliente nela\n\t  Opcao: ", mesa[j].nMesa, mesa[j].nMesa);
                        scanf("%d",&op);
                        if((op!=0)&&(op!=1))
                            printf("Opcao Invalida, tente novamente!!!");
                    }
                    if(op){//op == 1
                        int z, k;
                        for(z = j; z <= i; z++){
                            mesa[z].nMesa = mesa[z+1].nMesa;
                            mesa[z].totalP = mesa[z+1].totalP;
                            for(int l = 0; l <= mesa[z+1].ntp; l++)
                                mesa[z].nPedido[l] = mesa[z+1].nPedido[l];
                        }
                        return i = i-1;
                        // mesa[]
                    }else{//op == 0
                        printf("\nATENCAO: Para parar de pedir lanches de uma mesa especifica, escolha a opção 7 – Nenhum lanche!!!\n");
                        int k, ok;
                        for(k = mesa[j].ntp+1; k <= T; k++){
                            ok = 1;
                            while(ok){
                                ok = 0;
                                printf("\n\t  PEDIDO DA MESA %d:\n",mesa[i].nMesa);
                                printf("\nLanche: %d\n", k+1);
                                printf("\nEscolha sua opção de lanche e digite o código correspondente:\n\t1 – Bauru ......................R$ 5,00\n\t2 – X Salada ...................R$ 4,50\n\t3 – X Frango ...................R$ 6,00\n\t4 – X Pernil ...................R$ 6,00\n\t5 – X Tudo .....................R$ 8,00\n\t6 – Cacho quente ...............R$ 3,00\n\t7 – Nenhum lanche\n\t  Opcao desejada: ");
                                scanf("%d",&mesa[j].nPedido[k]);
                                if(!((mesa[j].nPedido[k]==1)||(mesa[j].nPedido[k]==2)||(mesa[j].nPedido[k]==3)||(mesa[j].nPedido[k]==4)||(mesa[j].nPedido[k]==5)||(mesa[j].nPedido[k]==6)||(mesa[j].nPedido[k]==7))){
                                    printf("\nOpcao invalida, tente novamente!!!");
                                    ok = 1;
                                }
                            }
                            if(mesa[j].nPedido[k] == 7)
                                break;
                        }
                        mesa[j].ntp = k-1;
                        // printf("\n**%d**",mesa[j].ntp);
                        pedidoAtual(j);
                        return i;
                    }
                }
            }else{
                return i;
            }
        }
    }
    int main(void){
        int remoteLogOut = 1;
        int ok = 1, i = 0, k;
        printf("\nAtencao: Quando voce colocar um numero de mesa ja posto anteriormente, sera direcionado a um campo de edicao do pedido!!!\n");
        while(remoteLogOut){//remoteLogOut
            printf("\n\t\t   LANCHONETE COMA BEM!\n");
            printf("\nEntre com o numero de sua mesa: ");
            scanf("%d",&mesa[i].nMesa);
            if(i>0)
                i = confere(i);
            for(k = 0; k < T; k++){
                ok = 1;
                if(op==0)
                    ok = 0;
                else
                    printf("\nATENCAO: Para parar de pedir lanches de uma mesa especifica, escolha a opção 7 – Nenhum lanche!!!\n");
                while (ok) {
                    ok = 0;
                    printf("\n\t  PEDIDO DA MESA %d:\n",mesa[i].nMesa);
                    printf("\nLanche: %d\n", k+1);
                    printf("\nEscolha sua opção de lanche e digite o código correspondente:\n\t1 – Bauru ......................R$ 5,00\n\t2 – X Salada ...................R$ 4,50\n\t3 – X Frango ...................R$ 6,00\n\t4 – X Pernil ...................R$ 6,00\n\t5 – X Tudo .....................R$ 8,00\n\t6 – Cacho quente ...............R$ 3,00\n\t7 – Nenhum lanche\n\t  Opcao desejada: ");
                    scanf("%d",&mesa[i].nPedido[k]);
                    if(!((mesa[i].nPedido[k]==1)||(mesa[i].nPedido[k]==2)||(mesa[i].nPedido[k]==3)||(mesa[i].nPedido[k]==4)||(mesa[i].nPedido[k]==5)||(mesa[i].nPedido[k]==6)||(mesa[i].nPedido[k]==7))){
                        printf("\nOpcao invalida, tente novamente!!!");
                        ok = 1;
                    }else
                        system("cls");
                }
                if(mesa[i].nPedido[k] == 7)
                    break;
            }
            mesa[i].ntp = k-1;
            if(op!=0){
                pedidoAtual(i);
                printf("\n\tPressione Enter para continuar!");
            }
            getchar();
            getchar();
            system("cls");
            ok = 1;
            while(ok){
                ok = 0;
                printf("\nO caixa deseja fechar o caixa?\n0 - SIM\t\t1 - NAO\n\t Opcao: ");
                scanf("%d",&remoteLogOut);
                if((remoteLogOut!=0)&&(remoteLogOut!=1)){
                    printf("\nAtencao: Só temos as opcoes 0 ou 1. Tente novamente!!!\n");
                    ok = 1;
                    getchar();
                }
            }
            if(op!=0)
                i++;
            system("cls");
            // int numeroPedidos = i-1;
            // mesasDoDia(numeroPedidos);
        }
        int numeroPedidos = i-1;
        mesasDoDia(numeroPedidos);
        printf("\n");
    }
