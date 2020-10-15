#include "dut.h"

void dut(
    // IN
    hls::stream<org_unit_t>     &chan_in,
    // OUT
    hls::stream<org_unit_t>     &chan_out)
{
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS DATA_PACK variable=chan_out

#ifndef __SYNTHESIS__
    while (!chan_in.empty()) {
#endif
        org_unit_t data;
#pragma HLS ARRAY_RESHAPE variable=data.org complete dim=1

        data = chan_in.read();
        chan_out.write(data);

#ifndef __SYNTHESIS__
    }
#endif   
}

