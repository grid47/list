
+++
authors = ["grid47"]
title = "Leetcode 2401: Longest Nice Subarray"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2401: Longest Nice Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DJYpUQy3iME"
youtube_upload_date="2022-09-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/DJYpUQy3iME/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 1, AND = 0, n = nums.size(), j = 0;
        for(int i = 0; i < n; i++) {
            while(((AND & nums[i]) > 0)) {
                AND ^= nums[j++];
            }
            AND |= nums[i];
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

We are given an array `nums` of integers, and our task is to find the length of the longest subarray where all the elements have no common bits set to `1`. In other words, for every pair of elements in the subarray, their bitwise `AND` operation should result in `0`. We need to find the length of the largest such subarray in the given array.

A subarray is a contiguous portion of the array, and we are allowed to iterate over the array to determine this subarray's maximum length that satisfies the given condition.

### Approach

This problem requires us to find the longest contiguous subarray where the bitwise `AND` of all elements is `0`. To solve this efficiently, we can leverage the sliding window technique along with bitwise operations.

#### Key Concepts:
- **Bitwise AND**: The `AND` operation compares the corresponding bits of two numbers and returns `1` if both bits are `1`, otherwise returns `0`. For a subarray to satisfy the condition, all pairs of numbers within the subarray must not share any common `1` bits. In other words, the `AND` operation between any two numbers in the subarray should be `0`.
  
- **Sliding Window**: This approach helps in checking subarrays efficiently without recalculating for overlapping parts of subarrays. We will maintain a window (`[j, i]`) where the condition is satisfied, and the length of the subarray can be derived by calculating `i - j + 1`.

#### Plan:
1. **Initialize Variables**:
   - `res`: Stores the length of the longest valid subarray found so far.
   - `AND`: Keeps track of the bitwise `AND` of elements in the current subarray.
   - `j`: The left boundary of the sliding window.
   - `n`: The size of the array `nums`.
   
2. **Sliding Window Loop**:
   - Iterate through the array using the index `i`.
   - At each step, check if the current element (`nums[i]`) can be added to the subarray starting at index `j` without violating the condition (i.e., the `AND` of the entire subarray remains `0`).
   - If the `AND` of the subarray becomes non-zero (i.e., sharing common `1` bits), increment `j` to shrink the window from the left until the subarray becomes valid again.
   
3. **Update Maximum Length**:
   - For each position `i`, calculate the length of the valid subarray as `i - j + 1`.
   - Update `res` if this length is greater than the current `res`.

4. **Return Result**: At the end of the iteration, `res` will hold the length of the longest valid subarray.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int res = 1, AND = 0, n = nums.size(), j = 0;
```
- `res`: Initialized to `1` since the minimum length of a valid subarray is `1`.
- `AND`: Stores the bitwise `AND` of all the numbers in the current sliding window. Initially set to `0`.
- `n`: The length of the array `nums`.
- `j`: The starting index of the sliding window.

#### Step 2: Iterate Over the Array

We use a for loop to iterate through the array, where `i` represents the right boundary of the current subarray.

```cpp
for (int i = 0; i < n; i++) {
```

#### Step 3: Adjust the Left Boundary of the Window

If adding `nums[i]` to the current subarray causes the `AND` of the subarray to become non-zero (indicating that there are common `1` bits between the elements in the window), we adjust the left boundary of the window by incrementing `j`. This ensures that the subarray remains valid, i.e., its `AND` is zero.

```cpp
while(((AND & nums[i]) > 0)) {
    AND ^= nums[j++];
}
```
- The condition `((AND & nums[i]) > 0)` checks if there are common `1` bits between the current `AND` and `nums[i]`.
- If the condition is true, we remove elements from the left side of the window by incrementing `j` and adjusting `AND` accordingly with the XOR operation.

#### Step 4: Update the `AND` Value

Once we have a valid subarray (i.e., the `AND` of all elements in the window is `0`), we include the current element `nums[i]` in the `AND`.

```cpp
AND |= nums[i];
```
- This operation sets the `AND` to include the bits of the current element `nums[i]`.

#### Step 5: Calculate the Length of the Current Subarray

We then calculate the length of the current subarray by computing `i - j + 1` and update `res` if the new length is greater than the current longest valid subarray length.

```cpp
res = max(res, i - j + 1);
```
- This updates `res` with the maximum length found so far.

#### Step 6: Return the Result

Once the loop completes, we return `res`, which now holds the length of the longest subarray where all elements have no common bits set to `1`.

```cpp
return res;
```

### Complexity

#### Time Complexity

- The loop iterates through the array once, and for each element, the inner `while` loop ensures that each element is processed at most twice (once when added to the window and once when removed). Therefore, the total time complexity is **O(n)**, where `n` is the length of the array `nums`.

#### Space Complexity

- The space complexity is **O(1)** since we only use a few extra variables (`res`, `AND`, `j`, and `n`) that do not depend on the size of the input array. The algorithm operates in constant space outside the input array.

### Conclusion

This solution uses the sliding window technique with bitwise operations to efficiently find the longest subarray where no two elements share a common `1` bit. By maintaining the `AND` of the current window and adjusting the window's left boundary whenever the `AND` becomes non-zero, the algorithm ensures that the subarray is valid. The solution runs in **O(n)** time with **O(1)** space, making it optimal for large arrays.

Key Takeaways:
- The sliding window technique is applied to efficiently find the longest valid subarray.
- Bitwise operations, specifically the `AND` operation, are used to check if elements in the subarray share common `1` bits.
- The algorithm is both time-efficient (O(n)) and space-efficient (O(1)), making it suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-nice-subarray/description/)

---
{{< youtube DJYpUQy3iME >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
