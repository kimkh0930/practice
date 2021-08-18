package part1;

import java.util.Scanner;

public class ConditionSample {
    public static void main(String[] args){
        System.out.println("회원님의 레벨을 입력해주세요(gold/silver/bronze)");
        Scanner scanner = new Scanner(System.in);
        String level = scanner.next();
        int maxLimit = 0;
        // 두 조건문 로직을 작성해주세요.
        //else-if
        if(level == "bronze")
            maxLimit = 50;
        else if(level == "silver")
            maxLimit = 100;
        else if(level == "gold")
            maxLimit = 300;
        else
            System.out.println("오류");
        //switch

        System.out.printf("회원님의 최대 한도는 %d만원 입니다.", maxLimit);

    }
}
