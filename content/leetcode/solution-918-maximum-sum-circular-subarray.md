
+++
authors = ["grid47"]
title = "Leetcode 918: Maximum Sum Circular Subarray"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 918: Maximum Sum Circular Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming","Queue","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aLMZIfhhdMg"
youtube_upload_date="2020-05-15"
youtube_thumbnail="https://i.ytimg.com/vi/aLMZIfhhdMg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int lmax = nums[0], lmin = nums[0];
        int gmax = nums[0], gmin = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            lmax = max(nums[i], lmax + nums[i]);
            gmax = max(lmax, gmax);
            lmin = min(nums[i], lmin + nums[i]);
            gmin = min(lmin, gmin);
        }
        return gmax > 0? max(gmax, sum - gmin): gmax;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the maximum possible sum of a subarray in a circular array. In a circular array, the end of the array is connected back to the beginning, so the subarray can wrap around. The challenge here is to efficiently compute the maximum subarray sum in this circular context. We need to consider both the standard non-circular maximum subarray sum and the circular maximum subarray sum, returning the greater of the two values.

### Approach

To solve this problem, we break down the solution into two key parts:

1. **Calculate the Non-Circular Maximum Subarray Sum**:
   - This is simply the maximum subarray sum without considering the circular nature of the array.
   - We use **Kadane's algorithm** to find this sum, which allows us to compute the maximum subarray sum in linear time. The algorithm maintains a local maximum `lmax` as we traverse the array and updates a global maximum `gmax` whenever `lmax` exceeds `gmax`.

2. **Calculate the Circular Maximum Subarray Sum**:
   - To handle the circular nature, we need to consider the subarrays that wrap around the array. The key observation here is that the maximum circular subarray sum can be found by subtracting the minimum subarray sum from the total sum of the array.
   - By subtracting the smallest subarray sum from the total sum, we effectively get the maximum "wrapped" subarray sum.
   - Using a similar approach to Kadane’s algorithm, we calculate the minimum subarray sum by maintaining a local minimum `lmin` and a global minimum `gmin` as we iterate through the array.

3. **Determine the Final Result**:
   - After obtaining both the non-circular maximum (`gmax`) and the circular maximum (computed as `sum - gmin`), we return the larger of the two.
   - One edge case to consider is when all elements are negative. In this case, the circular sum would incorrectly give zero (sum - gmin), so we simply return `gmax`.

### Code Breakdown (Step by Step)

1. **Initialize Variables**:
   ```cpp
   int lmax = nums[0], lmin = nums[0];
   int gmax = nums[0], gmin = nums[0];
   int sum = nums[0];
   ```
   - We initialize variables for local and global maximums (`lmax`, `gmax`) and minimums (`lmin`, `gmin`) with the first element of the array.
   - We also initialize `sum` with the first element to keep track of the total sum of the array.

2. **Iterate Through the Array**:
   ```cpp
   for(int i = 1; i < nums.size(); i++) {
       sum += nums[i];
       lmax = max(nums[i], lmax + nums[i]);
       gmax = max(lmax, gmax);
       lmin = min(nums[i], lmin + nums[i]);
       gmin = min(lmin, gmin);
   }
   ```
   - We iterate through the rest of the array, updating `sum` with each element.
   - For each element, we compute the new `lmax` (local maximum), which is the maximum of the current element itself or the sum of `lmax` plus the current element.
   - We update `gmax` to store the highest `lmax` encountered.
   - Similarly, we calculate `lmin` (local minimum) as the minimum of the current element or `lmin` plus the current element, and update `gmin` to the lowest `lmin`.

3. **Return the Result**:
   ```cpp
   return gmax > 0 ? max(gmax, sum - gmin) : gmax;
   ```
   - We check if `gmax` is greater than zero. If it is, we return the maximum of `gmax` and the circular subarray sum (`sum - gmin`).
   - If `gmax` is non-positive (indicating all elements are negative), we return `gmax` to avoid incorrect results from the circular calculation.

### Complexity

1. **Time Complexity**:
   - The time complexity is **O(n)**, where `n` is the number of elements in the input array. This is because we only need a single pass through the array to compute all the required values for `gmax`, `gmin`, and `sum`.

2. **Space Complexity**:
   - The space complexity is **O(1)** since we only use a constant amount of extra space to store variables for the local and global maximums and minimums.

### Conclusion

This solution effectively finds the maximum subarray sum for both the non-circular and circular cases in a single pass, using Kadane’s algorithm for optimal performance. By leveraging both the maximum and minimum subarray sums, the approach handles the circular nature of the array while ensuring efficiency. The algorithm is well-suited for large arrays, maintaining O(n) complexity with minimal space requirements. This makes it an ideal solution for applications where quick subarray sum calculations are needed on circular data.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

---
{{< youtube aLMZIfhhdMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
