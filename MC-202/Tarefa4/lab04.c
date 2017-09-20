#include <stdio.h>
#include <stdlib.h>


typedef struct No{
    int id;
    int tem_exec;
    int prio;
    struct No *prox;

}No; 


typedef struct Fila{
    No *inicio;
    No *fim;
    
}Fila;


No* iniciarFila(Fila *fila){
    No *cab = malloc(sizeof(No));
    fila->inicio = cab;
    cab->prox = cab;
    return cab;
}

No* buscaLista_circ(Fila *fila, int id, No** ant){
    No *atual = fila->inicio->prox;
    fila->inicio->id = id;
    (*ant) = atual; 
    while(atual->id != id && atual != fila->inicio){
        (*ant) = atual;
        atual = atual->prox;
    }
    if(atual != fila->inicio && atual->id == id){
        return atual;
    }
    return NULL;
}

void inserirProcesso(Fila *fila, int id, int tem_exec, int prio){
    No *ant; 
    No *novo;
    novo = buscaLista_circ(fila, id, &ant);
    if(novo != NULL)
        return;
    novo = malloc(sizeof(No));
    novo->id = id;
    novo->tem_exec = tem_exec;
    novo->prio = prio;
    novo->prox = ant->prox;
    ant->prox = novo;
    return; 
    
}

int numeroProcessos(Fila *fila){
    int qnt = 0;
    No *inicio = fila->inicio;
    No *aux = fila->inicio->prox;
    while(inicio != aux){
        aux = aux->prox;
        qnt++;
    }
    return qnt;
}

void exibirProcessos(Fila *fila, int n){
    No *aux = fila->inicio->prox;
    if(aux == fila->inicio){
        printf("Nenhum processo existe na fila #%d\n", n);
        return;
    }
    
    do{
        printf("Processo %d (tempo de execucao %d) da fila #%d\n", aux->id, aux->tem_exec, n);
        aux = aux->prox;
    }while(aux != fila->inicio);
}


int main(){
    int p, t, op, fila, id, tem_exec, prio, x;
    Fila fila0, fila1, fila2;
    iniciarFila(&fila0);
    iniciarFila(&fila1);
    iniciarFila(&fila2);
    scanf("%d %d", &p, &t);
    while(scanf("%d", &op) == 1){
        if(op == 1){
            scanf("%d %d %d %d", &fila, &id, &tem_exec, &prio);
            if(p == 0 || t == 0){
                printf("Limite de processos excedido\n");
            }
            
            if(fila == 0 && p != 0 && t != 0){
                inserirProcesso(&fila0, id, tem_exec, prio);
                p--;
                t--;
                printf("Processo %d (tempo de execucao %d) adicionado na #fila %d\n", id, tem_exec, fila);
            }
            
            if(fila == 1 && p != 0 && t != 0){
                inserirProcesso(&fila1, id, tem_exec, prio);
                p--;
                t--;
                printf("Processo %d (tempo de execucao %d) adicionado na #fila %d\n", id, tem_exec, fila);
            }
            
            if(fila == 2 && p != 0 && t != 0){
                inserirProcesso(&fila2, id, tem_exec, prio);
                p--;
                t--;
                printf("Processo %d (tempo de execucao %d) adicionado na #fila %d\n", id, tem_exec, fila);
            }
            
        }
        /*
        if(op == 2){
            
            
        }
        
        if(op == 3){
            
        }
        */
        if(op == 4){
            scanf("%d", &fila);
            if(fila == 0){
                exibirProcessos(&fila0, fila);
            }
            if(fila == 1){
                exibirProcessos(&fila1, fila);
            }
            if(fila == 2){
                exibirProcessos(&fila2, fila);
            }
            
        }
        if(op == 5){
            scanf("%d", &fila);
            if(fila == 0){
                x = numeroProcessos(&fila0);
                printf("Quantidade de processos na fila #%d: %d", fila, x);
            }
            if(fila == 1){
                x = numeroProcessos(&fila1);
                printf("Quantidade de processos na fila #%d: %d", fila, x);
            }
            if(fila == 2){
                x = numeroProcessos(&fila2);
                printf("Quantidade de processos na fila #%d: %d", fila, x);
            }
            
        }
        /*
        if(op == 6){
            
            
        }
        */
    }
    
    
    
    
    
}


