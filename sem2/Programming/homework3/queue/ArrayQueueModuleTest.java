package queue;

public class ArrayQueueModuleTest {
    public static void fill() {
        for (int i = 0; i < 10; i++) {
            ArrayQueueModule.enqueue(i);
        }/*
        for (int i = 0; i < 10; i++) {
            ArrayQueueModule.enqueue(i);
        }
        */
    }

    public static void dump() {
        int testcycle = 0;
        while (!ArrayQueueModule.isEmpty()) {
            System.out.println(
                ArrayQueueModule.size() + " " +
                ArrayQueueModule.count(ArrayQueueModule.element()) + " " +
                ArrayQueueModule.element() + " " +
                ArrayQueueModule.dequeue()
            );
            if (testcycle % 3 == 0) {
                ArrayQueueModule.enqueue(testcycle);
            }
            testcycle++;
        }
    }

    /*
    public static void sacar() {
        for (int i = 0; i < 4; i++) {
            System.out.println(ArrayQueueModule.deque());
            ArrayQueueModule.print();
        }
    }
    */

    public static void main(String[] args) {
        fill();
        /*sacar();
        fill();
        sacar();
        fill();
        sacar();
        sacar();
        sacar();
        sacar();
        sacar();
        sacar();
        sacar();
        sacar();*/
        dump();
        fill();
        ArrayQueueModule.clear();
        dump();
    }
}
