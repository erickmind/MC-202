//Erick Kussumoto do Nascimento 196492
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int cod;
    int idade;
    struct no *prox;
}No;


typedef struct{
    No *inicio0;
    No *inicio1;
    No *inicio2;
    No *inicio3;
    No *inicio4;
}Lista; //Esse struct serve como inicio que aponta para a lista de cada categoria


void iniciarLista(Lista *endLista){
    endLista->inicio0 = NULL;
    endLista->inicio1 = NULL;
    endLista->inicio2 = NULL;
    endLista->inicio3 = NULL;
    endLista->inicio4 = NULL;
} //Cria uma variavel que aponta para um endereco de memoria do struct Lista(ou seja, cria um primeiro no que aponta para NULL). Esse sera o inicio da lista de nos. 


No *busca(Lista *endLista, int idade, No **ant, int cat){
    *ant = NULL;
     No *atual;
    if(cat == 0){
        atual = endLista->inicio0; // Cria uma variavel que aponta para o inicio da lista e serve de indice para inserir algum elemento.
    }
    if(cat == 1){
        atual = endLista->inicio1; 
    }
    if(cat == 2){
        atual = endLista->inicio2; 
    }
    if(cat == 3){
        atual = endLista->inicio3; 
    }
    if(cat == 4){
        atual = endLista->inicio4;
    }
    
    while((atual != NULL)&&(atual->idade > idade)){
        *ant = atual;
        atual = atual->prox;
    } //1- O laco percorre os nos ate chegar em NULL (final da lista). 2-Percorre ate o momento em que a idade usada na busca eh maior ou igual a um elemento de algum no da lista. 
    
    if((atual != NULL)&&(atual->idade == idade)){
        return atual;
    } // Se ele encontrar um elemento igual ao buscado em algum dos nos, encerra-se a funcao.

    return NULL;
} 


void inserirComeco(Lista *endLista, int cod, int idade, int cat){
    No *paciente = malloc(sizeof(No));
    if(cat == 0){
        paciente->prox = endLista->inicio0;
        endLista->inicio0 = paciente;
    }
    if(cat == 1){
        paciente->prox = endLista->inicio1;
        endLista->inicio1 = paciente;
    }
    if(cat == 2){
        paciente->prox = endLista->inicio2;
        endLista->inicio2 = paciente;
    }
    if(cat == 3){
        paciente->prox = endLista->inicio3;
        endLista->inicio3 = paciente;
    }
    if(cat == 4){
        paciente->prox = endLista->inicio4;
        endLista->inicio4 = paciente;
    }
    paciente->cod = cod;
    paciente->idade = idade;
    
} // A funcao aloca um ponteiro do tipo No dinamicamente para guardar os dados do paciente no inicio da lista. 


void imprimirCategoria(int cat, Lista *endListaEsp, Lista *endListaGeral){
    No *atual;
    int i, vazio, vazio2;
    vazio = 0;
    vazio2 =0;
    Lista *endLista = endListaEsp;
    
    for(i = 0; i < 2; i++){ // O laco serve para imprimir os pacientes tanto da lista especial quanto da lista geral
        if(cat == 0){
            atual = endLista->inicio0;
        }
        if(cat == 1){
            atual = endLista->inicio1;
        }
        if(cat == 2){
            atual = endLista->inicio2;
        }
        if(cat == 3){
            atual = endLista->inicio3;
        }
        if(cat == 4){
            atual = endLista->inicio4;
        }
        
        if(atual == NULL){
            vazio = 1;
        }else{
            vazio = 0;
        }
        
        while(atual != NULL){
            printf("Paciente %d (idade %d) da lista %d\n", atual->cod, atual->idade, cat);
            atual = atual->prox;
            vazio2 = 1;
        }
        endLista = endListaGeral;
    }
    
    if(vazio == 1 && vazio2 == 0){
        printf("Nenhum paciente na categoria %d\n", cat);
    }
} 


void imprimirLista(Lista *endListaEsp, Lista *endListaGeral, int t){
    No *atual;
    atual = endListaEsp->inicio0;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 0\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    atual = endListaGeral->inicio0; 
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 0\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    
    atual = endListaEsp->inicio1;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 1\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    atual = endListaGeral->inicio1;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 1\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    
    atual = endListaEsp->inicio2;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 2\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    atual = endListaGeral->inicio2;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 2\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    
    atual = endListaEsp->inicio3;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 3\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    atual = endListaGeral->inicio3;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 3\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    
    atual = endListaEsp->inicio4;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 4\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    atual = endListaGeral->inicio4;
    while(atual != NULL && t > 0){
        printf("Paciente %d (idade %d) da lista 4\n", atual->cod, atual->idade);
        atual = atual->prox;
        t--;
    }
    
} //A funcao imprime todos os pacientes, ate um inteiro t dado, que vai da lista de maior prioridade para a de menor prioridade


