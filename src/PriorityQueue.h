#include <bits/stdc++.h>
#include "Pair.h"

class PriorityQueue {
    private:
        std::vector<Pair>    _arr;
        /**
         * Ordena a _arr de manera que cumpla las características
         * de un MaxHeap
         * 
         * @param n Indica el nodo raíz, bajo el cual se ordena
         *          el MaxHeap.
        */
        void    max_heapify(long unsigned int);
    public:
        /**
         * Constructor por defecto
         */
        PriorityQueue();
        /**
         * Destructor
         */
        ~PriorityQueue();
        /**
         * Indica si hay elementos aún en el PriorityQueue. Como
         * el primer elemento de _arr no se usa, empty() retorna
         * true si este tiene un tamaño de 1
         * 
         * @return  Si acaso hay elementos en cola
         */
        bool    empty();

        /**
         * Retorna el siguiente elemento en cola. Como PriorityQueue
         * relaciona los elementos por su frecuencia, éste elemento
         * es el que posee la mayor de ellas.
         * 
         * @return  El elemento con mayor frecuencia en cola. Si
         *          hay más de uno, retorna sólo el primero de ellos
         *          en el arreglo.
         */
        Pair    top();

        /**
         * Encola el parámetro p en la PriorityQueue.
         * 
         * @param   p   El elemento a encolar
         */
        void    push(Pair);

        /**
         * Quita el siguiente elemento en la cola pero no lo retorna.
         * Véase top() para tomar éste elemento sin cambiarlo.
         * 
         * @see     top()
         */
        void    pop();

        /**
         * Quita todos los elementos de la cola, limpiando así la
         * instancia de PriorityQueue.
         * 
         * @see     pop()
         */
        void    clear();
};