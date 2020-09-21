#include "dut.h"

void proc_a(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    hls::stream<pix_unit_t>     &chan_out)
{
    ROW: for (int row = 0; row < 8; row++) {
#pragma HLS PIPELINE
        pix_unit_t  unit = chan_in.read();
#pragma HLS ARRAY_PARTITION variable=unit.data complete dim=1

        COL: for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            unit.data[i] += 1;
        }

        // write data to the output channel
        chan_out.write(unit);
    }
}

void proc_b(
    // IN
    uint32                      mem_id,
    hls::stream<pix_unit_t>     &chan_in,
    // OUT
    uint8                       mem[2][8][8])
{
    ROW: for (int row = 0; row < 8; row++) {
#pragma HLS PIPELINE
        pix_unit_t  unit = chan_in.read();
#pragma HLS ARRAY_PARTITION variable=unit.data complete dim=1

        COL: for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            unit.data[i] += 1;
        }

        // write data to the output memory
        MEM_WR: for (int i=0; i < 8; i++) {
#pragma HLS UNROLL
            mem[mem_id][row][i] = unit.data[i];
        } 
    }
}

void dut(
    // IN
    hls::stream<pix_unit_t>     &chan_in,
    // OUT
    uint8                       mem[2][8][8])
{
#pragma HLS DATA_PACK variable=chan_in
#pragma HLS ARRAY_RESHAPE variable=mem cyclic factor=8 dim=3
    for (int i=0; i < 2; i++) {
#pragma HLS DATAFLOW
        hls::stream<pix_unit_t>     fifo_unit;

        proc_a(chan_in, fifo_unit);

        proc_b(i, fifo_unit, mem);
    }
}
