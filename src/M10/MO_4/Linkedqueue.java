package M10.MO_4;

public class Linkedqueue<T> {

    private Node head, tail;

    private class Node {
        T data;
        Node next;

        Node(T data) {
            this.data = data;
        }
    }

    public void enqueue(T data) {
        Node oldtail = this.tail;
        this.tail = new Node(data);
        if (isEmpty()) {
            this.head = this.tail;
        } else {
            oldtail.next = this.tail;
        }
    }

    public T dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("NULL");
        }
        Node oldhead = this.head;
        this.head = head.next;
        if (isEmpty()) {
            tail = null;
        }
        return oldhead.data;
    }

    public boolean isEmpty() {
        return head == null;
    }
}
