/* Spring 24, Lab 4
	starter file to get started
Joanna Ni CPSC 1011 S24 
Section 1 Lab#4 2/13/24
 1 1
This program decrypts an encryped message within an array.
*/

#include <stdio.h>

int main() {
	int i, len;
	int advice[] = { 82, 116, 115, 106, 126, 32, 82, 102, 115, 102, 108, 106, 
		114, 106, 115, 121, 32, 89, 110, 117, 120, 32, 107, 116, 119, 32, 94, 
		116, 122, 115, 108, 32, 70, 105, 122, 113, 121, 120, 63, 32, 32, 54, 
		51, 32, 89, 119, 102, 104, 112, 32, 126, 116, 122, 119, 32, 110, 115, 
		104, 116, 114, 106, 32, 32, 55, 51, 32, 72, 119, 106, 102, 121, 106, 
		32, 103, 122, 105, 108, 106, 121, 32, 104, 102, 121, 106, 108, 116, 
		119, 110, 106, 120, 32, 32, 56, 51, 32, 71, 106, 32, 104, 102, 119, 
		106, 107, 122, 113, 32, 124, 110, 121, 109, 32, 120, 117, 106, 115, 
		105, 110, 115, 108, 32, 32, 57, 51, 32, 88, 102, 123, 106, 32, 110, 
		115, 121, 106, 115, 121, 110, 116, 115, 102, 113, 113, 126, 32, 32,
		58, 51, 32, 90, 120, 106, 32, 104, 119, 106, 105, 110, 121, 32, 104, 
		102, 119, 105, 120, 32, 124, 110, 120, 106, 113, 126, 32, 32, 59, 51, 
		32, 78, 115, 123, 106, 120, 121, 32, 106, 102, 119, 113, 126, 32, 102, 
		115, 105, 32, 116, 107, 121, 106, 115, 32, 32, 60, 51, 32, 71, 122, 110, 
		113, 105, 32, 122, 117, 32, 126, 116, 122, 119, 32, 119, 102, 110, 115, 
		126, 32, 105, 102, 126, 32, 107, 122, 115, 105, 32, 32, 61, 51, 32, 71, 
		106, 32, 114, 110, 115, 105, 107, 122, 113, 32, 116, 107, 32, 126, 116, 
		122, 119, 32, 105, 106, 103, 121, 50, 121, 116, 50, 110, 115, 104, 116, 
		114, 106, 32, 119, 102, 121, 110, 116 };

	// using sizeof, find size of array (length of string) for use when 
	// 	declaring new array that will hold the un-encrypted values
	len = sizeof(advice) / sizeof(advice[0]);

	// print encrypted message
	printf("\n\n");
	for (i = 0; i < len; i++) {
		printf("%c", advice[i]);
	}	
	
	// create new int array with un-encrypted values 
	printf("\n\n");
	
	int decoded[len];

	// print un-encrypted message from second array
	printf("\n\n");
	
	for (i = 0; i < len; i++) {
		if (advice[i] != 32) {
			//shifts advice[i] left 5 to get decoded
			decoded[i] = advice[i] - 5;
			//add new line if number-starting
			if (decoded[i] > 48 && decoded[i] < 57) {
				printf("\n%c", decoded[i]);
			} else {
				printf("%c", decoded[i]);
			}
		} else {
			printf("%c", 32);
		}
	}


	// print un-encrypted message reversing the case
	printf("\n\n");
	
	for (i = 0; i < len; i++) {
		if (decoded[i] >= 65 && decoded[i] <= 90){
			//upper to lower       decoded[i] += 32;
			printf("%c", decoded[i] + 32);
		} else if (decoded[i] >= 97 && decoded[i] <= 122) {
			//lower to upper       decoded[i] -= 32;
			printf("%c", decoded[i] - 32);
		} else {
			if (advice[i] != 32) {
				//add new line if number-starting
				if (decoded[i] > 48 && decoded[i] < 57) {
					printf("\n%c", decoded[i]);
				} else {
					printf("%c", advice[i] - 5);
				}
			} else {
				printf("%c", 32);
			}
		}
	}

	printf("\n\n");

	return 0;
}
