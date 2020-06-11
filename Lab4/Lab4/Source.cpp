#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenstein.h"
#include "LCS.h"
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )
using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	//--------������� �1---------------------------
	srand(time(NULL));
	char abc[27]; // ��� �������
	/*char s1[301];
	char s2[251];*/
	// ��������� ������
	for (int i = 97, n = 0; i <= 122; ++i, n++)
	{
		abc[n] = (char)i;
	}
	abc[26] = '\0';
	/*for (int i = 0; i < 300; i++)
	{
		s1[i] = abc[_rand(0, 25)];
	}
	s1[300] = '\0';
	for (int i = 0; i < 250; i++)
	{
		s2[i] = abc[_rand(0, 25)];
	}
	s2[250] = '\0';
	cout << "ABC = " << abc << endl << endl;
	cout << "S1 = " << s1 << endl << endl;
	cout << "S2 = " << s2 << endl << endl;*/
	//--------��������� �����������----------------
	char s1[151], s2[126];
	for (int i = 0; i < 150; i++)
	{
		s1[i] = abc[_rand(0, 25)];
	}
	s1[150] = '\0';
	for (int i = 0; i < 125; i++)
	{
		s2[i] = abc[_rand(0, 25)];
	}
	s2[125] = '\0';
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int lx = sizeof(s1);
	int ly = sizeof(s2);


	int S1_size[]{ 6,8,10,15,30,75,150 };
	int S2_size[]{ 5,6,8,13,25,63,125 };

	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	std::cout << "\n\n-- ���������� ����������� -----";
	std::cout << "\n\n--����� --- �������� -- ���.�������. ---\n";

	for (int i = 0; i < min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(S1_size[i], s1, S2_size[i], s2);
		t2 = clock();

		t3 = clock();
		levenshtein(S1_size[i], s1, S2_size[i], s2);
		t4 = clock();
		cout << right << setw(2) << S1_size[i] << "/" << setw(2) << S2_size[i]
			<< "        " << left << setw(10) << t2 - t1
			<< "   " << setw(10) << t4 - t3 << endl;
	}
	/*clock_t t1 = 0, t2 = 0;
	char X[] = "HRWCYUJ", Y[] = "WLPCAU";
	std::cout << std::endl << "-- ���������� ����� LCS ��� X � Y(��������)";
	std::cout << std::endl << "-- ������������������ X: " << X;
	std::cout << std::endl << "-- ������������������ Y: " << Y;
	t1 = clock();
	int s = lcs(
		sizeof(X) - 1,  // �����   ������������������  X   
		"HRWCYUJ",       // ������������������ X
		sizeof(Y) - 1,  // �����   ������������������  Y
		"WLPCAU"       // ������������������ Y
	);
	t2 = clock();
	std::cout << std::endl << "-- ����� LCS: " << s << std::endl;
	cout << "-- �����������������: " << (t2 - t1) << endl;
	t1 = 0;
	t2 = 0;
	char z[100] = "";
	char x[] = "HRWCYUJ",
		y[] = "WLPCAU";
	t1 = clock();
	int l = lcsd(x, y, z);
	t2 = clock();
	std::cout << std::endl
		<< "-- ���������� ����� �������������������� - LCS(������������ ����������������)" << std::endl;
	std::cout << std::endl << "����������������� X: " << x;
	std::cout << std::endl << "����������������� Y: " << y;
	std::cout << std::endl << "                LCS: " << z;
	std::cout << std::endl << "          ����� LCS: " << l;
	cout << endl << "�����������������: " << (t2 - t1) << endl;
	std::cout << std::endl;*/
	
	system("pause");
}