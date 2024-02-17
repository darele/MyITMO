;Helping functions

(defn sumvec [a]
    (letfn [
            (sumavec [a b]
                (
                cond
                    (== 0 (count a)) b
                :else
                    (recur (pop a) (+ b (peek a)))
                )
            )
        ]
        (sumavec a 0)
    )
)

(defn vop [a b f c]
    (
    cond
        (== 0 (count a)) (vec (rseq c))
    :else
        (recur (pop a) (pop b) f (conj c (f (peek a) (peek b))))
    )
)

;functions for vectors

(defn v+ [a b]
    (vop a b + [])
)

(defn v- [a b]
    (vop a b - [])
)

(defn v* [a b]
    (vop a b * [])
)

(defn vd [a b]
    (vop a b / [])
)

(defn v*s [a b]
    (v* a (vec (repeat (count a) b)))
)

(defn scalar [a b]
    (sumvec (v* a b))
)

;two dimensional vectors are expected
(defn det [a b]
    (- (scalar (pop a) (vector (peek b))) (scalar (pop b) (vector (peek a))))
)

;three dimensional vectors are expected
(defn vect [a b]
    (vector 
        (det
            (vector (peek (pop a)) (peek a)) (vector (peek (pop b)) (peek b))
        )
        (* 
            -1
            (det
                (vector 
                    (peek (pop (pop a))) (peek a)
                )
                (vector
                    (peek (pop (pop b))) (peek b)
                )
            )
        )
        (det
            (pop a) (pop b)
        )
    )
)

;Matrix functions

;Helping functions
;Assuming the two received matrices have the same # of rows and columns
(defn matop [a b f c]
    (
    cond
        (== 0 (count a)) (vec (rseq c))
    :else
        (recur
            (pop a) (pop b) f
            (conj 
                c (vop (peek a) (peek b) f [])
            )
        )
    )
)

;Expects a matrix
;returns the vector of the sum of the elements of every row
(defn vec_of_sum [a c]
    (
    cond
        (== 0 (count a)) (vec (rseq c))
    :else
        (recur (pop a) (conj c 
                (sumvec (peek a))
            )
        )
    )
)

;Given a matrix, gets the vector of last column
(defn last_vector [a]
    (letfn [
        (last_vector [a b]
            (
            cond
                (== 0 (count a)) (vec (rseq b))
            :else
                (recur (pop a) (conj b (peek (peek a))))
            )
        )]
        (last_vector a [])
    )
)

;Now matrix functions
(defn m+ [a b]
    (matop a b + [])
)
(defn m- [a b]
    (matop a b - [])
)
(defn m* [a b]
    (matop a b * [])
)
(defn md [a b]
    (matop a b / [])
)
(defn m*s [a b]
    (m* 
        a 
        (vec 
            (repeat (count a) (vec (repeat (count (peek a)) b)))
        )
    )
)
(defn m*v [a b]
    (vec_of_sum 
        (m* 
            a (vec (repeat (count a) b))
        )
        []
    )
)
(defn transpose [a]
    (letfn [
        (shorten [a b]
            (
            cond
                (== 0 (count a)) (vec (rseq b))
            :else
                (recur (pop a) (conj b (pop (peek a))))
            )
        )
        (transpose [a b]
            (
            cond
                (== 0 (count (peek a))) (vec (rseq b))
            :else
                (recur (shorten a []) (conj b (last_vector a)))
            )
        )
        ]
        (transpose a [])
    )
)

(defn m*m [a b]
    (letfn [
        (m*m [a b c]
            (
            cond
                (== 0 (count a)) (vec (rseq c))
            :else
                (recur
                    (pop a) b (conj c (m*v b (peek a)))
                )
            )
        )
    ]
    (m*m a (transpose b) [])
    )
)
"""
(println (v+ [8 15] [2 3]))
(println (v- [8 15] [2 3]))
(println (v* [8 15] [2 3]))
(println (vd [8 15] [2 3]))
(println (v*s [8 15] 4))
(println (scalar [1 3 -5] [4 -2 -1]))
(println (det [3 4] [1 2]))
(def a [3 -3 1])
(def b [4 9 2])
"""
"""
(println
    (vector 
    (vector (peek (pop a)) (peek a))
    (vector (peek (pop b)) (peek b))
    )
)
(println
    (vector
        (vector 
            (peek (pop (pop a))) (peek a)
        )
        (vector
            (peek (pop (pop b))) (peek b)
        )
    )
)
(println
    (vector
        (pop a) (pop b)
    )
)
"""
"""
(println (vect [3 -3 1][4 9 2]))
(println (m+ [[1 2 3] [4 5 6]] [[6 5 4] [3 2 1]]))
(println (m- [[1 2 3] [4 5 6]] [[6 5 4] [3 2 1]] ))
(println (m* [[1 2 3] [4 5 6]] [[6 5 4] [3 2 1]] ))
(println (md [[1 2 3] [4 5 6]] [[6 5 4] [3 2 1]] ))
(println (m*s [[1 2 3] [4 5 6]] 4))
(println (vec_of_sum [[1 2 3] [4 5 6]] []))
(println (m*v [[1 2 3] [4 5 6]] [1 2 3]))
(println (last_vector [[1 2 3] [4 5 6]]))
(println (transpose [[1 2 3] [4 5 6]]))
(println (m*m [[1 2 3 4] [5 6 7 8] [9 10 11 12]] [[1 2 3] [4 5 6] [7 8 9] [10 11 12]]))
"""