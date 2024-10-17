package M10.CHAT;

import java.util.ArrayList;
import java.util.List;

public class Board {
    private final int n;
    private final int[][] tiles;
    private int cache = -1;

    public Board(int[][] tiles) {
        if (tiles == null)
            throw new IllegalArgumentException("Tiles cannot be null.");
        n = tiles.length;
        this.tiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            this.tiles[i] = tiles[i].clone();
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(n).append("\n");
        for (int[] row : tiles) {
            for (int tile : row) {
                sb.append(tile).append(" ");
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    public int dimension() {
        return n;
    }

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

    private int goal(int row, int col) {
        return row * n + col + 1;
    }

    public int manhattan() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += manhattan(i, j);
            }
        }
        return sum;
    }

    private int manhattan(int row, int col) {
        int num = tiles[row][col];
        if (num == 0)
            return 0;
        int goalRow = (num - 1) / n;
        int goalCol = (num - 1) % n;
        return Math.abs(row - goalRow) + Math.abs(col - goalCol);
    }

    public boolean isGoal() {
        return hamming() == 0;
    }

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

    public Iterable<Board> neighbors() {
        List<Board> neighbors = new ArrayList<>();
        int blankRow = -1, blankCol = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tiles[i][j] == 0) {
                    blankRow = i;
                    blankCol = j;
                    break;
                }
            }
        }

        int[] dRow = { -1, 1, 0, 0 };
        int[] dCol = { 0, 0, -1, 1 };

        for (int k = 0; k < 4; k++) {
            int newRow = blankRow + dRow[k];
            int newCol = blankCol + dCol[k];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                int[][] newTiles = new int[n][n];
                for (int i = 0; i < n; i++) {
                    System.arraycopy(tiles[i], 0, newTiles[i], 0, n);
                }
                newTiles[blankRow][blankCol] = newTiles[newRow][newCol];
                newTiles[newRow][newCol] = 0;
                neighbors.add(new Board(newTiles));
            }
        }

        return neighbors;
    }

    public Board twin() {
        int[][] newTiles = new int[n][n];
        for (int i = 0; i < n; i++) {
            System.arraycopy(tiles[i], 0, newTiles[i], 0, n);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (newTiles[i][j] != 0) {
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (newTiles[x][y] != 0 && (x != i || y != j)) {
                                int temp = newTiles[i][j];
                                newTiles[i][j] = newTiles[x][y];
                                newTiles[x][y] = temp;
                                return new Board(newTiles);
                            }
                        }
                    }
                }
            }
        }
        return this; // This line should never be reached
    }

    public static void main(String[] args) {
        int[][] array = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 0 } };
        Board board = new Board(array);
        System.out.println(board.isGoal());
        for (Board neighbor : board.neighbors()) {
            System.out.println(neighbor);
        }
    }
}
