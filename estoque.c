#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void imprimeEstoque(Estoque estoque)
{
    printf("___________________________________________________________________________________________\n"
           "\n\t\t\t\tInformações de Estoque\n"
           "___________________________________________________________________________________________\n"
           "\n\tCNPJ\n\n\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tCódigo do Produto\n\n\t%d\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tQuantidade\n\n\t%d\n\n"
           "-------------------------------------------------------------------------------------------\n\n\n",
           estoque.cnpj,
           estoque.codigoProduto,
           estoque.quantidade);
}

Estoque cadastraEstoque()
{
    Estoque cadastro;

    system("cls");

    printf("-------------------------------------------------------------------------------------------\n"
           "\t\t\t\t\tCadastro do Estoque\n"
           "-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o CNPJ:\n\n");
    fflush(stdin);
    gets(cadastro.cnpj);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o código do produto:\n\n");
    fflush(stdin);
    scanf("%d", &cadastro.codigoProduto);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme a quantidade:\n\n");
    fflush(stdin);
    scanf("%d", &cadastro.quantidade);
    printf("-------------------------------------------------------------------------------------------\n");

    return cadastro;
}

void salvarEstoqueTXT(Estoque *estoques, int i_estoque)
{
    FILE *fp;

    if ((fp = fopen(ARQUIVO_ESTOQUE, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoque.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_estoque; n++)
    {
        fprintf(fp, "%s|%d|%d\n",
                estoques[n].cnpj,
                estoques[n].codigoProduto,
                estoques[n].quantidade);
    }
    fclose(fp);
}

int carregarEstoquesTXT(Estoque *estoques)
{
    FILE *fp;
    char buffer[1024];
    int i_estoque = 0;

    if ((fp = fopen(ARQUIVO_ESTOQUE, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoque.txt");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';

        strcpy((*(estoques + i_estoque)).cnpj, strtok(buffer, "|"));
        (*(estoques + i_estoque)).codigoProduto = atoi(strtok(NULL, "|"));
        (*(estoques + i_estoque)).quantidade = atoi(strtok(NULL, "|"));
        i_estoque++;
    }

    fclose(fp);

    return (i_estoque);
}
