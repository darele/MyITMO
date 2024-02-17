package queue;

public class MyArrayQueueTest {
    public static void fill(ArrayQueue cola) {
        for (int i = 0; i < 10; i++) {
            //ArrayQueue.print(cola);
            cola.enqueue(i);
        }
    }

    public static void dump(ArrayQueue cola) {
        int testcycle = 0;
        while (!cola.isEmpty()) {
            System.out.println(
                cola.size() + " " +
                cola.count(cola.element()) + " " +
                cola.element() + " " +
                cola.dequeue()
            );
            if (testcycle % 3 == 0) {
                cola.enqueue(testcycle);
            }
            testcycle++;
        }
    }

    public static void main(String[] args) {
        ArrayQueue cola1 = new ArrayQueue();
        ArrayQueue cola2 = new ArrayQueue();
        fill(cola1);
        fill(cola2);
        dump(cola1);
        dump(cola2);
        fill(cola1);
        cola1.clear();
        dump(cola1);
    }
}
