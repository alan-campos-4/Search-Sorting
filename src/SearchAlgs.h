#pragma once 
/*
 * Clase AlgoritmosBusqueda que implementa los Algoritmos de Búsqueda para buscar un elemento en un vector de enteros.
 * Define las implementaciones iterativas de los siguientes algoritmos de búsqueda en vectores de enteros en orden creciente:
 *	- Secuencial
 *	- Binaria o dicotómica
 *  - Interpolacion
 */

/* declaración de la clase AlgoritmosBusqueda */
class AlgoritmosBusqueda
{  
public:
    AlgoritmosBusqueda();
    ~AlgoritmosBusqueda();
	
    /*
    * Función Secuencial, implementa el algoritmo de búsqueda secuencial
    * param v: el vector de enteros donde buscar
    * param size: tamaño del vector
    * param key: clave o elemento a buscar
    * return posición de la clave en el vector
    */
    int Secuencial(int v[], int size, int key);

    /*
     * Función Binaria, implementa el algoritmo de búsqueda binaria Iterativo
     * param v: el vector de enteros donde buscar
     * param size: tamaño del vector
     * param key: clave o elemento a buscar
     * return posición de la clave en el vector
     */
    int Binaria(int v[], int size, int key);


    /*
     * Función Interpolacion, implementa el algoritmo de búsqueda por Interpolación
     * param v: el vector de enteros donde buscar
     * param size: tamaño del vector
     * param key: clave o elemento a buscar
     * return posición de la clave en el vector
     */
    int Interpolacion(int v[], int size, int key);
};