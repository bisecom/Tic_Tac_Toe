// SUPER-TIC-TAC-TOE GAME
#include <iostream>
#include <conio.h>
#include <windows.h>
#include<ctime>
#include <stdlib.h>

using namespace std;

static char game_arr[10] = "789456123";
bool player = 1;
char user_name_1[20], user_name_2[20];
char* p_user_name_1 = &user_name_1[20];
char* p_user_name_2 = &user_name_2[20];
char enter_check;

void first_win();
void first_win_pc();
void second_win();
void second_win_pc();
void draw();
char* users_naming(char* p_user_name_1, char* p_user_name_2);
void test_win();
void write(char arr[]);
void step_pc();
void step_users();
void operate_game_pc();
void operate_game_users();

int main()
{
	//srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("title СУПЕР КРЕСТИКИ-НОЛИКИ");
	setlocale(LC_ALL, "Russian");
	cout << "...ПРИВЕТ! ВАС ПРИВЕТСТВУЕТ ИГРА..." << endl;
	cout << "=====================================" << endl;
	cout << "-x-x-x--СУПЕР-КРЕСТИКИ-НОЛИКИ--o-o-o-" << endl;
	cout << "=====================================" << endl << endl;
	Sleep(3000);
	system("cls");
	cout << "---------------------------------------------------------------" << endl;
	cout << "ЧТОБЫ СРАЗИТЬСЯ ИГРОК ПРОТИВ ИГРОКА, ВВЕДИТЕ - 1, " << endl;
	cout << "ЧТОБЫ СРАЗИТЬСЯ ПРОТИВ ИСКУССТЕННОГО ИНТЕЛЛЕКТА, ВВЕДИТЕ - 2: ";
	cout << "\n---------------------------------------------------------------" << endl;
	for (;;)
	{
		cin >> enter_check;
		if (enter_check == '1' || enter_check == '2') { break; }
		else { cout << "ПОЖАЛУЙСТА, ВВЕДИТЕ КОРРЕКТНОЕ ЗНАЧЕНИЕ!" << endl; }
	}
	system("cls");
	switch (enter_check)
	{
	case '1':
	{
		cout << "=====================================" << endl;
		cout << "-x-x-x--СУПЕР-КРЕСТИКИ-НОЛИКИ--o-o-o-" << endl;
		cout << "=====================================" << endl << endl;
		users_naming(p_user_name_1, p_user_name_2);
		Sleep(1500);
		system("cls");
		operate_game_users();
		break;
	}
	case '2':
	{
		operate_game_pc();
		break;
	}

	}

	system("pause");
	return 0;
}



void first_win()
{
	cout << "ПОБЕДА ПЕРВОГО ИГРОКА (X)!!!" << endl;
	printf("%s", &user_name_1);
	cout << "," << " ПОЗДРАВЛЯЕМ ВАС!" << endl;
	system("pause >nul");
	exit(0);
}

void first_win_pc()
{
	cout << "ПОЗДРАВЛЯЕМ ВАС, ВЫ ПОБЕДИЛИ (X)!!!" << endl;
	system("pause >nul");
	exit(0);
}

void second_win()
{
	cout << "ПОБЕДА ВТОРОГО ИГРОКА (0)!!!" << endl;
	printf("%s", &user_name_2);
	cout << "," << " ПОЗДРАВЛЯЕМ ВАС!" << endl;
	system("pause >nul");
	exit(0);
}

void second_win_pc()
{
	cout << "К СОЖАЛЕНИЮ И В ЭТОТ РАЗ," << endl;
	cout << "ПОБЕДА ЗА ИСКУССТВЕННЫМ ИНТЕЛЕКТОМ (0)!!!" << endl;
	system("pause >nul");
	exit(0);
}

void draw()
{
	cout << "В ЭТОТ РАЗ, НИЧЬЯ!!!" << endl;
	system("pause >nul");
	exit(0);
}

char* users_naming(char* p_user_name_1, char* p_user_name_2)
{
	cout << "ПОЖАЛУЙСТА, ВВЕДИТЕ ИМЯ ИГРОКА(Х) № 1: " << endl;
	cin >> user_name_1;
	cout << "ПОЖАЛУЙСТА, ВВЕДИТЕ ИМЯ ИГРОКА(O) № 2: " << endl;
	cin >> user_name_2;
	_strupr_s(user_name_1);
	_strupr_s(user_name_2);

	return user_name_1;
	return user_name_2;
}

