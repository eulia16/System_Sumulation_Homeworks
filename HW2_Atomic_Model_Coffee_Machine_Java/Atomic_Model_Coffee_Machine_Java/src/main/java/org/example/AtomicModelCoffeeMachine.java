package org.example;

import java.util.*;

public class AtomicModelCoffeeMachine {
    private int numQuarters = 0;
    private int numDimes = 0;
    private int numNickels = 0;
    private int value=0;
    private boolean getChange = false;

    private final static int COFFEE_VALUE = 100;
    private final static int QUARTER_VALUE = 25;
    private final static int DIME_VALUE = 10;
    private final static int NICKEL_VALUE = 5;

    public AtomicModelCoffeeMachine(){
        //we were told the base state would be q=10, d=10, n=10, v=0, c=false
        numQuarters = 10;
        numDimes = 10;
        numNickels = 10;
    }



    //takes in new input and prints out output
    //Lambda = (Xn1, Sn)->Sn+1
    public void lambda() throws InsufficientChangeException {
        //we will perform a set of actions based on the previous input
        if(this.value > 99){
            int coffees = getNumCoffees();
            System.out.println("You received " + coffees + " in coffees");
        }
        if (this.getChange) {
            List<Character> change = getChange();
            System.out.println("You received " + change + " in change");
        }
        if(!this.getChange && this.value <100){
            System.out.println("Nothing Outputted");
        }
    }

    //these functions(getChange and getNumCoffees will be non-destructive regarding the state of the model)
    private List<Character> getChange() throws InsufficientChangeException {
        int modulusOfValue = this.value % COFFEE_VALUE;
        List<Character> returnValues = new ArrayList<>();
        if(modulusOfValue == 0) {
            return returnValues;//if there is no change to output, return the empty list
        }
        else{
            int numLoopsToAddRespectiveCoins=0;

            int modDividedByQuarterValue = modulusOfValue / QUARTER_VALUE;
            //if the divided amt is larger than this.numQuarters, use this.numQuarters for the loop,
            //and decrement the total value as expected, else just use the modDividedByQuarterVlalue
            if(modDividedByQuarterValue > this.numQuarters)
                numLoopsToAddRespectiveCoins = this.numQuarters;
            else
                numLoopsToAddRespectiveCoins = modDividedByQuarterValue;

            if(this.numQuarters !=0 ) {
                returnValues = getNumQuarters(returnValues, numLoopsToAddRespectiveCoins);
                modulusOfValue -= (numLoopsToAddRespectiveCoins * QUARTER_VALUE);
                if (modulusOfValue == 0)
                    return returnValues;
            }


            int modDividedByDimeValue = modulusOfValue / DIME_VALUE;
            if(modDividedByDimeValue > this.numDimes)
                numLoopsToAddRespectiveCoins = this.numDimes;
            else
                numLoopsToAddRespectiveCoins = modDividedByDimeValue;

            if(this.numDimes != 0) {
                returnValues = getNumDimes(returnValues, numLoopsToAddRespectiveCoins);
                modulusOfValue -= (numLoopsToAddRespectiveCoins * DIME_VALUE);
                if (modulusOfValue == 0)
                    return returnValues;
            }


            int modDividedByNickelValue = modulusOfValue / NICKEL_VALUE;
            if(modDividedByNickelValue > this.numNickels)
                numLoopsToAddRespectiveCoins = this.numNickels;
            else
                numLoopsToAddRespectiveCoins = modDividedByNickelValue;

            if(this.numNickels !=0) {
                returnValues = getNumNickels(returnValues, numLoopsToAddRespectiveCoins);
                modulusOfValue -= (numLoopsToAddRespectiveCoins * NICKEL_VALUE);
                if (modulusOfValue == 0)
                    return returnValues;
            }


        }

        //if the modulus
        if(modulusOfValue != 0)
            throw new InsufficientChangeException();

        return returnValues;
    }


    void printInternals(){
        System.out.println("Current value: " + this.value);
        System.out.println("Current numQuarters: " + this.numQuarters);
        System.out.println("Current numDimes: " + this.numDimes);
        System.out.println("Current numNickels: " + this.numNickels);
        System.out.println("Current value of getChange: " + this.getChange);

    }

    //getChangeSubMethods
    private List<Character> getNumQuarters(List<Character> ret, int numLoops){
        for(int i=0; i< numLoops; ++i){
            ret.add('q');
        }
        return ret;
    }
    private List<Character> getNumDimes(List<Character> ret, int numLoops){
        for(int i=0; i< numLoops; ++i){
            ret.add('d');
        }
        return ret;
    }
    private List<Character> getNumNickels(List<Character> ret, int numLoops){
        for(int i=0; i< numLoops; ++i){
            ret.add('n');
        }
        return ret;
    }

    private int getNumCoffees() {
        return this.value/COFFEE_VALUE;
    }

    //transitions states of coffee machine
    //Delta = Sn->Yn
    public void delta(String input){
        //first we will parse the input into tokens
        char[] tokens = input.toCharArray();
        //we will first update the state of the coffee machine based on the current value

        //if the value was above 100, a coffee will be dispensed, so our value field must be below 100 after
        this.value = this.value % 100;

        //if the getChange field was true, decrement the proper fields
        if(this.getChange){
            int numLoopsToPerform=0;
            //quarters first
            int numQuarterValue = this.value / QUARTER_VALUE;

            if(numQuarterValue > this.numQuarters)
                numLoopsToPerform = this.numQuarters;
            else
                numLoopsToPerform=numQuarterValue;

            for(int i =0; i< numLoopsToPerform; ++i){
                numQuarters--;
                this.value -= QUARTER_VALUE;
            }

            int numDimeValue = this.value / DIME_VALUE;

            if(numDimeValue > this.numDimes)
                numLoopsToPerform = this.numDimes;
            else
                numLoopsToPerform=numDimeValue;

            for(int i =0; i< numLoopsToPerform; ++i){
                numDimes--;
                this.value -= DIME_VALUE;
            }

            int numNickelValue = this.value / NICKEL_VALUE;

            if(numNickelValue > this.numNickels)
                numLoopsToPerform = this.numNickels;
            else
                numLoopsToPerform = numNickelValue;

            for(int i =0; i< numLoopsToPerform; ++i){
                numNickels--;
                this.value -= NICKEL_VALUE;
            }

        }

        //after dealing with the change, reset the state to false to ensure no stale states
        this.getChange = false;

        //now we move onto adding the input to the state

        for(char c : tokens){
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
                this.getChange = true;
        }

    }
}
