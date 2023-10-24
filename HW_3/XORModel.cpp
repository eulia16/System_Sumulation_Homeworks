//
// Created by Ethan's Macbook on 10/24/23.
//

#include "XORModel.h"

bool XORModel::delta(bool x1, bool x2) {
    this->s = x1 != x2;

}

bool XORModel::lambda() {
    return this->s;
}