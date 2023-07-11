#include <iostream>

#include "sequence-alignment.h"

int main() {
    string t1 = "AGGGCT";
    string t2 = "AGGCA";
    SequenceAlingment alignment(t1, t2, 3, 2);

    std::cout << "Min cost " << alignment.get_minimum_cost() << std::endl;
}