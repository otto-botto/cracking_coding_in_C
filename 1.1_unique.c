#include <stdbool.h>

bool unique(char* word) {
    int checker = 0;

    while (*word) {
        int val = *word;
        if ((checker & (1<<val)) > 0) {
            return false;
        }else {
            checker |= 1<<val;
        }
        word++;
    }
    return true;
}
