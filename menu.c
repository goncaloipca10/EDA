#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int menu() 
{int opcao;
system("cls");
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
{int opcao;
printf("MENU CLIENTE\n");
printf("Selecione uma opcao:\n");
printf("1 - Registar cliente\n");
printf("2 - Listar clientes\n");
printf("3 - Remover clientes\n");
printf("4 - Alterar clientes\n");
printf("9 - Voltar atras\n");
printf("Opcao:\n");
scanf("%d",&opcao);
return(opcao);
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
{int opcao;
printf("MENU MEIOS DE MOBILIDADE\n");
printf("Selecione uma opcao:\n");
printf("1 - Registar meio de mobilidade\n");
printf("2 - Listar meios de mobilidade\n");
printf("3 - Remover meios de mobilidade\n");
printf("4 - Alterar meios de mobilidade\n");
printf("5 - Guardar fichero de meios de mobilidade\n");
printf("6 - Ler ficherio de meios de mobilidade\n");
printf("9 - Voltar atras\n");
printf("Opcao:\n");
scanf("%d",&opcao);
return(opcao);
}


int main() 
{Cliente* clientes = NULL; // Lista ligada vazia
Meios* meios = NULL; // Lista ligada vazia
Gestor* gestor = NULL; // Lista ligada vazia 

//variaveis
int codigo;
char tipo[50];
float bateria;
float autonomia;
float custo;

char nome[50];
char email[50];

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
                    system("cls");
                    printf("Tipo:\n");
                    scanf("%d",&nif);
                    printf("Bateria:\n");
                    scanf("%f",&bateria);
                    getchar();
                    printf("Autonomia: \n");
                    scanf("%f", &autonomia);
                    getchar();
                    printf("Custo: \n");
                    scanf("%f", &custo);
                    getchar();
                        meios = inserirMeio(meios, codigo, tipo, bateria, autonomia, custo);
                break;
                case 2:
                    system("cls");
                    listarMeios(meios);
                    printf("\n");
                break;
                case 3:
                    system("cls");
                    printf("Codigo do meio que quer remover?\n");
                    scanf("%d",&nif);
                    meios = removerMeio(meios, codigo);
                break;
                case 4:
                    system("cls");
                    printf("Codigo do meio a ser alterado: ");
                    scanf("%d", &codigo);
                    getchar();
                    alterarMeio(meios, codigo);
                break;
                case 5:
                    guardarMeios(meios);
                break;
                case 6:
                    meios = lerMeios();
                break;
                case 9:
                    system("cls");
                    menu();
                break;
                default:
                break;
                }

                } while (opcao != 0);
            break;
        case 2:
                do {
                    opcao = menuClientes();
                    switch (opcao) {
                        case 1:
                            system("cls");
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
                            system("cls");
                            listarClientes(clientes);
                            printf("\n");
                            break;
                        case 3:
                            printf("NIF do cliente que quer remover?\n");
                            scanf("%d",&nif);
                            clientes = removerCliente(clientes, nif);
                        case 4:
                            printf("NIF do cliente a ser alterado: ");
                            scanf("%d", &nif);
                            getchar();
                            alterarCliente(clientes, nif);
                            break;
                        case 9:
                            system("cls");
                            menu();
                            break;
                        default:
                            system("cls");
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
                                    system("cls");
                                    printf("Nome:\n");
                                    scanf("%s",&nome[0]);
                                    printf("Email:\n");
                                    scanf("%s",&email[0]);
                                    getchar();
                                        gestor = inserirGestor(gestor, nome, email);
                                    break;
                                case 2:
                                    system("cls");
                                    listarGestores(gestor);
                                    printf("\n");
                                    break;
                                case 3:
                                    printf("Email do gestor que quer remover?\n");
                                    scanf("%s",&email[0]);
                                    gestor = removerGestor(gestor, email);
                                case 4:
                                    printf("Email do gestor a ser alterado: ");
                                    scanf("%s", &email[0]);
                                    getchar();
                                    alterarGestor(gestor, email);
                                    break;
                                case 9:
                                    system("cls");
                                    menu();
                                    break;
                                default:
                                    system("cls");
                                    printf("Opção inválida.\n");
                                    break;
                                    }
                } while (opcao != 0);
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar!\n");
            break;
        default:
            system("cls");
            printf("Opção inválida.\n");
            break;
    }
} while (opcao != 0);

return 0;
}