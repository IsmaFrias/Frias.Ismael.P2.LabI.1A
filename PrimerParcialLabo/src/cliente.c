#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "inputs.h"

/*********************************************************************/

void inicializarListaClientes(Cliente listaClientes[])
{
	Cliente auxiliar[6] = {{1, "Carlos", "m"}, {2, "Maria", "f"}, {3, "Jose", "m"}, {4, "Lucia", "f"}, {5, "Oscar", "m"}};

		for(int i=0; i<6; i++)
		{
			listaClientes[i] = auxiliar[i];
		}
}

/*********************************************************************/

void mostrarListaClientes(Cliente listaClientes[])
{
	SeparadorConGuionesCorto();
	for(int i=0; i<5; i++)
	{
		printf("\nID: %d     Color: %s     Sexo: %s", listaClientes[i].id, listaClientes[i].nombre, listaClientes[i].sexo);
	}
	SeparadorConGuionesCorto();
}
