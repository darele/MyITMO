// Code your design here






// Code your design here
module not_switch(in, out);
  input in;
  output out;
  
  supply1 power;
  supply0 ground;
  
  pmos p1(out, power, in);
  nmos n1(out, ground, in);
endmodule
  
module and_s(in, in2, out);
  input in, in2;
  output out;
  wire w, w2;
  
  supply1 power;
  supply0 ground;
  
  nmos n1(w2, ground, in2);
  nmos n2(w, w2, in);
  pmos p1(w, power, in);
  pmos p2(w, power, in2);
  
  not_switch my_not(w, out);
endmodule
  
module or_s(in, in2, out);
   input in, in2;
  output out;
  wire w, w2;
  
  supply0 ground;
  supply1 power;
  
  pmos p1(w2, power, in);
  pmos p2(w, w2, in2);
  nmos n1(w, ground, in);
  nmos n2(w, ground, in2);
  
  not_switch my_not(w, out);
endmodule

module notequal(in, in2, out);
  input in, in2;
  output out;
  wire w, w2, w3, w4, w5;
  
  not_switch mynot(in, w2);
  not_switch myothernot(in2, w3);
  and_s and1(in, in2, w);
  and_s and2(w2, w3, w4);
  or_s or1(w, w4, w5);
  not_switch myotherothernot(w5, out);
endmodule
    
module ternary_consensus(a0, a1, b0, b1, out0, out1);
  input a0, a1, b0, b1;
  output out0, out1;
  wire w, w2, w3, w4;
  
  and_s my_and(a0, b0, out0);
  notequal bit1(a0, b0, w);
  notequal bit2(a1, b1, w2);
  or_s my_or(w, w2, w3);
  and_s my_other_and(a1, b1, w4);
  or_s my_other_or(w3, w4, out1);
endmodule

module ternary_min(a0, a1, b0, b1, out0, out1);
  input a0, a1, b0, b1;
  output out0, out1;
  wire w, w2, w3, w4, w5, w6, w7, w8, w9, w10;
  wire one = 1;
  
  //bit1 and bit1 equals bit1
  and_s my_bit1(a0, b0, out0);
  
  //one of the input ternary bit is 00
  //then second bit is 0
  notequal eq1(a0, one, w);
  notequal eq2(a1, one, w2);
  notequal eq3(b0, one, w3);
  notequal eq4(b1, one, w4);
  and_s and1(w, w2, w6);
  and_s and2(w3, w4, w7);
  or_s o1(w6, w7, w8);
  not_switch not1(w8, w9);
  
  //and also, any of the bit1 of the
  //input elements is 0
  //then second bit is 1
  or_s o2(w, w3, w10);
  and_s and3(w9, w10, out1);
endmodule
    
module ternary_max(a0, a1, b0, b1, out0, out1);
  input a0, a1, b0, b1;
  output out0, out1;

endmodule

module ternary_any(a0, a1, b0, b1, out0, out1);
  input a0, a1, b0, b1;
  output out0, out1;

endmodule
  
  
  
  
  
  
  
  
  
  
  
  