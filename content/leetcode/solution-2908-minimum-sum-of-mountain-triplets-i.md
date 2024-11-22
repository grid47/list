
+++
authors = ["grid47"]
title = "Leetcode 2908: Minimum Sum of Mountain Triplets I"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2908: Minimum Sum of Mountain Triplets I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "GegaVi1CeUM"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/GegaVi1CeUM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i] < nums[j] && nums[k] < nums[j]) ans = min(ans,nums[i]+nums[j]+nums[k]);
                }
            }
        }
        
        return (ans==INT_MAX ? -1:ans);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the minimum sum of three numbers from a given list such that the selected numbers form a strictly increasing subsequence. If no such subsequence exists, the function should return `-1`. In essence, we need to identify three distinct numbers from the list such that their order is strictly increasing, and their sum is minimized.

### Approach

To solve this problem, we can iterate over all possible combinations of three distinct numbers from the given list of numbers. The core idea is to find such a combination where:
1. The first number is smaller than the second number.
2. The second number is smaller than the third number.

Once we find such a combination, we compute the sum of these three numbers. We then track the minimum sum across all valid combinations.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int n = nums.size();
int ans = INT_MAX;
```

- We start by determining the size of the `nums` array (`n`), which is the total number of elements in the list.
- The `ans` variable is initialized to `INT_MAX`, which is a placeholder to track the minimum sum we find as we iterate over the possible combinations. By initializing it to `INT_MAX`, we ensure that any valid sum will be smaller than this initial value.

#### Step 2: Iterate Over All Possible Triplets

```cpp
for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j++) {
        for(int k = j + 1; k < n; k++) {
            if(nums[i] < nums[j] && nums[k] < nums[j]) 
                ans = min(ans, nums[i] + nums[j] + nums[k]);
        }
    }
}
```

- We use three nested loops to iterate over all possible triplets of distinct indices `(i, j, k)` in the `nums` array:
  - The outer loop (`i`) iterates from 0 to `n - 3`, ensuring that there are at least two elements after `i` to form a triplet.
  - The middle loop (`j`) iterates from `i + 1` to `n - 2`, ensuring that `j` is always greater than `i`.
  - The inner loop (`k`) iterates from `j + 1` to `n - 1`, ensuring that `k` is greater than `j` and thus forming a valid triplet.

- Inside the inner loop, we check if the triplet `(nums[i], nums[j], nums[k])` satisfies the strictly increasing condition:
  - `nums[i] < nums[j]`: The first number is less than the second.
  - `nums[k] < nums[j]`: The third number is less than the second.
  - If both conditions are true, we calculate the sum of this triplet and update the `ans` variable if the sum is smaller than the current value of `ans`.

#### Step 3: Return the Result

```cpp
return (ans == INT_MAX ? -1 : ans);
```

- After iterating through all possible triplets, we check if `ans` is still equal to `INT_MAX`. If it is, it means no valid triplet was found that satisfies the strictly increasing condition, so we return `-1`.
- Otherwise, we return the minimum sum of the valid triplet that was found.

### Complexity

#### Time Complexity:

The solution uses three nested loops to explore all possible triplets in the `nums` array. For each combination of indices `(i, j, k)`, we perform a constant-time check to see if the triplet satisfies the strictly increasing condition and to update the `ans` variable.

- The outer loop runs `n - 2` times.
- The middle loop runs `n - 1 - i` times.
- The inner loop runs `n - k` times.

In the worst case, the number of iterations will be the number of combinations of 3 elements from `n`, which is `C(n, 3)` and can be approximated as `O(n^3)`.

Thus, the time complexity of the solution is **O(n^3)**.

#### Space Complexity:

The solution only uses a few variables (`n` and `ans`), and the input is modified in place. No additional data structures are used that grow with the size of the input.

Thus, the space complexity is **O(1)**, as the space used does not depend on the size of the input list.

### Conclusion

This solution solves the problem by brute force, iterating through all possible triplets in the `nums` array and checking if they satisfy the strictly increasing condition. The time complexity of the solution is **O(n^3)**, which makes it inefficient for large input sizes. For smaller inputs, this approach works as expected and finds the minimum sum of a valid triplet.

If optimization is needed for larger inputs, more advanced techniques such as dynamic programming or sorting-based methods may be used to reduce the time complexity. However, for the given problem size, this straightforward approach is simple and easy to understand, making it a good starting point for learning how to work with triplet-based problems in arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/description/)

---
{{< youtube GegaVi1CeUM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
