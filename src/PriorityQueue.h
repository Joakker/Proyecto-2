#include <bits/stdc++.h>
#include "Pair.h"

class PriorityQueue {
    private:
        std::vector<Pair>    _arr;
        void    max_heapify(long unsigned int);
    public:
        PriorityQueue();
        ~PriorityQueue();
        bool    empty();
        int     size();
        Pair    top();
        void    push(Pair);
        void    pop();
        void    clear();
};