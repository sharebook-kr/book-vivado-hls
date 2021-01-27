#ifndef __DUT_H__
#define __DUT_H__

#include <hls_stream.h>
#include "hls_int.h"

#define BLOCK_NUM  4

typedef struct {
    uint8   pix[8];
} unit_t;

void dut(
    //IN
    hls::stream<unit_t>     &chan_in, 
    //OUT
    hls::stream<unit_t>     &chan_out);

#endif 
