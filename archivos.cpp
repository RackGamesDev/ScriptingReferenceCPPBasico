#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>//Libreria para los archivos
#include<direct.h>//Para las carpetas
#include<dirent.h>//Carpetas
using namespace std;


void Escribir(string nombreArchivo, string contenidoArchivo){//Con esto se crearia el archivo, si no existe se hace desde 0 introduciendo el contenido que pidas y si ya existe se sobreescribe
	ofstream arch;//Declarar una variable de tipo ofstream, por lo que arch almacenara un archivo
	arch.open(nombreArchivo.c_str(), ios::out);//Abrir el archivo y ponerle un nombre (el de la funcion), en este caso lo crea para poder usarlo
	if(arch.fail()){//Para saber si se puede abrir sin errores
		cout<<"error con "<<nombreArchivo;
		//exit(1);//Cerrar el programa usando stdlib.h
	} else {
		arch<<contenidoArchivo.c_str();//Introduciendo datos al archivo, en este caso son caracteres
		//arch<<"\n archivo escrito";//Luego se puede introducir mas codigo
	}
	arch.close();//Cerrarlo al terminar
}

string Leer(string nombreArchivo){//Esto devuelve el conentenido de un archivo, en este caso suponiendo que se usara como string y siempre que el archivo exista
	string texto;
	ifstream arch;//Crear una variable de tipo ifstream, en este caso para abrir un archivo existente
	arch.open(nombreArchivo.c_str(),ios::in);//Abrirlo en modo lectura
	if(arch.fail()){//Un error comun aqui seria que no exista el archivo
		cout<<"error con "<<nombreArchivo;
		return NULL;
	} else {
		while(!arch.eof()){//Mientras no sea el final del archivo
			getline(arch,texto);//Volcar todos los caracteres del archivo a la variable
		}
		arch.close();//Cerrar archivo
		return texto;
	}
}

void Agnadir(string nombreArchivo, string nuevoContenidoArchivo){//Igual que escribir pero no borra el contenido que hubiese, sino que lo agnade al final
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


void CrearCarpeta(string ruta){//Crea una carpeta
	if(ruta != ""){
		if(mkdir(ruta.c_str()) == 0){
			cout<<ruta<<" creado";
		} else {
			cout<<"error";
		}
	}
}

bool CarpataExiste(string ruta){//Devuelve true si la carpeta existe
	DIR * directorio;
	if(directorio == opendir(ruta.c_str())){
		closedir(directorio);
		return true;
	} else {
		return false;
	}
}
bool ArchivoExiste(string ruta){//Devuelve true si el archivo existe
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
	//Escribir("d://hola//aaa.txt","sfdasdf");//Usando una direccion, la carpeta debe existir
	cout<<Leer("archivo.txt");//Devuelve el contenido del archivo
	Agnadir("archivo.txt", "nuevoooo");//Adhiriendo ese texto al final del archivo
	CrearCarpeta("d://a");
	cout<<CarpataExiste("d://a");
	cout<<ArchivoExiste("d://a.txt");
	Eliminar("archivo.txt");
	
	system("pause");
	return 0;
}
