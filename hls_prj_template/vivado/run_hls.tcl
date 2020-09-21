############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset hls_prj
set_top dut 

############################################################
# dut files
############################################################
add_files ../hls/dut.cc -cflags "-I../src/ -I../tb/"

############################################################
# testbench files
############################################################
add_files -tb ../tb/main.cc     -cflags "-I../src/ -I../tb/"

############################################################
# in/output data files
############################################################


open_solution "solution1"
set_part {xcu200-fsgd2104-2-e}
create_clock -period 3.3 -name default
config_sdx -optimization_level none -target none
csim_design
#csynth_design
#cosim_design
#export_design -format ip_catalog
exit
