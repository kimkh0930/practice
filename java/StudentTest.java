public class StudentTest {

    public static void main(String[] args) {

        Student studentKim = new Student();

        studentKim.studentID = 1234;
        studentKim.setStudentName("Kim");
        studentKim.address = "김포";

        studentKim.showStudentInfo();

        Student studentPark = new Student();
        studentPark.studentID = 4321;
        studentPark.studentName = "park";
        studentPark.address = "잠실";

        studentPark.showStudentInfo();
    }
}
