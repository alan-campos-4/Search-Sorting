//============================================================================
// Name        : Sorting-and-Search.cpp
// Author      : A
// Version     : ...
// Copyright   : ...
// Description : ...
//============================================================================

#include <iostream>
#include <stdlib.h> //system("cls")

#include "SearchTest.h"
#include "SortingTest.h"
using namespace std;



/*
 * TODO:
 * Translate all names to English
 * Implement generic methods
 *
 * */




void sortMenu()
{
    int op=0, op1=0, op2=0;
    TestOrdenacion TO;

    do {
        system("cls");
        cout << "\n\n\t----- SORTING ALGORITHMS -----" << endl << endl;
        cout << "\t\t1. Verify the functioning of an algorithm" << endl;
        cout << "\t\t2. Calculate the cost of a method" << endl;
        cout << "\t\t3. Compare the cost of two methods" << endl;
        cout << "\t\t4. Compare the cost of all methods" << endl;
        cout << "\t\t0. Exit" << endl;
        cout << endl << "\tSelect an option: ";
        cin >> op;

        switch (op)
        {
            case 1: {TO.comprobarAlgoritmos();}	break;
            case 2:
            {
            	system("cls");
				cout << endl << endl;
				cout << "\t***** Calculate the cost of a method *****" << endl << endl;
				TO.mostrarAlgoritmos();
				cout << "\n\tSelect an option: ";
				cin >> op1;
				if (op1 >= 0 && op1 <= 4)
					{TO.costeAleatorio(op1);}
				else
					{cout << "Invalid option." << endl;}
            }
            break;
            case 3:
            {
            	system("cls");
				cout << endl << endl;
				cout << "\t***** Calculate the cost of 2 methods *****" << endl << endl;
				TO.mostrarAlgoritmos();
				cout << "\n\tSelect the first option: "; cin >> op1;
				if (op1 >= 0 && op1 <= 4)
				{
					cout << "\tSelect the second option: "; cin >> op2;
					if (op2 >= 0 && op2 <= 4)
						{TO.costeAleatorio(op1, op2);}
					else { cout << "Invalid option.\n"; }
				}
				else { cout << "Invalid option.\n"; }
            }
            break;
            case 4: {TO.costeAleatorio();}	break;
            case 0: {} break;
            default: {cout << "Invalid option. Try again." << endl; } break;
        }

        system("pause");
    } while (op != 0);
};




void searchMenu()
{
    int op=0, op1=0, op2=0;
    TestBusqueda TB;

    do {
        system("cls");
        cout << "\n\n\t----- SEACRHING ALGORITHMS -----" << endl << endl;
        cout << "\t\t1. Verify the functioning of an algorithm" << endl;
        cout << "\t\t2. Calculate the cost of a method" << endl;
        cout << "\t\t3. Compare the cost of two methods" << endl;
        cout << "\t\t4. Compare the cost of all methods" << endl;
        cout << "\t\t0. Exit" << endl;
        cout << endl << "\tSelect an option: ";
        cin >> op;

        switch (op)
        {
        	case 1: { TB.comprobarAlgoritmos(); }	break;
			case 2:
			{
				system("cls");
				cout << endl << endl;
				cout << "\t***** Calculate the cost of a function *****" << endl << endl;
				TB.mostrarAlgoritmos();
				cout << "\n\n\tSelect and option: "; cin >> op1;
				if (op1 >= 0 && op1 <= 2)
					{TB.casoMedio(op1);}
				else
					{cout << "Invalid option" << endl;}
			}
			break;
			case 3:
			{
				system("cls");
				cout << endl << endl;
				cout << "\t***** Calculate the cost of 2 functions *****" << endl << endl;
				TB.mostrarAlgoritmos();
				cout << "\n\n\tSelect the first option: "; cin >> op1;
				if (op1 >= 0 && op1 <= 2)
				{
					cout << "\tSelect the second option: "; cin >> op2;
					if (op2 >= 0 && op2 <= 2)
						{TB.casoMedio(op1, op2);}
					else { cout << "Invalid option.\n"; }
				}
				else { cout << "Invalid option.\n"; }
			}
			break;
			case 4: { TB.casoMedio(); }	break;
        }

        system("pause");
    } while (op != 0);
};


/*
template<typename Base, typename T>
inline bool instanceof(const T *ptr)
	{return dynamic_cast<const Base*>(ptr) != nullptr;}

template <typename T>
void TestMenu(T Test)
{
	//
	int op=0, op1=0, op2=0;

	if (instanceof<TestBusqueda>(T))

	do {
		system("cls");
		cout << "\n\n\t----- SEACRHING ALGORITHMS -----" << endl << endl;
		cout << "\t\t1. Verify the functioning of an algorithm" << endl;
		cout << "\t\t2. Calculate the cost of a method" << endl;
		cout << "\t\t3. Compare the cost of two methods" << endl;
		cout << "\t\t4. Compare the cost of all methods" << endl;
		cout << "\t\t0. Exit" << endl;
		cout << endl << "\tSelect an option: ";
		cin >> op;

		system("pause");
	} while (op != 0);
}
//*/






int main()
{
	int mode=0;
	TestBusqueda TB;
	TestOrdenacion TO;

    do {
        system("cls");
		cout << "\n\n\t----- MAIN MENU -----" << endl << endl;
		cout << "\t\t1.- Sorting Algorithms" << endl << endl;
		cout << "\t\t2.- Search Algorithms" << endl << endl;
		cout << "\t\t0.- Exit" << endl << endl;
		cout << "\tSelect an option: ";
        cin >> mode;

        switch (mode)
        {
        	case 0: {}	break;
            case 1:	{sortMenu();}	break;
            case 2:	{searchMenu();}	break;
            //case 3: {TestMenu(TB);}	break;
            //case 4: {TestMenu(TO);}	break;
            default: {cout << "Invalid option. Try again." << endl; } break;
        }

    } while (mode != 0);

	return 0;

};



