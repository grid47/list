
+++
authors = ["grid47"]
title = "Leetcode 624: Maximum Distance in Arrays"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 624: Maximum Distance in Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp"
youtube = "J0yYlj_oVTI"
youtube_upload_date="2024-08-16"
youtube_thumbnail="https://i.ytimg.com/vi/J0yYlj_oVTI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/624.webp" 
    alt="Two arrays with the maximum distance between values highlighted, glowing as the distance is found."
    caption="Solution to LeetCode 624: Maximum Distance in Arrays Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0, mn = 10000, mx = -10000;
        for (auto& a : arrays) {
            res = max(res, max(a.back()-mn, mx-a.front()));
            mn = min(mn, a.front()), mx = max(mx, a.back());
        }
        return res;        
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the maximum distance between two elements in two different arrays that are part of a 2D array `arrays`. The arrays are sorted in non-decreasing order. The distance between two elements, one from each array, is defined as the absolute difference between those elements. The objective is to maximize this distance across all possible pairs of elements, each coming from a different array.

### Approach

To solve this problem efficiently, we can use a linear pass through the arrays, maintaining two variables that store the minimum and maximum elements encountered so far. This will allow us to calculate the maximum possible difference as we move through the arrays. By only considering the first and last elements of each subarray (since the arrays are sorted), we can minimize the number of comparisons needed.

Here's a step-by-step breakdown of the approach:

1. **Initialize the Result Variables:**
   - We define a variable `res` to store the maximum distance found so far. Initially, `res` is set to 0.
   - We also define `mn` and `mx` to keep track of the minimum and maximum values encountered in the previous subarrays. These are initialized to a large value (10000 for `mn` to ensure it starts larger than any potential array values) and a small value (`mx` is initialized to -10000 to start smaller than any element in the arrays).

2. **Iterate Over Each Array:**
   - For each array `a` in the input 2D array `arrays`, we calculate two possible distances:
     - The distance between the maximum element encountered so far (`mx`) and the minimum element of the current array (`a.front()`).
     - The distance between the minimum element encountered so far (`mn`) and the maximum element of the current array (`a.back()`).
   - Update `res` to store the maximum of these two distances.

3. **Update Minimum and Maximum Values:**
   - After processing the current array, we update the `mn` and `mx` to keep track of the smallest and largest elements seen across all arrays processed so far. `mn` is updated to the minimum of the current `mn` and the first element of the current array (`a.front()`), and `mx` is updated to the maximum of the current `mx` and the last element of the current array (`a.back()`).

4. **Return the Maximum Distance:**
   - After iterating through all arrays, the value stored in `res` represents the maximum distance between two elements from different arrays. This is the final result, which is returned.

### Code Breakdown (Step by Step)

1. **Initial Setup:**
   ```cpp
   int res = 0, mn = 10000, mx = -10000;
   ```
   - `res` holds the maximum distance found.
   - `mn` holds the smallest value encountered across all arrays.
   - `mx` holds the largest value encountered across all arrays.

2. **Loop Over Each Array:**
   ```cpp
   for (auto& a : arrays) {
       res = max(res, max(a.back()-mn, mx-a.front()));
       mn = min(mn, a.front()), mx = max(mx, a.back());
   }
   ```
   - For each array `a`, the maximum possible distance is computed by comparing:
     - The difference between the last element of the current array (`a.back()`) and the smallest element encountered so far (`mn`).
     - The difference between the largest element encountered so far (`mx`) and the first element of the current array (`a.front()`).
   - The maximum of these two distances is stored in `res`.

3. **Update Minimum and Maximum Values:**
   - After computing the potential maximum distance for the current array, the `mn` and `mx` values are updated:
     - `mn` is updated to be the smaller of the current `mn` and the first element of the current array (`a.front()`).
     - `mx` is updated to be the larger of the current `mx` and the last element of the current array (`a.back()`).

4. **Return the Result:**
   ```cpp
   return res;
   ```
   - After processing all arrays, the maximum distance (`res`) is returned.

### Complexity

#### Time Complexity:
- **O(N):** The solution iterates through each array exactly once. For each array, only a constant number of operations (comparisons and assignments) are performed. Thus, the time complexity is linear with respect to the total number of arrays in the input.

#### Space Complexity:
- **O(1):** The solution uses a fixed amount of extra space (variables `res`, `mn`, and `mx`). The space complexity is constant because the space used does not depend on the size of the input.

### Conclusion

This solution efficiently computes the maximum distance between two elements from different arrays using a linear pass through the input arrays. By maintaining the smallest and largest elements encountered so far, we ensure that each comparison is done in constant time. The approach is optimal, with a time complexity of O(N) and a constant space complexity. This makes the solution well-suited for handling large inputs, and it avoids the need for any nested loops or complex operations, which would have made the solution less efficient.

This approach is ideal for problems where you need to calculate the maximum or minimum difference between elements from different subarrays, and it works particularly well with sorted data. The algorithm is both simple and efficient, ensuring that the problem is solved with minimal computational overhead.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-distance-in-arrays/description/)

---
{{< youtube J0yYlj_oVTI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
