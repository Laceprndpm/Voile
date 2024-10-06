package X003;

import java.util.Random;

public class Dice {
    int num;
    Random random;

    Dice() {
        this.random = new Random();
    }
    
    int roll(){
        this.num = random.nextInt(6) + 1;
        return this.num;
    }
}
