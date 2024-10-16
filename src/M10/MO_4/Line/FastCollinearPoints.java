package Line;

// import java.util.ArrayList;
// import java.util.Arrays;
// import java.util.List;

// public class FastCollinearPoints {
//    Point[] points;
//    private final List<LineSegment> lineSegments = new ArrayList<>();

//    public FastCollinearPoints(Point[] outerpoints) // finds all line segments containing 4 or more points
//    {
//       this.points = outerpoints.clone();
//       Arrays.sort(this.points);
//       int end = points.length;
//       for (int i = 0; i < end-3; i++) { // over this array
//          Arrays.sort(this.points, i + 1, end, this.points[i].slopeOrder()); // sort by slop
//          Point temppoint = points[i];
//          for (int j = i + 1; j < end-2; j++) {
//             if (temppoint.slopeTo(points[j]) == temppoint.slopeTo(points[j + 1])
//                   && temppoint.slopeTo(points[j + 1]) == temppoint.slopeTo(points[j + 2])) {
//                lineSegments.add(new LineSegment(temppoint, points[j + 2]));
//             }
//          }
//       }
//    }

//    public int numberOfSegments() // the number of line segments
//    {
//       return lineSegments.size();
//    }

//    public LineSegment[] segments() // the line segments
//    {
//       return lineSegments.toArray(new LineSegment[0]);
//    }

//    public static void main(String[] args) {
//       Point[] points = new Point[4];
//       Point p1 = new Point(0, 0);
//       Point p2 = new Point(1, 1);
//       Point p3 = new Point(2, 2);
//       Point p4 = new Point(4, 4);
//       points[0] = p1;
//       points[1] = p2;
//       points[2] = p3;
//       points[3] = p4;
//       FastCollinearPoints fastCollinearPoints = new FastCollinearPoints(points);
//       int num = fastCollinearPoints.numberOfSegments();
//       System.out.println(num);
//    }
// // }
// public class FastCollinearPoints {
//    // Point[] points;
//    private final List<LineSegment> lineSegments = new ArrayList<>();

//    public FastCollinearPoints(Point[] outerpoints) // finds all line segments containing 4 or more points
//    {
//       Point[] points = outerpoints.clone();
//       Arrays.sort(points);
//       int end = points.length;

//       for (int i = 0; i < end - 3; i++) { // over this array
//          Arrays.sort(points, i + 1, end, points[i].slopeOrder()); // sort by slope
//          Point temppoint = points[i];
//          int count = 1;
//          Point maxPoint = null;
//          Point minPoint = temppoint;

//          for (int j = i + 1; j < end; j++) {
//             if (Double.compare(temppoint.slopeTo(points[j]), temppoint.slopeTo(points[j - 1])) == 0) {
//                count++;
//                if (maxPoint == null || points[j].compareTo(maxPoint) > 0) {
//                   maxPoint = points[j];
//                }
//             } else {
//                if (count >= 3) {
//                   lineSegments.add(new LineSegment(minPoint, maxPoint));
//                }
//                count = 1;
//             }
//          }
//          if (count >= 3) {
//             lineSegments.add(new LineSegment(minPoint, maxPoint)); // Handle last case
//          }
//       }
//    }

//    public int numberOfSegments() {
//       return lineSegments.size();
//    }

//    public LineSegment[] segments() {
//       return lineSegments.toArray(new LineSegment[0]);
//    }

//    public static void main(String[] args) {

//       // read the n points from a file
//       In in = new In(args[0]);
//       int n = in.readInt();
//       Point[] points = new Point[n];
//       for (int i = 0; i < n; i++) {
//          int x = in.readInt();
//          int y = in.readInt();
//          points[i] = new Point(x, y);
//       }

//       // draw the points
//       StdDraw.enableDoubleBuffering();
//       StdDraw.setXscale(0, 32768);
//       StdDraw.setYscale(0, 32768);
//       for (Point p : points) {
//          p.draw();
//       }
//       StdDraw.show();

//       // print and draw the line segments
//       FastCollinearPoints collinear = new FastCollinearPoints(points);
//       for (LineSegment segment : collinear.segments()) {
//          StdOut.println(segment);
//          segment.draw();
//       }
//       StdDraw.show();
//    }
// }
// import java.util.Arrays;
// import java.util.ArrayList;

// public class FastCollinearPoints {
//    private final LineSegment[] lineSegments;

//    public FastCollinearPoints(Point[] points) {
//       if (points == null)
//          throw new IllegalArgumentException("Input points cannot be null");

