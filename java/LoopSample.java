package part1;

import java.util.Scanner;
import java.util.Arrays;

public class LoopSample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int amount = 1;
        int maxCount = 10;
        // while 문
        while (조건1 && 조건2) {
            amount = scanner.nextInt();
            //무한 루프가 돌지 않기 위한 수행문;

            System.out.println("남은 송금 횟수는 " + maxCount + "번 입니다.");
        }
        // for 문

        // do while 문

        // Nested for 문
        int[][] bankDeposit = {{300, 200, 100}, {2, 30}, {300, 50}};
        int[] bankBalance = {0, 0, 0};
        for(초기화식; 조건식; 증감식){
            System.out.println("%d번째 은행 입금 이력은 %s입니다.", i, Arrays.toString(bankDeposit[i]));
            for(초기화식; 조건식; 증감식){
                //수행문;
            }
        }
        System.out.println(Arrays.toString(bankBalance));

        // Continue

    }
}