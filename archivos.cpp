#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>//libreria para los archivos
#include<direct.h>//para las carpetas
#include<dirent.h>//carpetas
using namespace std;


void Escribir(string nombreArchivo, string contenidoArchivo){//con esto se crearia el archivo, si no existe se hace desde 0 introduciendo el contenido que pidas y si ya existe se sobreescribe
	ofstream arch;//declarar una variable de tipo ofstream, por lo que arch almacenara un archivo
	arch.open(nombreArchivo.c_str(), ios::out);//abrir el archivo y ponerle un nombre (el de la funcion), en este caso lo crea para poder usarlo
	if(arch.fail()){//para saber si se puede abrir sin errores
		cout<<"error con "<<nombreArchivo;
		//exit(1);//cerrar el programa usando stdlib.h
	} else {
		arch<<contenidoArchivo.c_str();//introduciendo datos al archivo, en este caso son caracteres
		//arch<<"\n archivo escrito";//luego se puede introducir mas codigo
	}
	arch.close();//cerrarlo al terminar
}

string Leer(string nombreArchivo){//esto devuelve el conentenido de un archivo, en este caso suponiendo que se usara como string y siempre que el archivo exista
	string texto;
	ifstream arch;//crear una variable de tipo ifstream, en este caso para abrir un archivo existente
	arch.open(nombreArchivo.c_str(),ios::in);//abrirlo en modo lectura
	if(arch.fail()){//un error comun aqui seria que no exista el archivo
		cout<<"error con "<<nombreArchivo;
		return NULL;
	} else {
		while(!arch.eof()){//mientras no sea el final del archivo
			getline(arch,texto);//volcar todos los caracteres del archivo a la variable
		}
		arch.close();//cerrar archivo
		return texto;
	}
}

void Agnadir(string nombreArchivo, string nuevoContenidoArchivo){//igual que escribir pero no borra el contenido que hubiese, sino que lo agnade al final
	ofstream arch;
	arch.open(nombreArchivo.c_str(),ios::app);//app de aplicar
	if(arch.fail()){
		cout<<"error con "<<nombreArchivo;
		//exit(1);
	} else {
		arch<<nuevoContenidoArchivo.c_str();
	}
	arch.close();
}


void CrearCarpeta(string ruta){//crea una carpeta
	if(ruta != ""){
		if(mkdir(ruta.c_str()) == 0){
			cout<<ruta<<" creado";
		} else {
			cout<<"error";
		}
	}
}

bool CarpataExiste(string ruta){//devuelve true si la carpeta existe (funciona raro)
	DIR * directorio;
	if(directorio == opendir(ruta.c_str())){
		closedir(directorio);
		return true;
	} else {
		return false;
	}
}
bool ArchivoExiste(string ruta){//devuelve true si el archivo existe (funciona raro)
	FILE * archivo;
	if(archivo = fopen(ruta.c_str(), "r")){
		fclose(archivo);
		return true;
	} else {
		return false;
	}
}
void Eliminar(string ruta){//elimina un archivo o carpeta comprobando si existe (funciona raro)
	string comando;
	if(CarpataExiste(ruta)){
		comando = "rmdir " + ruta + " /s /q";
		system(comando.c_str());
	} else if (ArchivoExiste(ruta)){
		comando = "del " + ruta;
		system(comando.c_str());
	} else {
		cout<<"error con "<<ruta;
	}

}



int main(){
	Escribir("archivo.txt","asdflasjdlfsjd");
	//Escribir("d://hola//aaa.txt","sfdasdf");//usando una direccion, la carpeta debe existir
	cout<<Leer("archivo.txt");//devuelve el contenido del archivo
	Agnadir("archivo.txt", "nuevoooo");//adhiriendo ese texto al final del archivo
	CrearCarpeta("d://a");
	cout<<CarpataExiste("d://a");
	cout<<ArchivoExiste("d://a.txt");
	Eliminar("archivo.txt");
	
	system("pause");
	return 0;
}