void test_win()
{
	for (int i = 0; i < 3; ++i)
	{
		if (game_arr[i] == 'X' && game_arr[i + 3] == 'X' && game_arr[i + 6] == 'X' && enter_check == '1')
			first_win();
		if (game_arr[i] == 'X' && game_arr[i + 3] == 'X' && game_arr[i + 6] == 'X' && enter_check == '2')
			first_win_pc();
	}
	for (int i = 0; i < 9; i += 3)
	{
		if (game_arr[i] == 'X' && game_arr[i + 1] == 'X' && game_arr[i + 2] == 'X' && enter_check == '1')
			first_win();
		if (game_arr[i] == 'X' && game_arr[i + 1] == 'X' && game_arr[i + 2] == 'X' && enter_check == '2')
			first_win_pc();
	}
	for (int i = 0; i < 3; ++i)
	{
		if (game_arr[i] == 'O' && game_arr[i + 3] == 'O' && game_arr[i + 6] == 'O' && enter_check == '1')
			second_win();
		if (game_arr[i] == 'O' && game_arr[i + 3] == 'O' && game_arr[i + 6] == 'O' && enter_check == '2')
			second_win_pc();
	}
	for (int i = 0; i < 9; i += 3)
	{
		if (game_arr[i] == 'O' && game_arr[i + 1] == 'O' && game_arr[i + 2] == 'O' && enter_check == '1')
			second_win();
		if (game_arr[i] == 'O' && game_arr[i + 1] == 'O' && game_arr[i + 2] == 'O' && enter_check == '2')
			second_win_pc();
	}
	if (game_arr[0] == 'X' && game_arr[4] == 'X' && game_arr[8] == 'X' && enter_check == '1')
		first_win();
	if (game_arr[0] == 'X' && game_arr[4] == 'X' && game_arr[8] == 'X' && enter_check == '2')
		first_win_pc();
	if (game_arr[0] == 'O' && game_arr[4] == 'O' && game_arr[8] == 'O' && enter_check == '1')
		second_win();
	if (game_arr[0] == 'O' && game_arr[4] == 'O' && game_arr[8] == 'O' && enter_check == '2')
		second_win_pc();
	if (game_arr[2] == 'X' && game_arr[4] == 'X' && game_arr[6] == 'X' && enter_check == '1')
		first_win();
	if (game_arr[2] == 'X' && game_arr[4] == 'X' && game_arr[6] == 'X' && enter_check == '2')
		first_win_pc();
	if (game_arr[2] == 'O' && game_arr[4] == 'O' && game_arr[6] == 'O' && enter_check == '1')
		second_win();
	if (game_arr[2] == 'O' && game_arr[4] == 'O' && game_arr[6] == 'O' && enter_check == '2')
		second_win_pc();

	if ((game_arr[0] == 'X' || game_arr[0] == 'O') && (game_arr[1] == 'X' || game_arr[1] == 'O') &&
		(game_arr[2] == 'X' || game_arr[2] == 'O') && (game_arr[3] == 'X' || game_arr[3] == 'O') &&
		(game_arr[4] == 'X' || game_arr[4] == 'O') && (game_arr[5] == 'X' || game_arr[5] == 'O') &&
		(game_arr[6] == 'X' || game_arr[6] == 'O') && (game_arr[7] == 'X' || game_arr[7] == 'O') &&
		(game_arr[8] == 'X' || game_arr[8] == 'O')) draw();


}

void write(char arr[])
{
	cout << "=====================================" << endl;
	cout << "-x-x-x--СУПЕР-КРЕСТИКИ-НОЛИКИ--o-o-o-" << endl;
	cout << "=====================================" << endl << endl;
	for (int i = 0; i < 9; i += 3)
	{
		cout << "          " << arr[i] << "      " << arr[i + 1] << "      " << arr[i + 2] << endl << endl << endl;
	}
	cout << "=====================================" << endl;
	cout << "-x-x-x-x-x-x-x-x-x-o-o-o-o-o-o-o-o-o-" << endl;
	cout << "=====================================" << endl;
}

