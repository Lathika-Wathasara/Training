`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/19/2022 12:52:36 AM
// Design Name: 
// Module Name: D_FF
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


module D_FF(
    output q,
    input d,
    input r_set,
    
    input initials,
    input clk
    );
    reg q;
    always@(posedge clk or negedge r_set)
    if (~r_set)
    q <= initials;
    else
    q<= d;
endmodule
