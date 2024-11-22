
+++
authors = ["grid47"]
title = "Leetcode 1685: Sum of Absolute Differences in a Sorted Array"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1685: Sum of Absolute Differences in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WYe644djV30"
youtube_upload_date="2021-01-04"
youtube_thumbnail="https://i.ytimg.com/vi/WYe644djV30/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
        vector<int> ans(n, 0);
        ans[0] = z;
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to calculate the sum of absolute differences for each element in an array `nums`. Specifically, for each element `nums[i]`, we need to compute the sum of the absolute differences between `nums[i]` and every other element in the array. The result should be stored in a vector where the `i-th` element represents the sum of absolute differences for the element `nums[i]`.

For example, given an array `[2, 3, 5]`, the output should be `[4, 3, 4]` because:
- For `2`: `|2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4`
- For `3`: `|3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3`
- For `5`: `|5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5`

### Approach

To efficiently compute the sum of absolute differences for each element in the array, we can utilize a mathematical approach that avoids the need for nested loops, thus optimizing performance. Here's a breakdown of the approach:

1. **Initial Calculation**: Compute the initial sum of absolute differences for the first element `nums[0]` relative to all other elements in the array. This will serve as our starting point for calculations.

2. **Dynamic Update**: Use the result from the previous element to calculate the result for the next element. This is done by recognizing how the sum of differences changes when moving from `nums[i-1]` to `nums[i]`. Specifically, we will derive the formula to update our answer based on the current and previous values.

3. **Vector Storage**: Store the results in a vector, where each index corresponds to the respective element in `nums`.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the implementation:

```cpp
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
```
- **Class Definition**: We define a class named `Solution` and create a public method `getSumAbsoluteDifferences`, which takes a vector of integers `nums` as its parameter.

```cpp
        int z = 0, n = nums.size();
        for(int i = 0; i < n; i++)
            z += nums[i] - nums[0];
```
- **Initialization**:
  - We initialize `z` to store the total sum of absolute differences for the first element, and `n` to hold the size of the `nums` vector.
  - The first `for` loop calculates the sum of differences between `nums[0]` and each element in `nums`. The result is stored in `z`.

```cpp
        vector<int> ans(n, 0);
        ans[0] = z;
```
- **Result Storage**:
  - We create a vector `ans` of size `n` initialized to zero, which will hold the final results.
  - We store the calculated sum of absolute differences for `nums[0]` in `ans[0]`.

```cpp
        for(int i = 1; i < n; i++)
            ans[i] = ans[i-1] + i * (nums[i] - nums[i-1]) - (n - i)* (nums[i] - nums[i-1]);
```
- **Dynamic Calculation**:
  - We use a `for` loop to iterate from the second element to the last element in `nums`.
  - For each element `nums[i]`, we calculate the sum of absolute differences using the previous result `ans[i-1]`.
  - The formula used is derived from the relationship between the current and previous elements, factoring in how many times each value affects the overall sum based on its position.

```cpp
        return ans;
    }
};
```
- **Return Result**: After calculating the sum of absolute differences for all elements, we return the vector `ans`, which contains the results.

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the number of elements in the `nums` vector. We loop through the array a constant number of times.

- **Space Complexity**: The space complexity is \( O(n) \) due to the additional storage required for the result vector `ans`.

### Conclusion

This solution efficiently calculates the sum of absolute differences for each element in an array using a mathematical approach that avoids nested loops. 

Key highlights include:

1. **Efficiency**: By avoiding nested loops, the algorithm runs in linear time, making it suitable for larger datasets.

2. **Mathematical Insight**: The use of a dynamic update formula allows for quick recalculation of the sum of absolute differences as we iterate through the array.

3. **Scalability**: The method can handle any size of input and provides a quick and efficient way to obtain the desired results.

Overall, the code showcases a clear and efficient algorithm for solving the problem, focusing on leveraging mathematical relationships to optimize performance and readability.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/)

---
{{< youtube WYe644djV30 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
