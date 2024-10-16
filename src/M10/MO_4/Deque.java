package M10.MO_4;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private Node head, tail;
    private int size = 0;

    private class Node {
        private Node next;
        private Node last;
        private Item data;

        Node(Item data) {
            this.data = data;
        }
    }

    // construct an empty deque
    public Deque() {

    }

    // is the deque empty?
    public boolean isEmpty() {
        return (this.head == null) || (this.tail == null);
    }

    // return the number of items on the deque
    public int size() {
        return size;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("null is not allowed");
        }
        Node oldheade = this.head;
        this.head = new Node(item);
        this.head.next = oldheade;
        if (oldheade != null) {
            oldheade.last = this.head;
        }
        size++;
        if (isEmpty()) {
            this.tail = this.head;
        }
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("null is not allowed");
        }
        Node oldtail = this.tail;
        this.tail = new Node(item);
        if (oldtail != null) {
            oldtail.next = this.tail;
        }
        this.tail.last = oldtail;
        size++;
        if (isEmpty()) {
            this.head = this.tail;
        }
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty()) {
            throw new NoSuchElementException("No more element to remove");
        }
        Item temp = head.data;
        head = head.next;
        size--;
        if (isEmpty()) {
            tail = null;
        }
        return temp;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty()) {
            throw new NoSuchElementException("No more element to remove");
        }
        Item temp = tail.data;
        tail = tail.last;
        size--;
        if (isEmpty()) {
            head = null;
        }
        return temp;
    }

    // return an iterator over items in order from front to back
    // public Iterator<Item> iterator(){

    // }

    // unit testing (required)
    public static void main(String[] args) {
        Deque<String> deque = new Deque<>();
        deque.addFirst("num1");
        System.err.println(deque.removeFirst());
        deque.addLast("num2");
        System.err.println(deque.removeLast());
        deque.addFirst("3");
        deque.addFirst("2");
        deque.addFirst("1");
        deque.addLast("4");
        for (String i : deque) {
            System.err.println(i);
        }

    }

    @Override
    public Iterator<Item> iterator() {
        return new MyIterator();
    }

    private class MyIterator implements Iterator<Item> {
        private Node current = head;

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }

        @Override
        public boolean hasNext() {
            return (current != null);
        }

        @Override
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException("No more");
            }
            Item temp = current.data;
            current = current.next;
            return temp;
        }
    }

}