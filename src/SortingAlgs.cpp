/*
 * Clase AlgoritmosOrdenacion que implementa los Algoritmos de Ordenación para ordenar un vector de enteros en orden descendente.
 * Define las implementaciones de los siguientes métodos de Ordenación en vectores: 
 *	- Burbuja
 *  - Selección
 *	- Inserción
 *  - QuickSort
 */
#include <iostream>
u
#include "SortingAlgs.h"
sing namespace std;



/*
 * Función ordenaBurbuja, implementa el método de ordenación Burbuja
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 */
AlgoritmosOrdenacion :: AlgoritmosOrdenacion() {}
AlgoritmosOrdenacion :: ~AlgoritmosOrdenacion(){}






/******************************* Burbuja ***************************************************************************
 *  Prototipo:   void Burbuja(int v[], int size)
 *  Descripcion: Implementa el algoritmo de Ordenación por Burbuja para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::Burbuja(int v[], int n) 
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (v[j] > v[j + 1])
			{
				swap(v, j, j+1);/**** EXA L2 ****/
				//int aux = v[j]; v[j] = v[j+1]; v[j+1] = aux;
			}
		}
	}
}





/******************************* Selección *************************************************************************
 *  Prototipo:   void Seleccion(int v[], int size)
 *  Descripcion: Implementa el algoritmo de Ordenación por Seleccion para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::Seleccion(int v[], int size)
{
	int posminimo;
	for (int i = 0; i < size; i++)
	{
		posminimo = i;
		for (int j = i + 1; j < size; j++)
		{
			if (v[j] < v[posminimo])
			{
				posminimo = j;
			}
		}
		swap(v, i, posminimo);
	}
}

 




/******************************* Insercion *************************************************************************
 *  Prototipo:   void Insercion(int v[], int n)
 *  Descripcion: Implementa el algoritmo de Ordenación por Insercion para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::Insercion(int v[], int size) 
{
	int x, j;
	for (int i = 0; i < size; i++)
	{
		x = v[i];
		j = i - 1;
		while (j >= 0 && x < v[j]) 
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = x;
	}
}














/******************************* OrdenaQuickSort *******************************************************************
 *  Prototipo:   void OrdenaQuickSort(int v[], int n)
 *  Descripcion: Invoca el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::OrdenaQuickSort(int v[], int size) 
{
	QuickSort(v, 0, size-1);
}

/******************************* QuickSort *************************************************************************
 *  Prototipo:   void QuickSort(int v[], int primero, int ultimo)
 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E u int: índice del último elemento del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::QuickSort(int v[], int p, int r) 
{
	if (p < r)
	{
		int q = Partition(v, p, r);
		QuickSort(v, p, q);
		QuickSort(v, q+1, r);
	}
}

/******************************* Partition *************************************************************************
 *  Prototipo:   int Partition(int v[], int p, int r)
 *  Descripcion: particiona(reorganiza) el vector v[p..r] según el Pivote en dos subvectores
 *  A[p..q] y A[q+1..r], de forma que los elementos de A[p..q] son menores o iguales que los de A[q+1..r].
 *  (p y r delimitan la zona de v sobre la que se realiza la particion)
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E r int: índice del último elemento del vector
 *  param S q int: índice de la partición
 ******************************************************************************************************************/
int AlgoritmosOrdenacion::Partition(int v[], int p, int r) 
{
	int piv = v[p];
	int i = p - 1;
	int j = r + 1;
	
	do {
		do { j--; } while (v[j] > piv);
		do { i++; } while (v[i] < piv);
		if (i < j)	{swap(v, i, j); } /**** EXA L2 ****/
	} while (i < j);
	
	return j;
};










/******************************* OrdenaMergeSort *******************************************************************
 *  Prototipo:   void OrdenaQuickSort(int v[], int n)
 *  Descripcion: Invoca el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::OrdenaMergeSort(int v[], int size)
{
	MergeSort(v, 0, size - 1);
}

/******************************* MergeSort *************************************************************************
 *  Prototipo:   void QuickSort(int v[], int primero, int ultimo)
 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E u int: índice del último elemento del vector
 ******************************************************************************************************************/
