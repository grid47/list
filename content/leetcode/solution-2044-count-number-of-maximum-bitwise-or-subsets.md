
+++
authors = ["grid47"]
title = "Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2044: Count Number of Maximum Bitwise-OR Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_wBj3IMV7tY"
youtube_upload_date="2024-10-18"
youtube_thumbnail="https://i.ytimg.com/vi/_wBj3IMV7tY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;
        int dp[1 << 17] = {1};
        dp[0] = 1;
        for(int a : nums) {
            for(int i = mx; i >= 0; i--) {
                dp[i | a] += dp[i];
            }
            mx |= a;
        }
        return dp[mx];
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the number of subsets within a given list of integers `nums` that, when combined using a bitwise OR operation, yield the maximum possible OR value obtainable from any subset of `nums`. Our goal is to efficiently calculate how many subsets of `nums` achieve this maximum OR value.

### Approach

To solve this, we use dynamic programming (DP) combined with bitwise operations. The bitwise OR operation compares each bit position in two integers, setting each bit in the result to 1 if either of the corresponding bits in the operands is 1. Using this approach, we aim to maximize the OR value across all possible subsets of `nums` and count how many subsets reach this maximum.

Here's a breakdown of the approach:

1. **Initialize Variables**: We define a variable `mx` to store the maximum OR value we can achieve, and a DP array `dp` where each entry `dp[i]` tracks the number of ways to reach a specific OR value `i`.
2. **Calculate Possible OR Values**: We iterate over each number in `nums`, updating the `dp` array to record all possible OR values and the number of ways to achieve each.
3. **Track Maximum OR Value**: As we iterate, we also keep updating `mx` to reflect the largest OR value obtained across subsets.
4. **Return Count of Maximum OR Subsets**: Finally, `dp[mx]` will contain the count of all subsets whose OR is equal to `mx`.

### Code Breakdown (Step by Step)

Let's break down each part of the code to understand how it implements this approach.

1. **Class and Method Definition**: We define the class `Solution` with the method `countMaxOrSubsets`, which takes a vector `nums` as input and returns an integer representing the count of subsets with the maximum OR value.

    ```cpp
    class Solution {
    public:
        int countMaxOrSubsets(vector<int>& nums) {
    ```

2. **Initialize Maximum OR Value (`mx`) and DP Array (`dp`)**: We start by defining an integer `mx`, which will hold the maximum OR value we achieve, and a DP array `dp` of size `1 << 17` (enough to hold OR values given the constraints). We initialize `dp[0]` to 1, representing the base case (empty subset).

    ```cpp
    int mx = 0;
    int dp[1 << 17] = {1};
    dp[0] = 1;
    ```

3. **Iterate Over Each Element in `nums`**: For each integer `a` in `nums`, we update the DP array to record all possible OR values we can obtain by including `a` in various subsets.

    ```cpp
    for(int a : nums) {
    ```

4. **Update DP Array**: For each element `a`, we iterate backward through the DP array from `mx` down to 0. For each index `i` in `dp`, `dp[i | a] += dp[i]` updates the count of subsets achieving the OR value `i | a` (which represents adding `a` to the subset represented by `i`).

    ```cpp
        for(int i = mx; i >= 0; i--) {
            dp[i | a] += dp[i];
        }
    ```

5. **Update Maximum OR Value**: After processing each element, we update `mx` to reflect the cumulative maximum OR value achievable with the current subset of `nums`.

    ```cpp
        mx |= a;
    ```

6. **Return Result**: After processing all elements, `dp[mx]` will contain the number of subsets with the maximum OR value `mx`. We return this value.

    ```cpp
        return dp[mx];
    }
    ```

### Complexity Analysis

- **Time Complexity**: The time complexity is \(O(n \cdot 2^{\text{max_bits}})\), where `n` is the number of elements in `nums`, and `max_bits` represents the bit width necessary to cover all potential OR results given the constraints. Since we iterate over each element in `nums` and process a limited range of OR values for each, the complexity is feasible within the problem constraints.
- **Space Complexity**: The space complexity is \(O(2^{\text{max_bits}})\) due to the DP array `dp`, which stores the counts of each possible OR result up to `1 << max_bits`.

### Conclusion

This solution uses a clever combination of dynamic programming and bitwise operations to efficiently find the count of subsets achieving the maximum OR value for any list of integers `nums`. By keeping track of possible OR values with a DP array, the code ensures that all possible subsets are accounted for without explicitly generating them. The result is a highly optimized solution that leverages the power of bitwise operations for an efficient count of maximum OR subsets. This approach demonstrates an effective way to handle subset generation problems with specific bitwise criteria.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/description/)

---
{{< youtube _wBj3IMV7tY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
