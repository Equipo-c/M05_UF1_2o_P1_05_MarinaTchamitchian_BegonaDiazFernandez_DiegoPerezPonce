#include <iostream>
using namespace std;

//prueba rama

#define CONSOLE_HEIGHT 29
#define CONSOLE_WIDTH 119

enum MAP_TILES {WALL='#', EMPTY=' ', POINT='.' };
enum USER_INPUTS { NONE,UP,DOWN,RIGHT,LEFT,QUIT };
MAP_TILES mapa[CONSOLE_HEIGHT][CONSOLE_WIDTH];





char Player = 'O';
USER_INPUTS input = USER_INPUTS::NONE; 
bool run = true;
int Player_X = 10; 
int Player_Y = 10; 

void Inicializar() 
{
	//rellenamos el mapa

	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (i == 0 || i == CONSOLE_HEIGHT - 1 || j == 0 || j == CONSOLE_WIDTH - 1)
			{
				mapa[i][j] = MAP_TILES::WALL; 
			}
			else
			{
			
				mapa[i][j] = MAP_TILES::EMPTY;
			}
		}
	}


}
// While() {} numero de veces que se repite la consola
void Input() {
	char tempInput; 
	cin >> tempInput;
	switch (tempInput)

	{
	case 'W':
	case 'w':
		input = USER_INPUTS::UP;
		break;
	case 'A':
	case 'a':
		input = USER_INPUTS::LEFT;
		break;
	case 'S':
	case 's':
		input = USER_INPUTS::DOWN;
		break;
	case 'D':
	case 'd':
		input = USER_INPUTS::RIGHT;
		break; 
	case 'q':
	case 'Q':
		input = USER_INPUTS::QUIT;
		break;
	default:
		input = USER_INPUTS::NONE; 
		break;
	}
}

void Logica() 
{
	//salir del juego
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
		newPos_X--;
		break;
	case LEFT:
		newPos_X++;
		break;
	case QUIT:
		run = false; 
		break;
	
		
	}

	
	Player_Y = newPos_Y; 
	Player_X = newPos_X; 
}
	


void Draw() {
	//limpiar pantalla tras interaccion
	system("CLS");

	//int i, j; 
	for (size_t i = 0; i < CONSOLE_WIDTH; i++)
	{
		for (size_t j = 0; j < CONSOLE_WIDTH; j++)
		{
			if (Player_X == j && Player_Y == i)
			{
				cout << Player; 
			}
			else
			{
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




