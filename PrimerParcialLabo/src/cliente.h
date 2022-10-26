#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo[2];
}Cliente;

/*
 * inicializa la lista de clientes
 * Parametro: lista de bicicletas, lista de clietnes
 */
void inicializarListaClientes(Cliente listaClientes[]);

/*
 * muestra la lista de clientes
 * Parametro: lista de bicicletas, lista de clientes
 */
void mostrarListaClientes(Cliente listaClientes[]);

#endif /* CLIENTE_H_ */
