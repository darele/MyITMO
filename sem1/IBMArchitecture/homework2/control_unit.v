module control_unit(opcode, funct, memtoreg, memwrite, branch, alusrc, regdst, regwrite, alucontrol);
  input [5:0] opcode, funct;
  output memtoreg, memwrite, branch, alusrc, regdst, regwrite;
  output [2:0] alucontrol;

  // TODO: implementation
  reg memtoreg, memwrite, branch, alusrc, regdst, regwrite;
  
  reg [2:0] alcontrol;
  reg [1:0] opalu;
  assign alucontrol = alcontrol;
  
  always@(*) begin
    if (opcode == 0)begin
      memtoreg = 0;
      memwrite = 0;
      branch = 0;
      alusrc = 0;
      regdst = 1;
      regwrite = 1;
      opalu = 2'b10;
    end else begin
      if (opcode == 6'b100011) begin
        memtoreg = 1;
        memwrite = 0;
        branch = 0;
        alusrc = 1;
        regdst = 0;
        regwrite = 1;
        opalu = 2'b0;
      end else begin
        if (opcode == 6'b101011) begin
          memwrite = 1;
          branch = 0;
          alusrc = 1;
          regwrite = 0;
          opalu = 2'b0;
        end else begin
          if (opcode == 6'b000100) begin
            memwrite = 0;
            branch = 1;
            alusrc = 0;
            regwrite = 0;
            opalu = 2'b01;
          end else begin
            if (opcode == 6'b001000)
            memtoreg = 0;
            alusrc = 1;
            branch = 0;
            regdst = 0;
            regwrite = 1;
            opalu = 2'b0;
            memwrite = 0;
          end
        end
      end
    end
  end
  
  always@(*)begin
    if (opalu == 2'b0) begin
      alcontrol = 3'b010;
    end else begin
      if (opalu == 2'b01) begin
        alcontrol = 3'b110;
      end else begin
        if (opalu == 2'b10) begin
          if (funct == 6'b100000) begin
            alcontrol = 3'b010;
          end else if (funct == 6'b100010) begin
            alcontrol = 3'b110;
          end else if (funct == 6'b100100) begin
            alcontrol = 3'b0;
          end else if (funct == 6'b100101) begin
            alcontrol = 3'b001;
          end else begin
            alcontrol = 3'b111;
          end
        end
      end
    end
  end
endmodule