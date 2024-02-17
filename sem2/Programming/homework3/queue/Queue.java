package queue;

import java.util.function.Predicate;

/*
Model: a[1]...a[n]
Invariant: for i in 1..n: a[i] != null

let inmutable(n): for i = 1..n: a'[i] == a[i]
*/

public interface Queue{
    /*
    Pred: element != null
    post: n' = n + 1 == element && head' == element && inmutable(n');
    */
    public void enqueue(Object element);

    /*
        Pred: n' > 0
        Post: R = tail' && inmutable(n');
    */
    public Object element();

    /*
        Pred: n' > 0
        Post: R = tail && tail' = tail.next && n' == n - 1 && inmutable(n');
    */
    public Object dequeue();

    /*
        Pred: true
        Post: head == tail && n' == 0 && inmutable(n');
    */
    public void clear();

    /*
        Pred: true
        Post: R = n' && inmutable(n');
    */
    public int size();

    /*
        Pred: true
        Post: R = (n' == 0) && inmutable(n');
    */
    public boolean isEmpty();

    /*
        Pred: element != null
        Post: R = |element| (number of times element appears) && inmutable(n');
    */
    public int count(Object element);

    /*
        Pred: p != null
        Post: R = Number of elements satisfying p && inmutable(n');
    */
    public int countIf(Predicate <Object> p);


}