//c++
//los comentarios se hacen asi
/*
comentario de varias lineas
*/
//los espacios y saltos no importan, se usan ;s y {}, al compilar y ejecutar se crea un exe, tipo de archivo es .cpp
//aqui << es para meter un dato a una accion y >> es para guardar un dato en algo

#include<iostream>//obligatorio
#include<math.h>//para mas matematicas y raices cuadradas
#include<conio.h>//para el getch de mas abajo, haria que no se cierre
#include<stdlib.h>//se puede usar "system("pause");" para que haga lo mismo que el getch
#include<time.h>//para aleatoriedad y tiempo
#include<string.h>//para hacer strings bien y no arrays de chars cutres
using namespace std;//obligatorio para consola



int Funcion1(int x, int y){//las funciones deben ser declaradas en una linea anterior a la que se va a llamar, en caso contrario se puede hacer la funcion mas abajo pero escribir su encabezado arriba(encabezado es int funcion1(int,int);) y mas abajo igual pero sin el ; y con el codigo
	//las funciones pueden pedir valores para usarlos en su codigo, se introducen al llamarla
	//las funciones pueden ser de cualquier variable teniendo que devolverla o void que no devuelve nada
	return x+y;//devolviendo un int, porque la funcion es int
}
void Funcion2(){//esta funcion es void y no devuelve nada, pero si podria pedir valores
	cout<<"aa";
}
template <class UNTIPO>//opcional: se pone antes del encabezado para que la  funcion sea de un tipo generico
void Funcion3(UNTIPO x);//declarando un encabezado de funcion, porque se llamara mas adelante pero el codigo esta escrito mas abajo
void Funcion4(int& x){//con & te refieres a la celda de la ram de esa variable, al hacerlo se vera repercutido en niveles superiores
	x++;
}
void Funcion5(int *x){}//para que pida una direccion de memoria al llamar a la funcion


int glob = 0;//las variables se pueden crear fuera del main para usarlas en otras funciones

struct Estructura {//se pueden crear estructuras que contienen datos primitivos u otras estructuras para usarlas luego como variables, esto es muy similar al orientado a objetos
	char nombre[10];
	int tamagno;
};
struct Estructuraa {
	char nombre[10];
	int tamagno;
	struct Estructura stru;//una estructura dentro de otra, ej: .estructura.tamagno
} est1, est2;//aqui se estan declarando fuera de una funcion, pero tambien se puede dentro



