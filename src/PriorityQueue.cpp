#include "PriorityQueue.h"


PriorityQueue::PriorityQueue() {
    _arr.push_back(0);
}

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::push(int n) {
    _arr.push_back(n);
    int current = _arr.size() - 1;
    while (current != 1) {
        if (_arr[current] > _arr[current >> 1]) {
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

int PriorityQueue::top() {
    return _arr[1];
}

bool PriorityQueue::empty() {
    return _arr.size() <= 1;
}

int PriorityQueue::size() {
    return _arr.size() - 1;
}


void PriorityQueue::max_heapify(long unsigned int n) {
    long unsigned int largest= n;
    if ((n << 1) < _arr.size() && _arr[largest] < _arr[n << 1])
        largest = n << 1;
    if ((n << 1) + 1 < _arr.size() && _arr[largest] < _arr[(n << 1) + 1])
        largest = (n << 1) + 1;
    if (n != largest) {
        std::swap(_arr[n], _arr[largest]);
        this->max_heapify(largest);
    }
}