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
            costs[i] = vector<int>(size, 0);
        }

        for (int i = 0; i <= (n + m); i++) {
            costs[i][0] = i * gap_cost;
            costs[0][i] = i * gap_cost;
        }

        min_cost = calculate_minimum_cost();
        find_solution();
    }

    int get_minimum_cost() {
        return min_cost;
    };

    string final_x, final_y;

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

    void find_solution() {
        int size = n + m;
        int i = m, j = n;

        int x_pos = size;
        int y_pos = size;

        auto x_tmp = vector<int>(size + 1);
        auto y_tmp = vector<int>(size + 1);

        while (!(i == 0 || j == 0)) {
            if (x[i - 1] == y[j - 1]) {
                x_tmp[x_pos--] = (int)x[i - 1];
                y_tmp[y_pos--] = (int)y[j - 1];
                i--;
                j--;
            } else if (costs[i - 1][j - 1] + mismatch_cost == costs[i][j]) {
                x_tmp[x_pos--] = (int)x[i - 1];
                y_tmp[y_pos--] = (int)y[j - 1];
                i--;
                j--;
            } else if (costs[i - 1][j] + gap_cost == costs[i][j]) {
                x_tmp[x_pos--] = (int)x[i - 1];
                y_tmp[y_pos--] = (int)'_';
                i--;
            } else if (costs[i][j - 1] + gap_cost == costs[i][j]) {
                x_tmp[x_pos--] = (int)'_';
                y_tmp[y_pos--] = (int)y[j - 1];
                j--;
            }
        }

        while (x_pos > 0) {
            if (i > 0)
                x_tmp[x_pos--] = (int)x[--i];
            else
                x_tmp[x_pos--] = (int)'_';
        }
        while (y_pos > 0) {
            if (j > 0)
                y_tmp[y_pos--] = (int)y[--j];
            else
                y_tmp[y_pos--] = (int)'_';
        }

        int id = 1;
        for (i = size; i >= 1; i--) {
            if ((char)y_tmp[i] == '_' && (char)x_tmp[i] == '_') {
                id = i + 1;
                break;
            }
        }

        for (i = id; i <= size; i++)
            final_x += (char)x_tmp[i];
        for (i = id; i <= size; i++)
            final_y += (char)y_tmp[i];
    }
};