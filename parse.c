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
    printf("opt{short_opt:'%s', long_opt:'%s'}\n", opt->short_opt,
           opt->long_opt);
}

void print_opts() {
    for (int i = 0; i < _opt_count; i++) {
        _print_opt(_options[i]);
    }
}

void add_opt(const char* short_opt, const char* long_opt) {
    struct option* opt = (struct option*)malloc(sizeof(struct option));
    char* stripped_short_opt = strip_left(short_opt, '-');
    char* stripped_long_opt = strip_left(long_opt, '-');
    opt->short_opt = (char*)malloc(sizeof(char) * (strlen(stripped_short_opt) + 1));
    opt->long_opt = (char*)malloc(sizeof(char) * (strlen(stripped_long_opt) + 1));
    strcpy(opt->short_opt, stripped_short_opt);
    strcpy(opt->long_opt, stripped_long_opt);
    opt->value = NULL;
    opt->isset = 0;
    _options[_opt_count] = opt;
    _opt_count++;
    free(stripped_short_opt);
    free(stripped_long_opt);
}
