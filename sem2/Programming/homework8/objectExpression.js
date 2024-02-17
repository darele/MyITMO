"use strict";

let Expression = {
  toString: function() {
    if (typeof(this.v) === "number") {
      return this.v.toString();
    } else {
      return this.v;
    }
  },
  evaluate: function(x, y, z) {
    if (typeof(this.v) === "number") {
      return this.v;
    } else {
      if (this.v === "x") {
        return x;
      } else if (this.v === "y") {
        return y;
      } else {
        return z;
      }
    }
  },
  prefix: function() {
    return this.toString();
  }
}

let Binary_Operator = {
  evaluate: function(x, y, z) {
    return this.f(this.operator1.evaluate(x, y, z), this.operator2.evaluate(x, y, z));
  },
  toString: function() {
    // :NOTE: return this.operator1.toString() + " " + this.operator2.toString() + " " + this.bin_operator
    let ans = "";
    ans += this.operator1.toString();
    ans += " ";
    ans += this.operator2.toString();
    ans += " ";
    ans += this.bin_operator;
    return ans;
  },
  prefix: function() {
    return "(" + this.bin_operator + " " + this.operator1.prefix() + " " + this.operator2.prefix() + ")";
  }
}

let Unary_Operator = {
  evaluate: function(x, y, z) {
    return this.f(this.operator1.evaluate(x, y, z));
  },
  toString: function() {
    // :NOTE: аналогично BinOperator
    let ans = "";
    ans += this.operator1.toString();
    ans += " ";
    ans += this.uni_operator;
    return ans;
  },
  prefix: function() {
    return "(" + this.uni_operator + " " + this.operator1.prefix() + ")";
  }
}

let n_ary_Operator = {
  evaluate: function(x, y, z) {
    let ans = this.operators[0].evaluate(x, y, z);
    for (let i = 1; i < this.operators.length; i++) {
      ans = this.f(ans, this.operators[i].evaluate(x, y, z));
    }
    return ans;
  },
  toString: function() {
    let ans = "";
    for (let i = 0; i < this.operators.length; i++) {
      ans += this.operators[i].toString();
      ans += " ";
    }
    ans += this.operation;
    return ans;
  }
}

let add = Object.create(Binary_Operator);
add.f = function(a, b) {return a + b;}
add.bin_operator = "+";

let subtract = Object.create(Binary_Operator);
subtract.f = function(a, b) {return a - b;}
subtract.bin_operator = "-";

let multiply = Object.create(Binary_Operator);
multiply.f = function(a, b) {return a * b;}
multiply.bin_operator = "*";

let divide = Object.create(Binary_Operator);
divide.f = function(a, b) {return a / b;}
divide.bin_operator = "/";

let negate = Object.create(Unary_Operator);
negate.f = function(a) {return -a;}
negate.uni_operator = "negate";

let sinh = Object.create(Unary_Operator);
sinh.f = function(a) {return Math.sinh(a);}
sinh.uni_operator = "sinh";

let cosh = Object.create(Unary_Operator);
cosh.f = function(a) {return Math.cosh(a);}
cosh.uni_operator = "cosh";

let min3 = Object.create(n_ary_Operator);
min3.f = function(a, b) {return Math.min(a, b);}
min3.operation = "min3";

let max5 = Object.create(n_ary_Operator);
max5.f = function(a, b) {return Math.max(a, b);}
max5.operation = "max5";

function superNaryConstructor(operation, ...args) {
  for (let i = 0; i < args.length; i++) {
    operation.operators.push(args[i]);
  }
}

function superUnaryConstructor(operation, a) {
  operation.operator1 = a;
}

function superBinaryConstructor(operation, a, b) {
  operation.operator1 = a;
  operation.operator2 = b;
}

function Const(arg) {
  let v = typeof(arg) !== "string" ? parseInt(arg) : parseInt(arg.toString());
  let data = Object.create(Expression);
  data.v = v;
  return data;
}

function Variable(arg) {
  let v = typeof(arg) === "string" ? arg : arg.toString();
  let data = Object.create(Expression);
  data.v = v;
  return data;
}

function Add(a, b) {
  let operation = Object.create(add);
  superBinaryConstructor(operation, a, b);
  return operation;
}

function Subtract(a, b) {
  let operation = Object.create(subtract);
  superBinaryConstructor(operation, a, b);
  return operation;
}

function Multiply(a, b) {
  let operation = Object.create(multiply);
  superBinaryConstructor(operation, a, b);
  return operation;
}

function Divide(a, b) {
  let operation = Object.create(divide);
  superBinaryConstructor(operation, a, b);
  return operation;
}

function Negate(a) {
  let operation = Object.create(negate);
  superUnaryConstructor(operation, a);
  return operation;
}

function Min3(a, b, c) {
  let operation = Object.create(min3);
  operation.operators = [];
  superNaryConstructor(operation, a, b, c);
  return operation;
}

function Max5(a, b, c, d, e) {
    let operation = Object.create(max5);
    operation.operators = [];
    superNaryConstructor(operation, a, b, c, d, e);
    return operation;
}

function Sinh(a) {
  let operation = Object.create(sinh);
  superUnaryConstructor(operation, a);
  return operation;
}

function Cosh(a) {
  let operation = Object.create(cosh);
  superUnaryConstructor(operation, a);
  return operation
}

let operaciones = new Map();
operaciones.set("+", Add);
operaciones.set("-", Subtract);
operaciones.set("*", Multiply);
operaciones.set("/", Divide);

