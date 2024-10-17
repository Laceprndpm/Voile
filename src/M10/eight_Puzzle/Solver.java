package M10.eight_Puzzle;

import edu.princeton.cs.algs4.MinPQ;

public class Solver {
    MinPQ<Node> pq = new MinPQ<>(32);

    // Node class
    private class Node implements Comparable<Node> {
        final Board board;
        private final int priority;
        final int moves;

        public Node(Board board, int moves) {
            this.board = board;
            this.moves = moves;
            priority = moves + board.manhattan();
        }

        @Override
        public int compareTo(Node o) {
            return this.priority - o.priority;
        }
        
    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial) {
        Node node = new Node(initial, 0);
        pq.insert(node);
        while (!pq.min().board.isGoal()) {
            game();
        }
        System.out.println("fu");
    }

    // itrate game tree
    private void game() {
        Node node = pq.delMin();
        Board board = node.board;
        for (Board is : board.neighbors()) {
            pq.insert(new Node(is, node.moves+1));
        }
    }

    // is the initial board solvable? (see below)
    public boolean isSolvable() {
        return false;
    }

    // min number of moves to solve initial board; -1 if unsolvable
    public int moves() {
        return 0;
    }

    // sequence of boards in a shortest solution; null if unsolvable
    public Iterable<Board> solution() {
        return null;
    }

    // test client (see below)
    public static void main(String[] args) {
        int[][] array = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 0, 8 } };
        Board board = new Board(array);
        Solver solver = new Solver(board);
    }
}
/********************************************************************* */
// import java.util.ArrayList;

// import edu.princeton.cs.algs4.MinPQ;

// public class Solver {
// private MinPQ<Board> pq = new MinPQ<>(32);
// private Board initial;
// private int moves = -1; // 最小步数
// private boolean solvable = false; // 是否可解
// private ArrayList<Board> solution = new ArrayList<>(); // 解决方案

// // find a solution to the initial board (using the A* algorithm)
// public Solver(Board initial) {
// this.initial = initial;
// if (isSolvable()) {
// pq.insert(initial);
// while (!pq.min().isGoal()) {
// game();
// }
// moves = pq.min().getstep(); // 记录最小步数
// solvable = true;
// // 回溯解决方案
// backtrackSolution();
// }
// }

// // 迭代游戏树
// private void game() {
// Board board = pq.delMin();
// for (Board neighbor : board.neighbors()) {
// pq.insert(neighbor);
// }
// }

// // 验证初始棋盘是否可解
// public boolean isSolvable() {
// // 可以在这里实现具体的验证逻辑
// // 例如，可以计算逆序数或使用其他方法
// return true; // 这里仅为示例，具体逻辑需要实现
// }

// // 获取最小步数
// public int moves() {
// return solvable ? moves : -1;
// }

// // 获取解决方案
// public Iterable<Board> solution() {
// return solvable ? solution : null;
// }

// // 回溯解决方案
// private void backtrackSolution() {
// // 这里可以实现从目标棋盘回溯到初始棋盘的逻辑
// // 将每一步棋盘状态添加到 solution 列表中
// solution.add(initial); // 示例，只添加初始棋盘
// // 实际回溯逻辑需实现
// }

// public static void main(String[] args) {
// // 示例输入
// int[][] tiles = { { 1, 2, 3 }, { 4, 5, 6 }, { 8, 7, 0 } };
// Board initial = new Board(tiles);
// Solver solver = new Solver(initial);

// if (solver.isSolvable()) {
// System.out.println("Minimum number of moves: " + solver.moves());
// for (Board b : solver.solution()) {
// System.out.println(b);
// }
// } else {
// System.out.println("No solution possible");
// }
// }
// }