#include "warpc.h"

void compress(const char *input_path, const char *output_path) {
    FILE *in = fopen(input_path, "rb");
    FILE *out = fopen(output_path, "wb");
    if (!in || !out) {
        perror("File error");
        return;
    }

    BitWriter bw;
    init_bitwriter(&bw, out);

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        for (int i = 7; i >= 0; i--) {
            int bit = (ch >> i) & 1;
            bit ^= 1;  // Simple bit-level XOR (invert)
            write_bit(&bw, bit);
        }
    }

    flush_bits(&bw);
    fclose(in);
    fclose(out);
}