int main(){//funcion main que se ejecuta al abrir el programa
	
	cout<<"texto que aparece";//imprimir en consola
	cout<<"\n es salto de linea, pero tambien"<<endl<<endl;//se le agrega endl para saltar de linea, se pueden poner mas encadenados
	cout<<"\t a"<<endl;//t seria como presionar tabulador
	
	int num = 2;//creando una variable durante el main
	long nuuum = 45354;//int pero con mas bits, operable con int
	float dec = 3.5;
	double mega = 1.11111;//float pero mas preciso, operable con float
	char letra = 'a';//almacena un caracter, al ser uno se usa la comilla simple y no la doble
	cout<<num;//se pueden usar talcual
	int numm;//no hace falta usar valores iniciales
	int a1, a2, a3 = 0;//se pueden crear varias en una linea
	bool cerouno = 1;//no se suele usar el true o false, bool es un numero de 1 bit expresable como 0 o 1
	const int numerrr = 1600;//variable constante que nunca cambia y ocupa menos 
	num = int(nuuum/10);//hace que si o si devuelva un dato de esa variable
	
	//punteroossss:
	cout<<&mega;//devuelve la direccion de memoria en la ram de esa variable, no el valor que tiene
	double *direccion;//esta variable guarda una direccion de memoria, para usarlo con arrays no hace falta declararlo con [] y se le suma x a la direccion para especificar la posicion, en caso de que sea array de arrays se ponen varios *s. con estructuras en lugar de usar el "." se usa "->"
	direccion = &mega;//ahora guarda la direccion de memoria de esa variable, al usarla sin el asterisco representa una direccion, solo se puede asignar a variables del mismo tipo
	cout<<*direccion;//al usarla con el asterisco representa el valor de esa direccion
	//delete direccion;//borra una variable de la ram usando la direccion de memoria de esta, si la variable fuese un array seria delete[] direccion; (mucho cuidado con esto) (stdlib.h)
	//delete &mega;
	
	fflush(stdin);//elimina el buffer de entrada de consola
	cin>>numm;//guarda la entrada en consola
	cin>>num>>numm;//varios consecutivamente usando los >>
	cout<<endl<<"escribiste:  "<<numm;//concatenaciones
	cout<<num+numm;//las operaciones + - * /
	num=numm;//aunque parezca que no, el = tambien funciona
	num+=3;//funciona con los otros operadores
	num++;//con + o -
	num = num%2;//devuelve el resto de la division
	cout<<sqrt(25);//raiz cuadrada con libreria math.h
	cout<<pow(2,5);//elevar x a y con libreria math.h
	cout<<abs(num);//la version positiva de un numero, viene de stdlib.h
	
	cout.precision(3);//cambia una propiedad de las siguientes impresiones para redondear los floats a esos digitos
	cout<<1.4593;//seria 1.46
	
	
	if(num==3){//las condicionales, se usa el == > < >= <= != para comparar, && es and y || es or
		
	} else if(num==5){//para otra condicion si la anterior no se cumple
		
	}
	 else {// else para el caso contrario
		
	}
	cout<<(4>2);//las condiciones tambien se pueden usar a si, si son ciertas contaran como 1 y si no lo son seran 0 (no existe el true y false)
	switch(num){//para comprobar el estado de una variable
		case 1://cada caso ejecuta un codigo
		
			break;//si no se pusiese break al terminar ese codigo tambien comprobaria el siguiente
		case 2:
			
			break;
		default://default es similar al else
			
			break;
	}
	bool boo = (num==2)? true: false;//una manera de usar bools, lo del ? en adelante es opcional
	
	
	int x = 0;
	while(x<=5){//bucle while que se ejecuta siempre que algo sea cierto
		x++;
		break;//esto es para romper el bucle opcional
	}
	
	do{//esto ejecuta el codigo mientras algo sea cierto pero lo sea o no lo ejecuta primero una vez
		x++;
	}while(x<=8);
	
	for(int i = 0; i<9; i++){//bucle for (iniciar iterador; condicion de cumplir; al terminar el bucle hace)
		cout<<i;
		//break;//tambien vale el break
	}
	
	
	srand(time(NULL));//de aqui en adelante se pueden generar numeros aleatorios, necesita include stdlib.h y time.h
	int aleatorio = 1 + rand()%(100);//generar un rango, se hace con (limite superior) + 1 - (limite inferior), en este caso seria entre 1 y 100
	
	
	int numeros[3] = {1,2,3};//declarar un array con valores predefinidos
	int numeross[4];//si no se especifican valores se usan todas las posiciones con datos por defecto
	cout<<numeros[2];//leer o establecer el valor de una posicion del array, el 0 es el primero	
	int tabla[2][2];//se pueden crear arrays de varias dimensiones
	int tablaa[3][3] = {{1,2,3},{1,2,3}};//hay que pasar de fila para ponerlo todo en una linea
	cout<< tablaa[2][1];//para referirse a una posicion
	num = sizeof(numeross) / sizeof(int);//devuelve cuantas posiciones tiene
	
	char letras[] = {'a','b','c'};//imitando un string equivale a "abc"
	char letrass[] = "123";//las "" sirven para hacer un array de chars, al declararlo el array medira lo mismo que la cadena, teniendo un limite de longitud
	char letrasss[8];//declarando el array de char con un limite
	num = atoi(letrass);//convierte de string a int ignorando los no digitos (include stdlib.h)
	dec = atof(letrass);//convierte de string a float (deberia tener decimales) ignorando los no digitos (include stdlib.h)
	//de aqui en adelante hace falta el include string.h
	cin.getline(letrasss,8,'\n');//igual que el cin>> pero almacena el input en una variable, usando un limite de caracteres y imprimiento algo al final
	num = strlen(letrass);//devuelve la longitud del string
	strcpy(letrasss,letrass);//vuelca el contenido de la variable derecha a la de la izquierda. aqui no importa la longitud
	if(strcmp(letras,letrass)==0){//compara 2 strings, devuelve 0 si son iguales, -1 si la segunda mide mas y 1 si la segunda mide menos
	}
	strcat(letras,letrass);//agnade a la primera variable el texto de la segunda al final, no suelen importar el tamagno de las cadenas
	strrev(letras);//la pone al reves
	strupr(letras);//pasa las letras a mayusculas
	strlwr(letras);//pasa las letras a minusculas
	
	
	struct Estructura estt;//declarando una variable en base a una estructura que se declaro fuera del main, esto es muy similar al orientado a objetos. funciona igual que una variable normal y permite arrays obviamente
	estt.tamagno = 2;//para acceder o establecer sus propiedades se hace asi
	struct Estructura estt2 = {"nombree", 45};//para establecer los valores a la vez hay que ponerlos en el orden en el que se declaran
	estt = estt2;//se pueden igualar asi
	cout<<estt.nombre;
	
	
	num = Funcion1(4,5);//llamando a una funcion que devuelve int y que pide variables, 
	Funcion2();//llamando a una funcion que ni devuelve nada(void) ni pide valores
	Funcion3(num);
	Funcion3(dec);//esta funcion pide un dato generico, se puede usar de varias formas
	Funcion1(3,6);//aunque una funcion devuelva algo, se puede usar tal cual si fuese necesario
	Funcion4(num);//esta funcion cambia el valor de la celda de la ram, num se vera perjudicado
	
	
	//hay pilas, nodos y listas en el otro script, copiar o importar su codigo
	
	
	cout<<'\n';
	system("pause");//similar al getch pero de la libreria stdlib.h
	system("cls");//borra toda la consola, de la libreria stdlib.h, en general lo de system es para ejecutar comandos de ese sistema operativo
	//getch();//con conio importado hace que el exe no se cierre al terminar
	return 0;//para cerrar y confirmar que todo fue bien
}


template <class UNTIPO>//se pone aqui tambien
void Funcion3(UNTIPO x){//pide el tipo que te has inventado(generico)
	//como ya esta hecho el encabezado mas arriba, se puede llamar mas adelante del encabezado
	cout<<(x * 2);//usando la variable como si fuese cualquier cosa
}
