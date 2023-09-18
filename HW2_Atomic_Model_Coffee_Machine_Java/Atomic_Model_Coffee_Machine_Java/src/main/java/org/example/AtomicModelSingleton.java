package org.example;

//singleton class
public enum AtomicModelSingleton {
    INSTANCE;
    private AtomicModelCoffeeMachine atomicModelInstance;

    AtomicModelSingleton( ) {
        this.atomicModelInstance = new AtomicModelCoffeeMachine();
    }

    public AtomicModelCoffeeMachine getInstance(){
        return atomicModelInstance;
    }


}
