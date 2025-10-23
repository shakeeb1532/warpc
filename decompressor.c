#include "warpc.h"

void decompress(const char *input_path, const char *output_path) {
    FILE *in = fopen(input_path, "rb");
    FILE *out = fopen(output_path, "wb");
    if (!in || !out) {
        perror("File error");
        return;
    }

    BitReader br;
    init_bitreader(&br, in);

    int bit, byte = 0, count = 0;
    while ((bit = read_bit(&br)) != -1) {
        bit ^= 1;  // Invert back
        byte = (byte << 1) | bit;
        count++;
        if (count == 8) {
            fputc(byte, out);
            byte = 0;
            count = 0;
        }
    }

    fclose(in);
    fclose(out);
}

