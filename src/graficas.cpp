/*
 *Clase Graficas, contiene m�todos para crear los ficheros de comandos para dibujar
 * la gr�fica que corresponda.
 */
#include "graficas.h"
#include "Constantes.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;





/*
 * M�todo generarGrafica(string nombre_algoritmo, int orden), genera el fichero de comandos para GNUPlot
 * y dibuja la gr�fica del caso MEDIO de un algoritmo y su ajuste a la funci�n correspondiente.
 * param nombre_algoritmo: NOMBRE del algoritmo.
 * param orden: Orden de Complejidad del algoritmo.
 */
void Graficas::generarGrafica(string nombre_algoritmo, int orden)
{

	string nombre_grafica = "Cmd" + nombre_algoritmo + ".gpl";
	ofstream fCmd(nombre_grafica);
	string fit, funct, tipo, via;
	switch (orden)
	{
		case N2:{
			fit = "N2(x)";			funct = "a*x*x + b*x + c"; 
			tipo = "1:2 lw 1 lt 2";	via = "a,b,c";
		}break;
		case NlogN:{
			fit = "NlogN(x)";		funct = "a*log(log(x)) + b*x + c";
			tipo = "1:2 lw 1 lt 2";	via = "a,b,c";
		}break;
		case N:	{
			fit = "N(x)";		funct = "a*x + b";
			tipo = "1:2";		via = "a,b";
		}break;
		case LOGN:{
			fit = "LOGN(x)";	funct = "a*log(x) + b";
			tipo = "1:2";		via = "a,b";
		}break;
		case LOGLOGN:{
			fit = "LOGLOGN(x)";	funct = "a*log(log(x)) + b";
			tipo = "1:2";		via = "a,b";
		}break;
	}

	fCmd << "#ESTE ES UN SCRIPT DE GNUPLOT PARA ESTUDIO DE 1 ALGORITMO" << "\n";

	fCmd << "set title \"" << nombre_algoritmo << "\" \n";
	fCmd << "set key top left vertical inside \n";
	fCmd << "set grid \n";
	fCmd << "set xlabel \"Talla(n)\" \n";
	fCmd << "set ylabel \"Tiempo(ms)\" \n";
	fCmd << fit << " = " << funct << endl;
	fCmd << "fit " << fit << " \"" << nombre_algoritmo << ".dat\" using 1:2 via " << via << endl;
	fCmd << "plot \"" << nombre_algoritmo << ".dat\" using " << tipo << " title \"" << nombre_algoritmo << "\", " << fit << endl;
	fCmd << "set terminal jpeg" << endl;
	fCmd << "set output \"" << nombre_algoritmo << ".jpeg\"" << endl;
	fCmd << "replot" << endl;

	fCmd << "pause -1 \"Pulsa Enter para continuar...\"";
	fCmd.close();

	system(nombre_grafica.c_str());
	cout << endl << "-> Grafica guardada en el fichero " << nombre_algoritmo << ".jpeg" << endl;
	cout << endl << "-> Fichero de comandos guardado en " << nombre_grafica << endl << endl;
	
}






/*
 * M�todo generarGrafica(string nombre1,string nombre2), genera el fichero de comandos para COMPARAR DOS Algoritmos con GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer algoritmo.
 * param nombre2: es el nombre del fichero de datos del segundo algoritmo.
 */
void Graficas::generarGrafica(string nombre1, string nombre2)
{
	string nombre = nombre1 + nombre2;
	string nombre_grafica = "Cmd" + nombre + ".gpl";
	ofstream fCmd(nombre_grafica);

	fCmd << "#ESTE ES UN SCRIPT DE GNUPLOT PARA COMPARACION DE ALGORITMOS" << endl;
	fCmd << "set title \"" << nombre1 << ", " << nombre2 << "\"" << endl;
	fCmd << "set key top left vertical inside" << endl;
	fCmd << "set grid" << endl;
	fCmd << "set xlabel \"Talla (n)\"" << endl;
	fCmd << "set ylabel \"Tiempo (ms)\"" << endl;
	fCmd << "plot \"" << nombre << ".dat\" using 1:2 with lines lw 1 lt 7 title \"" << nombre1 << "\",";
	fCmd <<		 "\"" << nombre << ".dat\" using 1:3 with lines lw 1 lt 3 title \"" << nombre2 << "\"" << endl;
	fCmd << "set terminal jpeg" << endl;
	fCmd << "set output \"" << nombre << ".jpeg\"" << endl;
	fCmd << "replot" << endl;

	fCmd << "pause -1 \"Pulsa Enter para continuar...\"";
	fCmd.close();

	system(nombre_grafica.c_str());
	cout << endl << "-> Grafica guardada en el fichero " << nombre + ".jpeg" << endl;
	cout << endl << "-> Fichero de comandos guardado en " << nombre_grafica << endl << endl;
}


