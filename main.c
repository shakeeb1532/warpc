#include "warpc.h"

int main(int argc, char *argv[]) {
    if (argc < 6) {
        printf("Usage: warpc -c|-d -i input -o output\n");
        return 1;
    }

    int compress_flag = 0, decompress_flag = 0;
    const char *input_file = NULL, *output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            compress_flag = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            decompress_flag = 1;
        } else if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            input_file = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[++i];
        }
    }

    if (!input_file || !output_file) {
        printf("Input or output file not specified\n");
        return 1;
    }

    if (compress_flag) {
        compress(input_file, output_file);
    } else if (decompress_flag) {
        decompress(input_file, output_file);
    } else {
        printf("Please specify -c to compress or -d to decompress\n");
        return 1;
    }

    return 0;
}

