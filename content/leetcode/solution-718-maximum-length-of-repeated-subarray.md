
+++
authors = ["grid47"]
title = "Leetcode 718: Maximum Length of Repeated Subarray"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 718: Maximum Length of Repeated Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sliding Window","Rolling Hash","Hash Function"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/718.webp"
youtube = "MynhR1bMtWY"
youtube_upload_date="2021-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/MynhR1bMtWY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/718.webp" 
    alt="An array where the longest repeated subarray is highlighted and softly glowing as it's determined."
    caption="Solution to LeetCode 718: Maximum Length of Repeated Subarray Problem"
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
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

        for(int i = 0; i < n1 + 1; i++) dp[i][0] = 0;
        for(int i = 0; i < n2 + 1; i++) dp[0][i] = 0;
        // dp[0][0] = 0;

        // subseq - !subarr
        int mx = 0;
        for(int i = 1; i < n1 + 1; i++)
        for(int j = 1; j < n2 + 1; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                 dp[i][j] = dp[i - 1][j - 1] + 1;
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the length of the longest common subarray between two given arrays, `nums1` and `nums2`. A **subarray** is defined as a contiguous segment of an array. The goal is to identify the longest contiguous segment that appears in both arrays and return its length. 

This problem can be viewed as a variation of the **longest common subsequence** problem, but with the additional restriction that the matching elements must be contiguous in both arrays.

### Approach

To solve this problem, we can utilize **dynamic programming (DP)**. The idea is to use a two-dimensional DP table to store the length of the longest common subarray found so far at any pair of indices in the two arrays.

We define a DP table `dp[i][j]` where:
- `dp[i][j]` represents the length of the longest common subarray ending at `nums1[i-1]` and `nums2[j-1]`.

The key idea is to iterate through both arrays and update the DP table based on whether the elements `nums1[i-1]` and `nums2[j-1]` are equal. If they are, the longest common subarray ending at `i` and `j` is one longer than the longest common subarray ending at `i-1` and `j-1`. Otherwise, the common subarray length is zero.

At each step, we track the maximum length of the common subarray encountered so far.

### Code Breakdown (Step by Step)

Let’s break down the code to understand how it works:

1. **Initialization**:
   - We first compute the sizes of the two input arrays:
   ```cpp
   int n1 = nums1.size(), n2 = nums2.size();
   ```
   - We then create a 2D DP table `dp` of size `(n1 + 1) x (n2 + 1)` initialized to 0. The extra row and column are used to handle the base case when one of the arrays is empty:
   ```cpp
   vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
   ```

2. **Base Case**:
   - The first row (`dp[0][*]`) and the first column (`dp[*][0]`) are initialized to zero because if either array is empty, the longest common subarray is of length 0. This is done using two loops:
   ```cpp
   for(int i = 0; i < n1 + 1; i++) dp[i][0] = 0;
   for(int i = 0; i < n2 + 1; i++) dp[0][i] = 0;
   ```

3. **Dynamic Programming Transition**:
   - We then iterate through both arrays starting from index 1 to compute the values in the DP table:
   ```cpp
   int mx = 0;  // This will hold the maximum length of the common subarray.
   for(int i = 1; i < n1 + 1; i++)
       for(int j = 1; j < n2 + 1; j++) {
           if (nums1[i - 1] == nums2[j - 1]) {
               dp[i][j] = dp[i - 1][j - 1] + 1;
               mx = max(mx, dp[i][j]);
           }
       }
   ```
   - For each pair of indices `i` and `j`, if `nums1[i - 1] == nums2[j - 1]`, it means we have found a common element. The length of the longest common subarray ending at `i` and `j` is `dp[i-1][j-1] + 1`, which is the length of the subarray ending at `i-1` and `j-1` extended by one element.
   - If `nums1[i - 1] != nums2[j - 1]`, the value of `dp[i][j]` remains 0, as no common subarray ends at those indices.
   - At each step, we update `mx` to track the maximum length of any common subarray encountered so far:
   ```cpp
   mx = max(mx, dp[i][j]);
   ```

4. **Return the Result**:
   - After iterating through the entire array, the maximum length of the longest common subarray is stored in `mx`, and we return this value:
   ```cpp
   return mx;
   ```

### Complexity Analysis

- **Time Complexity**:
  - The algorithm uses two nested loops to fill the DP table, where the outer loop runs `n1` times and the inner loop runs `n2` times, where `n1` and `n2` are the lengths of the two input arrays `nums1` and `nums2`. Thus, the time complexity is **O(n1 * n2)**, which is optimal for this type of problem.
  
- **Space Complexity**:
  - The algorithm uses a 2D DP table of size `(n1 + 1) x (n2 + 1)`, which requires **O(n1 * n2)** space. This is the space complexity of the solution. The extra space is necessary to store the intermediate results of the DP computation.

  If space is a concern, one could optimize the space complexity by using only two rows of the DP table, reducing the space complexity to **O(min(n1, n2))**, since only the previous row is needed at each step.

### Conclusion

This solution leverages dynamic programming to find the longest common subarray between two arrays. By using a 2D DP table, we track the length of the longest subarray ending at each pair of indices in `nums1` and `nums2`. The algorithm is efficient, with a time complexity of **O(n1 * n2)** and a space complexity of **O(n1 * n2)**, making it well-suited for solving problems involving finding common subarrays or subsequences.

This method ensures that we explore all possible matching subarrays and compute the longest one efficiently. The use of dynamic programming eliminates the need for brute-force solutions, which would be much slower for large inputs. This approach can be easily adapted to other problems involving common subsequences or subarrays.

In summary, the dynamic programming approach used here is a robust and optimal way to solve the problem of finding the longest common subarray. It provides a clear, systematic approach that can be applied to a variety of related problems in string and array manipulation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/)

---
{{< youtube MynhR1bMtWY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
