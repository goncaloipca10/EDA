#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int menu() 
{int opcao;
system("clear");
printf("Bem-vindo!\n");
printf("Selecione uma opcao:\n");
printf("1 - Meios de mobilidade\n");
printf("2 - Clientes\n");
printf("3 - Gestores\n");
printf("0 - Sair\n");
printf("Opcao:\n");
scanf("%d",&opcao);
return(opcao);
}

int menuClientes() 
{int opcaoClientes;
printf("MENU CLIENTE\n");
printf("Selecione uma opcao:\n");
printf("1 - Registar cliente\n");
printf("2 - Listar clientes\n");
printf("3 - Remover clientes\n");
printf("4 - Alterar clientes\n");
printf("9 - Voltar atras\n");
printf("Opcao:\n");
scanf("%d",&opcaoClientes);
return(opcaoClientes);
}

int menuGestores() 
{int opcao;
printf("MENU GESTOR\n");
printf("Selecione uma opcao:\n");
printf("1 - Registar Gestor\n");
printf("2 - Listar Gestor\n");
printf("3 - Remover Gestor\n");
printf("4 - Alterar Gestor\n");
printf("9 - Voltar atras\n");
printf("Opcao:\n");
scanf("%d",&opcao);
return(opcao);
}

int menuMeios()
{int opcaoMeios;
printf("MENU MEIOS DE MOBILIDADE\n");
printf("Selecione uma opcao:\n");
printf("1 - Registar meio de mobilidade\n");
printf("2 - Listar meios de mobilidade\n");
printf("3 - Remover meios de mobilidade\n");
printf("4 - Alterar meios de mobilidade\n");
printf("5 - Guardar fichero de meios de mobilidade\n");
printf("6 - Ler ficherio de meios de mobilidade\n");
printf("7 - Guardar ficherio de meios de mobilidade em binario\n");
printf("8 - Ler ficherio de meios de mobilidade em binario\n");
printf("9 - Listar meio de mobilidade especifico\n");
printf("10 - Voltar atras\n");
printf("Opcao:\n");
scanf("%d",&opcaoMeios);
return(opcaoMeios);    
}

int main() 
{Cliente* clientes = NULL; // Lista ligada vazia
Gestor* gestor = NULL; // Lista ligada vazia 
Meios* meios = NULL; // Lista ligada vazia

//variaveis
char codigo[50];
char tipo[50];
float bateria;
float autonomia;
float custo;
char nome[50];
char email[50];

char novoTipo[100];
float novaBateria;
float novaAutonomia;
float novoCusto;

int nif;
float saldo;
char morada[100];

int opcao;

do {
    opcao = menu();
    switch (opcao) {
        case 1:
            do {
                opcao = menuMeios();
               
                switch (opcao)
                {
                case 1:
                    system("clear");
                    printf("Codigo:\n");
                    scanf("%s", codigo);
                    getchar();
                    printf("Tipo:\n");
                    scanf("%s", tipo);
                    getchar();
                    printf("Bateria:\n");
                    scanf("%f", &bateria);
                    printf("Autonomia: \n");
                    scanf("%f", &autonomia);
                    printf("Custo: \n");
                    scanf("%f", &custo);
                        meios = inserirMeio(meios, codigo, tipo, bateria, autonomia, custo);
                    break;
                case 2:
                    system("clear");
                    printf("Codigo | Tipo | Bateria | Autonomia | Custo\n");
                    listarMeios(meios);
                    printf("\n");
                    break;
                case 3:
                    system("clear");
                    printf("Codigo do meio que quer remover?\n");
                    scanf("%s", codigo);
                    meios = removerMeio(meios, codigo);
                    break;
                case 4:
                    system("clear");
                    printf("Codigo do meio a ser alterado: ");
                    scanf("%s", codigo);
                    getchar();
                    printf("Novo Tipo: ");
                    scanf("%s", novoTipo);
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
                    printf("Meio alterado com sucesso.\n");

                    alterarMeio(meios, codigo);
                    
                    break;
                case 5:
                    guardarMeios(meios);
                    break;
                case 6:
                    meios = lerMeios();
                    break;
                case 7:
                    guardarMeiosBin(meios);
                    break;
                case 8:
                    meios = lerMeiosBin();
                    break;
                case 9:
                    printf("Codigo do meio a ser listado: ");
                    scanf("%s", codigo);
                    getchar();
                    printf("Codigo | Tipo | Bateria | Autonomia | Custo\n");
                    consultar(meios, codigo);
                    break;
                case 10:
                    system("clear");
                    menu();
                    break;
                default:
                    system("clear");
                    printf("Opção inválida.\n");
                    break;
                }
            } while (opcao != 0);
            break;   

        case 2:
                do {
                opcao = menuClientes();
                    switch (opcao) {
                    case 1:
                        system("clear");
                        printf("NIF:\n");
                        scanf("%d",&nif);
                        printf("Saldo:\n");
                        scanf("%f",&saldo);
                        getchar();
                        printf("Nome: \n");
                        scanf("%s", nome);
                        getchar();
                        printf("Morada: \n");
                        scanf("%s", morada);
                        getchar();
                            clientes = inserirCliente(clientes, nif, saldo, nome, morada);
                        break;
                    case 2:
                        system("clear");
                        listarClientes(clientes);
                        printf("\n");
                        break;
                    case 3:
                        printf("NIF do cliente que quer remover?\n");
                        scanf("%d",&nif);
                        clientes = removerCliente(clientes, nif);
                        break;
                    case 4:
                        printf("NIF do cliente a ser alterado: ");
                        scanf("%d", &nif);
                        getchar();
                        alterarCliente(clientes, nif);
                        break;
                    case 9:
                        system("clear");
                        menu();
                        break;
                    default:
                        system("clear");
                        printf("Opção inválida.\n");
                        break;
                    }
                    
                } while (opcao != 0);
            break;
        case 3:
                do {
                opcao = menuGestores();
                switch (opcao) {
                    case 1:
                        system("clear");
                        printf("Nome:\n");
                        scanf("%s", nome);
                        printf("Email:\n");
                        scanf("%s", email);
                        getchar();
                            gestor = inserirGestor(gestor, nome, email);
                        break;
                    case 2:
                        system("clear");
                        listarGestores(gestor);
                        printf("\n");
                        break;
                    case 3:
                        printf("Email do gestor que quer remover?\n");
                        scanf("%s", email);
                        gestor = removerGestor(gestor, email);
                        break;
                    case 4:
                        printf("Email do gestor a ser alterado: ");
                        scanf("%s", email);
                        getchar();
                        alterarGestor(gestor, email);
                        break;
                    case 9:
                        system("clear");
                        menu();
                        break;
                    default:
                        system("clear");
                        printf("Opção inválida.\n");
                        break;
                        }
                } while (opcao != 0);
            break;
        case 0:
            system("clear");
            printf("Obrigado por utilizar!\n");
            break;
        default:
            system("clear");
            printf("Opção inválida.\n");
        break;
    }
} while (opcao != 0);

return 0;
}