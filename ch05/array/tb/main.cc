#include <hls_stream.h>
#include <iostream>
#include "../hls/dut.h"

using namespace std;

int main(void) 
{
    cout << "Hello HLS" << endl;
    hls::stream<org_unit_t>     chan_in;
    hls::stream<org_unit_t>     chan_out;

    // feeding 
#if 0
    for (int i=0; i < 10; i++) {
        org_unit_t data_in;
        for (int j=0; j < 8; j++)
            data_in.org[j] = i;

        chan_in.write(data_in);
    }
#endif

    // call DUT
    int mismatch = 0;

    for (int i=0; i < 10; i++) {
        org_unit_t data_in;
        for (int j=0; j < 8; j++)
            data_in.org[j] = i;

        chan_in.write(data_in);

        dut(
            // INPUT
            chan_in,
            // OUTPUT
            chan_out
        );

        org_unit_t data_out= chan_out.read();
        cout << i << endl;
        if (data_out.org[0] != i+1) {
            mismatch = 1;
        }
    }

    //  read output from the channel
#if 0
    for (int i =0; i < 10; i++) {
        org_unit_t data_out= chan_out.read();

        cout << i << endl;
        if (data_out.org[0] != i+1) {
            mismatch = 1;
            break;
        }
    }
#endif

    if (mismatch == 1) {
        cout << "MISMATCH" << endl;
        return 1;
    } else {
        cout << "PASSED" << endl;
        return 0;
    }
}
