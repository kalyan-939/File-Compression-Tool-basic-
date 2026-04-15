#include <stdio.h>
#include <stdlib.h>

// Function to compress file
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char current, prev;
    int count = 1;

    prev = fgetc(in);

    while ((current = fgetc(in)) != EOF) {
        if (current == prev) {
            count++;
        } else {
            fprintf(out, "%c%d", prev, count);
            prev = current;
            count = 1;
        }
    }

    fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);

    printf("File compressed successfully!\n");
}

// Function to decompress file
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    int count;

    while (fscanf(in, "%c%d", &ch, &count) != EOF) {
        for (int i = 0; i < count; i++) {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);

    printf("File decompressed successfully!\n");
}

int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("1. Compress File\n");
    printf("2. Decompress File\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
