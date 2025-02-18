/* Include any necessary libraries and header files */
#include "../header_files/compress.h"
#include "../header_files/constants.h"
#include "../header_files/utils.h"
#include <stdio.h>

int compress(const char *input_file_name, const char *output_file_name) {
    FILE *input, *output;
    open_files(&input, &output, input_file_name, output_file_name, "w");

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, input)) {
        for (int i = 0; line[i] != '\0'; i++) {
            char current_char = line[i];
            int count = 1;

            while (line[i + 1] == current_char) {
                count++;
                i++;
            }

            fprintf(output, "%c%d", current_char, count);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
