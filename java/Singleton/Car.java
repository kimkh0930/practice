package oop.ch19;

public class Car {

    private static int serialNum = 10000;

    private int carNum;

    public Car(){
        serialNum++;
        carNum = getSerialNum();
    }

    public static int getSerialNum() {
        return serialNum;
    }

    public int getCarNum() {
        return carNum;
    }

    public void setCarNum(int carNum) {
        this.carNum = carNum;
    }
}
