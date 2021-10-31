#include <iostream>
#include <windows.h>  
using namespace std;

#define CONSOLE_HEIGHT 10
#define CONSOLE_WIDTH 10

enum MAP_TILES { WALL = '#', EMPTY = ' ', POINT = '.' };
MAP_TILES mapa[CONSOLE_HEIGHT][CONSOLE_WIDTH];

enum USER_INPUT { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
char player = 'O';
//int j = 0;
USER_INPUT input = USER_INPUT::NONE;
bool run = true;

int player_x = 5;
int player_y = 5;

int mapa_puntos = 0;
int player_puntos = 0;

void Inicializar() {
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if ((i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1))
			{
				mapa[i][j] = MAP_TILES::WALL;
			}
			else if (i == 5 || i == CONSOLE_HEIGHT - 6 || j == 5 || j == CONSOLE_WIDTH - 6) {
				mapa[i][j] = MAP_TILES::POINT;
				mapa_puntos++;
			}
			else {
				mapa[i][j] = MAP_TILES::EMPTY;
			}

		}
	}
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
	if (mapa[newPos_y][newPos_x] == MAP_TILES::WALL)
	{
		newPos_y = player_y;
		newPos_x = player_x;
	}
	else if (mapa[newPos_y][newPos_x] == MAP_TILES::POINT) {
		mapa_puntos--;
		player_puntos++;
		mapa[newPos_y][newPos_x] = MAP_TILES::EMPTY;
	}
	/* volver al otro lado de la pantalla cuando cruzas un limite
	if (newPos_y < 0) {
		newPos_y = CONSOLE_HEIGHT - 1;
	}
	if ( newPos_x < 0) {
		newPos_x = CONSOLE_WIDTH - 1;
	}
	newPos_y %= CONSOLE_HEIGHT;
	newPos_x %= CONSOLE_WIDTH;*/
	player_y = newPos_y;
	player_x = newPos_x;

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
			if (player_x == j && player_y == i) {
				cout << player;
			}
			else {

				cout << (char)mapa[i][j];
			}
		}
		cout << endl;
	}
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
		Input();
		logic();
		Draw();
	}


}}




