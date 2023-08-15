#include<iostream>
#include<stdlib.h>
#include "Paquete.h"//incluyendo la libreria personalizada, se pone la ruta (tal cual la de windows o relativa a este script), como esta en la misma carpeta se puede poner talcual
using namespace std;
using namespace paquetico;//si en la libreria las cosas estan en un namespace hay que mencionarlo, lo que este fuera del namespace no hace falta escribir esto

int main(){
	
	cout<<Sumar(1, 2)<<endl;//como ya esta importado se puede usar como si nada, esto esta en el namespace y hay que poner la linea de arriba
	cout<<hora<<endl;//esto esta fuera del namespace y se podria usar sin el using namespace
	system("pause");
	return 0;
}
