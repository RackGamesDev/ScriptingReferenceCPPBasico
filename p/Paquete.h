//Podria incluir otras librerias
//Esto es un paquete y se debe guardar como .h, no como .cpp
//Las librerias luego pueden compartir codigo con otros scripts al importarlas
//No hay que compilar los .h

namespace paquetico{//Lo que haya dentro de un namespace sera solo propio contando como otro script excepto por los include y los using
//Cosas publicas que se podran usar fuera
int Sumar(int x, int y){
	return x + y;
}
int tiempo = 10;
struct Cubo{
	int x;
	int y;
	int z;
};
class Objeto{
	private:
		int noo;
	public:
		int tamagno;
		void Aumentar(){
			tamagno++;
		}
		Objeto(int _noo, int _tamagno){
			noo = _noo;
			tamagno = _tamagno;
		}
};
}
int hora = 60;//Esto esta fuera del namespace y se podra usar simplemente importandola y ya


