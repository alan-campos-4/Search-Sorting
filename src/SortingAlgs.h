#pragma once 
/*
 * Clase AlgoritmosOrdenacion que define los Algoritmos de Ordenación para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes métodos de Ordenación en vectores: 
 *	- Burbuja
 *  - Selección
 *	- Inserción
 *  - QuickSort
 */
#include "conjuntoInt.h"

/*
 * declaración de la clase AlgoritmosOrdenacion
 */
class AlgoritmosOrdenacion
{  
public:
	AlgoritmosOrdenacion();
    ~AlgoritmosOrdenacion();

	/******************************* Burbuja ******************************************************************************
	 *  Prototipo:   void Burbuja(int v[], int size)
	 *  Descripcion: Implementa el algoritmo de Ordenación por Burbuja para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E size int: tamaño del vector
	 *********************************************************************************************************************/
	void Burbuja(int v[], int size);
	
	/******************************* Seleccion ***************************************************************************
	 *  Prototipo:   void Seleccion(int v[], int size)
	 *  Descripcion: Implementa el algoritmo de Ordenación por Seleccion para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E size int: tamaño del vector
	 *********************************************************************************************************************/
	void Seleccion(int v[], int size);
	
	/******************************* Insercion ***************************************************************************
	 *  Prototipo:   void Insercion(int v[], int n)
	 *  Descripcion: Implementa el algoritmo de Ordenación por Insercion para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E size int: tamaño del vector
	 *********************************************************************************************************************/
	void Insercion(int v[], int size);

	/******************************* OrdenaQuickSort *********************************************************************
	 *  Prototipo:   void OrdenaQuickSort(int v[], int n)
	 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E size int: tamaño del vector
	 ********************************************************************************************************************/
	void OrdenaQuickSort(int v[], int size);

	/******************************* QuickSort **************************************************************************
	 *  Prototipo:   void QuickSort(int v[], int primero, int ultimo)
	 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E primero int: índice del primer elemento del vector
	 *  param E ultimo int: índice del último elemento del vector
	 *******************************************************************************************************************/
	void QuickSort(int v[], int primero, int ultimo);

	/******************************* Partition *************************************************************************
	 *  Prototipo:   int Partition(int v[], int p, int r)
	 *  Descripcion: particiona(reorganiza) el vector v[p..r] según el Pivote en dos subvectores
	 *  A[p..q] y A[q+1..r], de forma que los elementos de A[p..q] son menores o iguales que los de A[q+1..r].
	 *  (p y r delimitan la zona de v sobre la que se realiza la particion)
	 *  param E/S v[] entero: vector
	 *  param E p int: índice del primer elemento del vector
	 *  param E r int: índice del último elemento del vector
	 *  param S q int: índice de la partición
	 ********************************************************************************************************************/
	int Partition(int v[], int p, int r);






	/**** EXA L2 ****/

	/******************************* OrdenaShakersort ********************************************************************
	 *  Prototipo:   void OrdenaQuickSort(int v[], int n)
	 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E size int: tamaño de vector
	 ********************************************************************************************************************/
	void OrdenaShakerSort(int v[], int size);

	/******************************* Shakersort **************************************************************************
	 *  Prototipo:   void QuickSort(int v[], int p, int u)
	 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
	 *  param E/S v[] entero: vector
	 *  param E p int: índice del primer elemento del vector
	 *  param E u int: índice del último elemento del vector
	 ********************************************************************************************************************/
	void ShakerSort(int v[], int p, int r);




	void OrdenaMergeSort(int v[], int size);

	void MergeSort(int v[], int e, int n);

	void Merge(int v[], int e, int m, int n);




	/******************************* Swap *******************************************************************************
	 *  Prototipo:   void swap(int v[], int i, int j)
	 *  Descripcion: Intercambia el elemento del vector a[i] con el elemento a[j]
	 *  param E/S v[] entero: vector
	 *  param E p int: índice del primer elemento del vector que se quiere intercambiar
	 *  param E u int: índice del segundo elemento del vector que se quiere intercambiar
	 ********************************************************************************************************************/
	void swap(int v[], int i, int j);

	/******************************* PosMaximo ***************************************************************************
	 *  Prototipo:   int PosMinimo(int v[], int p, int u)
	 *  Descripcion: Devuelve la posición del máximo elemento de un vector a[primero..ultimo]
	 *  param E/S v[] entero: vector
	 *  param E p int: índice del primer elemento del vector
	 *  param E u int: índice del último elemento del vector
	 ********************************************************************************************************************/
	int PosMaximo(int v[], int p, int u);

	/******************************* PosMinimo ***************************************************************************
	 *  Prototipo:   int PosMinimo(int v[], int p, int u)
	 *  Descripcion: Devuelve la posición del minimo elemento de un vector a[primero..ultimo]
	 *  param E/S v[] entero: vector
	 *  param E p int: índice del primer elemento del vector
	 *  param E u int: índice del último elemento del vector
	 ********************************************************************************************************************/
	int PosMinimo(int v[], int p, int u);
	
};
