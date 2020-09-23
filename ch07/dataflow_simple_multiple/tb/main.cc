#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    hls::stream<pix_unit_t>         chan_in;
    hls::stream<pix_unit_t>         chan_out;
    uint8                           mem[2][8][8];       // two 8x8 blocks

    // feeding 
    for (int block=0; block < 4; block++) {
        for (int row=0; row < 8; row++) {
            pix_unit_t unit;

            // fill the row
            for (int col=0; col < 8; col++) {
                unit.data[col] = 64 * block + row * 8 + col;
            }

            chan_in.write(unit);
        }
    }

    // call DUT
    dut(
        // IN
        chan_in,
        // OUT
        chan_out 
    );

    while (!chan_out.empty()) {
        pix_unit_t unit = chan_out.read();

        for (int i =0; i < 8; i++) {
            cout.width(3);
            cout << unit.data[i] << " "; 
        }
        cout << endl;
    }

    return 0;
}