#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SSN_LENGTH 12 // Including null terminator
#define HASH_SIZE 100003 // Hash table size for duplicate tracking

// Hash table entry structure
typedef struct Entry {
    char ssn[SSN_LENGTH];
    struct Entry *next;
} Entry;

// Hash function for SSNs
unsigned int hash(const char *ssn) {
    unsigned int hash = 5381;
    for (int i = 0; ssn[i] != '\0'; i++) {
        hash = ((hash << 5) + hash) + ssn[i]; // hash * 33 + ssn[i]
    }
    return hash % HASH_SIZE;
}

// Insert SSN into hash table and return if it is a duplicate
bool isDuplicate(char *ssn, Entry *hashTable[]) {
    unsigned int index = hash(ssn);
    Entry *current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->ssn, ssn) == 0) {
            return true; // Found duplicate
        }
        current = current->next;
    }

    // Insert new SSN into the hash table
    Entry *newEntry = malloc(sizeof(Entry));
    strcpy(newEntry->ssn, ssn);
    newEntry->next = hashTable[index];
    hashTable[index] = newEntry;

    return false;
}

// Validation function for SSN
bool isValidSSN(const char *ssn, int *invalidFormat, int *invalidStart, int *invalidGroupSerial) {
    // Check for the correct format
    if (strlen(ssn) != 11 || ssn[3] != '-' || ssn[6] != '-') {
        (*invalidFormat)++;
        return false;
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
        (*invalidStart)++;
        return false;
    }

    // Check for invalid group and serial numbers
    if (strcmp(group, "00") == 0 || strcmp(serial, "0000") == 0) {
        (*invalidGroupSerial)++;
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char ssn[SSN_LENGTH]; // Buffer for SSN
    int totalCount = 0;
    int invalidCount = 0;
    int invalidFormatCount = 0;
    int duplicateCount = 0;
    int invalidStartCount = 0;
    int invalidGroupSerialCount = 0;

    // Initialize hash table
    Entry *hashTable[HASH_SIZE] = {NULL};

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
        totalCount++;

        // Check for duplicates
        if (isDuplicate(ssn, hashTable)) {
            duplicateCount++;
            invalidCount++;
            continue;
        }

        // Validate SSN format and content
        if (!isValidSSN(ssn, &invalidFormatCount, &invalidStartCount, &invalidGroupSerialCount)) {
            invalidCount++;
        }
    }

    fclose(file);

    // Free hash table memory
    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *current = hashTable[i];
        while (current != NULL) {
            Entry *next = current->next;
            free(current);
            current = next;
        }
    }

    // Print the results
    printf("Total SSNs processed: %d\n", totalCount);
    printf("Invalid SSNs: %d\n", invalidCount);
    printf("Invalid format: %d\n", invalidFormatCount);
    printf("Duplicate SSNs: %d\n", duplicateCount);
    printf("SSNs starting with 9 or 666/000: %d\n", invalidStartCount);
    printf("Invalid group/serial numbers: %d\n", invalidGroupSerialCount);

    return 0;
}
