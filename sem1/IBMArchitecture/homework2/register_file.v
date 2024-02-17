module register_file(clk, we3, a1, a2, a3, wd3, rd1, rd2);
  input clk, we3;
  input [4:0] a1, a2, a3;
  input [31:0] wd3;
  output [31:0] rd1, rd2;

  // TODO: implementation
  reg [31:0] newrds [0:31];
  reg newrd1, newrd2;
  
  integer i;
  initial begin
    for (i = 0; i < 32; i = i + 1) begin
      newrds[i] = 0;
    end
  end
 
  always@(*) begin
    if (a1 != 0) begin
      newrd1 = newrds[a1];
    end else begin
      newrd1 = 0;
    end
    if (a2 != 0) begin
      newrd2 = newrds[a2];
    end else begin
      newrd2 = 0;
    end
  end
  
  always@(posedge clk) begin
    if (we3 == 1) begin
      newrds[a3] <= wd3;
    end
  end

  assign rd1 = newrd1;
  assign rd2 = newrd2;
endmodule