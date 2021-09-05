package Chapter6.ch07;

import java.util.ArrayList;
import java.util.List;

public class TravelCustomerTest {

    public static void main(String[] args) {

        TravelCustomer customerkim = new TravelCustomer("kim", 40, 100);
        TravelCustomer customerpark = new TravelCustomer("park", 20, 100);
        TravelCustomer customerseo = new TravelCustomer("seo", 13, 50);

        List<TravelCustomer> customerList = new ArrayList<>();
        customerList.add(customerkim);
        customerList.add(customerpark);
        customerList.add(customerseo);

        System.out.println("고객 명단 출력");
        customerList.stream().map(c->c.getName()).forEach(s-> System.out.println(s));

        System.out.println("여행비용");
        System.out.println(customerList.stream().mapToInt(c->c.getPrice()).sum());

        System.out.println("20세 이상 고객");
        customerList.stream().filter(c->c.getAge()>=20).map(c->c.getName()).sorted().forEach(s-> System.out.println(s));
    }
}
