/*

github.com/lmao-code/Sapper



@2020

*/

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

const int field_x = 50;
const int field_y = 50;

//English
const string new_game_en = "New game";
const string rules_en    = "Rules";
const string exit_en     = "Exit";
const string thank_en    = "Thank you for the game!";
const string correct_please_en = "Please, enter the correct menu item";

//Russian
const string new_game_ru = "Новая игра";
const string rules_ru    = "Правила";
const string exit_ru     = "Выход";



int field[field_y][field_x];

void output()
{
	
}

void rules()
{
}

void game()
{
}

int menu();
{
	int ret = 3;
	bool select_correct = false;
	system("crt");
	cout << "1) " << new_game_en;
	cout << "2) " << rules_en;
	cout << "3) " << exit_en;
	string user_select = "";
	cin >> user_select;
	if (user_select == "1") {ret = 1; select_correct = true}
	if (user_select == "2") {ret = 2; select_correct = true}
	if (user_select == "3") {ret = 3; select_correct = true}
	while (select_correct == false)
	{
		system("crt");
		cout << correct_please_en << endl;
		cout << "1) " << new_game_en;
		cout << "2) " << rules_en;
		cout << "3) " << exit_en;
		string user_select = "";
		cin >> user_select;
		if (user_select == "1") {ret = 1; select_correct = true}
		if (user_select == "2") {ret = 2; select_correct = true}
		if (user_select == "3") {ret = 3; select_correct = true}
	}
	reurn ret;
}

int main() {
	cout << logo;
	while (int user_select = menu(); user_select != 3)
	{
		if (user_select == 1) game();
		if (user_select == 2) rules();
	}
	system("cls");
	cout << thank_en;
	sleep(500);
	return 0;
}