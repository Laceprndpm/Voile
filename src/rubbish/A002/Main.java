package A002;

public class Main {

    class B {
        int value = 0;
    }    public static void main(String[] args) {
        // Asub asub = new Asub();
        // System.out.println(asub.default_value);
        // System.out.println(asub.public_value);
        // System.out.println(asub.protected_value);
        // Asub.display();
        Main m = new Main();
        B b = m.new B();
        b.value = 2;
    }
}

// public class A {
//     public class B {
//         // B的构造器
//         public B() {
//             System.out.println("B's constructor called");
//         }
//     }

//     public void createBInstance() {
//         // 在A内创建B的实例
//         B bInstance = new B();
//     }

//     public static void main(String[] args) {
//         A aInstance = new A();
//         aInstance.createBInstance();
//     }
// }
