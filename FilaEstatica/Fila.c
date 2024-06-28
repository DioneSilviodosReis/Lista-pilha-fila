#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

#define MAX 100

struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

int main() {
    Fila *fi;
    struct aluno al, al_consulta;

    // Create queue
    fi = cria_Fila();
    if (fi == NULL) {
        printf("Erro ao criar a fila!\n");
        return 1;
    }

    // Insert an element into the queue
    al.matricula = 123;
    snprintf(al.nome, sizeof(al.nome), "Joao");
    al.n1 = 7.5;
    al.n2 = 8.3;
    al.n3 = 9.0;

    if (insere_Fila(fi, al)) {
        printf("Aluno inserido com sucesso!\n");
    } else {
        printf("Erro ao inserir aluno!\n");
    }

    // Check queue size
    printf("Tamanho da fila: %d\n", tamanho_Fila(fi));

    // Consult the front element of the queue
    if (consulta_Fila(fi, &al_consulta)) {
        printf("Consulta na fila: %d %s %.2f %.2f %.2f\n", al_consulta.matricula, al_consulta.nome, al_consulta.n1, al_consulta.n2, al_consulta.n3);
    } else {
        printf("Erro ao consultar a fila!\n");
    }

    // Remove an element from the queue
    if (remove_Fila(fi)) {
        printf("Elemento removido com sucesso!\n");
    } else {
        printf("Erro ao remover elemento!\n");
    }

    // Check if the queue is empty
    if (Fila_vazia(fi)) {
        printf("A fila está vazia!\n");
    } else {
        printf("A fila não está vazia!\n");
    }

    // Free the queue
    libera_Fila(fi);
    
    return 0;
}
