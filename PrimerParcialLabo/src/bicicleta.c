#include <stdio.h>
#include <string.h>
#include "inputs.h"
#include "bicicleta.h"
#include "color.h"
#include "cliente.h"

/****************************************************************************/

void inicializarBicisLibres(Bicicleta bicis[], int sizeBicis)
{
		for(int i=0; i<sizeBicis; i++)
		{
			bicis[i].id = 0;
		}
}

/****************************************************************************/

int buscarLugarLibre(Bicicleta bicis[], int sizeBicis)
{
	int index;
	index = -1;

	for(int i=0; i<sizeBicis; i++)
	{
		if(bicis[i].id == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}

/****************************************************************************/

int altaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[], Cliente listaClientes[])
{
	int index;

		index = buscarLugarLibre(bicis, sizeBicis);

		if(index != -1)
		{
			if(utn_getNumero(&bicis[index].id, "\nIngrese ID de bicicleta:  ",
								"\nError ingrese un id valido", 0, 100000, 500)==0){}
			PedirCadena(bicis[index].marca, "\nIngrese marca de la bicicleta: ");

			mostrarListaTipos(listaTipos);
			if(utn_getNumero(&bicis[index].idTipo, "\nIngrese ID de tipo:  ",
								"\nError ingrese un id valido", 999, 1003, 500)==0){}
			mostrarListaColores(listaColor);
			if(utn_getNumero(&bicis[index].idColor, "\nIngrese ID del color:  ",
								"\nError ingrese un id valido", 4999, 5004, 500)==0){}
			PedirCadena(bicis[index].material, "\nIngrese material (c -> carbono / a -> aluminio): ");

			mostrarListaClientes(listaClientes);
			if(utn_getNumero(&bicis[index].idCliente, "\nIngrese ID del cliente:  ",
							    "\nError ingrese un id valido", 0, 5, 500)==0){}
		}

	return index;
}

/****************************************************************************/

void mostrarListaBicicletas(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	for(int i=0; i<sizeBicis-1; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(bicis[i].id != 0 && bicis[i].idTipo == listaTipos[j].id)
			{
				if(bicis[i].idCliente == 1)
				{
					printf("\nID Bici: %d     Material: %s      Tipo: %s       Cliente: Carlos", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
				}
				else if(bicis[i].idCliente == 2)
				{
					printf("\nID Bici: %d     Material: %s      Tipo: %s       Cliente: Maria", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
				}
				else if(bicis[i].idCliente == 3)
				{
					printf("\nID Bici: %d     Material: %s      Tipo: %s       Cliente: Jose", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
				}
				else if(bicis[i].idCliente == 4)
				{
					printf("\nID Bici: %d     Material: %s      Tipo: %s       Cliente: Lucia", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
				}
				else if(bicis[i].idCliente == 5)
				{
					printf("\nID Bici: %d     Material: %s      Tipo: %s       Cliente: OScar", bicis[i].id, bicis[i].material, listaTipos[j].descripcion);
				}
			}
		}
	}
}

/****************************************************************************/

int modificarTipo(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idIngresado;
	int idNuevoTipo;
	int retorno = -1;

	    SeparadorConGuionesCorto();
	    mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
		SeparadorConGuionesCorto();
		if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta: ",
						"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

			for(int i=0; i<sizeBicis; i++)
			{
				if(bicis[i].id == idIngresado)
				{
					mostrarListaTipos(listaTipos);
					if(utn_getNumero(&idNuevoTipo, "\nIngrese el nuevo ID del tipo: ",
									"\nError ingrese un ID valido: \n", 1000, 1003, 50) == 0){}
					bicis[i].idTipo = idNuevoTipo;
					retorno = 1;
					break;
				}
				else
				{
					printf("\nNo se econtro el ID ingresado\n");
					break;
				}
			}

	return retorno;
}

/****************************************************************************/

int modificarMaterial(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idIngresado;
	int retorno = -1;

		    SeparadorConGuionesCorto();
		    mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta: ",
							"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id == idIngresado)
					{
						PedirCadena(bicis[i].material, "\nIngrese nuevo material (c -> carbono / a -> aluminio: ");
						retorno = 1;
						break;
					}
					else
					{
						printf("\nNo se econtro el ID ingresado\n");
						break;
					}
				}

		return retorno;
}

/****************************************************************************/

int bajaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int retorno = -1;
	int idIngresado;

			SeparadorConGuionesCorto();
			mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
			SeparadorConGuionesCorto();
			if(utn_getNumero(&idIngresado, "\nIngrese ID de la bicicleta a dar de baja: ",
								"\nError ingrese un ID valido: \n", 1, 999999999, 50) == 0){}

			for(int i=0; i<sizeBicis; i++)
			{
				if(bicis[i].id == idIngresado)
			    {
					bicis[i].id = 0;
					retorno = 1;
					break;
				}
				else
				{
					printf("\nNo se econtro el ID ingresado");
				}
			}

	return retorno;
}

/****************************************************************************/

void mostrarBicicletaDelColorSeleccioonado(Bicicleta bicis[], int sizeBicis, Color listaColor[])
{
	int idColor;

				mostrarListaColores(listaColor);
				if(utn_getNumero(&idColor, "\nIngrese ID del color: ",
						"\nError ingrese un ID, valido", 4999, 5004, 50)==0)

				SeparadorConGuionesCorto();
				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id != 0 && bicis[i].idColor == idColor)
					{
						for(int j=0; j<5; j++)
						{
							if(listaColor[j].id == idColor)
							{
								printf("\nID bici: %d        Marca: %s         Color: %s", bicis[i].id, bicis[i].marca, listaColor[j].nombreColor);
							}
						}
					break;
					}
					else
					{
						printf("\nAun no hay bicicletas de ese color\n");
						break;
					}
				}
				SeparadorConGuionesCorto();

}

