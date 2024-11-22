
+++
authors = ["grid47"]
title = "Leetcode 1680: Concatenation of Consecutive Binary Numbers"
date = "2024-05-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1680: Concatenation of Consecutive Binary Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1ZtYzuWUFwA"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/1ZtYzuWUFwA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod = (int) 1e9 + 7;
        
        long ans = 0;
        int len = 0;
        for(int i = 1; i <= n; i++) {
            if(__builtin_popcount(i) == 1) len++;
            
            ans = ((ans << len) % mod + i % mod) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to compute the concatenated binary representation of the numbers from 1 to \( n \). Specifically, we need to concatenate the binary representations of these numbers, treating the entire sequence as a single binary number, and return its value modulo \( 10^9 + 7 \). 

For example, if \( n = 3 \), the binary representations are:
- 1 → `1`
- 2 → `10`
- 3 → `11`

Concatenating these gives `11011`, which is equal to \( 27 \) in decimal.

### Approach

To solve the problem efficiently, we use the following approach:

1. **Modulo Definition**: We define a modulo value as \( 10^9 + 7 \) to ensure our calculations remain manageable and to meet the problem's constraints.

2. **Initialization**: We initialize a variable `ans` to hold our concatenated result, starting from 0, and a variable `len` to track the length of the binary representation of each number.

3. **Iterate from 1 to \( n \)**:
   - For each number \( i \), we check if it is a power of two using the `__builtin_popcount` function, which counts the number of set bits (1s) in the binary representation. If a number has only one set bit, it is a power of two, and thus its binary representation's length will increase.
   - We then update `ans` by shifting it left by `len` bits (to make space for the new number) and adding the current number \( i \) to `ans`, ensuring all operations are performed under modulo \( 10^9 + 7 \).

4. **Return the Result**: After processing all numbers up to \( n \), we return `ans`, which now contains the desired value.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the implementation:

```cpp
class Solution {
public:
    int concatenatedBinary(int n) {
```
- **Class Definition**: We define a class named `Solution` and create a public method `concatenatedBinary`, which takes an integer \( n \) as its parameter.

```cpp
        int mod = (int) 1e9 + 7;
```
- **Modulo Definition**: We define a variable `mod` set to \( 10^9 + 7 \). This helps in preventing integer overflow and ensures that we return the result within the specified limits.

```cpp
        long ans = 0;
        int len = 0;
```
- **Initialization**: We initialize `ans` as a long integer to accumulate our result without overflow. We also initialize `len` to keep track of the length of the binary representation.

```cpp
        for(int i = 1; i <= n; i++) {
```
- **Iteration**: We start a loop that iterates from 1 to \( n \), processing each integer.

```cpp
            if(__builtin_popcount(i) == 1) len++;
```
- **Power of Two Check**: For each integer \( i \), we check if it is a power of two by determining if it has exactly one set bit. If it does, we increment `len`, which reflects the increase in the length of binary representation.

```cpp
            ans = ((ans << len) % mod + i % mod) % mod;
```
- **Updating the Result**: We update `ans` by shifting it left by `len` bits to make space for the new number. We then add the current number \( i \) to this shifted value. All operations are performed under modulo \( 10^9 + 7 \) to ensure we don’t exceed the limits.

```cpp
        }
        return ans;
    }
};
```
- **Completion**: Once all numbers are processed, we return `ans`, which holds the concatenated binary value modulo \( 10^9 + 7 \).

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \) since we iterate through all numbers from 1 to \( n \), performing constant-time operations for each.
  
- **Space Complexity**: The space complexity is \( O(1) \) since we only use a few integer variables and do not utilize any data structures that scale with input size.

### Conclusion

This solution efficiently computes the concatenated binary representation of the numbers from 1 to \( n \) using bit manipulation and modular arithmetic. 

Key highlights include:

1. **Efficiency**: The approach runs in linear time, making it suitable even for large values of \( n \) within the constraints.

2. **Simplicity**: By leveraging the `__builtin_popcount` function, we can easily determine when to increment the length of our binary representation.

3. **Modular Arithmetic**: Ensuring that all operations are performed modulo \( 10^9 + 7 \) helps manage large numbers and fits within the problem's requirements.

Overall, the code presents a clean and effective solution to the problem, showcasing the power of bit manipulation in achieving optimal performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

---
{{< youtube 1ZtYzuWUFwA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
