//LLALLIER PALLU CARDOSO DE FARIA
#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "conio.h"
#include "string.h"
#include "ctype.h"
// Declaro varias que serao usadas em varias funcoes fora de todas funcoes: variaveis globais
int i,limite=0,ok,linha,b;
char edit;
	struct dados_dos_produtos{//Crio um vetor de structs que vai armazenar os dados de cada produto em uma posicao
		char pdt[100];
		float valor;
		int qtd;
	}inf_produto[500];
/*Declaro e desenvolvo as funcoes no cabecalho em cima da sua funcao fonte (main)*/
void incluir(void){
	int t;
	//Pergunta para definir o limite do vetor
	printf("Quantos produtos voce deseja registrar?\n");
	scanf("%d", &t);
	for(i=limite+1;i<=t+limite;i++){//zera strings
		inf_produto[i].pdt[0]='\0';
		inf_produto[i].valor=0;
		inf_produto[i].qtd=0;
	}
	printf("Digite os produtos desejados: ");//Coleta as informacoes dos produtos para o estoque.
	for(linha=limite+1;linha<=t+limite;linha++){//da quantidade atual para a final, desejada pelo usuario
		printf("\nProduto %d : ", linha);
		scanf("%s", inf_produto[linha].pdt);
		printf("\nValor do(a) %s : ", inf_produto[linha].pdt);
		scanf("%f", &inf_produto[linha].valor);
		printf("\nQuantidade em estoque do produto %s : ", inf_produto[linha].pdt);
		scanf("%d", &inf_produto[linha].qtd);
	}
	//printf final do estoque
	printf("\n\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=t+limite;i++){
		printf("\n%s\t\t\tR%c%.2f\t\t\t%d        ",inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
	limite=limite+t;//Incrementa ao limite o tanto de produtos incljuidos.
}

void consultar(void){
	char consultar[1000];
	getchar();
	int cont=0;
	printf("\nDigite o nome do produto que voce deseja consultar: ");
	scanf("%[^\n]s", consultar);//Pede nome do produto a ser consultado
	for (int i=1;i<=limite;i++) {//Vamos procurar por todo nosso estoque para achar um produto com o nome dado pelo usuario
		// strcmp compara 2 strings, que quando identicas fazem a funcao retornar 0
		if((strcmp(consultar,inf_produto[i].pdt))==0){//Quando acha imprime suas informacoes
			printf("\n\nProduto\t\t\tValores\t\t\tQuantidade");
			printf("\n%s\t\t\tR%c%.2f\t\t\t%d        ",inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
		}else{
			cont++;
			if(cont >= limite)//se sim o produto correu pelo programa inteiro e n achou um string identica
				printf("\n%s nao existe no estoque", consultar);
		}
	}
}

void estoque(void){
	/* função que edita o estoque
	Primeiramente um
	Uma pergunta com o
	Um
	Uma estrutura de decisão que permita o usuário escolher sua função digitando em letra maiúscula ou minúscula
	A estrutura de cada função é mostrada após a opcao do usuário
	Um printf final mostrando o novo estoque
	*/
	ok=0;
	printf("\nAtual Estoque\n");//printf do estoque antigo sera exibido
	printf("\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=limite;i++){
		printf("\n%d-%s\t\t\tR%c%.2f\t\t\t%d\n",i,inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
	while(ok==0){
		ok=1;
		printf("\nDigite o numero da linha que voce deseja modificar: ");
		scanf("%d", &linha);//numero da linha que deseja modificar
		if ((linha<1)||(linha>limite)){
			printf("\nNao temos produtos na linha %d no estoque, de uma nova",linha);
			ok=0;
		}
	}
	edit = ' ';//"zera" a var char
	ok = 0;
	getche();
	while (ok == 0) {//submenu para o usuario mostra suas opcoes de edicao de estoque
		ok=1;
		printf("\nO que voce deseja modificar? ");
		printf("\nP-Produto");
		printf("\nV-Valores");
		printf("\nQ-Quantidade");
		printf("\nEscolha sua opcao: ");
		scanf("%s", &edit);
		edit=toupper(edit);//toupper transforma letras minusculas em maiusculas
		if(edit=='P'){
			printf("Entre com o novo nome para o produto %s: ",inf_produto[linha].pdt);
			inf_produto[linha].pdt[0]='\0';
			scanf("%s", inf_produto[linha].pdt);
		}else{
			if(edit=='V'){
				inf_produto[linha].valor=0;
				printf("Digite o novo valor do prduto %s: ", inf_produto[linha].pdt);
				scanf("%f", &inf_produto[linha].valor);
			}else{
				if(edit=='Q'){
					inf_produto[linha].qtd=0;
					printf("\nDigite a nova quantidade em estoque do produto %s: ",inf_produto[linha].pdt);
					scanf("%d", &inf_produto[linha].qtd);
				}else{
					printf("\nOpcao invalida, tente novamente!!");
					ok=0;
				}
			}
		}
	}
	printf("\nAtual Estoque\n");
	printf("\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=limite;i++){
		printf("\n%d-%s\t\t\tR%c%.2f\t\t\t%d\n",i,inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
}

void listar_todos(void){
	//Imprime todo estoque
	printf("\n\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=limite;i++){
		printf("\n%s\t\t\tR%c%.2f\t\t\t%d        ",inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
}

void excluir(void){
	printf("\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=limite;i++){
		printf("\n%d-%s\t\t\tR%c%.2f\t\t\t%d        ",i,inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
	printf("\nDigite a posicao referente ao produto que voce deseja excluir: ");
	scanf("%d", &linha);
	inf_produto[linha].pdt[0]='\0';//Zera nome de produto na linha escolhida pelo usuario
	for(i=linha;i<=limite;i++){//sobrepoe as informacoes da linha de baixo para a de cima, afim de n imprimir uma linha vazia. Da liha escolhida até a ultima.
		strcpy(inf_produto[i].pdt,inf_produto[i+1].pdt);//Copia segunda string para a primeira
		inf_produto[i].valor=inf_produto[i+1].valor;
		inf_produto[i].qtd=inf_produto[i+1].qtd;
	}
	limite--;//Como excluimos uma linha ele diminui o limite de elementos no estoque
	printf("\nImpressao com linha definida excluida");
	printf("\nProduto\t\t\tValores\t\t\tQuantidade");
	for(i=1;i<=limite;i++){
		printf("\n%d-%s\t\t\tR%c%.2f\t\t\t%d        ",i,inf_produto[i].pdt,36,inf_produto[i].valor,inf_produto[i].qtd);
	}
}

int main(void){
	setlocale(LC_ALL,"portuguese");
	int opcao,ok;
	ok=limite=0;
	while(ok==0){
		printf("\n\t\tVISUAL MODAS");
		printf("\n\tANA CLARA LEMES DE OLIVEIRA 1B\n");
		printf("\n\t1-Incluir");
		printf("\n\t2-Excluir");
		printf("\n\t3-Editar estoque");
		printf("\n\t4-Consultar");
		printf("\n\t5-Lista todos");
		printf("\n\t6-Encerrar");
		printf("\n\tOpcao: ");
		scanf("%d", &opcao);
		system("cls");
		if(opcao==1){
			incluir();
		}else
		if(opcao==2){
			excluir();
		}else
		if(opcao==3){
			estoque();
		}else
		if(opcao==4){
			consultar();
		}else
		if(opcao==5){
			listar_todos();
		}else
		if(opcao==6){
			printf("Programa encerrado");
			ok=1;
		}
		getche();
		system("cls");
	}
}
