#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;//Podria no ser int
	Nodo *siguiente;	
};
//Pilas, agregar elementos a una pila para que luego al quitarlo se quite el mas reciente y se vuelque el contenido a una variable, lifo (last in first out)
void InsertarPila(Nodo *&pila, int n){//Agrega un dato al final
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	cout<<"agregar "<<n<<endl;
}
void SacarPila(Nodo *&pila, int &n){//Saca el ultimo elemento en agregarse de la pila y convierte la variable de la llamada en su contenido
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux ->siguiente;
	delete aux;
	cout<<"quitar "<<n<<endl;
	
}
void ResetPila(Nodo *&_pila, int &n){//Resetea toda la pila a null
	while(_pila!=NULL){
		SacarPila(_pila,n);
	}
}
bool PilaVacia(Nodo *pila){//Devuelve true o 1 si la pila esta vacia
	return (pila==NULL);
}

//Colas, agregar elementos a una cola para que luego al quitarlo se quite el mas antiguo y se vuelque el contenido a una variable, fifo (first in first out)
bool ColaVacia(Nodo *frente){//Devuelve true o 1 si la cola esta vacia
	return (frente == NULL);
}
void InsertarCola(Nodo *&frente, Nodo *&fin, int n){//Insertar un elemento a la cola
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = NULL;
	if(ColaVacia(frente)){
		frente = nuevo_nodo;
	} else {
		fin -> siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	cout<<"agregar "<<n<<endl;
}
void SacarCola(Nodo *&frente, Nodo *&fin, int &n){//Para sacar el elemento mas antiguo de la cola y volcar su contenido a la variable
	n = frente->dato;
	Nodo *aux = frente;
	if(frente == fin){//Para saber si hay 1 o mas de 1 elemento en la cola
		frente = NULL;
		fin = NULL;
	} else {
		frente = frente->siguiente;
	}
	delete aux;
	cout<<"sacar "<<n<<endl;
}
void ResetCola(Nodo *&frente, Nodo *&fin){//Para resetear la cola
	int t;
	while (frente != NULL){
		SacarCola(frente,fin,t);
	}
}

//Listas, son como arrays dinamicos y las hay simples, doble enlazado, circular simple, circular doble enlazado dependiendo de sus nodos y la variable "siguiente"
void InsertarLista(Nodo *&lista, int n){//Para insertar un elemento a la lista, se inserta al final
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	Nodo *aux1 = lista;
	Nodo *aux2;
	//Esto es para que los numeros se ordenen solos, eliminar para que se agregen tal cual
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(lista == aux1){
		lista = nuevo_nodo;
	} else {
		aux2->siguiente = nuevo_nodo;
	}
	//-----
	nuevo_nodo->siguiente = aux1;
	cout<<"insertar "<<n<<endl;
}
void MostrarLista(Nodo *lista){//En este caso imprime todos los elementos de la lista pero se puede usar para otras cosas. se mostraran ordenados por tamagno (int)
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual != NULL){
		cout<<"mostrarr: "<<actual->dato<<endl;//Se esta usando el elemento a mostrar
		actual = actual->siguiente;
	}
}
bool BuscarLista(Nodo *lista, int n){//Devuelve true si n esta en la lista y false si no
	bool band = false;
	Nodo *actual = new Nodo();
	actual = lista;
	while((actual != NULL) && (actual->dato <= n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual -> siguiente;
	}
	cout<<"estar de "<<n<<" es "<<band;
	return band;
}
void EliminarPrimerLista(Nodo *&lista, int n){//Elimina el primer elemento equivalente a n que encuentre
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = lista;
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		if(aux_borrar == NULL){
			cout<<"error, no existe"<<endl;//Codigo en caso de que no exista
		} else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		} else {
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}
void BuscarEliminarLista(Nodo *&lista, int &n){//Elimina el primer elemento que encuentre coincidente con n (funciona  raro)
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	cout<<"eliminar el "<<n;
	delete aux;
}
void ResetLista(Nodo *&lista, int &n){//Borrar toda la lista (funciona raro)
	while(lista != NULL){
		BuscarEliminarLista(lista, n);
	}
}



//Arboles, son nodos de los cuales derivan varios nodos, son mejores los del otro script porque estos son muy basicos
struct RNodo{//Estructura para los nodos de los arboles
	int dato;//Podria no ser int
	RNodo *der;//En este caso solo podrian derivar 2, pero se pueden poner mas o incluso un array
	RNodo *izq;
	RNodo *padre;
};
RNodo *RCrearNodo(int n, RNodo *padre){//Declarar un nodo para el arbol
	RNodo *nuevo_nodo = new RNodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}
void RInsertarNodo(RNodo *&arbol, int n, RNodo *padre){//Meter el nodo ya creado al arbol, como esta talcual se pete en pequegno en la izquierda y el grande en la derecha pero se podria mejorar
	if (arbol == NULL){
		RNodo *nuevo_nodo = RCrearNodo(n, padre);
		arbol = nuevo_nodo;
	} else {//Aqui seria para ver si se mete en la izquierda/derecha/etc... como esta talcual se mete el pequegno en la izquierda y el grande en la derecha pero se podria hacer en la funcion para elegir derecha/izquierda/etc (mas recomendable)
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){//Aqui hay que cambiar
			RInsertarNodo(arbol->izq, n, arbol);
			cout<<"inserta "<<n<<" a la izquierda de "<<valorRaiz;
		} else {
			RInsertarNodo(arbol->der, n, arbol);
			cout<<"inserta "<<n<<" a la derecha de "<<valorRaiz;
		}
	}
}
void RMostrarArbol(RNodo *arbol, int cont){//Imprimir el arbol siguiendo la norma de izquierda y derecha, llamarla con cont=0
	if(arbol == NULL){
		return;
	} else {
		RMostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		RMostrarArbol(arbol->izq,cont+1);
	}
}
bool RBuscar(RNodo *arbol, int n){//Devuelve true si el numero esta en algun nodo del arbol
	if(arbol == NULL){
		return false;
	} else if(arbol->dato == n){
		return true;
	} else if(n < arbol->dato){
		return RBuscar(arbol->izq,n);
	} else {
		return RBuscar(arbol->der,n);
	}
}
void ROrden(RNodo *arbol){//Otra forma de imprimir el arbol segun lo de izquierda y derecha
	if(arbol == NULL){
		return;
	} else {//Depende del orden de estas 3 lineas son ordenaciones distintas
		cout<<arbol->dato<<" - ";
		ROrden(arbol->izq);
		ROrden(arbol->der);
	}
	
}
//Las 5 funciones inferiores son para eliminar
RNodo *RMinimo(RNodo *arbol){//ver el nodo mas izquierdo, usado por REliminarNodo
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izq){
		return RMinimo(arbol->izq);
	} else {
		return arbol;
	}
}
void RDestruirNodo(RNodo *nodo){//Destruir un nodo completamente, usado por eliminar
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}
void RReemplazar(RNodo *arbol, RNodo *nuevoNodo){//Usado por eliminar
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		} else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}
void REliminarNodo(RNodo *nodoEliminar){//Eliminar un nodo, usado por REliminar
	if(nodoEliminar->izq && nodoEliminar->der){
		RNodo *menor = RMinimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		REliminarNodo(menor);
	} else if(nodoEliminar->izq){
		RReemplazar(nodoEliminar, nodoEliminar->izq);
		RDestruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){
		RReemplazar(nodoEliminar,nodoEliminar->der);
		RDestruirNodo(nodoEliminar);
	} else {
		RReemplazar(nodoEliminar, NULL);
		RDestruirNodo(nodoEliminar);
	}
}
void REliminar(RNodo *arbol, int n){//Busca un numero y elimina el nodo que lo lleve, luego se reemplazan por los menores
	if(arbol == NULL){
		return;
	} else if(n< arbol->dato){
		REliminar(arbol->izq, n);
	} else if(n> arbol->dato){
		REliminar(arbol->der, n);
	} else {
		REliminarNodo(arbol);
		cout<<"eliminar "<<n;
	}
}



