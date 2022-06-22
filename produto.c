#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

//----------------------------------------------------------
//
void ordenarProduto(Produto p[], int n)
{
    int i, j;
    int temp, temp2;
    char temp1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].valor > p[j].valor)
            {
                temp2 = p[i].valor;
                p[i].valor = p[j].valor;
                p[j].valor = temp2;

                temp = p[i].codigoProduto;
                p[i].codigoProduto = p[j].codigoProduto;
                p[j].codigoProduto = temp;

                temp1 = *p[i].descricao;
                *p[i].descricao = *p[j].descricao;
                *p[j].descricao = temp1;
            }
        }
    }
}

void imprimeProduto(Produto produto)
{

    printf("\n===========================================================\n"
           "\tInformações de Produto: \n"
           "\n\t\tCódigo: %d\n"
           "\n\t\tDescrição: %s\n"
           "\n\t\tValor: R$%.2f\n",
           produto.codigoProduto,
           produto.descricao,
           produto.valor);
}

//----------------------------------------------------------
//
Produto cadastraProduto()
{
    Produto cadastro;

    system("cls");

    printf("\n-----------------------------\n"
           "Cadastro do produto\n");

    printf("\nInforme o código do produto:\n\n");
    scanf("%d", &cadastro.codigoProduto);
    fflush(stdin);

    printf("\n\n\nInforme a descrição do produto:\n\n");
    gets(cadastro.descricao);

    printf("\n\n\nInforme o valor do produto (R$):\n\n");
    scanf("%f", &cadastro.valor);
    fflush(stdin);

    return cadastro;
}

void salvarProdutoTXT(Produto *produtos, int i_produtos)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_produtos; n++)
    {
        fprintf(fp, "%d|%s|%f\n",
                produtos[n].codigoProduto,
                produtos[n].descricao,
                produtos[n].valor);
    }
    fclose(fp);
}

int carregarProdutosTXT(Produto *produtos)
{
    FILE *fp;
    char buffer[1024];
    int i_produtos = 0;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';

        (*(produtos + i_produtos)).codigoProduto = atoi(strtok(buffer, "|"));
        strcpy((*(produtos + i_produtos)).descricao, strtok(NULL, "|"));
        (*(produtos + i_produtos)).valor = atof(strtok(NULL, "|"));

        i_produtos++;
    }

    fclose(fp);

    return (i_produtos);
}