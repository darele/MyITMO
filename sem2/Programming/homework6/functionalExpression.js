"use strict";

//const cnst = value => x => value;
//const variable = () => x => x;
//const parse = input => input.trim() === "x" ? variable("x") : cnst(+input);

function evaluar(objeto, x, y, z) {
  if (typeof(objeto) === "number") {
    return objeto;
  } else if (typeof(objeto) == "string") {
    if (objeto === "x") {
      return x;
    } else if (objeto === "y") {
      return y;
    } else {
      return z;
    }
  } else {
    return objeto(x, y, z);
  }
}
  
function data(f) {
  return (a) => {
    return (x, y, z) => {
      return f(evaluar(a, x, y, z));
    }
  }
}

function op(f) {
  return (a, b) => {
    return (x, y, z) => {
        return f(evaluar(a, x, y, z), evaluar(b, x, y, z));
    }
  }
}

const add = op((a, b) => a + b);
const subtract = op((a, b) => a - b);
const multiply = op((a, b) => a * b);
const divide = op((a, b) => a / b);
const uniminus = op((a, b) => -a);
const negate = (a) => uniminus(a, 0);
const cnst = data((a) => a);
const variable = data((a) => a);
const pi = cnst(Math.PI);
const e = cnst(Math.E);

//let exp = negate(cnst(5));
//console.log(exp(0,0,0))

//let kika = multiply(e, multiply(5, 5));
//console.log(kika(0,0,0));

function f(x) {
  let exp = add(
    subtract(
      multiply(
        variable("x"),
        variable("x")),
      multiply(
        cnst(2),
        variable("x"))),
    cnst(1));
  console.log(exp(x, 0, 0));
}

for (let i = 0; i < 11; i++) {
  f(i);
}