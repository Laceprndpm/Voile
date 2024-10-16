package Line;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BruteCollinearPoints {
   private final List<LineSegment> lineSegments = new ArrayList<>();

   public BruteCollinearPoints(Point[] points) // finds all line segments containing 4 points
   {
      if (points == null) {
         throw new IllegalArgumentException("Not null");
      }

      for (int i = 0; i < points.length; i++) {
         if (points[i] == null) {
            throw new IllegalArgumentException("A null");
         }
      }

      Point[] copypoints = points.clone();
      Arrays.sort(copypoints);

      for (int i = 0; i < copypoints.length - 1; i++) {
         if (copypoints[i].compareTo(copypoints[i + 1]) == 0) {
            throw new IllegalArgumentException("same");
         }
      }

      int n = copypoints.length;
      for (int p = 0; p < n - 3; p++) {
         for (int q = p + 1; q < n - 2; q++) {
            for (int r = q + 1; r < n - 1; r++) {
               for (int s = r + 1; s < n - 0; s++) {
                  Point p1 = copypoints[p];
                  Point p2 = copypoints[q];
                  Point p3 = copypoints[r];
                  Point p4 = copypoints[s];

                  if (p1.slopeTo(p2) == p1.slopeTo(p3) && p1.slopeTo(p2) == p1.slopeTo(p4)) {
                     lineSegments.add(new LineSegment(p1, p4));
                  }
               }
            }
         }
      }
   }

   public int numberOfSegments() // the number of line segments
   {
      return lineSegments.size();
   }

   public LineSegment[] segments() // the line segments
   {
      return lineSegments.toArray(new LineSegment[0]);
   }

   public static void main(String[] args) {
      Point[] points = new Point[4];
      Point p1 = new Point(0, 0);
      Point p2 = new Point(1, 1);
      Point p3 = new Point(2, 2);
      Point p4 = new Point(4, 4);
      points[0] = p1;
      points[1] = p2;
      points[2] = p3;
      points[3] = p4;
      BruteCollinearPoints bruteCollinearPoints = new BruteCollinearPoints(points);
      System.out.println(bruteCollinearPoints.segments()[0]);
   }
}