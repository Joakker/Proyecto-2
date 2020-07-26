#include <bits/stdc++.h>
#include "LinkedList.h"
#include "PriorityQueue.h"


using namespace std;


#define AVAILABLE_CODE	++sigma


int main(int argc, char* argv[]){
	int n;
	int sigma = argc == 1? 27: std::stoi(argv[1]);
	LinkedList 					ll;
	PriorityQueue 				pq;
	map<pair<int, int>, Pair>	hash;

	while (cin >> n) {
		ll.addBack(n);
	}

	for (int i = 1; i <= sigma; i++) {
		for (int j = 1; j <= sigma; j++) {
			hash[{i, j}] = Pair({i, j},0);
		}
	}

	for (LinkedList::iterator i = ll.begin(); i != ll.end(); ++i) {
		pair<int, int> p = make_pair(*i, *(i + 1));
		if (hash[p].freq == 0) {
			hash[p].first = LinkedList::iterator(i);
		}
		hash[p].freq++;
		hash[p].last = LinkedList::iterator(i);
	}

	for (map<pair<int,int>,Pair>::iterator i = hash.begin(); i != hash.end(); i++) {
		if ((*i).second.freq > 1) {
			pair<int,int> p = (*i).first;
			pq.push(Pair(p, (*i).second.freq));
		}
	}

	while (!pq.empty()) {
		Pair p = pq.top();
		;
		pq.pop();
	}
	return 0;
}