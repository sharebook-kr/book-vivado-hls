#ifndef __DUT_H__
#define __DUT_H__

#include <hls_stream.h>
#include "hls_int.h"

void dut(
    // IN
    hls::stream<uint64>     &chan_in,
    // OUT
    hls::stream<uint64>     &chan_out);

#endif 
