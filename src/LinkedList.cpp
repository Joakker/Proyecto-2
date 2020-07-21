#include <bits/stdc++.h>
#include "LinkedList.h"


using namespace std;

//Se inicializa la lista enlazada creando 2 nodos que funcionaran como la cabeza 
//y la cola de nuestra lista, no tendran un valor
//debe estar vacio asi que definimos que el nodo siguiente al header es el trailer
//y el nodo anterior sera NULL, de la misma forma el nodo anterior a trailer sera
//header y el nodo siguiente sera NULL
LinkedList::LinkedList(){  
	header = new Nodo;
	trailer = new Nodo;
	header->next = trailer;
	trailer->prev = header;
	header->prev = NULL;
	trailer->next = NULL;

}
//Destructor del LinkedList
//Se van elinando los nodos a partir del siguiente a header
//hasta el anterior a trailer, dejando una LinkedList vacia
//luego se elimina el header y el trailer de forma individual

LinkedList::~LinkedList(){
	while(header->next != trailer){
		removeFront();
	}
	delete trailer;
	delete header;
}
//Entrega la data del Nodo siguiente al header
int LinkedList::getFront(){
	return header->next->data;
}
//Entrega la data de Nodo anterior al trailer
int LinkedList::getBack(){
	return trailer->prev->data;
}
//Añadir un Nodo con data al Inicio de la LinkedList
//Se crea el nodo que añadiremos y se le entrega 
//la data necesaria, luego se define el anterior 
//del nodo recien creado como el header y al siquiente
//como el actual nodo siguente que tiene header
//finalizamos definiendo el nodo anterior al siguiente actual
//como nuestro nuevo Nodo y al Nodo siguiente a header como
//nuestro nuevo nodo 
void LinkedList::addFront(int val){
	Nodo *nd = new Nodo;
	nd->data = val;
	nd->prev = header;
	nd->next = header->next;

	header->next->prev = nd;
	header->next = nd;  
}
//de forma analoga al addFront pero aplicando el trailer
void LinkedList::addBack(int val){
	Nodo *nd = new Nodo;
	nd->data = val;
	nd->prev = trailer->prev;
	nd->next = trailer;

	trailer->prev->next = nd;
	trailer->prev = nd;
}
//Se crea un nodo definido como definido como header->next->next
//luego se borra el primer nodo con data (siguiente a header)
//se define al nodo creado como el nuevo siguiente a header y
//se define que el nodo anterior al creado es header,
//eliminando todo rastro del nodo removido
void LinkedList::removeFront(){
	Nodo *nd = header->next->next;
	delete header->next;
	header->next= nd;
	nd->prev= header;


}
//analogo a removeFront
void LinkedList::removeBack(){
	Nodo *nd = trailer->prev->prev;
	delete trailer->prev;
	trailer->prev= nd;
	nd->next = trailer;

}
//Se crea un nodo definido como el anterior al trailer
//luego se crea un ciclo donde se imprime la data 
//del nodo actual y se define ahora como el anterior a si mismo
//este proceso se repite mientras el nodo definido no sea el header
//su funcion es imprimir la lista doblemente enlazada al revez
void LinkedList::printReverse(){
	Nodo *nd = trailer->prev;

	while(nd!=header){
		cout<< nd->data << " ";
		nd = nd->prev;
	}

}
void LinkedList::printForward(){
	Nodo *nd = header->next;

	while(nd!=trailer){
		cout<< nd->data << " ";
		nd = nd->next;
	}
}