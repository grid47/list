
+++
authors = ["grid47"]
title = "Leetcode 2917: Find the K-or of an Array"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2917: Find the K-or of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jNPKX6McyCg"
youtube_upload_date="2023-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jNPKX6McyCg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0; // Initialize the answer to 0.
        
        for (int i = 0; i < 31; i++) {
            // Bit position represented by 2^i.
            int rep = (1 << i); 
            int cnt = 0; // Initialize a counter to count set bits at this position.

            // Iterate through the input vector 'nums'.
            for (auto ele : nums) {
                if (rep & ele) {
                    // If the i-th bit is set in 'ele', increment the count.
                    cnt++;
                }
            }

            // If the count of set bits at this position is greater than or equal to 'k', set the corresponding bit in the answer.
            if (cnt >= k) {
                ans = ans | rep;
            }
        }

        return ans; // Return the final answer, which is the result of the OR operation on selected bits.
    }
};
{{< /highlight >}}
---

### Problem Statement
Given an array of integers `nums`, and an integer `k`, we are to find the bitwise OR of all the numbers in the array that have a bit set at a particular position (indexed from `0` to `30` assuming a 32-bit integer). For each bit position, if the count of numbers with that bit set is greater than or equal to `k`, we will set that bit in the result. The goal is to return the result after performing this bitwise operation for all positions.

### Approach

The core approach here revolves around bitwise operations, specifically bitwise OR (`|`), which combines bits in a manner where the bit is set if either of the corresponding bits in the operands is set. We can break down the problem into smaller steps:

1. **Iterate Over Bit Positions**:
   - We need to check each bit from position `0` to `30` (assuming we are dealing with 32-bit integers, which is typically sufficient for most practical applications).
   
2. **Count the Set Bits**:
   - For each bit position `i`, we count how many numbers in the array `nums` have that bit set. This is done by checking if the number ANDed with `2^i` (which isolates the `i`-th bit) is non-zero.

3. **Decision on Setting the Bit in the Result**:
   - If the count of set bits at position `i` is greater than or equal to `k`, we set that bit in the result. We achieve this by using the bitwise OR (`|`) operation on the result.

4. **Final Result**:
   - After iterating through all the bit positions, the final result will contain the OR-ed values of the selected bits.

### Code Breakdown (Step by Step)

#### 1. Initialize Variables

The code starts by initializing `ans` to `0`. This variable will hold the final result after performing the OR operation on all selected bits.

```cpp
int ans = 0; // Initialize the answer to 0.
```

Here, `ans` is the cumulative result of the OR operation across all bits that satisfy the given condition.

#### 2. Loop Over All Bit Positions

The next step involves iterating through each bit position from `0` to `30`. This is achieved by using a loop that runs for 31 iterations.

```cpp
for (int i = 0; i < 31; i++) {
```

In each iteration, the `i`-th bit position of each number in the array will be checked.

#### 3. Set the Current Bit for Comparison

Within the loop, the code calculates the `rep` variable, which represents the value of `2^i`. This is the bit mask that isolates the `i`-th bit of any number. The bitwise shift operator (`<<`) is used to compute `2^i`.

```cpp
int rep = (1 << i); // Bit position represented by 2^i.
```

#### 4. Count Set Bits at the Current Bit Position

Next, we initialize a counter `cnt` to `0`. This counter will be used to count how many numbers in the array have the `i`-th bit set. The code iterates over each number in the array, checking if the `i`-th bit is set by performing a bitwise AND operation with `rep`.

```cpp
int cnt = 0; // Initialize a counter to count set bits at this position.

for (auto ele : nums) {
    if (rep & ele) {
        // If the i-th bit is set in 'ele', increment the count.
        cnt++;
    }
}
```

In the inner loop, for each number `ele`, the condition `rep & ele` checks whether the `i`-th bit of `ele` is set. If it is, the counter `cnt` is incremented.

#### 5. Set the Bit in the Result

Once the count `cnt` for the current bit position is determined, the next step is to check if `cnt >= k`. If this condition is true, it means that enough numbers have the `i`-th bit set, and we should set this bit in the result `ans`. The bitwise OR operation `ans = ans | rep` is used to set the corresponding bit in the answer.

```cpp
if (cnt >= k) {
    ans = ans | rep;
}
```

This ensures that if at least `k` numbers have the `i`-th bit set, the `i`-th bit in the result will be set.

#### 6. Return the Final Answer

After completing all 31 iterations (for all possible bit positions), the final result stored in `ans` is returned.

```cpp
return ans; // Return the final answer, which is the result of the OR operation on selected bits.
```

### Complexity Analysis

1. **Time Complexity**:
   - The outer loop runs for `31` iterations (since we are considering the bit positions from `0` to `30`).
   - The inner loop iterates over all `n` elements in the `nums` array. Thus, the time complexity is `O(31 * n)` or simplified as `O(n)`, where `n` is the number of elements in the array.
   - Since `31` is a constant, the time complexity can be considered linear, `O(n)`.

2. **Space Complexity**:
   - The space complexity is `O(1)`, as the only extra space used is for a few integer variables (`ans`, `rep`, `cnt`, etc.), which do not depend on the input size `n`.

### Conclusion

The solution is an efficient approach to solving the problem using bitwise operations. By iterating over each bit position and counting how many numbers in the array have that bit set, we can dynamically decide which bits to set in the result. This method leverages the power of bit manipulation, which is both time-efficient and space-efficient for large input arrays.

The approach is particularly useful in scenarios where we need to evaluate conditions based on specific bit positions across multiple numbers, making it a common technique in problems related to bitwise operations. The time complexity of `O(n)` ensures that the solution scales well even for large input sizes, making it a good choice for competitive programming or real-world applications involving bitwise operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-k-or-of-an-array/description/)

---
{{< youtube jNPKX6McyCg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
