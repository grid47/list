
+++
authors = ["grid47"]
title = "Leetcode 1186: Maximum Subarray Sum with One Deletion"
date = "2024-07-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1186: Maximum Subarray Sum with One Deletion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EWCdm1cKtrA"
youtube_upload_date="2024-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/EWCdm1cKtrA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
        int curr_mx = arr[0], overall_mx = arr[0];
        vector<int> f(n), b(n);
        f[0] = arr[0];
        for(int i = 1; i < n; i++) {
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(curr_mx, overall_mx);
            f[i] = curr_mx;
        }
        
        curr_mx = overall_mx = b[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(overall_mx, curr_mx);
            b[i] = curr_mx;
        }
        
        res = overall_mx;
        for(int i = 1; i < n-1; i++) {
            res = max(res, f[i-1]+b[i+1]);
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The goal is to find the maximum sum of a contiguous subarray in a given array of integers, with the added twist that you may delete at most one element from the array. If you decide to delete one element, the remaining subarrays can still be combined to maximize the overall sum.

For example, given an array `[-1, -2, 0, 3]`, the maximum sum after possibly removing an element is `3` (removing `-1` or `-2`). The solution needs to efficiently handle both the case of deleting an element and not deleting any element.

### Approach
The solution utilizes a dynamic programming approach to keep track of two primary calculations:
1. **Maximum Subarray Sum Ending at Each Index**: Calculate the maximum sum of subarrays ending at each index, using Kadane's algorithm.
2. **Maximum Subarray Sum Starting from Each Index**: Calculate the maximum sum of subarrays starting from each index.

By combining these two arrays, we can efficiently compute the maximum sum possible after removing at most one element.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
```
- **Lines 1-3**: The `Solution` class contains the `maximumSum` method, which takes a vector of integers `arr` as input.
- The variable `res` is initialized to hold the result, while `n` is the size of the array.

```cpp
        int curr_mx = arr[0], overall_mx = arr[0];
        vector<int> f(n), b(n);
        f[0] = arr[0];
```
- **Lines 4-7**: Two variables, `curr_mx` and `overall_mx`, are initialized to the first element of the array. 
- Two vectors `f` and `b` are created to store the maximum subarray sums ending at and starting from each index, respectively.
- `f[0]` is set to the first element since it is the only subarray possible at index 0.

```cpp
        for(int i = 1; i < n; i++) {
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(curr_mx, overall_mx);
            f[i] = curr_mx;
        }
```
- **Lines 8-12**: This loop iterates through the array from the second element onwards.
- `curr_mx` is updated to be the maximum of either the current element alone (`arr[i]`) or the sum of the current element and the maximum subarray sum up to the previous element (`curr_mx + arr[i]`).
- `overall_mx` is updated to track the maximum value found so far.
- The maximum subarray sum ending at each index `i` is stored in `f[i]`.

```cpp
        curr_mx = overall_mx = b[n-1] = arr[n-1];
```
- **Line 13**: The variables `curr_mx` and `overall_mx` are reset for the next calculation. `b[n-1]` is initialized to the last element, as it's the only subarray at the last index.

```cpp
        for(int i = n-2; i >= 0; i--){
            curr_mx = max(arr[i], curr_mx + arr[i]);
            overall_mx = max(overall_mx, curr_mx);
            b[i] = curr_mx;
        }
```
- **Lines 14-18**: This loop iterates backward through the array, similar to the previous loop.
- The maximum subarray sums starting from each index are calculated and stored in the vector `b`.

```cpp
        res = overall_mx;
        for(int i = 1; i < n-1; i++) {
            res = max(res, f[i-1]+b[i+1]);
        }
```
- **Lines 19-22**: The variable `res` is first set to `overall_mx`, which represents the maximum sum without deleting any element.
- A second loop iterates from the second to the second-to-last element of the array. For each index `i`, it calculates the sum of the maximum subarray sum ending just before `i` (`f[i-1]`) and the maximum subarray sum starting just after `i` (`b[i+1]`), which simulates the effect of deleting the element at index `i`.
- The result is updated to the maximum of the current `res` and the combined sums.

```cpp
        return res;
    }
};
```
- **Line 23**: Finally, the method returns the maximum sum found.

### Complexity
1. **Time Complexity**: 
   - The algorithm consists of two linear passes through the array, resulting in a total time complexity of \(O(n)\).
  
2. **Space Complexity**: 
   - The solution uses \(O(n)\) space for the two additional vectors `f` and `b` that store intermediate results.

### Conclusion
The `maximumSum` function efficiently computes the maximum possible sum of a contiguous subarray, considering the option to remove at most one element. By utilizing dynamic programming techniques and Kadane's algorithm for tracking maximum sums, the solution is both optimal and straightforward. This approach provides a robust means of tackling the problem while maintaining clarity and efficiency, making it suitable for larger input sizes. The ability to handle both cases—removing an element or not—ensures that all potential solutions are considered, leading to the best possible outcome.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/)

---
{{< youtube EWCdm1cKtrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
