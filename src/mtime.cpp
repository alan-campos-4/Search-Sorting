#include "mtime.h"
/* retorna "a - b" en segundos */
double Mtime::performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
/* Uso
.......
LARGE_INTEGER t_ini, t_fin;
double secs;
QueryPerformanceCounter(&t_ini);


QueryPerformanceCounter(&t_fin);
secs = performancecounter_diff(&t_fin, &t_ini);
cout<<"tiempo= "<<secs * 1000.0<<"milisegundos\n";
.......
*/
