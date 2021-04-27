struct option {
    char* long_opt;
    char* short_opt;
    char* value;
    int isset;
};

void print_opts();
void add_opt(const char* short_opt, const char* long_opt);
