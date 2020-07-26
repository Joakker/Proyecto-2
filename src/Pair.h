#ifndef PAIR_H
#define PAIR_H

#include "LinkedList.h"


struct Pair {
    int l, r;
    int freq;
    LinkedList::iterator first;
    LinkedList::iterator last;
    Pair(std::pair<int,int>, int);
    Pair();
};


#endif