
+++
authors = ["grid47"]
title = "Leetcode 2567: Minimum Score by Changing Two Elements"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2567: Minimum Score by Changing Two Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MPtncVNtKW0"
youtube_upload_date="2023-02-18"
youtube_thumbnail="https://i.ytimg.com/vi/MPtncVNtKW0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n - 3] - nums[0];
        int b = nums[n - 1] - nums[2];
        int c = nums[n - 2] - nums[1];
        return min({a, b, c});
        
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an integer array `nums`, the task is to make at most two modifications to the array to minimize the range between the maximum and minimum values of the modified array. Specifically, we need to find the smallest possible difference between the maximum and minimum elements of the array after performing up to two modifications.

### Approach

1. **Sorting the Array**:
   - First, we sort the array `nums` in ascending order. Sorting allows us to systematically address the minimum and maximum values by focusing on the smallest and largest elements.
   - Once sorted, modifying the array to minimize the range is straightforward since the smallest and largest elements are positioned at the beginning and end of the sorted array.

2. **Evaluate Possible Modifications**:
   - Since we can modify up to two elements, there are three primary strategies to minimize the range:
     1. **Remove the Two Largest Elements**: If we remove the two largest values (from the end of the sorted array), the range becomes `nums[n - 3] - nums[0]`.
     2. **Remove the Two Smallest Elements**: If we remove the two smallest values (from the start of the sorted array), the range becomes `nums[n - 1] - nums[2]`.
     3. **Remove One Smallest and One Largest Element**: If we remove one smallest and one largest value, the range becomes `nums[n - 2] - nums[1]`.
   
3. **Calculate and Compare Ranges**:
   - For each strategy, calculate the range between the maximum and minimum values of the modified array.
   - The minimum of these three ranges gives the optimal solution, as it represents the smallest possible range that can be achieved by modifying the array up to two times.

### Code Breakdown (Step by Step)

1. **Sort the Array**:
   ```cpp
   sort(nums.begin(), nums.end());
   ```
   Sorting `nums` allows us to easily access the smallest and largest elements, facilitating the calculation of potential ranges.

2. **Calculate Range for Each Modification Strategy**:
   ```cpp
   int a = nums[n - 3] - nums[0];
   int b = nums[n - 1] - nums[2];
   int c = nums[n - 2] - nums[1];
   ```
   - `a` represents the range when we remove the two largest elements. This range is `nums[n - 3] - nums[0]`.
   - `b` represents the range when we remove the two smallest elements. This range is `nums[n - 1] - nums[2]`.
   - `c` represents the range when we remove one smallest and one largest element. This range is `nums[n - 2] - nums[1]`.

3. **Return the Minimum of All Possible Ranges**:
   ```cpp
   return min({a, b, c});
   ```
   - We use `min({a, b, c})` to find the smallest range among the three possible values (`a`, `b`, and `c`), which gives the minimum difference after modifying the array up to two times.

### Complexity Analysis

- **Time Complexity**:
  - Sorting the array takes \(O(n \log n)\).
  - Calculating the three ranges and finding the minimum is \(O(1)\).
  - Thus, the overall time complexity is \(O(n \log n)\).

- **Space Complexity**:
  - The solution uses \(O(1)\) extra space, as it only requires variables to store the range calculations (`a`, `b`, `c`) and the result.

### Conclusion

This solution efficiently minimizes the range between the maximum and minimum values of the array by using sorting and analyzing possible modifications. By considering only three specific strategies for removing elements, it achieves an optimal range reduction with minimal computations. This approach is efficient and effective for finding the minimal range after up to two modifications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/)

---
{{< youtube MPtncVNtKW0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