//       // Check for null points and duplicates
//       for (Point p : points) {
//          if (p == null)
//             throw new IllegalArgumentException("Point cannot be null");
//       }
//       Point[] uniquePoints = Arrays.stream(points).toArray(Point[]::new);
//       if (uniquePoints.length < points.length)
//          throw new IllegalArgumentException("Input contains repeated points");

//       int n = uniquePoints.length;
//       ArrayList<LineSegment> segments = new ArrayList<>();

//       for (Point p : uniquePoints) {
//          Point[] slopes = uniquePoints.clone();
//          Arrays.sort(slopes, p.slopeOrder()); // Sort points by slope relative to point p

//          int count = 1; // Count of collinear points including p
//          for (int j = 1; j < n; j++) {
//             // Check if adjacent points have the same slope with respect to p
//             if (j < n - 1 && p.slopeTo(slopes[j]) == p.slopeTo(slopes[j + 1])) {
//                count++;
//             } else {
//                // If we found 3 or more additional points (count includes p)
//                if (count >= 3) {
//                   Point minPoint = p; // Start with point p
//                   Point maxPoint = slopes[j]; // Assume the last point as max initially

//                   // Find the min and max points
//                   for (int k = j - count; k <= j; k++) {
//                      if (slopes[k].compareTo(minPoint) < 0) {
//                         minPoint = slopes[k];
//                      }
//                      if (slopes[k].compareTo(maxPoint) > 0) {
//                         maxPoint = slopes[k];
//                      }
//                   }
//                   segments.add(new LineSegment(minPoint, maxPoint));
//                }
//                count = 1; // Reset count for the next slope
//             }
//          }
//          // Final check for the last group
//          if (count >= 3) {
//             Point minPoint = p;
//             Point maxPoint = slopes[n - 1];
//             for (int k = n - 1 - count; k <= n - 1; k++) {
//                if (slopes[k].compareTo(minPoint) < 0) {
//                   minPoint = slopes[k];
//                }
//                if (slopes[k].compareTo(maxPoint) > 0) {
//                   maxPoint = slopes[k];
//                }
//             }
//             segments.add(new LineSegment(minPoint, maxPoint));
//          }
//       }

//       lineSegments = segments.toArray(new LineSegment[0]);
//    }

//    public int numberOfSegments() {
//       return lineSegments.length;
//    }

//    public LineSegment[] segments() {
//       return lineSegments.clone();
//    }

//    public static void main(String[] args) {
//       // Sample input points
//       Point[] points = {
//             new Point(0, 0),
//             new Point(1, 1),
//             new Point(2, 2),
//             new Point(3, 3),
//             new Point(4, 4),
//             new Point(0, 1),
//             new Point(1, 0)
//       };

//       FastCollinearPoints fastCollinearPoints = new FastCollinearPoints(points);
//       System.out.println("Number of segments: " + fastCollinearPoints.numberOfSegments());
//       for (LineSegment segment : fastCollinearPoints.segments()) {
//          System.out.println(segment);
//       }
//    }
// }

// Point[] uniquePoints = Arrays.stream(points).toArray(Point[]::new);
// if (uniquePoints.length < points.length)
// throw new IllegalArgumentException("Input contains repeated points");

// for (int i = 0; i < copyPoints.length; i++) {
// Point[] copyPoints1 = copyPoints.clone();
// Arrays.sort(copyPoints1, copyPoints[i].slopeOrder());
// for (int j = 0; j < copyPoints1.length; j++) {
// if (copyPoints[i].slopeTo(copyPoints1[j - 1]) ==
// copyPoints[i].slopeTo(copyPoints1[j])
// || copyPoints[i].slopeTo(copyPoints1[j]) == copyPoints[i]
// .slopeTo(copyPoints1[j + 1])) {
// }
// }
// }
// int i = 0;
// int j = 1;
// while (i < copyPoints.length) {
// if (copyPoints[i] != copyPoints[j]) {
// j++;
// i++;
// } else if (copyPoints[i] == copyPoints[j]) {
// ArrayList<Point> pointsList = new ArrayList<>();
// pointsList.add()
// while (copyPoints[i]==copyPoints[j]) {
// pointsList.add(null)
// }
// }
// }
/********************************************************************************************************************************************* */
// ArrayList<LineSegment> segments = new ArrayList<>();// To store all the
// result

// for (int i = 0; i < copyPoints.length; i++) {
// Point[] copy2Points = copyPoints.clone();
// Arrays.sort(copy2Points, copyPoints[i].slopeOrder());

