//
// Created by Ethan's Macbook on 10/24/23.
//

#include "NetworkModel.h"


NetworkModel::NetworkModel(){
    this->XOR1 = new XORModel();
    this->XOR2 = new XORModel;
    this->M = new MemoryModel();
    this->state = M->lambda();

}
void NetworkModel::lamdba(){
    std::cout << "Output: " << this->state << std::endl;
}
void NetworkModel::couplings(){
    XOR1Out = XOR1->lambda();
    XOR2Out = XOR2->lambda();
    memModelOut = M->lambda();
    state = XOR2Out;

}
void NetworkModel::delta(std::string s){
    bool x1, x2;

    char split[s.size() + 1];

    for(int i=0; i<s.size(); ++i){
        split[i] = s[i];
    }
    split[s.size()] = '\0';

    if(s[0] == '1')
        x1 = true;
    else
        x1 = false;
    if(split[1] == '1')
        x2 = true;
    else
        x2 = false;

    //input goes into XOR1 first, then to XOR2, and then to the output as well as the MemoryModel

    XOR1->delta(x1, x2);

    bool outputXOR2 = XOR2->delta(XOR1Out, memModelOut);

    bool outputMemoryModel = M->delta(XOR2Out);

}
XORModel* NetworkModel::getXOR1(){
    return this->XOR1;
}
XORModel* NetworkModel::getXOR2(){
    return this->XOR2;
}
MemoryModel* NetworkModel::getMemoryModel(){
    return this->M;
}
