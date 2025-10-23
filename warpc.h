#ifndef WARPC_H
#define WARPC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void compress(const char *input_path, const char *output_path);
void decompress(const char *input_path, const char *output_path);

typedef struct {
    FILE *file;
    uint8_t buffer;
    int bit_pos;
} BitWriter;

typedef struct {
    FILE *file;
    uint8_t buffer;
    int bit_pos;
} BitReader;

void init_bitwriter(BitWriter *bw, FILE *file);
void write_bit(BitWriter *bw, int bit);
void flush_bits(BitWriter *bw);

void init_bitreader(BitReader *br, FILE *file);
int read_bit(BitReader *br);

#endif
