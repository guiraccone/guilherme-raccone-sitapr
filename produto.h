#ifndef PRODUTO_H
#define PRODUTO_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_PRODUTOS "./db/produtos.txt"

//----------------------------------------------------------
// Estrutura de dados produto.
typedef struct
{
    int codigoProduto;
    char descricao[100];
    float valor;
} Produto;

//----------------------------------------------------------
// Estrutura de dados produto.
void imprimeProduto(Produto produto);
Produto cadastraProduto();
int carregarProdutosTXT(Produto *produtos);
void salvarProdutoTXT(Produto *produtos, int i_produtos);
void ordenarProduto(Produto *produtos, int i_produtos);

#endif
