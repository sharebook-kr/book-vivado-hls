#include "dut.h"

void dut(
    // IN
    hls::stream<org_unit_t>     &chan_in,
    // OUT
    hls::stream<org_unit_t>     &chan_out)
{
#pragma HLS PIPELINE II=1 rewind
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS DATA_PACK variable=chan_out

    org_unit_t data;
    data = chan_in.read();

    for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
        data.org[i] = data.org[i]+1;
    }

    chan_out.write(data);
}

