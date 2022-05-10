
#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	char M[3][3] = {
				   { ' ', ' ', ' ' },
				   { ' ', ' ', ' ' },
				   { ' ', ' ', ' ' }
								   };	
	char Bar[5][5] = {
				   { '|', '|' },
				   { '-', '|', '-', '|', '-' },
				   { '|', '|' },
				   { '-', '|', '-', '|', '-' },
				   { '|', '|' }
	};
	int a;
	int b;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool player = false;
	bool bot = false;

	cout << endl;

	while (player == bot) {
		SetConsoleCursorPosition(h, { 0, 1 });
		for (int i = 0; i < 5; i++)
		{
			cout << "  ";
			if (i % 2 != 0)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << Bar[i][j] << " ";
				}
				cout << endl;
				continue;
			}
			for (int j = 0; j < 3; j++)
			{
				cout << M[i / 2][j] << " ";
				cout << Bar[i][j] << " ";
			}
			cout << endl;
		}

		cout << "Enter column and row (without space): " << endl;
		while (1)
		{
			cin >> a;
			SetConsoleCursorPosition(h, { 0, 7 });
			cout << "  ";

			if (M[(a % 10) - 1][(a / 10) - 1] == ' ')
			{
				M[(a % 10) - 1][(a / 10) - 1] = 'X';
				SetConsoleCursorPosition(h, { 0, 9 });
				cout << "           ";
				break;
			}
			else
			{
				SetConsoleCursorPosition(h, { 0, 9 });
				cout << "Wrong value";
				SetConsoleCursorPosition(h, { 0, 7 });
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (M[i][0] == M[i][1] && M[i][1] == 'X' && M[i][1] == M[i][2])
			{
				player = true;
			}
			if (M[0][i] == M[1][i] && M[1][i] == 'X' && M[1][i] == M[2][i])
			{
				player = true;
			}
		}
		if (M[0][0] == M[1][1] && M[1][1] == 'X' && M[1][1] == M[2][2])
		{
			player = true;
		}
		if (M[0][2] == M[1][1] && M[1][1] == 'X' && M[1][1] == M[2][0])
		{
			player = true;
		}
		if (player == true)
		{
			SetConsoleCursorPosition(h, { 0, 1 });
			for (int i = 0; i < 5; i++)
			{
				cout << "  ";
				if (i % 2 != 0)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << Bar[i][j] << " ";
					}
					cout << endl;
					continue;
				}
				for (int j = 0; j < 3; j++)
				{
					cout << M[i / 2][j] << " ";
					cout << Bar[i][j] << " ";
				}
				cout << endl;
			}
			SetConsoleCursorPosition(h, { 0, 9 });
			cout << "Player WIN" << endl;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (M[i][j] == ' ')
				{
					a = -1;
					break;
				}

			}
			if (a == -1)
			{
				break;
			}
		}
		if (a != -1 && player != true)
			{
				SetConsoleCursorPosition(h, { 0, 1 });
				for (int i = 0; i < 5; i++)
				{
					cout << "  ";
					if (i % 2 != 0)
					{
						for (int j = 0; j < 5; j++)
						{
							cout << Bar[i][j] << " ";
						}
						cout << endl;
						continue;
					}
					for (int j = 0; j < 3; j++)
					{
						cout << M[i / 2][j] << " ";
						cout << Bar[i][j] << " ";
					}
					cout << endl;
				}
				SetConsoleCursorPosition(h, { 0, 9 });
				cout << "DRAW" << endl;
				a = -2;
				break;
			}
		while (1)
		{
			a = rand() % 3;
			b = rand() % 3;
			if (M[a][b] == ' ')
			{
				M[a][b] = 'O';
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (M[i][0] == M[i][1] && M[i][1] == 'O' && M[i][1] == M[i][2])
			{
				bot = true;
			}
			if (M[0][i] == M[1][i] && M[1][i] == 'O' && M[1][i] == M[2][i])
			{
				bot = true;
			}
		}
		if (M[0][0] == M[1][1] && M[1][1] == 'O' && M[1][1] == M[2][2])
		{
			bot = true;
		}
		if (M[0][2] == M[1][1] && M[1][1] == 'O' && M[1][1] == M[2][0])
		{
			bot = true;
		}
		if (bot == true)
		{
			SetConsoleCursorPosition(h, { 0, 1 });
			for (int i = 0; i < 5; i++)
			{
				cout << "  ";
				if (i % 2 != 0)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << Bar[i][j] << " ";
					}
					cout << endl;
					continue;
				}
				for (int j = 0; j < 3; j++)
				{
					cout << M[i / 2][j] << " ";
					cout << Bar[i][j] << " ";
				}
				cout << endl;
			}
			SetConsoleCursorPosition(h, { 0, 9 });
			cout << "Bot WIN" << endl;
		}
	}

	system("pause");
	return 0;
}
