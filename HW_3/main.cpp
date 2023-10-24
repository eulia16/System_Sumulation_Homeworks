#include <iostream>
#include "NetworkModel.h"

using namespace std;

int main() {
    NetworkModel* networkModel = new NetworkModel();
    int networkTick = 0;

    cout << "You are entering the network model, please enter some shit(a couplt of booleans)" << endl;


    while(true) {
        cout << "Enter another line" << endl;


        string input;
        cin >> input;

        if(input == "exit")
            exit(0);

        cout << "Network Tick: " + networkTick << endl;
        //if we want to have one network tick present as expected
        for(int i=0; i<3; ++i){

            //incase you want the states of each model as well
//                System.out.println("Information regarding each atomic model");
//                Thread.sleep(1000);
//                System.out.println("XOR1 state: " + networkModel.getXOR2().lamdba());
//                System.out.println("XOR2 state: " + networkModel.getXOR2().lamdba());
//                System.out.println("Memory Model state: " + networkModel.getMemoryModel().lambda());
            //calls the labmdas of each model
            networkModel->couplings();
            networkModel->delta(input);

        }

        //outputs the result after 3 ticks
        networkModel->lamdba();

        networkTick++;


    }

    return 0;
}