void AlgoritmosOrdenacion::MergeSort(int v[], int e, int n)
{
	if (e < n)
	{
		int m = (e+n)/2;
		MergeSort(v, e, m);
		MergeSort(v, m+1, n);
		Merge(v, e, m, n);
	}
}

void AlgoritmosOrdenacion::Merge(int v[], int e, int m, int n)
{
	///*
	int d = n - e + 1;
	int B[d];	//array auxiliar para mezcla
	int i = e;      //variable del primer elemento de la primera subsecuencia
	int j = m + 1;  //variable del primer elemento de la segunda subsecuencia
	int k = 0;

	while (i <= m && j <= n)
	{
		if (v[i] <= v[j])	{ B[k++] = v[i++]; }
		else				{ B[k++] = v[j++]; }
	}
	// Si se agotaron todos los elementos de la segunda subsecuencia 
	while (i <= m) 
	{
		B[k++] = v[i++];
	}
	// Si se agotaron los de la primera secuencia
	while (j <= n) 
	{
		B[k++] = v[j++];
	}
	// Copiar todos los elementos del auxiliar al array
	for (k = 0; k <= n - e; k++) 
	{ 
		v[e + k] = B[k];
	}
	//*/
};













/**** EXA L2 ****/

/******************************* OrdenaShakerSort ********************************************************************
 *  Prototipo:   void OrdenaQuickSort(int v[], int n)
 *  Descripcion: Invoca el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E size int: tamaño de vector
 ********************************************************************************************************************/
void AlgoritmosOrdenacion::OrdenaShakerSort(int v[], int size)
{
	ShakerSort(v, 0, size-1);
}

/******************************* ShakerSort **************************************************************************
 *  Prototipo:   void QuickSort(int v[], int p, int u)
 *  Descripcion: Implementa el algoritmo de Ordenación por QuickSort para el vector de enteros "v" de tamaño "n".
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E u int: índice del último elemento del vector
 ********************************************************************************************************************/
void AlgoritmosOrdenacion::ShakerSort(int v[], int p, int u)
{
	while (p < u)
	{
		swap(v, u, PosMaximo(v, p, u));
		u--;
		swap(v, p, PosMinimo(v, p, u));
		p++;
	}
};







/******************************* Swap *******************************************************************************
 *  Prototipo:   void swap(int v[], int i, int j)
 *  Descripcion: Intercambia la posición de dos elemento de un vector
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector que se quiere intercambiar
 *  param E u int: índice del segundo elemento del vector que se quiere intercambiar
 ********************************************************************************************************************/
void AlgoritmosOrdenacion::swap(int v[], int i, int j)
{
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
};

/******************************* PosMaximo ***************************************************************************
 *  Prototipo:   int PosMaximo(int v[], int p, int u)
 *  Descripcion: Devuelve la posición del máximo elemento de un vector a[primero..ultimo]
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E u int: índice del último elemento del vector
 ********************************************************************************************************************/
int AlgoritmosOrdenacion::PosMaximo(int v[], int p, int u)
{
	int pmax = p;
	for (int i = p + 1; i <= u; i++)
	{
		if (v[i] > v[pmax])	{pmax = i;}
	}
	return pmax;
};

/******************************* PosMinimo ***************************************************************************
 *  Prototipo:   int PosMinimo(int v[], int p, int u)
 *  Descripcion: Devuelve la posición del minimo elemento de un vector a[primero..ultimo]
 *  param E/S v[] entero: vector
 *  param E p int: índice del primer elemento del vector
 *  param E u int: índice del último elemento del vector
 ********************************************************************************************************************/
int AlgoritmosOrdenacion::PosMinimo(int v[], int p, int u)
{
	int pmin = p;
	for (int i = p + 1; i <= u; i++)
	{
		if (v[i] < v[pmin])	{pmin = i;}
	}
	return pmin;
};


