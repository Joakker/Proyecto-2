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

//de forma analoga al addFront pero aplicando el trailer
void LinkedList::addBack(int val){
	Nodo *nd = new Nodo;
	nd->data = val;
	nd->prev = trailer->prev;
	nd->next = trailer;

	trailer->prev->next = nd;
	trailer->prev = nd;
}
//Se crea un nodo definido como header->next->next
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

void LinkedList::printForward(){
	Nodo *nd = header->next;

	while(nd!=trailer){
		cout<< nd->data << " ";
		nd = nd->next;
	}
	cout<<endl;
}

void LinkedList::removepair(std::pair<int, int> par, int lim){
	Nodo *actual= header->next;
	while(actual!=trailer){
		if(actual->data == par.first && actual->next->data == par.second){
		//cout << "El nodo actual es: " <<"{" << actual->data << ", " << actual->next->data << "}" << endl;
		actual->data = lim;
		delete actual->next;
		actual->next = actual->next->next;
		actual->next->prev = actual;
		}
	actual = actual->next;
	}
}

LinkedList::iterator::self_type LinkedList::iterator::operator++() {
	self_type i = *this;
	ptr_ = ptr_->next;
	return i;
}

int& LinkedList::iterator::operator*() {
	return ptr_->data;
}

bool LinkedList::iterator::operator==(const LinkedList::iterator::self_type& rhs) {
	return ptr_ == rhs.ptr_;
}

bool LinkedList::iterator::operator!=(const LinkedList::iterator::self_type& rhs) {
	return ptr_ != rhs.ptr_;
}

LinkedList::iterator LinkedList::begin() {
	return iterator(header->next);
}

LinkedList::iterator LinkedList::end() {
	return iterator(trailer->prev);
}

LinkedList::iterator::iterator(Nodo* n) {
	this->ptr_ = n;
}

LinkedList::iterator::iterator() {
	this->ptr_ = nullptr;
}

LinkedList::iterator LinkedList::iterator::operator+(int n) {
	return iterator(this->ptr_->next);
}