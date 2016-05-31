module wb_midi #(parameter REG_WIDTH=8)(
	input               clk,
	input               rst,
	// Wishbone bus
	input      [31:0]   wb_adr_i,//
	input      [31:0]   wb_dat_i,//
	output reg [31:0]   wb_dat_o,//
	input      [ 3:0]   wb_sel_i,//
	input               wb_cyc_i,//
	input               wb_stb_i,//
	output              wb_ack_o,//
	input               wb_we_i,//
	// SPI 
	output reg   [REG_WIDTH-1:0]	status,
	output reg   [REG_WIDTH-1:0]	data1,
	output reg   [REG_WIDTH-1:0]	data2
	
);

reg  ack = 0;
//assign wb_ack_o = wb_stb_i & wb_cyc_i & ack;
assign wb_ack_o = wb_stb_i & wb_cyc_i;
//assign rst=1;

   always @(posedge clk)begin
     if (rst)begin
        status <= 8'b00; // All set to in at reset
        data1  <= 8'b00;
        data2  <= 8'b00;
	//wb_wr  <= 1'b1;
     end
     else if (~ack) begin  
//            ack <= 1;                          //Write cycle
            case(wb_adr_i[3:2])
             2'b00: status <= wb_dat_i[7:0];
             2'b01: data1  <= wb_dat_i[7:0];
	     2'b10: data2  <= wb_dat_i[7:0];
            endcase
        end
    // end        
   end   
endmodule
