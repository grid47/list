
+++
authors = ["grid47"]
title = "Leetcode 1493: Longest Subarray of 1's After Deleting One Element"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1493: Longest Subarray of 1's After Deleting One Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PnzvwU4CFg8"
youtube_upload_date="2020-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PnzvwU4CFg8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int longestSubarray(vector<int>& nums) {
        
        int ans = 0;
        
        int n = nums.size();
        
        int k = 1;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) k--;
            
            while(k < 0) {
                if(nums[j] == 0)
                    k++;
                j++;
            }
            ans = max(ans, i - j);
        }
        
        /*
        i - j mean one elment will be cut from [j, i] closed interval
        what k does is, make that element a zero.
        */

        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the length of the longest subarray in a binary array (composed of `0`s and `1`s) after removing **at most one `0`**. The goal is to return the maximum length of contiguous `1`s that can be achieved by removing a single `0` from the array.

### Approach

To solve this problem, we can use a sliding window technique. The idea is to maintain a window that keeps track of the number of `0`s in the current subarray. By allowing at most one `0` in the window, we can adjust the left pointer of the window whenever we exceed this limit. Here’s a step-by-step breakdown of the approach:

1. **Initialize Pointers and Variables**: Use two pointers (`i` for the current end of the window and `j` for the start of the window) and a variable `k` to track the number of `0`s in the current window.
  
2. **Expand the Window**: As we iterate through the array with the right pointer `i`, if we encounter a `0`, we decrement `k`.

3. **Shrink the Window**: If `k` becomes less than `0`, it means there are more than one `0`s in the current window, so we need to increment the left pointer `j` until we have at most one `0`.

4. **Calculate Maximum Length**: Throughout the process, keep track of the maximum length of the window that can be formed.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
```
This begins the declaration of the `Solution` class and its method `longestSubarray`, which takes a vector of integers as input.

#### Step 1: Initialize Variables

```cpp
        int ans = 0;
        int n = nums.size();
        int k = 1;
        int j = 0;
```
- `ans`: This variable will hold the maximum length of the desired subarray.
- `n`: The size of the input array `nums`.
- `k`: Set to `1`, representing the maximum number of `0`s allowed in the window.
- `j`: This pointer will represent the start of the current subarray window.

#### Step 2: Iterate Over the Array

```cpp
        for(int i = 0; i < n; i++) {
```
- A for loop begins, iterating through the array with `i` representing the current end of the window.

#### Step 3: Manage the Window Size

```cpp
            if(nums[i] == 0) k--;
```
- If the current element `nums[i]` is `0`, decrement `k`. This indicates we have encountered a `0` and are now allowing one fewer `0` in the current window.

#### Step 4: Adjust the Left Pointer

```cpp
            while(k < 0) {
                if(nums[j] == 0)
                    k++;
                j++;
            }
```
- The inner while loop checks if `k` is less than `0`, which means we have encountered more than one `0`. If this is the case, we increment `j` to shrink the window from the left. If the element at `j` is `0`, we increment `k` to indicate that we are removing a `0` from the window.

#### Step 5: Calculate the Length of the Current Window

```cpp
            ans = max(ans, i - j);
```
- After adjusting the pointers, calculate the current length of the valid window (`i - j`) and update `ans` with the maximum value found so far.

### Complexity

#### Time Complexity
- The time complexity of this algorithm is **O(n)**, where `n` is the length of the input array. The algorithm processes each element of the array at most twice (once by `i` and once by `j`).

#### Space Complexity
- The space complexity is **O(1)**, as we are using a fixed amount of extra space for variables regardless of the input size.

### Conclusion

This implementation provides an efficient way to determine the length of the longest contiguous subarray of `1`s that can be obtained by removing at most one `0`. The sliding window approach optimizes the search for valid subarrays, making it suitable for large input sizes.

**Key Points**:
- **Efficiency**: The O(n) time complexity ensures that the solution is efficient and scalable for large inputs.
- **Clarity**: The sliding window method is intuitive and easy to follow, making the code more understandable.
- **Edge Cases**: The implementation handles edge cases, such as arrays with all `1`s or arrays with only one `0`, effectively without additional checks.

Overall, this solution is an excellent example of how to apply sliding window techniques to solve problems related to contiguous subarrays, especially when constraints are placed on the elements within the window.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/)

---
{{< youtube PnzvwU4CFg8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
