struct option {
    char* long_opt;
    char* short_opt;
    char* value;
    int isset;
};

void print_options();