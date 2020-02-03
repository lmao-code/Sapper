
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include <string>
#include <fstream>

using namespace std;

const int xx = 60; // размеры поля
const int yy = 25;

char life[yy][xx]; // массивы для хранение поля и его временной копии
char cop[yy][xx];

int sosed(int y, int x) // процедура считает количество соседей у клетки
{
	int ret = 0;
	int x1 = x - 1,   y1 = y - 1;
	int x2 = x,       y2 = y - 1;
	int x3 = x + 1,   y3 = y - 1;
	int x4 = x - 1,   y4 = y;
	int x5 = x + 1,   y5 = y;
	int x6 = x - 1,   y6 = y + 1;
	int x7 = x,       y7 = y + 1;
	int x8 = x + 1,   y8 = y + 1;

	if (x1 == -1) x1 = xx - 1;
	if (x2 == -1) x2 = xx - 1;
	if (x3 == -1) x3 = xx - 1;
	if (x4 == -1) x4 = xx - 1;
	if (x5 == -1) x5 = xx - 1;
	if (x6 == -1) x6 = xx - 1;
	if (x7 == -1) x7 = xx - 1;
	if (x8 == -1) x8 = xx - 1;

	if (x1 == xx) x1 = 0;
	if (x2 == xx) x2 = 0;
	if (x3 == xx) x3 = 0;
	if (x4 == xx) x4 = 0;
	if (x5 == xx) x5 = 0;
	if (x6 == xx) x6 = 0;
	if (x7 == xx) x7 = 0;
	if (x8 == xx) x8 = 0;

	if (y1 == -1) y1 = yy - 1;
	if (y2 == -1) y2 = yy - 1;
	if (y3 == -1) y3 = yy - 1;
	if (y4 == -1) y4 = yy - 1;
	if (y5 == -1) y5 = yy - 1;
	if (y6 == -1) y6 = yy - 1;
	if (y7 == -1) y7 = yy - 1;
	if (y8 == -1) y8 = yy - 1;

	if (y1 == yy) y1 = 0;
	if (y2 == yy) y2 = 0;
	if (y3 == yy) y3 = 0;
	if (y4 == yy) y4 = 0;
	if (y5 == yy) y5 = 0;
	if (y6 == yy) y6 = 0;
	if (y7 == yy) y7 = 0;
	if (y8 == yy) y8 = 0;

	if (life[y1][x1] == '+') ret++;
	if (life[y2][x2] == '+') ret++;
	if (life[y3][x3] == '+') ret++;
	if (life[y4][x4] == '+') ret++;
	if (life[y5][x5] == '+') ret++;
	if (life[y6][x6] == '+') ret++;
	if (life[y7][x7] == '+') ret++;
	if (life[y8][x8] == '+') ret++;

	return ret;
}

void outt() // вывод текущего поля на экран
{
	string S = "";
	for (int i = 0; i < yy; i++)
	{
		for (int j = 0; j < xx; j++)
		{
			S += life[i][j];
			//S += ' ';
		}
		S += '\n';
	}
	cout << S;
}

int main()
{
	ifstream fin; // ввод из файла
	fin.open("input.txt");

	for (int i = 0; i < yy; i++) // считываем исходное сосотояние поля из файла
	{
		for (int j = 0; j < xx; j++)
		{
			fin >> life[i][j];
		}
	}

	while (true) //основной цикл         !!!! цикл бесконечный !!!!
	{

		system("cls"); // очистка экрана

		outt(); // вывод текущего состояния

		//getchar();  // переход к следующему состоянию по нажатию кнопки или по таймеру
		Sleep(50);

		for (int i = 0; i < yy; i++) // запись нового поколения в массив-копию, выполнение правил игры
		{
			for (int j = 0; j < xx; j++)
			{
				if (life[i][j] == '-')
				{
					if (sosed(i, j) == 3)
					{
						cop[i][j] = '+';
					}
					else
					{
						cop[i][j] = '-';
					}
				}
				else
				{
					if (sosed(i, j) == 2 || sosed(i, j) == 3)
					{
						cop[i][j] = '+';
					}
					else
					{
						cop[i][j] = '-';
					}
				}
			}
		}

		for (int i = 0; i < yy; i++) // вносим изменения в основной массив
		{
			for (int j = 0; j < xx; j++)
			{
				life[i][j] = cop[i][j];
			}
		}

	}

	return 0;
}
