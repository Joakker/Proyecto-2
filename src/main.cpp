#include <bits/stdc++.h>
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Pair.h"



int main(int argc, char* argv[]) {
    int sigma = argc == 1? 27 : std::stoi(argv[1]);
    #define AVAILABLE_ID ++sigma

    int n;                                  // Variable auxiliar
    LinkedList ll;                          // Secuencia a comprimir
    PriorityQueue pq;                       // Aquí se guardan los pares
    std::map<std::pair<int,int>,Pair> dups; // Contiene los duplicados

    while (std::cin >> n) {
        ll.addBack(n);
    }

    do {
        dups.clear();
        
        for (int i = 1; i <= sigma; i++)
            for (int j = 1; j <= sigma; j++)
                dups[{i, j}] = Pair({i, j}, 0);

        for (LinkedList::iterator i = ll.begin(); i != ll.end(); ++i) {
            if (dups[{*i, *(i + 1)}].freq == 0)
                dups[{*i, *(i + 1)}].first = LinkedList::iterator(i);
            dups[{*i, *(i + 1)}].freq++;
            dups[{*i, *(i + 1)}].last = LinkedList::iterator(i);
        }

        for (std::map<std::pair<int,int>,Pair>::iterator i = dups.begin(); i != dups.end(); i++)
            if (i->second.freq > 1)
                pq.push(i->second);

        if (pq.empty())
            break;
        Pair p = pq.top();
        ll.removepair({p.l, p.r}, AVAILABLE_ID);
        pq.clear();
    } while (true);

    ll.printForward();

    #undef AVAILABLE_ID
    return 0;
}