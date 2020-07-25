#include <bits/stdc++.h>

struct Entry {
    int                 key;
    std::pair<int, int> value;
};

class PriorityQueue {
    private:
        std::vector<Entry>    _arr;
        void    max_heapify(long unsigned int);
    public:
        PriorityQueue();
        ~PriorityQueue();
        bool    empty();
        int     size();
        Entry   top();
        void    push(int, std::pair<int,int>);
        void    pop();
        void    increase_key(std::pair<int,int>);
};