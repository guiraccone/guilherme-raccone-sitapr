#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
//----------------------------------------------------------

void procurarCliente(Cliente *clientes, int i_clientes)
{
    int i;
    char cpfProcurado[12];

    printf("\tDigite o CPF do cliente procurado.\n\n");
    scanf("%s", &cpfProcurado);

    for (i = 0; i < i_clientes; i++)
    {
        if (strcmp(cpfProcurado, clientes[i].cpf) == 0)
        {
            printf("\n\nRegistro de cliente encontrado.\n\n");
            printf("\n\t\tNome: %s", clientes[i].nome);
            printf("\n\t\tCPF: %s", clientes[i].cpf);
            printf("\n\t\tSaldo: R$%.2f", clientes[i].saldo);
            return;
        }
        else
        {
            fflush(stdin);
        }
    }
    printf("\nCPF não encontrado.\n");
}
//----------------------------------------------------------
// Função para imprimir os dados de um cliente.
void imprimeCliente(Cliente cliente)
{
    printf("\n===========================================================\n"
           "\tInformações de Cliente: \n"
           "\n\t\tCPF: %s\n"
           "\n\t\tNome: %s\n"
           "\n\t\tSaldo: R$%.2f\n",
           cliente.cpf,
           cliente.nome,
           cliente.saldo);
}

//----------------------------------------------------------
// Função para cadastrar os dados de um cliente.
Cliente cadastraCliente()
{
    Cliente cadastro;

    system("cls");

    printf("\n-----------------------------\n"
           "Cadastro de cliente\n");

    printf("\nInforme o CPF do cliente: ");
    gets(cadastro.cpf);
    fflush(stdin);

    printf("\nInforme o nome do cliente: ");
    gets(cadastro.nome);
    fflush(stdin);

    printf("\nInforme o saldo do cliente (R$): ");
    scanf("%f", &cadastro.saldo);
    fflush(stdin);

    return cadastro;
}

//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarClienteTXT(Cliente *clientes, int i_clientes)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_CLIENTES, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_clientes; n++)
    {
        fprintf(fp, "%s|%s|%f\n",
                clientes[n].cpf,
                clientes[n].nome,
                clientes[n].saldo);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarClientesTXT(Cliente *clientes)
{
    FILE *fp;
    char buffer[1024];
    int i_clientes = 0;

    if ((fp = fopen(ARQUIVO_CLIENTES, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(clientes + i_clientes)).cpf, strtok(buffer, "|"));
        strcpy((*(clientes + i_clientes)).nome, strtok(NULL, "|"));
        (*(clientes + i_clientes)).saldo = atof(strtok(NULL, "|"));

        i_clientes++;
    }

    fclose(fp);

    return (i_clientes);
}