#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse.h"

#ifndef MAX_OPTS
#define MAX_OPTS 64
#endif

struct option* _options[MAX_OPTS];
int _opt_count = 0;

void _print_option(struct option* opt) {
    printf("opt{short_opt:'%s', long_opt:'%s'}\n", opt->short_opt,
           opt->long_opt);
}

void print_opts() {
    for (int i = 0; i < _opt_count; i++) {
        _print_option(_options[i]);
    }
}

void add_opt(const char* short_opt, const char* long_opt) {
    struct option* opt = (struct option*)malloc(sizeof(struct option));
    opt->short_opt = (char*)malloc(sizeof(char) * (strlen(short_opt) + 1));
    opt->long_opt = (char*)malloc(sizeof(char) * (strlen(long_opt) + 1));
    strcpy(opt->short_opt, short_opt);
    strcpy(opt->long_opt, long_opt);
    opt->value = NULL;
    opt->isset = 0;
    _options[_opt_count] = opt;
    _opt_count++;
}

int main() {
    add_opt("-h", "--help");
    add_opt("-v", "--verbose");
    print_opts();
    return 0;
}