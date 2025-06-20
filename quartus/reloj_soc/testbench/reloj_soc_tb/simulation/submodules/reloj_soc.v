// reloj_soc.v

// Generated using ACDS version 18.0 614

`timescale 1 ps / 1 ps
module reloj_soc (
		input  wire [7:0]  buttons_export, // buttons.export
		input  wire        clk_clk,        //     clk.clk
		output wire [31:0] leds_export,    //    leds.export
		input  wire        reset_reset_n   //   reset.reset_n
	);

	wire  [31:0] nios_ii_data_master_readdata;                          // mm_interconnect_0:NIOS_II_data_master_readdata -> NIOS_II:d_readdata
	wire         nios_ii_data_master_waitrequest;                       // mm_interconnect_0:NIOS_II_data_master_waitrequest -> NIOS_II:d_waitrequest
	wire         nios_ii_data_master_debugaccess;                       // NIOS_II:debug_mem_slave_debugaccess_to_roms -> mm_interconnect_0:NIOS_II_data_master_debugaccess
	wire  [14:0] nios_ii_data_master_address;                           // NIOS_II:d_address -> mm_interconnect_0:NIOS_II_data_master_address
	wire   [3:0] nios_ii_data_master_byteenable;                        // NIOS_II:d_byteenable -> mm_interconnect_0:NIOS_II_data_master_byteenable
	wire         nios_ii_data_master_read;                              // NIOS_II:d_read -> mm_interconnect_0:NIOS_II_data_master_read
	wire         nios_ii_data_master_readdatavalid;                     // mm_interconnect_0:NIOS_II_data_master_readdatavalid -> NIOS_II:d_readdatavalid
	wire         nios_ii_data_master_write;                             // NIOS_II:d_write -> mm_interconnect_0:NIOS_II_data_master_write
	wire  [31:0] nios_ii_data_master_writedata;                         // NIOS_II:d_writedata -> mm_interconnect_0:NIOS_II_data_master_writedata
	wire  [31:0] nios_ii_instruction_master_readdata;                   // mm_interconnect_0:NIOS_II_instruction_master_readdata -> NIOS_II:i_readdata
	wire         nios_ii_instruction_master_waitrequest;                // mm_interconnect_0:NIOS_II_instruction_master_waitrequest -> NIOS_II:i_waitrequest
	wire  [13:0] nios_ii_instruction_master_address;                    // NIOS_II:i_address -> mm_interconnect_0:NIOS_II_instruction_master_address
	wire         nios_ii_instruction_master_read;                       // NIOS_II:i_read -> mm_interconnect_0:NIOS_II_instruction_master_read
	wire         nios_ii_instruction_master_readdatavalid;              // mm_interconnect_0:NIOS_II_instruction_master_readdatavalid -> NIOS_II:i_readdatavalid
	wire         mm_interconnect_0_uart_avalon_jtag_slave_chipselect;   // mm_interconnect_0:UART_avalon_jtag_slave_chipselect -> UART:av_chipselect
	wire  [31:0] mm_interconnect_0_uart_avalon_jtag_slave_readdata;     // UART:av_readdata -> mm_interconnect_0:UART_avalon_jtag_slave_readdata
	wire         mm_interconnect_0_uart_avalon_jtag_slave_waitrequest;  // UART:av_waitrequest -> mm_interconnect_0:UART_avalon_jtag_slave_waitrequest
	wire   [0:0] mm_interconnect_0_uart_avalon_jtag_slave_address;      // mm_interconnect_0:UART_avalon_jtag_slave_address -> UART:av_address
	wire         mm_interconnect_0_uart_avalon_jtag_slave_read;         // mm_interconnect_0:UART_avalon_jtag_slave_read -> UART:av_read_n
	wire         mm_interconnect_0_uart_avalon_jtag_slave_write;        // mm_interconnect_0:UART_avalon_jtag_slave_write -> UART:av_write_n
	wire  [31:0] mm_interconnect_0_uart_avalon_jtag_slave_writedata;    // mm_interconnect_0:UART_avalon_jtag_slave_writedata -> UART:av_writedata
	wire  [31:0] mm_interconnect_0_nios_ii_debug_mem_slave_readdata;    // NIOS_II:debug_mem_slave_readdata -> mm_interconnect_0:NIOS_II_debug_mem_slave_readdata
	wire         mm_interconnect_0_nios_ii_debug_mem_slave_waitrequest; // NIOS_II:debug_mem_slave_waitrequest -> mm_interconnect_0:NIOS_II_debug_mem_slave_waitrequest
	wire         mm_interconnect_0_nios_ii_debug_mem_slave_debugaccess; // mm_interconnect_0:NIOS_II_debug_mem_slave_debugaccess -> NIOS_II:debug_mem_slave_debugaccess
	wire   [8:0] mm_interconnect_0_nios_ii_debug_mem_slave_address;     // mm_interconnect_0:NIOS_II_debug_mem_slave_address -> NIOS_II:debug_mem_slave_address
	wire         mm_interconnect_0_nios_ii_debug_mem_slave_read;        // mm_interconnect_0:NIOS_II_debug_mem_slave_read -> NIOS_II:debug_mem_slave_read
	wire   [3:0] mm_interconnect_0_nios_ii_debug_mem_slave_byteenable;  // mm_interconnect_0:NIOS_II_debug_mem_slave_byteenable -> NIOS_II:debug_mem_slave_byteenable
	wire         mm_interconnect_0_nios_ii_debug_mem_slave_write;       // mm_interconnect_0:NIOS_II_debug_mem_slave_write -> NIOS_II:debug_mem_slave_write
	wire  [31:0] mm_interconnect_0_nios_ii_debug_mem_slave_writedata;   // mm_interconnect_0:NIOS_II_debug_mem_slave_writedata -> NIOS_II:debug_mem_slave_writedata
	wire         mm_interconnect_0_ram_s1_chipselect;                   // mm_interconnect_0:RAM_s1_chipselect -> RAM:chipselect
	wire  [31:0] mm_interconnect_0_ram_s1_readdata;                     // RAM:readdata -> mm_interconnect_0:RAM_s1_readdata
	wire  [10:0] mm_interconnect_0_ram_s1_address;                      // mm_interconnect_0:RAM_s1_address -> RAM:address
	wire   [3:0] mm_interconnect_0_ram_s1_byteenable;                   // mm_interconnect_0:RAM_s1_byteenable -> RAM:byteenable
	wire         mm_interconnect_0_ram_s1_write;                        // mm_interconnect_0:RAM_s1_write -> RAM:write
	wire  [31:0] mm_interconnect_0_ram_s1_writedata;                    // mm_interconnect_0:RAM_s1_writedata -> RAM:writedata
	wire         mm_interconnect_0_ram_s1_clken;                        // mm_interconnect_0:RAM_s1_clken -> RAM:clken
	wire         mm_interconnect_0_reg_leds_s1_chipselect;              // mm_interconnect_0:REG_LEDS_s1_chipselect -> REG_LEDS:chipselect
	wire  [31:0] mm_interconnect_0_reg_leds_s1_readdata;                // REG_LEDS:readdata -> mm_interconnect_0:REG_LEDS_s1_readdata
	wire   [1:0] mm_interconnect_0_reg_leds_s1_address;                 // mm_interconnect_0:REG_LEDS_s1_address -> REG_LEDS:address
	wire         mm_interconnect_0_reg_leds_s1_write;                   // mm_interconnect_0:REG_LEDS_s1_write -> REG_LEDS:write_n
	wire  [31:0] mm_interconnect_0_reg_leds_s1_writedata;               // mm_interconnect_0:REG_LEDS_s1_writedata -> REG_LEDS:writedata
	wire  [31:0] mm_interconnect_0_reg_buttons_s1_readdata;             // REG_BUTTONS:readdata -> mm_interconnect_0:REG_BUTTONS_s1_readdata
	wire   [1:0] mm_interconnect_0_reg_buttons_s1_address;              // mm_interconnect_0:REG_BUTTONS_s1_address -> REG_BUTTONS:address
	wire         mm_interconnect_0_timer_s1_chipselect;                 // mm_interconnect_0:TIMER_s1_chipselect -> TIMER:chipselect
	wire  [15:0] mm_interconnect_0_timer_s1_readdata;                   // TIMER:readdata -> mm_interconnect_0:TIMER_s1_readdata
	wire   [2:0] mm_interconnect_0_timer_s1_address;                    // mm_interconnect_0:TIMER_s1_address -> TIMER:address
	wire         mm_interconnect_0_timer_s1_write;                      // mm_interconnect_0:TIMER_s1_write -> TIMER:write_n
	wire  [15:0] mm_interconnect_0_timer_s1_writedata;                  // mm_interconnect_0:TIMER_s1_writedata -> TIMER:writedata
	wire         irq_mapper_receiver0_irq;                              // TIMER:irq -> irq_mapper:receiver0_irq
	wire         irq_mapper_receiver1_irq;                              // UART:av_irq -> irq_mapper:receiver1_irq
	wire  [31:0] nios_ii_irq_irq;                                       // irq_mapper:sender_irq -> NIOS_II:irq
	wire         rst_controller_reset_out_reset;                        // rst_controller:reset_out -> [NIOS_II:reset_n, RAM:reset, REG_BUTTONS:reset_n, REG_LEDS:reset_n, TIMER:reset_n, UART:rst_n, irq_mapper:reset, mm_interconnect_0:NIOS_II_reset_reset_bridge_in_reset_reset, rst_translator:in_reset]
	wire         rst_controller_reset_out_reset_req;                    // rst_controller:reset_req -> [NIOS_II:reset_req, RAM:reset_req, rst_translator:reset_req_in]

	reloj_soc_NIOS_II nios_ii (
		.clk                                 (clk_clk),                                               //                       clk.clk
		.reset_n                             (~rst_controller_reset_out_reset),                       //                     reset.reset_n
		.reset_req                           (rst_controller_reset_out_reset_req),                    //                          .reset_req
		.d_address                           (nios_ii_data_master_address),                           //               data_master.address
		.d_byteenable                        (nios_ii_data_master_byteenable),                        //                          .byteenable
		.d_read                              (nios_ii_data_master_read),                              //                          .read
		.d_readdata                          (nios_ii_data_master_readdata),                          //                          .readdata
		.d_waitrequest                       (nios_ii_data_master_waitrequest),                       //                          .waitrequest
		.d_write                             (nios_ii_data_master_write),                             //                          .write
		.d_writedata                         (nios_ii_data_master_writedata),                         //                          .writedata
		.d_readdatavalid                     (nios_ii_data_master_readdatavalid),                     //                          .readdatavalid
		.debug_mem_slave_debugaccess_to_roms (nios_ii_data_master_debugaccess),                       //                          .debugaccess
		.i_address                           (nios_ii_instruction_master_address),                    //        instruction_master.address
		.i_read                              (nios_ii_instruction_master_read),                       //                          .read
		.i_readdata                          (nios_ii_instruction_master_readdata),                   //                          .readdata
		.i_waitrequest                       (nios_ii_instruction_master_waitrequest),                //                          .waitrequest
		.i_readdatavalid                     (nios_ii_instruction_master_readdatavalid),              //                          .readdatavalid
		.irq                                 (nios_ii_irq_irq),                                       //                       irq.irq
		.debug_reset_request                 (),                                                      //       debug_reset_request.reset
		.debug_mem_slave_address             (mm_interconnect_0_nios_ii_debug_mem_slave_address),     //           debug_mem_slave.address
		.debug_mem_slave_byteenable          (mm_interconnect_0_nios_ii_debug_mem_slave_byteenable),  //                          .byteenable
		.debug_mem_slave_debugaccess         (mm_interconnect_0_nios_ii_debug_mem_slave_debugaccess), //                          .debugaccess
		.debug_mem_slave_read                (mm_interconnect_0_nios_ii_debug_mem_slave_read),        //                          .read
		.debug_mem_slave_readdata            (mm_interconnect_0_nios_ii_debug_mem_slave_readdata),    //                          .readdata
		.debug_mem_slave_waitrequest         (mm_interconnect_0_nios_ii_debug_mem_slave_waitrequest), //                          .waitrequest
		.debug_mem_slave_write               (mm_interconnect_0_nios_ii_debug_mem_slave_write),       //                          .write
		.debug_mem_slave_writedata           (mm_interconnect_0_nios_ii_debug_mem_slave_writedata),   //                          .writedata
		.dummy_ci_port                       ()                                                       // custom_instruction_master.readra
	);

	reloj_soc_RAM ram (
		.clk        (clk_clk),                             //   clk1.clk
		.address    (mm_interconnect_0_ram_s1_address),    //     s1.address
		.clken      (mm_interconnect_0_ram_s1_clken),      //       .clken
		.chipselect (mm_interconnect_0_ram_s1_chipselect), //       .chipselect
		.write      (mm_interconnect_0_ram_s1_write),      //       .write
		.readdata   (mm_interconnect_0_ram_s1_readdata),   //       .readdata
		.writedata  (mm_interconnect_0_ram_s1_writedata),  //       .writedata
		.byteenable (mm_interconnect_0_ram_s1_byteenable), //       .byteenable
		.reset      (rst_controller_reset_out_reset),      // reset1.reset
		.reset_req  (rst_controller_reset_out_reset_req),  //       .reset_req
		.freeze     (1'b0)                                 // (terminated)
	);

	reloj_soc_REG_BUTTONS reg_buttons (
		.clk      (clk_clk),                                   //                 clk.clk
		.reset_n  (~rst_controller_reset_out_reset),           //               reset.reset_n
		.address  (mm_interconnect_0_reg_buttons_s1_address),  //                  s1.address
		.readdata (mm_interconnect_0_reg_buttons_s1_readdata), //                    .readdata
		.in_port  (buttons_export)                             // external_connection.export
	);

	reloj_soc_REG_LEDS reg_leds (
		.clk        (clk_clk),                                  //                 clk.clk
		.reset_n    (~rst_controller_reset_out_reset),          //               reset.reset_n
		.address    (mm_interconnect_0_reg_leds_s1_address),    //                  s1.address
		.write_n    (~mm_interconnect_0_reg_leds_s1_write),     //                    .write_n
		.writedata  (mm_interconnect_0_reg_leds_s1_writedata),  //                    .writedata
		.chipselect (mm_interconnect_0_reg_leds_s1_chipselect), //                    .chipselect
		.readdata   (mm_interconnect_0_reg_leds_s1_readdata),   //                    .readdata
		.out_port   (leds_export)                               // external_connection.export
	);

	reloj_soc_TIMER timer (
		.clk        (clk_clk),                               //   clk.clk
		.reset_n    (~rst_controller_reset_out_reset),       // reset.reset_n
		.address    (mm_interconnect_0_timer_s1_address),    //    s1.address
		.writedata  (mm_interconnect_0_timer_s1_writedata),  //      .writedata
		.readdata   (mm_interconnect_0_timer_s1_readdata),   //      .readdata
		.chipselect (mm_interconnect_0_timer_s1_chipselect), //      .chipselect
		.write_n    (~mm_interconnect_0_timer_s1_write),     //      .write_n
		.irq        (irq_mapper_receiver0_irq)               //   irq.irq
	);

	reloj_soc_UART uart (
		.clk            (clk_clk),                                              //               clk.clk
		.rst_n          (~rst_controller_reset_out_reset),                      //             reset.reset_n
		.av_chipselect  (mm_interconnect_0_uart_avalon_jtag_slave_chipselect),  // avalon_jtag_slave.chipselect
		.av_address     (mm_interconnect_0_uart_avalon_jtag_slave_address),     //                  .address
		.av_read_n      (~mm_interconnect_0_uart_avalon_jtag_slave_read),       //                  .read_n
		.av_readdata    (mm_interconnect_0_uart_avalon_jtag_slave_readdata),    //                  .readdata
		.av_write_n     (~mm_interconnect_0_uart_avalon_jtag_slave_write),      //                  .write_n
		.av_writedata   (mm_interconnect_0_uart_avalon_jtag_slave_writedata),   //                  .writedata
		.av_waitrequest (mm_interconnect_0_uart_avalon_jtag_slave_waitrequest), //                  .waitrequest
		.av_irq         (irq_mapper_receiver1_irq)                              //               irq.irq
	);

	reloj_soc_mm_interconnect_0 mm_interconnect_0 (
		.CLK_clk_clk                               (clk_clk),                                               //                             CLK_clk.clk
		.NIOS_II_reset_reset_bridge_in_reset_reset (rst_controller_reset_out_reset),                        // NIOS_II_reset_reset_bridge_in_reset.reset
		.NIOS_II_data_master_address               (nios_ii_data_master_address),                           //                 NIOS_II_data_master.address
		.NIOS_II_data_master_waitrequest           (nios_ii_data_master_waitrequest),                       //                                    .waitrequest
		.NIOS_II_data_master_byteenable            (nios_ii_data_master_byteenable),                        //                                    .byteenable
		.NIOS_II_data_master_read                  (nios_ii_data_master_read),                              //                                    .read
		.NIOS_II_data_master_readdata              (nios_ii_data_master_readdata),                          //                                    .readdata
		.NIOS_II_data_master_readdatavalid         (nios_ii_data_master_readdatavalid),                     //                                    .readdatavalid
		.NIOS_II_data_master_write                 (nios_ii_data_master_write),                             //                                    .write
		.NIOS_II_data_master_writedata             (nios_ii_data_master_writedata),                         //                                    .writedata
		.NIOS_II_data_master_debugaccess           (nios_ii_data_master_debugaccess),                       //                                    .debugaccess
		.NIOS_II_instruction_master_address        (nios_ii_instruction_master_address),                    //          NIOS_II_instruction_master.address
		.NIOS_II_instruction_master_waitrequest    (nios_ii_instruction_master_waitrequest),                //                                    .waitrequest
		.NIOS_II_instruction_master_read           (nios_ii_instruction_master_read),                       //                                    .read
		.NIOS_II_instruction_master_readdata       (nios_ii_instruction_master_readdata),                   //                                    .readdata
		.NIOS_II_instruction_master_readdatavalid  (nios_ii_instruction_master_readdatavalid),              //                                    .readdatavalid
		.NIOS_II_debug_mem_slave_address           (mm_interconnect_0_nios_ii_debug_mem_slave_address),     //             NIOS_II_debug_mem_slave.address
		.NIOS_II_debug_mem_slave_write             (mm_interconnect_0_nios_ii_debug_mem_slave_write),       //                                    .write
		.NIOS_II_debug_mem_slave_read              (mm_interconnect_0_nios_ii_debug_mem_slave_read),        //                                    .read
		.NIOS_II_debug_mem_slave_readdata          (mm_interconnect_0_nios_ii_debug_mem_slave_readdata),    //                                    .readdata
		.NIOS_II_debug_mem_slave_writedata         (mm_interconnect_0_nios_ii_debug_mem_slave_writedata),   //                                    .writedata
		.NIOS_II_debug_mem_slave_byteenable        (mm_interconnect_0_nios_ii_debug_mem_slave_byteenable),  //                                    .byteenable
		.NIOS_II_debug_mem_slave_waitrequest       (mm_interconnect_0_nios_ii_debug_mem_slave_waitrequest), //                                    .waitrequest
		.NIOS_II_debug_mem_slave_debugaccess       (mm_interconnect_0_nios_ii_debug_mem_slave_debugaccess), //                                    .debugaccess
		.RAM_s1_address                            (mm_interconnect_0_ram_s1_address),                      //                              RAM_s1.address
		.RAM_s1_write                              (mm_interconnect_0_ram_s1_write),                        //                                    .write
		.RAM_s1_readdata                           (mm_interconnect_0_ram_s1_readdata),                     //                                    .readdata
		.RAM_s1_writedata                          (mm_interconnect_0_ram_s1_writedata),                    //                                    .writedata
		.RAM_s1_byteenable                         (mm_interconnect_0_ram_s1_byteenable),                   //                                    .byteenable
		.RAM_s1_chipselect                         (mm_interconnect_0_ram_s1_chipselect),                   //                                    .chipselect
		.RAM_s1_clken                              (mm_interconnect_0_ram_s1_clken),                        //                                    .clken
		.REG_BUTTONS_s1_address                    (mm_interconnect_0_reg_buttons_s1_address),              //                      REG_BUTTONS_s1.address
		.REG_BUTTONS_s1_readdata                   (mm_interconnect_0_reg_buttons_s1_readdata),             //                                    .readdata
		.REG_LEDS_s1_address                       (mm_interconnect_0_reg_leds_s1_address),                 //                         REG_LEDS_s1.address
		.REG_LEDS_s1_write                         (mm_interconnect_0_reg_leds_s1_write),                   //                                    .write
		.REG_LEDS_s1_readdata                      (mm_interconnect_0_reg_leds_s1_readdata),                //                                    .readdata
		.REG_LEDS_s1_writedata                     (mm_interconnect_0_reg_leds_s1_writedata),               //                                    .writedata
		.REG_LEDS_s1_chipselect                    (mm_interconnect_0_reg_leds_s1_chipselect),              //                                    .chipselect
		.TIMER_s1_address                          (mm_interconnect_0_timer_s1_address),                    //                            TIMER_s1.address
		.TIMER_s1_write                            (mm_interconnect_0_timer_s1_write),                      //                                    .write
		.TIMER_s1_readdata                         (mm_interconnect_0_timer_s1_readdata),                   //                                    .readdata
		.TIMER_s1_writedata                        (mm_interconnect_0_timer_s1_writedata),                  //                                    .writedata
		.TIMER_s1_chipselect                       (mm_interconnect_0_timer_s1_chipselect),                 //                                    .chipselect
		.UART_avalon_jtag_slave_address            (mm_interconnect_0_uart_avalon_jtag_slave_address),      //              UART_avalon_jtag_slave.address
		.UART_avalon_jtag_slave_write              (mm_interconnect_0_uart_avalon_jtag_slave_write),        //                                    .write
		.UART_avalon_jtag_slave_read               (mm_interconnect_0_uart_avalon_jtag_slave_read),         //                                    .read
		.UART_avalon_jtag_slave_readdata           (mm_interconnect_0_uart_avalon_jtag_slave_readdata),     //                                    .readdata
		.UART_avalon_jtag_slave_writedata          (mm_interconnect_0_uart_avalon_jtag_slave_writedata),    //                                    .writedata
		.UART_avalon_jtag_slave_waitrequest        (mm_interconnect_0_uart_avalon_jtag_slave_waitrequest),  //                                    .waitrequest
		.UART_avalon_jtag_slave_chipselect         (mm_interconnect_0_uart_avalon_jtag_slave_chipselect)    //                                    .chipselect
	);

	reloj_soc_irq_mapper irq_mapper (
		.clk           (clk_clk),                        //       clk.clk
		.reset         (rst_controller_reset_out_reset), // clk_reset.reset
		.receiver0_irq (irq_mapper_receiver0_irq),       // receiver0.irq
		.receiver1_irq (irq_mapper_receiver1_irq),       // receiver1.irq
		.sender_irq    (nios_ii_irq_irq)                 //    sender.irq
	);

	altera_reset_controller #(
		.NUM_RESET_INPUTS          (1),
		.OUTPUT_RESET_SYNC_EDGES   ("deassert"),
		.SYNC_DEPTH                (2),
		.RESET_REQUEST_PRESENT     (1),
		.RESET_REQ_WAIT_TIME       (1),
		.MIN_RST_ASSERTION_TIME    (3),
		.RESET_REQ_EARLY_DSRT_TIME (1),
		.USE_RESET_REQUEST_IN0     (0),
		.USE_RESET_REQUEST_IN1     (0),
		.USE_RESET_REQUEST_IN2     (0),
		.USE_RESET_REQUEST_IN3     (0),
		.USE_RESET_REQUEST_IN4     (0),
		.USE_RESET_REQUEST_IN5     (0),
		.USE_RESET_REQUEST_IN6     (0),
		.USE_RESET_REQUEST_IN7     (0),
		.USE_RESET_REQUEST_IN8     (0),
		.USE_RESET_REQUEST_IN9     (0),
		.USE_RESET_REQUEST_IN10    (0),
		.USE_RESET_REQUEST_IN11    (0),
		.USE_RESET_REQUEST_IN12    (0),
		.USE_RESET_REQUEST_IN13    (0),
		.USE_RESET_REQUEST_IN14    (0),
		.USE_RESET_REQUEST_IN15    (0),
		.ADAPT_RESET_REQUEST       (0)
	) rst_controller (
		.reset_in0      (~reset_reset_n),                     // reset_in0.reset
		.clk            (clk_clk),                            //       clk.clk
		.reset_out      (rst_controller_reset_out_reset),     // reset_out.reset
		.reset_req      (rst_controller_reset_out_reset_req), //          .reset_req
		.reset_req_in0  (1'b0),                               // (terminated)
		.reset_in1      (1'b0),                               // (terminated)
		.reset_req_in1  (1'b0),                               // (terminated)
		.reset_in2      (1'b0),                               // (terminated)
		.reset_req_in2  (1'b0),                               // (terminated)
		.reset_in3      (1'b0),                               // (terminated)
		.reset_req_in3  (1'b0),                               // (terminated)
		.reset_in4      (1'b0),                               // (terminated)
		.reset_req_in4  (1'b0),                               // (terminated)
		.reset_in5      (1'b0),                               // (terminated)
		.reset_req_in5  (1'b0),                               // (terminated)
		.reset_in6      (1'b0),                               // (terminated)
		.reset_req_in6  (1'b0),                               // (terminated)
		.reset_in7      (1'b0),                               // (terminated)
		.reset_req_in7  (1'b0),                               // (terminated)
		.reset_in8      (1'b0),                               // (terminated)
		.reset_req_in8  (1'b0),                               // (terminated)
		.reset_in9      (1'b0),                               // (terminated)
		.reset_req_in9  (1'b0),                               // (terminated)
		.reset_in10     (1'b0),                               // (terminated)
		.reset_req_in10 (1'b0),                               // (terminated)
		.reset_in11     (1'b0),                               // (terminated)
		.reset_req_in11 (1'b0),                               // (terminated)
		.reset_in12     (1'b0),                               // (terminated)
		.reset_req_in12 (1'b0),                               // (terminated)
		.reset_in13     (1'b0),                               // (terminated)
		.reset_req_in13 (1'b0),                               // (terminated)
		.reset_in14     (1'b0),                               // (terminated)
		.reset_req_in14 (1'b0),                               // (terminated)
		.reset_in15     (1'b0),                               // (terminated)
		.reset_req_in15 (1'b0)                                // (terminated)
	);

endmodule
