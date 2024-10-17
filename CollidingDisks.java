
/******************************************************************************
 *  Compilation:  javac-algs4 CollidingDisks.java
 *  Execution:    java-algs4 CollidingDisks n
 *
 *  Simulates the motion of n hard disks, subject to the laws of elastic
 *  collisions. This program is intended to test that algs4.jar is properly
 *  installed.
 *
 ******************************************************************************/

import javax.swing.plaf.ColorUIResource;

import edu.princeton.cs.algs4.CollisionSystem;
import edu.princeton.cs.algs4.Particle;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

public class CollidingDisks {
    public static void main(String[] args) {
        int n = 50; // number of particles (default 20)
        if (args.length == 1) {
            n = Integer.parseInt(args[0]);
        }

        // enable double buffering to support animations
        StdDraw.enableDoubleBuffering();

        // create the n particles
        Particle[] particles = new Particle[n];
        for (int i = 0; i < n; i++) {
            double r = StdRandom.uniformDouble(0.005, 0.01);
            particles[i] = new Particle(StdRandom.uniformDouble(-0.9, 0.9), StdRandom.uniformDouble(-0.9, 0.9),
                    StdRandom.uniformDouble(-0.009, 0.009), StdRandom.uniformDouble(-0.009,
                            0.009),
                    r, r * r, new ColorUIResource(0x00ff00));
        }

        // simulate the system
        CollisionSystem system = new CollisionSystem(particles);
        system.simulate(Double.POSITIVE_INFINITY);
    }
}
