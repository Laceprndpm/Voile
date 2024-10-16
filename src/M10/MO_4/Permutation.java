import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdIn;

public class Permutation {
    public static void main(String[] args) {
        if (args.length != 1) {
            throw new IllegalArgumentException("Need 1 cmd Argument");
        }
        int number = Integer.parseInt(args[0]);
        RandomizedQueue<String> randomizedQueue = new RandomizedQueue<>();
        while (true) {
            try {
                String temp = StdIn.readString();
                randomizedQueue.enqueue(temp);
            } catch (NoSuchElementException e) {
                break;
            }
        }
        int count = 0;
        for (String i : randomizedQueue) {
            System.err.println(i);
            count++;
            if (count == number) {
                break;
            }
        }
    }
}