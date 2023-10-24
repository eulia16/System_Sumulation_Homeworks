//
// Created by Ethan's Macbook on 10/24/23.
//

#include "MemoryModel.h"


MemoryModel::MemoryModel(bool one, bool two) {
    this->q1 = one;
    this->q2 = two;
}

MemoryModel::MemoryModel() {
    this->q1 = false;
    this->q2 = false;
}

bool MemoryModel::delta(bool one) {
    bool returnValue = q1;

    q1 = q2;
    q2 = one;
    return returnValue;
}

bool MemoryModel::lambda() {
    return q1;
}