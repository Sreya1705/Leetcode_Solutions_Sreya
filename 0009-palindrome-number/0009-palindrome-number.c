#include <stdbool.h>

bool isPalindrome(int x) {
    // Edge Case 1: Negative numbers are not palindromes (e.g., -121 reads as 121-)
    // Edge Case 2: Numbers ending in 0 are not palindromes, unless the number itself is 0
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;
    
    // Reverse the second half of the number
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + (x % 10);
        x /= 10;
    }

    // For even lengths (e.g., 1221): x will be 12, reversedHalf will be 12 -> x == reversedHalf
    // For odd lengths (e.g., 121): x will be 1, reversedHalf will be 12 -> x == reversedHalf / 10
    return x == reversedHalf || x == reversedHalf / 10;
}
