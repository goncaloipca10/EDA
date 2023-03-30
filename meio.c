#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Variável global para controlar o número de clientes inseridos
int num_meios = 0;

//Registar Meios na Lista
Meios* inserirMeio(Meios* inicio, char codigo[], char tipo[], float bateria, float autonomia, float custo) {
    if (!existeMeio(inicio, codigo)) {
        Meios* novoMeio = (Meios*) malloc(sizeof(struct meios));
        if (novoMeio != NULL) {
            strcpy(novoMeio->codigo, codigo);
            strcpy(novoMeio->tipo, tipo);
            novoMeio->bateria = bateria;
            novoMeio->autonomia = autonomia;
            novoMeio->custo = custo;
            novoMeio->seguinte = inicio;
            inicio = novoMeio;
            system("clear");
            printf("Meio inserido com sucesso!\n");
            return novoMeio; // retorna a lista atualizada
        }
    } else {
        system("clear");
        printf("O Meio ja se encontra registado.\n");
    }
    return inicio;
}

//Listar todos os meios da Lista
void listarMeios(Meios* inicio) {
    while (inicio != NULL) {
        printf("%s %s %.2f %.2f %.2f\n", inicio->codigo, inicio->tipo, inicio->bateria, inicio->autonomia, inicio->custo);
        inicio = inicio->seguinte;
    }
}

//Remover Meios atraves do seu codigo
Meios* removerMeio(Meios* inicio, char codigo[])
{
    Meios *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (strcmp(atual->codigo, codigo) == 0) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(strcmp(atual->codigo, codigo) != 0)) 
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

//Alterar Meios
void alterarMeio(Meios* meios, char codigo[]) {
    Meios* meio = existeMeio(meios, codigo);
    if (meio == NULL) {
        system("clear");
        printf("Meios nao encontrado.\n");
        return;
    }
}


// Vericar se existe algum meio registado
Meios* existeMeio(Meios* inicio, char codigo[]){
    while(inicio != NULL){
        if (strcmp(inicio->codigo, codigo) == 0) return inicio;
            inicio = inicio->seguinte;
        }
 return NULL;
}


int guardarMeios(Meios* inicio) //Guardar Meios em ficheiro txt
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)

 {
 Meios* aux= inicio;
 while (aux != NULL)

 {
  fprintf(fp,"%s;%s;%f;%f;%f;\n", aux->codigo, aux->tipo, 
	                            aux->bateria, aux->autonomia, aux->custo);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

Meios* lerMeios() //Ler Meios em ficheiro txt
{FILE* fp;
  char codigo[50];
  float bateria, autonomia, custo;
  char tipo[50];
  Meios* aux=NULL;
  fp = fopen("meios.txt","r");
  if (fp!=NULL)
  {while (!feof(fp))
    { fscanf(fp,"%s;%s;%f;%f;%f\n", codigo, tipo, &bateria, &autonomia, &custo);
      aux = inserirMeio(aux, codigo, tipo, bateria, autonomia, custo);
    }
    fclose(fp);
  }
  return(aux);
}


int guardarMeiosBin(Meios* inicio) //Guardar Meios em binario
{FILE* fp;
 fp = fopen("meios.bin","wb");  // "w" write
 if (fp!=NULL)
 {
 Meios* aux= inicio; // aux referencia o início da lista ligada
 while (aux != NULL)
 {
  fwrite(aux->codigo, sizeof(char), 50, fp);
  fwrite(aux->tipo, sizeof(char), 50, fp);
  fwrite(&aux->bateria, sizeof(float), 1, fp);
  fwrite(&aux->autonomia, sizeof(float), 1, fp);
  fwrite(&aux->custo, sizeof(float), 1, fp);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}


Meios* lerMeiosBin() //Ler ficheiro em binario
{FILE* fp;
    char codigo[50];
    float bateria, autonomia, custo;
    char tipo[50];

 Meios* aux=NULL;
 fp = fopen("meios.bin","rb"); // "r"  read
 if (fp!=NULL)
 {while (!feof(fp))
  { fread(codigo, sizeof(char), 50, fp);
    fread(tipo, sizeof(char), 50, fp);
    fread(&bateria, sizeof(float), 1, fp);
    fread(&autonomia, sizeof(float), 1, fp);
    fread(&custo, sizeof(float), 1, fp);
    aux = inserirMeio(aux, codigo, tipo, bateria, autonomia, custo);
  }
  fclose(fp);
 }
 return(aux);
}

Meios* consultar(Meios* inicio, char codigo[]) // consultar registo a partir do código
{
 while(inicio!=NULL)
 {if (inicio->codigo==codigo) return(inicio);
  inicio=inicio->seguinte;
 }
 return(NULL);
}