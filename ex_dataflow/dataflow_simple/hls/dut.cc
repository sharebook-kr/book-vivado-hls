#include "dut.h"

void proc_a(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    hls::stream<pix_unit_t>     &chan_out)
{
    for (int row = 0; row < 8; row++) {
#pragma HLS PIPELINE
        pix_unit_t  unit = chan_in.read();
#pragma HLS ARRAY_PARTITION variable=unit.data complete dim=1

        for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            unit.data[i] += 1;
        }

        // write data to the ouput channel
        chan_out.write(unit);
    }
}

void proc_b(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    // OUT
    hls::stream<pix_unit_t>     &chan_out)
{
    for (int row = 0; row < 8; row++) {
#pragma HLS PIPELINE
        pix_unit_t  unit = chan_in.read();
#pragma HLS ARRAY_PARTITION variable=unit.data complete dim=1

        for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            unit.data[i] += 1;
        }

        // write data to the ouput channel
        chan_out.write(unit);
    }
}

void proc_c(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    // OUT
    hls::stream<pix_unit_t>     &chan_out)
{
    for (int row = 0; row < 8; row++) {
#pragma HLS PIPELINE
        pix_unit_t  unit = chan_in.read();
#pragma HLS ARRAY_PARTITION variable=unit.data complete dim=1

        for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            unit.data[i] += 1;
        }

        // write data to the ouput channel
        chan_out.write(unit);
    }
}

void dut(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    // OUT
    hls::stream<pix_unit_t>     &chan_out)
{
#pragma HLS DATAFLOW
#pragma HLS DATA_PACK variable=chan_out
#pragma HLS DATA_PACK variable=chan_in
    hls::stream<pix_unit_t>     fifo_unit1;
#pragma HLS DATA_PACK variable=fifo_unit1
    hls::stream<pix_unit_t>     fifo_unit2;
#pragma HLS DATA_PACK variable=fifo_unit2

    proc_a(chan_in, fifo_unit1);

    proc_b(fifo_unit1, fifo_unit2);

    proc_c(fifo_unit2, chan_out);
}
