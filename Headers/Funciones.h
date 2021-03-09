#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;
using namespace rlutil;
#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27
char tecla;
int cuerpo[200][2];
int n=1;
int tam = 3;
int x=10, y=12;
int dir=3;
int xc=30, yc=20;
int Puntos=0;
int xxc= 40, yyc=18;
int d;
int dif;
double tiempo;

void dificultad(){
    setColor(LIGHTGREEN);
	cout<<"Snake \n ELIJA  UNA DIFICULTAD PARA ALTERAR LA VELOCIDAD \n ";
	setColor(LIGHTGREEN);
	cout<<"1: FACIL \n ";
	setColor(YELLOW);
	cout<<"2: MEDIA \n ";
	setColor(RED);
	cout<<"3: DIFICIL"<<endl;
	setColor(WHITE);
	cin>>d;
	switch(d){
		case 1:
			dif=80;
			break;
		case 2:
		    dif=60;
			break;
		case 3:
		    dif=35;
			break;
	}
	system("cls");
}

void gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;

	SetConsoleCursorPosition(hCon,dwPos);
}

void pintar(){
	for(int i=2; i<78;i++){
            setColor(LIGHTGREEN);
		gotoxy(i,3);cout<<(char)205;
		gotoxy(i,23);cout<<(char)205;
	}
	for(int i=4;i<23;i++){

		gotoxy(2,i); cout<<(char)186;
		gotoxy(77,i); cout<<(char)186;
	}

	gotoxy(2,3);cout<<(char)201;
	gotoxy(2,23);cout<<(char)200;
	gotoxy(77,3);cout<<(char)187;
	gotoxy(77,23);cout<<(char)188;

}

void dibujarcuerpo(){
	for(int i=1; i<tam;i++){
            setColor(LIGHTGREEN);
		gotoxy(cuerpo[i][0],cuerpo[i][1]); cout<<"*";
	}
}

void guardarposicion(){
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if (n==tam){n=1;}
	dibujarcuerpo();
}


void borrarcuerpo(){
		gotoxy(cuerpo[n][0],cuerpo[n][1]); cout<<" ";
		guardarposicion();
	}

void Teclear(){
	if (kbhit()){
		tecla=getch();
		switch(tecla){
			case ARRIBA:
			if (dir !=2){dir=1;}
			break;
			case ABAJO:
			if(dir != 1 ){dir=2;}
			break;
			case IZQUIERDA:
			if (dir != 3){dir=4;}
			break;
			case DERECHA:
			if (dir != 4){dir=3;}
			break;
		}
	}

}

void comida(){
	if (x==xc && y==yc) {
		srand((unsigned)time(NULL));
		xc=(rand()% 73)+4;
		srand((unsigned)time(NULL));
		yc=(rand()% 19)+4;
		tam++;

		gotoxy(xc,yc);
		setColor(RED);
		cout<<(char)4;
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}

}

bool gameover(){
	if (y==3 || y== 23 || x==2 || x==77){return false; }
	for (int j=tam-1; j>0;j--){
		if(cuerpo[j][0]==x && cuerpo [j][1]==y) {return false; }
	}

	return true;

}

void puntosx(){
	tiempo=tiempo+0.05;
	int tiempo2=tiempo;
	gotoxy(35,2);cout<<"TIEMPO:"<<tiempo<<" sg";
	if (x==xxc && y== yyc){
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
		Puntos=Puntos+5;
        gotoxy(50,2);
        cout<<"PUNTAJE: ";
        cout<<Puntos;
	}
	if (tiempo2 %10==0){
	    gotoxy(xxc,yyc); cout<<(char)6;
	} else if (tiempo2 %15==0){
		gotoxy(xxc,yyc); cout<<" ";
		srand((unsigned)time(NULL));
		xxc=(rand()%73)+4;
		srand((unsigned)time(NULL));
		yyc=(rand()%19)+4;
	}
}

void proceso(){
	borrarcuerpo();
	setColor(RED);
	comida();
	puntosx();
	Teclear();
	Teclear();
	if (dir==1){y--;}
	if (dir==2){y++;}
	if (dir==3){x++;}
	if (dir==4){x--;}
	Sleep(dif);
}
#endif // FUNCIONES_H_INCLUDED
