#include "PriorityQueue.h"


PriorityQueue::PriorityQueue() {
    _arr.push_back(Pair());
}

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::push(Pair p) {
    _arr.push_back(p);
    int current = _arr.size() - 1;
    while (current != 1) {
        if (_arr[current].freq > _arr[current >> 1].freq) {
            std::swap(_arr[current], _arr[current >> 1]);
            current >>= 1;
        } else break;
    }
}

void PriorityQueue::pop() {
    if (_arr.size() == 1)
        return;
    std::swap(_arr[1], _arr[_arr.size() - 1]);
    _arr.pop_back();
    max_heapify(1);
}

Pair PriorityQueue::top() {
    return _arr[1];
}

bool PriorityQueue::empty() {
    return _arr.size() <= 1;
}



void PriorityQueue::max_heapify(long unsigned int n) {
    long unsigned int largest= n;
    if ((n << 1) < _arr.size() && _arr[largest].freq < _arr[n << 1].freq)
        largest = n << 1;
    if ((n << 1) + 1 < _arr.size() && _arr[largest].freq < _arr[(n << 1) + 1].freq)
        largest = (n << 1) + 1;
    if (n != largest) {
        std::swap(_arr[n], _arr[largest]);
        this->max_heapify(largest);
    }
}


void PriorityQueue::clear() {
    _arr.clear();
    _arr.push_back(Pair());
}