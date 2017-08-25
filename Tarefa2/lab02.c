#include <stdio.h>

typedef struct{
    int cod;
    int idade;
    struct No *prox;
}No;


typedef struct{
    No *inicio0;
    No *inicio1;
    No *inicio2;
    No *inicio3;
    No *inicio4;
}Lista;


void iniciarLista(Lista *endLista){
    endLista->inicio0 = NULL;
    endLista->inicio1 = NULL;
    endLista->inicio2 = NULL;
    endLista->inicio3 = NULL;
    endLista->inicio4 = NULL;
} //Cria uma variavel que aponta para um endereco de memoria do struct Lista(ou seja, cria um primeiro no que aponta para NULL). Esse sera o inicio da lista de nos. 


No *busca(Lista *endLista, int idade, No **ant){
    *ant = NULL;
    No *atual = endLista->inicio; // Cria uma variavel que aponta para o inicio da lista e serve de indice para inserir algum elemento.
    
    while((atual != NULL)&&(atual->idade < idade)){
        *ant = atual;
        atual = atual->prox;
    } //1- O laco percorre os nos ate chegar em NULL (final da lista). 2-Percorre ate o momento em que a idade usada na busca eh maior ou igual a um elemento de algum no da lista. 
    
    if((atual != NULL)&&(atual->idade == idade)){
        return atual;
    } // Se ele encontrar um elemento igual ao buscado em algum dos nos, encerra-se a funcao.
    
    return NULL;
} 

No *busca_inicio_lista(){
    
}

void inserirComeco(Lista *endLista, int cod, int idade, int cat){
    No *paciente = malloc(sizeof(No));
    if(cat == 0){
        endLista->inicio = paciente->categoria; //endLista = novo;
        paciente->cat = cat; 
        paciente->prox = NULL;
        paciente->categoria = cod;
        paciente->idade = idade;
    }
    if(cat == 1){
        
    }
    if(cat == 2){
        
    }
    if(cat == 3){
        
    }
    if(cat == 4){
        
    }
}


void addLista(Lista *endLista, int cod, int idade, int cat){
    No *x, *y;
    No *ant = NULL;
    x = busca(&endLista, idade, &ant);
    if(x != NULL){
        return;
    }
    if(ant == NULL){
        inserirComeco(&endLista, cod, idade, cat);
        
    }else{
        y = busca_inicio_lista();
        if(y == NULL){    
            if(cat == 0){
                
            }
            if(cat == 1){
                        
            }
            if(cat == 2){
                
            }
            if(cat == 3){
                
            }
            if(cat == 4){
                
            }
        }
    }       
}



int main(){
    int a, cod, cat, idade;
    Lista A;
    iniciarLista(&A);
    while(scanf("%d", &a) == 1){
        if(a == 1){
            scanf("%d %d %d", &cod, &cat, &idade);
            addLista(&A, cod, idade, cat);
        }
        if(a == 2){
            removerLista();
        }
        if(a == 3){
            chamarPaciente();
        }
        if(a == 4){
            mudarPaciente();
        }
        if(a == 5){
            imprimirCategoria();
        }
        if(a == 6){
            imprimirLista();
        }
        
        
        
        
        
        
    }
    
    
}