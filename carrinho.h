#ifndef CARRINHO_H
#define CARRINHO_H

#define ARQUIVO_CARRINHOS "./db/carrinhos.txt"

typedef struct
{
    char cpf[11];
    int codigoProduto;
} CarrinhoCompras;

CarrinhoCompras cadastraCarrinho();
void imprimeCarrinho(CarrinhoCompras carrinho);
int carregarCarrinhosTXT(CarrinhoCompras *carrinhos);
void salvarCarrinhoTXT(CarrinhoCompras *carrinhos, int i_carrinhos);

#endif