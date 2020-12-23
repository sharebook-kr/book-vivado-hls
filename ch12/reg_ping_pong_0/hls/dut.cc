#include "dut.h"

// 8x8 block transpose with register ping-pong buffer
void dut(
    //IN
    hls::stream<pix_unit_t> &chan_in,
    //OUT
    hls::stream<pix_unit_t> &chan_out)
{
    uint8 buf[8][8];
 #pragma HLS ARRAY_PARTITION variable=buf complete dim=0     // set buffer as register

    // read a column
    RD: for (int c=0; c < 8; c++) {
#pragma HLS PIPELINE
        pix_unit_t local = chan_in.read();

        for (int r=0; r < 8; r++) {
#pragma HLS UNROLL
            buf[r][c] = local.pix[r];
        }
    }

    // write a row
    WR: for (int r=0; r < 8; r++) {
#pragma HLS PIPELINE
        pix_unit_t local;
#pragma HLS ARRAY_PARTITION variable=local.pix complete dim=0

        for (int c=0; c < 8; c++) {
#pragma HLS UNROLL
            local.pix[c] = buf[r][c];
        }

        chan_out.write(local);
    }
}