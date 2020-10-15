#include "dut.h"

void dut(
    // IN
    hls::stream<uint64>     &chan_in,
    // OUT
    hls::stream<uint64>     &chan_out)
{
#pragma HLS PIPELINE
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS DATA_PACK variable=chan_out

    uint64 data_in = chan_in.read();
    uint64 data_out = 0;

    for (int i =0; i < 8; i++) {
#pragma HLS UNROLL
        uint8 temp = data_in.range((i+1) * 8 -1, i * 8);
        data_out.range((i+1)*8-1, i*8)  = temp + 1;
    }

    chan_out.write(data_out);
}

