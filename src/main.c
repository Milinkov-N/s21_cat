#include <stdio.h>

#include "s21_cat.h"

int main(int argc, char** argv) {
    for (int i = 1; i != argc; ++i) {
        printf("argv[%d]: %s\n", i, argv[i]);
        // code here
    }

    return 0;
}
