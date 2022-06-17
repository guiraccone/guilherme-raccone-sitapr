#ifndef CLIENTE_H
#define CLIENTE_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_CLIENTES "./db/clientes.txt"

//----------------------------------------------------------
// Estrutura de dados cliente.
typedef struct
{
    char cpf[12];
    char nome[50];
    float saldo;
} Cliente;

//----------------------------------------------------------
// Estrutura de dados cliente.
Cliente cadastraCliente();
void imprimeCliente(Cliente cliente);
int carregarClientesTXT(Cliente *clientes);
void salvarClienteTXT(Cliente *clientes, int i_clientes);
void procurarCliente(Cliente *clientes, int i_clientes);

#endif