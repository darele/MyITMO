(require '[clojure.string :as string])

(definterface expression (evaluate [mapa]) (tostring []) (d [var]))

(deftype numero [value] expression 
    (evaluate [this mapa] value)
    (tostring [this] (str value))
    (d [this var] (numero. 0))
)

(deftype var [name] expression 
    (evaluate [this mapa] (get mapa name)) 
    (tostring [this] name)
    (d [this var] 
        (if 
            (== 0 (compare name var)) (numero. 1)
            (numero. 0)
        )
    )
)

(deftype binary-op [a b f fname] expression 
    (evaluate [this mapa] 
        (if
            (double? (.evaluate a mapa)) (f (double (.evaluate a mapa)) (double (.evaluate b mapa)))
            (f (.evaluate a mapa) (.evaluate b mapa))
        )
    )
    (tostring [this] 
        (if
            (== 0 (compare fname "negate")) 
            (string/join 
                ["(" (string/join 
                    " " [fname (.tostring b)]
                    )
                ")"
                ]
            )
            (string/join 
                ["(" (string/join 
                    " " [fname (.tostring a) (.tostring b)]
                    )
                ")"
                ]
            )
        )
    )
    (d [this var] 
        (cond
            (== 0 (compare fname "+")) (binary-op. (.d a var) (.d b var) + "+")
            (or (== 0 (compare fname "-")) (== 0 (compare fname "negate"))) (binary-op. (.d a var) (.d b var) - "-")
            (== 0 (compare fname "*")) 
                (binary-op. 
                    (binary-op. (.d a var) b * "*")
                    (binary-op. a (.d b var) * "*")
                    + "+"
                )
        )
    )
)

(deftype division [a b] expression 
    (evaluate [this mapa] 
        (if
            (and (double? (.evaluate a mapa)) (double? (.evaluate b mapa)))
            (/ (double (.evaluate a mapa)) (double (.evaluate b mapa)))
            (/ (.evaluate a mapa) (.evaluate b mapa))
        )
    )
    (tostring [this] 
        (string/join 
            ["(" (string/join " " ["/" (.tostring a) (.tostring b)]) ")"]
        )
    )
    (d [this var]
        (division.
            (binary-op. 
                (binary-op. (.d a var) b * "*")
                (binary-op. a (.d b var) * "*")
                - "-"
            )
            (binary-op. b b * "*")
        )
    )
)

(deftype unary-op [a f fname] expression
  (evaluate [this mapa] 
        (if
            (double? (.evaluate a mapa)) (f (double (.evaluate a mapa)))
            (f (.evaluate a mapa))
        )
    )
    (tostring [this] 
      (string/join 
          ["(" (string/join 
              " " [fname (.tostring a)]
              )
          ")"
          ]
      )
    )
    (d [this var] 
        (cond
            (== 0 (compare fname "negate")) (unary-op. (.d a var) - "negate")
            (== 0 (compare fname "exp")) 
              (binary-op. (unary-op. a (fn [x] (Math/exp (double x))) "exp") (.d a var) * "*")
            (== 0 (compare fname "ln")) 
              (division. (.d a var) a)
        )
    )
)

(defn Constant [a] (numero. a))
(defn Variable [a] (var. a))
(defn Add [a b] (binary-op. a b + "+"))
(defn Subtract [a b] (binary-op. a b - "-"))
(defn Multiply [a b] (binary-op. a b * "*"))
(defn Divide [a b] (division. a b))
(defn Negate [a] (unary-op. a - "negate"))
(defn Exp [a] (unary-op. a (fn [x] (Math/exp (double x))) "exp"))
(defn Ln [a] (unary-op. a (fn [x] (Math/log (if (double? x) (Math/abs (double x)) (Math/abs x)))) "ln"))
(defn evaluate [a mapa] (.evaluate a mapa))
(defn toString [a] (.tostring a))
(defn diff [a var] (.d a var))

;helping Nuance
(def operadores-binarios
    {
    "+" Add,
    "-" Subtract,
    "*" Multiply,
    "/" Divide,
    }
)
(def operadores-unitarios
    {
    "negate" Negate,
    "exp" Exp,
    "ln" Ln,
    }
)

(defn operator [a]
    (or (contains? operadores-binarios a) (contains? operadores-unitarios a))
)

;expects a list and gets the mathematical expression for it
(defn get-member[a]
    (
    cond
        (number? a) (Constant a)
        (and (symbol? a) (not (operator (str a)))) (Variable (str a))
    :else
        (
        cond
            (list? (first a)) (get-member (first a))
            (number? (first a)) (Constant (first a))
            (not (operator (str (first a)))) (Variable (str (first a)))
            (contains? operadores-unitarios (str (first a))) ((get operadores-unitarios (str (first a))) (get-member (rest a)))
            ;; :NOTE: и тут тогда будет только одна строчка
            :else ((get operadores-binarios (str (first a))) (get-member (rest a)) (get-member (rest (rest a))))
        )
    )
)

(defn parseObject [a]
    (get-member (read-string a))
)

;(def expr (ln (Variable "x")))
;(println (toString (diff expr "x")))
;(println (toString (diff (Divide (Negate (Variable "x")) (Constant 2.0)) "x")))

;(def expr
;    (parseObject "(/ 1 x)")
;)

;(def kika (diff expr "x"))

;(println (toString kika))
;(println (evaluate expr {"z" 0.0, "x" 0.0, "y" 0.0}))