void inserirMeio(No *ant, int idade, int cod){
    No *paciente = malloc(sizeof(No));
    paciente->prox = ant->prox;
    ant->prox = paciente;
    paciente->cod = cod;
    paciente->idade = idade;
} // A funcao insere um no com os dados de um paciente no meio de uma lista


void addLista(Lista *endLista, int cod, int idade, int cat){
    No *x;
    No *ant;
    x = busca(endLista, idade, &ant, cat);
    if(x != NULL){ // Se encontrar algum paciente com a mesma idade na lista
        inserirMeio(x, idade, cod);
        return;
    }
    
    if(ant == NULL){ // Lista vazia ou so ha pacientes mais novos na lista
        inserirComeco(endLista, cod, idade, cat);
    }else{
        inserirMeio(ant, idade, cod); 
    }  
}


No *buscaRemover(int cod, No **ant, Lista *endLista, int *cat){
    *ant = NULL;
    No *atual;
    atual = endLista->inicio0;
    while((atual != NULL)&&(atual->cod != cod)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL)&&(atual->cod == cod)){
        *cat = 0;
        return atual;
    }
    
    *ant = NULL;
    atual = endLista->inicio1;
    while((atual != NULL)&&(atual->cod != cod)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL)&&(atual->cod == cod)){
        *cat = 1;
        return atual;
    }
    
    *ant = NULL;
    atual = endLista->inicio2;
    while((atual != NULL)&&(atual->cod != cod)){    
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL)&&(atual->cod == cod)){
        *cat = 2;
        return atual;
    }
    
    *ant = NULL;
    atual = endLista->inicio3;
    while((atual != NULL)&&(atual->cod != cod)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL)&&(atual->cod == cod)){
        *cat = 3;
        return atual;
    }
    
    *ant = NULL;
    atual = endLista->inicio4;
    while((atual != NULL)&&(atual->cod != cod)){
        *ant = atual;
        atual = atual->prox;
    }
    if((atual != NULL)&&(atual->cod == cod)){
        *cat = 4;
        return atual;
    }
    return NULL;
}


void removerInicio(No **endLista){
    No **temp = endLista;
    *endLista = (*temp)->prox;
}


void removerMeio(No **ant){
    No **temp = &((*ant)->prox);
    (*ant)->prox = (*temp)->prox;
}


void removerLista(int cod, Lista *endListaEsp, Lista *endListaGeral){
    No *ant;
    No *x = NULL;
    No *print;
    int cat, idade;
    x = buscaRemover(cod, &ant, endListaEsp, &cat);
    if(x == NULL)
        x = buscaRemover(cod, &ant, endListaGeral, &cat);
    idade = x->idade;
    if(ant == NULL){
        if(cat == 0){
            if(idade >= 65 || idade <= 3){
                print = endListaEsp->inicio0;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaEsp->inicio0);
            }else{
                print = endListaGeral->inicio0;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaGeral->inicio0);
            }
        }
        if(cat == 1){
            if(idade >= 65 || idade <= 3){
                print = endListaEsp->inicio1;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaEsp->inicio1);
            }else{
                print = endListaGeral->inicio1;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaGeral->inicio1);
            }
        }
        if(cat == 2){
            if(idade >= 65 || idade <= 3){
                print = endListaEsp->inicio2;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaEsp->inicio2);
            }else{
                print = endListaGeral->inicio2;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaGeral->inicio2);
            }
        }
        if(cat == 3){
            if(idade >= 65 || idade <= 3){
                print = endListaEsp->inicio3;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaEsp->inicio3);
            }else{
                print = endListaGeral->inicio3;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaGeral->inicio3);
            }
        }
        if(cat == 4){
            if(idade >= 65 || idade <= 3){
                print = endListaEsp->inicio4;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaEsp->inicio4);
            }else{
                print = endListaGeral->inicio4;
                printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
                removerInicio(&endListaGeral->inicio4);
            }
        }
    }else{
        print = ant->prox;
        printf("Paciente %d (idade %d) removido com sucesso na lista de prioridade %d!\n", print->cod, print->idade, cat);
        removerMeio(&ant);
    }
}


