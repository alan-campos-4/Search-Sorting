/*
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que el algoritmo funciona adecuadamente.
 * 2. Calcular la eficiencia te�rica y experimental para los casos de un Algoritmo de Ordenaci�n,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente
 * 3. Comparar el coste temporal de los casos de un Algoritmo de Ordenaci�n, permitiendo guardar los datos
 *    e imprimir la gr�fica correspondiente.
 * 4. Comparar el coste temporal de los casos medios de los algoritmos de b�squeda
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente.
 */
#include "conjuntoInt.h"
#include "Constantes.h"
#include "mtime.h"
#include "graficas.h"
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstdlib>

#include "SortingTest.h"

#include "SortingAlgs.h"
using namespace std;


TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");//BubbleSort
	nombreAlgoritmo.push_back("Seleccion");//SelectionSort
	nombreAlgoritmo.push_back("Insercion");//InsertionSort
	nombreAlgoritmo.push_back("QuickSort");
	nombreAlgoritmo.push_back("ShakerSort");
	//nombreAlgoritmo.push_back("MergeSort");
}
TestOrdenacion::~TestOrdenacion() {}





void TestOrdenacion::mostrarAlgoritmos()
{
	for (int i = 0; i <= nombreAlgoritmo.size(); i++)
	{
		cout << "\t\t" << i << ". ";
		if (i == nombreAlgoritmo.size())	{cout << "Salir";}
		else
		{
			string str = nombreAlgoritmo[i];
			transform(str.begin(), str.end(), str.begin(), ::toupper);
			cout << str;
		}
		cout << endl;
	}
};






/*
 * Ordena un vector de enteros seg�n el m�todo indicado
 * param E/S v: el vector de enteros a ordenar
 * param E size: tama�o del vector de enteros a ordenar
 * param E numAlgoritmo: algoritmo de ordenaci�n utilizado
 * Valor devuelto: Tiempo empleado en la ordenaci�n (en milisegundos)
 */
double TestOrdenacion::ordenarVectorDeInt(int v[], int size, int numAlgoritmo)
{
	AlgoritmosOrdenacion estrategia;
	/* C�lculo del tiempo en ordenar */
	LARGE_INTEGER t_ini, t_fin;
	Mtime t;
	QueryPerformanceCounter(&t_ini);
	/* Invoca al algoritmo de ordenaci�n elegido */
	switch (numAlgoritmo)
	{
		case BURBUJA:	{estrategia.Burbuja(v, size);}			break;
		case INSERCION: {estrategia.Insercion(v, size);}		break;
		case SELECCION: {estrategia.Seleccion(v, size);}		break;
		case QUICKSORT:	{estrategia.OrdenaQuickSort(v, size);}	break;
		case SHAKERSORT:{estrategia.OrdenaShakerSort(v, size);}	break;
		case MERGESORT: {estrategia.OrdenaMergeSort(v, size);}	break;
	}
	QueryPerformanceCounter(&t_fin);
	return t.performancecounter_diff(&t_fin, &t_ini) * 1000/*000*/;/* ms */
};






/* Comprueba que el algoritmo funciona */
void TestOrdenacion::comprobarAlgoritmos()
{
	system("cls");
	cout << endl << "\t\t\t**** Comprobacion de los metodos de Busqueda ****" << endl << endl;
	cout << endl << "==> Introduce la talla: ";
	int talla;
	cin >> talla;

	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);

		cout << endl << "\n\n\t----- Ordenacion por " << nombreAlgoritmo[metodo] << " -----" << endl;
		cout << endl << "-> Vector para el caso del algoritmo " << nombreAlgoritmo[metodo] << " con vector inicial: " << endl;
		v->VerVector();

		/* C�lculo del tiempo en ordenar */
		double tiempo = ordenarVectorDeInt(v->getDatos(), talla, metodo);

		/* Mostrar tiempo de ejecuci�n */
		cout << endl << "   - Tiempo de ejecucion = " << tiempo << "ms" << endl;
		cout << endl << "-> Vector ordenado con el algoritmo " << nombreAlgoritmo[metodo] << ": " << endl;
		v->VerVector();
		system("pause");
	}
};







/*
 * Calcula el coste EMPIRICO del caso ALEATORIO de un Algoritmo de ordenaci�n,
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param numeroAlgoritmo: n�mero del algoritmo a estudiar.
 */
