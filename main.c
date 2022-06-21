/**********************************************************
 *  SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 *  Unidade Curricular: Lógica de programação
 *  Situação de aprendizagem
 *  Professor: Lucas Antunes
 *  Alunos: Guilherme Matheus Raccone
 *  Luzerna, 26/05/2022
 **********************************************************/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "estoque.h"
#include "loja.h"
#include "carrinho.h"

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_ESTOQUE 100
#define MAX_CARRINHO 100
#define MAX_LOJAS 100

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Estoque estoques[MAX_ESTOQUE];
CarrinhoCompras carrinhos[MAX_CARRINHO];
Loja lojas[MAX_LOJAS];

int i_clientes = 0; // Variável de índice do vetor.
int i_produtos = 0;
int i_lojas = 0;
int i_carrinhos = 0;
int i_estoque = 0;

//----------------------------------------------------------
//
void opcao1()
{

    printf("\n\tAperte a tecla informada nas opções abaixo para operar na estrutura de Cliente:\n\n"
           "\t\t[ 1 ] - Adicionar Cliente\n"
           "\t\t[ 2 ] - Listar Clientes\n"
           "\t\t[ 3 ] - Procurar Cliente por CPF\n\n"
           "\t\t[ESC] - Voltar ao menu inicial\n\n\n");

    switch (getch())
    {

    case '1':
        clientes[i_clientes++] = cadastraCliente();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_clientes; n++)
        {
            imprimeCliente(clientes[n]);
        }
        break;

    case '3':
        system("cls");
        procurarCliente(clientes, i_clientes);
        break;
    case 27:
        return;

    default:
        printf("Comando não implementado\n");
    }
}

void opcao2()
{
    printf("\n\tAperte a tecla informada nas opções abaixo para operar na estrutura de Produto:\n\n"
           "\t\t[ 1 ] - Adicionar Produto\n"
           "\t\t[ 2 ] - Listar Produtos\n"
           "\t\t[ 3 ] - Ordenar Produtos por Preço\n\n"
           "\t\t[ESC] - Voltar ao menu inical\n\n\n");

    switch (getch())
    {
    case '1':
        produtos[i_produtos++] = cadastraProduto();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_produtos; n++)
        {
            imprimeProduto(produtos[n]);
        }
        break;

    case '3':
        ordenarProduto(produtos, i_produtos);
        printf("Produtos ordenados !\n");
        break;

    case 27:
        return;

    default:
        printf("Comando não implementado\n");
    }
}

void opcao3()
{
    printf("\n\tAperte a tecla informada nas opções abaixo para operar na estrutura de Estoque:\n\n"
           "\t\t[ 1 ] - Adicionar Estoque\n"
           "\t\t[ 2 ] - Listar Estoque\n\n"
           "\t\t[ESC] - Voltar ao menu inical\n\n\n");

    switch (getch())
    {
    case '1':
        estoques[i_estoque++] = cadastraEstoque();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_estoque; n++)
        {
            imprimeEstoque(estoques[n]);
        }
        break;

    case 27:
        return;
    }
}

void opcao4()
{
    printf("\n\tAperte a tecla informada nas opções abaixo para operar na estrutura de Carrinho:\n\n"
           "\t\t[ 1 ] - Adicionar Carrinho\n"
           "\t\t[ 2 ] - Listar Carrinhos\n\n"
           "\t\t[ESC] - Voltar ao menu inical\n\n\n");

    switch (getch())
    {
    case '1':
        carrinhos[i_carrinhos++] = cadastraCarrinho();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_carrinhos; n++)
        {
            imprimeCarrinho(carrinhos[n]);
        }
        break;

    case 27:
        return;
    }
}

void opcao5()
{
    printf("\n\tAperte a tecla informada nas opções abaixo para operar na estrutura de Loja:\n\n"
           "\t\t[ 1 ] - Adicionar Loja\n"
           "\t\t[ 2 ] - Listar Lojas\n\n"
           "\t\t[ESC] - Voltar ao menu inicial\n\n\n");

    switch (getch())
    {
    case '1':
        lojas[i_lojas++] = cadastraLoja();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_lojas; n++)
        {
            imprimeLoja(lojas[n]);
        }
        break;

    case 27:
        return;

    default:
        printf("Comando não implementado\n");
    }
}

int main()
{
    system("color 71");

    SetConsoleOutputCP((UINT)65001);

    i_clientes = carregarClientesTXT(clientes);
    i_produtos = carregarProdutosTXT(produtos);
    i_estoque = carregarEstoquesTXT(estoques);
    i_carrinhos = carregarCarrinhosTXT(carrinhos);
    i_lojas = carregarLojasTXT(lojas);

    while (1)
    {
        system("cls");

        printf("\n\tAperte a tecla informada nas opções abaixo para operar em alguma estrutura.\n\n"
               "\t\t[ 1 ] - Cliente\n"
               "\t\t[ 2 ] - Produto\n"
               "\t\t[ 3 ] - Estoque\n"
               "\t\t[ 4 ] - Carrinho\n"
               "\t\t[ 5 ] - Lojas\n\n"
               "\t\t[ESC] - Fechar o programa e salvar mudanças\n\n\n");

        switch (getch())
        {
        case '1':

            system("cls");
            opcao1();
            break;

        case '2':
            system("cls");
            opcao2();
            break;

        case '3':

            system("cls");
            opcao3();
            break;

        case '4':

            system("cls");
            opcao4();
            break;

        case '5':

            system("cls");
            opcao5();
            break;

        case 27:

            salvarCarrinhoTXT(carrinhos, i_carrinhos);
            salvarClienteTXT(clientes, i_clientes);
            salvarEstoqueTXT(estoques, i_estoque);
            salvarLojaTXT(lojas, i_lojas);
            salvarProdutoTXT(produtos, i_produtos);

            return (0);

        default:
            printf("Comando não implementado\n");
        }

        printf("\n\n\n");
        system("pause");
    }
}