int main(){
	int a = 9;
	Nodo *pila1 = NULL;//Crear pila
	InsertarPila(pila1, a);//Agregar a la pila
	SacarPila(pila1,a);//Quitar de la pila y convertir a en el ultimo elemento
	cout<<a<<endl;
	ResetPila(pila1, a);//Quitar todos los elementos de la pila
	cout<<PilaVacia(pila1);//Para saber si esta vacia
	
	
	Nodo *frente1 = NULL;//Se necesitan 2 asi para crear una cola (se podrian encapsular ambos en un struct pero no es recomendable)
	Nodo *fin1 = NULL;
	InsertarCola(frente1,fin1, a);//Agregar a a la pila de frente1 y fin1
	SacarCola(frente1, fin1, a);//Sacando el elemento mas antiguo de la cola y volcandolo a la variable
	ResetCola(frente1,fin1);//Eliminando todos los elementos de la cola usando frente y fin
	cout<<ColaVacia(frente1);//Para saber si esta vacia, usando solo frente
	
	
	a=6;
	Nodo *lista1 = NULL;//Crear lista
	InsertarLista(lista1, a);//Agregar elemento en la lista al final
	a=4;
	InsertarLista(lista1, a);
	a=5;
	InsertarLista(lista1,a);
	InsertarLista(lista1,a);
	MostrarLista(lista1);//Mostrarlos ordenados por tamagno
	cout<<BuscarLista(lista1,4);//Mirar si el 4 esta en la lista
	EliminarPrimerLista(lista1,5);//Elimina el primer 5 que encuentre
	BuscarEliminarLista(lista1,a);//Elimina el primer elemento concidente con la variable que encuentre


	a = 0;
	RNodo *arbol1 = NULL;//Declarar un arbol
	RInsertarNodo(arbol1, 10, arbol1);//Estableciendo el dato del nodo arbol1 como 10, como en este caso se ordenan automaticamente basta con repetir esta linea y se asigna al nodo que le digas
	RInsertarNodo(arbol1, 5, arbol1);
	RInsertarNodo(arbol1, 8, arbol1);
	RInsertarNodo(arbol1, 9, arbol1);
	RInsertarNodo(arbol1, 2, arbol1);
	cout<<"\n\n";
	RMostrarArbol(arbol1,a);//Mostrando el arbol, a debe ser cualquier variable con valor 0
	cout<<RBuscar(arbol1,5);//Imprimira 1 porque el 5 si 
	ROrden(arbol1);//Imprimir el arbol todo recto
	REliminar(arbol1,5);//Elimina el nodo con 5 del arbol usando luego las otras 4 funciones
	ROrden(arbol1);
	
	
	
	getch();
	return 0;
}

