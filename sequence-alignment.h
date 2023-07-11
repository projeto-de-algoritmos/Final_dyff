#pragma once

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::min;
using std::string;
using std::vector;

class SequenceAlingment {
public:
    SequenceAlingment(string x, string y, int mismatch_cost, int gap_cost) {
        this->x             = x;
        this->y             = y;
        this->gap_cost      = gap_cost;
        this->mismatch_cost = mismatch_cost;

        m = x.length();
        n = y.length();

        int size = n + m + 1;
        costs.resize(size);
        for (int i = 0; i < size; i++) {
            costs[i] = vector<int>();
            costs[i].resize(size);
        }

        for (int i = 0; i <= (n + m); i++) {
            costs[i][0] = i * gap_cost;
            costs[0][i] = i * gap_cost;
        }

        min_cost = calculate_minimum_cost();
    }

    int get_minimum_cost() {
        return min_cost;
    };

private:
    int min_cost = 0;
    int gap_cost, mismatch_cost;
    int m, n;
    vector<vector<int>> costs;
    string x, y;

    int calculate_minimum_cost() {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (x[i - 1] == y[j - 1]) {
                    costs[i][j] = costs[i - 1][j - 1];
                } else {
                    costs[i][j] = min({costs[i - 1][j - 1] + mismatch_cost,
                                       costs[i - 1][j] + gap_cost,
                                       costs[i][j - 1] + gap_cost});
                }
            }
        }

        return costs[m][n];
    }
};