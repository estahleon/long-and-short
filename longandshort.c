#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Must provide three arguments \n");
        return 1;
    }

    FILE *start = fopen(argv[1], "r");
    if (!start) {
        printf("Couldn't open input file\n");
        return 1;
    }

    FILE *upper = fopen(argv[2], "w");
    if (!upper) {
        printf("Couldn't open uppercase output file\n");
        fclose(start);
        return 1;
    }

    FILE *lower = fopen(argv[3], "w");
    if (!lower) {
        printf("Couldn't open lowercase output file\n");
        fclose(start);
        fclose(upper);
        return 1;
    }

    char line[255];
    int upperCount = 0;
    int lowerCount = 0;

    while (fgets(line, 255, start)) {
        line[strcspn(line, "\n")] = '\0';

        if (strlen(line) < 20) {
            for (int i = 0; line[i]; i++) {
                line[i] = toupper(line[i]);
            }
            fprintf(upper, "%s\n", line);
            upperCount++;
        } else {
            for (int i = 0; line[i]; i++) {
                line[i] = tolower(line[i]);
            }
            fprintf(lower, "%s\n", line);
            lowerCount++;
        }
    }

    fclose(start);
    fclose(upper);
    fclose(lower);

    printf("%d lines written to %s\n", upperCount, argv[2]);
    printf("%d lines written to %s\n", lowerCount, argv[3]);

    return 0;
}

