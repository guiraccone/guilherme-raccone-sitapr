#ifndef ESTOQUE_H
#define ESTOQUE_H

#define ARQUIVO_ESTOQUE "./db/estoque.txt"

typedef struct
{
    char cnpj[14];
    int codigoProduto;
    int quantidade;
} Estoque;

Estoque cadastraEstoque();
void imprimeEstoque(Estoque estoque);
int carregarEstoquesTXT(Estoque *estoques);
void salvarEstoqueTXT(Estoque *estoques, int i_estoque);

#endif