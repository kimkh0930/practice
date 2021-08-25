package oop.ch19;

public class CarFactory {

    private static CarFactory instance = new CarFactory();

    public CarFactory() {
    }

    public static CarFactory getInstance(){
        if(instance == null){
            instance = new CarFactory();
        }
        return instance;
    }

    public Car createCar(){
        Car car = new Car();
        return car;
    }
}
