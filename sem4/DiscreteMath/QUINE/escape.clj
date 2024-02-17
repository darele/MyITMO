(defn escape [s]
    (clojure.string/escape s {\" "\\\"" \\ "\\\\"})
)
(defn readManyLines [s]
    (cond
        (not= s "")
        (do
            (def line (read-line))
            (str line "\n" (readManyLines line))
        )
    )
)
(println (escape (readManyLines "a")))

