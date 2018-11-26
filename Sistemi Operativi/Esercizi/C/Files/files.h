
#ifndef files_h
#define files_h

#include <stdio.h>

int cat(int argc, char **argv);
int diff(int argc, char **argv);

void print_random(int count);
void posix_print_random(int count);

void count_file_modifies(const char *filename, int seconds);

#endif /* files_h */
