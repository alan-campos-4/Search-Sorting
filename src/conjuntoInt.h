#pragma once 
/////////// Declaración de la clase ConjuntoInt /////////////

class ConjuntoInt
{
private:
	int *datos; // datos: vector de enteros de tama�o variable
	int tamano; // tamano: talla del vector

public:
	/*************** ConjuntoInt *********************************************
	 *  Prototipo:    ConjuntoInt (int max); 
	 *  Descripcion:  constructor que crea un nuevo objeto din�mico. 
	 *  param E: max= numero m�ximo de elementos, "tama�o", del vector "datos"
	 *****************************************************************************/
	ConjuntoInt(int max = 0);

	/*************** ~ConjuntoInt *********************************************
	 *  Prototipo:    ~ConjuntoInt (int n);
	 *  Descripcion:  destructor que borra el objeto din�mico.
	 *  param E: n= numero de elementos, "tama�o", del vector "datos"
	 *****************************************************************************/
	~ConjuntoInt ();
	
	void vaciar ();
	
	/*************** GeneraVector ***************************************************************
     *  Prototipo:    void GeneraVector (int n)
     *  Descripcion:  Inicializa de manera aleatoria los n primeros elementos del vector "datos"
     **********************************************************************************************/
	void GeneraVector (int n);
	
	/*************** VerVector *******************************************************
	 *  Prototipo:    void VerVector()
	 *  Descripcion:  Muestra en pantalla los n primeros elementos del vector "datos"
	 ************************************************************************************/
	void VerVector();
	
	/* devuelve el vector */
	int* getDatos();

	int getDatos(int n);

	void cambiar(int n, int pos);

	int generaKey();

	int getPrimero();

   /************************** MostrarResultados *********************************************
  *  Prototipo:    void MostrarResultados (int a, int c)
  *  Descripcion:  Muestra el numero de operaciones realizadas para buscar en el vector
  *  Param E a entero: numero de asignaciones realizadas
  *  Param E c entero: numero de comparaciones realizadas
  *  Valor devuelto: ninguno
  ******************************************************************************************/
   void MostrarResultados(int a, int c);
};
