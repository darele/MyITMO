(defn escape [s]
    (clojure.string/escape s {\' "'" \" "\\\"" \\ "\\\\"})
)
(def src "fn escape(input: &str) -> String {
    let mut result = String::new();
    for c in input.chars() {
        match c {
            '\"' => result.push_str(\"\\\\\\\"\"),
            '\\\\' => result.push_str(\"\\\\\\\\\"),
            _ => result.push(c),
        }
    }
    result
}
fn main() {
    let src = \"?\";
    let this_src = \"~\";
    let p = &src.find('?').unwrap();
    let p2 = &src.find('~').unwrap();
    let first_part = &src[0..*p];
    let second_part = escape(&this_src);
    let third_part = &src[(p + 1)..*p2];
    let fourth_part = escape(&src);
    let fifth_part = &src[(p2 + 1)..];
    println!(\"{}{}{}{}{}\", first_part, second_part, third_part, fourth_part, fifth_part);
}

")
(def thisSrc "(defn escape [s]
(clojure.string/escape s {\\' \"'\" \\\" \"\\\\\\\"\" \\\\ \"\\\\\\\\\"})
)
(def src \"?\")
(def thisSrc \"~\")
(def p (clojure.string/index-of src \"?\"))
(def p2 (clojure.string/index-of src \"~\"))
(println (str (subs src 0 p) (escape thisSrc) (subs src (+ p 1) p2) (escape src) (subs src (+ p2 1))))")
(def p (clojure.string/index-of src "?"))
(def p2 (clojure.string/index-of src "~"))
(println (str (subs src 0 p) (escape thisSrc) (subs src (+ p 1) p2) (escape src) (subs src (+ p2 1))))

