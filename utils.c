#include <stdio.h>
#include <string.h>
#include "utils.h"

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        int len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
    } else {
        buffer[0] = '\0';
    }
}

int readInt(const char *prompt) {
    char line[100];
    int value;
    int valid = 0;

    do {
        printf("%s", prompt);
        readLine(line, sizeof(line));
        if (sscanf(line, "%d", &value) == 1) {
            valid = 1;
        } else {
            printf("Invalid input. Please enter a whole number.\n");
        }
    } while (!valid);

    return value;
}

int readPositiveInt(const char *prompt) {
    int value;
    do {
        value = readInt(prompt);
        if (value < 0) {
            printf("Value cannot be negative. Try again.\n");
        }
    } while (value < 0);
    return value;
}

float readNonNegativeFloat(const char *prompt) {
    char line[100];
    float value;
    int valid = 0;

    do {
        printf("%s", prompt);
        readLine(line, sizeof(line));
        if (sscanf(line, "%f", &value) == 1) {
            if (value < 0) {
                printf("Value cannot be negative. Try again.\n");
                valid = 0;
            } else {
                valid = 1;
            }
        } else {
            printf("Invalid input. Please enter a number (e.g. 1500.00).\n");
        }
    } while (!valid);

    return value;
}

void readNonEmptyString(const char *prompt, char *buffer, int size) {
    int valid = 0;
    do {
        printf("%s", prompt);
        readLine(buffer, size);
        if (strlen(buffer) == 0) {
            printf("This field cannot be empty. Try again.\n");
        } else {
            valid = 1;
        }
    } while (!valid);
}

void pauseScreen(void) {
    printf("\nPress ENTER to continue...");
    getchar();
}
