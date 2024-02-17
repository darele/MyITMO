package queue;

public class LinkedQueue extends AbstractQueue {
    private Node head;
    private Node tail;

    public void enqueueImpl(Object element) {
        Node newNode = new Node(element);
        if (this.size == 0) {
            this.tail = newNode;
        } else {
            this.head.next = newNode;
        }
        this.head = newNode;
    }

    public Object elementImpl() {
        return this.tail.value;
    }

    public void dequeueImpl() {
        this.tail = this.tail.next;
    }

    public void clearImpl() {
        this.head = null;
        this.tail = null;
    }

    private class Node {
        private Object value;
        private Node next;

        public Node(Object value) {
            assert value != null;
            this.value = value;
        }
    }
}