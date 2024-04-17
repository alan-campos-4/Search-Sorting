/**** Implementacion de la clase ConjuntoInt ****/
#include "conjuntoInt.h"
#include <ctime>  //para time
#include <cstdlib> // for srand, rand
#include <iostream>
using namespace std;

/* crea un nuevo objeto usando el constructor*/
ConjuntoInt::ConjuntoInt (int max)
{
	tamano = max;
	datos = new int[max];
}

/*Borra el objeto dinámico, usando el destructor.*/
ConjuntoInt::~ConjuntoInt ()
{
	delete [] datos;
}
void ConjuntoInt::vaciar ()
{
	tamano = 0;
}




/*************** GeneraVector *********************************************
 *  Prototipo:    void GeneraVector (int n)
 *  Descripcion:  Inicializa de manera aleatoria los n primeros elementos del vector datos
 *****************************************************************************/
void ConjuntoInt::GeneraVector (int n)
{
	tamano = n;
	srand( (unsigned)time( NULL ) ); //srand(time(0));
	for (int i = 0; i < tamano; i++)
		{datos[i] = rand() % 100;} //genera un número aleatorio entre 1 y 999
	
}



/*************** VerVector *********************************************
 *  Prototipo:    void ConjuntoInt::VerVector()
 *  Descripcion:  Visualiza el vector "datos" de tamaño "tamano" por pantalla
 */
void ConjuntoInt::VerVector()
{
	for (int i = 0; i < tamano; i++)
		{cout << datos[i] << (i < tamano - 1 ? "-" : "\n"); }
}




/* devuelve el vector */
int* ConjuntoInt::getDatos()
{
	int *v = datos;
	for (int i = 0; i < tamano; i++) 
		{v[i] = datos[i];}
	return v;
}

/* devuelve un elemento del vector */
int ConjuntoInt::getDatos(int n)
{
	int* v = datos;
	for (int i = 0; i < tamano; i++)
	{
		v[i] = datos[i];
	}
	return v[n];
}

void ConjuntoInt::cambiar(int n, int pos)
{
	datos[pos] = n;
}



/* devuelve el valor del vector en una posición aleatoria entre 1 y el tamaño del vector */
int ConjuntoInt::generaKey()
{
	return datos[rand() % tamano];
}





/* devuelve el valor del vector en la primera posición*/
int ConjuntoInt::getPrimero()
{
	return datos[0];
}




/*************** ConjuntoInt::MostrarResultados *********************************************
	 *  Prototipo:    void MostrarResultados (int a, int c)
	 *  Descripcion:  Muestra el numero de operaciones realizadas para buscar en el vector
	 *  Param E a entero: numero de asignaciones realizadas
	 *  Param E c entero: numero de comparaciones realizadas
	 *  Valor devuelto: ninguno
 *****************************************************************************/
void ConjuntoInt::MostrarResultados(int a, int c)
{
	cout << endl << "Resultados ==> " << endl;
	cout << "\t- Asignaciones: " << a << endl;
	cout << "\t- Comparaciones: " << c << endl;
	cout << "-------------------------------------------" << endl;
}