void chamarPaciente(int cat, Lista *endListaEsp, Lista *endListaGeral){
    No *print;
    if(cat == 0){
        if(endListaEsp->inicio0 != NULL){
            print = endListaEsp->inicio0;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaEsp->inicio0);
        }else{
            print = endListaGeral->inicio0;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaGeral->inicio0);
        }
    }
    if(cat == 1){
        if(endListaEsp->inicio1 != NULL){
            print = endListaEsp->inicio1;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaEsp->inicio1);
        }else{
            print = endListaGeral->inicio1;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaGeral->inicio1);
        }
    }
    if(cat == 2){
        if(endListaEsp->inicio2 != NULL){
            print = endListaEsp->inicio2;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaEsp->inicio2);
        }else{
            print = endListaGeral->inicio2;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaGeral->inicio2);
        }
    }
    if(cat == 3){
        if(endListaEsp->inicio3 != NULL){
            print = endListaEsp->inicio3;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaEsp->inicio3);
        }else{
            print = endListaGeral->inicio3;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaGeral->inicio3);
        }
    }
    if(cat == 4){
        if(endListaEsp->inicio4 != NULL){
            print = endListaEsp->inicio4;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaEsp->inicio4);
        }else{
            print = endListaGeral->inicio4;
            printf("Paciente %d (idade %d) da categoria de prioridade %d chamado para atendimento!\n", print->cod, print->idade, cat);
            removerInicio(&endListaGeral->inicio4);
        }
    }
}


void mudarPaciente(int cod, int cat, Lista *endListaEsp, Lista *endListaGeral){
    No *ant;
    No *x = NULL;
    int catInicial, idade;
    x = buscaRemover(cod, &ant, endListaEsp, &catInicial);
    if(x == NULL)
        x = buscaRemover(cod, &ant, endListaGeral, &catInicial);
    idade = x->idade;
    if(ant == NULL){
        if(catInicial == 0){
            if(idade >= 65 || idade <= 3){
                removerInicio(&endListaEsp->inicio0);
                addLista(endListaEsp, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }else{
                removerInicio(&endListaGeral->inicio0);
                addLista(endListaGeral, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }
        }
        if(catInicial == 1){
            if(idade >= 65 || idade <= 3){
                removerInicio(&endListaEsp->inicio1);
                addLista(endListaEsp, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }else{
                removerInicio(&endListaGeral->inicio1);
                addLista(endListaGeral, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }
        }
        if(catInicial == 2){
            if(idade >= 65 || idade <= 3){
                removerInicio(&endListaEsp->inicio2);
                addLista(endListaEsp, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }else{
                removerInicio(&endListaGeral->inicio2);
                addLista(endListaGeral, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }
        }
        if(catInicial == 3){
            if(idade >= 65 || idade <= 3){
                removerInicio(&endListaEsp->inicio3);
                addLista(endListaEsp, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }else{
                removerInicio(&endListaGeral->inicio3);
                addLista(endListaGeral, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }
        }
        if(catInicial == 4){
            if(idade >= 65 || idade <= 3){
                removerInicio(&endListaEsp->inicio4);
                addLista(endListaEsp, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }else{
                removerInicio(&endListaGeral->inicio4);
                addLista(endListaGeral, cod, idade, cat);
                printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
            }
        }
    }else{
        if(idade >= 65 || idade <= 3){
            removerMeio(&ant);
            addLista(endListaEsp, cod, idade, cat);
            printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
        }else{
            removerMeio(&ant);
            addLista(endListaGeral, cod, idade, cat);
            printf("Paciente %d (idade %d) mudou para a categoria de prioridade %d!\n", cod, idade, cat);
        }
    }
}


int main(){
    int a, cod, cat, idade, t;
    Lista geral, esp;
    iniciarLista(&geral);
    iniciarLista(&esp);
    while(scanf("%d", &a) == 1){
        if(a == 1){
            scanf("%d %d %d", &cod, &cat, &idade);
            if(idade >= 65 || idade <= 3){
                addLista(&esp, cod, idade, cat);
            }else{
                addLista(&geral, cod, idade, cat);
            }
            printf("Paciente %d (idade %d) adicionado com sucesso na lista de prioridade %d!\n", cod, idade, cat);
        }
        if(a == 2){
            scanf("%d", &cod);
            removerLista(cod, &esp, &geral);
        }
        if(a == 3){
            scanf("%d", &cat);
            chamarPaciente(cat, &esp, &geral);
        }
        if(a == 4){
            scanf("%d %d", &cod, &cat);
            mudarPaciente(cod, cat, &esp, &geral);
        }
        if(a == 5){
            scanf("%d", &cat);
            imprimirCategoria(cat, &esp, &geral);
        }
        
        if(a == 6){
            scanf("%d", &t);
            imprimirLista(&esp, &geral, t);
        }
    }
}