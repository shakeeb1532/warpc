#include "warpc.h"

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: warpc -c|-d -i input -o output\n");
        return 1;
    }

    const char *mode = argv[1];
    const char *input_path = NULL;
    const char *output_path = NULL;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && i + 1 < argc) {
            input_path = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_path = argv[++i];
        }
    }

    if (!input_path || !output_path) {
        printf("Input or output file missing.\n");
        return 1;
    }

    if (strcmp(mode, "-c") == 0) {
        compress(input_path, output_path);
    } else if (strcmp(mode, "-d") == 0) {
        decompress(input_path, output_path);
    } else {
        printf("Unknown mode: %s\n", mode);
        return 1;
    }
    return 0;
}
