package org.example;

/**
 * Remember Lambda before delta!!!
 */
public class App 
{
    public static void main( String[] args )
    {
        AtomicModelCoffeeMachine singleton = AtomicModelSingleton.INSTANCE.getInstance();

        System.out.println( "Welcome to the Coffee Atomic Model" );
        System.out.println( "You will have the option of entering input from the set: " );
        System.out.println( singleton.potentialInputs);
        System.out.println("You will also get output from the following set: ");
        System.out.println( singleton.potentialOutputs);
        System.out.println( "You are now entering the model: (remember lambda before delta ;) )");







    }
}
