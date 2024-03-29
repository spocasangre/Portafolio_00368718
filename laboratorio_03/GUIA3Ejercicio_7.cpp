#include <iostream>

using namespace std;

struct listaDatos{
	int num;
	listaDatos* sig;
};
void insertarDatos(listaDatos** pInicio);
void imprimirMenu(void);
void imprimirDatos(listaDatos* lista);
void eliminarNum(listaDatos** lista, int busq);

int main(void) {
	int opcion=0, busca=0;
	listaDatos* pInicio = NULL;
	do{
		imprimirMenu(); cin >> opcion;

		switch (opcion) {
		case 1:
			insertarDatos(&pInicio);
			break;
		case 2:
			imprimirDatos(pInicio);
			break;
		case 3:
			cout<<"Ingrese el numero que desea eliminar: ";cin>>busca;
			cout<<endl;
			eliminarNum(&pInicio, busca);
			break;		
		}

	} while (opcion != 0);

	return 0;
}

void imprimirMenu(void) {
	cout << "MENU PRINCIPAL" << endl << endl;
	cout << "1. Introducir datos (numeros enteros) . . ." << endl;
	cout << "2. Mostrar lista . . ." << endl;
	cout << "3. Borrar un numero especifico. . ." << endl;
	cout << "0. Salir   Su opcion:" << endl;
}

void insertarDatos(listaDatos** pInicio) {
	listaDatos* nuevo = new listaDatos;
	cout << "Ingrese un numero: "; cin >> nuevo->num;
	nuevo->sig = NULL;

	if (!*pInicio)
		* pInicio = nuevo;
	else {
		listaDatos* aux = *pInicio;
		
		while (aux->sig)
			aux = aux->sig;

		aux->sig = nuevo;
	}
}

void imprimirDatos(listaDatos* lista){
	if(!lista)
		return;
	else{
		cout << "Numero:\t" << lista->num << endl;
		imprimirDatos(lista->sig);		 
	}	
}

void eliminarNum(listaDatos** lista, int busq) {
	if (*lista) {
		if ((*(*lista)).num == busq) {
			*lista = (*(*lista)).sig;
			eliminarNum(lista, busq);
		}
		else {
			eliminarNum(&(*(*lista)).sig, busq);
		}
	}
}

