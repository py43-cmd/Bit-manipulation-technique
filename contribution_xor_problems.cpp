// Contribution Technique - XOR Problems
#include <iostream>
#include <vector>
using namespace std;

/*
PROBLEM 1: Sum of XOR of all pairs
APPROACH: For each bit, count pairs where bits differ

If bit position has:
- 'zeros' elements with 0 at this bit
- 'ones' elements with 1 at this bit

Then pairs with different bits = zeros * ones
Contribution to answer = zeros * ones * (1 << bit)
*/

long long sumXORAllPairs(vector<int>& arr) {
    int n = arr.size();
    long long answer = 0;
    
    // For each bit position
    for(int bit = 0; bit < 30; bit++) {
        long long zeros = 0, ones = 0;
        
        // Count elements with 0 and 1 at this bit
        for(int i = 0; i < n; i++) {
            if(arr[i] & (1 << bit)) {
                ones++;
            } else {
                zeros++;
            }
        }
        
        // Pairs with different bits contribute to this position
        answer += zeros * ones * (1LL << bit);
    }
    
    return answer;
}

/*
PROBLEM 2: Sum of XOR of all subarrays
More complex - track XOR values and their frequencies
*/

long long sumXORAllSubarrays(vector<int>& arr) {
    int n = arr.size();
    long long answer = 0;
    
    // For each starting position
    for(int i = 0; i < n; i++) {
        int xor_val = 0;
        
        // For each ending position
        for(int j = i; j < n; j++) {
            xor_val ^= arr[j];
            answer += xor_val;
        }
    }
    
    return answer;
}

int main() {
    vector<int> arr = {1, 2, 3};
    
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    cout << "Sum of XOR of all pairs: " << sumXORAllPairs(arr) << endl;
    cout << "Sum of XOR of all subarrays: " << sumXORAllSubarrays(arr) << endl;
    
    return 0;
}
