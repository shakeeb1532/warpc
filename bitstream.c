#include "warpc.h"

void init_bitwriter(BitWriter *bw, FILE *file) {
    bw->file = file;
    bw->buffer = 0;
    bw->bit_pos = 0;
}

void write_bit(BitWriter *bw, int bit) {
    if (bit) bw->buffer |= (1 << (7 - bw->bit_pos));
    bw->bit_pos++;
    if (bw->bit_pos == 8) {
        fputc(bw->buffer, bw->file);
        bw->buffer = 0;
        bw->bit_pos = 0;
    }
}

void flush_bits(BitWriter *bw) {
    if (bw->bit_pos > 0) {
        fputc(bw->buffer, bw->file);
        bw->buffer = 0;
        bw->bit_pos = 0;
    }
}

void init_bitreader(BitReader *br, FILE *file) {
    br->file = file;
    br->buffer = 0;
    br->bit_pos = 8;
}

int read_bit(BitReader *br) {
    if (br->bit_pos == 8) {
        int c = fgetc(br->file);
        if (c == EOF) return -1;
        br->buffer = (uint8_t)c;
        br->bit_pos = 0;
    }
    int bit = (br->buffer >> (7 - br->bit_pos)) & 1;
    br->bit_pos++;
    return bit;
}

