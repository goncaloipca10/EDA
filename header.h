#include <stdio.h>

// Definição da estrutura de dados para clientes
typedef struct cliente {
    int nif;
    float saldo;
    char nome[50];
    char morada[100];
    struct cliente* seguinte;
} Cliente;

// Definição da estrutura de dados para gestores
typedef struct gestor {
    char nome[50];
    char email[100];
    struct gestor* seguinte;
} Gestor;


// Definição da estrutura de dados para meios de Mobilidade Eletrica
typedef struct meios {
    char codigo[50];
    char tipo[20];
    float bateria;
    float autonomia;
    float custo;
    struct meios* seguinte;
} Meios;


// Funções para manipulação dos dados de clientes
Cliente* inserirCliente(Cliente* inicio, int nif, float saldo, char nome[], char morada[]);
void listarClientes(Cliente* inicio);
Cliente* removerCliente(Cliente* inicio, int nif);
void alterarCliente(Cliente* clientes, int nif);
Cliente* existeCliente(Cliente* inicio, int nif);

// Funções para manipulação dos dados de gestores
Gestor* inserirGestor(Gestor* inicio, char nome[], char email[]);
void listarGestores(Gestor* inicio);
Gestor* removerGestor(Gestor* inicio, char email[]);
void alterarGestor(Gestor* gestores, char email[]);
Gestor* existeGestor(Gestor* inicio, char email[]);

// Funções para manipulação dos dados dos meios de mobilidade
Meios* inserirMeio(Meios* inicio, char codigo[], char tipo[], float bateria, float autonomia, float custo);
void listarMeios(Meios* inicio);
Meios* removerMeio(Meios* inicio, char codigo[]);
void alterarMeio(Meios* meios, char codigo[]);
Meios* existeMeio(Meios* inicio, char codigo[]);


int guardarMeios(Meios* inicio);
Meios* lerMeios();