
+++
authors = ["grid47"]
title = "Leetcode 2090: K Radius Subarray Averages"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2090: K Radius Subarray Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rdKE6yZ_D3A"
youtube_upload_date="2021-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rdKE6yZ_D3A/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> psum(n, 0);
        vector<int> avg(n, 0);
        psum[0] = nums[0];
        for(int i = 1; i < n; i++)
            psum[i] = psum[i - 1] + nums[i];
        
        for(int i = 0; i < n; i++) {
            if(i - k < 0 || i + k >= n) {
                avg[i] = -1;
            } else {
                avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
            }
        }
        return avg;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find the average of all elements in a sliding window of size `2k + 1` for a given array `nums`. For each index `i`, if the sliding window cannot be formed (i.e., if `i - k` is less than 0 or `i + k` is greater than or equal to the length of `nums`), the output should be `-1`. The goal is to implement an efficient solution that avoids unnecessary recomputation, particularly in situations where the size of the array and the value of `k` can be large.

### Approach

To tackle this problem efficiently, we utilize the concept of prefix sums. The prefix sum array allows us to compute the sum of any subarray in constant time, which is essential for maintaining optimal performance while calculating averages in a sliding window. The solution involves the following key steps:

1. **Initialization**: We first establish the size of the input array, `n`, and create two arrays: `psum` for storing the prefix sums and `avg` for the final average results.

2. **Building the Prefix Sum Array**: We populate the `psum` array such that each element at index `i` holds the sum of the elements from the start of the array up to `i`. This is accomplished through a simple loop where each element is added to the previous sum.

3. **Calculating Averages**: With the prefix sum array in place, we iterate through each index `i` of the original array. For each index:
   - We check if the current index allows for a valid sliding window by ensuring `i - k` is not less than 0 and `i + k` is less than `n`.
   - If a valid window exists, we compute the average of the elements in the window using the prefix sum array. The average is calculated by subtracting the sum of elements outside the window from the total sum provided by the prefix sums and then dividing by `2 * k + 1`.
   - If a valid window does not exist, we simply set the average at that index to `-1`.

This approach ensures that we efficiently compute the required averages without redundantly summing elements, leading to significant performance gains, especially for larger arrays.

### Code Breakdown (Step by Step)

The code provided implements the outlined approach in a clear manner:

1. **Prefix Sum Calculation**:
   ```cpp
   psum[0] = nums[0];
   for(int i = 1; i < n; i++)
       psum[i] = psum[i - 1] + nums[i];
   ```
   Here, we initialize the first element of the prefix sum array and iteratively fill in the rest by adding the current element to the previous sum.

2. **Average Calculation**:
   ```cpp
   for(int i = 0; i < n; i++) {
       if(i - k < 0 || i + k >= n) {
           avg[i] = -1;
       } else {
           avg[i] = (psum[i + k] - ((i - k) == 0 ? 0 : psum[i - k - 1])) / (2 * k + 1);
       }
   }
   ```
   In this loop, we assess whether we can form a complete window around the index `i`. If not, we assign `-1`. If we can, we calculate the average by leveraging the prefix sum array for quick access to the necessary sums.

3. **Return Statement**:
   ```cpp
   return avg;
   ```
   Finally, the computed averages are returned as a vector.

### Complexity

The overall complexity of this algorithm is linear, O(n), where `n` is the length of the input array. This is due to the single pass needed to construct the prefix sum and another pass to compute the averages. The space complexity is also O(n) due to the storage of the prefix sum and the average arrays. This efficient approach ensures that we can handle even large datasets swiftly.

### Conclusion

In summary, the provided solution efficiently computes the averages for a sliding window of size `2k + 1` using the prefix sum technique. By leveraging this method, the algorithm achieves optimal time complexity while maintaining clarity and maintainability in the code. This solution is particularly valuable in scenarios where quick average computations are essential, such as in real-time data processing or large-scale numerical analyses.

[`Link to LeetCode Lab`](https://leetcode.com/problems/k-radius-subarray-averages/description/)

---
{{< youtube rdKE6yZ_D3A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
