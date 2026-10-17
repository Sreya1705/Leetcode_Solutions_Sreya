#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    // 1. Allocate memory for 2 double values (Kelvin and Fahrenheit)
    double* result = (double*)malloc(2 * sizeof(double));
    
    // 2. Set the size of the returned array
    *returnSize = 2;
    
    // 3. Perform conversions
    result[0] = celsius + 273.15;
    result[1] = celsius * 1.80 + 32.00;
    
    return result;
}
