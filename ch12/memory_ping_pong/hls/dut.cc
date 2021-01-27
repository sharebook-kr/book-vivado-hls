#include "dut.h"

void mem_wr(
    //IN
    hls::stream<unit_t>     &chan_in, 
    //OUT
    uint8                   mem[8][8],
    hls::stream<uint1>      &chan_out)
{
    for (int row=0; row < 8; row++) {
#pragma HLS PIPELINE II=1 
        int addr = row;
        unit_t local = chan_in.read();

        for (int col=0; col < 8; col++) {
#pragma HLS UNROLL
            mem[addr][col] = local.pix[col];
        }

       if (row == 7) {
        chan_out.write(1);
        }
    }
}

void mem_rd(
    //IN
    hls::stream<uint1>          &chan_in,
    uint8                       mem[8][8],
    //OUT
    hls::stream<unit_t>         &chan_out)
{
    for (int row=0; row < 8; row++) {
#pragma HLS PIPELINE II=1

        int addr = row;

        // wait until ping/pong buffer is ready
        if (row == 0) {
            uint1 ctrl_dummy = chan_in.read();
        }

        unit_t local;
#pragma HLS ARRAY_PARTITION variable=local.pix complete dim=1

        for (int col=0; col < 8; col++) {
#pragma HLS UNROLL
            local.pix[col] = mem[addr][col];
        }

        chan_out.write(local);
    }
}

void dut(
    //IN
    hls::stream<unit_t>     &chan_in, 
    //OUT
    hls::stream<unit_t>     &chan_out)
{
#pragma HLS DATAFLOW
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS DATA_PACK variable=chan_out

    uint8   mem[8][8];
#pragma HLS ARRAY_RESHAPE variable=mem cyclic factor=8 dim=2

    hls::stream<uint1>  fifo_ctrl;

    mem_wr(
        //IN
        chan_in,
        mem, 
        //OUT
        fifo_ctrl
    );

    mem_rd(
        //IN
        fifo_ctrl,
        mem,
        //OUT
        chan_out
    );
}
