/*
* ESTOS COMENTARIOS SE PUEDEN IR BORRANDO SEGUN VAMOS AVANZANDO, PERO CREO QUE PODRIAN ESTAR BIEN PARA
* IR TRABAJNDO EL PROYECTO.
 
HOLA CHICOS, A VER OS CUENTO 
ESTAMOS EN LA FASE DE DIBUJAR EL MAPA, SEGUN EL MODELO BASE DE ALBERTO Y LO QUE ME HA PARECIDO ENTENDER DE LA PRACTICA PUEDE SER EL MAPA MAS PEQUEÑO TIPO 10X10
AUN ASI YO HE COPIADO EL MAPA DE ALBERTO QUE SON 6# + 6 · +6# EN VERTICAL Y 32# +18· +32# EN HORIZONTAL (ESTO LO PODEIS MODIFICAR SI LO PREFERIS)

YO HE CONSEGUIDO QUE EL MAPA REINICIE PULSANDO LA LETRA "a", LO PODEMOS DEJAR ASI, YA QUE MAS TARDE SE REINICIARA AL PULSAR CUALQUIERA DE LOS INPUTS DEL PLAYER
PERO NO CONSIGO QUE EL MAPA QUE YO QUIERO SE DIBUJE EN PANTALLA, ASI QUE EN ESE PUNTO ESTAMOS... 
CON LO QUE AVANCEIS VAMOS HABLANDO. 
*/



//ESTS UNA PRUEBA DOS
//sgsgsa
//agsag




//Holanova

//hola222
//hola33


//Confirmando Prueba


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




