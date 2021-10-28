

#include <iostream>
using namespace std;


#define CONSOLE_HEIGHT 3
#define CONSOLE_WIDTH 30
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
char input = 'a';
bool run = true;


// While() {} numero de veces que se repite la consola
void Input() {
	cin >> input;
}

void Logica() {
	//salir del juego
	if (input == 'q' || input == 'Q')
	{
		run = false;
	}
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
	while (run) {

		Input();
		Logica();
		Draw();
	}


}




