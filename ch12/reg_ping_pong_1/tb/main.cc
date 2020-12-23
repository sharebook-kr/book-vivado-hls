#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    hls::stream<pix_unit_t>     chan_in;
    hls::stream<pix_unit_t>     chan_out;

    // feeding 
    for (int iter=0; iter < 4; iter++) {
        for (int c =0; c < 8; c++) {
            pix_unit_t local;

            for (int r=0; r < 8; r++)
                local.pix[r] = r * 10;

            chan_in.write(local);
        }
    }

    // DUT
    for (int iter=0; iter < 4; iter++) {
        dut(
            //IN
            chan_in,
            //OUT
            chan_out
        );

        while(!chan_out.empty()) {
            pix_unit_t out = chan_out.read();

            for (int i=0; i < 8; i++) {
                printf("%3d ", out.pix[i].to_int());
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}