package Chapter2.ch24;

public class StudentSubjectTest {

    public static void main(String[] args) {

        Student studentKim = new Student(1001,"kim");

        studentKim.addSubject("국어",100);
        studentKim.addSubject("수학",50);

        Student studentPark = new Student(1002,"park");
        studentPark.addSubject("국어",70);
        studentPark.addSubject("수학",85);
        studentPark.addSubject("영어",100);

        studentKim.showScoreInfo();
        System.out.println("===========");
        studentPark.showScoreInfo();
    }
}
