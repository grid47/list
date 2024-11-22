
+++
authors = ["grid47"]
title = "Leetcode 775: Global and Local Inversions"
date = "2024-08-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 775: Global and Local Inversions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/775.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/775.webp" 
    alt="A sequence where global and local inversions are counted, each inversion glowing softly as it's identified."
    caption="Solution to LeetCode 775: Global and Local Inversions Problem"
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
    bool isIdealPermutation(vector<int>& nums) {
        int cmax = 0, n = nums.size();
        for(int i = 0; i < n - 2; i++) {
            cmax = max(cmax, nums[i]);
            if(cmax > nums[i + 2]) return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task at hand is to determine whether a given permutation of integers can be classified as "ideal." In the context of this problem, an "ideal" permutation is defined by the property that for every index `i`, the largest number in the subarray `nums[0]` to `nums[i]` must not exceed the element at index `i + 2`. More formally, if the permutation is ideal, for every index `i`, the following condition should hold:

\[ \text{max}(nums[0], nums[1], \dots, nums[i]) \leq nums[i+2] \]

This problem requires us to check if this condition is satisfied for all possible indices in the array.

**Example 1:**

- Input: `nums = [1, 0, 2, 3, 4]`
- Output: `true`

Here, the array is ideal because for each `i`, the largest number up to index `i` is less than or equal to the number at index `i + 2`.

**Example 2:**

- Input: `nums = [1, 2, 0, 3]`
- Output: `false`

In this case, the condition is violated for `i = 0` because the largest number up to index `0` (which is `1`) is greater than `nums[2]` (which is `0`).

### Approach

To solve this problem, we need to traverse the input array `nums` and, at each step, check whether the largest element in the subarray from index `0` to `i` is less than or equal to the element at index `i + 2`. Specifically, we need to track the maximum value encountered so far while iterating through the array. If, at any point, we find that this maximum value exceeds `nums[i + 2]`, we return `false`, as the permutation cannot be ideal. If no such violation is found by the end of the loop, we return `true`.

#### Detailed Explanation:

- We initialize `cmax` to store the maximum value encountered up to index `i`.
- For each index `i` from `0` to `n-3` (where `n` is the length of the array), we update `cmax` to be the maximum of `cmax` and `nums[i]`.
- Then, we check whether `cmax` exceeds `nums[i + 2]`. If it does, the array is not ideal, and we return `false`.
- If we complete the loop without finding any violations, the array is ideal, and we return `true`.

This approach ensures that we are checking all potential violations efficiently in a single pass through the array.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int cmax = 0, n = nums.size();
```

- `cmax` is initialized to `0` and will be used to track the maximum number encountered up to the current index `i`.
- `n` stores the size of the input array `nums`.

#### Step 2: Iterate Through the Array

```cpp
for(int i = 0; i < n - 2; i++) {
    cmax = max(cmax, nums[i]);
```

- We iterate through the array from `i = 0` to `i = n-3` (i.e., the second-to-last element).
- At each step, we update `cmax` to be the maximum of the current `cmax` and the current element `nums[i]`.

#### Step 3: Check the Ideal Condition

```cpp
if(cmax > nums[i + 2]) return false;
```

- After updating `cmax`, we check if it exceeds `nums[i + 2]`. If it does, the permutation is not ideal, and we return `false` immediately.

#### Step 4: Return True if No Violations are Found

```cpp
return true;
```

- If the loop completes without returning `false`, it means that all the conditions for an ideal permutation are satisfied, so we return `true`.

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity of the solution is linear because we are iterating through the array once. For each element, we perform constant-time operations (updating `cmax` and comparing values).

#### Space Complexity:
- **O(1)**: The space complexity is constant because we are using a fixed amount of extra space (for the variables `cmax` and `n`). No additional data structures that grow with the input size are used.

### Conclusion

This solution is optimal and highly efficient for determining if a given permutation is ideal. The key to solving this problem efficiently lies in the observation that we only need to keep track of the maximum value encountered up to each index. By checking this value against `nums[i + 2]` at each step, we can verify whether the permutation satisfies the condition for being ideal.

#### Key Insights:
- The condition for an ideal permutation can be checked by maintaining a running maximum (`cmax`) while traversing the array.
- The time complexity is **O(n)**, which ensures that the solution can handle large input sizes efficiently.
- The space complexity is **O(1)**, making the solution space-efficient as well.

This method is not only time-efficient but also very intuitive. It uses a single pass to determine whether the condition for an ideal permutation holds across the entire array, ensuring a quick resolution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/global-and-local-inversions/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
