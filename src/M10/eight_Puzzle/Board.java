package M10.eight_Puzzle;

import java.util.ArrayList;
import java.util.List;

public class Board {
    private int cache = -2;
    private final int n;
    private final int[][] tiles;

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {
        n = tiles.length;
        this.tiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            this.tiles[i] = tiles[i].clone(); // 深拷贝
        }
        if (cache == -2) {
            cache = manhattan();
        }
    }

    // string representation of this board
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(n).append("\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(tiles[i][j]).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    // board dimension n
    public int dimension() {
        return n;
    }

    // number of tiles out of place
    public int hamming() {
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tiles[i][j] != 0 && tiles[i][j] != goal(i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    // 目标位置计算
    private int goal(int row, int col) {
        return row * n + col + 1;
    }

    // sum of Manhattan distances between tiles and goal
    public int manhattan() {
        if (cache != -2) {
            return cache;
        } else {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // 计算每个方块的曼哈顿距离
                    sum += manhattan(i, j);
                }
            }
            cache = sum;
            return cache;
        }
    }

    // 计算指定位置的曼哈顿距离
    private int manhattan(int row, int col) {
        int num = tiles[row][col];
        if (num == 0)
            return 0; // 空白方块不计入距离

        // 计算目标位置
        int goalRow = (num - 1) / n; // 目标行
        int goalCol = (num - 1) % n; // 目标列

        // 计算曼哈顿距离
        return Math.abs(row - goalRow) + Math.abs(col - goalCol);
    }

    // is this board the goal board?
    public boolean isGoal() {
        return manhattan() == 0;
    }

    // does this board equal y?
    public boolean equals(Object y) {
        if (this == y)
            return true;
        if (y == null || getClass() != y.getClass())
            return false;
        Board that = (Board) y;
        if (this.n != that.n)
            return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (this.tiles[i][j] != that.tiles[i][j])
                    return false;
            }
        }
        return true;
    }

    // all neighboring boards
    public Iterable<Board> neighbors() {
        List<Board> neighbors = new ArrayList<>();
        int blankRow = -1, blankCol = -1;

        // 找到空白方块的位置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tiles[i][j] == 0) { // 0 表示空白方块
                    blankRow = i;
                    blankCol = j;
                    break;
                }
            }
        }

        // 定义可能的滑动方向（上、下、左、右）
        int[] dRow = { -1, 1, 0, 0 }; // 行的变化
        int[] dCol = { 0, 0, -1, 1 }; // 列的变化

        // 生成相邻的棋盘
        for (int k = 0; k < 4; k++) {
            int newRow = blankRow + dRow[k];
            int newCol = blankCol + dCol[k];

            // 检查新位置是否在范围内
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                // 创建新棋盘并交换空白方块与相邻方块
                int[][] newTiles = new int[n][n];
                for (int i = 0; i < n; i++) {
                    System.arraycopy(tiles[i], 0, newTiles[i], 0, n);
                }
                // 交换
                newTiles[blankRow][blankCol] = newTiles[newRow][newCol];
                newTiles[newRow][newCol] = 0;
                // 同步缓存
                Board temp = new Board(newTiles);
                temp.cache = this.cache - this.manhattan(newRow, newCol) + temp.manhattan(blankRow, blankCol);

                neighbors.add(temp);
            }
        }

        return neighbors;
    }

    // a board that is obtained by exchanging any pair of tiles
    public Board twin() {
        int[][] newTiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(tiles[i], 0, newTiles[i], 0, n);
        }

        // 找到两个非空白的方块进行交换
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (newTiles[i][j] != 0) { // 找到第一个非空白方块
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (newTiles[x][y] != 0 && (x != i || y != j)) { // 找到第二个非空白方块
                                // 交换两个方块
                                int temp = newTiles[i][j];
                                newTiles[i][j] = newTiles[x][y];
                                newTiles[x][y] = temp;
                                return new Board(newTiles); // 返回新的棋盘
                            }
                        }
                    }
                }
            }
        }

        return this; // 不应该到达这里，确保返回一个有效的 Board
    }

    // unit testing (not graded)
    public static void main(String[] args) {
        int[][] array = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
        Board board = new Board(array);
        System.out.println(board.isGoal());
        for (Board is : board.neighbors()) {
            for (Board is2 : is.neighbors()) {
                System.out.println(is2);
                System.out.println("is");
                System.out.println(is2.manhattan());
                System.out.println();
            }
        }

    }
}