void Graficas::generarGrafica(string nombre1, string nombre2, string nombre3)
{
	string nombreTodos = nombre1 + nombre2 + nombre3;
	string nombre_grafica = "Cmd" + nombreTodos + ".gpl";
	ofstream fCmd(nombre_grafica);

	fCmd << "#ESTE ES UN SCRIPT DE GNUPLOT PARA COMPARACION DE ALGORITMOS" << endl;
	fCmd << "set title \"" << nombre1 << ", " << nombre2 << ", " << nombre3 << "\"" << endl;
	fCmd << "set key top left vertical inside" << endl;
	fCmd << "set grid" << endl;
	fCmd << "set xlabel \"Talla (n)\"" << endl;
	fCmd << "set ylabel \"Tiempo (ms)\"" << endl;
	fCmd << "plot \"" << nombreTodos << ".dat\" using 1:2 title \"" << nombre1 << "\",";
	fCmd <<		"\"" << nombreTodos << ".dat\" using 1:3 with lines lw 1 lt 3 title \"" << nombre2 << "\",";
	fCmd <<		"\"" << nombreTodos << ".dat\" using 1:4 with lines lw 1 lt 4 title \"" << nombre3 << "\"" << endl;
	fCmd << "set terminal jpeg" << endl;
	fCmd << "set output \"" << nombreTodos << ".jpeg\"" << endl;
	fCmd << "replot" << endl;

	fCmd << "pause -1 \"Pulsa Enter para continuar...\"";
	fCmd.close();

	system(nombre_grafica.c_str());
	cout << endl << "-> Grafica guardada en el fichero " << nombreTodos + ".jpeg" << endl;
	cout << endl << "-> Fichero de comandos guardado en " << nombre_grafica << endl << endl;
}






/*
 * M�todo generarGrafica(vector<string> nombreAlgoritmo), genera el fichero de comandos para COMPARAR TODOS los Algoritmos con GNUPlot.
 * param nombreAlgoritmo: es el nombre de vector de nombres de todos los algoritmos a comparar.
 */
void Graficas::generarGrafica(vector<string> nombreAlgoritmo)
{
	string nombreTodos, nombre_grafica;
	int n = nombreAlgoritmo.size();
	for (int i = 0; i < n; i++) { nombreTodos += nombreAlgoritmo[i]; }
	nombre_grafica = "Cmd" + nombreTodos + ".gpl";
	ofstream fCmd(nombre_grafica);

	fCmd << "#ESTE ES UN SCRIPT DE GNUPLOT PARA COMPARACION DE ALGORITMOS" << "\n";

	fCmd << "set title \"";
	for (int i = 0; i < n; i++) { fCmd << nombreAlgoritmo[i] << (i == n-1 ? "\"" : ", "); }
	fCmd << endl;

	fCmd << "set key top left vertical inside" << endl;
	fCmd << "set grid" << endl;
	fCmd << "set xlabel \"Talla (n)\"" << endl;
	fCmd << "set ylabel \"Tiempo (ms)\"" << endl;

	fCmd << "plot ";
	for (int i = 0; i < n; i++)
	{
		int p = 2*i;
		if (i > n/2)
		{
			fCmd << "\"" << nombreTodos << ".dat\" using 1:" << i + 2 << " title \"" << nombreAlgoritmo[i];
		}
		else
		{
			fCmd << "\"" << nombreTodos << ".dat\" using 1:" << i + 2 << " with lines lw 1 lt " << p << " title \"" << nombreAlgoritmo[i];
		}
		fCmd << (i == nombreAlgoritmo.size() - 1 ? "\"" : "\", ");
	}
	fCmd << endl;
	/*
	*	numAlg		i			>2		<2
		1,2,3,4,5	0,1,2,3,4	4,5		0,1,2
		1,2,3		0,1,2		
	
	*/

	fCmd << "set terminal jpeg" << endl;
	fCmd << "set output \"" << nombreTodos << ".jpeg\"" << endl;
	fCmd << "replot" << endl;
	fCmd << "pause -1 \"Pulsa Enter para continuar...\"";
	fCmd.close();

	system(nombre_grafica.c_str());
	cout << endl << "-> Grafica guardada en el fichero " << nombreTodos + ".jpeg" << endl;
	cout << endl << "-> Fichero de comandos guardado en " << nombre_grafica << endl << endl;
}
