#include "dut.h"


void dut(
    // IN
    hls::stream<uint8>      &chan_in,
    // OUT
    hls::stream<uint8>      &chan_out)
{
#ifndef __SYNTHESIS__
    while (!chan_in.empty()) {
#endif

    uint8   data = chan_in.read();
    chan_out.write(data);

#ifndef __SYNTHESIS__
    }
#endif
}