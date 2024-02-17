package queue;

import java.util.function.Predicate;
import java.util.*;

public abstract class AbstractQueue implements Queue{
    int size;
    final Map<Object, Integer> countMap;
    

    public AbstractQueue() {
        countMap = new HashMap<Object, Integer>();
        size = 0;
    }

    public void enqueue(Object element) {
        assert element != null;
        enqueueImpl(element);
        countMap.putIfAbsent(element, 0);
        countMap.put(element, countMap.get(element) + 1);
        size++;
    }

    protected abstract void enqueueImpl(Object element);

    public Object element() {
        assert size > 0;
        return elementImpl();
    }

    protected abstract Object elementImpl();

    public Object dequeue() {
        assert this.size > 0;
        Object result = element();
        countMap.put(result, countMap.get(result) - 1);
        dequeueImpl();
        this.size--;
        return result;
    }

    protected abstract void dequeueImpl();

    public void clear() {
        clearImpl();
        size = 0;
        countMap.clear();
    }

    protected abstract void clearImpl();

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int count(Object element) {
        assert element != null;
        return countMap.getOrDefault(element, 0);
    }

    public int countIf(Predicate<Object> p) {
        for (Map.Entry<Object, Integer> entry : countMap.entrySet()) {
            if (p.test(entry.getKey())) {
                return entry.getValue();
            }
        }
        return 0;
    }
}