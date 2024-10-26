#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SSN_LENGTH 12 // Including the null terminator
#define MAX_SSNS 1000000 // Maximum number of SSNs to process

bool isValidSSN(const char *ssn) {
    // Check for the correct format
    if (strlen(ssn) != 11 || ssn[3] != '-' || ssn[6] != '-') {
        return false; // Invalid format
    }

    // Extract the relevant parts of the SSN
    char area[4], group[3], serial[5];
    strncpy(area, ssn, 3);
    area[3] = '\0';
    strncpy(group, ssn + 4, 2);
    group[2] = '\0';
    strncpy(serial, ssn + 7, 4);
    serial[4] = '\0';

    // Check for invalid starting numbers
    if (strcmp(area, "000") == 0 || strcmp(area, "666") == 0 || area[0] == '9') {
        return false; // Invalid area number
    }

    // Check for invalid group and serial numbers
    if (strcmp(group, "00") == 0 || strcmp(serial, "0000") == 0) {
        return false; // Invalid group or serial number
    }

    return true; // Valid SSN
}

int main(int argc, char *argv[]) {
    FILE *file;
    char ssn[SSN_LENGTH]; // Buffer for SSN
    int invalidCount = 0;
    int invalidFormatCount = 0;
    int invalidDuplicateCount = 0;
    int invalidStartCount = 0;
    int invalidGroupSerialCount = 0;
    bool duplicateSet[MAX_SSNS] = {false}; // To track seen SSNs

    // Check if a filename was provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ssn_file>\n", argv[0]);
        return 1;
    }

    // Open the file specified as a command-line argument
    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Read SSNs from the file
    while (fgets(ssn, sizeof(ssn), file)) {
        ssn[strcspn(ssn, "\n")] = '\0'; // Remove newline character

        // Check for duplicates
        int index = atoi(ssn);
        if (index < 0 || index >= MAX_SSNS || duplicateSet[index]) {
            invalidDuplicateCount++;
            invalidCount++;
            continue; // Skip further validation
        }
        duplicateSet[index] = true; // Mark as seen

        // Validate the SSN
        if (!isValidSSN(ssn)) {
            invalidCount++;
            // Increment specific counts based on failure reasons
            if (strlen(ssn) != 11 || ssn[3] != '-' || ssn[6] != '-') {
                invalidFormatCount++;
            } else if (ssn[0] == '9' || strcmp(ssn, "666") == 0 || strcmp(ssn, "000") == 0) {
                invalidStartCount++;
            } else if (strcmp(ssn + 4, "00") == 0 || strcmp(ssn + 7, "0000") == 0) {
                invalidGroupSerialCount++;
            }
        }
    }

    fclose(file);

    // Print the results
    printf("Total SSNs processed: %d\n", invalidCount + (int)(sizeof(duplicateSet) / sizeof(duplicateSet[0])) - invalidDuplicateCount);
    printf("Invalid SSNs: %d\n", invalidCount);
    printf("Invalid format: %d\n", invalidFormatCount);
    printf("Duplicate SSNs: %d\n", invalidDuplicateCount);
    printf("SSNs starting with 9 or 666/000: %d\n", invalidStartCount);
    printf("Invalid group/serial numbers: %d\n", invalidGroupSerialCount);

    return 0;
}
