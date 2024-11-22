
+++
authors = ["grid47"]
title = "Leetcode 1749: Maximum Absolute Sum of Any Subarray"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1749: Maximum Absolute Sum of Any Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XVVB_ZXsbnI"
youtube_upload_date="2021-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/XVVB_ZXsbnI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int global = 0, lx = 0, ln = 0;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > lx + nums[i])
                lx = nums[i];
            else lx += nums[i];

            if(nums[i] < ln + nums[i])
                ln = nums[i];
            else ln += nums[i];
            
            
            if(abs(lx) > global)
                global = abs(lx);
            if(abs(ln) > global)
                global = abs(ln);            
        }
        return global;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an integer array `nums`, find the maximum absolute sum of any subarray within the array. The absolute sum of a subarray is the absolute value of the sum of its elements. The task is to determine the maximum value of this absolute sum across all possible subarrays of `nums`.

### Approach

The solution uses a modified form of Kadane’s algorithm, a common algorithm for finding maximum subarray sums. Here, we need to consider both maximum positive sums and minimum (most negative) sums, because the absolute sum can be derived from either extreme.

The approach involves iterating over the array while maintaining:
1. `lx` - the current maximum subarray sum.
2. `ln` - the current minimum subarray sum.
3. `global` - the maximum absolute sum seen so far.

For each element, we update `lx` by either taking the element itself (if starting a new subarray is optimal) or adding the element to the previous maximum. Similarly, we update `ln` by taking either the element itself or adding it to the previous minimum. At each step, we update `global` with the highest absolute value between `lx` and `ln`.

### Code Breakdown (Step by Step)

```cpp
int maxAbsoluteSum(vector<int>& nums) {
    int global = 0, lx = 0, ln = 0;
    int n = nums.size();
    
    for(int i = 0; i < n; i++) {
        if(nums[i] > lx + nums[i])
            lx = nums[i];
        else lx += nums[i];

        if(nums[i] < ln + nums[i])
            ln = nums[i];
        else ln += nums[i];
        
        if(abs(lx) > global)
            global = abs(lx);
        if(abs(ln) > global)
            global = abs(ln);            
    }
    return global;
}
```

1. **Initialize Variables**:
   - `global` keeps track of the maximum absolute subarray sum encountered.
   - `lx` (local max) and `ln` (local min) track the maximum and minimum subarray sums at each index.
   - `n` stores the size of `nums` for easy access.

2. **Iterate Through Array**:
   - **Update Maximum Subarray Sum (`lx`)**: For each `nums[i]`, check if starting a new subarray with `nums[i]` alone is better than extending the previous maximum sum. Update `lx` with the result.
   - **Update Minimum Subarray Sum (`ln`)**: Similarly, decide if starting a new subarray with `nums[i]` alone results in a lower (more negative) sum than extending the previous minimum sum. Update `ln`.

3. **Track Global Absolute Maximum**:
   - Compare `global` with the absolute values of `lx` and `ln` to capture the highest absolute subarray sum so far.

4. **Return Result**:
   - After traversing the array, `global` will hold the maximum absolute subarray sum.

### Complexity

- **Time Complexity**: \(O(n)\), where \(n\) is the size of `nums`. The algorithm iterates over `nums` once.
- **Space Complexity**: \(O(1)\), as it uses a fixed number of extra variables for tracking values.

### Conclusion

This solution provides an efficient way to find the maximum absolute sum of any subarray in `nums`. By managing two running sums for maximum and minimum subarrays, it ensures both positive and negative extremes are considered, yielding an optimal solution for maximum absolute sum in linear time. This approach leverages Kadane’s algorithm principles, extended to capture absolute values.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/)

---
{{< youtube XVVB_ZXsbnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
