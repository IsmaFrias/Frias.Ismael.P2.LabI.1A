#ifndef BICICLETA_H_
#define BICICLETA_H_
#include "tipo.h"
#include "color.h"
#include "cliente.h"

typedef struct
{
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material[20]; // “c” carbono, “a” aluminio
	int idCliente;
}Bicicleta;

/*
 * Inicializa la lista de bicicletas en 0
 * Parametro: lista de bicicletas
 */
void inicializarBicisLibres(Bicicleta bicis[], int sizeBicis);

/*
 * busca un lugar libre en el array de bicicletas
 * Parametro: lista de bicicletas
 */
int buscarLugarLibre(Bicicleta bicis[], int sizeBicis);

/*
 * muestra lista de bicicletas dadas de alta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarListaBicicletas(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * da de alta una bicicleta
 * Parametro: lista de bicicletas, lista de tipos, lista de color, tamaño de la lista
 */
int altaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[], Cliente listaClientes[]);

/*
 * modifica el tipo de bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int modificarTipo(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * modifica el material de bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int modificarMaterial(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * da de baja una bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
int bajaBicicleta(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * Muestra de que color es la bicilceta elegida
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarBicicletaDelColorSeleccioonado(Bicicleta bicis[], int sizeBicis, Color listaColor[]);

/*
 * Muestra de que tipo es la bicilceta elegida
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarBicicletaDelTipoSeleccioonado(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

/*
 * Muestra cual es el material mas elegido
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void MayorCantidadBicisMaterial(Bicicleta bicis[], int sizeBicis);

/*
 * Muestra lista de bicicleta ordenadas por tipo
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarListaBicicletasPorTipo(Bicicleta bicis[], int sizeBicis);

/*
 * Muestra del tipo y color elegido
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista lista de colores
 */
void mostrarBicicletaDelTipoYColorSeleccioonado(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[], Color listaColor[]);

/*
 * Muestra la mayor cantidad dde colores
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void MayorCantidadDeColores(Bicicleta bicis[], int sizeBicis);

/*
 * Muestra que se le hizo a la bicicleta
 * Parametro: lista de bicicletas, lista de tipos, tamaño de la lista
 */
void mostrarTrabajoABiciSeleccionada(Bicicleta bicis[], int sizeBicis, Tipo listaTipos[]);

#endif /* BICICLETA_H_ */
