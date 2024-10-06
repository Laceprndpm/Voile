package A002;

import A001.*;

public class Asub extends A {
    public static void display() {
        System.out.println(S_protected_value);
        // System.out.println(S_default_value);
    }

    public static void main(String[] args) {
        Asub asub = new Asub();
        System.err.println(asub.protected_value);
    }
    // public static void main(String[] args) {
    //     A a = new A();
    //     System.out.println(a.public_value);
    //     // System.out.println(a.private_value);
    //     // System.out.println(a.default_value);
    //     // System.out.println(a.protected);
    //     Asub asub = new Asub();
    //     System.err.println(asub.public_value);
    // }

    // public class Asub extends A {
    // }
}