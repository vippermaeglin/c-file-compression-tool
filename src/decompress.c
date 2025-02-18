/* Include any necessary libraries and header files */
#include "../header_files/decompress.h"
#include "../header_files/constants.h"
#include "../header_files/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int decompress(const char *input_file_name, const char *output_file_name) {
    FILE *fin = fopen(input_file_name, "r");
    FILE *fout = fopen(output_file_name, "w");

    if (!fin || !fout) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char ch;
    int count;

    while ((ch = fgetc(fin)) != EOF) {
        if (ch == '\n') {
            // Preserve newlines exactly as they are
            fputc(ch, fout);
        } else {
            // Read the count after the character
            if (fscanf(fin, "%d", &count) == 1) {
                for (int i = 0; i < count; i++) {
                    fputc(ch, fout);
                }
            }
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
