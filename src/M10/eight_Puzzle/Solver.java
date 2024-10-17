package M10.eight_Puzzle;

import java.util.ArrayList;
import edu.princeton.cs.algs4.MinPQ;

public class Solver {
    MinPQ<Node> pq = new MinPQ<>(32);
    private int moves;
    private Node end;

    // Node class
    private class Node implements Comparable<Node> {
        final Board board;
        private final int priority;
        final int moves;
        private final Node preNode;

        public Node(Board board, int moves, Node preNode) {
            this.board = board;
            this.moves = moves;
            this.preNode = preNode;
            priority = moves + board.manhattan();
        }

        @Override
        public int compareTo(Node o) {
            return this.priority - o.priority;
        }

    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial) {
        if (initial == null) {
            throw new IllegalArgumentException();
        }
        if (!isSolvable(initial.tiles)) {
            moves = -1;
            end = null;
        }
        Node node = new Node(initial, 0, null);
        pq.insert(node);
        while (!pq.min().board.isGoal()) {
            game();
        }
        this.end = pq.min();
        this.moves = pq.min().moves;
    }

    // itrate game tree
    private void game() {
        Node node = pq.delMin();
        Board board = node.board;
        for (Board it : board.neighbors()) {
            if (node.preNode == null || !node.preNode.board.equals(it))
                pq.insert(new Node(it, node.moves + 1, node));
        }
    }

    /***************************************************************************** */
    // is the initial board solvable? (see below)
    public boolean isSolvable(int[][] tiles) {
        int n = tiles.length;
        int inversions = countInversions(tiles);
        int blankRow = findBlankRow(tiles); // 从底部开始计数

        // 根据棋盘的维度和逆序数判断可解性
        if (n % 2 == 1) {
            return inversions % 2 == 0; // 奇数维度棋盘
        } else {
            return (inversions + blankRow) % 2 == 0; // 偶数维度棋盘
        }
    }

    // 计算逆序数
    private int countInversions(int[][] tiles) {
        int[] flatTiles = new int[tiles.length * tiles.length];
        int index = 0;

        // 将二维数组扁平化
        for (int[] row : tiles) {
            for (int tile : row) {
                flatTiles[index++] = tile;
            }
        }

        int inversions = 0;
        for (int i = 0; i < flatTiles.length; i++) {
            if (flatTiles[i] == 0)
                continue; // 跳过空白方块
            for (int j = i + 1; j < flatTiles.length; j++) {
                if (flatTiles[j] == 0)
                    continue; // 跳过空白方块
                if (flatTiles[i] > flatTiles[j]) {
                    inversions++;
                }
            }
        }
        return inversions;
    }

    // 找到空白方块的行数（从底部开始计数）
    private int findBlankRow(int[][] tiles) {
        for (int i = 0; i < tiles.length; i++) {
            for (int j = 0; j < tiles.length; j++) {
                if (tiles[i][j] == 0) {
                    return tiles.length - i; // 从底部开始计数
                }
            }
        }
        return -1; // 如果没有找到空白方块
    }

    /*********************************** */
    // min number of moves to solve initial board; -1 if unsolvable
    public int moves() {
        return this.moves;
    }

    // sequence of boards in a shortest solution; null if unsolvable
    public Iterable<Board> solution() {
        ArrayList<Board> temp = new ArrayList<>();
        // corner situation
        if (end == null) {
            return null;
        }
        // find back
        Node current = end;
        while (current.preNode != null) {
            temp.add(current.board);
            current = current.preNode;
        }
        return temp;
    }

    // test client (see below)
    public static void main(String[] args) {
    }
}