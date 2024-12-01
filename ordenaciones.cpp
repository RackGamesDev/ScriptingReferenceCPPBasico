#include <iostream>
#include<conio.h>

using namespace std;

int main(){//Algunos algoritmos de ordenacion de arrays

	int numeros1[] = {1,0,2,9,3,8,4,7,5,6};
	//Burbuja
	int aux1;
	for(int i=0; i<sizeof(numeros1) / sizeof(int); i++){
		for(int ii=0; ii<sizeof(numeros1) / sizeof(int); ii++){
			if (numeros1[ii] > numeros1[ii+1]){
				aux1 = numeros1[ii];
				numeros1[ii] = numeros1[ii+1];
				numeros1[ii+1] = aux1;
			}
		}
	}

	
	int numeros2[] = {1,0,2,9,3,8,4,7,5,6};
	//Insercion
	int aux2, pos;
	for (int i=0; i<sizeof(numeros2) / sizeof(int); i++){
		pos = i;
		aux2 = numeros2[i];
		while((pos>0)&&(numeros2[pos-1]>aux2)){
			numeros2[pos]= numeros2[pos-1];
			pos--;
		}
		numeros2[pos] = aux2;
	}
	
	
	int numeros3[] = {1,0,2,9,3,8,4,7,5,6};
	//Seleccion
	int aux3, min;
	for (int i=0; i<sizeof(numeros3); i++){
		min = i;
		for (int ii=i+1; ii<sizeof(numeros3); ii++){
			if (numeros3[ii] < numeros3[min]){
				min = ii;
			}
		}
		aux3 = numeros3[i];
		numeros3[i] = numeros3[min];
		numeros3[min] = aux3;
	}
	
	
	for (int i=0; i<10; i++){
		cout<<numeros1[i];
	}
	cout<<"\n";
	for (int i=0; i<10; i++){
		cout<<numeros2[i];
	}
	cout<<"\n";
	for (int i=0; i<10; i++){
		cout<<numeros3[i];
	}
	
	getch();
	return 0;
}
