
module reloj_soc (
	audio_BCLK,
	audio_DACDAT,
	audio_DACLRCK,
	audio_config_SDAT,
	audio_config_SCLK,
	audio_pll_clk,
	buttons_export,
	clk_clk,
	hps_f2h_cold_reset_req_reset_n,
	hps_f2h_debug_reset_req_reset_n,
	hps_f2h_stm_hw_events_stm_hwevents,
	hps_f2h_warm_reset_req_reset_n,
	hps_h2f_reset_reset_n,
	hps_io_hps_io_sdio_inst_CMD,
	hps_io_hps_io_sdio_inst_PWREN,
	hps_io_hps_io_sdio_inst_D0,
	hps_io_hps_io_sdio_inst_D1,
	hps_io_hps_io_sdio_inst_CLK,
	hps_io_hps_io_sdio_inst_D2,
	hps_io_hps_io_sdio_inst_D3,
	hps_io_hps_io_uart0_inst_RX,
	hps_io_hps_io_uart0_inst_TX,
	hps_io_hps_io_uart0_inst_CTS,
	hps_io_hps_io_uart0_inst_RTS,
	leds_export,
	memory_mem_a,
	memory_mem_ba,
	memory_mem_ck,
	memory_mem_ck_n,
	memory_mem_cke,
	memory_mem_cs_n,
	memory_mem_ras_n,
	memory_mem_cas_n,
	memory_mem_we_n,
	memory_mem_reset_n,
	memory_mem_dq,
	memory_mem_dqs,
	memory_mem_dqs_n,
	memory_mem_odt,
	memory_mem_dm,
	memory_oct_rzqin,
	resetxd_reset_n);	

	input		audio_BCLK;
	output		audio_DACDAT;
	input		audio_DACLRCK;
	inout		audio_config_SDAT;
	output		audio_config_SCLK;
	output		audio_pll_clk;
	input	[7:0]	buttons_export;
	input		clk_clk;
	input		hps_f2h_cold_reset_req_reset_n;
	input		hps_f2h_debug_reset_req_reset_n;
	input	[27:0]	hps_f2h_stm_hw_events_stm_hwevents;
	input		hps_f2h_warm_reset_req_reset_n;
	output		hps_h2f_reset_reset_n;
	inout		hps_io_hps_io_sdio_inst_CMD;
	output		hps_io_hps_io_sdio_inst_PWREN;
	inout		hps_io_hps_io_sdio_inst_D0;
	inout		hps_io_hps_io_sdio_inst_D1;
	output		hps_io_hps_io_sdio_inst_CLK;
	inout		hps_io_hps_io_sdio_inst_D2;
	inout		hps_io_hps_io_sdio_inst_D3;
	input		hps_io_hps_io_uart0_inst_RX;
	output		hps_io_hps_io_uart0_inst_TX;
	input		hps_io_hps_io_uart0_inst_CTS;
	output		hps_io_hps_io_uart0_inst_RTS;
	output	[31:0]	leds_export;
	output	[12:0]	memory_mem_a;
	output	[2:0]	memory_mem_ba;
	output		memory_mem_ck;
	output		memory_mem_ck_n;
	output		memory_mem_cke;
	output		memory_mem_cs_n;
	output		memory_mem_ras_n;
	output		memory_mem_cas_n;
	output		memory_mem_we_n;
	output		memory_mem_reset_n;
	inout	[7:0]	memory_mem_dq;
	inout		memory_mem_dqs;
	inout		memory_mem_dqs_n;
	output		memory_mem_odt;
	output		memory_mem_dm;
	input		memory_oct_rzqin;
	input		resetxd_reset_n;
endmodule