void TestOrdenacion::costeAleatorio(int numeroAlgoritmo)
{
	system("cls");
	string nombre = nombreAlgoritmo[numeroAlgoritmo];
	ofstream f(nombre + ".dat");
	cout << endl << "\t*** Ordenacion por " << nombre << " *** " << endl << endl;
	cout << endl << "Tiempos promedios en ejecucion " << nombre << endl << endl;
	cout << "\tTalla" << "\t" << setw(10) << "Tiempo(ms)" << endl << endl;

	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		double tiempo = 0.0;

		for (int j = 0; j < NUMREPETICIONES; j++)
		{
			v->GeneraVector(talla);
			tiempo += ordenarVectorDeInt(v->getDatos(), talla, numeroAlgoritmo);
		}
		tiempo /= NUMREPETICIONES;

		f << talla << "\t" << tiempo;
		cout << "\t" << talla << "\t" << setw(10) << tiempo;
		
		f << endl;
		cout << endl;

	}
	f.close();
	cout << endl << "-> Datos guardados en el fichero " << nombre + ".dat " << endl;
	cout << endl << "Generar grafica de resultados? (s/S): ";

	char opc; cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		Graficas g;
		int orden;
		switch (numeroAlgoritmo)
		{
			case QUICKSORT: {orden = NlogN; }	break;
			case MERGESORT: {orden = NlogN; }	break;
			default:		{orden = N2; }		break;
		}
		g.generarGrafica(nombre, orden);
	}
	else { cout << endl << "-> No se genera la grafica" << endl << endl; }

	system("pause");
};








/*
* Compara los costes EMPIRICOS de los casos ALEATORIOS de DOS algoritmos de ordenaci�n.
* Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
* param numAlg1: Primer Algoritmo de Ordenaci�n a comparar
* param numAlg2: Segundo Algoritmo de Ordenaci�n a comparar
*/
void TestOrdenacion::costeAleatorio(int numAlg1, int numAlg2)
{
	system("cls");
	string nom1 = nombreAlgoritmo[numAlg1];
	string nom2 = nombreAlgoritmo[numAlg2];
	string nombre = nom1 + nom2;
	ofstream f(nombre + ".dat");
	int algoritmos[2] = {numAlg1, numAlg2};
	cout << setw(40) << "*** Comparacion Ordenacion " << nom1 << " y " << nom2 << " ***" << endl;
	cout << setw(60) << "Tiempos de ejecucion promedio. Tiempo (ms)" << endl << endl;
	cout << "\tTalla " << "\t" << setw(10) << nom1 << "\t" << setw(10) << nom2 << endl << endl;
	
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		f << talla;
		cout << "\t" << talla;

		for (int i = 0; i < 2; i++)
		{
			ConjuntoInt* v = new ConjuntoInt(talla);
			double tiempo = 0.0;

			for (int j = 0; j < NUMREPETICIONES; j++)
			{
				v->GeneraVector(talla);
				tiempo += ordenarVectorDeInt(v->getDatos(), talla, algoritmos[i]);
			}
			tiempo /= NUMREPETICIONES;

			f << "\t" << tiempo;
			cout << "\t" << setw(10) << tiempo;
		}
		f << endl;
		cout << endl;
	}
	f.close();

	cout << endl << "-> Datos guardados en el fichero " << nombre + ".dat " << endl;
	cout << endl << "Generar grafica de resultados? (s/S): ";
	char opc;
	cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		Graficas g;
		g.generarGrafica(nom1, nom2);
	}
	else { cout << "-> No se genera la grafica" << endl << endl; }


	system("pause");
};







/*
 * Compara los costes EMPIRICOS de los casos ALEATORIOS de los algoritmos de ordenaci�n.
 * Genera el fichero de datos y la gr�fica correspondiente.
 */ 
void TestOrdenacion::costeAleatorio()
{
	system("cls");
	string nombreTodos;
	int numAlgs = nombreAlgoritmo.size();
	
	cout << setw(40) << "*** Comparacion Ordenacion: ";
	for (int i = 0; i < numAlgs; i++)
	{
		cout << nombreAlgoritmo[i] << (i == numAlgs - 1 ? " ***" : ", ");
		nombreTodos += nombreAlgoritmo[i];
	}

	cout << "\n\n\tTalla ";
	for (int i = 0; i < numAlgs; i++)	{cout << "\t" << setw(10) << nombreAlgoritmo[i];}
	cout << "\n\n";

	ofstream f(nombreTodos + ".dat");
	

	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		f << talla;	
		cout << "\t" << talla;

		for (int i = 0; i < numAlgs; i++)
		{
			ConjuntoInt* v = new ConjuntoInt(talla);
			v->GeneraVector(talla);
			double tiempo = 0.0;

			for (int j = 0; j < NUMREPETICIONES; j++)
			{
				tiempo += ordenarVectorDeInt(v->getDatos(), talla, i);
			}
			tiempo /= NUMREPETICIONES;

			f << "\t" << tiempo;	cout << "\t" << setw(10) << tiempo;
		}

		f << endl;	cout << endl;
	}
	f.close();

	cout << endl << "-> Datos guardados en el fichero " << nombreTodos + ".dat " << endl;
	cout << endl << "Generar grafica de resultados? (s/S): ";
	char opc;
	cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		Graficas g;
		g.generarGrafica(nombreAlgoritmo);
	}
	else { cout << "-> No se genera la grafica" << endl << endl; }


	system("pause");
};
