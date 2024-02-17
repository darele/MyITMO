(load-file "parser.clj")
(require '[clojure.string :as string])

;Homework10

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

(def foperadores-binarios
    {
    "+" add,
    "-" subtract,
    "*" multiply,
    "/" divide,
    }
)
(def foperadores-unitarios
    {
    "negate" negate,
    "exp" exp,
    "ln" ln,
    }
)

(defn operator [a]
    (or (contains? foperadores-binarios a) (contains? foperadores-unitarios a))
)

;expects a list and gets the mathematical expression for it
(defn fget-member[a]
    (
    cond
        (number? a) (constant a)
        (and (symbol? a) (not (operator (str a)))) (variable (str a))
    :else
        (
        cond
            (list? (first a)) (fget-member (first a))
            (number? (first a)) (constant (first a))
            (not (operator (str (first a)))) (variable (str (first a)))
            (contains? foperadores-unitarios (str (first a))) ((get foperadores-unitarios (str (first a))) (fget-member (rest a)))
            :else ((get foperadores-binarios (str (first a))) (fget-member (rest a)) (fget-member (rest (rest a))))
        )
    )
)

(defn parseFunction [a]
    (fget-member (read-string a))
)


;Homework11

(definterface expression (evaluate [mapa]) (tostring []) (suffix []) (d [var]))

(deftype numero [value] expression 
    (evaluate [this mapa] value)
    (tostring [this] (str value))
    (suffix [this] (str value))
    (d [this var] (numero. 0))
)

(deftype var [name] expression 
    (evaluate [this mapa] (get mapa (string/lower-case (str (first name)))))
    (tostring [this] name)
    (suffix [this] name)
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
        (string/join 
            ["(" (string/join 
                " " [fname (.tostring a) (.tostring b)]
                )
            ")"
            ]
        )
    )
    (suffix [this]
        (string/join
            (string/join 
                ["(" (string/join " " [(.suffix a) (.suffix b) fname]) ")"]
            )
        )
    )
    (d [this var] 
        (cond
            (== 0 (compare fname "+")) (binary-op. (.d a var) (.d b var) + "+")
            (or (== 0 (compare fname "-"))) (binary-op. (.d a var) (.d b var) - "-")
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
    (suffix [this]
        (string/join
            (string/join 
                ["(" (string/join " " [(.suffix a) (.suffix b) "/"]) ")"]
            )
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
    (suffix [this]
        (string/join
            [
                "(" (string/join 
                    " " [(.suffix a) fname]
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

;Homework 11, so far so well

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
(defn toStringSuffix [a] (.suffix a))
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

;Homework 12

(defn sign [s tail]
    (if (#{\+ \-} s)
        (cons s tail)
        tail
    )
)

(def expression-parser
    (let [
        *all-chars (mapv char (range 0 128))
        *letter (+char (apply str (filter #(Character/isLetter %) *all-chars)))
        *string (+str (+plus *letter))
        *digit (+char (apply str (filter #(Character/isDigit %) *all-chars)))
        *number (+map read-string (+str (+seqf sign (+opt (+char "+-")) (+plus (+or (+char ".") *digit)))))
        *space (+char (apply str (filter #(Character/isWhitespace %) *all-chars)))
        *ws (+ignore (+star *space))
        *oparenthesis (+map str (+char "("))
        *cparenthesis (+map str (+char ")"))
        *negate (+seqf (constantly 'negate) (+char "n") (+char "e") (+char "g") (+char "a") (+char "t") (+char "e"))
        *operator (+char "+-*/")
        *unary-operator *negate
        *operando (+or *number *string)]
        (letfn [(*seq [begin p end]
                (+seqn 1 (+char begin) *ws (+opt (+seqf cons *ws p)) *ws (+char end)))
                (*unary-op [] (+seq *ws (+or *operando (delay (*value))) *ws *unary-operator))
                (*binary-op [] (+seq *ws (+or *operando (delay (*value))) *ws (+or *operando (delay (*value))) *ws *operator))
                (*member [] (+seq *ws (+ignore *oparenthesis) *ws (+or (*unary-op) (*binary-op) (delay (*value))) *ws (+ignore *cparenthesis)))
                (*value [] (+or *operando (*member) *operator))]
        (+parser (+seqn 0 *ws (*value) *ws)))))

;expects a vector with expressions within other vectors written in suffix form

(defn parse-by-symbol [v]
    (cond
        (not (vector? v)) (
            if (number? v) 
            (Constant v) 
            (Variable (str v))
        )
        (vector? (peek v)) (parse-by-symbol (peek v));
        (number? (peek v)) (Constant (peek v))
        (not (operator (str (peek v)))) (Variable (str (peek v)))
        (contains? operadores-unitarios (str (peek v))) ((get operadores-unitarios (str (peek v))) (parse-by-symbol (pop v)))
        (contains? operadores-binarios (str (peek v))) ((get operadores-binarios (str (peek v))) (parse-by-symbol (pop (pop v))) (parse-by-symbol (pop v)))
    )
)

(def parseObjectSuffix 
    (fn [input] (parse-by-symbol (expression-parser input)))
)

