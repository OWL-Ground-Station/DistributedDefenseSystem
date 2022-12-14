#include "monitor.h"

int update_entrophy(file_entr entrophies[], int arr_len) {

    for (int i = 0; i < arr_len; ++i) {
        file_entr curr = entrophies[i];
        double entr = calc_entrophy_file(curr.filename);
        // Simple for testing just update if entrophy is greater than 50%
        if ((entr - curr.entrophy) / curr.entrophy > 0.5) {
          return 1;
        }
        curr.entrophy = entr;
    }

    return 0;
}