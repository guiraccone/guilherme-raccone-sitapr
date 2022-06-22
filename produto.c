#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

//----------------------------------------------------------
//
void ordenarProduto(Produto p[], int n)
{
    int i, j;
    Produto temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].valor > p[j].valor)
            {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void imprimeProduto(Produto produto)
{

    printf("___________________________________________________________________________________________\n"
           "\n\t\t\t\tInformações do Produto"
           "\n___________________________________________________________________________________________\n"
           "\n\tCódigo\n\n\t%d\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tDescrição\n\n\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tValor \n\n\tR$%.2f\n\n"
           "-------------------------------------------------------------------------------------------\n\n\n",
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

    printf("-------------------------------------------------------------------------------------------\n"
           "\t\t\t\t\tCadastro do produto\n"
           "-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o código do produto:\n\n");
    fflush(stdin);
    scanf("%d", &cadastro.codigoProduto);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme a descrição do produto:\n\n");
    fflush(stdin);
    gets(cadastro.descricao);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o valor do produto (R$):\n\n");
    fflush(stdin);
    scanf("%f", &cadastro.valor);
    printf("-------------------------------------------------------------------------------------------\n");

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