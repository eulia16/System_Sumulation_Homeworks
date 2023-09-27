#include <iostream>
#include <string>

#include "AtomicModelCoffeeMachine.h"

using namespace std;

int main() {



    AtomicModelCoffeeMachine* atomicModel = new AtomicModelCoffeeMachine();

    cout <<  "Welcome to the Coffee Atomic Model" << endl;
    cout << "You will have the option of entering input from the set: " << endl;
    cout << "{ q, d, n, c, w }" << endl;
    cout << "You will also get output from the following set: " << endl;
    cout <<  "{ q, d, n, c, Nothing }"  << endl;
    cout << "You are now entering the model: (remember lambda before delta ;) )" << endl;

    while(true) {
        string input;
        cout << "Please enter more input" << endl;
        cin >> input;

        if(input == "exit")
            exit(0);
        //for testing purposes
        if(input == "print"){
            atomicModel->printInternals();
            continue;
        }

        atomicModel->lambda();
        atomicModel->delta(input);
        cout << endl;
    }




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
