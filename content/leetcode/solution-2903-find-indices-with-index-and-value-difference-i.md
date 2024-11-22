
+++
authors = ["grid47"]
title = "Leetcode 2903: Find Indices With Index and Value Difference I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2903: Find Indices With Index and Value Difference I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "R731s1mHVWM"
youtube_upload_date="2023-10-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R731s1mHVWM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int idif, int vdif) {

        int mn = 0, mx = 0;
        for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
            mn = nums[mn] < nums[j] ? mn : j;
            mx = nums[mx] > nums[j] ? mx : j;
            if (abs(nums[i] - nums[mn]) >= vdif)
                return {mn, i};
            if (abs(nums[i] - nums[mx]) >= vdif)
                return {mx, i};
        }
        return {-1, -1};        

    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find two indices in the given array `nums` such that the absolute difference between the values at those indices is at least `vdif`, starting from the index `idif`. If such a pair of indices is found, return the indices. If no such pair exists, return `{-1, -1}`.

### Approach

The solution uses a two-pointer approach, where one pointer (`i`) iterates through the array starting from the `idif` index, and another pointer (`j`) tracks the minimum and maximum values seen up until the current index `i`. The goal is to identify if the difference between the current element `nums[i]` and either the minimum or maximum value encountered so far is greater than or equal to `vdif`. If this condition is met, we return the corresponding pair of indices.

1. **Initial Setup**:
   - We initialize two variables `mn` and `mx` to track the indices of the minimum and maximum elements as we traverse through the array.
   - We also set up the iteration to start from the given index `idif` and iterate through the array.

2. **Iterating Through the Array**:
   - We iterate through the array from index `idif` using the variable `i`, and for each index `i`, we calculate the minimum and maximum values up to that index using the variables `mn` and `mx`.
   - We check the absolute difference between the current element `nums[i]` and the element at index `mn` (the minimum value) and `mx` (the maximum value).
   
3. **Checking the Condition**:
   - If the absolute difference between `nums[i]` and `nums[mn]` is greater than or equal to `vdif`, we return the pair of indices `{mn, i}`.
   - If the absolute difference between `nums[i]` and `nums[mx]` is greater than or equal to `vdif`, we return the pair `{mx, i}`.

4. **Return No Pair**:
   - If the loop completes without finding a pair, the function returns `{-1, -1}` to indicate that no valid pair exists.

### Code Breakdown (Step by Step)

#### Step 1: Initial Setup

```cpp
int mn = 0, mx = 0;
```

- The variables `mn` and `mx` are initialized to zero. They will hold the indices of the minimum and maximum values encountered so far during the iteration through the array.

#### Step 2: Iteration and Tracking Minimum and Maximum Indices

```cpp
for (int i = idif, j = 0; i < nums.size(); ++i, ++j) {
    mn = nums[mn] < nums[j] ? mn : j;
    mx = nums[mx] > nums[j] ? mx : j;
```

- The loop starts from `idif` (the given starting index) and iterates over the rest of the array. The variable `i` moves from `idif` to the end of the array (`nums.size()`).
- The variable `mn` is updated to track the index of the minimum element between the current value of `mn` and `j`. This is done using a ternary conditional (`mn = nums[mn] < nums[j] ? mn : j;`).
- Similarly, `mx` is updated to track the index of the maximum element between the current value of `mx` and `j`.

#### Step 3: Checking the Absolute Difference Condition

```cpp
if (abs(nums[i] - nums[mn]) >= vdif)
    return {mn, i};
if (abs(nums[i] - nums[mx]) >= vdif)
    return {mx, i};
```

- For each index `i`, the code checks whether the absolute difference between `nums[i]` and the element at index `mn` (the minimum value up to `i`) is greater than or equal to `vdif`. If true, it returns the indices `{mn, i}`.
- Similarly, it checks whether the absolute difference between `nums[i]` and `nums[mx]` (the maximum value up to `i`) is greater than or equal to `vdif`. If true, it returns `{mx, i}`.

#### Step 4: Return No Pair Found

```cpp
return {-1, -1};
```

- If no such pair is found during the entire iteration, the function returns `{-1, -1}` to indicate that no valid pair of indices exists.

### Complexity

#### Time Complexity:
- The time complexity is `O(n)`, where `n` is the length of the input array `nums`. The function iterates over the array only once, checking the conditions for each index. Inside the loop, each operation (updating the minimum and maximum indices, checking the conditions, etc.) takes constant time, so the overall complexity is linear in the size of the input.

#### Space Complexity:
- The space complexity is `O(1)` because the function uses only a constant amount of extra space (just a few integer variables for tracking the minimum and maximum indices).

### Conclusion

This solution efficiently finds two indices in the given array `nums` such that the absolute difference between the values at those indices is at least `vdif`, starting from the index `idif`. By using a single loop and maintaining the indices of the minimum and maximum values seen so far, the solution avoids unnecessary computations and achieves a linear time complexity. This makes the solution optimal for large arrays, providing a quick way to determine whether such a pair of indices exists.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/description/)

---
{{< youtube R731s1mHVWM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
