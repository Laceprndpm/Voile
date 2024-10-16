import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Random;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] array;
    private int size;
    private final Random random;

    // construct an empty randomized queue
    @SuppressWarnings("unchecked")
    public RandomizedQueue() {
        this.array = (Item[]) new Object[2];
        random = new Random();
        size = 0;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return size == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        return size;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) {
            throw new IllegalArgumentException("Null item");
        }
        if (size == array.length) {
            resize(size * 2);
        }
        array[size++] = item;
    }

    private void resize(int capacity) {
        @SuppressWarnings("unchecked")
        Item[] newArray = (Item[]) new Object[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        this.array = newArray;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        int index = random.nextInt(size);
        Item item = array[index];
        array[index] = array[--size];
        array[size] = null;
        if (size > 0 && size == array.length / 4) {
            resize(array.length / 2);
        }
        return item;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return array[random.nextInt(size)];
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomizedIterator();
    }

    private class RandomizedIterator implements Iterator<Item> {
        private final Item[] copy;
        private int current;

        @SuppressWarnings("unchecked")
        public RandomizedIterator() {
            copy = (Item[]) new Object[size];
            System.arraycopy(array, 0, copy, 0, size);
            shuffle(copy);
            current = 0;
        }

        private void shuffle(Item[] array) {
            for (int i = size - 1; i > 0; i--) {
                int j = random.nextInt(i + 1);
                Item temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException("No remove method");
        }

        @Override
        public boolean hasNext() {
            return current < size;
        }

        @Override
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException("No more Elements");
            }
            return copy[current++];
        }

    }

    // unit testing (required)
    public static void main(String[] args) {
        RandomizedQueue<String> randomizedQueue = new RandomizedQueue<>();
        randomizedQueue.enqueue("NUM1");
        randomizedQueue.enqueue("NUM2");
        int size = randomizedQueue.size();
        System.out.println(size);
        System.out.println(randomizedQueue.sample());
        String temp = randomizedQueue.dequeue();
        System.out.println(temp);
        randomizedQueue.dequeue();
        System.err.println("----");
        randomizedQueue.enqueue("caution!");
        randomizedQueue.enqueue("NUM1");
        randomizedQueue.enqueue("NUM2");
        for (String i : randomizedQueue) {
            System.err.println(i);
        }
    }

}