    #include<iostream>
    #include<math.h>
    #include<curses.h>
    #include<stdio.h>
    #include<time.h>
    #include<unistd.h>
    #include<stdlib.h>
    #define T 1000
    int *vetor,dim;
void bus_lin(void){
    int e,cont_e=0,i;
    printf("\nEntre com o elemento a ser encontrado = ");
    scanf("%d",&e);
    // Buscando o elemento no vetor
    for(i=0;i<=dim;i++){ // vare o vetor procurando pela ocorrência do elemento desejado
        if(vetor[i]==e){
            cont_e++;
            printf("\nElemento %d encontrado na posicao %d do vetor",e,i);
        }
    }
    // imprimindo o total de elementos se encontrados
    if(cont_e>0){
        printf("\n\nTotal de elementos encontrador = %d",cont_e);
    }else{
        printf("\nNao foram encontrados elementos %d no vetor ",e);
    }
}
void bus_bin(void){
    int found,i,r,ele,pos;
    printf("\n\nEntre com elemento a ser encontrado :");
    scanf("%d",&ele);
    i=1;r=dim;found=1; // inicia i em 1 como limite inferior e r em n como limite superior e found=1,
    // found eh uma var que muda quan do o elemento eh encontrado
    while((i<=dim) && (found==1)){ // faz enquanto o limite inferior em i seja menor que o limite superior em n e found=1
        pos=(i+r)/2;
        if(((i>r) || (r<i)) && (vetor[pos] != ele)){ // se o limite inferior chegar ao limite superior ou vise versa e o elemento desta
            //posição não for igual a que se esta procurando, avisa que não existe e muda o valor do found
            printf("Elemento %d nao encontrado!",ele);
            found=0;
        }
        if(vetor[pos]==ele){ // elemento encontrado
                printf("Elemento %d encontrado na posicao %d",ele,pos);
                found=0;
        }else{
            // altera dos limites de procura
            if(vetor[pos]<ele)
                i=pos+1; // se o elemento da posição for < que o elemento que se deseja encontrar, faz o limite inferior (i) subir para pos+1
            else
                r=pos-1; // se o elemento da posição for > que o elemento que se deseja encontrar, faz o limite superior (r) descer para pos-1;
        }
    }
}
void ordenaca_permutacao(void){
    int n,h,aux;
    for(h=0;h<dim;h++){
        for(n=dim-1;n>=h;n--){ // laço para variar o vetor de traz para frente até j ser igual a i
            if(vetor[h]>vetor[n]){ // teste se o elemento do vetor na posição i é maior que o elemento do vetor da posição j
                aux=vetor[h]; // se sim transf o elemento do vetor na posição para uma var aux
                vetor[h]=vetor[n]; // transf o que está na posição j do vetor para a posição i do vetor
                vetor[n]=aux; // transf o que está na var aux para a posição j do vetor
            }
        }
    }
}

int main(void){
    void ordenacao_insercao_binaria(void);
    int i;
    int ok,Hug=0,h;
    char ko,men,bus;
    time_t t_inicial, t_final;
    float t_gasto;
    srand(time(NULL));
    while(Hug==0){
        system("tput clear");
        ok=0;
        while(ok==0){
            printf("\n\nEntre com a dimensao do Vetor maior que zero e menor que %d ",T);
            scanf("%d",&dim);
            if((dim>0) && (dim<=T))
                ok=1;
        }
        t_inicial=time(NULL);
        vetor=(int*)(malloc(dim*sizeof(int)));
        if(vetor==NULL){
            printf("\nErro na alocação de memoria");
            system("read -p \"Pressione enter para sair\" saindo");
            exit(1);
        }
        // geração e impressão do vetor
        for(i=0;i<dim;i++){
            vetor[i]=rand()%1000;
            for(h=0;h<i;h++){
                if(vetor[i]==vetor[h]){
                    h=i+1;
                    i--;
                }
            }
        }
        printf("\n\nImpressao do vetor Gerado e Fora de Ordem \n");
        for(i=0;i<dim;i++){
            printf("%d ",vetor[i]);
        }
        std::cout.flush();
        sleep(1);
        getchar();
        men=' ';
        while((men!='P')&&(men!='p')&&(men!='I')&&(men!='i')){
            printf("\n\nQual das ordenações deseja executar?\nOrdenação por permutação-P\nInserção Binaria-I\n");
            men=getchar();
        }
        // chamada da fução para ordenar por Inserção Binária
        if((men=='I')||(men=='i')){
            ordenacao_insercao_binaria();
        }else{
            ordenaca_permutacao();
        }
        printf("\n\nImpressao do vetor Gerado e em Ordem \n");
        for(i=0;i<dim;i++){
            printf("%d ",vetor[i]);
        }
        getchar();
        bus=' ';
        while((bus!='B')&&(bus!='b')&&(bus!='L')&&(bus!='l')){
            printf("\n\nQual busca deseja realizar? \nB-Busca Binária\nL-Busca Linear\n");
            bus=getchar();
        }
        if((bus=='B')||(bus=='b'))
            bus_bin();
        else
            bus_lin();
        getchar();
        ko=' ';
        while((ko!='y')&&(ko!='Y')&&(ko!='N')&&(ko!='n')){
            printf("\n\nDeseja executar novamente ? Y-sim  N-nao");
            ko=getchar();
        }
        if((ko=='N')||(ko=='n')){
            Hug=1;
        }
        free(vetor);
        t_final=time(NULL);
        t_gasto=difftime(t_final,t_inicial);
        printf("\nO tempo gasto para realizar a ordenacao ");
        if((men=='I')||(men=='i'))
            printf("por Insecao Binaria e");
        else
            printf("por Permutacao e");
        if((bus=='B')||(bus=='b'))
            printf(" a busca binaria ");
        else
            printf(" a busca linear ");
        printf("foi %.5f",t_gasto);
    }
}


// declaração da funcao para ordenar por Inserção Binária
void ordenacao_insercao_binaria(void){
    int i,j,temp,l,r,pos;
    // rotina de ordenacao
        for(i=1;i<dim;i++){
            temp=vetor[i];
            l=0;
            r=i;
            while(l < r){
                pos = (l + r) / 2;
                if(vetor[pos] <= temp)
                    l = pos + 1;
                else
                    r = pos;
            }
            for(j=i;j>=r+1;j--)
                vetor[j]=vetor[j-1];
                vetor[r]=temp;
        }
        // impressão do vetor ordenado
        printf("\n\nImpressão do Vetor Ordenado por Insercao Binaria \n");
        for(i=0;i<dim;i++){
            printf("%d ",vetor[i]);
        }
}
