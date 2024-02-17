module data_memory(a, we, clk, wd, rd);
  input we, clk;
  input [31:0] a;
  input [31:0] wd;
  output [31:0] rd;

  // TODO: implementation
  reg [31:0] againram [0:63];
  integer i;
  always@(posedge clk) begin
    if (we) againram[a/4] = wd;
  end
  
  initial begin
    for (i = 0; i < 64; i = i + 1) begin
      againram[i] <= 0;
    end
  end

  assign rd = againram[a/4];

endmodule

module instruction_memory(a, rd);
  input [31:0] a;
  output [31:0] rd;

  // Note that at this point our programs cannot be larger then 64 subsequent commands.
  // Increase constant below if larger programs are going to be executed.
  reg [31:0] ram[0:63];

  initial
    begin
      $readmemb("instructions.dat", ram);
    end

  // TODO: implementation
  assign rd = ram[a / 4];
endmodule
