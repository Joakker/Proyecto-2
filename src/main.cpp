#include <bits/stdc++.h>
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Pair.h"

using namespace std;

void Menu();
void Menu2(int el, int r);
void Menu3();
pair<int,int> EncontrarParMasFrecuente(std::map<pair<int,int>, int> mapar,int nel);

int main(int argc, char* argv[]) {
    int sigma = argc == 1? 27 : std::stoi(argv[1]);
    #define AVAILABLE_ID ++sigma

    int n,el,r,des, metodo;                  // Variable auxiliar
    double tim;
    LinkedList ll;                          // Secuencia a comprimir
    PriorityQueue pq;                       // Aquí se guardan los pares
    std::map<std::pair<int,int>,Pair> dups;// Contiene los duplicados
    pair<int, int> par;
    map<pair<int,int>, int> mapar; 
    srand(time(0));
    Menu();
    cout <<"Numero elementos: ";
    cin >> el;
    cout <<"Rango: ";
    cin >> r;
    sigma = r;
    Menu2(el,r);
    cin >> des;
    while(des != 1 && des != 2){
        cout << "No te pases de listo conmigo muchacho: " << endl;
        cin >> des;
    }
    if(des == 1){
        cout << "Ingrese los numeros:";

        for(int i=0 ; i < el;i++){
        cin >> n;
        while(n > sigma || n < 1){
            cout << "Ingrese un numero dentro del rango" << endl;
            cin >> n;
        }
        ll.addBack(n);
        }
    }
    if(des == 2){
        for(int i=0 ; i < el;i++){
        ll.addBack(rand()%sigma+1);
        }
    }
    cout << "Secuencia de numeros : " << endl;
    ll.printForward();
    cout << endl;
    Menu3();
    cin >> metodo;
    while(des != 1 && des != 2){
        cout << "Porfavor entregue un metodo valido:" << endl;
        cin >> metodo;
    }
    if(metodo == 1){
    clock_t start = clock();  
        do{
            mapar.clear();
            for(LinkedList::iterator i = ll.begin(); i != ll.end() ;++i){
                mapar[{*i,*(i+1)}]++;
            }
            par = EncontrarParMasFrecuente(mapar,sigma);
            if(par.first == 0 && par.second == 0){
                break;
            }
            ll.removepair(par, sigma+1);
            sigma++;
        

        }while(true);
    tim = ((double)clock() - start) / CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"tiempo de ejecucion para compresion de "<< el << " terminos es: " << tim <<endl;
    }



    
    if(metodo == 2){
    clock_t start = clock();     
    do {
        dups.clear();
        
        for (int i = 1; i <= sigma; i++)
            for (int j = 1; j <= sigma; j++)
                dups[{i, j}] = Pair({i, j}, 0);

        for (LinkedList::iterator i = ll.begin(); i != ll.end(); ++i) {
            if (dups[{*i, *(i + 1)}].freq == 0)
                dups[{*i, *(i + 1)}].first = LinkedList::iterator(i);
            dups[{*i, *(i + 1)}].freq++;
            dups[{*i, *(i + 1)}].last = LinkedList::iterator(i);
        }

        for (std::map<std::pair<int,int>,Pair>::iterator i = dups.begin(); i != dups.end(); i++)
            if (i->second.freq > 1)
                pq.push(i->second);

        if (pq.empty())
            break;
        Pair p = pq.top();
        ll.removepair({p.l, p.r}, AVAILABLE_ID);
        pq.clear();
        //ll.printForward();
        //cout << endl;
    } while (true);
    tim = ((double)clock() - start) / CLOCKS_PER_SEC;
    cout<<endl;
    cout<<"tiempo de ejecucion para compresion de "<< el << " terminos es: " << tim <<endl;
    }
    ll.printForward();
    #undef AVAILABLE_ID
    return 0;
}

void Menu(){
    cout <<"*****************************************" << endl;
    cout <<"*    Bienvenidos a la cibercarretera    *" << endl;
    cout <<"*              Amiguito                 *" << endl;
    cout <<"*     escoja el numero de elementos     *" << endl;
    cout <<"*  en la Secuencia y el rango de estos  *" << endl;
    cout <<"*****************************************" << endl;
    cout << endl;

}
void Menu2(int el, int r){
    std::cout <<"*****************************************" << endl;
    cout <<"* Usted ingresara " << el << " elementos          *" << endl; 
    cout <<"* con rango (1-" << r << ") desea hacerlo:        *" << endl;
    cout <<"*           1. Manualmente              *" << endl;
    cout <<"*           2. Aleatoriamente           *" << endl;
    cout <<"*****************************************" << endl;
    cout << endl;
}

void Menu3(){
    cout <<"********************************************" << endl;
    cout <<"*   Ya con los datos entregado elija el    *" << endl;
    cout <<"*metodo con el cual comprimir la Secuencia:*" << endl;
    cout <<"*           1. Metodo directo              *" << endl;
    cout <<"*           2. Metodo Avanzado             *" << endl;
    cout <<"********************************************" << endl;
    cout << endl;

}

pair<int,int> EncontrarParMasFrecuente(std::map<pair<int,int>, int> mapar,int nel){
    pair<int, int> par = {0,0};
    for(int i = 1; i <= nel; i++){
        for(int j = 1; j <= nel; j++){
             if((mapar[{i,j}]>mapar[par]) && mapar[{i,j}]>1){
              par.first = i;
              par.second = j;
                
             }
        }
    } 
    return par;
}

   