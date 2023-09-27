//
// Created by Ethan's Macbook on 9/26/23.
//
#include <list>
#include <string>
#include <iostream>

#ifndef HW2_ATOMIC_MODEL_COFFEE_MACHINE_C___ATOMICMODELCOFFEEMACHINE_H
#define HW2_ATOMIC_MODEL_COFFEE_MACHINE_C___ATOMICMODELCOFFEEMACHINE_H

#define COFFEE_VALUE  100
#define QUARTER_VALUE 25
#define DIME_VALUE    10
#define NICKEL_VALUE  5


class AtomicModelCoffeeMachine{
public:
    AtomicModelCoffeeMachine();
    ~AtomicModelCoffeeMachine();
    void lambda();
    void delta(std::string input);
    void printInternals();

private:
    int numQuarters, numDimes, numNickels, value;
    bool change;
    std::list<char>* getChange();
    std::list<char>* getNumQuarters(std::list<char>* ret, int numLoops);
    std::list<char>* getNumDimes(std::list<char>* ret, int numLoops);
    std::list<char>* getNumNickels(std::list<char>* ret, int numLoops);
    int getCoffees();







};

#endif //HW2_ATOMIC_MODEL_COFFEE_MACHINE_C___ATOMICMODELCOFFEEMACHINE_H
