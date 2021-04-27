#include <stdlib.h>
#include <string.h>

char* strip_left(const char* input, const char delimiter) {
    int start = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != delimiter) {
            break;
        }
        start++;
    }
    char* output = calloc((strlen(input) - start + 1), sizeof(char));
    strncpy(output, input + start, strlen(input) - start);
    return output;
}