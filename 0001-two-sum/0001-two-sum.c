#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 1. Allocate memory for the result array containing 2 indices
    int* result = (int*)malloc(2 * sizeof(int));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 2. Use nested loops to check every unique pair of elements
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // 3. If a pair sums to the target, save indices and return
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2; // Tell LeetCode the array size is 2
                return result;
            }
        }
    }

    // 4. Return NULL if no solution is found (though LeetCode guarantees one)
    *returnSize = 0;
    free(result);
    return NULL;
}
