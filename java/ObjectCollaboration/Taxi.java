package oop.ch14;

public class Taxi {

    String taxiName;
    int money;

    public Taxi(String taxiName){
        this.taxiName = taxiName;
    }

    public void take(int money){
        this.money += money;
    }

    public void showTaxiinfo(){
        System.out.println(taxiName + "의 수입은 "+ money + "원 입니다.");
    }
}
