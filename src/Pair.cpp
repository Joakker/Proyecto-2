#include <bits/stdc++.h>
#include "Pair.h"

Pair::Pair(std::pair<int,int> p, int freq) {
    this->l = p.first;
    this->r = p.second;
    this->freq = freq;
}
