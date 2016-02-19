#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int** crearTablero();
void llenarCubo(int**);
void imprimirTablero(int**);
int** puntos(int**, int, int, int, int);
bool validar(int**, int, int);

int main(int ragc, char*argv[]){
	int** matriz;
	matriz=crearTablero();
	llenarCubo(matriz);
	bool ganador=false;
	int p1, p2;
	bool pos;
	while(ganador==false){
		imprimirTablero(matriz);
		ganador=true;
		cout<<"---Juagdor 1---"<<endl;
		cout<<"Posicion x: ";
		cin>>p1;
		cout<<"Posicion y: ";
		cin>>p2;
		pos=validar(matriz,p1,p2);		
		if(pos){
			
		}else{
			cout<<"No se Puede Colocar en Esa Coordenada"<<endl;
		}
				
	}
	return 0;
}

int** crearTablero(){
	int** tablero= new int*[7];
	for(int i=0; i<7; i++){
		tablero[i]=new int[7];		
	}
	return tablero;
}

void llenarCubo(int** tablero){
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			tablero[i][j]=0;
		}
	}
	tablero[0][3]=1;
	tablero[6][3]=1;
	tablero[3][0]=2;
	tablero[3][6]=2;
}

void imprimirTablero(int** tablero){
	for(int i=0; i<7; i++){
		for(int j=0; j<7; j++){
			cout<<tablero[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int** convertir(int** matriz, int x, int y, int op, int jug){
	int a1, a2, a3, a4, a5, a7;
	int cont=1;
	if((x!=0) || (y!=0) || (x!=6) || (y!=6){
		if(matriz[x-cont][y-cont]==op){
			matriz[x-cont][y-cont]=jug;
		}
		if(matriz[x-cont][y]==op){
			matriz[x-cont][y]=jug;
		}
		if(matriz[x-cont][y+cont]==op){
			matriz[x-cont][y+cont]=jug;
		}
		if(matriz[x][y-cont]==op){
			matriz[x][y-cont]=jug;
		}
		if(matriz[x][y+cont]==op){
			matriz[x][y+cont]=jug;
		}
		if(matriz[x+cont][y-cont]==op){
			matriz[x+cont][y-cont]=jug;
		}
		if(matriz[x+cont][y]==op){
			matriz[x+cont][y]=jug;
		}
		if(matriz[x+cont][y+cont]==op){
			matriz[x+cont][y+cont]=jug;
		}
	}
	return matriz;
	
}

bool validar(int** matriz, int x, int y){
	bool poner=true;
	if((matriz[x][y]==1) || (matriz[x][y]==2)){
		poner=false;
	}
	return poner;
}
