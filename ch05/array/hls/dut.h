#ifndef __DUT_H__
#define __DUT_H__

#include <hls_stream.h>
#include "hls_int.h"

typedef struct {
    uint8  org[8];
} org_unit_t;

void dut(
    // IN
    hls::stream<org_unit_t>     &chan_in,
    // OUT
    hls::stream<org_unit_t>     &chan_out);

#endif 
