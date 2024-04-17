/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de Búsqueda para buscar un elemento en un vector de enteros.
 * Implementaciones iterativas de los siguientes algoritmos de búsqueda en vectores de enteros:
 *	- Secuencial
 *	- Binaria o dicotómica
 *  - Interpolacion
 */
#include "SearchAlgs.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/* Implementación de los métodos de la clase AlgoritmosBusqueda */
AlgoritmosBusqueda::AlgoritmosBusqueda()	{ }
AlgoritmosBusqueda::~AlgoritmosBusqueda()	{ }




/*
 * Función Secuencial, implementa el método de búsqueda secuencial Iterativo
 * param v: el vector de enteros donde buscar
 * param size: tamaño del vector
 * param key: clave o elemento a buscar
 * return posición de la clave en el vector
 */
int AlgoritmosBusqueda::Secuencial(int v[], int size, int key)
{
	int i = 0;
	while (v[i]!=key && i<size)
		{i++;}
	if (v[i] == key)
		return i;	 // devuelve la posición i donde se encuentra el valor en el array
	else
		return -1;  // devuelve -1, no se encuentra el valor en el array
}




/*
 * Función Binaria, implementa el algoritmo de búsqueda binaria
 * param v: el vector de enteros donde buscar
 * param size: tamaño del vector
 * param key: clave o elemento a buscar
 * return posición de la clave en el vector
 */
int AlgoritmosBusqueda::Binaria(int v[], int size, int key) 
{
	bool encontrado = false;
	int mitad, primero = 1, ultimo = size;

	while (primero <= ultimo && !encontrado)
	{
		mitad = (primero + ultimo) / 2;
		if (key == v[mitad])
		{
			encontrado = true;
		}
		else {
			if (key < v[mitad])
			{
				ultimo = mitad - 1;
			}
			else {
				if (key > v[mitad])
				{
					primero = mitad + 1;
				}
			}
		}
	}
	if (encontrado)
		return mitad;
	else
		return -1;
	return 0;
}





/*
 * Función Interpolacion, implementa el algoritmo de búsqueda por Interpolación
 * param v: el vector de enteros donde buscar
 * param size: tamaño del vector
 * param key: clave o elemento a buscar
 * return posición de la clave en el vector
 */
int AlgoritmosBusqueda::Interpolacion(int v[], int size, int key)
{
	int p, primero = 0, ultimo = size-1;

	while ((v[ultimo] >= key) && (v[primero] <= key))
	{
		p = primero + ((key - v[primero]) * (ultimo - primero)) / (v[ultimo] - v[primero]);
		//p = primero + ((ultimo - primero) * (key - v[primero]) / (v[ultimo] - v[primero]));
		if (v[p] < key) //if (key > v[p])
		{
			primero = p + 1;
		}
		else
		{
			if (v[p] > key) //if (key < v[p])
			{
				primero = p - 1; //ultimo = p-1;
			}
			else
			{
				return p; //primero = p;
			}
		}
	}
	if (v[primero] == key)
		return primero;
	else
		return -1;
	return 0;
}


