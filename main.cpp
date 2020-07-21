#include <bits/stdc++.h>
#include "LinkedList.h"



using namespace std;


int main(){

	LinkedList ll;

	ll.addFront(5);
	ll.addFront(5);
	ll.addBack(19);

	ll.printForward();
	cout << endl;
	ll.printReverse();
	cout << endl;


	return 0;
}