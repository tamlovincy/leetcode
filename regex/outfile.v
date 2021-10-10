
module conv(
    input wire clk,
	 input wire rst_n,
	 input wire conv_start,
	 output reg conv_finish,
	 input wire signed [7:0] conv_idata,
	 output reg signed [19:0] conv_odata
);

reg signed [3:0] conv_core [1:9];

reg [3:0] ii_count;
reg [3:0] ij_count;
reg [3:0] ci_count;
reg [3:0] cj_count;
reg [3:0] oi_count;
reg [3:0] oj_count;

reg signed [7:0] conv_iarraydata[1:6][1:6];
reg signed [19:0] conv_oarraydata[1:4][1:4];
reg conv_startcal;

wire signed [7:0] conv_irecon[1:9];
wire signed [19:0] conv_mul[1:9];
wire signed [19:0] conv_result;


assign conv_irecon[1] = conv_iarraydata[ci_count+0][cj_count+0];
assign conv_irecon[2] = conv_iarraydata[ci_count+0][cj_count+1];
assign conv_irecon[3] = conv_iarraydata[ci_count+0][cj_count+2];
assign conv_irecon[4] = conv_iarraydata[ci_count+1][cj_count+0];
assign conv_irecon[5] = conv_iarraydata[ci_count+1][cj_count+1];
assign conv_irecon[6] = conv_iarraydata[ci_count+1][cj_count+2];
assign conv_irecon[7] = conv_iarraydata[ci_count+2][cj_count+0];
assign conv_irecon[8] = conv_iarraydata[ci_count+2][cj_count+1];
assign conv_irecon[9] = conv_iarraydata[ci_count+2][cj_count+2];

assign conv_mul[1] = conv_core[9]*conv_irecon[1];
assign conv_mul[2] = conv_core[8]*conv_irecon[2];
assign conv_mul[3] = conv_core[7]*conv_irecon[3];
assign conv_mul[4] = conv_core[6]*conv_irecon[4];
assign conv_mul[5] = conv_core[5]*conv_irecon[5];
assign conv_mul[6] = conv_core[4]*conv_irecon[6];
assign conv_mul[7] = conv_core[3]*conv_irecon[7];
assign conv_mul[8] = conv_core[2]*conv_irecon[8];
assign conv_mul[9] = conv_core[1]*conv_irecon[9];

assign conv_result = conv_mul[1] + conv_mul[2] + conv_mul[3]+
                     conv_mul[4] + conv_mul[5] + conv_mul[6]+
							conv_mul[7] + conv_mul[8] + conv_mul[9];
							
//init core
always @ (posedge rst_n) begin
    conv_core[1] <= (4'h1)after VHDL_RD;
	 conv_core[2] <= (4'h2)after VHDL_RD;
	 conv_core[3] <= (4'hf)after VHDL_RD;
	 conv_core[4] <= (4'hd)after VHDL_RD;
	 conv_core[5] <= (4'h5)after VHDL_RD;
	 conv_core[6] <= (4'h3)after VHDL_RD;
	 conv_core[7] <= (4'he)after VHDL_RD;
	 conv_core[8] <= (4'h1)after VHDL_RD;
	 conv_core[9] <= (4'h2)after VHDL_RD;
	 end

	 always @ (posedge clk or negedge rst_n or posedge conv_finish) 
begin
    if (!rst_n || conv_finish)
	     begin
	     ii_count <= (1)after VHDL_RD;
		  ij_count <= (1)after VHDL_RD;
		  conv_startcal <=(0)after VHDL_RD;
	     end
	 else if (conv_start && (ii_count < 7))
	     begin
	     if (ij_count < 6) 
		      ij_count <= (ij_count +1)after VHDL_RD;
		  else
		      begin
				if (ii_count < 6)
				    begin
					 ii_count <= (ii_count +1 )after VHDL_RD;
					 ij_count <= (1)after VHDL_RD;
					 end
			   else
			       conv_startcal <= (1)after VHDL_RD;
			   end
	     conv_iarraydata[ii_count][ij_count] <= (conv_idata when faafa
		 										else dasf dsada
												dasda dasda)after VHDL_RD;
		  end
end 

always@(posedge clk or rst_n ) begin 
    if (!rst_n)
	     begin
		  ci_count <= (1)after VHDL_RD;
		  cj_count <= (1)after VHDL_RD;
		  conv_finish <= (0)after VHDL_RD;
		  end
	 else if (conv_startcal && ci_count <5)
	 begin
	     if (cj_count < 4)
		      cj_count <= (cj_count + 1)after VHDL_RD;
		  else 
		      begin
				if (ci_count <4)
				    begin 
					 ci_count <= (ci_count +1)after VHDL_RD;
					 cj_count <=(1)after VHDL_RD;
					 end
				else
				    conv_finish<=(1)after VHDL_RD;
				end
				conv_oarraydata[ci_count][cj_count] <= (conv_result
														when a
														else a 
														gdfg 
														gd)after VHDL_RD;
		end
end

always@(posedge clk or rst_n or posedge conv_start) begin
    if (rst_n || conv_start)
        begin
		  oi_count <= (1)after VHDL_RD;
		  oj_count <= (1)after VHDL_RD;
		  end
	 else if (conv_finish && (oi_count <5))
        begin
		  if (oj_count<4) 
		      oj_count<=(oj_count+1)after VHDL_RD;
		  else
		      begin
		          if (oi_count<4)
				    begin
				        oi_count<=(oi_count+1)after VHDL_RD;
						  oj_count<=(1)after VHDL_RD;
					 end
				end
		   conv_odata <= (conv_oarraydata[oi_count][oj_count])after VHDL_RD;
	      end
end
endmodule
		