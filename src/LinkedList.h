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

private:
	Nodo *header;
	Nodo *trailer;

};
