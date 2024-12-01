//c++
//Los comentarios se hacen asi
/*
Comentario de varias lineas
*/
//Los espacios y saltos no importan, se usan ;s y {}, al compilar y ejecutar se crea un exe, tipo de archivo es .cpp

#include<iostream>//Obligatorio
#include<math.h>//Para mas matematicas y raices cuadradas
#include<conio.h>//Para el getch de mas abajo, haria que no se cierre
#include<stdlib.h>//Se puede usar "system("pause");" para que haga lo mismo que el getch
#include<time.h>//Para aleatoriedad y tiempo
#include<string.h>//Para hacer strings bien y no arrays de chars cutres
using namespace std;//Obligatorio para consola



int Funcion1(int x, int y){//Las funciones deben ser declaradas en una linea anterior a la que se va a llamar, en caso contrario se puede hacer la funcion mas abajo pero escribir su encabezado arriba(encabezado es int funcion1(int,int);) y mas abajo igual pero sin el ; y con el codigo
	//Las funciones pueden pedir valores para usarlos en su codigo, se introducen al llamarla
	//Las funciones pueden ser de cualquier variable teniendo que devolverla o void que no devuelve nada
	return x+y;//Devolviendo un int, porque la funcion es int
}
void Funcion2(){//Esta funcion es void y no devuelve nada, pero si podria pedir valores
	cout<<"aa";
}
template <class UNTIPO>//Opcional: se pone antes del encabezado para que la  funcion sea de un tipo generico
void Funcion3(UNTIPO x);//Declarando un encabezado de funcion, porque se llamara mas adelante pero el codigo esta escrito mas abajo
void Funcion4(int& x){//Con & te refieres a la celda de la ram de esa variable, al hacerlo se vera repercutido en niveles superiores
	x++;
}
void Funcion5(int *x){}//Para que pida una direccion de memoria al llamar a la funcion


int glob = 0;//Las variables se pueden crear fuera del main para usarlas en otras funciones

struct Estructura {//Se pueden crear estructuras que contienen datos primitivos u otras estructuras para usarlas luego como variables, esto es muy similar al orientado a objetos
	char nombre[10];
	int tamagno;
};
struct Estructuraa {
	char nombre[10];
	int tamagno;
	struct Estructura stru;//Una estructura dentro de otra, ej: .estructura.tamagno
} est1, est2;//Aqui se estan declarando fuera de una funcion, pero tambien se puede dentro



