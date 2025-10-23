#ifndef WARPC_H
#define WARPC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void compress(const char *input_path, const char *output_path);
void decompress(const char *input_path, const char *output_path);

#endif
