package org.example;

public class InsufficientChangeException extends Exception{

    InsufficientChangeException(){
        super("Insufficient Change!");
    }
}
