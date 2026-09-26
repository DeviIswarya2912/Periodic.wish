#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Maximum possible valid times on a binary watch is 720 (12 * 60)
    char** result = (char**)malloc(720 * sizeof(char*));
    int capacity = 720;
    *returnSize = 0;

    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            if (countBits(h) + countBits(m) == turnedOn) {
                result[*returnSize] = (char*)malloc(6 * sizeof(char));
                sprintf(result[*returnSize], "%d:%02d", h, m);
                (*returnSize)++;
            }
        }
    }

    return result;
}
