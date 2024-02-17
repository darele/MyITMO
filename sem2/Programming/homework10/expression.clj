(defn constant [a]
    (fn [mapa] a)
)

(defn variable [x]
    (fn [mapa] (get mapa x))
)

(defn negate [x]
    (fn [mapa]
        (if (double? (x mapa)) 
            (- (double (x mapa)))
            (- (x mapa))
        )
    )
)

(defn exp [a]
    (fn [mapa] (java.lang.Math/exp (a mapa)))
)

(defn ln [a]
    (fn [mapa] (Math/log (Math/abs (double (a mapa)))))
)

(defn binary_operator [a b f]
    (fn [mapa] (f (a mapa) (b mapa)))
)

(defn add [a b]
    (binary_operator a b +)
)

(defn subtract [a b]
    (binary_operator a b -)
)

(defn multiply [a b]
    (binary_operator a b *)
)

(defn divide [a b]
    (fn [mapa]
        (if (and (double? (a mapa)) (double? (b mapa)))
            (/ (double (a mapa)) (double (b mapa)))
            (/ (a mapa) (b mapa))
        )
    )
)

;helping functions
(defn operator [a]
    (or 
        (== 0 (compare a "+"))
        (or
            (== 0 (compare a "-"))
            (or
                (== 0 (compare a "*"))
                (or
                    (== 0 (compare a "negate"))
                    (or
                        (== 0 (compare a "/"))
                        (or
                            (== 0 (compare a "exp"))
                            (== 0 (compare a "ln"))
                        )
                    )
                )
            )
        )
    )
)

;expects a list and gets the mathematical expression for it
(defn get-member[a]
    (
    cond
        (number? a) (constant a)
        (and (symbol? a) (not (operator (str a)))) (variable (str a))
    :else
        (
        cond
            (list? (first a)) (get-member (first a))
            (number? (first a)) (constant (first a))
            (not (operator (str (first a)))) (variable (str (first a)))
            (== 0 (compare (str (first a)) "+")) (add (get-member (rest a)) (get-member (rest (rest a))))
            (== 0 (compare (str (first a)) "-")) (subtract (get-member (rest a)) (get-member (rest (rest a))))
            (== 0 (compare (str (first a)) "*")) (multiply (get-member (rest a)) (get-member (rest (rest a))))
            (== 0 (compare (str (first a)) "/")) (divide (get-member (rest a)) (get-member (rest (rest a))))
            (== 0 (compare (str (first a)) "negate")) (negate (get-member (rest a)))
            (== 0 (compare (str (first a)) "exp")) (exp (get-member (rest a)))
            (== 0 (compare (str (first a)) "ln")) (ln (get-member (rest a)))
        )
    )
)

(defn parseFunction [a]
    (get-member (read-string a))
)

