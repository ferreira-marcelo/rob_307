set_property SRC_FILE_INFO {cfile:/home/fabian/Documents/ensta/deuxieme/rob307/rob_307/hardware_model/hw_arm_microblaze/hw_arm_microblaze.srcs/sources_1/bd/microblaze_arm/ip/microblaze_arm_dlmb_bram_if_cntlr_5/microblaze_arm_dlmb_bram_if_cntlr_5_ooc.xdc rfile:../../../../../hw_arm_microblaze.srcs/sources_1/bd/microblaze_arm/ip/microblaze_arm_dlmb_bram_if_cntlr_5/microblaze_arm_dlmb_bram_if_cntlr_5_ooc.xdc id:1 order:EARLY scoped_inst:U0} [current_design]
set_property SRC_FILE_INFO {cfile:/home/fabian/Documents/ensta/deuxieme/rob307/rob_307/hardware_model/hw_arm_microblaze/hw_arm_microblaze.runs/microblaze_arm_dlmb_bram_if_cntlr_5_synth_1/dont_touch.xdc rfile:../../../dont_touch.xdc id:2} [current_design]
set_property src_info {type:SCOPED_XDC file:1 line:55 export:INPUT save:INPUT read:FILTER_OUT_OF_CONTEXT} [current_design]
create_clock -period 10.000 -name LMB_Clk [get_ports LMB_Clk]
set_property src_info {type:XDC file:2 line:9 export:INPUT save:INPUT read:READ} [current_design]
set_property DONT_TOUCH true [get_cells U0]
