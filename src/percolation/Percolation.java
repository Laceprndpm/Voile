// public class Percolation {
//     private int[][] parent;
//     private boolean[][] box;
//     private int n;
//     private int[][] size;
//     private int opencount = 0;
//     // creates n-by-n grid, with all sites initially blocked
//     public Percolation(int n){
//         this.n = n;
//         this.parent = new int[n+1][n];
//         this.box = new boolean[n][n];
//         this.size = new int[n+1][n];
//         for (int i = 0; i < n+1; i++) {
//             for (int j = 0; j < n; j++) {
//                 this.parent[i][j] = i * n + j;
//                 this.size[i][j] = 1;
//                 // this.box[i][j]=false;
//             }
//         }
//         // The root and the tail
//         this.parent[n][0] = n * n;
//         this.parent[n][1] = n * n + 1;
//         for (int i = 0; i < n; i++) {
//             parent[0][i] = parent[n][0];
//             parent[n-1][i] = parent[n][1];
//         }
//     }

//     // opens the site (row, col) if it is not open already
//     public void open(int row, int col) {
//         if (this.isOpen(row, col)==true) {
//             return;
//         } else {
//             this.opencount++;
//             this.box[row][col] = true;
//             connectAdjacent(row,col);
//             return;
//         }
//     }

//     // is the site (row, col) open?
//     public boolean isOpen(int row, int col) {
//         return box[row][col];
//     }

//     // is the site (row, col) full?
//     public boolean isFull(int row, int col) {
//         if (this.find(row, col) == this.find(n, 0)) {
//             return true;
//         } else {
//             return false;
//         }
//     }

//     // returns the number of open sites
//     public int numberOfOpenSites() {
//         return opencount;
//     }

//     // does the system percolate?
//     public boolean percolates() {
//         return (find(n, 1)==find(n, 0));
//     }

//     //find method
//     public int find(int row, int col) {
//         if (parent[row][col] != row * n + col) {
//             int newrow = parent[row][col] / n;
//             int newcol = parent[row][col] % n;
//             parent[row][col] = find(newrow, newcol); // 路径压缩
//         }
//         return parent[row][col];
//     }

//     // public int find(int row, int col) {
//     //     if (parent[row][col] != row) { // 这里假设父节点指向当前行
//     //         int rootRow = parent[row][col];
//     //         parent[row][col] = find(rootRow, col); // 路径压缩
//     //     }
//     //     return parent[row][col]; // 返回根节点
//     // }

//     private void connectAdjacent(int row, int col) {
//         // 检查并连接相邻的开放站点
//         if (row > 0 && isOpen(row - 1, col))
//             union(row, col, row - 1, col); // 上
//         if (row < n - 1 && isOpen(row + 1, col))
//             union(row, col, row + 1, col); // 下
//         if (col > 0 && isOpen(row, col - 1))
//             union(row, col, row, col - 1); // 左
//         if (col < n - 1 && isOpen(row, col + 1))
//             union(row, col, row, col + 1); // 右
//     }

//     private void union(int row1, int col1, int row2, int col2) {
//         int root1 = find(row1, col1);
//         int root2 = find(row2, col2);

//         if (root1 != root2) {
//             // 按大小合并
//             if (size[root1/n][root1%n] < size[root2/n][root2%n]) {
//                 parent[root1/n][root1%n] = root2; // 连接根
//                 size[root2/n][root2%n] += size[root1/n][root1%n];
//             } else {
//                 parent[root2/n][root2%n] = root1; // 连接根
//                 size[root1/n][root1%n] += size[root2/n][root2%n];
//             }
//         }
//     }

//     // parent client (optional)
//     public static void main(String[] args) {
//         Percolation percolation = new Percolation(5);
//         percolation.open(0, 0);
//     }
// }
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private boolean[][] grid;
    private WeightedQuickUnionUF uf;
    private int openCount;
    private int n;
    private int virtualTop;
    private int virtualBottom;

    public Percolation(int n) {
        if (n <= 0)
            throw new IllegalArgumentException("n must be greater than 0");
        this.n = n;
        this.grid = new boolean[n][n];
        this.uf = new WeightedQuickUnionUF(n * n + 2);
        this.virtualTop = n * n; // virtual top
        this.virtualBottom = n * n + 1; // virtual bottom
        this.openCount = 0;
    }

    public void open(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("row and col must be between 1 and n");
        if (!isOpen(row, col)) {
            grid[row - 1][col - 1] = true;
            openCount++;
            int index = (row - 1) * n + (col - 1);
            if (row == 1)
                uf.union(index, virtualTop); // connect to virtual top
            if (row == n)
                uf.union(index, virtualBottom); // connect to virtual bottom

            // connect to adjacent open sites
            connectAdjacent(row, col);
        }
    }

    public boolean isOpen(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("row and col must be between 1 and n");
        return grid[row - 1][col - 1];
    }

    public boolean isFull(int row, int col) {
        if (row < 1 || row > n || col < 1 || col > n)
            throw new IllegalArgumentException("row and col must be between 1 and n");
        return uf.connected((row - 1) * n + (col - 1), virtualTop);
    }

    public int numberOfOpenSites() {
        return openCount;
    }

    public boolean percolates() {
        return uf.connected(virtualTop, virtualBottom);
    }

    private void connectAdjacent(int row, int col) {
        int index = (row - 1) * n + (col - 1);
        if (row > 1 && isOpen(row - 1, col)) // up
            uf.union(index, (row - 2) * n + (col - 1));
        if (row < n && isOpen(row + 1, col)) // down
            uf.union(index, row * n + (col - 1));
        if (col > 1 && isOpen(row, col - 1)) // left
            uf.union(index, (row - 1) * n + (col - 2));
        if (col < n && isOpen(row, col + 1)) // right
            uf.union(index, (row - 1) * n + col);
    }

    public static void main(String[] args) {
        // Test client (optional)
        Percolation p = new Percolation(5);
        p.open(1, 1);
        System.out.println("Is (1,1) open? " + p.isOpen(1, 1)); // true
    }
}
