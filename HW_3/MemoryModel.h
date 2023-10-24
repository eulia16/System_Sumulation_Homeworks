//
// Created by Ethan's Macbook on 10/24/23.
//

#ifndef HW_3_MEMORYMODEL_H
#define HW_3_MEMORYMODEL_H


class MemoryModel {

public:
    MemoryModel(bool one, bool two);
    MemoryModel();

    bool delta(bool one);
    bool lambda();

private:
    bool q1, q2;



};


#endif //HW_3_MEMORYMODEL_H
