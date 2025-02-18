/* Include any necessary libraries and header files */
#include "../header_files/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void open_files(FILE **input, FILE **output, const char *input_filename, const char *output_filename, const char *mode) {
    *input = fopen(input_filename, "r");
    if (!*input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    *output = fopen(output_filename, mode);
    if (!*output) {
        perror("Error opening output file");
        fclose(*input);
        exit(EXIT_FAILURE);
    }
}

void generate_output_filename(const char *input_file, char *output_file, const char *new_ext) {
    char base_name[256];  // Buffer for filename without extension
    int version = 0;

    // Copy input filename and remove extension if it exists
    strcpy(base_name, input_file);
    char *dot = strrchr(base_name, '.');  // Find last '.'
    if (dot && dot != base_name) {  // Ensure it's not the first character
        *dot = '\0';  // Remove extension
    }

    // Try the first filename (avoid adding extra dot)
    snprintf(output_file, 300, "%s%s", base_name, new_ext);

    // Check if file exists, incrementing version if necessary
    while (access(output_file, F_OK) == 0) {  // Ensure <unistd.h> is included
        version++;
        snprintf(output_file, 300, "%s_%d%s", base_name, version, new_ext);
    }
}