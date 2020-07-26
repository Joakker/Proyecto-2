#include <bits/stdc++.h>
#include "LinkedList.h"



using namespace std;
int ContarPosiblesPares(std::map<pair<int,int>, int> mapar,int nel);
pair<int,int> EncontrarParMasFrecuente(std::map<pair<int,int>, int> mapar,int nel);


int main(){
	int nel,num;
	cout<< "Ingrese el numero de elementos que tendra la secuencia aleatoria:" << endl;
	cin >> nel;
	cout<< "Ingrese el rango que tendran los numeros creados" << endl;
	cin >> num;
	LinkedList ll;
	srand(time(0));
	for(int i=0; i<nel ;i++){
		ll.addBack((rand()%num)+1);
	}

	pair<int, int> par;
	pair<int, int> ref (0,0);
	
/*  ll.addFront(5);
	ll.addFront(5);
	ll.addBack(19);
*/
	ll.printForward();
	
/*
	ll.printReverse();
	cout << endl;
	par = make_pair(ll.getFront(), ll.getFront());

	cout << par.first << "  " << par.second << endl;
 */
	map<pair<int,int>, int> mapar;

	/*mapar[{ll.getFront(),ll.getBack()}] = 3;
	mapar[{2,4}] = 6;
	mapar[{14,4}] = 1;
	mapar[{3,4}] = 8;
   */
 	//for(map<pair<int,int>, int>:: iterator map = mapar.begin(); map != mapar.end();map++){
 	//	cout <<"{" << map->first.first << "," << map->first.second << "}" << " " << map->second << endl;
 		
 	//}
 	//map<pair<int,int>,int>::iterator map = mapar.find({ll.getFront(),ll.getBack()}); Encontrar una clave
 	/*if(map!=mapar.end()){
 		
 		cout << map->first.first << " " << map->first.second << " " << map->second << endl;
 	}*/

 	//for(int i = 1; i < nel+1; i++){
 	//	for(int j = 1; j < nel+1; j++){
 	//		mapar[{i,j}] = 0;
 	//	}
 	//}
 	for(LinkedList::iterator i = ll.begin(); i != ll.end() ;++i){
 		mapar[{*i,*(i+1)}]++;
 	}
	cout << ContarPosiblesPares(mapar,nel) << endl;
 	ll.removepair(EncontrarParMasFrecuente(mapar,nel), num+1);
 	ll.printForward();
 	mapar.clear();
 	num++;
 	
 	
  	
	return 0;
}


int ContarPosiblesPares(std::map<pair<int,int>, int> mapar,int nel){
	int it = 0;
	for(int i = 1; i < nel+1; i++){
 		for(int j = 1; j < nel+1; j++){
 			 if(mapar[{i,j}]>1){
 			 	cout << "{" << i << ", " << j << "}" << "= " << mapar[{i,j}] << endl; 
 			 	it++;
 			 }
 		}
 	}
 	cout << endl;
 	return it;
}

pair<int,int> EncontrarParMasFrecuente(std::map<pair<int,int>, int> mapar,int nel){
	pair<int, int> par;
	pair<int, int> ref (0,0);
	for(int i = 1; i < nel+1; i++){
 		for(int j = 1; j < nel+1; j++){
 			 if((mapar[{i,j}]>mapar[par])){
 			  par.first = i;
 			  par.second = j;
 				
 			 }
 		}
 	}
 	//cout << "{" << par.first << ", " << par.second << "}" << endl; 
 	return par;
}

