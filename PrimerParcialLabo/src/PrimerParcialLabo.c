#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "color.h"
#include "tipo.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#define T 5
#define P 50


int main(void) {

	setbuf(stdout, NULL);

	    Tipo tipos[T];
	    Color colores[T];
	    Servicio servicios[T];
	    Bicicleta bicis[P];
	    Trabajo trabajos[P];
	    Cliente clientes[T];

	    int opcion;
	    int retorno;
	    int opcionModificar;
	    int flagAlta = -1;
	    int flagModificar = -1;

	    inicializarBicisLibres(bicis, P);
	    inicializarListaTipo(tipos);
	    inicializarListaColores(colores);
	    inicializarListaServicios(servicios);
	    inicializarTrabajosLibres(trabajos, P);
	    inicializarListaClientes(clientes);

	        do{
				if(utn_getNumero(&opcion, "\n1-Alta bicicleta\n2-Modificar bicicleta\n3-Baja bicicleta\n4-Listar bicicletas\n5"
						"-Listar tipos\n6-Listar colores\n7-Listar servicios\n8-Alta trabajo\n9-Listar trabajos\n10-Informes\n11-Salir\n\nIngrese una opcion: ",
						"\nError ingrese una opcion valida\n", 1, 11, 50) == 0){}

					switch(opcion)
					{
						case 1:
							retorno = altaBicicleta(bicis, P, tipos, colores, clientes);
							if(retorno != -1)
							{
								SeparadorConGuionesCorto();
								printf("\nSe dio de alta exitosamente!!!\n\n");
								SeparadorConGuionesCorto();
								flagAlta = 1;
							}
							else
							{
								printf("\nNo hay mas espacio");
							}
						break;
						case 2:
							if(flagAlta == 1)
							{

								if(utn_getNumero(&opcionModificar, "\nQue desea modficar?\n1-Modificar tipo\n2-Modificar material\n\nIngrese opcion: ",
											"\nError ingrese una opcion valida\n", 1, 2, 50) == 0){}

									if(opcionModificar == 1)
									{
										retorno = modificarTipo(bicis, P, tipos);
										if(retorno == 1)
										{
											printf("\nSe modifico el tipo exitosamente!!!");
											flagModificar = 1;
										}
										else
										{
											printf("\nNo se pudo realizar la modificacion\n");
										}
									}
									else
									{
										retorno = modificarMaterial(bicis, P, tipos);
										if(retorno == 1)
										{
											printf("\nSe modifico el material exitosamente!!!\n");
											flagModificar = 1;
										}
										else
										{
											printf("\nNo se pudo realizar la modificacion\n");
										}
									}
							}
							else
							{
								printf("\nDebe dar de alta antes de poder hacer una modificacion\n");
							}
						break;
						case 3:
							if(flagModificar == 1)
							{
								retorno = bajaBicicleta(bicis, P, tipos);
								if(retorno == 1)
								{
									printf("\nSe dio de baja la bicicleta exitosamente!!!");
								}
								else
								{
									printf("\nNo se pudo realizar la baja");
								}
							}
							else
							{
								printf("\nDebe dar de alta antes de poder dar de baja\n");
							}
						break;
						case 4:
							if(flagAlta == 1)
							{
								SeparadorConGuionesCorto();
								mostrarListaBicicletas(bicis, P, tipos);
								SeparadorConGuionesCorto();
							}
							else
							{
								printf("\nDebe dar de alta antes de mostrar este listado\n");
							}
						break;
						case 5:
							mostrarListaTipos(tipos);
						break;
						case 6:
							mostrarListaColores(colores);
						break;
						case 7:
							mostrarListaServicios(servicios);
						break;
						case 8:
							retorno = altaTrabajo(trabajos, P, bicis, P, servicios, tipos);
							if(retorno == -1)
							{
								printf("\nNo se pudo realizar el trabajo\n");
							}
							else
							{
								printf("\nSe dio de alta el trabajo exitosamente!!!\n");
							}
						break;
						case 9:
							listarTrabajos(trabajos, P, bicis, P);
						break;
						case 10:
							if(utn_getNumero(&opcion, "\n1-Mostrar bicicletas del color seleccionado por el usuario\n"
									"2-Mostrar bicicletas de un tipo seleccionado\n"
									"3-Informar si hay más bicicletas de carbono o de aluminio y mostrar la cantidad.\n"
									"4-Mostrar un listado de las bicicletas separadas por tipo\n"
									"5-Elegir un color y un tipo y contar cuantas bicicletas hay de ese color y ese tipo\n"
									"6-Mostrar el o los colores más elegidos por los clientes.\n"
									"\nBONUSTRACK\n7-Pedir una bicicleta y mostrar todos los trabajos que se le hicieron a la misma\n"
									"\n\nIngrese una opcion: ",
									"\nError ingrese una opcion valida\n", 1, 7, 50) == 0){}

								switch(opcion)
								{
									case 1:
										mostrarBicicletaDelColorSeleccioonado(bicis, P, colores);
									break;
									case 2:
										mostrarBicicletaDelTipoSeleccioonado(bicis, P, tipos);
									break;
									case 3:
										MayorCantidadBicisMaterial(bicis, P);
									break;
									case 4:
										mostrarListaBicicletasPorTipo(bicis, P);
									break;
									case 5:
										mostrarBicicletaDelTipoYColorSeleccioonado(bicis, P, tipos, colores);
									break;
									case 6:
										MayorCantidadDeColores(bicis, P);
									break;
									case 7:
										mostrarTrabajoABiciSeleccionada(bicis, P, tipos);
									break;
								}
							break;
					}


	        }while(opcion != 11);

	return EXIT_SUCCESS;
}