// int p = 0;
// int q = 1;

// while (p < copy2Points.length - 1) {
// if (copyPoints[i].slopeTo(copy2Points[p]) !=
// copyPoints[i].slopeTo(copy2Points[q])) {
// p++;
// q++;
// continue;// if not same , move two pointers
// } else { // the condition of the pointers' data is same
// ArrayList<Point> pointsList = new ArrayList<>();
// pointsList.add(copyPoints[i]);
// pointsList.add(copy2Points[q]);
// while (copyPoints[i].slopeTo(copy2Points[p]) ==
// copyPoints[i].slopeTo(copy2Points[q])) {
// pointsList.add(copy2Points[q]);
// q++;
// if (q == copy2Points.length - 1) {
// break;
// }
// }

// p = q;
// if (q != copy2Points.length - 1) {
// q = p + 1;
// }

// if (pointsList.size() <= 3) {// if size <= 3,there is no need to return them
// continue;
// }
// Point[] pointsArray = pointsList.toArray(new Point[0]);
// Arrays.sort(pointsArray);
// if (pointsArray[0] == copyPoints[i]) {// only when the first point is the
// point we are test can we put
// // this line into the data
// segments.add(new LineSegment(pointsArray[0], pointsArray[pointsArray.length -
// 1]));
// }
// }
// }
// }
/************************************************************************************************************************/
import java.util.Arrays;
import java.util.ArrayList;

public class FastCollinearPoints {
   private ArrayList<LineSegment> segments = new ArrayList<>(); // To store all the result

   public FastCollinearPoints(Point[] points) {
      /*
       * To test whether there is a IllegalArgument
       * 
       */
      
      if (points == null)
         throw new IllegalArgumentException("Input points cannot be null");

      // Check for null points and duplicates
      for (Point p : points) {
         if (p == null)
            throw new IllegalArgumentException("Point cannot be null");
      }
      Point[] copyPoints = points.clone();
      Arrays.sort(copyPoints);
      for (int i = 0; i < copyPoints.length - 1; i++) {
         if (copyPoints[i].compareTo(copyPoints[i + 1]) == 0) {
            throw new IllegalArgumentException();// handle duplicate points
         }
      }
      /*
       * the main part
       */

      for (int i = 0; i < copyPoints.length; i++) {
         Point[] copy2Points = copyPoints.clone();
         Arrays.sort(copy2Points, copyPoints[i].slopeOrder());

         int p = 0;

         while (p < copy2Points.length) {
            int q = p + 1;

            // Collect points with the same slope
            ArrayList<Point> pointsList = new ArrayList<>();
            pointsList.add(copyPoints[i]);

            while (q < copy2Points.length &&
                  copyPoints[i].slopeTo(copy2Points[p]) == copyPoints[i].slopeTo(copy2Points[q])) {
               pointsList.add(copy2Points[q]);
               q++;
            }

            // Check if we have enough points
            if (pointsList.size() >= 4) {
               Point[] pointsArray = pointsList.toArray(new Point[0]);
               Arrays.sort(pointsArray);
               // Only add if the first point is the one we are testing
               if (pointsArray[0].equals(copyPoints[i])) {
                  segments.add(new LineSegment(pointsArray[0], pointsArray[pointsArray.length - 1]));
               }
            }

            // Move p to q for the next iteration
            p = q;
         }
      }
   }

   public int numberOfSegments() // the number of line segments
   {
      return segments.size();
   }

   public LineSegment[] segments() // the line segments
   {
      return segments.toArray(new LineSegment[0]);
   }

   public static void main(String[] args) {
      // Sample input points
   }
}
// int n = uniquePoints.length;
// ArrayList<LineSegment> segments = new ArrayList<>();

// for (Point p : uniquePoints) {
// Point[] slopes = uniquePoints.clone();
// Arrays.sort(slopes, p.slopeOrder()); // Sort points by slope relative to
// point p

// int count = 1; // Count of collinear points including p
// for (int j = 1; j < n; j++) {
// // Check if adjacent points have the same slope with respect to p
// if (j < n - 1 && p.slopeTo(slopes[j]) == p.slopeTo(slopes[j + 1])) {
// count++;
// } else {
// // If we found 3 or more additional points (count includes p)
// if (count >= 3) {
// Point minPoint = p; // Start with point p
// Point maxPoint = slopes[j]; // Assume the last point as max initially

