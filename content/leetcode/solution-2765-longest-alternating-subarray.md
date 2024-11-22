
+++
authors = ["grid47"]
title = "Leetcode 2765: Longest Alternating Subarray"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2765: Longest Alternating Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Yg_VhAOIIuk"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/Yg_VhAOIIuk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int n = A.size(), res = 0, j = 0;
        for (int i = 0; i < n; ++i)
            for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
                res = max(res, j - i + 1);
        return res > 1 ? res : -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the length of the longest subarray of integers in a given array `A` that satisfies the following condition:

- The elements in the subarray alternate between increasing and decreasing values. That is, for any consecutive elements `A[i]` and `A[i+1]`, we have the condition `A[i+1] == A[i] + (i+1 - i) % 2`. 

If no alternating subarray of length greater than 1 exists, we should return `-1`.

### Approach

To solve this problem, the key observation is that we need to check for each possible subarray and verify whether the elements alternate between increasing and decreasing values. 

We'll utilize two pointers (`i` and `j`) to identify subarrays that fulfill the alternating condition. The idea is to use the pointers to extend the subarray and check if the next element satisfies the alternating condition. If it does, we extend the current subarray, and if not, we restart and look for a new potential subarray.

#### Key Observations:
1. **Alternating Pattern**: The array elements alternate if each subsequent element differs from the previous element in a predictable pattern: 
   - If `i` is even, the next element should be greater than the previous one.
   - If `i` is odd, the next element should be smaller than the previous one.

2. **Two Pointers**: We use two pointers to explore potential subarrays. The outer loop (`i`) iterates over possible starting points, while the inner loop (`j`) expands the subarray as long as the alternating pattern holds.

3. **Max Subarray Length**: We track the maximum length of a valid alternating subarray.

4. **Edge Case**: If no alternating subarray of length greater than 1 is found, we return `-1`.

### Code Breakdown (Step by Step)

Let's break down the code into manageable sections to understand how it works.

1. **Variable Initialization**:
   ```cpp
   int n = A.size(), res = 0, j = 0;
   ```
   - `n` stores the size of the input array `A`.
   - `res` is used to keep track of the length of the longest alternating subarray found.
   - `j` is the index used to explore the potential subarrays.

2. **Outer Loop (Iterating Over Possible Starting Points)**:
   ```cpp
   for (int i = 0; i < n; ++i)
   ```
   - The outer loop iterates through each element in the array `A`, starting from index `i`.
   - For each starting element `A[i]`, we attempt to extend the subarray by adjusting `j`.

3. **Inner Loop (Expanding the Subarray)**:
   ```cpp
   for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
   ```
   - The inner loop starts from index `i+1` and checks if each subsequent element `A[j]` follows the alternating pattern with respect to `A[i]`.
   - The condition `A[j] == A[i] + (j - i) % 2` checks whether the current element alternates correctly:
     - If `(j - i) % 2 == 0` (i.e., the index difference is even), the element at `A[j]` should be greater than `A[i]`.
     - If `(j - i) % 2 == 1` (i.e., the index difference is odd), the element at `A[j]` should be smaller than `A[i]`.
   - If this condition is satisfied, we continue expanding the subarray, incrementing `j`.

4. **Tracking the Maximum Length**:
   ```cpp
   res = max(res, j - i + 1);
   ```
   - For every valid subarray that we find (where the alternating pattern holds), we update `res` with the maximum length of the current alternating subarray (`j - i + 1`).

5. **Returning the Result**:
   ```cpp
   return res > 1 ? res : -1;
   ```
   - Finally, after processing all possible subarrays, we return `res`. If `res` is greater than 1, it means we have found an alternating subarray with a length greater than 1, and we return that length.
   - If `res` is 1 or less, it means no valid alternating subarray of length greater than 1 was found, so we return `-1`.

### Complexity Analysis

#### Time Complexity:
1. **Outer Loop**: The outer loop iterates over each element in the array, so it runs `n` times.
2. **Inner Loop**: For each starting index `i`, the inner loop potentially runs `n - i` times, but the number of iterations is constrained by how long the alternating pattern continues. In the worst case, the inner loop could also run `n` times for each `i`.

Thus, the total time complexity of the algorithm is \(O(n^2)\), where `n` is the size of the array `A`.

#### Space Complexity:
1. **No Additional Space**: The solution uses only a few variables (`res`, `i`, `j`), and it doesn't use any extra space apart from the input array `A`.

Thus, the space complexity is \(O(1)\), which means the algorithm uses constant space in addition to the input.

### Conclusion

The solution employs a brute force approach using two pointers to explore each possible subarray and check if it satisfies the alternating pattern. While this approach has a time complexity of \(O(n^2)\), it is straightforward and easy to understand.

In the worst-case scenario, where the entire array could be a valid alternating subarray, the algorithm checks every possible subarray. The space complexity is constant, making the algorithm efficient in terms of space. However, due to its quadratic time complexity, it might not scale well for very large input arrays.

This approach is suitable for solving smaller or moderate-sized problems but might require optimization techniques, such as dynamic programming or more advanced data structures, for very large arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-alternating-subarray/description/)

---
{{< youtube Yg_VhAOIIuk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
