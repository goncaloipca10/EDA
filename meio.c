#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Variável global para controlar o número de clientes inseridos
int num_meios = 0;

Meios* inserirMeio(Meios* inicio, int codigo, char tipo[], float bateria, float autonomia, float custo) {
    if (!existeMeio(inicio, codigo)) {
        Meios* novoMeio = (Meios*) malloc(sizeof(struct meios));
        if (novoMeio != NULL) {
            novoMeio->codigo = codigo;
            strcpy(novoMeio->tipo, tipo);
            novoMeio->bateria = bateria;
            novoMeio->autonomia = autonomia;
            novoMeio->custo = custo;
            novoMeio->seguinte = inicio;
            inicio = novoMeio;
            system("cls");
            printf("Meio inserido com sucesso!\n");
            return novoMeio;
        }
    } else {
        system("cls");
        printf("O Meio ja se encontra registado.\n");
    }
    return inicio;
}


void listarMeios(Meios* inicio) {
    printf("Tipo | Bateria | Autonomia | Custo\n");
    while (inicio != NULL) {
        printf("%s %.2f %.2f %.2f\n", inicio->tipo, inicio->bateria, inicio->autonomia, inicio->custo);
        inicio = inicio->seguinte;
    }
}

Meios* removerMeio(Meios* inicio, int codigo)
{
    Meios *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codigo == codigo) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codigo!=codigo)) 
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

void alterarMeio(Meios* meios, int codigo) {
    Meios* meio = existeMeio(meios, codigo);
    if (meio == NULL) {
        system("cls");
        printf("Meios nao encontrado.\n");
        return;
    }
    
    char novoTipo[100];
    float novaBateria;
    float novaAutonomia;
    float novoCusto;

    printf("Novo Tipo: ");
    scanf("%s", &novoTipo[0]);
    getchar();

    printf("Nova Bateria: ");
    scanf("%f", &novaBateria);
    getchar();

    printf("Nova Autonomia: ");
    scanf("%f", &novaAutonomia);
    getchar();

    printf("Novo Custo: ");
    scanf("%f", &novoCusto);
    getchar();

    strcpy(meios->tipo, novoTipo);
    meios->bateria = novaBateria;
    meios->autonomia = novaAutonomia;
    meios->custo = novoCusto;

    system("cls");
    printf("Meio alterado com sucesso.\n");
}

Meios* existeMeio(Meios* inicio, int codigo){
    while(inicio != NULL){
        if (inicio->codigo == codigo) return inicio;
            inicio = inicio->seguinte;
        }
 return NULL;
}


int guardarMeios(Meios* inicio)
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)

 {
 Meios* aux= inicio;
 while (aux != NULL)

 {
  fprintf(fp,"%d;%s;%f;%f;%f;\n", aux->codigo, aux->tipo, 
	                            aux->bateria, aux->autonomia, aux->custo);
  aux = aux->seguinte;
 }

 fclose(fp);
 return(1);
 }
 else return(0);
}

Meios* lerMeios()
{FILE* fp;
  int codigo;
  float bateria, autonomia, custo;
  char tipo[50];
  Meios* aux=NULL;
  fp = fopen("meios.txt","r");
  if (fp!=NULL)
  {while (!feof(fp))
    { fscanf(fp,"%d;%s;%f;%f;%f\n", &codigo, tipo, &bateria, &autonomia, &custo);
      aux = inserirMeio(aux, codigo, tipo, bateria, autonomia, custo);
    }
    fclose(fp);
  }
  return(aux);
}