/****************************************************************************/

void mostrarBicicletaDelTipoSeleccioonado(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idTipo;

				mostrarListaTipos(listaTipos);
				if(utn_getNumero(&idTipo, "\nIngrese ID del tipo: ",
						"\nError ingrese un ID, valido", 999, 1003, 50)==0)

				SeparadorConGuionesCorto();
				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id != 0 && bicis[i].idTipo == idTipo)
					{
						for(int j=0; j<5; j++)
						{
							if(listaTipos[j].id == idTipo)
							{
								printf("\nID bici: %d        Marca: %s         Tipo: %s", bicis[i].id, bicis[i].marca, listaTipos[j].descripcion);
							}
						}
						break;
					}
					else
					{
						printf("\nAun no hay bicicletas de ese tipo\n");
						break;
					}
				}
				SeparadorConGuionesCorto();
}

/****************************************************************************/

void MayorCantidadBicisMaterial(Bicicleta bicis[], int sizeBicis)
{
	int contadorAluminio = 0;
	int contadorCarbono = 0;

		for(int i=0; i<sizeBicis; i++)
		{
			if(strcmp(bicis[i].material, "a")== 0)
			{
				contadorAluminio++;
			}
			else if(strcmp(bicis[i].material, "c")== 0)
			{
				contadorCarbono++;
			}
		}

		SeparadorConGuionesCorto();
		if(contadorCarbono == 0 && contadorAluminio == 0)
		{
			printf("\nAun no hay bicicletas cargadas\n");
		}
		else
		{
			if(contadorCarbono > contadorAluminio)
			{
				printf("\nHay mas bicicletas de Carbono con la cantidad de: %d bicicletas\n", contadorCarbono);
			}
			else if(contadorCarbono == contadorAluminio)
			{
				printf("\nHay igual cantidad de bicicletas de carbono y aluminio, cantidad: %d\n", contadorAluminio);
			}
			else
			{
				printf("\nHay mas bicicletas de Aluminio con la cantidad de: %d bicicletas\n", contadorAluminio);
			}
		}
		SeparadorConGuionesCorto();
}

/****************************************************************************/

