#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen index of each ASCII character
    // Initialized to -1 because 0 is a valid string index
    int lastSeen[128];
    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }

    int maxLength = 0;
    int start = 0; // Left pointer of the sliding window

    // Iterate through the string with the right pointer 'end'
    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char currentChar = s[end];

        // If the character was seen before AND its last recorded index 
        // falls within our current sliding window range
        if (lastSeen[currentChar] >= start) {
            // Shrink the window by moving 'start' just past the previous duplicate
            start = lastSeen[currentChar] + 1;
        }

        // Update the last seen position of the character
        lastSeen[currentChar] = end;

        // Calculate the current window size and update max length if it's larger
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}
