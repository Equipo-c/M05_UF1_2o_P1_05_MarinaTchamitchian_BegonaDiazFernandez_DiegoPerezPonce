#include <iostream>
#include <windows.h>  
#include <stdio.h>
#include <conio.h>


using namespace std;

#define CONSOLE_HEIGHT 15
#define CONSOLE_WIDTH 40

enum MAP_TILES { WALL = '#', EMPTY = ' ', PUNTOS = '.' };

MAP_TILES mapa[CONSOLE_HEIGHT][CONSOLE_WIDTH];

enum USER_INPUT { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
char player = 'O';
//int j = 0;
USER_INPUT input = USER_INPUT::NONE;
bool run = true;

int player_x = 19;
int player_y = 14;

int mapa_puntos = 0;
int player_puntos = 0;

/*HANDLE  hConsole;
int k;*/
int backcolor = 0;
//int playerColor = 1;

void setCColor(int color)
{
	static HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color | (backcolor * 0x10 + 0x100));
}
//colores para escoger
int color[7] = {
	  0x009,
	  0x00E,
	  0x00C,
	  0x002,
	  0x00B,
	  0x005,
	  0x00F

};

void Inicializar() {

	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if ((i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1))
			{

				mapa[i][j] = MAP_TILES::WALL;

			}

			else if (i == 6 || i == CONSOLE_HEIGHT - 6 || j == 14 || j == CONSOLE_WIDTH - 11) {
				mapa[i][j] = MAP_TILES::PUNTOS;

				mapa_puntos++;
			}
			else {
				//else if (i == 3 || i == CONSOLE_HEIGHT - 3 || j == 4 || j == CONSOLE_WIDTH - 5) {
				mapa[i][j] = MAP_TILES::EMPTY;



			}

		}
	}

	//PARED IZQUIERDA
	mapa[6][0] = MAP_TILES::EMPTY;
	mapa[7][0] = MAP_TILES::EMPTY;
	//PARED DERECHA
	mapa[6][39] = MAP_TILES::EMPTY;
	mapa[7][39] = MAP_TILES::EMPTY;
	//PARED ARRIBA
	mapa[0][16] = MAP_TILES::EMPTY;
	mapa[0][17] = MAP_TILES::EMPTY;
	mapa[0][18] = MAP_TILES::EMPTY;
	mapa[0][19] = MAP_TILES::EMPTY;
	mapa[0][20] = MAP_TILES::EMPTY;
	//PARED ABAJO
	mapa[14][16] = MAP_TILES::EMPTY;
	mapa[14][17] = MAP_TILES::EMPTY;
	mapa[14][18] = MAP_TILES::EMPTY;
	mapa[14][19] = MAP_TILES::EMPTY;
	mapa[14][20] = MAP_TILES::EMPTY;



	mapa[13][15] = MAP_TILES::WALL;
	mapa[12][15] = MAP_TILES::WALL;
	mapa[13][21] = MAP_TILES::WALL;
	mapa[12][21] = MAP_TILES::WALL;


	mapa[2][3] = MAP_TILES::WALL;

	mapa[2][35] = MAP_TILES::WALL;
	mapa[2][34] = MAP_TILES::WALL;
	mapa[3][34] = MAP_TILES::WALL;
	mapa[3][35] = MAP_TILES::WALL;
	mapa[2][33] = MAP_TILES::WALL;



	mapa[2][4] = MAP_TILES::WALL;
	mapa[2][5] = MAP_TILES::WALL;
	mapa[2][6] = MAP_TILES::WALL;
	mapa[2][7] = MAP_TILES::WALL;
	mapa[3][5] = MAP_TILES::WALL;
	mapa[3][6] = MAP_TILES::WALL;
	mapa[3][3] = MAP_TILES::WALL;
	mapa[3][4] = MAP_TILES::WALL;


	mapa[3][7] = MAP_TILES::WALL;
	mapa[5][2] = MAP_TILES::WALL;
	mapa[5][3] = MAP_TILES::WALL;
	mapa[5][1] = MAP_TILES::WALL;

	mapa[8][1] = MAP_TILES::WALL;
	mapa[8][2] = MAP_TILES::WALL;
	mapa[8][3] = MAP_TILES::WALL;

	mapa[8][38] = MAP_TILES::WALL;
	mapa[8][37] = MAP_TILES::WALL;
	mapa[8][36] = MAP_TILES::WALL;

	mapa[5][38] = MAP_TILES::WALL;
	mapa[5][37] = MAP_TILES::WALL;
	mapa[5][36] = MAP_TILES::WALL;

	mapa[1][15] = MAP_TILES::WALL;
	mapa[1][21] = MAP_TILES::WALL;

	mapa[2][15] = MAP_TILES::WALL;
	mapa[2][21] = MAP_TILES::WALL;
	mapa[2][32] = MAP_TILES::WALL;
	mapa[2][31] = MAP_TILES::WALL;
	mapa[3][32] = MAP_TILES::WALL;
	mapa[3][31] = MAP_TILES::WALL;
	mapa[3][33] = MAP_TILES::WALL;

	mapa[12][5] = MAP_TILES::WALL;
	mapa[12][6] = MAP_TILES::WALL;
	mapa[12][7] = MAP_TILES::WALL;
	mapa[12][8] = MAP_TILES::WALL;
	mapa[11][5] = MAP_TILES::WALL;
	mapa[10][5] = MAP_TILES::WALL;

	mapa[7][9] = MAP_TILES::WALL;
	mapa[7][10] = MAP_TILES::WALL;
	mapa[7][11] = MAP_TILES::WALL;

	mapa[12][30] = MAP_TILES::WALL;
	mapa[11][30] = MAP_TILES::WALL;
	mapa[10][30] = MAP_TILES::WALL;
	//mapa[9][30] = MAP_TILES::WALL;

	//mapa[6][20] = MAP_TILES::WALL;
	mapa[7][20] = MAP_TILES::WALL;
	mapa[8][20] = MAP_TILES::WALL;

	mapa[8][10] = MAP_TILES::WALL;
	mapa[7][10] = MAP_TILES::WALL;
	//mapa[9][10] = MAP_TILES::WALL;
	//mapa[9][10] = MAP_TILES::WALL;

	mapa[7][18] = MAP_TILES::WALL;
	mapa[7][19] = MAP_TILES::WALL;
	mapa[7][20] = MAP_TILES::WALL;
	mapa[7][22] = MAP_TILES::WALL;
	mapa[7][21] = MAP_TILES::WALL;
	mapa[7][23] = MAP_TILES::WALL;
	mapa[7][24] = MAP_TILES::WALL;
	mapa[7][25] = MAP_TILES::WALL;
	mapa[7][26] = MAP_TILES::WALL;
	mapa[7][27] = MAP_TILES::WALL;

	mapa[5][20] = MAP_TILES::WALL;
	mapa[4][20] = MAP_TILES::WALL;

}
void Input() {
	char tempInput;
	cin >> tempInput;
	switch (tempInput)
	{
	case 'W':
	case 'w':
		input = USER_INPUT::UP;

		break;
	case 'S':
	case 's':
		input = USER_INPUT::DOWN;
		break;
	case 'D':
	case 'd':
		input = USER_INPUT::RIGHT;
		break;
	case 'A':
	case 'a':
		input = USER_INPUT::LEFT;
		break;
	case 'q':
	case 'Q':
		input = USER_INPUT::QUIT;
		break;
	default:
		input = USER_INPUT::NONE;
		break;
	}
}