void mostrarListaBicicletasPorTipo(Bicicleta bicis[], int sizeBicis)
{
	int flag = 0;

	SeparadorConGuionesCorto();
	for(int i=0; i<sizeBicis-1; i++)
	{

		if(bicis[i].id != 0 && bicis[i].idTipo == 1000)
		{
			printf("\nTipo: Rutera    Material: %s     Marca: %s ", bicis[i].material, bicis[i].marca);
			flag = 1;
		}
		if(bicis[i].id != 0 && bicis[i].idTipo == 1001)
		{
			printf("\nTipo: Carrera    Material: %s     Marca: %s ", bicis[i].material, bicis[i].marca);
			flag = 1;
		}
		if(bicis[i].id != 0 && bicis[i].idTipo == 1002)
		{
			printf("\nTipo: Mountain    Material: %s     Marca: %s ", bicis[i].material, bicis[i].marca);
			flag = 1;
		}
		if(bicis[i].id != 0 && bicis[i].idTipo == 1003)
		{
			printf("\nTipo: BMX    Material: %s     Marca: %s ",  bicis[i].material, bicis[i].marca);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nNo hay bicicletas cargadas");
	}
	SeparadorConGuionesCorto();
}

/****************************************************************************/

void mostrarBicicletaDelTipoYColorSeleccioonado(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[])
{
	int idTipo;
	int idColor;
	int cantidad = 0;

			mostrarListaTipos(listaTipos);
			if(utn_getNumero(&idTipo, "\nIngrese ID del tipo: ",
					"\nError ingrese un ID, valido", 999, 1003, 50)==0)

			mostrarListaColores(listaColor);
			if(utn_getNumero(&idColor, "\nIngrese ID del color: ",
					"\nError ingrese un ID, valido", 4999, 5004, 50)==0)

			SeparadorConGuionesCorto();
			for(int i=0; i<sizeBicis; i++)
			{
				if(bicis[i].id != 0 && bicis[i].idTipo == idTipo && bicis[i].idColor == idColor)
				{
					cantidad++;
				}
			}
			if(cantidad == 0)
			{
				printf("\nAun no hay bicicletas de ese tipo y color\n");
			}
			else
			{
				printf("\nLa cantida de bicicletas de ese tipo y color son: %d\n", cantidad);
			}
			SeparadorConGuionesCorto();
}

/****************************************************************************/

void MayorCantidadDeColores(Bicicleta bicis[], int sizeBicis)
{
	int contadorGris= 0;
	int contadorBlanco = 0;
	int contadorAzul = 0;
	int contadorNegro = 0;
	int contadorRojo = 0;

		for(int i=0; i<sizeBicis; i++)
		{
			if(bicis[i].idColor == 5000)
			{
				contadorGris++;
			}
			else if(bicis[i].idColor == 5001)
			{
				contadorBlanco++;
			}
			else if(bicis[i].idColor == 5002)
			{
				contadorAzul++;
			}
			else if(bicis[i].idColor == 5003)
			{
				contadorNegro++;
			}
			else if(bicis[i].idColor == 5004)
			{
				contadorRojo++;
			}
		}

		SeparadorConGuionesCorto();
		if(contadorGris == 0 && contadorBlanco == 0 && contadorAzul == 0 && contadorNegro == 0 && contadorRojo == 0)
		{
			printf("\nAun no hay bicicletas cargadas\n");
		}
		else
		{
			if(contadorGris > contadorBlanco && contadorGris > contadorAzul && contadorGris > contadorNegro && contadorGris > contadorRojo)
			{
				printf("\nHay mas bicicletas del color Gris con la cantidad de: %d bicicletas\n", contadorGris);
			}
			else if(contadorBlanco > contadorGris && contadorBlanco > contadorAzul && contadorBlanco > contadorNegro && contadorBlanco > contadorRojo)
			{
				printf("\nHay mas bicicletas del color Blanco con la cantidad de: %d bicicletas\n", contadorBlanco);
			}
			else if(contadorAzul > contadorGris && contadorAzul > contadorBlanco && contadorAzul > contadorNegro && contadorAzul > contadorRojo)
			{
				printf("\nHay mas bicicletas del color Azul con la cantidad de: %d bicicletas\n", contadorAzul);
			}
			else if(contadorNegro > contadorGris && contadorNegro > contadorAzul && contadorNegro > contadorBlanco && contadorNegro > contadorRojo)
			{
				printf("\nHay mas bicicletas del color Negro con la cantidad de: %d bicicletas\n", contadorNegro);
			}
			else if(contadorRojo > contadorGris && contadorRojo > contadorAzul && contadorRojo > contadorNegro && contadorRojo > contadorBlanco)
			{
				printf("\nHay mas bicicletas del color Rojo con la cantidad de: %d bicicletas\n", contadorBlanco);
			}
		}
		SeparadorConGuionesCorto();
}

/****************************************************************************/

void mostrarTrabajoABiciSeleccionada(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[])
{
	int idBici;

		SeparadorConGuionesCorto();
		mostrarListaBicicletas(bicis, sizeBicis, listaTipos);
		SeparadorConGuionesCorto();
				if(utn_getNumero(&idBici, "\nIngrese ID de la bicicleta: ",
						"\nError ingrese un ID, valido", 0, 99999, 50)==0)

				SeparadorConGuionesCorto();
				for(int i=0; i<sizeBicis; i++)
				{
					if(bicis[i].id != 0 && bicis[i].id == idBici)
					{
						for(int j=0; j<5; j++)
						{
							if(bicis[i].idTipo == listaTipos[j].id)
							{
								printf("\nEsta bicicleta es de Tipo: %s y de la Marca: %s y del Material: %s", listaTipos[j].descripcion,
																						bicis[i].marca, bicis[i].material);
							}
						}
					break;
					}
					else
					{
						printf("\nAun no hay bicicletas de ese color\n");
						break;
					}
				}
				SeparadorConGuionesCorto();

}
