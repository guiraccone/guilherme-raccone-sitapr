#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

void imprimeEstoque(Estoque estoque)
{
    printf("\n===========================================================\n"
           "\tInformações de Estoque: \n"
           "\n\t\tCNPJ: %s\n"
           "\n\t\tCódigo: %d\n"
           "\n\t\tQuantidade: %d\n",
           estoque.cnpj,
           estoque.codigoProduto,
           estoque.quantidade);
}

Estoque cadastraEstoque()
{
    Estoque cadastro;

    printf("\n-----------------------------\n"
           "Cadastro do estoque\n");

    printf("Informe o CNPJ:\n");
    gets(cadastro.cnpj);

    printf("Informe o código do produto:\n");
    scanf("%d", &cadastro.codigoProduto);
    fflush(stdin);

    printf("Informe a quantidade:\n");
    scanf("%d", &cadastro.quantidade);
    fflush(stdin);

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
        (*(estoques + i_estoque)).codigoProduto, atoi(strtok(NULL, "|"));
        (*(estoques + i_estoque)).quantidade, atoi(strtok(NULL, "|"));
        i_estoque++;
    }

    fclose(fp);

    return (i_estoque);
}
