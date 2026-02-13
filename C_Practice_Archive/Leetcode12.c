#include <stdio.h>  // Includes standard input-output functions

int mySqrt(int x) {
    if (x == 0 || x == 1) return x; // Handle small cases directly

    int left = 1, right = x, ans = 0; // Initialize left and right boundaries, and answer variable
    
    while (left <= right) { // Continue until the search space is valid
        int mid = left + (right - left) / 2; // Find middle element (avoids overflow of (left + right) / 2)

        if (mid <= x / mid) {  // Equivalent to mid * mid <= x, but avoids overflow
            ans = mid;         // Store potential answer
            left = mid + 1;    // Move to the right half (try for a larger value)
        } else {
            right = mid - 1;   // Move to the left half (mid is too large)
        }
    }
    return ans; // Return the largest integer whose square is ≤ x
}

int main() {
    int x = 8; // Example input
    printf("Square root of %d (floored) is: %d\n", x, mySqrt(x)); // Print result
    return 0; // End of program
}
