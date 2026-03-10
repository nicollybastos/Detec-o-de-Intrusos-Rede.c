// Sistema de Detecção de Intrusão em Rede (Cyber Security IDS)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_TABELA 10

// Estrutura para Hash Chaining

typedef struct Nodo {
    char valor[50];
    struct Nodo* proximo;
} Nodo;

Nodo* tabela_chaining[TAMANHO_TABELA];

// Função Hash

int funcao_hash(const char* chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++){
        soma += chave[i];
    }
    return soma % TAMANHO_TABELA;
}

// Inserção Chaining (eventos)

void inserir_chaining(const char* valor) {
    int indice = funcao_hash(valor);

    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    strcpy(novo->valor, valor);

    novo->proximo = tabela_chaining[indice];
    tabela_chaining[indice] = novo;
}

// Busca Chaining

Nodo* buscar_chaining(const char* valor) {

    int indice = funcao_hash(valor);
    Nodo* atual = tabela_chaining[indice];

    while (atual != NULL){

        if (strcmp(atual->valor, valor) == 0){
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

// Remoção Chaining

void remover_chaining(const char* valor) {

    int indice = funcao_hash(valor);

    Nodo* atual = tabela_chaining[indice];
    Nodo* anterior = NULL;

    while (atual != NULL){

        if (strcmp(atual->valor, valor) == 0){

            if (anterior == NULL){
                tabela_chaining[indice] = atual->proximo;
            }
            else{
                anterior->proximo = atual->proximo;
            }

            free(atual);

            printf("Evento '%s' removido do log.\n", valor);
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Evento '%s' nao encontrado.\n", valor);
}

// Mostrar tabela chaining

void mostrar_chaining () {

    printf("\n=== LOG DE EVENTOS DE SEGURANCA (CHAINING) ===\n");

    for(int i = 0; i < TAMANHO_TABELA; i++){

        printf("[%d]: ", i);

        Nodo* atual = tabela_chaining[i];

        while (atual != NULL){

            printf("%s -> ", atual->valor);
            atual = atual->proximo;

        }

        printf("NULL\n");
    }
}

// Tabela Hash Linear (Ataques)

typedef struct {
    char valor[50];
    int ocupado;
} Entrada;

Entrada tabela_linear[TAMANHO_TABELA];

// Inserção Linear

void inserir_linear(const char* valor){

    int indice = funcao_hash(valor);

    for (int i = 0; i < TAMANHO_TABELA; i++){

        int pos = (indice + i) % TAMANHO_TABELA;

        if (tabela_linear[pos].ocupado == 0 || tabela_linear[pos].ocupado == -1){

            strcpy(tabela_linear[pos].valor, valor);

            tabela_linear[pos].ocupado = 1;

            return;
        }
    }

    printf("Tabela cheia. Nao foi possivel inserir '%s'.\n", valor);
}

// Busca Linear

int buscar_linear(const char* valor){

    int indice = funcao_hash(valor);

    for (int i = 0; i < TAMANHO_TABELA; i++){

        int pos = (indice + i) % TAMANHO_TABELA;

        if (tabela_linear[pos].ocupado == 0){
            return -1;
        }

        if (tabela_linear[pos].ocupado == 1 &&
            strcmp(tabela_linear[pos].valor, valor) == 0){

            return pos;
        }
    }

    return -1;
}

// Remoção Linear

void remover_linear(const char* valor){

    int pos = buscar_linear(valor);

    if(pos == -1){

        printf("Ataque '%s' nao encontrado.\n", valor);
        return;
    }

    tabela_linear[pos].ocupado = -1;

    printf("Ataque '%s' removido.\n", valor);
}

// Mostrar tabela linear

void mostrar_linear(){

    printf("\n=== TIPOS DE ATAQUE DETECTADOS (LINEAR PROBING) ===\n");

    for (int i = 0; i < TAMANHO_TABELA; i++){

        printf("[%d]: ", i);

        if (tabela_linear[i].ocupado == 1){

            printf("%s\n", tabela_linear[i].valor);

        }

        else if (tabela_linear[i].ocupado == -1){

            printf("<removido>\n");

        }

        else{

            printf("<livre>\n");

        }
    }
}

// Menu do Sistema IDS

void menu(){

    printf("\n==============================\n");
    printf(" SISTEMA DE DETECCAO DE INTRUSAO\n");
    printf("==============================\n");

    printf("1 - Mostrar logs de eventos\n");
    printf("2 - Mostrar tipos de ataque\n");
    printf("3 - Buscar evento\n");
    printf("4 - Remover evento\n");
    printf("5 - Sair\n");
}

// MAIN

int main () {

    for (int i = 0; i < TAMANHO_TABELA; i++) {

        tabela_chaining[i] = NULL;
        tabela_linear[i].ocupado = 0;
    }

    // Eventos de segurança simulados

    const char* eventos[] = {

        "login suspeito",
        "port scan detectado",
        "sql injection",
        "trafego anormal",
        "falha autenticacao",
        "excesso requisicoes",
        "acesso nao autorizado"
    };

    int n = sizeof(eventos) / sizeof(eventos[0]);

    // Tipos de ataque

    const char* ataques[] = {

        "brute force",
        "ddos",
        "sql injection",
        "reconhecimento",
        "phishing"
    };

    int m = sizeof(ataques) / sizeof(ataques[0]);

    for (int i = 0; i < n; i++){
        inserir_chaining(eventos[i]);
    }

    for (int i = 0; i < m; i++){
        inserir_linear(ataques[i]);
    }

    int opcao;
    char busca[50];

    do {

        menu();

        printf("\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1){

            mostrar_chaining();
        }

        if (opcao == 2){

            mostrar_linear();
        }

        if (opcao == 3){

            printf("Digite o evento: ");
            fgets(busca, 50, stdin);
            busca[strcspn(busca,"\n")] = 0;

            if (buscar_chaining(busca)){

                printf("Evento encontrado no log.\n");
            }
            else{

                printf("Evento nao encontrado.\n");
            }
        }

        if (opcao == 4){

            printf("Digite evento para remover: ");
            fgets(busca,50,stdin);
            busca[strcspn(busca,"\n")] = 0;

            remover_chaining(busca);
        }

    } while (opcao != 5);

    printf("\nEncerrando sistema IDS...\n");

    return 0;
}
