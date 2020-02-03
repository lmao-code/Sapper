/*
github.com/lmao-code/Sapper

+-------------------------------------------------------------------------------+
| *     *  ***  *   *  ****   ***   *         *  ****  ****  ****   ****  ****  |
| * * * *   *   **  *  *     *      *         *  *     *     *   *  *     *   * |
| *  *  *   *   * * *  ****   ***    *   *   *   ****  ****  ****   ****  ****  |
| *     *   *   *  **  *         *    * * * *    *     *     *      *     * *   |
| *	    *  ***  *   *  ****   ***	   *   *     ****  ****  *      ****  *  *  |
+-------------------------------------------------------------------------------+

*/

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int field_x = 10;
const int field_y = 10;
const int default_size_x = 10;
const int default_size_y = 10;
const int default_complexity = 1;

//English
const string new_game_en = "New game";
const string rules_en = "Rules";
const string exit_en = "Exit";
const string thank_en = "Thank you for the game!";
const string correct_please_en = "Please, enter the correct menu item";

//Russian
const string new_game_ru = "Новая игра";
const string rules_ru = "Правила";
const string exit_ru = "Выход";
const string thank_ru = "Thank you for the game!";
const string correct_please_ru = "Please, enter the correct menu item";

const string logo1 = " +---------------------------------------------------------------------+";
const string logo2 = " | *     * *** *   * ****  ***   *       *  **** **** ****  **** ****  |";
const string logo3 = " | * * * *  *  **  * *    *      *       *  *    *    *   * *    *   * |";
const string logo4 = " | *  *  *  *  * * * ****  ***   *   *   *  **** **** ****  **** ****  |";
const string logo5 = " | *     *  *  *  ** *        *   * * * *   *    *    *     *    * *   |";
const string logo6 = " | *     * *** *   * ****  ***     *   *    **** **** *     **** *  *  |";
const string logo7 = " +---------------------------------------------------------------------+";

int  field[field_y][field_x];
char field_ch[field_y][field_x] = {'*'};

/*
Output:
 ___ ___ ___ ___ ___ ___ ___ ___ ___ ___
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
|   |   |   |   |   |   |   |   |   |   |
|___|___|___|___|___|___|___|___|___|___|
* unknown
@ bomb
*/

void output()
{
	system("cls");
	for (int j = 0; j < field_x; j++)
	{
		cout << " ___";
	}
	cout << " " << endl;
	for (int i = 0; i < field_y; i++)
	{
		for (int j = 0; j < field_x; j++)
		{
			cout << "| " << field_ch[i][j] << " ";
		}
		cout << "|" << endl;
		for (int j = 0; j < field_x; j++)
		{
			cout << "|___";
		}
		cout << "|" << endl;
	}
}

/* int sosed(int y, int x) // процедура считает количество соседей у клетки
{
	int ret = 0;
	int x1 = x - 1, y1 = y - 1;
	int x2 = x, y2 = y - 1;
	int x3 = x + 1, y3 = y - 1;
	int x4 = x - 1, y4 = y;
	int x5 = x + 1, y5 = y;
	int x6 = x - 1, y6 = y + 1;
	int x7 = x, y7 = y + 1;
	int x8 = x + 1, y8 = y + 1;
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
} */

void rules()
{
	cout << "Игра Minesweeper очень проста."                                                     << endl;
	cout << "Число в ячейке показывает, сколько мин скрыто вокруг данной ячейки"                 << endl;
	cout << "Если рядом с открытой ячейкой есть пустая ячейка, то она откроется автоматически"   << endl;
	cout << "Если вы открыли ячейку с миной, то игра проиграна"                                  << endl;
	cout << "Что бы пометить ячейку, в которой находится бомба, нажмите её правой кнопкой мыши"  << endl;
}

void game(bool fast_start)
{
	system("cls");
	int complexity = 0;
	int size_x = 0;
	int sixe_y = 0;
	
	if (fast_start)
	{
		size_x = default_size_x;
		size_y = default_size_y;
		complexity = default_complexity;
	}
	else
	{
		string user_input = "";
		cin >> user_input;
		bool input_correct = false;
		if (user_input == "1") { ret = 1; input_correct = true; }
		if (user_input == "2") { ret = 2; input_correct = true; }
		if (user_input == "3") { ret = 3; input_correct = true; }
		if (user_input == "f") { ret = 4; input_correct = true; }
	
		while (input_correct == false)
		{
			system("cls");
			cout << correct_please_en << endl;
			cout << "1) " << new_game_en << endl;
			cout << "2) " << rules_en << endl;
			cout << "3) " << exit_en << endl;
			user_input = "";
			cin >> user_input;
			if (user_input == "1") { ret = 1; input_correct = true; }
			if (user_input == "2") { ret = 2; input_correct = true; }
			if (user_input == "3") { ret = 3; input_correct = true; }
			if (user_input == "f") { ret = 4; input_correct = true; }
		}
	}	
	string user_input = "";
	int x, y;
	
	output();

}

int menu()
{
	int ret = 3;
	system("cls");
	cout << "1) " << new_game_en << endl;
	cout << "2) " << rules_en    << endl;
	cout << "3) " << exit_en     << endl;

	string user_input = "";
	cin >> user_input;
	bool input_correct = false;
	if (user_input == "1") { ret = 1; input_correct = true; }
	if (user_input == "2") { ret = 2; input_correct = true; }
	if (user_input == "3") { ret = 3; input_correct = true; }
	if (user_input == "f") { ret = 4; input_correct = true; }
	
	while (input_correct == false)
	{
		system("cls");
		cout << correct_please_en << endl;
		cout << "1) " << new_game_en << endl;
		cout << "2) " << rules_en << endl;
		cout << "3) " << exit_en << endl;
		user_input = "";
		cin >> user_input;
		if (user_input == "1") { ret = 1; input_correct = true; }
		if (user_input == "2") { ret = 2; input_correct = true; }
		if (user_input == "3") { ret = 3; input_correct = true; }
		if (user_input == "f") { ret = 4; input_correct = true; }
	}

	return ret;
}

int main() {
	setlocale(LC_ALL, "Russian");

	system("cls");
	cout << logo1 << endl;
	cout << logo2 << endl;
	cout << logo3 << endl;
	cout << logo4 << endl;
	cout << logo5 << endl;
	cout << logo6 << endl;
	cout << logo7 << endl;
	getchar();

	for (int i = 0; i < field_y; i++)
	{
		for (int j = 0; j < field_x; j++)
		{
			field_ch[i][j] = '*';
		}
	}

	output();
	getchar();

	int user_select = menu();
	while (user_select != 3)
	{
		if (user_select == 1) { game(false); }
		if (user_select == 2) { rules(); getchar(); }
		if (user_select == 4) { game(true); }
		user_select = menu();
	}
	system("cls");
	cout << thank_en;
	//sleep(500);
	return 0;
}