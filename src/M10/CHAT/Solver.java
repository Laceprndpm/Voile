package M10.CHAT;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class Solver {
    private final int moves;
    private final Iterable<Board> solution;

    public Solver(Board initial) {
        if (initial == null)
            throw new IllegalArgumentException("Initial board cannot be null.");
        PriorityQueue<SearchNode> pq = new PriorityQueue<>();
        pq.add(new SearchNode(initial, 0, null));
        SearchNode solutionNode = null;

        while (!pq.isEmpty()) {
            SearchNode currentNode = pq.poll();

            if (currentNode.board.isGoal()) {
                solutionNode = currentNode;
                break;
            }

            for (Board neighbor : currentNode.board.neighbors()) {
                if (currentNode.previous == null || !neighbor.equals(currentNode.previous)) {
                    pq.add(new SearchNode(neighbor, currentNode.moves + 1, currentNode.board));
                }
            }
        }

        if (solutionNode == null) {
            moves = -1;
            solution = null;
        } else {
            moves = solutionNode.moves;
            solution = constructSolution(solutionNode);
        }
    }

    private Iterable<Board> constructSolution(SearchNode node) {
        List<Board> solution = new ArrayList<>();

        // 反向追踪到初始节点
        while (node != null) {
            solution.add(node.board);
            node = node.previous; // 追踪到前一个节点
        }

        // 由于我们是从目标节点开始追踪的，所以需要反转列表
        Collections.reverse(solution);
        return solution;
    }

    public boolean isSolvable() {
        return moves != -1;
    }

    public int moves() {
        return moves;
    }

    public Iterable<Board> solution() {
        return solution;
    }

    private static class SearchNode implements Comparable<SearchNode> {
        private final Board board;
        private final int moves;
        private final Board previous;
        private final int priority;

        public SearchNode(Board board, int moves, Board previous) {
            this.board = board;
            this.moves = moves;
            this.previous = previous;
            this.priority = moves + board.manhattan(); // 可以选择 Hamming 作为替代
        }

        @Override
        public int compareTo(SearchNode other) {
            return Integer.compare(this.priority, other.priority);
        }
    }

    public static void main(String[] args) {
        // 读取输入并解决拼图的逻辑
        // ...
    }
}
