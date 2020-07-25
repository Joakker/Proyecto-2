#include <bits/stdc++.h>

class Nodo{
private:
	int data;
	Nodo *prev;
	Nodo *next;

	friend class LinkedList;
};

class LinkedList{
public:
	LinkedList();
	~LinkedList();
	int getFront();
	int getBack();
	void addFront(int val);
	void addBack(int val);
	void removeFront();
	void removeBack();
	void printReverse();
	void printForward();
	
	class iterator {
	public:
		typedef iterator self_type;
		typedef Nodo* pointer;
		self_type operator++();
		int& operator*();
		iterator operator+(int);
		bool operator==(const self_type&);
		bool operator!=(const self_type&);
		iterator(Nodo*);
	private:
		pointer ptr_;
	};

	iterator begin();
	iterator end();
private:
	Nodo *header;
	Nodo *trailer;

};
