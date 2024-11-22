
+++
authors = ["grid47"]
title = "Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1031: Maximum Sum of Two Non-Overlapping Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YAcHH5AVsZg"
youtube_upload_date="2019-07-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/YAcHH5AVsZg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int maxTwoNoOverlap(vector<int>& A, int L, int M, int sz, int res = 0) {
        vector<int> left(sz+1), right(sz+1);

        for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
            s_l += A[i], s_r += A[j];
            left[i + 1] = max(left[i], s_l);
            right[j] = max(right[j + 1], s_r);
            if (i + 1 >= L) s_l -= A[i + 1 - L];
            if (i + 1 >= M) s_r -= A[j + M - 1];
        }

        for (auto i = 0; i < A.size(); ++i) {
            res = max(res, left[i] + right[i]);
        }
  
        return res;

    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(maxTwoNoOverlap(nums, firstLen, secondLen, nums.size()),
                   maxTwoNoOverlap(nums, secondLen, firstLen, nums.size()));
    }
};
{{< /highlight >}}
---



### Problem Statement
The goal is to find the maximum sum of two non-overlapping subarrays within a given array of integers. We are given two lengths, `L` and `M`, which represent the lengths of the two subarrays. The task is to maximize the sum of these two subarrays while ensuring that they do not overlap.

For example, given the array:
```
A = [1, 2, 1, 2, 5, 3, 2]
```
and lengths `L = 2` and `M = 3`, the optimal non-overlapping subarrays would yield the maximum sum.

### Approach
To solve this problem, we can break it down into a few key steps:
1. **Prefix Sum Arrays**: We will calculate two prefix sum arrays: one for subarrays of length `L` (denoted as `left`) and one for subarrays of length `M` (denoted as `right`).
2. **Max Sum Calculation**: For each position in the array, we will calculate the maximum sums of the two subarrays that can be formed without overlapping.
3. **Iteration**: We will iterate through the array to populate these prefix sum arrays, ensuring that we account for the lengths `L` and `M` correctly to avoid overlap.

The solution consists of a function `maxTwoNoOverlap` that handles the logic for calculating the maximum sums of two non-overlapping subarrays for given lengths.

### Code Breakdown (Step by Step)

1. **Class Declaration**:
   - The code defines a class `Solution`, which encapsulates the logic for solving the problem.

2. **Function Declaration**:
   - The function `maxTwoNoOverlap` takes the following parameters:
     - `A`: The input array of integers.
     - `L`: Length of the first subarray.
     - `M`: Length of the second subarray.
     - `sz`: The size of the input array.
     - `res`: A variable initialized to `0` that will hold the result.

3. **Initialization**:
   - Two vectors, `left` and `right`, are initialized to store the maximum sums of subarrays of length `L` and `M`, respectively. Both vectors are of size `sz + 1` to accommodate the calculations easily.

4. **Calculating Left and Right Sums**:
   - A loop iterates through the array to calculate the maximum sums of subarrays of lengths `L` and `M`:
     - **Left Sum Calculation**:
       - `s_l` keeps track of the current sum for the subarray of length `L`.
       - The current value of `A[i]` is added to `s_l`, and the maximum is updated in the `left` array.
       - If we have processed at least `L` elements, we subtract the value that exits the window.
     - **Right Sum Calculation**:
       - Similarly, `s_r` tracks the current sum for the subarray of length `M` from the right side of the array.
       - The maximum is updated in the `right` array.
       - If we have processed at least `M` elements, we subtract the value that exits the window.

5. **Combining Results**:
   - After populating the `left` and `right` arrays, another loop runs through the array to find the maximum combined sum of the two non-overlapping subarrays:
     - The maximum sum at each index `i` is calculated by adding `left[i]` and `right[i]`.

6. **Return Statement**:
   - The function returns the maximum sum found.

7. **Main Function**:
   - The function `maxSumTwoNoOverlap` calls `maxTwoNoOverlap` twice:
     - First with lengths `firstLen` and `secondLen`.
     - Second with lengths `secondLen` and `firstLen`.
   - This ensures that we account for both orderings of the two subarrays, thus maximizing the total sum.

### Complexity Analysis
- **Time Complexity**: The overall time complexity is \(O(n)\), where \(n\) is the number of elements in the input array. The loops for calculating the sums and iterating through the array each run in linear time.
- **Space Complexity**: The space complexity is \(O(n)\) due to the use of the `left` and `right` arrays for storing intermediate results.

### Conclusion
The provided code effectively calculates the maximum sum of two non-overlapping subarrays by utilizing a combination of prefix sums and careful iteration through the array. The solution is efficient and straightforward, making it suitable for large input sizes.

This approach is particularly useful in scenarios where resource allocation or partitioning of data is required, such as in financial computations, interval scheduling, and optimizing resource usage in various applications.

In summary, the `maxTwoNoOverlap` and `maxSumTwoNoOverlap` functions demonstrate a clear understanding of the problem and an effective implementation of a common algorithmic technique, providing a robust solution to the challenge of maximizing sums in non-overlapping subarrays. 

By ensuring clarity in each step of the process, this explanation serves to enhance understanding of both the code and the underlying logic, making it beneficial for learners and practitioners in algorithm design and optimization.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/)

---
{{< youtube YAcHH5AVsZg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
