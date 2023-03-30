#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Variável global para controlar o número de clientes inseridos
int num_clientes = 0;
//Registar Cliente
Cliente* inserirCliente(Cliente * inicio, int nif, float saldo, char nome[], char morada[]) {
    if (!existeCliente(inicio, nif)) {
        Cliente* novoCliente = (Cliente*) malloc(sizeof(struct cliente));
        if (novoCliente != NULL) {
            novoCliente->nif = nif;
            novoCliente->saldo = saldo;
            strcpy(novoCliente->nome, nome);
            strcpy(novoCliente->morada, morada);
            novoCliente->seguinte = inicio;
            inicio = novoCliente;
            system("clear");
            printf("Cliente inserido com sucesso!\n");
            return novoCliente;
        }
    } else {
        system("clear");
        printf("O cliente ja se encontra registado.\n");
    }
    return inicio;
}
//Listar todos os clientes na lista
void listarClientes(Cliente* inicio) {
    printf("NIF | Saldo | Nome | Morada\n");
    while (inicio != NULL) {
        printf("%d %.2f %s %s\n", inicio->nif, inicio->saldo, inicio->nome, inicio->morada);
        inicio = inicio->seguinte;
    }
}
//Remover cliente pelo nif
Cliente* removerCliente(Cliente* inicio, int nif)
{
    Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->nif == nif) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->nif!=nif)) 
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
//Alterar os dados do clientes atraves do nif
void alterarCliente(Cliente* clientes, int nif) {
    Cliente* cliente = existeCliente(clientes, nif);
    if (cliente == NULL) {
        system("clear");
        printf("Cliente nao encontrado.\n");
        return;
    }
    float novoSaldo;
    char novaMorada[100];

    printf("Novo saldo: ");
    scanf("%f", &novoSaldo);
    getchar();

    printf("Nova morada: ");
    scanf("%s", novaMorada);
    getchar();

    cliente->saldo = novoSaldo;
    strcpy(cliente->morada, novaMorada);

    system("clear");
    printf("Cliente alterado com sucesso.\n");
}

//Verificar se existe algum registo na lista 
Cliente* existeCliente(Cliente* inicio, int nif){
    while(inicio != NULL){
        if (inicio->nif == nif) return inicio;
            inicio = inicio->seguinte;
        }
 return NULL;
}
