
+++
authors = ["grid47"]
title = "Leetcode 2369: Check if There is a Valid Partition For The Array"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2369: Check if There is a Valid Partition For The Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HywUcx60BRo"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/HywUcx60BRo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> nums, memo;
    
    bool dp(int idx) {
        if(idx == n) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
            if(dp(idx + 2)) return memo[idx] = true;
        }
        
        if(idx + 2 < n) {
            if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
                if(dp(idx + 3)) return memo[idx] = true;                
            }
            if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
                if(dp(idx + 3)) return memo[idx] =true;
            }
        }

        return memo[idx] = false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, -1);
        return dp(0);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine whether an array can be partitioned into one or more valid subarrays. Each subarray must either be:

1. **A pair** of equal elements.
2. **A triplet** of consecutive integers (e.g., [1, 2, 3]).

The function should return `true` if the array can be partitioned into valid subarrays and `false` otherwise.

### Approach

To solve this problem, we can employ **dynamic programming (DP)**, which is efficient for such partitioning problems. The key idea is to recursively check each position in the array and decide whether we can form a valid partition from that position onward.

Here are the main steps involved in solving the problem:

1. **Recursive Definition**: At each index `i`, we check if we can form a valid pair or triplet starting at index `i`.
2. **Memoization**: To avoid recomputing the results for the same index multiple times, we use memoization. This stores the results of previously computed subproblems, ensuring that each subproblem is solved only once.
3. **Base Case**: If we reach the end of the array, we return `true`, indicating that a valid partition is possible.
4. **Recursive Cases**: We check if the current index forms a valid pair or triplet, and recursively check the next indices accordingly.

### Code Breakdown (Step by Step)

1. **Class and Variables**:
    ```cpp
    class Solution {
    public:
        int n;
        vector<int> nums, memo;
    ```
    Here, `n` stores the size of the input array `nums`, and `memo` is a memoization vector used to store whether it is possible to partition the array starting from index `i`. The `nums` vector contains the input array.

2. **Base Case and Memoization Check**:
    ```cpp
    bool dp(int idx) {
        if(idx == n) return true;  // If we have reached the end, it's a valid partition
        
        if(memo[idx] != -1) return memo[idx];  // If the result for this index is already computed, return it
    ```
    The base case is when the index reaches the end of the array (`idx == n`). In this case, we return `true`, indicating that we've successfully partitioned the entire array.

    If `memo[idx]` is not `-1`, it means we've already computed the result for index `idx`, so we return that result to avoid redundant calculations.

3. **Recursive Case - Pair Check**:
    ```cpp
        if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
            if(dp(idx + 2)) return memo[idx] = true;  // If nums[idx] == nums[idx + 1], try partitioning from idx + 2
        }
    ```
    If the current index and the next index form a valid pair (i.e., `nums[idx] == nums[idx + 1]`), we recursively check the partition starting from `idx + 2` (because we used two elements for this partition).

4. **Recursive Case - Triplet Check**:
    ```cpp
        if(idx + 2 < n) {
            if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
                if(dp(idx + 3)) return memo[idx] = true;  // If nums[idx], nums[idx + 1], nums[idx + 2] are equal, try partitioning from idx + 3
            }
            if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
                if(dp(idx + 3)) return memo[idx] = true;  // If nums[idx], nums[idx + 1], nums[idx + 2] are consecutive integers, try partitioning from idx + 3
            }
        }
    ```
    Next, we check if the current index can form a valid triplet:
    - If the current index and the next two indices form a valid triplet (either all equal or consecutive integers), we recursively check the partition starting from `idx + 3`.

5. **Final Return**:
    ```cpp
        return memo[idx] = false;  // If no valid partition is found from idx, mark it as false and return
    }
    ```
    If none of the conditions for a valid pair or triplet are met, we return `false` for this index, indicating that no valid partition is possible starting from here.

6. **Main Function - validPartition**:
    ```cpp
    bool validPartition(vector<int>& nums) {
        this->nums = nums;  // Initialize nums with the input array
        n = nums.size();  // Initialize the size of the array
        memo.resize(n, -1);  // Initialize memoization vector with -1 (indicating not computed yet)
        return dp(0);  // Start the recursive partitioning from index 0
    }
    ```
    The `validPartition` function initializes the input array `nums` and its size `n`. It then initializes the `memo` vector with `-1` to indicate that no subproblems have been solved yet. The function then starts the recursive partitioning process from index `0` and returns the result.

### Complexity

1. **Time Complexity**:
    - Each state of the DP table is computed once. Since the `dp` function works with each index and checks a fixed number of conditions (pair and triplet), the overall time complexity is O(n), where `n` is the size of the input array `nums`.
    - The recursive calls only depend on the current index, and the memoization ensures that no index is processed more than once.
    
    Therefore, the time complexity is **O(n)**.

2. **Space Complexity**:
    - The space complexity is determined by the size of the `memo` vector and the recursion stack.
    - The `memo` vector has size `n`, and the recursion depth is at most `n` (in the worst case, we could call `dp` for every index).
    
    Thus, the space complexity is **O(n)**.

### Conclusion

This solution efficiently solves the problem using dynamic programming with memoization. The use of recursion and memoization allows us to avoid recomputing the result for the same index multiple times, reducing the overall time complexity to O(n). The solution handles both pairs and triplets of numbers (both equal and consecutive), ensuring that all valid partitions are considered. This approach is scalable for larger arrays, making it a robust solution for partitioning problems of this type.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

---
{{< youtube HywUcx60BRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