void step_pc()
{
	int newstep;
	srand(time(NULL));
	if (player)
	{
		cout << "ХОД ЗА ВАМИ (X): ";
		cin >> newstep;
		if (newstep >= 4 && newstep <= 6 && game_arr[newstep - 1] != 'X' && game_arr[newstep - 1] != 'O')
		{
			game_arr[newstep - 1] = 'X';
			player = !player;
		}
		else if (newstep >= 7 && newstep <= 9 && game_arr[newstep - 7] != 'X' && game_arr[newstep - 7] != 'O')
		{
			game_arr[newstep - 7] = 'X';
			player = !player;
		}
		else if (newstep >= 1 && newstep <= 3 && game_arr[newstep + 5] != 'X' && game_arr[newstep + 5] != 'O')
		{
			game_arr[newstep + 5] = 'X';
			player = !player;
		}

		else {
			cout << "\nЗДЕСЬ УЖЕ ЗАНЯТО!\n";
			system("pause >nul");
		}
	}
	else
	{
		cout << "ХОД ЗА ИСКУССТВЕННЫМ ИНТЕЛЕКТОМ (0): ";
		Sleep(1000);
		// #1 condition
		if (game_arr[4] != 'X' && game_arr[4] != 'O')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		//#2 condition
		else if (game_arr[0] == 'O' && game_arr[3] == 'O' && game_arr[6] != 'X')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'O' && game_arr[4] == 'O' && game_arr[7] != 'X')
		{
			game_arr[7] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'O' && game_arr[5] == 'O' && game_arr[8] != 'X')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'O' && game_arr[6] == 'O' && game_arr[0] != 'X')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		else if (game_arr[4] == 'O' && game_arr[7] == 'O' && game_arr[1] != 'X')
		{
			game_arr[1] = 'O';
			player = !player;
		}
		else if (game_arr[5] == 'O' && game_arr[8] == 'O' && game_arr[2] != 'X')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'O' && game_arr[1] == 'O' && game_arr[2] != 'X')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'O' && game_arr[4] == 'O' && game_arr[5] != 'X')
		{
			game_arr[5] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'O' && game_arr[7] == 'O' && game_arr[8] != 'X')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'O' && game_arr[2] == 'O' && game_arr[0] != 'X')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		else if (game_arr[4] == 'O' && game_arr[5] == 'O' && game_arr[3] != 'X')
		{
			game_arr[3] = 'O';
			player = !player;
		}
		else if (game_arr[7] == 'O' && game_arr[8] == 'O' && game_arr[6] != 'X')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'O' && game_arr[4] == 'O' && game_arr[2] != 'X')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'O' && game_arr[4] == 'O' && game_arr[6] != 'X')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'O' && game_arr[4] == 'O' && game_arr[8] != 'X')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[8] == 'O' && game_arr[4] == 'O' && game_arr[0] != 'X')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		// to get inside
		else if (game_arr[0] == 'O' && game_arr[6] == 'O' && game_arr[3] != 'X')
		{
			game_arr[3] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'O' && game_arr[7] == 'O' && game_arr[4] != 'X')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'O' && game_arr[8] == 'O' && game_arr[5] != 'X')
		{
			game_arr[5] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'O' && game_arr[2] == 'O' && game_arr[1] != 'X')
		{
			game_arr[1] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'O' && game_arr[5] == 'O' && game_arr[4] != 'X')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'O' && game_arr[8] == 'O' && game_arr[7] != 'X')
		{
			game_arr[7] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'O' && game_arr[8] == 'O' && game_arr[4] != 'X')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'O' && game_arr[2] == 'O' && game_arr[4] != 'X')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		//#3 condition
		else if (game_arr[0] == 'X' && game_arr[1] == 'X' && game_arr[2] != 'O')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'X' && game_arr[4] == 'X' && game_arr[5] != 'O')
		{
			game_arr[5] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'X' && game_arr[7] == 'X' && game_arr[8] != 'O')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'X' && game_arr[2] == 'X' && game_arr[0] != 'O')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		else if (game_arr[4] == 'X' && game_arr[5] == 'X' && game_arr[3] != 'O')
		{
			game_arr[3] = 'O';
			player = !player;
		}
		else if (game_arr[7] == 'X' && game_arr[8] == 'X' && game_arr[6] != 'O')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'X' && game_arr[3] == 'X' && game_arr[6] != 'O')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'X' && game_arr[4] == 'X' && game_arr[7] != 'O')
		{
			game_arr[7] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'X' && game_arr[5] == 'X' && game_arr[8] != 'O')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'X' && game_arr[6] == 'X' && game_arr[0] != 'O')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		else if (game_arr[4] == 'X' && game_arr[7] == 'X' && game_arr[1] != 'O')
		{
			game_arr[1] = 'O';
			player = !player;
		}
		else if (game_arr[5] == 'X' && game_arr[8] == 'X' && game_arr[2] != 'O')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'X' && game_arr[4] == 'X' && game_arr[8] != 'O')
		{
			game_arr[8] = 'O';
			player = !player;
		}
		else if (game_arr[8] == 'X' && game_arr[4] == 'X' && game_arr[0] != 'O')
		{
			game_arr[0] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'X' && game_arr[8] == 'X' && game_arr[4] != 'O')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'X' && game_arr[4] == 'X' && game_arr[2] != 'O')
		{
			game_arr[2] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'X' && game_arr[4] == 'X' && game_arr[6] != 'O')
		{
			game_arr[6] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'X' && game_arr[6] == 'X' && game_arr[4] != 'O')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'X' && game_arr[6] == 'X' && game_arr[3] != 'O')
		{
			game_arr[3] = 'O';
			player = !player;
		}
		else if (game_arr[1] == 'X' && game_arr[7] == 'X' && game_arr[4] != 'O')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[2] == 'X' && game_arr[8] == 'X' && game_arr[5] != 'O')
		{
			game_arr[5] = 'O';
			player = !player;
		}
		else if (game_arr[0] == 'X' && game_arr[2] == 'X' && game_arr[1] != 'O')
		{
			game_arr[1] = 'O';
			player = !player;
		}
		else if (game_arr[3] == 'X' && game_arr[5] == 'X' && game_arr[4] != 'O')
		{
			game_arr[4] = 'O';
			player = !player;
		}
		else if (game_arr[6] == 'X' && game_arr[8] == 'X' && game_arr[7] != 'O')
		{
			game_arr[7] = 'O';
			player = !player;
		}

		//#4 condition
		else if (game_arr[4] == 'X')

		{
			int counter = 0, random_numb = 0;
			for (int i = 0; i < 9; i++)
			{
				//if (game_arr[4] == 'X') continue;
				if (game_arr[i] != 'X' && game_arr[i] != 'O')
					counter++;
			}
			if (counter == 8)
				random_numb = rand() % 9;
			if (random_numb == 4)
			{
				random_numb++;
				game_arr[random_numb] = 'O';
				player = !player;
			}
			if (random_numb != 4)
			{
				game_arr[random_numb] = 'O';
				player = !player;
			}
		}
		//#5 condition
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (game_arr[i] != 'X' && game_arr[i] != 'O')
				{
					game_arr[i] = 'O';
					break;
				}

			}
			player = !player;
		}

	}

}

