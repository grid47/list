
+++
authors = ["grid47"]
title = "Leetcode 2811: Check if it is Possible to Split Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2811: Check if it is Possible to Split Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BVkYLy-gzcg"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/BVkYLy-gzcg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        for (int i = 0; i < nums.size() - 1; ++i)
            if (nums[i] + nums[i + 1] >= m)
                return true;
        return nums.size() < 3;        
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an array `nums` of integers and an integer `m`. The task is to determine if it is possible to split the array into two non-empty subarrays such that the sum of the two consecutive elements at any position is greater than or equal to `m`. 

The array `nums` must be split such that at least one pair of consecutive elements in the array has a sum greater than or equal to `m`. Additionally, the array should have at least 2 elements to form a valid split.

Your goal is to return `true` if such a split is possible, otherwise return `false`.

### Approach

To solve the problem, we need to verify whether there exists any pair of consecutive elements in the array `nums` such that their sum is greater than or equal to `m`. If we find such a pair, we can immediately conclude that a valid split is possible, and we return `true`.

We can break down the approach as follows:

1. **Check Consecutive Elements**:
   - Start iterating over the array from the first element.
   - For each pair of consecutive elements `nums[i]` and `nums[i + 1]`, check if their sum is greater than or equal to `m`.
   - If any such pair is found, we can return `true` immediately, because we have found a valid split.
   
2. **Edge Case**:
   - If the array has fewer than 3 elements, it is always possible to split it (since there are not enough elements to make a meaningful split), so we directly return `true` in this case.

3. **Return False if No Valid Pair is Found**:
   - If no pair of consecutive elements has a sum greater than or equal to `m`, and the array contains 3 or more elements, we return `false`.

### Code Breakdown (Step by Step)

1. **Function Definition**:
   ```cpp
   bool canSplitArray(vector<int>& nums, int m) {
   ```
   - This function `canSplitArray` takes a vector `nums` (the input array) and an integer `m` as input, and it returns a boolean value indicating whether a valid split is possible.

2. **Iterate Through the Array**:
   ```cpp
   for (int i = 0; i < nums.size() - 1; ++i)
   ```
   - We loop through the array starting from the first element, checking each pair of consecutive elements. The loop runs from `i = 0` to `i = nums.size() - 2` (because we're comparing `nums[i]` with `nums[i + 1]`).

3. **Check if Pair Sum is Greater Than or Equal to `m`**:
   ```cpp
   if (nums[i] + nums[i + 1] >= m)
       return true;
   ```
   - For each consecutive pair, we check if their sum is greater than or equal to `m`. If the condition is satisfied, we immediately return `true`, indicating that the array can be split at that point.

4. **Handle Small Arrays**:
   ```cpp
   return nums.size() < 3;
   ```
   - If no valid split was found during the loop, we check if the array has fewer than 3 elements. In such cases, we return `true`, because arrays with fewer than 3 elements can always be trivially split.
   
5. **Return False**:
   - If no consecutive pair sums to a value greater than or equal to `m`, and the array has 3 or more elements, we return `false`.

### Complexity

1. **Time Complexity**:
   - The time complexity is **O(n)**, where `n` is the size of the input array `nums`. We only need to iterate over the array once to check the consecutive pairs. Each iteration involves a constant-time sum and comparison operation, which means the overall time complexity is linear in the size of the input.

2. **Space Complexity**:
   - The space complexity is **O(1)**, because the algorithm uses only a fixed amount of additional space (for variables like `i` and `m`). The input array `nums` is processed in-place, and we do not use any extra data structures that depend on the size of the input.

### Conclusion

The solution to this problem is straightforward and efficient. By iterating through the array and checking consecutive pairs, we can determine if there is a valid split based on the sum of adjacent elements. If no such pair exists and the array has more than 2 elements, the answer is `false`. However, if the array has fewer than 3 elements or if a valid pair is found, the answer is `true`.

The time complexity of **O(n)** ensures that this approach is scalable even for large arrays, and the space complexity of **O(1)** makes the solution very efficient in terms of memory usage. This solution is optimal for solving the problem within the given constraints and ensures that we do not perform unnecessary computations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

---
{{< youtube BVkYLy-gzcg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
