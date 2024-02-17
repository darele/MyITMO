package queue;

public class ArrayQueueADTTest {
    public static void fill(ArrayQueueADT cola) {
        for (int i = 0; i < 10; i++) {
            //ArrayQueueADT.print(cola);
            ArrayQueueADT.enqueue(cola, i);
        }
    }

    public static void dump(ArrayQueueADT cola) {
        int testcycle = 0;
        while (!ArrayQueueADT.isEmpty(cola)) {
            System.out.println(
                ArrayQueueADT.size(cola) + " " +
                ArrayQueueADT.count(cola, ArrayQueueADT.element(cola)) + " " +
                ArrayQueueADT.element(cola) + " " +
                ArrayQueueADT.dequeue(cola)
            );
            if (testcycle % 3 == 0) {
                ArrayQueueADT.enqueue(cola, testcycle);
            }
            testcycle++;
        }
    }

    public static void main(String[] args) {
        ArrayQueueADT cola1 = ArrayQueueADT.create();
        ArrayQueueADT cola2 = ArrayQueueADT.create();
        fill(cola1);
        fill(cola2);
        dump(cola1);
        dump(cola2);
        fill(cola1);
        ArrayQueueADT.clear(cola1);
        dump(cola1);
    }
}
