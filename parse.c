#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"
#include "strings.h"

#ifndef MAX_OPTS
#define MAX_OPTS 64
#endif

struct option* _options[MAX_OPTS];
int _opt_count = 0;

void _print_opt(const struct option* opt) {
    printf("opt{short_opt:'%s', long_opt:'%s', isset:%d, value:'%s'}\n",
           opt->short_opt, opt->long_opt, opt->isset, opt->value);
}

void print_opts() {
    for (int i = 0; i < _opt_count; i++) {
        _print_opt(_options[i]);
    }
}

void add_opt(struct option* opt) {
    // TODO: Add checks to make sure long_opt and short_opt are valid
    // TODO: Strip leading - from opts
    opt->isset = 0;
    opt->value = NULL;
    _options[_opt_count] = opt;
    _opt_count++;
}

void parse_args(int argc, char** argv) {
    char* prev_token = NULL;
    for (int i = 1; i < argc; i++) {
        char* curr_token = argv[i];
        int token_len = strlen(argv[i]);
        int tack_count = 0;
        {
            int j = 0;
            while (curr_token[j] == '-') {
                tack_count++;
                j++;
            }
        }
        if (tack_count == 1) {
            for (int j = tack_count; j < token_len; j++) {
                printf("%c\n", curr_token[j]);
            }
        } else if (tack_count == 2) {
            printf("%s\n", curr_token + tack_count);
        }
    }
}
