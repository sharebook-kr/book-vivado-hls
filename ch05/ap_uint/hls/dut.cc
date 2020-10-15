#include "dut.h"

void dut(
    // IN
    hls::stream<org_unit_t>     &chan_in,
    // OUT
    hls::stream<org_unit_t>     &chan_out)
{
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS DATA_PACK variable=chan_out

    org_unit_t data;
    data = chan_in.read();

    org_unit_t data_out;

    for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
        data_out.org[i] = data.org[i]+1;
    }

    chan_out.write(data_out);
}

