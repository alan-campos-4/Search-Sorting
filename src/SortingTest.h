#pragma once
/* 
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los algoritmos funcionan adecuadamente.
 * 2. Calcular la eficiencia experimental para los casos ALEATORIOS de los Algoritmos de Ordenaci�n,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente 
 * 3. Comparar el coste temporal de todos los Algoritmos de Ordenaci�n, permitiendo guardar los datos 
 *    e imprimir la gr�fica correspondiente.
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
 * Ordena un vector de enteros seg�n el m�todo indicado
 * param E/S v: el vector de enteros a ordenar
 * param E size: tama�o del vector de enteros a ordenar
 * param E numAlgoritmo: algoritmo de ordenaci�n utilizado
 * Valor devuelto: Tiempo empleado en la ordenaci�n (en milisegundos)
 */
	double ordenarVectorDeInt(int v[], int size, int numAlgoritmo);


/* Comprueba que el algoritmo funciona */
	void comprobarAlgoritmos();

/*
 * Calcula el coste EMPIRICO del caso ALEATORIO de un Algoritmo de ordenaci�n,
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param numeroAlgoritmo: n�mero del algoritmo a estudiar.
 */
	void costeAleatorio(int numeroAlgoritmo);

/*
* Compara los costes EMPIRICOS de los casos ALEATORIOS de DOS algoritmos de ordenaci�n.
* Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
* param numAlg1: Primer Algoritmo de Ordenaci�n a comparar
* param numAlg2: Segundo Algoritmo de Ordenaci�n a comparar
*/
	void costeAleatorio(int numAlg1, int numAlg2);

/*
 * Compara los costes EMPIRICOS de los casos ALEATORIOS de los algoritmos de ordenaci�n.
 * Genera el fichero de datos y la gr�fica correspondiente.
 */
	void costeAleatorio();

};