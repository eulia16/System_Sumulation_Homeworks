package org.example;

import java.util.Scanner;

/**
 * Remember Lambda before delta!!!
 */
public class App 
{
    public static void main( String[] args ) throws InsufficientChangeException {

        Scanner scanner = new Scanner(System.in);
        AtomicModelCoffeeMachine singleton = new AtomicModelCoffeeMachine();

        System.out.println( "Welcome to the Coffee Atomic Model" );
        System.out.println( "You will have the option of entering input from the set: " );
        System.out.println( "{\"q\", \"d\", \"n\", \"c\", \"w\"}");
        System.out.println("You will also get output from the following set: ");
        System.out.println( "{\"q\", \"d\", \"n\", \"c\", \"Nothing\"}");
        System.out.println( "You are now entering the model: (remember lambda before delta ;) )");

        while(true) {
            System.out.println("Please enter more input");
            String input = scanner.nextLine();

            if(input.equalsIgnoreCase("exit"))
                System.exit(0);
            //for testing purposes
            if(input.equalsIgnoreCase("print")){
                singleton.printInternals();
                continue;
            }

            singleton.lambda();
            singleton.delta(input);
            System.out.println();
        }

    }
}
