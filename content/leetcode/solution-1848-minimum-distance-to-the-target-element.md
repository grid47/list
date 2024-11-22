
+++
authors = ["grid47"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1848: Minimum Distance to the Target Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "eAA1gS_2QwY"
youtube_upload_date="2021-05-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eAA1gS_2QwY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
    int res = INT_MAX;
    for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
        if (nums[i] == target)
            res = abs(start - i);
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The goal of the problem is to find the minimum distance from a given starting index to the closest occurrence of a specified target value in an array of integers. The function takes three parameters: an integer vector `nums`, an integer `target`, and an integer `start`. The task is to determine the minimum absolute distance between the index of the `target` in `nums` and the `start` index.

### Approach

To solve the problem, we can follow a straightforward approach:

1. **Initialization**: Begin by initializing a variable `res` to a large value (using `INT_MAX`) to keep track of the minimum distance found.

2. **Iterate through the Array**: Use a loop to traverse each element in the array `nums`. For each index, check if the current element equals the `target`.

3. **Calculate Distance**: If the current element is equal to the `target`, calculate the absolute distance between the current index and the `start` index. If this distance is smaller than the previously recorded minimum distance (`res`), update `res`.

4. **Return the Result**: After checking all elements, return the minimum distance found.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
- We define a class `Solution` that contains the method we will use to find the minimum distance.

```cpp
    int getMinDistance(vector<int>& nums, int target, int start) {
```
- The method `getMinDistance` is defined, which takes three parameters: a vector of integers `nums`, an integer `target`, and an integer `start`.

```cpp
    int res = INT_MAX;
```
- We initialize a variable `res` to `INT_MAX`, which represents the maximum possible integer value. This is used to track the minimum distance encountered during the search.

```cpp
    for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
```
- We use a `for` loop to iterate through each index `i` in the `nums` array. The loop continues as long as `i` is less than the size of `nums` and `res` is greater than the absolute distance between `start` and `i`. This ensures that we stop checking once we have found a distance smaller than the current value of `res`.

```cpp
        if (nums[i] == target)
```
- Inside the loop, we check if the current element `nums[i]` is equal to the `target`.

```cpp
            res = abs(start - i);
```
- If the condition is true, we calculate the absolute distance between `start` and `i` and update `res` with this value.

```cpp
    return res;
}
```
- Finally, after checking all elements in the array, we return the minimum distance `res` found.

### Complexity

- **Time Complexity**: 
  - The time complexity of this solution is \( O(n) \), where \( n \) is the number of elements in the `nums` array. This is because we potentially need to check each element once.

- **Space Complexity**: 
  - The space complexity is \( O(1) \) since we are using a fixed amount of space for the variables, regardless of the size of the input.

### Conclusion

This code provides an efficient and simple solution to the problem of finding the minimum distance to a target value in an array. By leveraging a linear scan of the array, it effectively locates the closest occurrence of the target relative to the specified starting index.

The approach is intuitive and easy to implement, making it suitable for use in scenarios where one needs to quickly assess the proximity of a value in a list. The use of absolute distance calculation ensures that we consider both directions from the starting index, providing a complete picture of the minimum distance to the target.

This method can be particularly useful in various applications, such as search algorithms, data retrieval tasks, and scenarios where quick access to the closest matches in a dataset is required. Its simplicity and efficiency make it a valuable technique for software developers and data scientists alike.

In summary, the `getMinDistance` function efficiently determines the closest occurrence of a target value in an array while maintaining a clear and concise structure that promotes readability and maintainability. This makes it an ideal choice for competitive programming and algorithmic challenges where performance and clarity are paramount.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-distance-to-the-target-element/description/)

---
{{< youtube eAA1gS_2QwY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
