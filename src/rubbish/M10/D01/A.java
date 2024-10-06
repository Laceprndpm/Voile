package M10.D01;

public class A {
    int name;
    int test;

    public A(int name) {
        this.name = name + 1;
        test = name;
    }

    public void display(){
        System.out.println("this.name = " + this.name);
        System.out.println("name = " + name);
        System.out.println("test = " + this.test);

    }
}
