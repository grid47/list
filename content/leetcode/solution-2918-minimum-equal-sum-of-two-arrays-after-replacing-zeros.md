
+++
authors = ["grid47"]
title = "Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2918: Minimum Equal Sum of Two Arrays After Replacing Zeros in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0l2IwK_OHac"
youtube_upload_date="2023-10-29"
youtube_thumbnail="https://i.ytimg.com/vi/0l2IwK_OHac/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
        for(int num: nums1) cnt1 += num == 0, sum1 += num;
        for(int num: nums2) cnt2 += num == 0, sum2 += num;

        if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
            cnt2 == 0 && cnt1 + sum1 > sum2)
                return -1;

        return max(sum1 + cnt1, sum2 + cnt2);

    }
};
{{< /highlight >}}
---

### Problem Statement:
The given problem requires determining the minimum sum of two lists, `nums1` and `nums2`, based on specific conditions involving zeros in the lists. The goal is to compute a sum where zeros can potentially influence the outcome. The result is defined by how the zeros in each list interact with the non-zero elements, making this problem an interesting challenge in both logic and optimization.

### Approach:
To solve this problem, we need to assess the impact of zeros in each of the two input arrays, `nums1` and `nums2`. The main idea is to calculate the sums of the elements in both arrays, while also counting how many zeros are present. Based on the presence of zeros and their counts, we derive an answer that either represents the minimum sum possible or `-1` if certain conditions are violated. Let's break down the approach step by step:

1. **Initialization of Variables**:
   We define several variables:
   - `cnt1` and `cnt2`: These are counters that track how many zeros exist in `nums1` and `nums2`, respectively.
   - `sum1` and `sum2`: These variables store the sum of all elements in `nums1` and `nums2`, respectively. These sums will help us calculate the final answer.

   ```cpp
   long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
   ```

2. **Iterating through `nums1`**:
   We loop through the first list `nums1` and:
   - Increment `cnt1` each time we encounter a zero.
   - Add the value of each element to `sum1`.

   ```cpp
   for(int num: nums1) cnt1 += num == 0, sum1 += num;
   ```

3. **Iterating through `nums2`**:
   Similarly, we iterate through `nums2` and:
   - Increment `cnt2` for each zero encountered.
   - Add each element’s value to `sum2`.

   ```cpp
   for(int num: nums2) cnt2 += num == 0, sum2 += num;
   ```

4. **Checking for Invalid Conditions**:
   After calculating the necessary sums and zero counts, we check if the condition for returning `-1` is met. The condition checks whether one list has no zeros while the other list has a sum that exceeds the first list's sum:
   - If `cnt1` is `0` (no zeros in `nums1`) and the sum of `nums2` plus `cnt2` (the number of zeros in `nums2`) exceeds the sum of `nums1`, return `-1`.
   - If `cnt2` is `0` (no zeros in `nums2`) and the sum of `nums1` plus `cnt1` exceeds the sum of `nums2`, return `-1`.

   ```cpp
   if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
      cnt2 == 0 && cnt1 + sum1 > sum2)
          return -1;
   ```

5. **Calculating the Result**:
   If the invalid conditions are not met, we calculate the final result by returning the maximum of the sum of each list plus its corresponding zero count:
   - `sum1 + cnt1` represents the sum of `nums1` with the added zeros, and similarly, `sum2 + cnt2` represents the sum of `nums2` with the added zeros.

   ```cpp
   return max(sum1 + cnt1, sum2 + cnt2);
   ```

   This step ensures that we are computing the minimum sum that satisfies the conditions laid out in the problem statement.

### Code Breakdown (Step by Step):
1. **Initialization and Zero Count**:
   We begin by setting up the variables necessary for tracking the sum and the count of zeros. This prepares us to handle both the sums of the arrays and the conditions that will arise based on the zeros.

   ```cpp
   long long cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
   ```

2. **First Loop: Sum and Zero Count in `nums1`**:
   This loop iterates through `nums1` and updates the counter `cnt1` for zeros and the sum `sum1` for all elements. The logic in this loop is essential for tracking both the non-zero sum and the count of zeros.

   ```cpp
   for(int num: nums1) cnt1 += num == 0, sum1 += num;
   ```

3. **Second Loop: Sum and Zero Count in `nums2`**:
   Similarly, we loop through `nums2`, updating the `cnt2` and `sum2` values. This loop provides the same information for `nums2` as the first loop does for `nums1`.

   ```cpp
   for(int num: nums2) cnt2 += num == 0, sum2 += num;
   ```

4. **Condition for Returning `-1`**:
   After we have computed the necessary sums and zero counts, we check whether either array has no zeros, and the other array's sum, when adjusted by the zero count, exceeds the sum of the first array. If any of these conditions hold, we return `-1`.

   ```cpp
   if(cnt1 == 0 && cnt2 + sum2 > sum1 ||
      cnt2 == 0 && cnt1 + sum1 > sum2)
          return -1;
   ```

5. **Final Calculation**:
   If the invalid conditions are not met, we compute the maximum of the adjusted sums and return it as the result.

   ```cpp
   return max(sum1 + cnt1, sum2 + cnt2);
   ```

### Complexity:
1. **Time Complexity**:
   The solution involves two loops that each iterate through the arrays `nums1` and `nums2`. Each loop runs in linear time relative to the size of the arrays. Therefore, the overall time complexity is:
   \[
   O(n + m)
   \]
   where `n` is the size of `nums1` and `m` is the size of `nums2`. Since we only process each element of the arrays once, the solution is efficient and optimal in terms of time complexity.

2. **Space Complexity**:
   The space complexity of this solution is constant, \(O(1)\), because we only use a fixed number of variables (`cnt1`, `cnt2`, `sum1`, `sum2`) to store intermediate values, regardless of the size of the input arrays.

### Conclusion:
The solution to this problem efficiently handles the task of calculating the minimum sum of two arrays while considering the impact of zeros in each array. By using a straightforward approach that counts zeros and computes sums, the solution is both time and space efficient. It effectively handles the conditions required for invalid cases and ensures the correct minimum sum is returned based on the given problem statement.

This approach is both simple and optimal, making it suitable for a wide range of input sizes, with the time complexity scaling linearly with the size of the input arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/)

---
{{< youtube 0l2IwK_OHac >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
