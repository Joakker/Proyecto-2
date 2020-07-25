#include "PriorityQueue.h"


PriorityQueue::PriorityQueue() {
    _arr.push_back({0, {0, 0}});
}

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::push(int key, std::pair<int, int> value) {
    _arr.push_back({key, value});
    int current = _arr.size() - 1;
    while (current != 1) {
        if (_arr[current].key > _arr[current >> 1].key) {
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

Entry PriorityQueue::top() {
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
    if ((n << 1) < _arr.size() && _arr[largest].key < _arr[n << 1].key)
        largest = n << 1;
    if ((n << 1) + 1 < _arr.size() && _arr[largest].key < _arr[(n << 1) + 1].key)
        largest = (n << 1) + 1;
    if (n != largest) {
        std::swap(_arr[n], _arr[largest]);
        this->max_heapify(largest);
    }
}

void PriorityQueue::increase_key(std::pair<int,int> value) {
    for (Entry e: _arr) {
        if (e.value.first == value.first && e.value.second == value.second) {
            e.key++;
            return;
        }
    }
    push(1, value);
}