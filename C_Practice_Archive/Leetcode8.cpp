#include <iostream>
using namespace std;

int isPowerOfTwo(int n) {
    if (n <= 0) return 0;  // Return 0 (false) for non-positive numbers
    if (n == 1) return 1;  // 1 is a power of two, return 1 (true)

    if (n % 2 == 0) {
        return isPowerOfTwo(n / 2);  // Recursively check for n/2
    }
    return 0;  // If n is not divisible by 2, return false (0)
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two.\n";
    } else {
        cout << n << " is not a power of two.\n";
    }

    return 0;
}
