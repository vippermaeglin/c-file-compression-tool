#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

void open_files(FILE **input, FILE **output, const char *input_filename, const char *output_filename, const char *mode);
void generate_output_filename(const char *input_file, char *output_file, const char *new_extension);

#endif