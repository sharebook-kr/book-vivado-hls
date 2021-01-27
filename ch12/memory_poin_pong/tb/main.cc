#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    cout << "Manual ping-pong buffer ctrl example" << endl;

    hls::stream<unit_t>     chan_in;
    hls::stream<unit_t>     chan_out;

    // feeding 
    for (int blk=0; blk < BLOCK_NUM; blk++) {
        for (int row=0; row < 8; row++) {
            unit_t line;

            for (int col=0; col < 8; col++) {
                line.pix[col] = blk * 10;
            }

            chan_in.write(line);
        } 
    }

    // call DUT
    for (int blk=0; blk < BLOCK_NUM; blk++) {
        dut(
            //IN
            chan_in,
            //OUT
            chan_out
        );
    }


    while (!chan_out.empty()) {
        unit_t line = chan_out.read();

        for (int col =0; col < 8; col++)  {
            printf("%2d ", line.pix[col].to_int() );
        }
        cout << endl;
    }

    return 0;
}