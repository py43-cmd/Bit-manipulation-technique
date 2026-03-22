# Bit-manipulation-technique
# 🎯 Bit Manipulation Technique Template

A comprehensive C++ template repository for mastering **bit manipulation** and **contribution technique** used in competitive programming (Codeforces, AtCoder, LeetCode, etc.).

## 📚 Table of Contents

1. [Overview](#overview)
2. [Core Bit Manipulation Techniques](#core-bit-manipulation-techniques)
3. [Contribution Technique](#contribution-technique)
4. [Advanced Topics](#advanced-topics)
5. [Files Structure](#files-structure)
6. [Quick Start](#quick-start)
7. [Problem Examples](#problem-examples)
8. [Time Complexity Comparison](#time-complexity-comparison)

---

## 🔍 Overview

This repository contains **production-ready C++ code** for:
- ✅ **8 Core Bit Manipulation Techniques**
- ✅ **Contribution Technique** (O(n) solutions)
- ✅ **Codeforces-optimized templates**
- ✅ **Real problem examples with explanations**
- ✅ **Competitive programming best practices**

**Constraint:** Works best for problems with `n ≤ 10^6`

---

## 🔢 Core Bit Manipulation Techniques

### 1. Bitmask DP
**Use When:** Small constraints (n ≤ 20), need subset states

```cpp
// TSP: dp[mask][i] = min cost to visit cities in mask, ending at i
dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + cost[i][j]);
```

**Problems:** Traveling Salesman, Assignment Problem, Hamiltonian Path

---

### 2. Subset Enumeration
**Use When:** Need to generate all 2^n subsets

```cpp
// Iterate all subsets of mask
for(int submask = mask; ; submask = (submask - 1) & mask) {
    // Process submask
    if(submask == 0) break;
}
```

**Time:** O(3^n) for all subsets

---

### 3. XOR Tricks
**Key Properties:**
- `a ^ a = 0`
- `a ^ 0 = a`
- `a ^ b = b ^ a` (commutative)

**Problems:**
- Find single number in array (others appear twice)
- Find two missing numbers
- Maximum XOR pair

```cpp
// Find single number
int result = 0;
for(int x : arr) result ^= x;
```

---

### 4. Bit Counting (Popcount)
**Methods:**

```cpp
// Kernighan's Algorithm - O(k) where k = set bits
int countBits(int n) {
    int count = 0;
    while(n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

// Built-in - O(1)
int count = __builtin_popcount(n);
```

---

### 5. Greedy with Bits (MSB to LSB)
**Use When:** Maximizing/minimizing bit-based values

```cpp
// Build maximum value greedily from MSB
int result = 0;
for(int i = 31; i >= 0; i--) {
    int temp = result | (1 << i);
    if(isPossible(temp)) result = temp;
}
```

---

### 6. Trie-Based Bit Problems
**Use When:** Multiple maximum XOR queries

```cpp
struct TrieNode {
    TrieNode* child[2];
};

// Insert: O(32)
// Query max XOR: O(32)
// Better than O(n^2) with many queries
```

---

### 7. Segment Trees with Bits
**Use When:** Range OR/AND queries

```cpp
// Segment tree node stores OR of range
tree[node] = tree[2*node] | tree[2*node+1];
```

---

### 8. Meet in the Middle
**Use When:** n ≤ 40 (too large for 2^n)

```cpp
// Complexity: O(2^(n/2)) instead of O(2^n)
// Generate first half: O(2^(n/2))
// Process second half: O(2^(n/2))
// Combine: O(2^(n/2))
```

---

## 🎓 Contribution Technique

**Core Idea:** Calculate contribution of each element instead of iterating all operations

**Formula:** `Answer = Σ (element × contribution_factor)`

### Problem 1: Sum of All Subarrays

**Naive:** O(n²)
```cpp
for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
        subarray_sum += arr[j];
    }
}
```

**Contribution:** O(n)
```cpp
for(int i = 0; i < n; i++) {
    long long left = i + 1;      // subarrays starting before/at i
    long long right = n - i;     // subarrays ending at/after i
    answer += arr[i] * left * right;
}
```

**Example:** arr = [1, 2, 3]
- Element 1: 1 × 1 × 3 = 3
- Element 2: 2 × 2 × 2 = 8
- Element 3: 3 × 3 × 1 = 9
- **Total = 20**

---

### Problem 2: Sum of AND in All Subarrays

**Approach:** For each bit, count subarrays where bit remains 1

```cpp
for(int bit = 0; bit < 30; bit++) {
    long long count = 0;
    long long consecutive = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] & (1 << bit)) {
            consecutive++;
        } else {
            count += consecutive * (consecutive + 1) / 2;
            consecutive = 0;
        }
    }
    count += consecutive * (consecutive + 1) / 2;
    
    answer += count * (1 << bit);
}
```

**Time:** O(n × 30)

---

### Problem 3: Sum of XOR of All Pairs

**Approach:** For each bit, count pairs with different bits

```cpp
for(int bit = 0; bit < 30; bit++) {
    long long zeros = 0, ones = 0;
    
    for(int x : arr) {
        if(x & (1 << bit)) ones++;
        else zeros++;
    }
    
    // Pairs with different bits contribute to this position
    answer += zeros * ones * (1LL << bit);
}
```

**Time:** O(n × 30)

---

### Problem 4: Sum of Minimum in All Subarrays

**Approach:** Use monotonic stack to find boundaries where element is minimum

```cpp
stack<int> st;
for(int i = 0; i < n; i++) {
    while(!st.empty() && arr[st.top()] >= arr[i]) {
        int idx = st.top();
        st.pop();
        
        int left = st.empty() ? -1 : st.top();
        int right = i;
        
        long long leftCount = idx - left;
        long long rightCount = right - idx;
        
        answer += arr[idx] * leftCount * rightCount;
    }
    st.push(i);
}
```

**Time:** O(n)

---

## 🚀 Advanced Topics

### Bitmask DP Applications
- Traveling Salesman Problem (TSP)
- Set Cover Problem
- Hamiltonian Path/Cycle
- Steiner Tree

### Contribution in Complex Problems
- Segment trees with contributions
- Square root decomposition with bits
- Persistent data structures

### Optimization Tricks
- Early termination in bit processing
- SIMD vectorization for popcount
- Cache-friendly bit operations

---

## 📁 Files Structure

```
bit-manipulation-technique-template/
├── README.md                              (This file)
├── contribution_technique_basics.cpp      (Sum of subarrays)
├── contribution_bit_manipulation.cpp      (AND/OR contributions)
├── contribution_xor_problems.cpp          (XOR problems)
├── contribution_advanced_problems.cpp     (Min/Max with stack)
└── examples/
    ├── tsp_bitmask_dp.cpp
    ├── max_xor_trie.cpp
    ├── subset_enumeration.cpp
    └── meet_in_middle.cpp
```

---

## ⚡ Quick Start

### Compile and Run

```bash
# Compile contribution_technique_basics.cpp
g++ -o basics contribution_technique_basics.cpp -std=c++17

# Run
./basics
```

### Output
```
Array: 1 2 3
Naive Approach Result: 20
Contribution Technique Result: 20
```

---

## 📝 Problem Examples

### Example 1: Sum of Subarrays
**Input:** [1, 2, 3]
**Output:** 20

**Explanation:**
- [1] = 1
- [2] = 2
- [3] = 3
- [1,2] = 3
- [2,3] = 5
- [1,2,3] = 6
- Total = 20

### Example 2: Sum of AND
**Input:** [5, 3, 7]
**Output:** 5 + 3 + 7 + 1 + 3 + 1 = 20

### Example 3: Sum of XOR Pairs
**Input:** [1, 2, 3]
**Output:** (1^2) + (1^3) + (2^3) = 3 + 2 + 1 = 6

---

## 📊 Time Complexity Comparison

| Problem | Naive | Optimized | Technique |
|---------|-------|-----------|-----------|
| Sum of subarrays | O(n³) | O(n) | Contribution |
| Sum of AND | O(n²×30) | O(n×30) | Bit contribution |
| Sum of XOR pairs | O(n²) | O(n×30) | Bit pairing |
| Sum of min | O(n²) | O(n) | Monotonic stack |
| TSP | - | O(2^n × n²) | Bitmask DP |
| Max XOR | O(n²) | O(32×n) | Trie |

---

## 🎯 Learning Path

**Beginner:**
1. Read contribution_technique_basics.cpp
2. Understand element contribution formula
3. Practice sum of subarrays problems

**Intermediate:**
1. Learn bit contribution (AND/OR)
2. Study XOR trick problems
3. Implement monotonic stack approach

**Advanced:**
1. Bitmask DP for state compression
2. Meet in the middle optimization
3. Trie-based bit problems

---

## 🔗 Resources

**Codeforces Problems:**
- [Educational DP](https://codeforces.com/edu/course/2)
- [Bit Manipulation](https://codeforces.com/blog/entry/45897)

**Practice Platforms:**
- Codeforces
- AtCoder
- LeetCode
- HackerRank

---

## 💡 Tips & Tricks

1. **Always check bit limits:** Use `long long` for overflow
2. **Test with small inputs:** Verify correctness before optimization
3. **Use __builtin functions:** Faster than manual counting
4. **Precompute powers of 2:** Avoid repeated calculations
5. **Draw bit diagrams:** Visualize bit operations

---

## 📌 Common Mistakes

❌ Using `int` instead of `long long` (overflow)
❌ Forgetting to handle bit position 31 (sign bit)
❌ Not considering 0 in bit counting
❌ Incorrect monotonic stack logic
❌ Off-by-one errors in subarray boundaries

---

## 🤝 Contributing

Feel free to:
- Add more examples
- Optimize existing code
- Fix bugs
- Add new techniques
- Improve documentation

---

## 📄 License

Open source - Free to use and modify

---

## 👨‍💻 Author

Created for competitive programming enthusiasts

**Last Updated:** 2026-03-22

---

## ❓ FAQ

**Q: When should I use contribution technique?**
A: When you need to optimize from O(n²) to O(n) by calculating each element's impact.

**Q: What's the difference between AND and OR contribution?**
A: AND: element contributes only in subarrays where ALL elements have the bit set
   OR: element contributes in ANY subarray containing it

**Q: Can I use bitmask DP for n > 20?**
A: No, 2^20 ≈ 1 million is the practical limit. Use meet-in-middle for n ≤ 40.

---

**Happy Coding! 🚀**
