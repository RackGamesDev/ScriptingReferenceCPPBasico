//clases
#include<iostream>
#include<stdlib.h>
using namespace std;

class Objeto{//declarando una clase
	protected:
		int muyProtegido;//esto solo se puede usar en esta clase, ni siquiera en las heredadas de esta
	private://todo lo que haya en private se podra usar solo dentro de la clase (normalmente variables)
		int tamagno;
		string nombre;
	public://todo lo que haya en public se podra usar en otros sitios (normalmente funciones y el constructor)
		int id;
		void Reporte(){
			cout<<"soy "<<nombre<<endl;
		}
		Objeto(int _tamagno, string _nombre, int _id){//el constructor para todas las variables
			tamagno = _tamagno;
			nombre = _nombre;
			id = _id;
		}
		~Objeto(){}//opcional: destructor para eliminar esa variable y todas sus propiedades, ver mas abajo
		void SetTamagno(int _tamagno){//setter, en caso de que las variables sean privadas y no esten en el constructor se puede hacer una funcion especifica para establecerlas (formalidad nada mas)
			tamagno = _tamagno;
		}
		int GetTamagno(){//tambien con los getter devuelven variables privadas fuera del constructor (formalidad nada mas) 
			return tamagno;
		}
		virtual void Mostrar(){//es una funcion con polimorfismo, asi las clases que hereden de esta podran tener funciones normales con el mismo nombre pero con otro codigo, mirar mas abajo en objeto4
			cout<<"mide "<<tamagno<<" nombre "<<nombre<<endl;
		}
};



class Objeto2{//otra forma de declararlo segun sus funciones:
	private:
		int num;
	public:
		void Reporte();//normalmente las funciones se hacen poniendo el encabezado y mas abajo el codigo, esto incluye al constructor
		Objeto2(int);
};
Objeto2::Objeto2(int _num){//se haria asi para poner el codigo fuera usando los encabezados
	num = _num;
}
void Objeto2::Reporte(){//las cosas tanto private como public funcionarian aqui dentro como si nada
	cout<<"tengo "<<num<<endl;
}


class Objeto3{
	private:
		int id;
		int tamagno;
	public:
		void Decir(){
			cout<<id<<tamagno<<endl;
		}
		Objeto3(int _id, int _tamagno){
			id = _id;
			tamagno = _tamagno;
		}
		Objeto3(int _id){//se pueden hacer varios constructores para poder declarar la variable insertando los datos de varias maneras, pero hay que tener cuidado con los tipos
			id = _id;
			tamagno = _id * 10;
		}
};


class Objeto4 : public Objeto{//herencia,  objeto4 tendra todas las cosas de objeto (privadas y publicas) de forma publica, si fuese privae seria de forma privada
//tambien se puede hacer que una clase herede de otra que herede de otra o que herede de varias a la vez poniendo : public clase : public clase. se usarian todas las cosas de sus clases anteriores
	private:
		int distancia;
	public:
		Objeto4(int _tamagno, string _nombre, int _id, int _distancia) : Objeto(_tamagno, _nombre, _distancia){//para hacer el constructor se ponen los atributos de las clases de herencia en orden y luego los de esta clase
			distancia = _distancia;//solo se especifican los atributos de esta clase
		}
		void Mostrar(){//objeto4 hereda de objeto que tiene una virtual void, de esta manera aqui se puede llamar a esa funcion pero al ser objeto4 tendra codigo extra, esto normalmente se hace con encabezados escribiendo el codigo fuera
			Objeto::Mostrar();//lo que haya en mostrar de objeto
			cout<<"distancia "<<distancia<<endl;//codigo extra exclusivo de objeto4
		}
};



int main(){
	Objeto obj1 = Objeto(14, "nom", 1);//declarando una variable de ese objeto, las propiedades hay que ponerlas en el mismo orden que el constructor
	obj1.Reporte();//usando sus funciones publicas
	obj1.id = 3;//usando sus variables publicas (tambien hay que ponerlas en el constructor)
	Objeto obj2(46, "adsf", 2);//otra manera de declararla
	cout<<obj1.GetTamagno();//conseguir una variable privada que no esta en el constructor
	obj1.SetTamagno(3);//cambiar una variable privada que no esta en el constructor 
	obj1.~Objeto();//esto destruye el objeto y todas sus propiedades siempre que se haya declarado un constructor
	Objeto3 objA(3,6);//objeto3 tiene varios constructores y se puede declarar de varias formas, pero hay que tener cuidado con los tipos
	Objeto3 objB(20);
	
	Objeto4 objj = Objeto4(5, "hola", 4, 3);//creando un objeto de una clase que deriva de otra
	objj.Mostrar();//al ser la clase derivada hara el codigo de la clase padre y de la suya propia al ser una funcion compartida
	Objeto *sobj1;
	sobj1 = new Objeto4(5, "hola", 4, 3);//sobj1 se declaro como Objeto pero al ser un puntero se puede hacer un new con cosas de una clase que derive y funcionaria como esta
	sobj1->Mostrar();//se usaria el -> porque es un puntero, no se usaria el "."
	
	system("pause");
	return 0;
}
