#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

string Leer(string nombreArchivo){
	string texto;
	ifstream arch;
	arch.open(nombreArchivo.c_str(),ios::in);
	if(arch.fail()){
		cout<<"error con "<<nombreArchivo;
		return NULL;
		exit(1);
	} else {
		while(!arch.eof()){
			getline(arch,texto);
		}
		arch.close();
		return texto;
	}
}



int main(){
	string cual;
	
	while (cual == ""){
		cout<<"Escribe la direccion exacta del archivo poniendo en minusculas el nombre del disco duro ej:(C: -> c:) y cambiando todas las barras inversas por barras normales (shift + 7) \n";
		cout<<"Direccion: ";
		getline(cin,cual);
	}
	system("cls");
	cout<<"El contenido es: "<<endl<<endl;
	cout<<Leer(cual)<<endl;
	
	
	system("pause");
	return 0;
}
