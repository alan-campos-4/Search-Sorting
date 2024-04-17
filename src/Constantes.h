#pragma once 
/*** Definiciones de las Constantes ***/

/* Constantes simb�licas para indicar el algoritmo de b�squeda*/
enum algoritmosBusq { SECUENCIAL, BINARIA, INTERPOLACION };

/* Constantes simb�licas para indicar el algoritmo de ordenaci�n*/
enum algoritmosOrd { BURBUJA, SELECCION, INSERCION, QUICKSORT, SHAKERSORT, MERGESORT };

/* Constantes para indicar el Orden del algoritmo*/
enum ordenes { LOGLOGN, LOGN, N, N2, NlogN };

/* Constantes para indicar la variacion de las tallas del vector */
enum valoresTallas { tallaIni=100, tallaFin=1000, incTalla=100 };

/* Constantes para indicar el Numero de repeticiones para el caso medio de cada Algoritmo */
static const int NUMREPETICIONES = 100;
