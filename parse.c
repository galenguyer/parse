#include <stdio.h>

#include "parse.h"

#ifndef MAX_OPTS
#define MAX_OPTS 64
#endif

struct option* _options[MAX_OPTS];
int _opt_count = 0;

void _print_option(struct option *opt) { printf("opt at %p\n", opt); }

void print_options() {
  for (int i = 0; i < _opt_count; i++) {
    _print_option(_options[i]);
  }
}

void add_opt() {
    struct option opt = { "-h", "-h" };
    _options[_opt_count] = &opt;
    _opt_count++;
}

int main() {
    add_opt();
    print_options();
    return 0;
}