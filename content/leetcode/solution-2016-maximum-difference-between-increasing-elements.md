
+++
authors = ["grid47"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2016: Maximum Difference Between Increasing Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "OmNZRgKr7GQ"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/OmNZRgKr7GQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the maximum difference between two elements in an array, such that the larger element comes after the smaller element. In other words, we need to determine the maximum value of `nums[j] - nums[i]`, where `j > i`. If no such pair exists that meets this condition, we should return `-1`. 

### Approach

To solve this problem efficiently, we can utilize a single-pass algorithm, which allows us to traverse the array just once while keeping track of the minimum value encountered so far. This method optimizes our approach to O(n) time complexity, where n is the number of elements in the input array. Here are the steps we’ll follow:

1. **Initialization**: We will start by initializing two variables: `mn` to keep track of the minimum value encountered so far and `res` to store the maximum difference found.

2. **Iterate Through the Array**: As we iterate through the array:
   - We will update the maximum difference if the current element minus the minimum value (`mn`) is greater than the previously recorded maximum difference (`res`).
   - We will also update `mn` to be the minimum of its current value and the current element.

3. **Final Check**: After completing the iteration, we will check if `res` remains `0`, which would imply that no valid pairs were found. In that case, we return `-1`. Otherwise, we return the maximum difference found.

### Code Breakdown (Step by Step)

Let’s analyze the implementation in detail:

```cpp
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
```
- We define a class named `Solution` with a public method `maximumDifference` that takes a vector of integers as its parameter.

```cpp
        int mn = nums[0], res = -1;
```
- We initialize `mn` with the first element of the array `nums` and `res` with `-1`, indicating that we haven't found any valid difference yet.

```cpp
        for (int i = 1; i < nums.size(); ++i) {
```
- We begin a loop starting from the second element (index `1`) and continue until the end of the vector.

```cpp
            res = max(res, nums[i] - mn);
```
- Here, we calculate the difference between the current element `nums[i]` and the minimum value `mn`. We update `res` with the maximum of its current value and the computed difference.

```cpp
            mn = min(mn, nums[i]);
```
- We update `mn` to be the smaller of its current value and the current element. This ensures that we are always considering the smallest element encountered so far.

```cpp
        }
```
- The loop completes when all elements have been processed.

```cpp
        return res == 0 ? -1 : res;
    }
};
```
- Finally, we return `-1` if `res` is still `0`, indicating that no valid pairs were found. Otherwise, we return the maximum difference calculated.

### Complexity

The time complexity of this approach is O(n) because we traverse the array only once. The space complexity is O(1) since we are using a constant amount of extra space for our variables (`mn` and `res`).

### Conclusion

In conclusion, the `maximumDifference` method provides an efficient way to find the maximum difference between two elements in an array, with the requirement that the larger element appears after the smaller one. 

By leveraging a single pass through the array while maintaining a record of the minimum value encountered, we are able to efficiently compute the desired result without the need for nested loops. This implementation highlights the power of using dynamic tracking of state during iteration to optimize performance.

This approach is particularly beneficial in scenarios where the input size can be large, as it minimizes the time spent on calculations and maintains simplicity in code. Whether you are working on competitive programming problems or building applications that require numerical analysis, understanding and applying this technique can enhance your coding proficiency.

The code is not only concise but also easy to understand, making it a valuable example for those looking to improve their algorithmic skills. This solution encapsulates important concepts in array manipulation, condition checking, and efficient algorithm design, serving as an excellent reference point for both novice and experienced programmers alike.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---
{{< youtube OmNZRgKr7GQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
