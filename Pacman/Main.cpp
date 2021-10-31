#include <iostream>
#include <windows.h>  
using namespace std;


#define CONSOLE_HEIGHT 10
#define CONSOLE_WIDTH 10

enum USER_INPUT { NONE, UP, DOWN, RIGHT, LEFT, QUIT };
USER_INPUT input = USER_INPUT::NONE;

bool run = true;

int player_x = 5;
int player_y = 5;

int mapa_puntos = 0;
int player_puntos = 0;

//{ 'x' };/*
char relleno={ 'x' };
//char relleno[CONSOLE_WIDTH] [CONSOLE_HEIGHT]  { "################################··················################################",
//"#                                                                                #"};
//"#                                                                                #",
//"#                                                                                #",
//"#                                                                                #",
//"·                                                                                ·",
//"·                                                                                ·",
//"·                                                                                ·",
//"·                                                                                ·",
//"·                                                                                ·",
//"·                                                                                ·",
//"#                                                                                #",
//"#                                                                                #",
//"#                                                                                #",
//"#                                                                                #",
//"#                                                                                #",
//"################################··················################################",
//};*/
//char input = 'a';


void Instanziar()
{}
// While() {} numero de veces que se repite la consola
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

void Logica() {
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
	/*if (mapa[newPos_y][newPos_x] == MAP_TILES::WALL)
	{
		newPos_y = player_y;
		newPos_x = player_x;
	}
	else if (mapa[newPos_y][newPos_x] == MAP_TILES::POINT) {
		mapa_puntos--;
		player_puntos++;
		mapa[newPos_y][newPos_x] = MAP_TILES::EMPTY;
	}
	 volver al otro lado de la pantalla cuando cruzas un limite
	if (newPos_y < 0) {
		newPos_y = CONSOLE_HEIGHT - 1;
	}
	if ( newPos_x < 0) {
		newPos_x = CONSOLE_WIDTH - 1;
	}
	newPos_y %= CONSOLE_HEIGHT;
	newPos_x %= CONSOLE_WIDTH;*/
	//Finalizar el juego
	if (mapa_puntos == 0)
	{
		cout << "BIEN HECHO" <<endl;
		cout << "Pulsa 'Q' para salir" <<endl;
		system("PAUSE");
	}
	player_y = newPos_y;
	player_x = newPos_x;
}

void Draw() {
	//limpiar pantalla tras interaccion
	system("CLS");

	//int i, j; 
	for (size_t i = 0; i < CONSOLE_WIDTH; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			cout << relleno;
		}


	}


	cout << endl;
}

int main()
{
	Instanziar();
	while (run) {

		Input();
		Logica();
		Draw();
	}


}




