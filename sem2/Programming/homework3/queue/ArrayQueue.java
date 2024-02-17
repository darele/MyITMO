package queue;

import java.util.*;

/*
Model: a[1]...a[n]
Invariant: for i in 1..n: a[i] != null

let inmutable(n): for i = 1..n: a'[i] == a[i]

*/
public class ArrayQueue extends AbstractQueue{
    private int ini, fin;
    private Object[] content;

    public ArrayQueue() {
        content = new Object[2];
        ini = 0;
        fin = 0;
    }

    private void create() {
        this.content = new Object[2];
        this.ini = 0;
        this.fin = 0;
    }

    public void enqueueImpl(ArrayQueue this, Object element) {
        ensureCapacity(this.size + 1);
        this.content[this.fin++] = element;
        this.fin %= this.content.length;
    }

    private void ensureCapacity(int n) {
        if (this.content.length <= n) {
            if (this.fin < this.ini) {
                Object[] tempContent1 = Arrays.copyOfRange(this.content, 0, this.fin);
                Object[] tempContent2 = Arrays.copyOfRange(this.content, this.ini, this.content.length);
                int dif = (this.content.length - this.ini);
                this.content = Arrays.copyOf(tempContent1, n * 2);
                this.ini = this.content.length - dif;
                for (int i = 0; i < tempContent2.length; i++) {
                    this.content[this.ini + i] = tempContent2[i];
                }
            } else {
                this.content = Arrays.copyOf(this.content, 2 * n);
            }
        }
    }

    public Object elementImpl(ArrayQueue this) {
        return this.content[this.ini];
    }

    public void dequeueImpl(ArrayQueue this) {
        this.ini++;
        this.ini %= this.content.length;
    }

    public boolean isEmpty(ArrayQueue this) {
        return this.ini == this.fin;
    }

    public void clearImpl(ArrayQueue this) {
        this.create();
    }

    //My own methods, ignore :D
    public void print(ArrayQueue this) {
        for (int i = 0; i < this.content.length; i++) {
            System.out.print(this.content[i] + " ");
        }
        System.out.println();
    }
}