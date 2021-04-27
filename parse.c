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
    opt->isset = 0;
    opt->value = NULL;
    _options[_opt_count] = opt;
    _opt_count++;
}
