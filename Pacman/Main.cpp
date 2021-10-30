#include <iostream>
using namespace std;


#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

enum MAP_TILES { WALL = '#', EMPTY = ' ', POINT = '.' };
enum USERS_INPUTS { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
enum MAP_TILES mapa[CONSOLE_HEIGHT][CONSOLE_WIDTH];

//Prueba Diego

char player = '0';
USERS_INPUTS input = USERS_INPUTS::NONE;
bool run = true;
int Player_X = 10;
int Player_Y = 10;

int mapa_puntos = 0;
int player_puntos = 0;


void Inicializar()
{
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
			{
				mapa[i][j] = MAP_TILES::WALL;

			}
			else if (i == 1 || i == CONSOLE_HEIGHT - 2 || j == 1 || j == CONSOLE_WIDTH - 2)
			{
				mapa[i][j] = MAP_TILES::POINT;
				mapa_puntos++;
			}
			else
			{
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
		input = USERS_INPUTS::UP;
		break;
	case 'A':
	case 'a':
		input = USERS_INPUTS::LEFT;
		break;
	case 'S':
	case 's':
		input = USERS_INPUTS::DOWN;
		break;
	case 'D':
	case 'd':
		input = USERS_INPUTS::RIGHT;
		break;
	case 'q':
	case 'Q':
		input = USERS_INPUTS::QUIT;
		break;
	default:
		input = USERS_INPUTS::NONE;
		break;
	}
}
void Logica() {
	int newPos_Y = Player_Y;
	int newPos_X = Player_X;
	switch (input)
	{

	case UP:
		newPos_Y--;
		break;
	case DOWN:
		newPos_Y++;
		break;
	case RIGHT:
		newPos_X++;
		break;
	case LEFT:
		newPos_X--;
		break;
	case QUIT:
		run = false;
		break;

	}
	if (mapa[newPos_Y][newPos_X] == MAP_TILES::WALL)
	{
		newPos_Y = Player_Y;
		newPos_X = Player_X;

	}


	Player_Y = newPos_Y;
	Player_X = newPos_X;
}
void Draw() {
	system("CLS");
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (Player_X == j && Player_Y == i) {
				cout << player;
			}
			else {
				cout << (char)mapa[i][j];
			}
		}
		cout << endl;
	}
}
int main()
{
	Inicializar();
	while (run) {
		Input();

		Logica();

		Draw();
	}
}




