    #include<stdio.h>
    #include<curses.h>
    #include<time.h>
    #include<stdlib.h>
    #include<curses.h>
int main(void){
    int mat[21][21],i,j,cont_e=0,e,h,m,dim_l,dim_c,ok=0,aux;
    srand(time(NULL));
    while(ok==0){
        printf("\nEntre com a dimensao de linhas da matriz com no maximo 10 =  ");
        scanf("%d", &dim_l);
        if((dim_l>0) && (dim_l<=10)){
        	ok=1;
        }else{
            printf("\nValor incorreto, digite-o novamente!");}
        }
        ok=0;
        while(ok==0){
            printf("\nEntre com a dimensao da colunas da matriz com no maximo 10 =  ");
            scanf("%d", &dim_c);
            if((dim_c>0) && (dim_c<=10)){
        	    ok=1;
            }else{
                printf("\nValor incorreto, digite-o novamente!");
            }
        }
            for(i=0;i<dim_l;i++){
                for(j=0;j<dim_c;j++){
	                mat[i][j]=0;
                }
            }
            //valor dos elementos
            for(i=0;i<dim_l;i++){
                for(j=0;j<dim_c;j++){
	                mat[i][j]= rand()%100;
                    for(h=0;h<dim_l;h++){
                        for(m=0;m<dim_c;m++){
                            if(h==i){
                                if((mat[h][m]==mat[i][j]) && (m!=j)){
	                                m=dim_c;
	                                h=dim_l;
	                                j--;
                                }
                            }else{
                                if(mat[h][m]==mat[i][j]){
                                    m=dim_c;
	                                h=dim_l;
	                                j--;
                                }
                            }
                        }
                    }
                }
            }
            for(i=0;i<dim_l;i++){
                for(j=0;j<dim_c;j++){
                    for(h=0;h<dim_l;h++){
                        for(m=0;m<dim_c;m++){
                            if(mat[i][j]<mat[h][m]){
	                            aux=mat[i][j];
	                            mat[i][j]=mat[h][m];
	                            mat[h][m]=aux;
                            }
                        }
                    }
                }
            }
            printf("\n");
            printf("\nimpressao da matriz ordenada\n");
            printf("\n");
            for(i=0;i<dim_l;i++){
                printf("\n");
                for(j=0;j<dim_c;j++){
                    printf("%d ",mat[i][j]);
                }
            }
            printf("\n");
            ok=1;
            while(ok==1){
                cont_e=0;
                printf("\nEntre com o elemento a ser encontrado = ");
	            scanf("%d",&e);
            	// Buscando o elemento no vetor
	            for(i=0;i<dim_c;i++){
		            for(j=0;j<dim_l;j++){
                		if(mat[i][j]==e){
		  	                cont_e=cont_e+1;
		  	                printf("\nElemento %d encontrado na posicao [%d][%d] da Matriz",e,i,j);
		                }
	                }
	            }
	        // imprimindo o total de elementos se encontrados
	        if(cont_e>0){
	            printf("\n\nTotal de elementos encontrador = %d\n",cont_e);
	        }else{
	            printf("\nNao foram encontrados elementos %d na Matriz \n",e);
            }
	        printf("\nDeseja procurar novamente? sim-1 nao-0 = ");
	        scanf("%d",&ok);
    }

}
