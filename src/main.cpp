#include "PriorityQueue.h"

int main(int argc, char* argv[]) {
    PriorityQueue pq = PriorityQueue();
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 8};
    for (int n: a)
        pq.push(n);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
    return 0;
}