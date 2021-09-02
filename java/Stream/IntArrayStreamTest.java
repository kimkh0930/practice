package Chapter6.ch06;

import java.util.Arrays;
import java.util.stream.IntStream;

public class IntArrayStreamTest {
    public static void main(String[] args) {

        int[] arr = {1,2,3,4,5};

        for(int num : arr){
            System.out.println(num);
        }

        System.out.println();
        IntStream is = Arrays.stream(arr);
        Arrays.stream(arr).forEach(n-> System.out.println(n)); //stream을 사용

        int sum = Arrays.stream(arr).sum(); //sum연산을 하기 위해 한번 더 stream을 생성
        System.out.println(sum);

    }
}
