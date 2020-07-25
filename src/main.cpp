#include <bits/stdc++.h>
#include "LinkedList.h"
#include "PriorityQueue.h"


using namespace std;


int main(int argc, char* argv[]){
	int n;
	LinkedList ll;
	PriorityQueue pq;
	map<pair<int, int>, int> stuff;
	
	while (cin >> n) {
		ll.addBack(n);
	}
	
	for (int i = 1; i <= 27; i++)
		for (int j = 1; j <= 27; j++)
			stuff[{i, j}] = 0;
	for (LinkedList::iterator i = ll.begin(); i != ll.end(); ++i) {
		pair<int,int> a = {*i, *(i + 1)};
		stuff[a]++;
		pq.increase_key(a);
	}
	while (!pq.empty()) {
		cout << "{" << pq.top().value.first << ", " << pq.top().value.second << "} ";
		pq.pop();
	}
	cout << endl;
	for (int i = 1; i <= 27; i++)
		for (int j = 1; j <= 27; j++)
			if (stuff[{i, j}] > 1)
				cout << "{" << i <<", "<< j << "} = " << stuff[{i, j}] << " ";
	return 0;
}