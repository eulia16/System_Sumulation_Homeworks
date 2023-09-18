package org.example;

import java.util.*;

public class AtomicModelCoffeeMachine {
    public static final Set<String> potentialInputs = new HashSet<>();
    public static final Set<String> potentialOutputs = new HashSet<>();
    private int numQuarters = 0;
    private int numDimes = 0;
    private int numNickels = 0;
    private double totalMoneyInputted=0;
    private boolean cancel = false;
    private boolean wait = false;



    public AtomicModelCoffeeMachine(){
        potentialInputs.addAll(List.of(new String[]{"Quarter", "Dime", "Nickel", "Cancel", "Wait"}));
        potentialOutputs.addAll(List.of(new String[]{"Quarter", "Dime", "Nickel", "Coffee", "Nothing"}));
        //we were told the base state would be q=10, d=10, n=10, v=0, c=false
        numQuarters = 10;
        numDimes = 10;
        numNickels = 10;

    }







    public static void printPotentialInputs(){


    }


}
