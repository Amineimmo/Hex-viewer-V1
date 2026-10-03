#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    unsigned char buffer[16];
    size_t bytes_read;
    size_t offset = 0;

    // Read chunks of up to 16 bytes at a time
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Print the current file byte offset in 8-digit hex
        printf("%08zx: ", offset);
        for (size_t i = 0; i < bytes_read; i++) {
            printf("%02X ", buffer[i]);
        }

        for (size_t i = bytes_read; i < 16; i++) {
            printf("   ");
        }
        printf(" |");
        for (size_t i = 0; i < bytes_read; i++) {
            // Printable characters range from ASCII 32 (' ') to 126 ('~')
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                putchar(buffer[i]);
            } else {
                putchar('.'); // Dot for non-printable/control characters
            }
        }
        printf("|\n");

        offset += bytes_read;
    }

    fclose(file);
    return 0;
}