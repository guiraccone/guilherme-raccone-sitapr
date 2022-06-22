#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

void imprimeLoja(Loja loja)
{
    printf("___________________________________________________________________________________________\n"
           "\n\t\t\t\t\tInformações da Loja:\n"
           "___________________________________________________________________________________________\n"
           "\n\tCNPJ\n\n\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tNome\n\n\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n"
           "\n\tSegmentação\n\n\t%s\n\n"
           "-------------------------------------------------------------------------------------------\n\n\n",
           loja.cnpj,
           loja.nome,
           loja.segmento);
}

Loja cadastraLoja()
{
    Loja cadastro;

    system("cls");

    printf("-------------------------------------------------------------------------------------------\n"
           "\t\t\t\tCadastro da loja\n"
           "-------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\tInforme o CNPJ:\n\n");
    fflush(stdin);
    gets(cadastro.cnpj);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme o nome da loja:\n\n");
    fflush(stdin);
    gets(cadastro.nome);
    printf("-------------------------------------------------------------------------------------------\n");

    printf("\n\t\t\tInforme a segmentação da loja:\n\n");
    fflush(stdin);
    gets(cadastro.segmento);
    printf("-------------------------------------------------------------------------------------------\n");

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
