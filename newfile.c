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
bool validateSSN(const char *ssn, int *rule1, int *rule3, int *rule4, int *rule5, int *rule6, int *rule7) {
    // Rule 1: Check format XXX-XX-XXXX
    if (strlen(ssn) != 11 || ssn[3] != '-' || ssn[6] != '-') {
        (*rule1)++;
        return false;
    }

    // Extract parts of the SSN
    char area[4], group[3], serial[5];
    strncpy(area, ssn, 3);
    area[3] = '\0';
    strncpy(group, ssn + 4, 2);
    group[2] = '\0';
    strncpy(serial, ssn + 7, 4);
    serial[4] = '\0';

    bool isValid = true;

    // Rule 3: Check if it begins with '9'
    if (area[0] == '9') {
        (*rule3)++;
        isValid = false;
    }

    // Rule 4: Check if it begins with '666'
    if (strcmp(area, "666") == 0) {
        (*rule4)++;
        isValid = false;
    }

    // Rule 5: Check if it begins with '000'
    if (strcmp(area, "000") == 0) {
        (*rule5)++;
        isValid = false;
    }

    // Rule 6: Check if positions 4-5 are '00'
    if (strcmp(group, "00") == 0) {
        (*rule6)++;
        isValid = false;
    }

    // Rule 7: Check if positions 6-9 are '0000'
    if (strcmp(serial, "0000") == 0) {
        (*rule7)++;
        isValid = false;
    }

    return isValid;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char ssn[SSN_LENGTH];
    int totalCount = 0;
    int invalidCount = 0;
    int rule1Count = 0;  // Format rule
    int duplicateCount = 0; // Duplicate rule
    int rule3Count = 0;  // Begins with '9'
    int rule4Count = 0;  // Begins with '666'
    int rule5Count = 0;  // Begins with '000'
    int rule6Count = 0;  // Group '00'
    int rule7Count = 0;  // Serial '0000'

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

        // Rule 2: Check for duplicates
        if (isDuplicate(ssn, hashTable)) {
            duplicateCount++;
            invalidCount++;
            continue;
        }

        // Check other rules
        if (!validateSSN(ssn, &rule1Count, &rule3Count, &rule4Count, &rule5Count, &rule6Count, &rule7Count)) {
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
    printf("Total invalid SSNs: %d\n", invalidCount);
    printf("Rule 1 - Invalid format (XXX-XX-XXXX): %d\n", rule1Count);
    printf("Rule 2 - Duplicate SSNs: %d\n", duplicateCount);
    printf("Rule 3 - Begins with '9': %d\n", rule3Count);
    printf("Rule 4 - Begins with '666': %d\n", rule4Count);
    printf("Rule 5 - Begins with '000': %d\n", rule5Count);
    printf("Rule 6 - Group number is '00': %d\n", rule6Count);
    printf("Rule 7 - Serial number is '0000': %d\n", rule7Count);

    return 0;
}
