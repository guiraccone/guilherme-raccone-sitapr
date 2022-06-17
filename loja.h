#ifndef LOJA_H
#define LOJA_H

#define ARQUIVO_LOJA "./db/loja.txt"

typedef struct
{
    char cnpj[14];
    char nome[50];
    char segmento[200];
} Loja;

Loja cadastraLoja();
void imprimeLoja(Loja loja);
int carregarLojasTXT(Loja *lojas);
void salvarLojaTXT(Loja *lojas, int i_lojas);

#endif