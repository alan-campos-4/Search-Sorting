#pragma once
/*
 * Clase Graficas, contiene m�todos para guardar las gr�ficas de los resultados,
 * es decir, crea los ficheros por lotes (comandos) para generar los ficheros gr�ficos que corresponda.
 */
#include <string>
#include <vector>
using namespace std;

class Graficas
{
public:
/*
 * M�todo generarGrafica(string nombre_algoritmo, int orden), genera el fichero de comandos para GNUPlot
 * y dibuja la gr�fica del caso MEDIO de un algoritmo y su ajuste a la funci�n correspondiente.
 * param nombre_algoritmo: NOMBRE del algoritmo.
 * param orden: Orden de Complejidad del algoritmo.
 */
	void generarGrafica(string metodo, int orden);
	
/*
 * M�todo generarGrafica(string nombre1,string nombre2), genera el fichero de comandos para COMPARAR DOS Algoritmos con GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer algoritmo.
 * param nombre2: es el nombre del fichero de datos del segundo algoritmo.
 */
	void generarGrafica(string nombre1, string nombre2);

	void generarGrafica(string nombre1, string nombre2, string nombre3);

	/*
 * M�todo generarGrafica(vector<string> nombreAlgoritmo), genera el fichero de comandos para COMPARAR TODOS los Algoritmos con GNUPlot.
 * param nombreAlgoritmo: es el nombre de vector de nombres de todos los algoritmos a comparar.
 */
	void generarGrafica(vector<string> nombreAlgoritmo);
};
