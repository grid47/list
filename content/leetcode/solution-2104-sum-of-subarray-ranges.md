
+++
authors = ["grid47"]
title = "Leetcode 2104: Sum of Subarray Ranges"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2104: Sum of Subarray Ranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "sMFAjHe3kkw"
youtube_upload_date="2021-12-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/sMFAjHe3kkw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long long res = 0, n = nums.size();
        
        for(int i = 0; i < n - 1; i++) {
            
            int mini = nums[i], maxi = nums[i];
            
            for(int j = i + 1; j < n; j++) {
                
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                res += maxi - mini;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

This code calculates the sum of the ranges for all possible subarrays of an input array `nums`. In a subarray, the range is defined as the difference between the maximum and minimum values in that subarray. The task is to calculate this range for every possible subarray and sum them up to get the final result.

### Approach

The approach here involves a nested loop strategy. For each element in the array, the algorithm identifies all subarrays starting at that element. It tracks the minimum and maximum values within each subarray as it iterates and calculates the range. By summing these ranges, it accumulates the total range for all subarrays in the variable `res`.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   long long res = 0, n = nums.size();
   ```
   - `res`: Stores the cumulative sum of all subarray ranges.
   - `n`: Stores the size of the input array `nums`.

2. **Outer Loop**:
   ```cpp
   for(int i = 0; i < n - 1; i++) {
   ```
   - The outer loop iterates over each starting position `i` of potential subarrays in `nums`. This allows us to calculate the range for all subarrays beginning with `nums[i]`.

3. **Initialize `mini` and `maxi`**:
   ```cpp
   int mini = nums[i], maxi = nums[i];
   ```
   - `mini`: Tracks the minimum value within the current subarray.
   - `maxi`: Tracks the maximum value within the current subarray.
   - Both `mini` and `maxi` start with the first element of the subarray, `nums[i]`.

4. **Inner Loop**:
   ```cpp
   for(int j = i + 1; j < n; j++) {
   ```
   - The inner loop extends the current subarray by one element each time, starting from `i + 1` up to `n-1`.

5. **Update `mini` and `maxi`**:
   ```cpp
   if(nums[j] < mini) mini = nums[j];
   if(nums[j] > maxi) maxi = nums[j];
   ```
   - As each new element is added to the subarray, `mini` and `maxi` are updated if the new element is smaller or larger, respectively. This helps keep track of the minimum and maximum values in the current subarray range.

6. **Calculate Range and Update Result**:
   ```cpp
   res += maxi - mini;
   ```
   - The difference between `maxi` and `mini` gives the range of the current subarray. This range is added to the cumulative result, `res`.

7. **Return Result**:
   ```cpp
   return res;
   ```
   - Once all possible subarrays have been processed, `res` contains the sum of ranges for every subarray in `nums`.

### Complexity Analysis

- **Time Complexity**: \(O(n^2)\)
   - The outer loop runs `n` times, and for each `i`, the inner loop can run up to `n - i - 1` times, resulting in an overall quadratic time complexity.
   
- **Space Complexity**: \(O(1)\)
   - Only a few extra variables (`mini`, `maxi`, and `res`) are used, so the space complexity is constant.

### Conclusion

This solution efficiently calculates the sum of subarray ranges using a nested loop structure, ideal for cases where input arrays are small to moderately sized. The algorithm’s nested structure ensures that every possible subarray is considered, and the approach of updating minimum and maximum values on each inner loop iteration provides an effective way to compute ranges dynamically. This code is straightforward, leveraging a brute-force approach that provides accurate results for the sum of all subarray ranges without requiring additional data structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-subarray-ranges/description/)

---
{{< youtube sMFAjHe3kkw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
