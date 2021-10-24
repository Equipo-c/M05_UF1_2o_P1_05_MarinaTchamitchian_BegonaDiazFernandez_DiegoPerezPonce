#include <iostream>
using namespace std;


#define CONSOLE_HEIGHT 10
#define CONSOLE_WIDTH 10

//char relleno[CONSOLE_HEIGHT][CONSOLE_WIDTH]={"#"};
char relleno =  '#' ;
char input= ' ';
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
	for (size_t i = 0; i < CONSOLE_HEIGHT; i++)
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




