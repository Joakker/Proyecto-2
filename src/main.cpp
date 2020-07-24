#include <bits/stdc++.h>
#include "LinkedList.h"
#include "PriorityQueue.h"



using namespace std;


int main(int argc, char* argv[]){
	int n;
	LinkedList ll;
	PriorityQueue pq;
	while (cin >> n) {
		ll.addBack(n);
	}
	for (int i: ll) {
		pq.push(i);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}