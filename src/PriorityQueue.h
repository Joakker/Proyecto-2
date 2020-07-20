#include <bits/stdc++.h>

class PriorityQueue {
    private:
        std::vector<int>    _arr;
        void    max_heapify(long unsigned int);
    public:
        PriorityQueue();
        ~PriorityQueue();
        bool    empty();
        int     size();
        int     top();
        void    push(int);
        void    pop();
};