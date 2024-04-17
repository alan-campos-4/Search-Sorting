/*
 * La clase TestBusqueda contiene los metodos para:
 * 1. Comprobar que los m�todos de b�squeda de la clase AlgoritmosBusqueda funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un m�todo de b�squeda,
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente
 * 3. Comparar el coste temporal de los casos medios de dos algoritmos de b�squeda permitiendo guardar los datos e imprimir la
 *    gr�fica correspondiente.
 * 4. Comparar el coste temporal de los casos medios de los algoritmos de b�squeda
 *    permitiendo guardar los datos e imprimir la gr�fica correspondiente.
 */
#include "SearchTest.h"
#include "SearchAlgs.h"
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
 //#include <cstdlib>
using namespace std;


TestBusqueda::TestBusqueda()
{
	nombreAlgoritmo.push_back("Secuencial");
	nombreAlgoritmo.push_back("Binaria");
	nombreAlgoritmo.push_back("Interpolacion"); 
} 
TestBusqueda::~TestBusqueda() {}





void TestBusqueda::mostrarAlgoritmos()
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
 * Busca un elemento en un vector de enteros seg�n el algoritmo indicado
 * param key: clave o elemento a buscar
 * param v: el vector de enteros donde buscar
 * param size: tama�o del vector de enteros
 * param posicion. Valor devuelto: entero, posici�n de la clave en el vector, si no se encuentra return -1
 * param numeroAlgoritmo: Algoritmo de b�squeda a utilizar
 * return Tiempo empleado en la b�squeda (en milisegundos)
 */
double TestBusqueda::buscaEnArrayDeInt(int key, int v[], int size, int& posicion, int numeroAlgoritmo)
{
	AlgoritmosBusqueda strategia;
	LARGE_INTEGER t_inicial, t_final;
	Mtime t;
	QueryPerformanceCounter(&t_inicial);
	switch (numeroAlgoritmo)
	{
		case SECUENCIAL:	{posicion = strategia.Secuencial(v, size, key); }		break;
		case BINARIA:		{posicion = strategia.Binaria(v, size, key); }			break;
		case INTERPOLACION:	{posicion = strategia.Interpolacion(v, size, key); }	break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000000;   //microsegundos
};






/* Comprueba los algoritmos de b�squeda*/
void TestBusqueda::comprobarAlgoritmos()
{
	system("cls");
	cout << endl << "\t\t\t**** Comprobacion de los metodos de Ordenacion ****" << endl;
	cout << endl << "==> Introduce la talla: ";
	int talla;
	cin >> talla;

	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		v->GeneraVector(talla);

		cout << endl << "\n\n\t----- " << nombreAlgoritmo[metodo] << " -----" << endl;
		cout << endl << "-> Vector para el metodo " << nombreAlgoritmo[metodo] << ": " << endl;
		if (metodo != SECUENCIAL) { sort(v->getDatos(), v->getDatos() + talla); }
		v->VerVector();

		int posicion;
		int key = v->generaKey();
		double tiempo = buscaEnArrayDeInt(key, v->getDatos(), talla, posicion, metodo);
		cout << "\n\tClave a buscar: " << key << endl;
		cout << "\tPosicion de " << key << " buscado con el metodo " << nombreAlgoritmo[metodo] << ": " << posicion << endl;
		cout << "\tTiempo de ejecucion = " << tiempo << " ms" << endl << endl;
		system("pause");
	}
};






/*
 * Calcula el caso medio de un algoritmo de b�squeda,
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param numeroAlgoritmo: algoritmo de b�squeda a estudiar.
 */
void TestBusqueda::casoMedio(int numeroAlgoritmo)
{
	system("cls");
	string nombre = nombreAlgoritmo[numeroAlgoritmo];
	ofstream f(nombre + ".dat");
	cout << endl << "\t*** Busqueda por " << nombre << " *** " << endl << endl;
	cout << endl << "Tiempos promedios en ejecucion " << nombre << endl << endl;
	cout << "\tTalla" << "\t" << setw(10) << "Tiempo(ms)" << endl << endl;
	
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla)
	{
		ConjuntoInt* v = new ConjuntoInt(talla);
		double tiempo = 0.0;
		int posicion;
		
		if (numeroAlgoritmo != SECUENCIAL)	{sort(v->getDatos(), v->getDatos() + talla);}
		for (int i = 0; i < NUMREPETICIONES; i++)
		{
			v->GeneraVector(talla);
			tiempo += buscaEnArrayDeInt(v->generaKey(), v->getDatos(), talla, posicion, numeroAlgoritmo);
		}
		tiempo /= NUMREPETICIONES;
		
		f << talla << "\t" << tiempo << endl;
		cout << "\t" << talla << "\t" << setw(10) << tiempo << " \t\t" << endl;
	}
	f.close();
	cout << endl << "-> Datos guardados en el fichero " << nombre << ".dat " << endl;
	cout << endl << "Generar grafica de resultados? (s/S): ";

	char opc;
	cin >> opc;
	if (opc == 's' || opc == 'S')
	{
		Graficas g;
		int orden;
		switch (numeroAlgoritmo)
		{
			default:			{orden = N; }		break;
			case BINARIA:		{orden = LOGN; }	break;
			case INTERPOLACION:	{orden = LOGLOGN; }	break;
		}
		g.generarGrafica(nombre, orden);
	}
	else { cout << endl << "-> No se genera la grafica" << endl << endl; }

	system("pause");
};






/*
 * Compara dos algoritmos de busqueda.
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 * param numAlg1: Primer Algoritmo de b�squeda a comparar
 * param numAlg2: Segundo Algoritmo de b�squeda a comparar
 */
void TestBusqueda::casoMedio(int numAlg1, int numAlg2)
{
	system("cls");
	string nom1 = nombreAlgoritmo[numAlg1];
	string nom2 = nombreAlgoritmo[numAlg2];
	string nombre = nom1 + nom2;
	ofstream f(nombre + ".dat");
	cout << setw(40) << "*** Comparacion Busqueda " << nom1 << " y " << nom2 << " ***" << endl;
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
			int posicion;
			v->GeneraVector(talla);

			if (i != SECUENCIAL)	{ sort(v->getDatos(), v->getDatos() + talla); }
			for (int j = 0; j < NUMREPETICIONES; j++)
			{
				tiempo += buscaEnArrayDeInt(v->generaKey(), v->getDatos(), talla, posicion, numAlg1);
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
	cout << endl << "Generar grafica de resultados? (s/n): ";

	char opc;
	cin >> opc;
	if ((opc == 's') || (opc == 'S'))
	{
		Graficas g;
		g.generarGrafica(nom1, nom2);
	}
	else { cout << "-> No se genera la grafica" << endl << endl; }


	system("pause");
};






/*
 * Compara los casos medios EMP�RICOS de todos los algoritmos de b�squeda.
 * Permite las opciones de crear el fichero de datos y la gr�fica correspondiente.
 */
void TestBusqueda::casoMedio()
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
			double tiempo = 0.0;
			int posicion;
			v->GeneraVector(talla);
			
			if (i != SECUENCIAL) { sort(v->getDatos(), v->getDatos() + talla); }
			for (int j = 0; j < NUMREPETICIONES; j++)
			{
				tiempo += buscaEnArrayDeInt(v->generaKey(), v->getDatos(), talla, posicion, i);
			}
			tiempo /= NUMREPETICIONES;

			f << "\t" << tiempo;
			cout << "\t" << setw(10) << tiempo;
		}
		f << endl;
		cout << endl;
	}
	f.close();

	cout << endl << "-> Datos guardados en el fichero " << nombreTodos << ".dat" << endl;
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
