#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Variável global para controlar o número de gestores inseridos
int num_gestores = 0;

Gestor* inserirGestor(Gestor* inicio, char nome[], char email[]) {
    if (!existeGestor(inicio, email)) {
        Gestor* novoGestor = (Gestor*) malloc(sizeof(struct gestor));
        if (novoGestor != NULL) {
            strcpy(novoGestor->nome, nome);
            strcpy(novoGestor->email, email);
            novoGestor->seguinte = inicio;
            inicio = novoGestor;
            system("cls");
            printf("Gestor inserido com sucesso!\n");
            return novoGestor;
        }
    } else {
        system("cls");
        printf("O Gestor ja se encontra registado.\n");
    }
    return inicio;
}


void listarGestores(Gestor* inicio) {
    printf("Nome      |     Email\n");
    while (inicio != NULL) {
        printf("%s %s\n", inicio->nome, inicio->email);
        inicio = inicio->seguinte;
    }
}

Gestor* removerGestor(Gestor* inicio, char email[])
{
    Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->email == email) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->email!=email)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

void alterarGestor(Gestor* gestores, char email[]) {
    Gestor* gestor = existeGestor(gestores, email);
    if (gestor == NULL) {
        system("cls");
        printf("Gestor nao encontrado.\n");
        return;
    }
    char novoNome[50];
    char novoEmail[100];

    printf("Novo Nome: ");
    scanf("%s", &novoNome[0]);
    getchar();

    printf("Nova morada: ");
    scanf("%s", &novoEmail[0]);
    getchar();

    strcpy(gestor->nome, novoNome);
    strcpy(gestor->email, novoEmail);

    system("cls");
    printf("Gestor alterado com sucesso.\n");
}

Gestor* existeGestor(Gestor* inicio, char email[]){
    while(inicio != NULL){
        if (inicio->email == email) return inicio;
            inicio = inicio->seguinte;
        }
 return NULL;
}