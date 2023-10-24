//
// Created by Ethan's Macbook on 10/24/23.
//

#ifndef HW_3_NETWORKMODEL_H
#define HW_3_NETWORKMODEL_H

#include "XORModel.h"
#include "MemoryModel.h"
#include <iostream>
#include <string>


class NetworkModel {

public:
    NetworkModel();
    void lamdba();
    void couplings();
    void delta(std::string s);
    XORModel* getXOR1();
    XORModel* getXOR2();
    MemoryModel* getMemoryModel();




private:
    XORModel* XOR1, *XOR2;
    MemoryModel* M;
    bool state, XOR1Out=false, XOR2Out = false, memModelOut = false;



};



#endif //HW_3_NETWORKMODEL_H
