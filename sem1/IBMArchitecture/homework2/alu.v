input signed [31:0] srca, srcb;
  input [2:0] alucontrol;
  output [31:0] aluresult;
  output zero;
  
  
  reg [31:0] aluout;
  assign aluresult = aluout;
   
  parameter ADD = 3'b010;
  parameter SUB = 3'b110;
  parameter OR = 3'b001;
  parameter AND = 3'b000;
  parameter SLT = 3'b111;
  
  
  always@(*)begin
    case(alucontrol)
      ADD:begin
        aluout = srca + srcb;
      end
      SUB:begin
        aluout = srca - srcb;
      end
      OR:begin
        aluout = srca | srcb;
      end
      AND:begin
        aluout = srca & srcb;
      end
      SLT:begin
        if (srca < srcb) begin
         aluout = 32'b1; 
          end
        else begin
          aluout = 32'b0;
        end
      end
    endcase
  end
  
  assign zero = aluout == 0;
  
endmodule