//esto esta sin terminar

#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

const int cant = 4;
struct RNodo{
	int dato;
	RNodo *hijo[cant];
	RNodo *padre;
};
RNodo *CrearNodo(int n, RNodo *padre){//declarar un nodo para el arbol
	RNodo *nuevo_nodo = new RNodo();
	nuevo_nodo->dato = n;
	for (int i=0;i<cant;i++){
		nuevo_nodo->hijo[i] = NULL;
	}
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}
void InsertarNodo(RNodo *&arbol, int n, int posicion){//inserta un subarbol en una posicion, si es nulo lo inserta y si no lo es lo pone por debajo en pos 0
	if (arbol == NULL){
		RNodo *nuevo_nodo = CrearNodo(n, NULL);
		arbol = nuevo_nodo;
	} else if(arbol->hijo[posicion] == NULL || arbol->hijo[posicion]->dato == 0){
		RNodo *nuevo_nodo = CrearNodo(n, arbol);
		arbol->hijo[posicion] = nuevo_nodo;
	} else {
		InsertarNodo(arbol->hijo[posicion], n, 0);
	}
}
void CambiarValor(RNodo *&arbol, int n){//cambia el valor del nodo que le digas
	if(arbol != NULL){
		arbol->dato = n;
	}
}

void RMostrarArbol(RNodo *arbol, int &nivel){//usado por mostrararbol
	if(arbol != NULL){
		for(int ii=0; ii<nivel;ii++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;	
		for (int i=0;i<cant;i++){
			if(arbol->hijo[i]!=NULL){
				nivel++;
				RMostrarArbol(arbol->hijo[i], nivel);
				
				
			} else {
				nivel--;
			}
		}
	}
}
void MostrarArbol(RNodo *arbol){//imprime el arbol como si fuesen carpetas
	int nivel = 0;
	cout<<"arbol:\n\n";
	RMostrarArbol(arbol, nivel);
	cout<<"\n\n ya esta";
}

//bool Buscar(RNodo *arbol, int n){//devuelve true si el numero esta en algun nodo del arbol o subarboles
//	return true;
//}







int main(){
	int a = 9;


	RNodo *arbol1 = NULL;//declarar un arbol
	CambiarValor(arbol1,10);
	InsertarNodo(arbol1, 1, 0);
	InsertarNodo(arbol1, 2, 1);
	InsertarNodo(arbol1, 7, 2);
	//InsertarNodo(arbol1, 3, 3);
	//InsertarNodo(arbol1, 12, 0);
	MostrarArbol(arbol1);
	
	
	
	getch();
	return 0;
}

