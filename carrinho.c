#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrinho.h"

void imprimeCarrinho(CarrinhoCompras carrinho)
{
    printf("\n===========================================================\n"
           "\tInformações de Carrinho: \n"
           "\n\t\tCPF: %s\n"
           "\n\t\tCódigo de Produto: %d\n",
           carrinho.cpf,
           carrinho.codigoProduto);
}

CarrinhoCompras cadastraCarrinho()
{
    CarrinhoCompras cadastro;

    printf("\n-----------------------------\n"
           "Cadastro de carrinho\n");

    printf("\nInforme o CPF: ");
    gets(cadastro.cpf);

    printf("\nInforme o código de produto: ");
    scanf("%d", &cadastro.codigoProduto);
    fflush(stdin);

    return (cadastro);
}

void salvarCarrinhoTXT(CarrinhoCompras *carrinhos, int i_carrinhos)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_CARRINHOS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo carrinhos.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_carrinhos; n++)
    {
        fprintf(fp, "%s|%d\n",
                carrinhos[n].cpf,
                carrinhos[n].codigoProduto);
    }

    fclose(fp);
}

int carregarCarrinhosTXT(CarrinhoCompras *carrinhos)
{
    FILE *fp;
    char buffer[1024];
    int i_carrinhos = 0;

    if ((fp = fopen(ARQUIVO_CARRINHOS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo carrinhos.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';

        strcpy((*(carrinhos + i_carrinhos)).cpf, strtok(buffer, "|"));
        (*(carrinhos + i_carrinhos)).codigoProduto = atof(strtok(NULL, "|"));

        i_carrinhos++;
    }

    fclose(fp);

    return (i_carrinhos);
}