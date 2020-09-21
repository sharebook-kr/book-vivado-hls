#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    cout << "Hello HLS" << endl;
    hls::stream<uint8>          chan_in;
    hls::stream<uint8>          chan_out;

    // feeding 
    for (int i =0; i < 10; i++) {
        uint8 data = i;
        chan_in.write(data);
    }

    // call DUT
    dut(
        // INPUT
        chan_in,
        // OUTPUT
        chan_out
    );

    //  read output from the channel
    int mismatch = 0;
    for (int i =0; i < 10; i++) {
        uint8 data = i;
        data = chan_out.read();

        if (data != i) 
            mismatch = 1;
    }

    if (mismatch == 1) {
        cout << "MISMATCH" << endl;
        return 1;
    } else {
        cout << "PASSED" << endl;
        return 0;
    }
}