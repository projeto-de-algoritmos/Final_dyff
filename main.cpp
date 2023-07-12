#include <iostream>

#include "sequence-alignment.h"

using std::cout;
using std::endl;

int main(int argc, char** argv) {
    if (argc != 3) {
        std::printf("Usage: %s \"string1\" \"string2\"", argv[0]);
        exit(1);
    }

    string t1         = argv[1];
    string t2         = argv[2];
    int mismatch_cost = 3;
    int gap_cost      = 2;

    SequenceAlingment alignment(t1, t2, mismatch_cost, gap_cost);

    int cost     = alignment.get_minimum_cost();
    auto final_x = alignment.final_x;
    auto final_y = alignment.final_y;

    cout << "Min cost " << cost << endl;
    cout << "X: " << final_x << endl;
    cout << "Y: " << final_y << endl;
}