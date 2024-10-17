package M10.MO_4;

// public class Main {
//     public static void main(String[] args) {
//         // Linkedqueue<String> linkedqueue = new Linkedqueue<>();
//         // linkedqueue.enqueue("Num1");
//         // System.err.println(linkedqueue.dequeue());
//         // linkedqueue.enqueue("error");
//         // System.err.println(linkedqueue.dequeue());

//         Object apple = new Apple();
//         ((Apple) apple).pie();
//     }
// }
import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class QuickSortDistribution extends JPanel {
    private static final int ARRAY_SIZE = 100;
    private static final int TEST_COUNT = 100000;
    private int[] differences;

    public QuickSortDistribution() {
        differences = new int[TEST_COUNT];
        Random rand = new Random();

        for (int i = 0; i < TEST_COUNT; i++) {
            // 生成一个100大小的随机数组，元素在1到100之间
            int[] array = rand.ints(ARRAY_SIZE, 1, 101).toArray();
            int pivotIndex = rand.nextInt(ARRAY_SIZE);
            int pivot = array[pivotIndex];

            int leftSum = 0;
            int rightSum = 0;

            // 计算左右和
            for (int j = 0; j < array.length; j++) {
                if (j < pivotIndex) {
                    leftSum += array[j];
                } else if (j > pivotIndex) {
                    rightSum += array[j];
                }
            }

            // 存储绝对差
            differences[i] = Math.abs(leftSum - rightSum);
        }
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        int maxDiff = 0;

        // 找到最大差值
        for (int diff : differences) {
            if (diff > maxDiff)
                maxDiff = diff;
        }

        // 创建直方图数组
        int[] histogram = new int[maxDiff + 1];
        for (int diff : differences) {
            histogram[diff]++;
        }

        // 绘制直方图
        for (int i = 0; i < histogram.length; i++) {
            g.fillRect(i * 5, getHeight() - histogram[i], 4, histogram[i]);
        }
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("QuickSort Pivot Distribution");
        QuickSortDistribution panel = new QuickSortDistribution();
        frame.add(panel);
        frame.setSize(800, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
    }
}
