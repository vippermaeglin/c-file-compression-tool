/* Include any necessary libraries and header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header_files/compress.h"
#include "../header_files/decompress.h"
#include "../header_files/utils.h"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <-c/-d> <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char output_file[256];  // Buffer for the output filename

    if (strcmp(argv[1], "-c") == 0 && argc == 3) {
        generate_output_filename(argv[2], output_file, ".rle");
        compress(argv[2], output_file);
        printf("Compression completed: %s -> %s\n", argv[2], output_file);
    } else if (strcmp(argv[1], "-d") == 0 && argc == 3) {
        generate_output_filename(argv[2], output_file, ".txt");
        decompress(argv[2], output_file);
        printf("Decompression completed: %s -> %s\n", argv[2], output_file);
    } else if (strcmp(argv[1], "-h") == 0) {
        printf("Use '-c' for compress or '-d' for decompress.\n");
    } else {
        printf("Invalid operation. Use 'h' for help.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}