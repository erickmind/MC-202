//Erick Kussumoto do Nascimento RA:196492

#include <stdio.h>
#include <stdlib.h>

struct Produto{
    int ID;
    int quantidade;
};

typedef struct Produto Item;

void inserirProduto (Item **Matriz, int Setor, int id, int qnt, int m){
    int i;
    for(i = 0; i < m; i++){
        if(Matriz[Setor][i].ID == -1 && Matriz[Setor][i].quantidade == -1){
            Matriz[Setor][i].ID = id;
            Matriz[Setor][i].quantidade = qnt;
            break;
        }
    }
} // A funcao insere na matriz de struct a quantidade e o id do produto

void imprimeVetor (Item **Matriz, int m, int Setor){
    int i;
    double prod, media;
    prod = 0;
    for(i = 0; i < m; i++){
        if(Matriz[Setor][i].quantidade != -1){
            prod = prod + Matriz[Setor][i].quantidade;
        }else{
            break;
        }
    }
    media = prod / i;
    
    printf("%d %.f %.2f\n", Setor, prod, media);
} // A funcao soma as quantidades de produtos em cada setor, faz a media e printa 

void Verifica(int n, int m, Item **Matriz){
    int i, j, k, l;
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            for(k = 0; k < m; k++){
               for(l = 0; l < m; l++){ 
                    if(Matriz[i][k].ID == Matriz[j][l].ID){
                        if(Matriz[i][k].ID != -1){
                            printf("SIM");
                            return;
                        }
                    }
               }
            }
        }
    }
    printf("NAO");
    return;
} // a funcao verifica se ja existe um mesmo elemento em dois setores diferentes a partir de 4 lacos


int main (){
    int i, j, n, m, S, id, qnt;
    Item **Matriz;
    scanf("%d %d", &n, &m);
    Matriz = malloc(n*sizeof(Item)); // Primeiro aloca-se um vetor de ponteiros
    for(i = 0; i < n; i++){
        Matriz[i] = malloc(m*sizeof(Item)); // Depois o vetor de ponteiros aponta para um vetor de struct
    }
    
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            Matriz[i][j].ID = -1;
            Matriz[i][j].quantidade = -1;
        }
    } //Esse laco insere um numero negativo em todas as posicoes da matriz de forma a saber se ja tem ou nao um produto na posicao  
    
    while(scanf("%d %d %d", &S, &id, &qnt) == 3){
        inserirProduto(Matriz, S, id, qnt, m);
    } // O laco ira inserir os produtos nos respectivos setores
    
    for(i = 0; i < n; i++){
        imprimeVetor(Matriz, m, i);
    }
    
    Verifica(n, m, Matriz);
    
    for(i = 0; i < n; i++){
        free(Matriz[i]);
    }
    free(Matriz);
    
}