package X002;

import java.util.Scanner;

// HelloWorld.java
public class HelloWorld {
    public static void main(String[] args) {
        double x = 0;
        double y = 0;
        double z = 0;
        Scanner S = new Scanner(System.in);
        x = S.nextDouble();
        y = S.nextDouble();
        z = Math.sqrt((x * x) + (y * y));
        System.out.println("The value is " + z);
        S.close();
    }
}