// // Find the min and max points
// for (int k = j - count; k <= j; k++) {
// if (slopes[k].compareTo(minPoint) < 0) {
// minPoint = slopes[k];
// }
// if (slopes[k].compareTo(maxPoint) > 0) {
// maxPoint = slopes[k];
// }
// }
// segments.add(new LineSegment(minPoint, maxPoint));
// }
// count = 1; // Reset count for the next slope
// }
// }
// // Final check for the last group
// if (count >= 3) {
// Point minPoint = p;
// Point maxPoint = slopes[n - 1];
// for (int k = n - 1 - count; k <= n - 1; k++) {
// if (slopes[k].compareTo(minPoint) < 0) {
// minPoint = slopes[k];
// }
// if (slopes[k].compareTo(maxPoint) > 0) {
// maxPoint = slopes[k];
// }
// }
// segments.add(new LineSegment(minPoint, maxPoint));
// }
// }

// lineSegments = segments.toArray(new LineSegment[0]);
// }

// public int numberOfSegments() {
// return lineSegments.length;
// }

// public LineSegment[] segments() {
// return lineSegments.clone();

// FastCollinearPoints fastCollinearPoints = new FastCollinearPoints(points);
// System.out.println("Number of segments: " +
// fastCollinearPoints.numberOfSegments());
// for (LineSegment segment : fastCollinearPoints.segments()) {
// System.out.println(segment);
// }
// }
// }import java.util.Arrays;
// import java.util.ArrayList;
// import java.util.Arrays;

// public class FastCollinearPoints {
// private final ArrayList<LineSegment> lineSegments = new ArrayList<>();

// public FastCollinearPoints(Point[] points) {
// if (points == null)
// throw new IllegalArgumentException("Input array is null");

// // Clone and sort points
// Point[] sortedPoints = points.clone();
// Arrays.sort(sortedPoints);

// // Check for duplicates
// for (int i = 1; i < sortedPoints.length; i++) {
// if (sortedPoints[i].equals(sortedPoints[i - 1])) {
// throw new IllegalArgumentException("Duplicate points detected");
// }
// }

// // Main logic
// for (int i = 0; i < sortedPoints.length; i++) {
// Point origin = sortedPoints[i];
// // Create a copy of the array excluding the origin
// Point[] others = new Point[sortedPoints.length - 1];
// System.arraycopy(sortedPoints, 0, others, 0, i);
// System.arraycopy(sortedPoints, i + 1, others, i, sortedPoints.length - i -
// 1);

// // Sort others by slope with respect to origin
// Arrays.sort(others, origin.slopeOrder());

// // Find collinear points
// int count = 1;
// for (int j = 1; j < others.length; j++) {
// if (origin.slopeTo(others[j]) == origin.slopeTo(others[j - 1])) {
// count++;
// } else {
// if (count >= 3) {
// Point[] collinearPoints = new Point[count + 1];
// collinearPoints[0] = origin;
// System.arraycopy(others, j - count, collinearPoints, 1, count);
// Arrays.sort(collinearPoints); // Sort to find endpoints
// lineSegments.add(new LineSegment(collinearPoints[0],
// collinearPoints[collinearPoints.length - 1]));
// }
// count = 1; // Reset count for the next segment
// }
// }

// // Check at the end of the array
// if (count >= 3) {
// Point[] collinearPoints = new Point[count + 1];
// collinearPoints[0] = origin;
// System.arraycopy(others, others.length - count, collinearPoints, 1, count);
// Arrays.sort(collinearPoints); // Sort to find endpoints
// lineSegments.add(new LineSegment(collinearPoints[0],
// collinearPoints[collinearPoints.length - 1]));
// }
// }

// // Remove duplicates
// removeDuplicates();
// }

// public int numberOfSegments() {
// return lineSegments.size();
// }

// public LineSegment[] segments() {
// return lineSegments.toArray(new LineSegment[0]);
// }

// private void removeDuplicates() {
// // Sort line segments to help with removal of duplicates
// LineSegment[] segmentsArray = lineSegments.toArray(new LineSegment[0]);
// Arrays.sort(segmentsArray);

// ArrayList<LineSegment> uniqueSegments = new ArrayList<>();
// for (int i = 0; i < segmentsArray.length; i++) {
// if (i == 0 || !segmentsArray[i].equals(segmentsArray[i - 1])) {
// uniqueSegments.add(segmentsArray[i]);
// }
// }
// lineSegments.clear();
// lineSegments.addAll(uniqueSegments);
// }

// public static void main(String[] args) {
// // Test code can be added here
// }
// }
