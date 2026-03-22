// C++ Bit Manipulation Examples and Techniques

#include <iostream>
using namespace std;

// Function to swap two numbers using bitwise XOR
void swap(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

// Function to check if a number is a power of 2
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

// Function to count the number of set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1; // Increment count if last bit is set
        n >>= 1; // Right shift n by 1
    }
    return count;
}

int main() {
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    int num = 16;
    cout << num << (isPowerOfTwo(num) ? " is a power of 2." : " is not a power of 2.") << endl;

    int setBits = countSetBits(num);
    cout << "Number of set bits in " << num << " : " << setBits << endl;

    return 0;
}
