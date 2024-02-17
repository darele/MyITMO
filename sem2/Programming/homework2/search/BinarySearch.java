package search;

import java.util.*;

public class BinarySearch {

    //Recursive search
    /*Pred: array is sorted by non-increasing order
        *x >= min(list)
        *ini = 0
        *fin = list.length - 1
    */
    //Post: list[R] <= x
    public static int search(int x, ArrayList<Integer> list, int ini, int fin) {
        if (ini > fin) {
            // ini' > fin' && ((fin < list.size() && list[fin] <= x) || list[ini] <= x)
            if (fin >= 0 && list.get(fin) <= x) {
                //list[fin] <= x && fin >= 0
                return fin;
            } else {
                //list[fin] > x || fin < 0
                return ini;
            }
        }
        //ini <= fin
        int mid = (ini + fin) / 2;
        if (list.get(mid) <= x) {
            //list[mid] <= x
            return search(x, list, ini, mid - 1);
            //list[R'] <= x
        } else {
            //list[mid] > x && list[R'] <= x
            return search(x, list, mid + 1, fin);
            //list[R'] <= x
        }
    }

    //iterative search
    /*Pred:
        *array is sorted by non-decreasing order
        *x >= min(list)
    */
    //Post: list[R] <= x
    public static int search(int x, ArrayList<Integer> list) {
        int ini = 0, fin = list.size() - 1;
        int mid = (ini + fin) / 2;
        //list[fin] <= x || list[ini] <= x
        while (ini <= fin) {
            //list[fin] <= x || list[ini] <= x && ini <= fin
            mid = (ini + fin) / 2;
            if (list.get(mid) <= x) {
                //list[mid] <= x && (list[fin] <= x || list[ini] <= x)
                //But if list[mid] <= x is satisfied, then the other is not necessary
                fin = mid - 1;
            } else {
                //list[mid] > x && (list[fin] <= x || list[ini] <= x)
                ini = mid + 1;
            }
        }
        //list[fin] <= x || list[ini] <= x
        if (fin >= 0 && list.get(fin) <= x) {
            //fin >= 0 && list[fin] <= x
            return fin;
            //list[R'] <= x
        } else {
            //fin < 0 || list[fin] > x
            return ini;
            //list[R'] <= x
        }
    }

    public static void main (String[] args) {
        int x = Integer.parseInt(args[0]);
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i < args.length; i++) {
            list.add(Integer.parseInt(args[i]));
        }
        //System.out.println(search(x, list, 0, list.size() - 1));
        System.out.println(search(x, list));
    }
}