
+++
authors = ["grid47"]
title = "Leetcode 1144: Decrease Elements To Make Array Zigzag"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1144: Decrease Elements To Make Array Zigzag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size(), left, right;
        vector<int> res(2, 0);
        for(int i = 0; i < n; i++) {

            left  = ( i     > 0 ) ? nums[i - 1] : 1001;
            right = ( i + 1 < n ) ? nums[i + 1] : 1001;

            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
        }

        return min(res[0], res[1]);
    }
};
{{< /highlight >}}
---


### Problem Statement
In this problem, we have an array of integers, and the goal is to transform it into a zigzag array by making the minimum number of operations. An array is in zigzag order if each element alternates between being smaller and larger than its neighbors:
- For even-indexed elements, the element should be smaller than its adjacent elements.
- For odd-indexed elements, the element should be larger than its adjacent elements.

An operation consists of reducing the value of any element by 1. Given an integer array `nums`, the task is to find the minimum number of moves needed to transform the array into a zigzag array.

### Approach
The solution uses a straightforward approach with a greedy technique to evaluate the number of moves required for two possible zigzag patterns:
1. **Pattern 1 (Even Smaller)**: Every element at an even index is smaller than its adjacent elements.
2. **Pattern 2 (Odd Smaller)**: Every element at an odd index is smaller than its adjacent elements.

The algorithm iterates through each element and calculates the number of moves needed to satisfy both patterns. It then returns the minimum of the two values, which represents the optimal number of moves.

### Code Breakdown (Step by Step)

Here’s a step-by-step breakdown of the code:

```cpp
class Solution {
public:
```
- **Line 1-2**: A class named `Solution` is defined, marking the beginning of the code.

```cpp
    int movesToMakeZigzag(vector<int>& nums) {
```
- **Line 3**: The function `movesToMakeZigzag` is defined, which takes a reference to a vector `nums` as an argument.

```cpp
        int n = nums.size(), left, right;
```
- **Line 4**: The variable `n` stores the size of the input array `nums`. The variables `left` and `right` will be used to store the values of the left and right neighbors of the current element.

```cpp
        vector<int> res(2, 0);
```
- **Line 5**: A vector `res` is initialized with two elements set to `0`. `res[0]` will store the moves required for the "even smaller" pattern, and `res[1]` will store the moves for the "odd smaller" pattern.

```cpp
        for(int i = 0; i < n; i++) {
```
- **Line 6**: A loop is initiated to iterate through each element in `nums`.

```cpp
            left  = ( i     > 0 ) ? nums[i - 1] : 1001;
            right = ( i + 1 < n ) ? nums[i + 1] : 1001;
```
- **Line 7-8**: `left` and `right` are assigned values based on the presence of neighboring elements:
  - If `i > 0`, `left` is assigned the value of the left neighbor `nums[i - 1]`. If `i` is at the start of the array, `left` is set to `1001`, which is a value greater than any possible element in `nums` (since constraints ensure elements are at most `1000`).
  - Similarly, `right` is set to the value of the right neighbor if it exists; otherwise, it’s set to `1001`.

```cpp
            res[i % 2] += max(0, nums[i] - min(left, right) + 1);
```
- **Line 9**: This line calculates the number of moves needed for the current element `nums[i]` to satisfy the zigzag condition. The index `i % 2` is used to determine whether we’re calculating for an "even smaller" or "odd smaller" pattern:
  - `min(left, right)` gives the minimum value between the neighboring elements.
  - `nums[i] - min(left, right) + 1` calculates how much we need to reduce `nums[i]` to make it less than both neighbors by at least `1`. If this value is positive, it is added to `res[i % 2]`.

```cpp
        return min(res[0], res[1]);
    }
};
```
- **Line 10-12**: The function returns the minimum of `res[0]` and `res[1]`, which represents the least number of moves needed to transform the array into a zigzag pattern.

### Complexity
- **Time Complexity**: The time complexity of this algorithm is \( O(n) \), where \( n \) is the length of the input array `nums`. The algorithm iterates over each element only once, making it efficient for large inputs.
  
- **Space Complexity**: The space complexity is \( O(1) \), as the algorithm only uses a fixed number of additional variables (`left`, `right`, and `res`), regardless of the input size.

### Conclusion
This C++ solution efficiently calculates the minimum moves needed to transform an array into a zigzag pattern by evaluating two possible patterns and returning the optimal solution. By systematically applying a greedy approach and only requiring a single pass through the array, the code ensures minimal time complexity and space usage. This approach is particularly useful in scenarios involving sequence pattern transformations, especially where minimum adjustments are desired.


[`Link to LeetCode Lab`](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