void step_users()
{
	int newstep;
	if (player)
	{
		printf("%s", &user_name_1);
		cout << "!" << " ХОД ЗА ВАМИ (X): ";
		cin >> newstep;
		if (newstep >= 4 && newstep <= 6 && game_arr[newstep - 1] != 'X' && game_arr[newstep - 1] != 'O')
		{
			game_arr[newstep - 1] = 'X';
			player = !player;
		}
		else if (newstep >= 7 && newstep <= 9 && game_arr[newstep - 7] != 'X' && game_arr[newstep - 7] != 'O')
		{
			game_arr[newstep - 7] = 'X';
			player = !player;
		}
		else if (newstep >= 1 && newstep <= 3 && game_arr[newstep + 5] != 'X' && game_arr[newstep + 5] != 'O')
		{
			game_arr[newstep + 5] = 'X';
			player = !player;
		}

		else {
			cout << "\nЗДЕСЬ УЖЕ ЗАНЯТО!\n";
			system("pause >nul");
		}
	}
	else
	{
		printf("%s", &user_name_2);
		cout << "!" << " ХОД ЗА ВАМИ (O): ";
		cin >> newstep;
		if (newstep >= 4 && newstep <= 6 && game_arr[newstep - 1] != 'X' && game_arr[newstep - 1] != 'O')
		{
			game_arr[newstep - 1] = 'O';
			player = !player;
		}
		else if (newstep >= 7 && newstep <= 9 && game_arr[newstep - 7] != 'X' && game_arr[newstep - 7] != 'O')
		{
			game_arr[newstep - 7] = 'O';
			player = !player;
		}
		else if (newstep >= 1 && newstep <= 3 && game_arr[newstep + 5] != 'X' && game_arr[newstep + 5] != 'O')
		{
			game_arr[newstep + 5] = 'O';
			player = !player;
		}

		else {
			cout << "ЗДЕСЬ УЖЕ ЗАНЯТО!\n";
			system("pause >nul");
		}
	}
}

void operate_game_pc()
{

	while (true)
	{
		write(game_arr);
		test_win();
		step_pc();
		system("cls");
	}
}

void operate_game_users()
{

	while (true)
	{
		write(game_arr);
		test_win();
		step_users();
		system("cls");
	}
}
