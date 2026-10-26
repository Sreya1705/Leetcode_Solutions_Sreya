#include <limits.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is the smaller array to optimize the binary search range to O(log(min(m, n)))
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0;
    int high = m;
    
    while (low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        // If partitionX is 0, nothing is on the left side for nums1. Use INT_MIN.
        // If partitionX is m, nothing is on the right side for nums1. Use INT_MAX.
        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        // Similarly for nums2
        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        // Check if we found the correct partition point
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            // If total number of elements is odd
            if ((m + n) % 2 != 0) {
                return (double)MAX(maxLeftX, maxLeftY);
            } 
            // If total number of elements is even
            else {
                return ((double)MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
            }
        } 
        // We are too far right in nums1, move left
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } 
        // We are too far left in nums1, move right
        else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}
