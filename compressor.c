#include "warpc.h"

void compress(const char *input_path, const char *output_path) {
    FILE *in = fopen(input_path, "rb");
    FILE *out = fopen(output_path, "wb");
    if (!in || !out) {
        perror("File error");
        return;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch ^ 0xAA, out);  // Dummy XOR compression
    }

    fclose(in);
    fclose(out);
}
