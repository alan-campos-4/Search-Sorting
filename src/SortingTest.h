#pragma once
/* 
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los algoritmos funcionan adecuadamente.
 * 2. Calcular la eficiencia experimental para los casos ALEATORIOS de los Algoritmos de Ordenación,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente 
 * 3. Comparar el coste temporal de todos los Algoritmos de Ordenación, permitiendo guardar los datos 
 *    e imprimir la gráfica correspondiente.
 */
 
#include <string>
#include <vector>
using namespace std;




class TestOrdenacion
{
	vector<string> nombreAlgoritmo;
public:
	TestOrdenacion();
	~TestOrdenacion();


	void mostrarAlgoritmos();


/*
 * Ordena un vector de enteros según el método indicado
 * param E/S v: el vector de enteros a ordenar
 * param E size: tamaño del vector de enteros a ordenar
 * param E numAlgoritmo: algoritmo de ordenación utilizado
 * Valor devuelto: Tiempo empleado en la ordenación (en milisegundos)
 */
	double ordenarVectorDeInt(int v[], int size, int numAlgoritmo);


/* Comprueba que el algoritmo funciona */
	void comprobarAlgoritmos();

/*
 * Calcula el coste EMPIRICO del caso ALEATORIO de un Algoritmo de ordenación,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param numeroAlgoritmo: número del algoritmo a estudiar.
 */
	void costeAleatorio(int numeroAlgoritmo);

/*
* Compara los costes EMPIRICOS de los casos ALEATORIOS de DOS algoritmos de ordenación.
* Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
* param numAlg1: Primer Algoritmo de Ordenación a comparar
* param numAlg2: Segundo Algoritmo de Ordenación a comparar
*/
	void costeAleatorio(int numAlg1, int numAlg2);

/*
 * Compara los costes EMPIRICOS de los casos ALEATORIOS de los algoritmos de ordenación.
 * Genera el fichero de datos y la gráfica correspondiente.
 */
	void costeAleatorio();

};