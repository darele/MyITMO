package queue;

import java.util.*;

/*
Model: a[1]...a[n]
Invariant: for i in 1..n: a[i] != null

let inmutable(n): for i = 1..n: a'[i] == a[i]

*/
public class ArrayQueueModule {
    private static int ini, fin, size;
    private static Object[] content = new Object[2];
    private static final Map<Object, Integer> countMap = new HashMap<Object, Integer>();

    /*
    Pred: element != null
    post: fin' = (fin + 1) % n' && a[fin'] == element && inmutable(n');
    */
    public static void enqueue(Object element) {
        assert element != null;
        ensureCapacity(size + 1);
        size++;
        content[fin++] = element;
        countMap.putIfAbsent(element, 0);
        countMap.put(element, countMap.get(element) + 1);
        fin %= content.length;
    }

    /*
        Pred: n > 0
        post: inmutable(n') && capacity > n;
    */
    private static void ensureCapacity(int n) {
        if (content.length <= n) {
            if (fin < ini) {
                Object[] tempContent1 = Arrays.copyOfRange(content, 0, fin);
                Object[] tempContent2 = Arrays.copyOfRange(content, ini, content.length);
                int dif = (content.length - ini);
                content = Arrays.copyOf(tempContent1, n * 2);
                ini = content.length - dif;
                for (int i = 0; i < tempContent2.length; i++) {
                    content[ini + i] = tempContent2[i];
                }
            } else {
                content = Arrays.copyOf(content, 2 * size);
            }
        }
    }

    /*
        Pred: n' > 0
        Post: R = a[ini'] && inmutable(n');
    */
    public static Object element() {
        assert size > 0;
        return content[ini];
    }

    /*
        Pred: n' > 0
        Post: R = content[ini'] && ini' = (ini + 1) % n && n' == n - 1 && inmutable(n');
    */
    public static Object dequeue() {
        assert fin != ini;
        Object result = content[ini];
        ini++;
        size--;
        ini %= content.length;
        countMap.put(result, countMap.get(result) - 1);
        return result;
    }

    /*
        Pred: true
        Post: R = n' && inmutable(n');
    */
    public static int size() {
        return size;
    }


    /*
        Pred: true
        Post: R = (n' == 0) && inmutable(n');
    */
    public static boolean isEmpty() {
        return ini == fin;
    }

    /*
        Pred: true
        Post: n' = 0 && ini = fin = 0 && inmutable(n);
    */
    public static void clear() {
        countMap.clear();
        size = 0;
        ini = 0;
        fin = 0;
    }

    /*
        Pred: element != null
        Post: R = |element| (number of times element appears) && inmutable(n');
    */
    public static int count(Object element) {
        assert element != null;
        return countMap.getOrDefault(element, 0);
    }
}