function parse(arg) {
    let pila = [];
    let temp = "";
    let i = 0;
    let s = "";
    s = typeof(arg) === "string" ? arg : arg.toString();
    function operadorBinario(a) {
    return (a === "+" ||
            a === "-" ||
            a === "*" ||
            a === "/");
    }

    function isVariable(a) {
    return (a === "x" || a === "y" || a === "z");
    }
    function skipwhitespace() {
    while (i < s.length && /\s/.test(s[i])) {
        i++;
    }
    }
    while (i < s.length) {
    temp = "";
    skipwhitespace();
    for (; i < s.length && !/\s/.test(s[i]); i++) {
        temp += s[i];
    }
    skipwhitespace();
    if (operadorBinario(temp)) {
        let operador1 = null;
        let operador2 = null;
        operador2 = pila.pop();
        operador1 = pila.pop();
        // :NOTE: можно было создать map из операции в класс Add / Subtract / etc.
        pila.push(operaciones.get(temp)(operador1, operador2));
    } else if (temp === "negate") {
        let operator1 = null;
        operator1 = pila.pop();
        pila.push(new Negate(operator1));
    } else if (temp === "min3") {
        let operadores = [];
        for (let j = 0; j < 3; j++) {
            operadores.push(pila.pop());
        }
        operadores = operadores.reverse();
        pila.push(new Min3(...operadores));
    } else if (temp === "max5")  {
        let operadores = [];
        for (let j = 0; j < 5; j++) {
            operadores.push(pila.pop());
        }
        operadores = operadores.reverse();
        pila.push(new Max5(...operadores));
    } else {
        if (isVariable(temp)) {
        pila.push(new Variable(temp));
        } else {
        pila.push(new Const(parseInt(temp)));
        }
    }
    }
    return pila.pop();
}


// :NOTE: можно было добавить пробелы вокруг ( и ), а после этого побить строку на токены через .split(regex)

function parsePrefix(a) {
  //console.error(a);
  let pos = 0;
  let balance = 0;
  let stringa = typeof(a) === "string" ? a : a.toString();
  let s = [];
  
  if (typeof(a) !== "string") {
    stringa = a.toString();
  } else {
    stringa = a;
  }
  
  let temp = "";
  // :NOTE: нужен встроенный метод .replace для замены одной подстроки на другую
  for (let i = 0; i < stringa.length; i++) {
    // :NOTE: ===
    if (stringa[i] === '(' || stringa[i] === ')') {
      temp += ' ';
      temp += stringa[i];
      temp += ' ';
    } else {
      temp += stringa[i];
    }
  }
  const arr = temp.split(/\s/);
  
  //getting rid of nulls
  for (let i = 0; i < arr.length; i++) {
    // :NOTE: split(/\s+/), чтобы не делать проверку на пустую строку
    if (arr[i].length === 0) {
      continue;
    }
    s.push(arr[i]);
  }
  
  if (s.length === 0) {
  	throw new Error("An empty string was given");
  }
  
  //console.log(s);
  
  let ans = parseOperation();
  //console.log(ans.toString());
  if (pos < s.length) {
    throw new Error("Unexpected operator, This is not a prefix expression");
  }
  return ans;
  
  function isDigit(x) {
    return x >= '0' && x <= '9';
  }
  function isVar(x) {
    return x === 'x'
    		|| x === 'y'
    		|| x === 'z';
  }
  function parseOperation() {
    if (pos === s.length) {
      throw new Error("Not enough operands");
    }
    // :NOTE: не используются переменные
    let op1, op2;
    if (isVar(s[pos])) {
      return new Variable(s[pos++]);
    }
    // :NOTE: сделать мап или функцию для операций и конструкторов, чтобы проверять так:
    //        if (s[pos] in BIN_OPERATIONS) { pos++; return getBinOperationBySign(s[pos - 1])(...);
    //        + аналогично сделать для unary
    if (s[pos] === "+") {
      pos++;
      return new Add(parseOperation(), parseOperation());
    } else if (s[pos] === "-") {
      pos++;
      return new Subtract(parseOperation(), parseOperation());
    } else if (s[pos] === "*") {
      pos++;
      return new Multiply(parseOperation(), parseOperation());
    } else if (s[pos] === "/") {
      pos++;
      return new Divide(parseOperation(), parseOperation());
    } else if (s[pos] === "(") {
      pos++;
      if (isDigit(s[pos][0]) || isVar(s[pos])) {
        throw new Error("Incorrect parenthesis");
      }
      let balancecopy = balance;
      balance++;
      let op = parseOperation();
      // :NOTE: не закомментированный console.log
      console.log(op);
      while (pos < s.length && s[pos] === ")") {
        balance--;
        if (balance < 0) {
          throw new Error("Too many ) characters");
        }
        pos++;
      }
      if (balancecopy < balance) {
        throw new Error("Unexpected )");
      }
      return op;
    } else if (s[pos] === "negate") {
      pos++;
      return new Negate(parseOperation());
    } else if (s[pos] === "cosh") {
      pos++;
      return new Cosh(parseOperation());
    } else if (s[pos] === "sinh") {
     	pos++;
      return new Sinh(parseOperation());
    } else {
      let i = 0;
      if (s[pos][i] === '-') {
        i++;
      }
      for (; i < s[pos].length; i++) {
        if (!isDigit(s[pos][i])) {
          throw new Error("Unsupported element");
        }
      }
      return new Const(parseInt(s[pos++]));
    }
  }
}

//let expr = new Divide(new Max5(new Variable('z'), new Const(995), new Const(491), new Variable('y'), new Variable('y')), new Const(-407));
//console.log(expr.toString());