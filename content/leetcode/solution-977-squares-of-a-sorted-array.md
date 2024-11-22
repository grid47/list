
+++
authors = ["grid47"]
title = "Leetcode 977: Squares of a Sorted Array"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 977: Squares of a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "z0InhrjK3es"
youtube_upload_date="2024-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/z0InhrjK3es/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0, r = nums.size() - 1;
        int ll, rr;
        for(int i = nums.size() - 1; i >= 0; i--) {
            ll = nums[l] * nums[l];
            rr = nums[r] * nums[r];
            if(ll < rr) ans[i] = rr, r--;
            else ans[i] = ll, l++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to return a **sorted array** of the squares of each number in the given array `nums`. The input array `nums` may contain both negative and non-negative integers, and the output should have the squares in non-decreasing order.

For example:
- **Input**: `nums = [-4, -1, 0, 3, 10]`
- **Output**: `[0, 1, 9, 16, 100]`

### Approach

This problem can be solved efficiently using the **two-pointer technique**. The key observation here is that the absolute values of the elements in the array increase as we move away from the center towards the edges in a sorted array. Therefore, by focusing on the largest values (in terms of absolute magnitude) from both the left and right sides of the array, we can directly build the sorted squares array without needing to sort the entire array afterward.

#### Key Insights:

1. **Squared Values**: When squaring both negative and positive numbers, the absolute value of negative numbers becomes positive. However, larger numbers will result in larger squared values. Therefore, for an array that contains both negative and positive values, the largest squares will come from either the largest negative number or the largest positive number.

2. **Two-pointer Approach**:
   - We can use a **left pointer (`l`)** starting at the beginning of the array, and a **right pointer (`r`)** starting at the end of the array.
   - At each step, we compare the absolute values of the elements at the `l` and `r` positions. The larger absolute value will give us the largest square.
   - The squared value is placed at the current position in the result array, and the pointer corresponding to the larger absolute value is moved inward.
   - This process continues until all positions in the result array are filled.

3. **Efficient Sorting**: 
   - By iterating from the end of the result array (starting at the largest index) and always choosing the largest squared value, we ensure that the array is populated in sorted order from the largest to the smallest value.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());  // Create a result vector to store squared values
        int l = 0, r = nums.size() - 1;  // Initialize two pointers: one at the start (l) and one at the end (r)
        int ll, rr;
```

1. **Initialization**:
   - `ans`: A result vector that will hold the squares of the elements from the `nums` array in sorted order.
   - `l`: A pointer initialized to the first element of the array.
   - `r`: A pointer initialized to the last element of the array.
   - `ll` and `rr`: Temporary variables to store the squared values of `nums[l]` and `nums[r]`.

```cpp
        for(int i = nums.size() - 1; i >= 0; i--) {  // Iterate from the end of the result array
            ll = nums[l] * nums[l];  // Square the value at the left pointer
            rr = nums[r] * nums[r];  // Square the value at the right pointer
```

2. **Squaring the Values**:
   - The loop starts at the last index of the result array (`i = nums.size() - 1`) and moves backwards to fill the result array.
   - `ll` and `rr` store the squared values of the elements at positions `l` and `r`.

```cpp
            if(ll < rr) ans[i] = rr, r--;  // If the square at the right pointer is larger, place it in the result and move the right pointer
            else ans[i] = ll, l++;  // Otherwise, place the square at the left pointer in the result and move the left pointer
        }
```

3. **Comparing Squared Values**:
   - We compare the squared values at the left (`ll`) and right (`rr`) pointers.
   - If `ll` (square of `nums[l]`) is smaller than `rr` (square of `nums[r]`), we place `rr` in the current position of the result array (`ans[i]`) and move the `r` pointer inward (`r--`).
   - If `ll` is greater than or equal to `rr`, we place `ll` in the result array and move the `l` pointer inward (`l++`).
   - This ensures that the largest values are placed in the result array first, in decreasing order of their magnitude.

```cpp
        return ans;  // Return the sorted array of squares
    }
};
```

4. **Return the Result**:
   - After the loop finishes, all the elements of the array `nums` have been squared and placed in the `ans` array in sorted order. We return this array as the result.

### Time and Space Complexity

- **Time Complexity**:
  - The algorithm iterates over the `nums` array once with a two-pointer approach. Each element is processed exactly once. Therefore, the time complexity is **O(n)**, where `n` is the size of the input array `nums`.

- **Space Complexity**:
  - The space complexity is **O(n)**, where `n` is the size of the input array `nums`. This is due to the result array `ans` that stores the squared values.

### Conclusion

This solution leverages the **two-pointer technique** to efficiently solve the problem of finding the sorted squares of an array. By iterating from both ends of the array and placing the largest squared values first, we avoid the need for sorting the entire array afterward. This approach provides an optimal solution with a time complexity of **O(n)** and space complexity of **O(n)**, making it highly efficient even for large arrays. The algorithm efficiently handles both negative and non-negative integers in the input array by focusing on the magnitude of their squared values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/squares-of-a-sorted-array/description/)

---
{{< youtube z0InhrjK3es >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
