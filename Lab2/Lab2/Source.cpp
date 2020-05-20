#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "Peres.h"
#include "Razm.h"
#include "Soc.h"
#include "Salesman.h"
#define N 5
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	//--------------------------------��������� �����������-----------------------------------------------------
	/*char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " - ��������� ��������� ���� ����������� -";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ���� �����������  ";
	combi::subset s1(sizeof(AA) / 2);         // �������� ����������   
	int  n = s1.getfirst();                // ������ (������) ������������    
	while (n >= 0)                          // ���� ���� ������������ 
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n; i++)
			std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		std::cout << "}";
		n = s1.getnext();                   // c�������� ������������ 
	};
	std::cout << std::endl << "�����: " << s1.count() << std::endl;*/
	//--------------------------------��������� ���������-------------------------------------------------------
	/*char  AA[][2] = { "A", "B", "C", "D", "E" };
	std::cout << std::endl << " --- ��������� ��������� ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)

		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ��������� ";
	combi::xcombination xc(sizeof(AA) / 2, 3);
	std::cout << "�� " << xc.n << " �� " << xc.m;
	int  n = xc.getfirst();
	while (n >= 0)
	{

		std::cout << std::endl << xc.nc << ": { ";

		for (int i = 0; i < n; i++)


			std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");

		std::cout << "}";

		n = xc.getnext();
	};
	std::cout << std::endl << "�����: " << xc.count() << std::endl;*/
	//--------------------------------��������� ������������----------------------------------------------------
	/*char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- ��������� ������������ ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)

		std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ������������ ";
	combi::permutation p(sizeof(AA) / 2);
	__int64  n = p.getfirst();
	while (n >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";

		for (int i = 0; i < p.n; i++)

			std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");

		std::cout << "}";

		n = p.getnext();
	};
	std::cout << std::endl << "�����: " << p.count() << std::endl;*/
	//--------------------------------��������� ����������------------------------------------------------------
	/*char  AA[][2] = { "A", "B", "C", "D" };
	std::cout << std::endl << " --- ��������� ���������� ---";
	std::cout << std::endl << "�������� ���������: ";
	std::cout << "{ ";
	for (int i = 0; i < N; i++)

		std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "��������� ����������  ��  " << N << " �� " << M;
	combi::accomodation s(N, M);
	int  n = s.getfirst();
	while (n >= 0)
	{

		std::cout << std::endl << std::setw(2) << s.na << ": { ";

		for (int i = 0; i < 3; i++)

			std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");

		std::cout << "}";

		n = s.getnext();
	};
	std::cout << std::endl << "�����: " << s.count() << std::endl;*/
	//--------------------------------������� 5-6---------------------------------------------------------------
	int d[N][N] = { //0   1    2    3     4        
			   {  0,  45, INF,  25,   50},    //  0
			   { 45,   0,  55,  20,  100},    //  1
			   { 70,  20,   0,  10,   30},    //  2 
			   { 80,  10,  40,   0,   10},    //  3
			   { 30,  50,  20,  10,    0} };   //  4  
	int r[N];                     // ��������� 
	int s = salesman(
		N,          // [in]  ���������� ������� 
		(int*)d,          // [in]  ������ [n*n] ���������� 
		r           // [out] ������ [n] ������� 0 x x x x  

	);
	std::cout << std::endl << "-- ������ ������������ -- ";
	std::cout << std::endl << "-- ����������  �������: " << N;
	std::cout << std::endl << "-- ������� ���������� : ";
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)

			if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";

			else std::cout << std::setw(3) << "INF" << " ";
	}
	std::cout << std::endl << "-- ����������� �������: ";
	for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
	std::cout << std::endl << "-- ����� ��������     : " << s;
	std::cout << std::endl;
	system("pause");
}