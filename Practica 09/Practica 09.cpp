#include <iostream>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

//funcion agregar elementos a la lista 
void agregarNodo(Nodo*& cabeza, int valor) {
	Nodo* nuevoNodo = new Nodo; //creando el apuntador hacia el nuevo nodos
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevoNodo;
	}
	else {
		Nodo* actual = cabeza;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		actual->siguiente = nuevoNodo;
	}

}
void imprimirlista(Nodo* cabeza) {
	Nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << actual->dato << " ";
		actual = actual->siguiente;
	}
	cout << endl;
}

void borrarlista(Nodo* cabeza) {
	while (cabeza != nullptr) {
		Nodo* siguiente = cabeza->siguiente;
		delete cabeza;
		cabeza = siguiente;
		cout << "elemento borrado ";
	}
}


int main() {
	Nodo* cabeza = nullptr; //declaramos un puntero de memoria nulo
	int  tamanolista;
	cout << "ingrese la cantidad de elementos que desea agregar a la lista: ";
	cin >> tamanolista;

	if (tamanolista <= 0) {
		cout << "cantidad de lementos no valida" << endl;
		return 1;
	}
	for (int i = 0; i < tamanolista; i++) {
		int valor;
		cout << "ingrese dato" << i + 1 << ": ";
		cin >> valor;
		///invocamos nuestra funcion de agregar Nodo
		agregarNodo(cabeza, valor);

	}

	cout << "imporimiendo lista de numeros" << endl;
	imprimirlista(cabeza);

	borrarlista(cabeza);

	return 0;
}