void logic() {
	int newPos_y = player_y;
	int newPos_x = player_x;


	switch (input)
	{
	case UP:
		newPos_y--;
		break;
	case DOWN:
		newPos_y++;
		break;
	case RIGHT:
		newPos_x++;
		break;
	case LEFT:
		newPos_x--;
		break;
	case QUIT:
		run = false;
		break;
	}

	//volver al otro lado de la pantalla cuando cruzas un limite
	if (newPos_y < 0) {
		newPos_y = CONSOLE_HEIGHT - 1;
	}

	if (newPos_x < 0) {
		newPos_x = CONSOLE_WIDTH - 1;
	}

	newPos_y %= CONSOLE_HEIGHT;
	newPos_x %= CONSOLE_WIDTH;

	if (mapa[newPos_y][newPos_x] == MAP_TILES::WALL)
	{
		newPos_y = player_y;
		newPos_x = player_x;
	}
	else if (mapa[newPos_y][newPos_x] == MAP_TILES::PUNTOS) {
		mapa_puntos--;
		player_puntos++;
		mapa[newPos_y][newPos_x] = MAP_TILES::EMPTY;
	}

	player_x = newPos_x;

	player_y = newPos_y;

	if (mapa_puntos <= 0)
	{
		cout << "BIEN HECHO" << endl;
		cout << "Pulsa 'Q' para salir" << endl;
		system("PAUSE");
	}
}
void Draw() {
	system("CLS"); //limpiar la pantalla
	
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			cout << (char)mapa[i][j];
			if (player_x == j && player_y == i) {
				//playerColor;
				cout << player;
			}
			else 
			{  //pintar el mapa de diferentes colores
				if (mapa[j][i] == WALL)
				{
					setCColor(color[0]);

				}
				else if (mapa[j][i] == PUNTOS)
				{
					setCColor(color[2]);
				}
			}
		}
		cout << endl;
	}

	/*hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);*/
	//system("Color DE");

	cout << "SCORE:" << player_puntos << endl;
	cout << "LEFT TO COLLECT:" << mapa_puntos << endl;
	cout << "Movments (w, s, d, a):" << endl;
}

int main()
{

	Inicializar();
	while (run)
	{
		//sin Enter
		/*while (_kbhit())
		{
			input = _getch();*/

			Input();
			logic();
			Draw();
		//}
	}
}