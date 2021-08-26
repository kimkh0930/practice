package Chapter3.ch08;

import java.util.ArrayList;

class Animal {

    public void move(){
        System.out.println("move");
    }
}

class Human extends Animal{

    @Override
    public void move() {
        System.out.println("walk");
    }

    public void readBook(){
        System.out.println("read book");
    }
}

class  Tiger extends Animal{

    @Override
    public void move() {
        System.out.println("run");
    }

    public void hunting(){
        System.out.println("hunting");
    }
}

class Eagle extends Animal{

    @Override
    public void move() {
        System.out.println("fly");
    }

    public void flying(){
        System.out.println("flying");
    }
}


public class AnimalTest {

    public static void main(String[] args) {
        Animal hAnimal = new Human();
        Animal tAnimal = new Tiger();
        Animal eAnimal = new Eagle();

        AnimalTest test = new AnimalTest();
//        test.moveAnimal(hAnimal);
//        test.moveAnimal(tAnimal);
//        test.moveAnimal(eAnimal);

        ArrayList<Animal> animalList = new ArrayList<>();
        animalList.add(hAnimal);
        animalList.add(tAnimal);
        animalList.add(eAnimal);

        for(Animal animal : animalList){
            animal.move();
        }

        test.testDownCasting(animalList);
    }

    public void testDownCasting(ArrayList<Animal> list){

        for(int i=0;i<list.size();i++){
            Animal animal = list.get(i);

            if(animal instanceof Human){
                Human human = (Human)animal;
                human.readBook();
            }
            else if(animal instanceof Tiger){
                Tiger tiger = (Tiger)animal;
                tiger.hunting();
            }
            else if(animal instanceof Eagle){
                Eagle eagle = (Eagle)animal;
                eagle.flying();
            }
            else{
                System.out.println("unsupported type");
            }
        }
    }

    public void moveAnimal(Animal animal){
        animal.move();
    }
}
