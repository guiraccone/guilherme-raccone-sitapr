#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
//----------------------------------------------------------

void procurarCliente(Cliente *clientes, int i_clientes)
{
    int i;
    char cpfProcurado[12];

    printf("___________________________________________________________________________________________\n"
           "\n\tDigite o CPF do cliente procurado.\n"
           "___________________________________________________________________________________________\n\n");
    scanf("%s", &cpfProcurado);

    for (i = 0; i < i_clientes; i++)
    {
        if (strcmp(cpfProcurado, clientes[i].cpf) == 0)
        {
            printf("\n\n\t\tRegistro de cliente encontrado.\n\n\n\n");

            printf("___________________________________________________________________________________________\n"
                   "\n\t\t\tInformações de Cliente: \n"
                   "___________________________________________________________________________________________\n"
                   "\n\t\tCPF: %s\n"
                   "-------------------------------------------------------------------------------------------\n"
                   "\n\t\tNome: %s\n"
                   "-------------------------------------------------------------------------------------------\n"
                   "\n\t\tSaldo: R$%.2f\n"
                   "-------------------------------------------------------------------------------------------\n\n\n",
                   clientes[i].cpf,
                   clientes[i].nome,
                   clientes[i].saldo);
            return;
        }
        else
        {
            fflush(stdin);
        }
    }
    printf("___________________________________________________________________________________________\n"
           "\n\tCPF inválido ou não encontrado.\n"
           "___________________________________________________________________________________________\n");
}
//----------------------------------------------------------
// Função para imprimir os dados de um cliente.
void imprimeCliente(Cliente cliente)
{
    printf("\n\n___________________________________________________________________________________________\n"
           "\n\t\t\t\tInformações do Cliente"
           "\n___________________________________________________________________________________________\n"
           "\n\t\tCPF\n\n\t\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\t\tNome\n\n\t\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\t\tSaldo\n\n\t\tR$%.2f\n\n"
           "-------------------------------------------------------------------------------------------\n\n\n",
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

    printf("-------------------------------------------------------------------------------------------\n"
           "\t\t\t\tCadastro de cliente\n"
           "-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o CPF do cliente:\n\n");
    fflush(stdin);
    gets(cadastro.cpf);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o nome do cliente:\n\n");
    fflush(stdin);
    gets(cadastro.nome);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o saldo do cliente (R$):\n\n");
    fflush(stdin);
    scanf("%f", &cadastro.saldo);
    printf("-------------------------------------------------------------------------------------------\n");

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