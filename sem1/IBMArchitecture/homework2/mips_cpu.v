`include "alu.v"
`include "control_unit.v"
`include "util.v"


module mips_cpu(clk, instruction_memory_a, instruction_memory_rd, data_memory_a, data_memory_rd, data_memory_we, data_memory_wd,
                register_a1, register_a2, register_a3, register_we3, register_wd3, register_rd1, register_rd2);
  input clk;
  output data_memory_we;
  output [31:0] instruction_memory_a, data_memory_a, data_memory_wd;
  inout [31:0] instruction_memory_rd, data_memory_rd;
  output register_we3; 
  output [4:0] register_a1, register_a2, register_a3;
  output [31:0] register_wd3;
  inout [31:0] register_rd1, register_rd2;

  // TODO: implementation
  output reg [31:0] pc;
  output wire pcsrc;
  output wire [31:0] pcplus4, pcprime, result;
  output memtoreg, memwrite, branch, alusrc, regdst, regwrite, zero;
  inout [2:0] alucontrol;
  wire [31:0] sign_lmm, srcb, gotos, aluresult, finalpc;
  
  initial begin
    pc = 0;
  end
  
  assign instruction_memory_a = pc;
  
   control_unit uniquecontrolunit(instruction_memory_rd [31:26], instruction_memory_rd [5:0], memtoreg, memwrite, branch, alusrc, regdst, regwrite, alucontrol);
  
  adder firstadder(pc, 32'b1, pcplus4);
  
  assign register_a1 = instruction_memory_rd [25:21];
  assign register_a2 = instruction_memory_rd [20:16];
  assign register_we3 = regwrite;
  
  mux2_5 multi1(register_a2, instruction_memory_rd [15:11], regdst, register_a3);
  sign_extend findsign(instruction_memory_rd [15:0], sign_lmm);	
  mux2_32 multi2(register_rd2, sign_lmm, alusrc, srcb);
  
  
  assign gotos = sign_lmm;
  
  
  alu uniquealu(register_rd1, srcb, alucontrol , aluresult, zero);
  
  assign data_memory_we = memwrite;
  assign pcsrc = zero & branch;
  assign data_memory_a = aluresult;
  assign data_memory_wd = register_rd2;
  
  mux2_32 multi3(aluresult, data_memory_rd, memtoreg, result);
  
  assign register_wd3 = result;                                   
                                   
  adder someadder(gotos, pcplus4, pcprime);                                  
  mux2_32 multi4(pcplus4, pcprime, pcsrc, finalpc);
                                      
  always @(posedge clk) begin
     pc = finalpc;
  end                                  
                                      
endmodule