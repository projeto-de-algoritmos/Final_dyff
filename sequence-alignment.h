#pragma once

#include <iostream>
#include <vector>

class SequenceAlingment {
public:
    std::vector<char> x;
    std::vector<char> y;

    SequenceAlingment() {
        // x.resize()
        std::cout << "SequenceAlingment" << std::endl;
    }
};