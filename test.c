/* MIT License

Copyright (c) 2021 Galen Guyer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#include <stdio.h>
#include <string.h>

#include "parse.h"
#include "strings.h"

int test(char* name, char* result, char* expected) {
    if (strcmp(expected, result) == 0) {
        printf("TEST PASSED: %s: expected %s, got %s\n", name, expected,
               result);
        return 1;
    } else {
        printf("TEST FAILED: %s: expected %s, got %s\n", name, expected,
               result);
        return 0;
    }
}

int main(int argc, char** argv) {
    int passed = 0, failed = 0;

    puts("----- [strip_left] -----");
    test("strip_left:single", strip_left("-h", '-'), "h") ? passed++ : failed++;
    test("strip_left:multiple", strip_left("--help", '-'), "help") ? passed++
                                                                   : failed++;
    test("strip_left:none", strip_left("help", '-'), "help") ? passed++
                                                             : failed++;

    puts("----- [Adding and Printing Opts] -----");
    struct option help = {.short_opt = "-h", .long_opt = "--help"};
    struct option verbosity = {.short_opt = "-v", .long_opt = "--verbose"};
    struct option echo = {.short_opt = "-e", .long_opt = "--echo"};
    add_opt(&help);
    add_opt(&verbosity);
    add_opt(&echo);
    print_opts();

    puts("----- [parse_args] -----");
    char* test_args[5] = {"parse", "-v", "--help", "--echo", "testing"};
    parse_args(5, test_args);

    puts("----- [Results] -----");
    printf("Tests Passed: %i\n", passed);
    printf("Tests Failed: %i\n", failed);
    return failed;
}