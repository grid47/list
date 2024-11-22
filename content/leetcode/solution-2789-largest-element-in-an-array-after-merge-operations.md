
+++
authors = ["grid47"]
title = "Leetcode 2789: Largest Element in an Array after Merge Operations"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2789: Largest Element in an Array after Merge Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "wbXDrozEtOs"
youtube_upload_date="2023-07-23"
youtube_thumbnail="https://i.ytimg.com/vi/wbXDrozEtOs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxArrayValue(vector<int>& in) {

        int n = in.size();        
        vector<long long> nums(n, 0);
        
        for(int i = 0; i < n; i++)
            nums[i] = in[i];

        long long res = nums[n - 1];
        
        for(int i = n - 1; i >= 0; i--) {
            res = max(res, (long long)nums[i]);
            if(i > 0 && nums[i] >= nums[i - 1]) {
                nums[i - 1] += nums[i];
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the maximum possible value that can be obtained from an array, given the operation where adjacent elements of the array can be merged if the current element is greater than or equal to the previous element. When two adjacent elements are merged, the first element of the pair is updated by adding the value of the second element. The task is to compute the maximum possible value that can be obtained after applying this operation optimally.

### Approach

The goal is to find the maximum possible value in the array after applying the merge operation optimally. The algorithm needs to efficiently compute this value by traversing the array and merging adjacent elements wherever it is valid (i.e., when the current element is greater than or equal to the previous element).

To solve this problem, we can take the following approach:

1. **Initialization:**
   - We need to initialize an array `nums` that holds the same values as the input array `in`, so that we can modify it during the merging process without affecting the original input.
   - A variable `res` will keep track of the maximum value encountered during the process.

2. **Traverse the Array from Right to Left:**
   - We start from the last element of the array and iterate backward. This ensures that we are processing possible merges from the end of the array to the beginning.
   - While iterating, we check if the current element is greater than or equal to the previous element. If it is, we merge the two elements by adding the current element's value to the previous element.
   - After merging, we update the array accordingly and continue checking the remaining elements.

3. **Maximize the Result:**
   - During each iteration, we keep track of the maximum value encountered so far by comparing the current element (`nums[i]`) with the previously stored maximum (`res`).

4. **Return the Maximum Value:**
   - After completing the traversal and merging operations, the `res` variable will hold the maximum possible value that can be obtained.

### Code Breakdown (Step by Step)

```cpp
long long maxArrayValue(vector<int>& in) {
    int n = in.size();  // Get the size of the input array
    vector<long long> nums(n, 0);  // Create a new array to store the elements of the input

    // Copy elements from the input array to nums
    for(int i = 0; i < n; i++) 
        nums[i] = in[i];

    long long res = nums[n - 1];  // Initialize the result with the last element of the array
```

- The code starts by calculating the size of the input array (`n`) and creating a `nums` array to store the elements. We initialize `res` with the last element of the array since it will serve as the starting point for our maximum value.

```cpp
    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        res = max(res, (long long)nums[i]);  // Keep track of the maximum value encountered so far

        // If the current element is greater than or equal to the previous element, merge them
        if(i > 0 && nums[i] >= nums[i - 1]) {
            nums[i - 1] += nums[i];  // Merge nums[i] into nums[i - 1]
        }
    }
```

- The core logic of the solution is contained in this loop. We iterate backward through the `nums` array, checking for valid merges. If `nums[i]` is greater than or equal to `nums[i - 1]`, we merge the two elements by adding `nums[i]` to `nums[i - 1]`.
- We also update the `res` variable on each iteration to ensure it holds the maximum value encountered.

```cpp
    return res;  // Return the maximum value found
}
```

- Finally, after completing the backward traversal and possible merges, we return the maximum value stored in `res`.

### Complexity

#### Time Complexity:

- The time complexity of this algorithm is **O(n)**, where `n` is the size of the input array. This is because the algorithm iterates through the array exactly once (from the last element to the first), performing constant-time operations inside the loop.

#### Space Complexity:

- The space complexity is **O(n)**, where `n` is the size of the input array. This is because we create an auxiliary array `nums` to store the elements of the input array. The space used by this array is proportional to the size of the input.

### Conclusion

This solution provides an efficient way to solve the problem of finding the maximum possible value in the array after applying the merge operation. By iterating backward through the array and merging elements wherever applicable, the algorithm ensures that the array is processed in an optimal manner. The time complexity of **O(n)** ensures that this approach will work efficiently even for large input sizes. The space complexity of **O(n)** is manageable and required to store the intermediate results during the merging process.

This approach effectively solves the problem while maintaining a clear and efficient implementation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/)

---
{{< youtube wbXDrozEtOs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
