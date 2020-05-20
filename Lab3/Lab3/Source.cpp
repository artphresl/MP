#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "salesman.h"
using namespace std;
#define N 5	//кол-во городов

double dget(double rmin, double rmax) // получить случайное число
{
	return ((double)rand() / (double)RAND_MAX)*(rmax - rmin) + rmin;
};

int iget(int rmin, int rmax)        // получить случайное число
{
	return (int)dget((double)rmin, (double)rmax);
};

int main()
{
	int d[N][N] = { {INF,2 * N,21 + N,INF,N},
					{N,INF,15 + N,68 - N,84 - N},
					{2 + N,3 * N,INF,86,49 + N},
					{17 + N,58 - N,4 * N,INF,3 * N},
					{93 - N,66 + N,52,13 + N,INF} };
	clock_t  t1, t2;

	t1 = clock();
	srand((unsigned)time(NULL));


	//for (int i = 0; i < 3; i++)
	//	d[iget(0, N - 1)][iget(0, N - 1)] = INF;


	int r[N];       // результат
	int s = salesman(
		N,          // [in]  количество городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		r           // [out] массив [n] маршрут 0 x x x x  

	);
	cout << "\n-- Komivoyazher -- ";
	cout << "\n-- City amount: " << N;
	cout << "\n-- Distance matrix : \n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j < N - 1)
			{
				if (d[i][j] == INF) cout << "INF ";
				else cout << d[i][j] << " ";
			}
			else
			{
				if (d[i][j] == INF) cout << "INF";
				else cout << d[i][j];
			}
		}
		cout << endl;
	}

	cout << "\n-- Optimal route: ";
	for (int i = 0; i < N; i++)
		cout << r[i] << "-->";
	cout << 0;

	cout << "\n-- Route distance     : " << s << "\n";
	t2 = clock();


	cout << "\ntime (sec):   " << (t2 - t1) << "\n";
	system("pause");
	return 0;
}