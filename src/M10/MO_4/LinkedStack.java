package M10.MO_4;

// A basic stack type,with the methods of pop(),push(),isempty()
public class LinkedStack {
    private Node head = null;
    private int size = 0;

    private class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
        }
    }

    public void push(String data) {
        this.size++;
        Node oldhead = this.head;
        this.head = new Node(data);
        this.head.next = oldhead;
    }

    public String pop() {
        if (head == null) {
            throw new IllegalStateException("Stack is empty");
        } else {
            this.size--;
        }
        String data = head.data;
        head = head.next;
        return data;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public int getsize() {
        return size;
    }
}
