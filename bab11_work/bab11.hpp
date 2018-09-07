//
// Created by opot on 10.12.17.
//

#ifndef SOURCE_BAB11_H
#define SOURCE_BAB11_H

#include <vector>
#include <set>

#include "bab.hpp"

struct BabNode {
    BabNode(Matrix* m, float z_low, std::set<int>* duplicated);
    BabNode(const Matrix* m, const float z_low, const std::set<int>* duplicated);
    void     calculate_void_measures();
    Solution Bab11(const Matrix* m);

    Matrix*                           matrix;
    static float                      threshold;
    float                             z_low;
    std::set<int>*                    duplicated;
    std::vector<std::pair<int, int>>* voids;//<column, void_measure>
    int branchingId = -1;

    bool isBranching();
};

Matrix* merge_clusters(const Matrix* m1, const Matrix* m2);

#endif //SOURCE_BAB11_H