int main(){//Funcion main que se ejecuta al abrir el programa
	
	cout<<"texto que aparece";//Imprimir en consola
	cout<<"\n es salto de linea, pero tambien"<<endl<<endl;//Se le agrega endl para saltar de linea, se pueden poner mas encadenados
	cout<<"\t a"<<endl;//t seria como presionar tabulador
	
	int num = 2;//Creando una variable durante el main
	long nuuum = 45354;//int pero con mas bits, operable con int
	float dec = 3.5;
	double mega = 1.11111;//float pero mas preciso, operable con float
	char letra = 'a';//Almacena un caracter, al ser uno se usa la comilla simple y no la doble
	cout<<num;//Se pueden usar talcual
	int numm;//No hace falta usar valores iniciales
	int a1, a2, a3 = 0;//Se pueden crear varias en una linea
	bool cerouno = 1;//No se suele usar el true o false, bool es un numero de 1 bit expresable como 0 o 1
	const int numerrr = 1600;//Variable constante que nunca cambia y ocupa menos 
	num = int(nuuum/10);//Hace que si o si devuelva un dato de esa variable
	
	//Punteroos:
	cout<<&mega;//Devuelve la direccion de memoria en la ram de esa variable, no el valor que tiene
	double *direccion;//Esta variable guarda una direccion de memoria, para usarlo con arrays no hace falta declararlo con [] y se le suma x a la direccion para especificar la posicion, en caso de que sea array de arrays se ponen varios *s. con estructuras en lugar de usar el "." se usa "->"
	direccion = &mega;//Ahora guarda la direccion de memoria de esa variable, al usarla sin el asterisco representa una direccion, solo se puede asignar a variables del mismo tipo
	cout<<*direccion;//Al usarla con el asterisco representa el valor de esa direccion
	//delete direccion;//Borra una variable de la ram usando la direccion de memoria de esta, si la variable fuese un array seria delete[] direccion; (mucho cuidado con esto) (stdlib.h)
	//delete &mega;
	
	fflush(stdin);//Elimina el buffer de entrada de consola
	cin>>numm;//Guarda la entrada en consola
	cin>>num>>numm;//Varios consecutivamente usando los >>
	cout<<endl<<"escribiste:  "<<numm;//Concatenaciones
	cout<<num+numm;//Las operaciones + - * /
	num=numm;//Aunque parezca que no, el = tambien funciona
	num+=3;//Funciona con los otros operadores
	num++;//Con + o -
	num = num%2;//Devuelve el resto de la division
	cout<<sqrt(25);//Raiz cuadrada con libreria math.h
	cout<<pow(2,5);//Elevar x a y con libreria math.h
	cout<<abs(num);//La version positiva de un numero, viene de stdlib.h
	
	cout.precision(3);//Cambia una propiedad de las siguientes impresiones para redondear los floats a esos digitos
	cout<<1.4593;//Seria 1.46
	
	
	if(num==3){//Las condicionales, se usa el == > < >= <= != para comparar, && es and y || es or
	} else if(num==5){//Para otra condicion si la anterior no se cumple
	}
	 else {//else para el caso contrario
	}
	cout<<(4>2);//Las condiciones tambien se pueden usar a si, si son ciertas contaran como 1 y si no lo son seran 0 (no existe el true y false)
	switch(num){//Para comprobar el estado de una variable
		case 1://Cada caso ejecuta un codigo
			break;//Si no se pusiese break al terminar ese codigo tambien comprobaria el siguiente
		case 2:
			break;
		default://default es similar al else
			
			break;
	}
	bool boo = (num==2)? true: false;//Una manera de usar bools, lo del ? en adelante es opcional
	
	
	int x = 0;
	while(x<=5){//Bucle while que se ejecuta siempre que algo sea cierto
		x++;
		break;//Esto es para romper el bucle opcional
	}
	
	do{//Esto ejecuta el codigo mientras algo sea cierto pero lo sea o no lo ejecuta primero una vez
		x++;
	}while(x<=8);
	
	for(int i = 0; i<9; i++){//Bucle for (iniciar iterador; condicion de cumplir; al terminar el bucle hace)
		cout<<i;
		//break;//Tambien vale el break
	}
	
	
	srand(time(NULL));//De aqui en adelante se pueden generar numeros aleatorios, necesita include stdlib.h y time.h
	int aleatorio = 1 + rand()%(100);//Generar un rango, se hace con (limite superior) + 1 - (limite inferior), en este caso seria entre 1 y 100
	
	
	int numeros[3] = {1,2,3};//Declarar un array con valores predefinidos
	int numeross[4];//Si no se especifican valores se usan todas las posiciones con datos por defecto
	cout<<numeros[2];//Leer o establecer el valor de una posicion del array, el 0 es el primero	
	int tabla[2][2];//Se pueden crear arrays de varias dimensiones
	int tablaa[3][3] = {{1,2,3},{1,2,3}};//Hay que pasar de fila para ponerlo todo en una linea
	cout<< tablaa[2][1];//Para referirse a una posicion
	num = sizeof(numeross) / sizeof(int);//Devuelve cuantas posiciones tiene
	
	char letras[] = {'a','b','c'};//Imitando un string equivale a "abc"
	char letrass[] = "123";//Las "" sirven para hacer un array de chars, al declararlo el array medira lo mismo que la cadena, teniendo un limite de longitud
	char letrasss[8];//Declarando el array de char con un limite
	num = atoi(letrass);//Convierte de string a int ignorando los no digitos (include stdlib.h)
	dec = atof(letrass);//Convierte de string a float (deberia tener decimales) ignorando los no digitos (include stdlib.h)
	//De aqui en adelante hace falta el include string.h
	cin.getline(letrasss,8,'\n');//Igual que el cin>> pero almacena el input en una variable, usando un limite de caracteres y imprimiento algo al final
	num = strlen(letrass);//Devuelve la longitud del string
	strcpy(letrasss,letrass);//Vuelca el contenido de la variable derecha a la de la izquierda. aqui no importa la longitud
	if(strcmp(letras,letrass)==0){//Compara 2 strings, devuelve 0 si son iguales, -1 si la segunda mide mas y 1 si la segunda mide menos
	}
	strcat(letras,letrass);//Agnade a la primera variable el texto de la segunda al final, no suelen importar el tamagno de las cadenas
	strrev(letras);//La pone al reves
	strupr(letras);//Pasa las letras a mayusculas
	strlwr(letras);//Pasa las letras a minusculas
	
	
	struct Estructura estt;//Declarando una variable en base a una estructura que se declaro fuera del main, esto es muy similar al orientado a objetos. funciona igual que una variable normal y permite arrays obviamente
	estt.tamagno = 2;//Para acceder o establecer sus propiedades se hace asi
	struct Estructura estt2 = {"nombree", 45};//Para establecer los valores a la vez hay que ponerlos en el orden en el que se declaran
	estt = estt2;//Se pueden igualar asi
	cout<<estt.nombre;
	
	
	num = Funcion1(4,5);//Llamando a una funcion que devuelve int y que pide variables, 
	Funcion2();//Llamando a una funcion que ni devuelve nada(void) ni pide valores
	Funcion3(num);
	Funcion3(dec);//Esta funcion pide un dato generico, se puede usar de varias formas
	Funcion1(3,6);//Aunque una funcion devuelva algo, se puede usar tal cual si fuese necesario
	Funcion4(num);//Esta funcion cambia el valor de la celda de la ram, num se vera perjudicado
	
	
	//Hay pilas, nodos y listas en el otro script, copiar o importar su codigo
	
	
	cout<<'\n';
	system("pause");//Similar al getch pero de la libreria stdlib.h
	system("cls");//Borra toda la consola, de la libreria stdlib.h, en general lo de system es para ejecutar comandos de ese sistema operativo
	//getch();//Con conio importado hace que el exe no se cierre al terminar
	return 0;//Para cerrar y confirmar que todo fue bien
}


template <class UNTIPO>//Se pone aqui tambien
void Funcion3(UNTIPO x){//Pide el tipo que te has inventado(generico)
	//Como ya esta hecho el encabezado mas arriba, se puede llamar mas adelante del encabezado
	cout<<(x * 2);//Usando la variable como si fuese cualquier cosa
}
