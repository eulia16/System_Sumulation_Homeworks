#include "AtomicModelCoffeeMachine.h"
#include "InsufficientFundsException.h"

AtomicModelCoffeeMachine::AtomicModelCoffeeMachine() {
    numQuarters = 0;
    numDimes = 0;
    numNickels = 0;

}

AtomicModelCoffeeMachine::~AtomicModelCoffeeMachine() {


}

void AtomicModelCoffeeMachine::delta(std::string input) {
    //first we will parse the input into tokens
      //char* tokens = strcpy(tokens, input.c_str());
    //we will first update the state of the coffee machine based on the current value

    //if the value was above 100, a coffee will be dispensed, so our value field must be below 100 after
    this->value = this->value % 100;

    //if the getChange field was true, decrement the proper fields
    if(this->change){
        int numLoopsToPerform=0;
        //quarters first
        int numQuarterValue = this->value / QUARTER_VALUE;

        if(numQuarterValue > this->numQuarters)
            numLoopsToPerform = this->numQuarters;
        else
            numLoopsToPerform=numQuarterValue;

        for(int i =0; i< numLoopsToPerform; ++i){
            numQuarters--;
            this->value -= QUARTER_VALUE;
        }

        int numDimeValue = this->value / DIME_VALUE;

        if(numDimeValue > this->numDimes)
            numLoopsToPerform = this->numDimes;
        else
            numLoopsToPerform=numDimeValue;

        for(int i =0; i< numLoopsToPerform; ++i){
            numDimes--;
            this->value -= DIME_VALUE;
        }

        int numNickelValue = this->value / NICKEL_VALUE;

        if(numNickelValue > this->numNickels)
            numLoopsToPerform = this->numNickels;
        else
            numLoopsToPerform = numNickelValue;

        for(int i =0; i< numLoopsToPerform; ++i){
            numNickels--;
            this->value -= NICKEL_VALUE;
        }

    }

    //after dealing with the change, reset the state to false to ensure no stale states
    this->change = false;

    //now we move onto adding the input to the state


    for(char c : input){
        if(c == 'q') {
            numQuarters++;
            value += QUARTER_VALUE;
        }
        if(c == 'd') {
            numDimes++;
            value += DIME_VALUE;
        }
        if(c == 'n') {
            numNickels++;
            value += NICKEL_VALUE;
        }
        if(c == 'w')
            continue;//see if this is correct later
        if(c == 'c')
            this->change = true;
    }

}



void AtomicModelCoffeeMachine::lambda(){
    if(this->value > 99){
        int coffees = getCoffees();
        std::cout << "You received " << coffees << " in coffees" << std::endl;
    }
    if (this->change) {
        std::list<char>* change = getChange();
        std::cout << "You received " <<std::endl;
        for(char c : *change)
            std::cout << c << ",";
        std::cout << " in change" << std::endl;
    }
    if(!this->change && this->value <100){
        std::cout << "Nothing Outputted" << std::endl;
    }
}

void AtomicModelCoffeeMachine::printInternals(){
    std::cout << "Current value: " << this->value << std::endl;
    std::cout << "Current numQuarters: " << this->numQuarters << std::endl;
    std::cout << "Current numDimes: " << this->numDimes << std::endl;
    std::cout << "Current numNickels: " << this->numNickels << std::endl;
    std::cout << "Current value of getChange: " << this->change << std::endl;

}

std::list<char>* AtomicModelCoffeeMachine::getChange(){

    int modulusOfValue = this->value % COFFEE_VALUE;
    std::list<char>* returnValues = new std::list<char>;
    if(modulusOfValue == 0) {
        return returnValues;//if there is no change to output, return the empty list
    }
    else {
        int numLoopsToAddRespectiveCoins = 0;

        int modDividedByQuarterValue = modulusOfValue / QUARTER_VALUE;
        //if the divided amt is larger than this.numQuarters, use this.numQuarters for the loop,
        //and decrement the total value as expected, else just use the modDividedByQuarterVlalue
        if (modDividedByQuarterValue > this->numQuarters)
            numLoopsToAddRespectiveCoins = this->numQuarters;
        else
            numLoopsToAddRespectiveCoins = modDividedByQuarterValue;

        if (this->numQuarters != 0) {
            returnValues = getNumQuarters(returnValues, numLoopsToAddRespectiveCoins);
            modulusOfValue -= (numLoopsToAddRespectiveCoins * QUARTER_VALUE);
            if (modulusOfValue == 0)
                return returnValues;
        }


        int modDividedByDimeValue = modulusOfValue / DIME_VALUE;
        if (modDividedByDimeValue > this->numDimes)
            numLoopsToAddRespectiveCoins = this->numDimes;
        else
            numLoopsToAddRespectiveCoins = modDividedByDimeValue;

        if (this->numDimes != 0) {
            returnValues = getNumDimes(returnValues, numLoopsToAddRespectiveCoins);
            modulusOfValue -= (numLoopsToAddRespectiveCoins * DIME_VALUE);
            if (modulusOfValue == 0)
                return returnValues;
        }


        int modDividedByNickelValue = modulusOfValue / NICKEL_VALUE;
        if (modDividedByNickelValue > this->numNickels)
            numLoopsToAddRespectiveCoins = this->numNickels;
        else
            numLoopsToAddRespectiveCoins = modDividedByNickelValue;

        if (this->numNickels != 0) {
            returnValues = getNumNickels(returnValues, numLoopsToAddRespectiveCoins);
            modulusOfValue -= (numLoopsToAddRespectiveCoins * NICKEL_VALUE);
            if (modulusOfValue == 0)
                return returnValues;
        }


    }

    //if the modulus
    if(modulusOfValue != 0)
         throw new InsufficientFundsException();

    return returnValues;

}

std::list<char>* AtomicModelCoffeeMachine::getNumQuarters(std::list<char>* ret, int numLoops){
    for(int i=0; i< numLoops; ++i){
        ret->push_back('q');
    }
    return ret;
}

std::list<char>* AtomicModelCoffeeMachine::getNumDimes(std::list<char>* ret, int numLoops){
    for(int i=0; i< numLoops; ++i){
        ret->push_back('d');
    }
    return ret;
}

std::list<char>* AtomicModelCoffeeMachine::getNumNickels(std::list<char>* ret, int numLoops){
    for(int i=0; i< numLoops; ++i){
        ret->push_back('n');
    }
    return ret;
}

int AtomicModelCoffeeMachine::getCoffees(){
    return this->value / COFFEE_VALUE;
}

