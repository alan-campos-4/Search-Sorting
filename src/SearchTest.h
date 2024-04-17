#pragma once
/* 
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los algoritmos de b�squeda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un algoritmo de b�squeda,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente 
 * 3. Comparar el coste temporal de los casos medios de dos algoritmos de b�squeda permitiendo guardar los datos e imprimir la 
 *    gr�fica correspondiente.
 * 4. Comparar el coste temporal de los casos medios de todos los algoritmos de b�squeda
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;
	
class TestBusqueda
{
	vector<string> nombreAlgoritmo;
public:
	TestBusqueda();
	~TestBusqueda();


	void mostrarAlgoritmos();


/*
 * Busca un elemento en un vector de enteros seg�n el algoritmo indicado
 * param key: clave o elemento a buscar
 * param v: el vector de enteros donde buscar
 * param size: tama�o del vector de enteros
 * param posicion. Valor devuelto: entero, posici�n de la clave en el vector, si no se encuentra return -1
 * param numeroAlgoritmo: Algoritmo de b�squeda a utilizar
 * return Tiempo empleado en la b�squeda (en milisegundos)
 */
	static double buscaEnArrayDeInt(int key,int v[],int size,int &posicion, int numeroAlgoritmo);

/*
* Comprueba que los algoritmos de b�squeda funcionan correctamente
*/
    void comprobarAlgoritmos();

/*
* Calcula el caso medio de un algoritmo de b�squeda,
* Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
* param numeroAlgoritmo: algoritmo de b�squeda a estudiar.
*/
	void casoMedio(int numeroAlgoritmo);

/*
* Compara dos algoritmos de busqueda.
* Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
* param numAlg1: Primer Algoritmo de b�squeda a comparar
* param numAlg2: Segundo Algoritmo de b�squeda a comparar
*/
	void casoMedio(int numAlg1, int numAlg2);

/*
 * Compara los casos medios EMP�RICOS de todos los algoritmos de b�squeda.
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 */
	void casoMedio();
};
