struct option {
    char* long_opt;
    char* short_opt;
    char* value;
    int isset;
};

void print_opts();
void add_opt(struct option* opt);
