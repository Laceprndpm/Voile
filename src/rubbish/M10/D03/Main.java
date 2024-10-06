package M10.D03;

public class Main {
    public static void main(String[] args) {
        Outer out = new Outer();
        Outer.Inter in = out.new Inter();
        System.err.println(in);
    }
}
