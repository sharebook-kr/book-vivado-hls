#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    hls::stream<uint64>     chan_in;
    hls::stream<uint64>     chan_out;

    // feeding 
    for (int i=0; i < 10; i++) {
        uint64 data_in;

        for (int j=0; j < 8; j++)
            data_in.range((j+1)*8-1, j*8) = i;

        chan_in.write(data_in);
    }

    // call DUT
    for (int i=0; i < 10; i++) {
        dut(
            // INPUT
            chan_in,
            // OUTPUT
            chan_out
        );
    }

    //  read output from the channel
    int mismatch = 0;
    for (int i=0; i < 10; i++) {
        uint64 data_out= chan_out.read();

        cout << i << endl;
        if (data_out.range(7, 0) != i+1) {
            mismatch = 1;
            break;
        }
    }

    if (mismatch == 1) {
        cout << "MISMATCH" << endl;
        return 1;
    } else {
        cout << "PASSED" << endl;
        return 0;
    }

    return 0;
}
