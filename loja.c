#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

void imprimeLoja(Loja loja)
{
    printf("\n===========================================================\n"
           "\tInformações de Loja: \n"
           "\n\t\tCNPJ: %s\n"
           "\n\t\tNome: %s\n"
           "\n\t\tSegmentação: %s\n",
           loja.cnpj,
           loja.nome,
           loja.segmento);
}

Loja cadastraLoja()
{
    Loja cadastro;

    system("cls");

    printf("\n-----------------------------\n"
           "Cadastro de Loja\n");

    printf("\nInforme o CNPJ: ");
    fflush(stdin);
    gets(cadastro.cnpj);

    printf("\nInforme o nome da loja: ");
    fflush(stdin);
    gets(cadastro.nome);

    printf("\nInforme a segmentação da loja: ");
    fflush(stdin);
    gets(cadastro.segmento);

    return cadastro;
}

void salvarLojaTXT(Loja *lojas, int i_lojas)
{
    FILE *fp;
    if ((fp = fopen(ARQUIVO_LOJA, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo loja.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_lojas; n++)
    {
        fprintf(fp, "%s|%s|%s\n",
                lojas[n].cnpj,
                lojas[n].nome,
                lojas[n].segmento);
    }
    fclose(fp);
}

int carregarLojasTXT(Loja *lojas)
{
    FILE *fp;
    char buffer[1024];
    int i_lojas = 0;

    if ((fp = fopen(ARQUIVO_LOJA, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo loja.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        buffer[strlen(buffer) - 1] = '\0';

        strcpy((*(lojas + i_lojas)).cnpj, strtok(buffer, "|"));
        strcpy((*(lojas + i_lojas)).nome, strtok(NULL, "|"));
        strcpy((*(lojas + i_lojas)).segmento, strtok(NULL, "|"));

        i_lojas++;
    }

    fclose(fp);

    return (i_lojas);
}
