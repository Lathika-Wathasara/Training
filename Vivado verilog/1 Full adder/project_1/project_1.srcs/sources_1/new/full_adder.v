`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/18/2022 01:44:02 AM
// Design Name: 
// Module Name: full_adder
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


module full_adder(
    
    input a, input b,
    input cin,
    output sum,
    input cout
    
    );
    wire c1,c2,c3;
    // sum = a xor b xor c
    xor#(50)(sum,a,b,cin); //#(50) is the gate delay
    // cout = a.b + cin.(a+b)
    and#(50) and1(c1,a,b);
    or#(50) or1(c2,a,b);
    and#(50) and2(c3,cin,c2);
    or#(50) or2(cout,c1,c3);
    
endmodule
