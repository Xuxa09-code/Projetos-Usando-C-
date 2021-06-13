/*LALLIER PALLU CARDOSO DE FARIA 1C*/
#include "curses.h"
#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "locale.h"
#include "math.h"
#include "string.h"
#include "buscas.h"
#include "criptografia.h"
#include "ordenacoes.h"
#define T 1000
FILE *arq;
int dim;
    char nome_arquivo_f(char nome_arquivo[T]){
        getchar();
        printf("\n\nEntre com o nome do arquivo que sera manipulado: ");
        scanf("%[^\n]s",nome_arquivo);
    }
    int ler_arquivo(char e,char nome_arquivo[],char mensagem[T],int numeros[T]){
        int i=0,t=0;
        if((arq=fopen(nome_arquivo,"r"))==NULL){
            printf("\n\nEste Arquivo Nao Existe\n\n");
            return -1;
        }
        if(t!=1){
            printf("\n\nVetor do arquivo %s\n",nome_arquivo);
            while(fscanf(arq,"%c",&mensagem[i])!=EOF){
                numeros[i]=mensagem[i]-'0';
                i++;
            }
            dim=i-1;
            numeros[i]='*';
            mensagem[i]='\0';
            getchar();
            for(i=0;numeros[i]!='*';i++){
                if(e=='C')
                    printf("%c",mensagem[i]);
                else
                    printf("%d ",numeros[i]);
            }
            fclose(arq);
            return 0;
        }
        getchar();
    }
    int criar_arquivo(char e,char nome_arquivo[T],char mensagem[T],int numeros[T]){
        int i;
        char aux;
        if((arq=fopen(nome_arquivo,"w"))==NULL){
            printf("Nao posso abrir o arquivo.");
            exit(0);
        }
        getchar();
        i=0;
        printf("\n\nEntre com a mensagem que desaja gravar no arquivo \n\n");
        while((aux=getchar())!='\n'){
            mensagem[i]=aux;
            if(e=='C')
                putc(mensagem[i],arq);
            else{
                numeros[i]=mensagem[i]-'0';
                fprintf(arq,"%d",numeros[i]);
            }
            i++;
        }
        numeros[i]='*';
        mensagem[i]='\0';
        dim=i;
        printf("\n\nConteudo do arquivo\n\t");
        if(e=='C')
            for(i=0;i<dim;i++)
                printf("%c",mensagem[i]);
        else
            for(i=0;numeros[i]!='*';i++)
                printf("%d ",numeros[i]);
        printf("\n");
        fclose(arq);
        printf("\nArquivo %s gerado com sucesso!!!",nome_arquivo);
    }
    char escolha_int_char(void){
        int cont=0;
        char e=' ';
        getchar();
        while((e!='N')&&(e!='C')){
            if(cont>0)
                printf("\nOpcao Invalida, tente novamente!");
            printf("\n\nO usuario deseja gravar um arquivo de:\n\tN-Numeros\n\tC-Caracteres\n\t  Opcao: ");
            e=toupper(getchar());
            cont++;
        }
        return e;
    }
    int numero_bus(void){
        int e;
        getchar();
        printf("\nEntre com o elemento a ser encontrado = ");
        scanf("%d",&e);
        return e;
    }
    char escolha_busca(int numeros[]){
        char op=' ';
        int vet[T],e,res,i;
        while((op!='L')&&(op!='B')&&(op!='S')){
            printf("\nO usuario deseja fazer qual das buscas?\n\tL-Busca Linear\n\tB-Busca Binaria\n\tS-Voltar para o Menu principal\n\t  Opcao: ");
            op=toupper(getchar());
            switch(op){
                case 'L':
                    e=numero_bus();
                    res=bus_lin(e,numeros,vet);
                    if(res==0){
                        printf("\nFoi encontrado o numero %d nas posicoes:",e);
                        for(i=0; vet[i+1]!='*';i++)
                            printf("\nVetor[%d] = %d",vet[i],e);
                        printf("\nTotal de numeros encontrados: %d\n",vet[i]);
                    }else
                        printf("\nAlgo de errado aconteceu, Verefique!\n");
                break;
                case 'B':
                    e=numero_bus();
                    res=bus_bin(e,numeros);
                    switch(res){
                        case (-1):
                            printf("\nVetor com um elemento repetido, Verifique!");
                        break;
                        case (-2):
                            printf("\nVetor desordenado, Verifique!");
                        break;
                        case (-3):
                            printf("\nO numero %d nao foi encontrado!",e);
                        break;
                        default:
                            printf("Numero %d encontrado na posicao %d!\n",e,res);
                        break;
                    }
                break;
                case 'S': break;
                default: printf("\nOpcao invalida, tente novamente!\n"); break;
            }
        }
        getchar();
    }
    char escolha_ordenacao(int numeros[T]){
        char op=' ',nome_arquivo[T];
        int res=0;
        while((op!='P')&&(op!='S')&&(op!='I')&&(op!='D')&&(op!='B')&&(op!='C')){
            printf("\nO usuario deseja realizar qual das ordenações abaixo:");
            printf("\n\tP-PERMUTAÇÃO\n\tS-SELEÇÃO DIRETA\n\tD-INSERÇÃO DIRETA\n\tB-BOLHA\n\tI-INSERÇÃO BINÁRIA\n\tC-Voltar para o Menu principal\n\t  Opcao: ");
            op=toupper(getchar());
            if((op!='P')&&(op!='S')&&(op!='I')&&(op!='D')&&(op!='B')&&(op!='C')){
                printf("\n\nOpcao Invalida, tente novamente!");
                getchar();
            }
        }
        if(op!='C'){
            switch(op){
                case 'P': ordenaca_permutacao(numeros,dim); break;
                case 'S': selecao_direta(numeros,dim); break;
                case 'D': ordenacao_insercao_direta(numeros,dim); break;
                case 'B': ordenacao_bolha(numeros,dim); break;
                case 'I': res=ordenacao_insercao_binaria(numeros,dim); break;
            }
            switch(res){
                case (-1): printf("\nVetor com numero repetido e ordenacao por Insercao Binaria nao permite, Verefique!"); break;
                default:
                    printf("\nVet ordenado: \n\t");
                    for(int i=0; numeros[i]!='*';i++)
                        printf("%d ",numeros[i]);
                break;
            }
            printf("\nATENCAO: Neste momento o usuario vai criar um arquivo pra alocar o vetor ordenado!\n");
            nome_arquivo_f(nome_arquivo);
            if((arq=fopen(nome_arquivo,"w"))==NULL){
                printf("Nao posso abrir o arquivo.");
                exit(0);
            }
            for(int i=0;i<dim;i++)
                fprintf(arq,"%d",numeros[i]);
            fclose(arq);
            printf("\nArquivo %s gerado e gravado!!!\n",nome_arquivo);
            getchar();
        }
    }
    void palavra_chave(char pchave[T],char op[3]){
        int i=0,dim;
        getchar();
        printf("\nEntre com a palavra chave: ");
        while((pchave[i]=getchar())!='\n')
            i++;
        dim=i;
        pchave[i]='\0';
        if(strcmp(op,"TS")==0){
            for(i=0;i<dim;i++)
                pchave[i]=toupper(pchave[i]);
        }
    }
    void montagem_exemplo(void){
        int i,j;
        char vet_rota[6][6];
        for(i=1;i<=5;i++){
            for(j=1;j<=5;j++)
                vet_rota[i][j]='.';
        }
        vet_rota[1][1]='1';
        vet_rota[1][5]='2';
        vet_rota[5][5]='3';
        vet_rota[5][1]='4';
        for(i=1;i<=5;i++){
            printf("\n");
            printf("\t\t");
            for(j=1;j<=5;j++)
                printf("%c ",vet_rota[i][j]);
        }
    }
    char chave_rota_H_A(){
        printf("\nComo chave, na criptografia por rota, voce tem que escolher o sentido sentido e ponto de inicio.");
        char chave=' ';
        while((chave!='H')&&(chave!='A')){
            getchar();
            printf("\nSentido:\nH-Horario\tA-Anti-horário\n");
            chave=toupper(getchar());
        }
        return chave;
    }
    int chave_rota_1234(void){
        int chave1=5;
        while((chave1>4)||(chave1<1)){
            printf("\n\t    Ponto de Inicio:\n");
            montagem_exemplo();
            printf("\n1-Superior Esquerdo\t2-Superior Direito\n3-Inferior Direito\t4-Inferior Esquerdo\n");
            scanf("%d",&chave1);
        }
        return chave1;
    }
    char escolha_criptografia(char mensagem[T]){
        char op[3]="XX",ok=' ',cripto[T],pchave[T],chave_char,nome_arquivo[T];
        int i=1,chave;
        printf("\nATENCAO:\n\tNas mensagens dos arquivos a serem criptografados, as palavras devem estar separados por espaco ' ', ou underline '_'\n\tNos que forem ser descriptografados, devem ser arquivos criptografados antes");
        printf("\nSe nao satisfeitas as condicoes a cima, programa sujeito a erros!!!\n");
        while(ok==' '){
            ok='y';
            printf("\nO usuario deseja fazer qual das criptografias?");
            printf("\n\tSS-SIMPLES\n\tCR-CESAR\n\tPA-POLIALFA\n\tTS-TRANSPOSIÇÃO SIMPLES\n\tTR-TRANSPOSIÇÃO POR ROTA\n\tRF-RAIL FENCE\n\tSC-Voltar para o Menu principal\n\t  Opcao: ");
            scanf("%s",op);
            if((strcmp(op,"SS")!=0)&&(strcmp(op,"CR")!=0)&&(strcmp(op,"PA")!=0)&&(strcmp(op,"TS")!=0)&&(strcmp(op,"TR")!=0)&&(strcmp(op,"RF")!=0)&&(strcmp(op,"SC")!=0)){
                printf("\nOpcao Invalida, tente novamente!");
                ok=' ';
            }
        }
        if(strcmp(op,"SC")!=0){
            getchar();
            while((ok!='C')&&(ok!='D')){
                printf("\nVoce deseja:\n\tC-Criptografia\n\tD-Descriptografia\n\t  Opcao: ");
                ok=toupper(getchar());
                if((ok!='C')&&(ok!='D'))
                    printf("\n\nOpcao Invalida, tente novamente!");
            }
            switch(op[0]){
                case 'S':
                    if(ok=='C'){
                        criptografia_substituicao(mensagem,cripto);
                    }else{
                        descriptografia_substituicao(mensagem,cripto);
                    }
                break;
                case 'C':
                    //cesar
                    while(i==1){
                        printf("\n\nEntre com um valor maior que 0!\n");
                        scanf("%d",&chave);
                        if(chave>=0)
                            i=0;
                        else
                            printf("\nOpção Invalida, tente novamente!");
                    }
                    if(ok=='C')
                        criptografia_cesar(mensagem,cripto,chave);
                    else
                        descriptografia_cesar(mensagem,cripto,chave);
                break;
                case 'P':
                    getchar();
                    palavra_chave(pchave,op);
                    //polialfa
                    if(ok=='C')
                        criptografia_polialfa(mensagem,pchave,cripto);
                    else
                        descriptografia_polialfa(mensagem,pchave,cripto);
                break;
                case 'T':
                    if(op[1]=='S'){
                        palavra_chave(pchave,op);
                        //int tam=strlen(mensagem);
                        //printf("\n%d",tam);
                        //transposicao_simples
                        if(ok=='C')
                            //printf(".");
                            criptografia_transposicaoSimples(mensagem,pchave,cripto);
                        else
                            descriptografia_transposicaoSimples(mensagem,pchave,cripto);
                    }else{
                        //function
                        chave=chave_rota_1234();
                        chave_char=chave_rota_H_A();
                        if(ok=='C')
                            cripitografia_rota(mensagem,cripto,chave,chave_char);
                        else
                            descripitografia_rota(mensagem,cripto,chave,chave_char);
                        //transposicao_rota
                    }
                break;
                case 'R':
                    //rail_face
                    if(ok=='C')
                        criptografia_cerca(mensagem,cripto);
                    else
                        descriptografia_cerca(mensagem,cripto);
                break;
            }
            printf("\nMensagem resultante do processo de ");
            if(ok=='C')
                printf("criptografia: ");
            else
                printf("descriptografia: ");
            printf("%s\n",cripto);
            printf("\nATENCAO: Neste momento o usuario vai criar um arquivo pra alocar a mensagem ");
            if(ok=='C')
                printf("criptografada\n");
            else
                printf("descriptografada!\n");
            nome_arquivo_f(nome_arquivo);
            if((arq=fopen(nome_arquivo,"w"))==NULL){
                printf("Nao posso abrir o arquivo.");
                exit(0);
            }
            fprintf(arq,"%s",cripto);
            fclose(arq);
            printf("\nArquivo %s gerado e criado",nome_arquivo);
        }
    }
    int main(void){
        int cont=0,numeros[T],ler;
        char op[3],e=' ',nome_arquivo[T],mensagem[T],novo_nome[T];
        printf("\n\n\t\tPROJETO DE LOG 4 BIMESTRE\n\t\t\tLALLIER PALLU C. FARIA\n");
        while(op[0]!='S'){
            mensagem[0]='\0';
            cont=0;
            strcpy(op,"XX");
            //while(((op[1]!='C')&&(op[2]!='A'))&&((strcmp(op,"LA"))==0)&&(op!="BS")&&(op!="OS")&&(op!="CS")&&(op!="RM")&&(op!="RN")&&(op!="S")){
            while(((strcmp(op,"CA"))!=0)&&((strcmp(op,"LA"))!=0)&&((strcmp(op,"BS"))!=0)&&((strcmp(op,"OS"))!=0)&&((strcmp(op,"CR"))!=0)&&((strcmp(op,"RM"))!=0)&&((strcmp(op,"RN"))!=0)&&((strcmp(op,"S"))!=0)){
                if(cont>0)printf("\nOpcao Invalida!\n");
                printf("\nEntre com a opcao desejada:");
                printf("\n\tCA-Criar Arquivo\n\tLA-Ler Arquivo\n\tBS-Buscas\n\tOS-Ordenações\n\tCR-Criptografias\n\tRM-Remover Arquivo\n\tRN-Renomear Arquivo\n\tS-Sair\n\n\t\tOpcao: ");
                scanf("%s",op);
                for(int i=0;i<2;i++)
                    op[i]=toupper(op[i]);
                cont++;
            }
            if(op[0]!='S'){
                nome_arquivo_f(nome_arquivo);
                switch(op[0]){
                    case 'C':
                        if(op[1]=='A'){
                            e=escolha_int_char();
                            criar_arquivo(e,nome_arquivo,mensagem,numeros);
                        }else{
                            ler=ler_arquivo('C',nome_arquivo,mensagem,numeros);
                            if(ler==0)
                                escolha_criptografia(mensagem);//criptografias
                        }
                    break;
                    case 'L':
                        e=escolha_int_char();
                        ler_arquivo(e,nome_arquivo,mensagem,numeros);
                    break;
                    case 'B':
                        ler=ler_arquivo('N',nome_arquivo,mensagem,numeros);
                        if(ler==0)
                            escolha_busca(numeros);
                    break;
                    case 'O':
                        ler=ler_arquivo('N',nome_arquivo,mensagem,numeros);
                        if(ler==0)
                            escolha_ordenacao(numeros);
                    break;
                    case 'R':
                        getchar();
                        if(op[1]=='M'){
                            //remover
                            if((remove(nome_arquivo))==0)
                                printf("\nArquivo %s removido com sucesso!!!\n",nome_arquivo);
                            else
                                printf("\nERRO, arquivo nao existente!!!\n");
                        }else{
                            //renomear
                            printf("\nEntre com o novo nome para substituir o %s: ",nome_arquivo);
                            scanf("%[^\n]s",novo_nome);
                            if((rename(nome_arquivo,novo_nome))==0)
                                printf("\nArquivo %s foi renomiado com sucesso!!! Agora seu nome eh: %s\n",nome_arquivo,novo_nome);
                            else
                                printf("\nAlgo de Errado aconteceu, verifique!!!");
                        }
                    break;
                }
            }
            getchar();
            system("tput clear");
        }
        printf("\nObrigado pela atencao!!!\n");
    }
