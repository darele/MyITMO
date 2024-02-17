package queue;

import java.util.*;

/*
Model: a[1]...a[n]
Invariant: for i in 1..n: a[i] != null

let inmutable(n): for i = 1..n: a'[i] == a[i]

*/
public class ArrayQueueADT {
    private int ini, fin, size;
    private Object[] content = new Object[2];
    private Map<Object, Integer> countMap = new HashMap<Object, Integer>();

    public ArrayQueueADT() {
        
    }

    /*
        Pred: true
        Post: R = instance of ArrayQueueADT && ini = fin = 0 && n' = 0 && inmutable(n')
    */
    public static ArrayQueueADT create() {
        final ArrayQueueADT cola = new ArrayQueueADT();
        cola.content = new Object[2];
        cola.countMap = new HashMap<Object, Integer>();
        cola.ini = 0;
        cola.fin = 0;
        cola.size = 0;
        return cola;
    }

    /*
    Pred: element != null
    post: fin' = (fin + 1) % n' && a[fin'] == element && inmutable(n');
    */
    public static void enqueue(ArrayQueueADT cola, Object element) {
        assert element != null;
        ensureCapacity(cola, cola.size + 1);
        cola.size++;
        cola.content[cola.fin++] = element;
        cola.fin %= cola.content.length;
        cola.countMap.putIfAbsent(element, 0);
        cola.countMap.put(element, cola.countMap.get(element) + 1);
    }

    /*
        Pred: n > 0
        post: inmutable(n') && capacity > n;
    */
    private static void ensureCapacity(ArrayQueueADT cola, int n) {
        if (cola.content.length <= n) {
            if (cola.fin < cola.ini) {
                Object[] tempContent1 = Arrays.copyOfRange(cola.content, 0, cola.fin);
                Object[] tempContent2 = Arrays.copyOfRange(cola.content, cola.ini, cola.content.length);
                int dif = (cola.content.length - cola.ini);
                cola.content = Arrays.copyOf(tempContent1, n * 2);
                cola.ini = cola.content.length - dif;
                for (int i = 0; i < tempContent2.length; i++) {
                    cola.content[cola.ini + i] = tempContent2[i];
                }
            } else {
                cola.content = Arrays.copyOf(cola.content, 2 * n);
            }
        }
    }

    /*
        Pred: n' > 0
        Post: R = a[ini'] && inmutable(n');
    */
    public static Object element(ArrayQueueADT cola) {
        assert cola.fin != cola.ini;
        return cola.content[cola.ini];
    }

    /*
        Pred: n' > 0
        Post: R = content[ini'] && ini' = (ini + 1) % n && n' == n - 1 && inmutable(n');
    */
    public static Object dequeue(ArrayQueueADT cola) {
        assert cola.size > 0;
        Object result = cola.content[cola.ini];
        cola.ini++;
        cola.ini %= cola.content.length;
        cola.size--;
        cola.countMap.put(result, cola.countMap.get(result) - 1);
        return result;
    }

    /*
        Pred: true
        Post: R = n' && inmutable(n');
    */
    public static int size(ArrayQueueADT cola) {
        return cola.size;
    }

    /*
        Pred: true
        Post: R = (n' == 0) && inmutable(n');
    */
    public static boolean isEmpty(ArrayQueueADT cola) {
        return cola.size == 0;
    }

   /*
        Pred: true
        Post: n' = 0 && ini = fin = 0 && inmutable(n);
    */
    public static void clear(ArrayQueueADT cola) {
        cola.content = new Object[2];
        cola.ini = 0;
        cola.fin = 0;
        cola.size = 0;
        cola.countMap.clear();
    }

    /*
        Pred: element != null
        Post: R = |element| (number of times element appears) && inmutable(n');
    */
    public static int count(ArrayQueueADT cola, Object element) {
        assert element != null;
        return cola.countMap.getOrDefault(element, 0);
    }


    //My own function, ignore :D
    public static void print(ArrayQueueADT cola) {
        for (int i = 0; i < cola.content.length; i++) {
            System.out.print(cola.content[i] + " ");
        }
        System.out.println();
    }
}