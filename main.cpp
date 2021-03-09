#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include "Headers/Rlutil.h"
#include "Headers/Funciones.h"

using namespace std;

using namespace rlutil;
#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27



int main(){
dificultad();
setColor(LIGHTGREEN);
gotoxy(50,2);cout<<"PUNTAJE:";
setColor(WHITE);
cout<<Puntos;
pintar();
gotoxy(xc,yc);cout<<(char)4;
while(tecla != ESC && gameover() ){
    proceso();
}
if ( !gameover()){
	MessageBox(NULL,"Has perdido","Maldito Perdedor", MB_OK);
	system("cls");

}
	system("pause>NULL");
	return 0;

}
