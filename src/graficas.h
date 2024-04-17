#pragma once
/*
 * Clase Graficas, contiene métodos para guardar las gráficas de los resultados,
 * es decir, crea los ficheros por lotes (comandos) para generar los ficheros gráficos que corresponda.
 */
#include <string>
#include <vector>
using namespace std;

class Graficas
{
public:
/*
 * Método generarGrafica(string nombre_algoritmo, int orden), genera el fichero de comandos para GNUPlot
 * y dibuja la gráfica del caso MEDIO de un algoritmo y su ajuste a la función correspondiente.
 * param nombre_algoritmo: NOMBRE del algoritmo.
 * param orden: Orden de Complejidad del algoritmo.
 */
	void generarGrafica(string metodo, int orden);
	
/*
 * Método generarGrafica(string nombre1,string nombre2), genera el fichero de comandos para COMPARAR DOS Algoritmos con GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer algoritmo.
 * param nombre2: es el nombre del fichero de datos del segundo algoritmo.
 */
	void generarGrafica(string nombre1, string nombre2);

	void generarGrafica(string nombre1, string nombre2, string nombre3);

	/*
 * Método generarGrafica(vector<string> nombreAlgoritmo), genera el fichero de comandos para COMPARAR TODOS los Algoritmos con GNUPlot.
 * param nombreAlgoritmo: es el nombre de vector de nombres de todos los algoritmos a comparar.
 */
	void generarGrafica(vector<string> nombreAlgoritmo);
};
