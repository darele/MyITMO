use std::io::{self, BufRead};
fn escape(input: &str) -> String {
    let mut result = String::new();
    for c in input.chars() {
        match c {
            '"' => result.push_str("\\\""),
            '\\' => result.push_str("\\\\"),
            _ => result.push(c),
        }
    }
    result
}
fn main() {
    let stdin = io::stdin();
    loop {
        let mut line = String::new();
        stdin.lock().read_line(&mut line).unwrap();
        let input = line.trim();
        if input == "" {
            break;
        }
        println!("{}", escape(&input));
    }
}