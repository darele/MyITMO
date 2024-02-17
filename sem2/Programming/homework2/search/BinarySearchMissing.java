package search;

import java.util.*;

public class BinarySearchMissing {

    //Pred:
    /*
        list.length > 0
        list is sorted by non-decreasing order
        ini = 0
        fin = list.length - 1
    */
    //Post
    /*
        list[R'] >= x
    */
    public static int search(int x, ArrayList<Integer> list, int ini, int fin) {
        if (ini > fin) {
            // ini' > fin' && ((fin >= 0 && list[fin] <= x) || list[ini] >= x || ini == list.size()))
            if (ini < list.size() && list.get(ini) == x) {
                //list[ini] == x
                return ini;
            }
            //(ini == list.size() || list[ini] > x) || list[fin] <= fin
            if (fin >= 0 && list.get(fin) == x) {
                //(list[fin] == x)
                return fin;
            }
            //then list[ini] > x
            return ini;
        }
        //ini' <= fin'
        int mid = (ini + fin) / 2;
        if (list.get(mid) < x) {

            return search(x, list, mid + 1, fin);
        } else {
            return search(x, list, ini, mid - 1);
        }
    }


    //Pred:
    /*
        array is sorted by non-decreasing order
    */
    //Post:
    /*
        list[R'] agrees with the rules of library's implementation for binary search,
    */
    public static int call_search(int x, ArrayList<Integer> list) {
        if (list.size() == 0) {
            return -1;
        }
        int temp = search(x, list, 0, list.size() - 1);
        if (temp < list.size()) {
            return list.get(temp) == x ? temp : -1 * temp - 1;
        } else {
            return -1 * temp - 1;
        }
    }

    //Pred:
    /*
        array is sorted by non-decreasing order
    */
    //Post:
    /*
        list[R'] >= x
    */
    public static int search(int x, ArrayList<Integer> list) {
        int ini = 0, fin = list.size() - 1;
        int mid = (ini + fin) / 2;
        //list ((ini + fin) / 2) <= x
        while (!(ini > fin)) {
            //list[fin] <= x || list[ini] <= x && ini <= fin
            mid = (ini + fin) / 2;
            if (list.get(mid) < x) {
                //list[mid] < x && (list[fin] <= x || list[ini] <= x)
                ini = mid + 1;
            } else {
                //list[mid] >= x && (list[fin] <= x || list[ini] <= x)
                fin = mid - 1;
            }
        }
        //list ((ini + fin) / 2) <= x
        if (ini < list.size() && list.get(ini) == x) {
            //ini < list.size() && list[ini] == x
            return ini;
        }
        //list ((ini + fin) / 2) <= x
        if (fin >= 0 && list.get(fin) == x) {
            //fin >= 0 && list[fin] == x
            return fin;
            //list[R'] <= x
        } else {
            //(fin < 0 || list[fin] > x) && (list[ini] > x || ini == list.size())
            return ini;
            //list[R'] > x || ini == list.size()
        }
    }


    //Pred:
    /*
        array is sorted by non-decreasing order
    */
    //Post:
    /*
        list[R'] agrees with the rules of library
    */
    public static int call_search2(int x, ArrayList<Integer> list) {
        if (list.size() == 0) {
            return -1;
        }
        int temp = search(x, list);
        if (temp < list.size()) {
            return list.get(temp) == x ? temp : -1 * temp - 1;
        } else {
            return -1 * temp - 1;
        }
    }

    public static void main (String[] args) {
        int x = Integer.parseInt(args[0]);
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 1; i < args.length; i++) {
            list.add(Integer.parseInt(args[i]));
        }
        System.out.println(call_search(x, list));
        //System.out.println(call_search2(x, list));
    }
}