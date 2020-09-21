#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    cout << "Hello HLS" << endl;
    hls::stream<pix_unit_t>         chan_in;
    uint8                           mem[2][8][8];       // two 8x8 blocks

    // feeding 
    for (int block=0; block < 2; block++) {
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
        // INPUT
        chan_in,
        // OUTPUT
       mem 
    );

    for (int block=0; block < 2; block++) {
        for (int row=0; row < 8; row++) {
            for (int col=0; col < 8; col++) {
                cout.width(3);
                cout << mem[block][row][col] << " ";  
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}