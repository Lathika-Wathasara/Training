`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/10/2022 11:23:01 PM
// Design Name: 
// Module Name: register_block
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module register_block(
    data,
    op_1,
    op_2,
    sel_i,
    sel_o1,
    sel_o2,
    rd,
    wr,
    reset,
    en,
    clk
    );
    
    input [31:0] data;
    input [4:0] sel_i,sel_o1, sel_o2;
    input rd, wr, reset, en, clk;
    output [31:0] op_1, op_2 ;
    reg [31:0] op_1,op_2;
    
    reg[31:0] register_block;
    
    integer i;
    wire tem;
    assign tem = clk||reset;
    
    always @(posedge tem)
    begin
    if (reset == 1)// at reset
        begin
        for (i=0; i<32;i=i+1)
            begin
                register_block[i] = 32'h0;
            end
        op_1 = 32'hx;
        end
    else if(reset ==0)
        begin
            case({rd,wr})
            2'b00 : begin
                // do nothing
            end
            2'b10 : begin
                op_1 <= register_block[sel_o1];
                op_2 <= register_block[sel_o2];
            end
            2'b01 : begin
                register_block[sel_i] = data;
            end
            2'b11 : begin
                op_1 = register_block[sel_o1];
                op_2 = register_block[sel_o2];
                register_block[sel_i] = data;
            end
            default: begin
                    //if undefined (do nothing)
                end
            endcase
        end
     else; //do nothing

    end
    
endmodule
